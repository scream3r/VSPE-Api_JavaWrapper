VSPE Api (VIRTUAL SERIAL PORTS EMULATOR) Java Wrapper

It's a test project for using of VSPE-Api (http://www.eterlogic.com/)

This repo contains:
    bins -> VSPE binaries needed for using VSPE-Api
	include -> VSPE includes
	smaples -> examples of using api
	src -> the main example (main.c)
	
For building main.c in MinGW use this compiler string: gcc main.c VSPE_API.lib -o main.exe