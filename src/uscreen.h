/*
 * uscreen.h
 *
 * Based on lib_easy.h by @rw-r-r-0644 
 *
*/

#ifndef LIB_EASY_H
#define LIB_EASY_H

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/fs_functions.h"
#include "dynamic_libs/gx2_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "dynamic_libs/padscore_functions.h"
#include "dynamic_libs/socket_functions.h"
#include "dynamic_libs/ax_functions.h"
#include "fs/fs_utils.h"
#include "fs/sd_fat_devoptab.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"
#include "common/common.h"
#include "common/common.h"


unsigned char *screenBuffer;
int curr_line; //Current print line
uint32_t buttons_hold; //Held buttons

void ucls();
void ScreenInit();
void flipBuffers();
void uprintf(const char* format, ...);
void updatePressedButtons();
int isPressed(int button);
void uInit();
void uDeInit();

#endif /* LIB_EASY_H */

