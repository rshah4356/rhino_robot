#include "motion.h"


void init_motor(motor_pins_t *motor_pin){
    init_gpio(motor_pin->dir_0_pin, GPIO_MODE_OUTPUT);
    init_gpio(motor_pin->dir_1_pin, GPIO_MODE_OUTPUT);
    init_gpio(motor_pin->encoder_B,GPIO_MODE_INPUT);
    init_interrupt(motor_pin->encoder_A);
    init_mcpwm(&(motor_pin->pwm));
}

void IRAM_ATTR enc_isr_handler(motor_commander_t *motor)
{
    if(gpio_get_level(motor->pins.encoder_B)== 0)
        motor->enc_ticks++;
    else
        motor->enc_ticks--;  
}


void drive_motor(motor_commander_t *motor){
    init_motor(&(motor->pins));
    static int err;
    static int prev_err;
    static int cum_err;

    
    // while(1){
        // err = motor->desr_velocity - motor->curr_velocity;
        // prev_err = err;
        // cum_err += err;
        // motor->del_duty_cycle = (motor->Kp)*err - (motor->Kd)*(err-prev_err) + (motor->Ki)*(cum_err);
        // motor->duty_cycle += motor->del_duty_cycle;        
        // if(motor->duty_cycle > 0)
        // {
            // gpio_set_level(motor->dir_0_pin,0);
            // gpio_set_level(motor->dir_1_pin,1);
        // }
        // if(motor->duty_cycle < 0)
        // {
            // gpio_set_level(motor->dir_0_pin,1);
            // gpio_set_level(motor->dir_1_pin,0);
        // }
        // mcpwm_set_duty(motor->pwm.pwm_unit, motor->pwm.pwm_timer, motor->pwm.pwm_operator, abs(motor->duty_cycle));
        // mcpwm_set_duty_type(motor->pwm.pwm_unit, motor->pwm.pwm_timer, motor->pwm.pwm_operator, MCPWM_DUTY_MODE_0);
    // }
}