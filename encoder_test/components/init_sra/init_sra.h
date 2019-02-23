#ifndef _INIT_SRA_H
#define _INIT_SRA_H
#include "driver/gpio.h"
#include "esp_attr.h"
#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"


typedef struct{
    mcpwm_unit_t pwm_unit;
    mcpwm_io_signals_t pwm_operator;
    mcpwm_timer_t pwm_timer;
    gpio_num_t pwm_pin;
}mcpwm_t;

typedef struct{
    gpio_num_t dir_0_pin;
    gpio_num_t dir_1_pin;
    gpio_num_t encoder_A;
    gpio_num_t encoder_B;
    gpio_num_t bump_switch;
    mcpwm_t pwm;
}motor_pins_t;

typedef struct{
    float Kp;
    float Ki;
    float Kd;
}motor_pid_t;

typedef struct{
    float cur_theta;
    float prev_theta;
}motor_position_t;

void init_interrupt(gpio_num_t NUM_GPIO);

void init_gpio(gpio_num_t NUM_GPIO, gpio_mode_t GPIO_MODE);

void init_mcpwm(mcpwm_t *motor);


#endif