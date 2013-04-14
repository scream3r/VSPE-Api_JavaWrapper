#python
import win32com.client
import msvcrt

vspe = win32com.client.Dispatch("VSPE.VSPEApi")
activationKey = ''; # <-----  PUT ACTIVATION KEY HERE

# display VSPE API version information
print vspe.vspe_getVersionInformation()

# activate VSPE API
vspe.vspe_activate(activationKey)

# initialize VSPE
vspe.vspe_initialize()

# create Connector (COM9, no baud rate emulation)
vspe.vspe_createDevice('Connector','9;0')

# create Splitter (COM9 => COM10)
vspe.vspe_createDevice('Splitter','10;9;0;19200,0,8,1,0,0;0;0;0')

# create Pair device (COM21 => COM22)
vspe.vspe_createDevice('Pair','21;22;0')

# start emulation
vspe.vspe_startEmulation()

# wait for any key ...
print 'Press any key to quit'
msvcrt.getch()


# stop emulation
vspe.vspe_stopEmulation()

# release VSPE
vspe.vspe_release()

