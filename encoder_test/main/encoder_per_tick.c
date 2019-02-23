#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

// #define calc_veloctiy_timer 55555   //111111
// #define calc_veloctiy_timer_multiplier (1000000*60)/(135*calc_veloctiy_timer)

#include "../components/motion/motion.h"
#include "../components/pin_defs_for_motor/pin_defs_for_motor.h"
// int pwm = 0;
// int motor_velocity;

motor_commander_t motor_0 = (motor_commander_t){.name = 'A', 
                                                .id = 0, 
                                                .pins.dir_0_pin = MOTOR_0_A,
                                                .pins.dir_1_pin = MOTOR_0_B,
                                                .pins.encoder_A = ENCODER_PHASE_A_0,
                                                .pins.encoder_B = ENCODER_PHASE_B_0,
                                                .pins.bump_switch = SW_0,
                                                .pins.pwm.pwm_unit = MCPWM_UNIT_0,
                                                .pins.pwm.pwm_operator = MCPWM0A, 
                                                .pins.pwm.pwm_timer = MCPWM_TIMER_0, 
                                                .pins.pwm.pwm_pin = MOTOR_0_PWM };


void app_main()
{ 
	gpio_isr_handler_add(motor_0.pins.encoder_A, enc_isr_handler, (void*) &motor_0);

     
    xTaskCreatePinnedToCore(drive_motor, "drive_motor", 8192, &motor_0, 23, NULL, 1);
    // xTaskCreate(setup_velocity_calculator, "setup_velocity_calculator", 4096, NULL, 11, NULL); 
    while(1) 
    {
        // printf("gpio = %d\t%d\n", gpio_get_level(ENCODER_PHASE_A_0), gpio_get_level(ENCODER_PHASE_B_0));
        vTaskDelay(1 / portTICK_RATE_MS);
    }
}
