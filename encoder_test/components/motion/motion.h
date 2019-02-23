#ifndef _MOTION_H
#define _MOTION_H

#include "../init_sra/init_sra.h"
typedef struct{
    char name;
    int id; 
    volatile long enc_ticks;   
    motor_pins_t pins;
    motor_position_t pos; 
    motor_pid_t pid;
}motor_commander_t;


void init_motor(motor_pins_t *motor_pin);

void drive_motor(motor_commander_t *motor);

void IRAM_ATTR enc_isr_handler(motor_commander_t *motor);
#endif