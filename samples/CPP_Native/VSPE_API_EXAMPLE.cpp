#include <stdio.h>
#include <conio.h>

// include VSPE API header and library
#include "VSPE_API.h"
#pragma comment(lib,"VSPE_API.lib")

int main()
{
    // ****************************
    // STEP 1 - INITIALIZATION
    // ****************************
    const char* config_file_path = "1.vspe";
    const char* activationKey = ""; // <-----  PUT ACTIVATION KEY HERE

    bool result;

    // display VSPE API version info
    printf("%s\n",vspe_getVersionInformation());

    // activate VSPE API
    result = vspe_activate(activationKey);
    if(result == false){
        printf("VSPE API activation error");
        return 1;
    }

    // initialize VSPE python binding subsystem
    result = vspe_initialize();

    if(result == false){
        printf("Initialization error");
        return 1;
    }


    // remove all existing devices
    vspe_destroyAllDevices();

    // stop current emulation
    result = vspe_stopEmulation();


    if(result == false)
    {
        printf("Error: emulation can not be stopped: maybe one of VSPE devices is still used.");
        vspe_release();
        return 1;
    }

    // *********************************
    // Dynamically creating devices
    // *********************************
    // Create Connector device (COM9, no baud rate emulation)
    int deviceId = vspe_createDevice("Connector", "9;0");
    if(deviceId == -1)
    {
        printf("Error: can not create device\n");
        vspe_release();
        return 1;
    }

    // Create Splitter (COM9 => COM10)
    deviceId = vspe_createDevice("Splitter", "10;9;0;19200,0,8,1,0,0;0;0;0");
    if(deviceId == -1)
    {
        printf("Error: can not create device\n");
        vspe_release();
        return 1;
    }

    // Create Pair device (COM21 => COM22)
    deviceId = vspe_createDevice("Pair", "21;22;0");
    if(deviceId == -1)
    {
        printf("Error: can not create device\n");
        vspe_release();
        return 1;
    }


    // *********************************
    // Working with configuration files
    // *********************************

    // save configuration to file
    result = vspe_saveConfiguration(config_file_path);
    if(result == false)
    {
        printf("Error: can not save configuration");
        vspe_release();
        return 1;
    }

    // load configuration from file
    result = vspe_loadConfiguration(config_file_path);
    if(result == false)
    {
        printf("Error: can not load configuration");
        vspe_release();
        return 1;
    }


    // ****************************
    // STEP 2 - EMULATION LOOP
    // ****************************

    // start emulation
    result = vspe_startEmulation();
    if(result == false)
    {
        printf("Error: can not start emulation");
        vspe_release();
        return 1;
    }


    // *********************************
    // Extracting devices information
    // *********************************
    int i, count = vspe_getDevicesCount();
    for(i = 0;i<count;++i)
    {
        int ok, used;
        const char* name, *initString;
        int deviceId = vspe_getDeviceIdByIdx(i);
        if(vspe_getDeviceInfo(deviceId, &name, &initString, &ok, &used))
        {
            printf("Detected device: %s (%s). Status: %s, Used: %s\n",
                name, initString, ok == 1 ? "OK" : "ERROR",
                used == 1 ? "YES" : "NO");
        }
    }


    // emulation loop
    printf("Press any key to quit");
    _getch();

    // ****************************
    // STEP 3 - EXIT
    // ****************************

    // stop emulation before exit (skip this call to force kernel devices continue to work)
    result = vspe_stopEmulation();
    if(result == false)
    {
        printf("Error: emulation can not be stopped: maybe one of VSPE devices is still used.");
        return 1;
    } // if(result == false)


    // release VSPE
    vspe_release();
    return 0;
}