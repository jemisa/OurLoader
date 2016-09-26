#include <stdlib.h>
#include <stdio.h>
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "system/memory.h"
#include "utils/utils.h"
#include "common/common.h"
#include "uscreen.h"

int launched = 0; //Used for relaunch

int load = 0;

/* Main Application */
int Menu_Main(void)
{
    if(launched) return EXIT_SUCCESS;

    launched=1; //Used for relaunch

    uprintf("OurLoader - A Region Free Wii U Disc Loader\n"); //Print text to screen...
	uprintf("OurBrew Team - code from Dimok (DDD) and rw-r-r_0644 (easylib)\n");
    uprintf("Press A to launch disk\n");
    uprintf("Press B to exit\n");
    while(1) {
        updatePressedButtons(); //Update buttons state
        if(isPressed(VPAD_BUTTON_B)) break; //Check if b is pressed
        if(isPressed(VPAD_BUTTON_A)) {
        	load=1;
        	break;
        }
    }


    if (load) { //If A pressed then load disk
    	uprintf("Loading disk...\n");
    	char buf_vol_odd[20] = "/vol/storage_odd03";
    	_SYSLaunchTitleByPathFromLauncher(buf_vol_odd, 18, 0); //Load /vol/storage_odd03 (disk)
    }

    uprintf("Exiting...\n");

	if (load) {
		return EXIT_RELAUNCH_ON_LOAD; //Exit
	} else {
		return EXIT_SUCCESS;
	}
}
