#ifndef _SYS_INPUT_SYSTEM_H_
#define _SYS_INPUT_SYSTEM_H_

#include <stdbool.h>

void sys_input_init();

char sys_input_update();

bool sys_input_askForContinue();

void sys_input_onEnterAction();

void sys_input_onDeleteAction();

#endif