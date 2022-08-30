#include "IOXESP32Motor.h"
#include "Arduino.h"

#define MOTOR1_A_PIN 27
#define MOTOR1_B_PIN 26
#define MOTOR2_A_PIN 14
#define MOTOR2_B_PIN 12

#define FREQ (1E3)

struct CH_PIN_t {
    int a, b;
};

static struct CH_PIN_t motor_ch_to_ch[2] = {
    {
        .a = 15,
        .b = 14
    },
    {
        .a = 13,
        .b = 12
    },
};

#define PWM_RESOLUTION 8
#define MAX_PWM_DUTY ((1 << PWM_RESOLUTION) - 1)

IOXESP32Motor::IOXESP32Motor(int ch, int a, int b) {
    this->ch = ch;
    this->a = a;
    this->b = b;
}

void IOXESP32Motor::begin() {
    pinMode(this->a, OUTPUT);
    pinMode(this->b, OUTPUT);

    ledcSetup(motor_ch_to_ch[this->ch].a, FREQ, PWM_RESOLUTION);
    ledcSetup(motor_ch_to_ch[this->ch].b, FREQ, PWM_RESOLUTION);

    ledcAttachPin(this->a, motor_ch_to_ch[this->ch].a);
    ledcAttachPin(this->b, motor_ch_to_ch[this->ch].b);
}

void IOXESP32Motor::forward(int speed) {
    ledcWrite(motor_ch_to_ch[this->ch].a, (100 - speed) / 100.0f * MAX_PWM_DUTY);
    ledcWrite(motor_ch_to_ch[this->ch].b, MAX_PWM_DUTY);
}

void IOXESP32Motor::backward(int speed) {
    ledcWrite(motor_ch_to_ch[this->ch].a, MAX_PWM_DUTY);
    ledcWrite(motor_ch_to_ch[this->ch].b, (100 - speed) / 100.0f * MAX_PWM_DUTY);
}

void IOXESP32Motor::stop() {
    ledcWrite(motor_ch_to_ch[this->ch].a, MAX_PWM_DUTY);
    ledcWrite(motor_ch_to_ch[this->ch].b, MAX_PWM_DUTY);
}

IOXESP32Motor M1(0, MOTOR1_A_PIN, MOTOR1_B_PIN);
IOXESP32Motor M2(1, MOTOR2_A_PIN, MOTOR2_B_PIN);
