/*
 * uscreen.h
 *
 * Based on lib_easy.h by @rw-r-r-0644 
 *
*/

#ifndef USCREEN_H
#define USCREEN_H

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
#include "common/common.h"
#include "common/common.h"


unsigned char *screenBuffer;
int curr_line; //Current print line
uint32_t buttons_hold; //Held buttons

void ucls(); //Clear screen
void ScreenInit(); // Init Screen (Thanks Captain Obivious !)
void flipBuffers();
void uprintf(const char* format, ...); //Print text
void updatePressedButtons(); // Update pressed buttons (Thanks Captain Obivious !)
int isPressed(int button); // Check if a key is pressed
void uInit(); //Init lib
void uDeInit(); //De-init lib

#endif /* USCREEN_H */

