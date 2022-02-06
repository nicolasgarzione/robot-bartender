class PID {
    public:
    
    #define P_ON_M 0
    #define P_ON_E 1

    PID(double* const, double* const, double* const, const double, const double, const double, unsigned const int, unsigned const int, unsigned const int, const bool);
    bool Compute();
    void SetOutputLimits(unsigned const int, unsigned const int);
    void SetTuning(const double, const double, const double, const bool);
    void SetSampleTime(unsigned const int);

    private:

    void Initialize();

    double Kp;
    double Ki;
    double Kd;

    bool pOn;

    double *Input;
    double *Output;
    double *Setpoint;

    unsigned long previousTime;
    double outputSum, lastInput;

    unsigned long sampleTime;
    unsigned int outMin, outMax;
    bool pOnE;
};