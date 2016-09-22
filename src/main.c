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
#include "uscreen.h"

int launched = 0;

/* Entry point */
int Menu_Main(void)
{
    if(launched) return EXIT_SUCCESS;
    //!*******************************************************************
    //!                   Initialize function pointers                   *
    //!*******************************************************************
    //! do OS (for acquire) and sockets first so we got logging
    InitOSFunctionPointers();
    InitSocketFunctionPointers();

    log_init("192.168.178.3");
    log_print("Starting launcher\n");

    InitFSFunctionPointers();
    InitVPadFunctionPointers();
    
    InitSysFunctionPointers();
    
    log_print("Function exports loaded\n");

    //!*******************************************************************
    //!                    Initialize heap memory                        *
    //!*******************************************************************
    log_print("Initialize memory management\n");
    //! We don't need bucket and MEM1 memory so no need to initialize
    memoryInitialize();

    //!*******************************************************************
    //!                        Initialize FS                             *
    //!*******************************************************************
    log_printf("Mount SD partition\n");
    mount_sd_fat("sd");
    

    //!*******************************************************************
    //!                    Enter main application                        *
    //!*******************************************************************

    log_printf("Unmount SD\n");
    unmount_sd_fat("sd");
    log_printf("Release memory\n");
    memoryRelease();
    log_deinit();
    
    launched=1;
    
    uprintf("OurLoader");
    uprintf("Press A to launch disk");
    	while(1) { 
		
		updatePressedButtons(); //Update buttons state
		if(isPressed(VPAD_BUTTON_A)) break; //Check if home is pressed
	}
    char buf_vol_odd[20];
        snprintf(buf_vol_odd, sizeof(buf_vol_odd), "%s", "/vol/storage_odd03");
        _SYSLaunchTitleByPathFromLauncher(buf_vol_odd, 18, 0);

    return EXIT_RELAUNCH_ON_LOAD;

}

