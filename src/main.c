#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


// include VSPE API header and library
#include "VSPE_API.h"
//#pragma comment(lib,"VSPE_API.lib")

int main()
{
    // ****************************
    // STEP 1 - INITIALIZATION
    // ****************************
    const char* config_file_path = "1.vspe";
    const char* activationKey = "SRBGMZSYPuIHWILsmLjF5CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPRJEEYxlJg+4gdYguyYuMXkIPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9CDyBL3GQYD0IPIEvcZBgPQg8gS9xkGA9JyUaC2ZWE1DZV2+wYWlRm7FFYrW3MDbZg8MkQsOQ8r1IPIEvcZBgPQg8gS9xkGA9LzrhjimHDiMlKqr6pSiw9CDl9n+0bAgFr2ho7nXjCoTMHYzt4tsbEkJGNktLGVG42SZ63UbmIUNcKmfhSzXldVCLhfvZv3StR9c/vkYG471Nh62eC1qIYuBUvm+a3BK8iR0POD8w5ovtuYr0T8aQP3eh4b8lUwnPHG9NRJxerttq/+/zX7c++9LDSQym3ThbWesK+A+X/vNw9qDgYt1dsJxDEEytsCRiT7bTiV5Djh1RlpIwETXWA089hiE9OYd7GpjKLq5dQOqSVcA3Fg1Wfdbqn/yn8q0/AIDOd0iZlbVeLY68zKh1Di4gGEoa1kR8EOBp2mxeaFrfwUm3DsJ5Pc04f7aEw9XljfBUwl/bAs3LVH5HRii8lXZvUVvnnfpcQ==1F250CF0960AE1C09E9450C816DE1232"; // <-----  PUT ACTIVATION KEY HERE

    bool result;

    // display VSPE API version info
    printf("%s\n",vspe_getVersionInformation());

    // activate VSPE API
    result = vspe_activate(activationKey);
    if(result == false){
        printf("VSPE API activation error");
        return 1;
    }
    else {
    	printf("VSPE API activated\n");
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
