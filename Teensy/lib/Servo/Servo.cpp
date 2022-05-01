// Modified Servo library from Arduino

#include "Arduino.h"
#include "Servo.h"

#define NO_ANGLE (0xff)

#if defined(__AVR__)

#elif defined(__arm__) && defined(TEENSYDUINO)

uint32_t Servo::attachedpins[(NUM_DIGITAL_PINS+31)/32]; // 1 bit per digital pin

Servo::Servo() : pin(255), angle(NO_ANGLE) {}

uint8_t Servo::attach(int pinArg, int min, int max)
{
	//Serial.printf("attach, pin=%d, min=%d, max=%d\n", pinArg, min, max);
	if (pinArg < 0 || pinArg >= NUM_DIGITAL_PINS) return 0;
	if (!digitalPinHasPWM(pinArg)) return 0;
	pin = pinArg;
	analogWriteFrequency(pin, 50);
	min16 = min >> 4;
	max16 = max >> 4;
	angle = NO_ANGLE;
	digitalWrite(pin, LOW);
	pinMode(pin, OUTPUT);
	attachedpins[pin >> 5] |= (1 << (pin & 31));
	return 1;
}

void Servo::write(int angleArg)
{
	//Serial.printf("write, pin=%d, angle=%d\n", pin, angleArg);
	if (pin >= NUM_DIGITAL_PINS) return;
	if (angleArg < 0) angleArg = 0;
	if (angleArg > 180) angleArg = 180;
	angle = angleArg;
	uint32_t us = (((max16 - min16) * 46603 * angle) >> 11) + (min16 << 12); // us*256
	uint32_t duty = (us * 3355) >> 22;
	//float usec = (float)((max16 - min16)<<4) * ((float)angle / 180.0f) + (float)(min16<<4);
	//uint32_t duty = (int)(usec / 20000.0f * 4096.0f);
	//Serial.printf("angle=%d, usec=%.2f, us=%.2f, duty=%d, min=%d, max=%d\n",
		//angle, usec, (float)us / 256.0f, duty, min16<<4, max16<<4);
#if TEENSYDUINO >= 137
	noInterrupts();
	uint32_t oldres = analogWriteResolution(12);
	analogWrite(pin, duty);
	analogWriteResolution(oldres);
	interrupts();
#else
	analogWriteResolution(12);
	analogWrite(pin, duty);
#endif
}

uint8_t Servo::attached()
{
	if (pin >= NUM_DIGITAL_PINS) return 0;
	return (attachedpins[pin >> 5] & (1 << (pin & 31))) ? 1 : 0;
}

#endif