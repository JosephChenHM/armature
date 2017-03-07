#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
#define MotorSpeedSet             0x82
#define DirectionSet              0xaa
#define Nothing                   0x01
class Motor
{
    public:
        double current_rpm;
        double required_rpm;

        static float Kp;
        static float Kd;
        static float Ki;

        static int max_rpm;
        static int counts_per_rev;
        static float wheel_diameter;

        Motor(int pwm_pin, int motor_pinA, int motor_pinB);
        void calculate_rpm(long current_encoder_ticks);
        int calculate_pwm();
        void spin(int pwm);
        void stop();
//Modify here
        void MotorSpeedSetAB(unsigned char MotorSpeedA , unsigned char MotorSpeedB, unsigned char Addreas);
        void MotorDirectionSet(unsigned char Direction,unsigned char Addreas);        
    private:
		int _pwm_pin;
        int _motor_pinA;
        int _motor_pinB;

        double _previous_pid_error;
        double _total_pid_error;
        long _previous_encoder_ticks;
        unsigned long _previous_rpm_time;
        double _prev_pwm;
};

#endif
