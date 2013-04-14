#python

# --------------------------------------
# VSPE python subsystem usage sample
# --------------------------------------

import msvcrt
import VSPE_Python

config_file_path = '1.vspe'
activationKey = ''; # <-----  PUT ACTIVATION KEY HERE

# display VSPE API version information
print VSPE_Python.vspe_getVersionInformation()


# ****************************
# STEP 1 - INITIALIZATION
# ****************************

# activate VSPE API
result = VSPE_Python.vspe_activate(activationKey)
if result == False:
	print 'VSPE API activation error'
	exit(1)

# initialize VSPE python binding subsystem
result = VSPE_Python.vspe_initialize()

if result == False:
	print 'Initialization error'
	exit(1)

# stop current emulation
result = VSPE_Python.vspe_stopEmulation()
if result == False:
	print 'Error: emulation can not be stopped: maybe one of VSPE devices is still used.'
	exit(1)



# *********************************
# Dynamically creating devices
# *********************************
# Create Connector device (COM9, no baud rate emulation)
deviceId = VSPE_Python.vspe_createDevice("Connector", "9;0");
if deviceId == -1:
	print 'Error: can not create device'
	VSPE_Python.vspe_release()
	exit(1)


# *********************************
# Working with configuration files
# *********************************

# save configuration to file
result = VSPE_Python.vspe_saveConfiguration(config_file_path)
if result == False:
	print 'Error: can not save configuration'
	VSPE_Python.vspe_release()
	exit(1)


# load configuration from file
result = VSPE_Python.vspe_loadConfiguration(config_file_path)
if result == False:
	print 'Error: can not load configuration'
	VSPE_Python.vspe_release()
	exit(1)

# ****************************
# STEP 2 - EMULATION LOOP
# ****************************

# start emulation
result = VSPE_Python.vspe_startEmulation()
if result == False:
	print 'Error: can not start emulation'
	VSPE_Python.vspe_release()
	exit(1)

# emulation loop
print 'Press any key to quit'
msvcrt.getch()


# ****************************
# STEP 3 - EXIT
# ****************************

# stop emulation before exit (skip this call to force kernel devices work without this script)
result = VSPE_Python.vspe_stopEmulation()
if result == False:
	print 'Error: emulation can not be stopped: maybe one of VSPE devices is still used.'
	exit(1)


# release VSPE python binding subsystem before exit
VSPE_Python.vspe_release()
exit(0)
