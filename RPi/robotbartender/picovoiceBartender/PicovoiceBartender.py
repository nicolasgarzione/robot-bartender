import os
import sys
import struct
import wave
from threading import Thread
from picovoice import *
from pvrecorder import PvRecorder

#access_key = "8cOb8NKsxqn4yohAH6LU3FRmSuNGpBmnjXPuoeadaqYw2tIgfTuAAw=="

class PicovoiceBartender(Thread):
    __access_key =  '8cOb8NKsxqn4yohAH6LU3FRmSuNGpBmnjXPuoeadaqYw2tIgfTuAAw=='
    __keyword_path = os.path.join(os.getcwd(),'RPi','data',"Bartender_en_windows_v2_1_0.ppn")
    __context_path = os.path.join(os.getcwd(),'RPi','data',"Bartender_en_windows_v2_1_0.rhn")

    drink = 'none'

    def __init__(
            self,
            access_key = __access_key,
            audio_device_index = 0,
            keyword_path = __keyword_path,
            context_path = __context_path,
            porcupine_library_path=None,
            porcupine_model_path=None,
            porcupine_sensitivity=0.5,
            rhino_library_path=None,
            rhino_model_path=None,
            rhino_sensitivity=0.5,
            require_endpoint=True,
            output_path=None):
        super(PicovoiceBartender, self).__init__()

        try:
            self._picovoice = Picovoice(
                access_key=access_key,
                keyword_path=keyword_path,
                wake_word_callback=self._wake_word_callback,
                context_path=context_path,
                inference_callback=self._inference_callback,
                porcupine_library_path=porcupine_library_path,
                porcupine_model_path=porcupine_model_path,
                porcupine_sensitivity=porcupine_sensitivity,
                rhino_library_path=rhino_library_path,
                rhino_model_path=rhino_model_path,
                rhino_sensitivity=rhino_sensitivity,
                require_endpoint=require_endpoint)
        except PicovoiceInvalidArgumentError as e:
            print("One or more arguments provided to Picovoice is invalid: {\n" +
                  "\t{access_key=}\n" +
                  "\t{keyword_path=}\n" +
                  "\t{self._wake_word_callback=}\n" +
                  "\t{context_path=}\n" +
                  "\t{self._inference_callback=}\n" +
                  "\t{porcupine_library_path=}\n" +
                  "\t{porcupine_model_path=}\n" +
                  "\t{porcupine_sensitivity=}\n" +
                  "\t{rhino_library_path=}\n" +
                  "\t{rhino_model_path=}\n" +
                  "\t{rhino_sensitivity=}\n" +
                  "\t{require_endpoint=}\n" +
                  "}")
            print(f"If all other arguments seem valid, ensure that '{access_key}' is a valid AccessKey")
            raise e
        except PicovoiceActivationError as e:
            print("AccessKey activation error")
            raise e
        except PicovoiceActivationLimitError as e:
            print(f"AccessKey '{access_key}' has reached it's temporary device limit")
            raise e
        except PicovoiceActivationRefusedError as e:
            print(f"AccessKey '{access_key}' refused")
            raise e
        except PicovoiceActivationThrottledError as e:
            print(f"AccessKey '{access_key}' has been throttled")
            raise e
        except PicovoiceError as e:
            print("Failed to initialize Picovoice")
            raise e

        self.audio_device_index = audio_device_index
        self.output_path = output_path

        Thread.__init__(self)
        self.daemon = True
        self.start()

    @staticmethod
    def _wake_word_callback():
        print('[wake word]\n')

    @staticmethod
    def _inference_callback(inference):
        if inference.is_understood:
            print('{')
            print("  intent : '%s'" % inference.intent)
            print('  slots : {')
            for slot, value in inference.slots.items():
                print("    %s : '%s'" % (slot, value))
            print('  }')
            print('}\n')
            PicovoiceBartender.drink = inference.slots
        else:
            print("Didn't understand the command.\n")

    def run(self):
        recorder = None
        wav_file = None

        try:
            recorder = PvRecorder(device_index=self.audio_device_index, frame_length=self._picovoice.frame_length)
            recorder.start()

            if self.output_path is not None:
                wav_file = wave.open(self.output_path, "w")
                wav_file.setparams((1, 2, 16000, 512, "NONE", "NONE"))

            print(f"Using device: {recorder.selected_device}")
            print('[Listening ...]')

            while True:
                pcm = recorder.read()

                if wav_file is not None:
                    try:
                        wav_file.writeframes(struct.pack("h" * len(pcm), *pcm))
                    except:
                        pass
                
                try:
                    self._picovoice.process(pcm)
                except:
                    pass

        except KeyboardInterrupt:
            sys.stdout.write('\b' * 2)
            print('Stopping ...')
        finally:
            if recorder is not None:
                recorder.delete()

            if wav_file is not None:
                wav_file.close()

            self._picovoice.delete()

            exit()

    @classmethod
    def show_audio_devices(cls):
        devices = PvRecorder.get_audio_devices()

        for i in range(len(devices)):
            print(f'index: {i}, device name: {devices[i]}')