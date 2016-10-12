//Version francaise d'OurLoader pour http://www.logic-sunrise.com/

//C libs
#include <stdlib.h>
#include <stdio.h>

// Wii U system libs
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "system/memory.h"
#include "common/common.h"

//Uscreen lib (fork of easy_lib)
#include "uscreen.h"

int launched = 0; //Used for relaunch

int load = 0;

/* Main Application */
int Menu_Main(void)
{
    if(launched) return EXIT_SUCCESS; //If game was previously loaded , we exit to HBL

    launched=1; //Used for relaunch

    uprintf("OurLoader - Lancez des disques de toutes régions !\n"); //Print text to screen...
    uprintf("Version francaise pour LogicSunrise\n");
	uprintf("Team OurBrew - code de Dimok (DDD) et de rw-r-r_0644 (easylib)\n");
    uprintf("Appuyez sur A pour lancer le disque\n");
    uprintf("Appuyez sur X pour lancer le menu HOME\n");
    uprintf("Appuyez sur B pour quitter\n");
    while(1) {
        updatePressedButtons(); //Update buttons state
        if(isPressed(VPAD_BUTTON_B)) break; //Check if b is pressed
        if(isPressed(VPAD_BUTTON_X)) SYSLaunchMenu(); //check if X is pressed
        if(isPressed(VPAD_BUTTON_A)) { //Ckeck if a is pressed
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
		return EXIT_RELAUNCH_ON_LOAD; //Exit and relaunch after game closed
	} else {
		return EXIT_SUCCESS; //Exit
	}
}
