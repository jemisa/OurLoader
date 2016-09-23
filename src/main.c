#include <stdlib.h>
#include <stdio.h>
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "system/memory.h"
#include "utils/utils.h"
#include "common/common.h"
#include "uscreen.h"

int launched = 0;

/* Entry point */
int Menu_Main(void)
{
    if(launched) return EXIT_SUCCESS;

    //Init dynamic libraries
    InitOSFunctionPointers();
    InitVPadFunctionPointers();
    InitSysFunctionPointers();
    
    launched=1; //Used for relaunch
    
    uprintf("OurLoader");
    uprintf("Press A to launch disk");
    while(1) { 
        updatePressedButtons(); //Update buttons state
        if(isPressed(VPAD_BUTTON_A)) break; //Check if home is pressed
    }
    
    uDeInit();
    
    char buf_vol_odd[20] = "/vol/storage_odd03";
    _SYSLaunchTitleByPathFromLauncher(buf_vol_odd, 18, 0);

    return EXIT_RELAUNCH_ON_LOAD;
}

