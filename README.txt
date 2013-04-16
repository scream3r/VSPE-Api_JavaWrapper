VSPE Api (VIRTUAL SERIAL PORTS EMULATOR) Java Wrapper

It's a test project for using of VSPE-Api (http://www.eterlogic.com/)

This repo contains:
    bins -> VSPE binaries needed for using VSPE-Api
    include -> VSPE includes
    smaples -> examples of using api
    src -> C(JNI) and Java Wrapper sources
	
For building VspeApi.c in MinGW use this compiler string: gcc VspeApi.c -I{JDK_INCLUDE_PATH} -I{JDK_INCLUDE_PATH\win32} -O3 -D_JNI_IMPLEMENTATION_ -Wl,--kill-at -shared -o VSPE-Wrapper.dll -L. -lVSPE_API