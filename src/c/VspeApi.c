/* VSPE-Wrapper (VIRTUAL SERIAL PORTS EMULATOR) - VSPE Api Java Wrapper.
 * © Alexey Sokolov (scream3r), 2013.
 *
 * This file is part of VSPE-Wrapper.
 *
 * VSPE-Wrapper is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VSPE-Wrapper is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with VSPE-Wrapper.  If not, see <http://www.gnu.org/licenses/>.
 *
 * e-mail: scream3r.org@gmail.com
 * web-site: https://github.com/scream3r
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "VSPE_API.h"
#include "vspe_VspeApi.h"

/*
 * Activate VSPE API using activation key
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_activate(JNIEnv *env, jclass clazz, jstring jKey) {
	const char* key = (*env)->GetStringUTFChars(env, jKey, JNI_FALSE);
	jboolean resultValue = vspe_activate(key) ? JNI_TRUE : JNI_FALSE;
	(*env)->ReleaseStringUTFChars(env, jKey, key);
	return resultValue;
}

/*
 * Initialize VSPE core
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_initialize(JNIEnv *env, jclass clazz) {
	return (vspe_initialize() ? JNI_TRUE : JNI_FALSE);
}

/*
 * Load configuration file
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_loadConfiguration(JNIEnv *env, jclass clazz, jstring jFileName) {
	const char* fileName = (*env)->GetStringUTFChars(env, jFileName, JNI_FALSE);
	jboolean resultValue = vspe_loadConfiguration(fileName) ? JNI_TRUE : JNI_FALSE;
	(*env)->ReleaseStringUTFChars(env, jFileName, fileName);
	return resultValue;
}

/*
 * Save configuration
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_saveConfiguration(JNIEnv *env, jclass clazz, jstring jFileName) {
	const char* fileName = (*env)->GetStringUTFChars(env, jFileName, JNI_FALSE);
	jboolean resultValue = vspe_saveConfiguration(fileName) ? JNI_TRUE : JNI_FALSE;
	(*env)->ReleaseStringUTFChars(env, jFileName, fileName);
	return resultValue;
}

/*
 * Create device
 * deviceName - Device name. For example "Connector", "Splitter", "Pair" etc.
 * initString - device initialization string
 *
 * return Device id
 */
JNIEXPORT jint JNICALL Java_vspe_VspeApi_createDevice(JNIEnv *env, jclass clazz, jstring jDeviceName, jstring jInitString) {
	const char* deviceName = (*env)->GetStringUTFChars(env, jDeviceName, JNI_FALSE);
	const char* initString = (*env)->GetStringUTFChars(env, jInitString, JNI_FALSE);
	jint resultValue = (jint)vspe_createDevice(deviceName, initString);
	(*env)->ReleaseStringUTFChars(env, jDeviceName, deviceName);
	(*env)->ReleaseStringUTFChars(env, jInitString, initString);
	return resultValue;
}

/*
 * Destroy device by deviceId
 *
 * @param deviceId Device id
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_destroyDevice(JNIEnv *env, jclass clazz, jint deviceId) {
	return (vspe_destroyDevice((int)deviceId) ? JNI_TRUE : JNI_FALSE);
}

/*
 * Get VSPE devices count
 */
JNIEXPORT jint JNICALL Java_vspe_VspeApi_getDevicesCount(JNIEnv *env, jclass clazz) {
	return (jint)vspe_getDevicesCount();
}

/*
 * Get VSPE deviceId by device index
 *
 * idx - device index
 *
 * return deviceId
 */
JNIEXPORT jint JNICALL Java_vspe_VspeApi_getDeviceIdByIdx(JNIEnv *env, jclass clazz, jint idx) {
	return (jint)vspe_getDeviceIdByIdx((int)idx);
}

/*
 * Get VSPE deviceId by COM port index
 */
JNIEXPORT jint JNICALL Java_vspe_VspeApi_getDeviceIdByComPortIndex(JNIEnv *env, jclass clazz, jint comPortIdx) {
	return (jint)vspe_getDeviceIdByComPortIndex((int)comPortIdx);
}

/*
 * Get device information
 *
 * return String array with length == 4
 * [0] - Device name
 * [1] - Device initString
 * [2] - Device state (1 = good)
 * [3] - Device clients count (0 - not used)
 *
 * If error occurred null will be returned
 */
JNIEXPORT jobjectArray JNICALL Java_vspe_VspeApi_getDeviceInfo(JNIEnv *env, jclass clazz, jint deviceId) {
	jobjectArray returnArray = NULL;
	int ok, used;
	const char *name, *initString;
	if(vspe_getDeviceInfo(deviceId, &name, &initString, &ok, &used)){
		char okStr[16];
		char usedStr[16];
		itoa(ok, okStr, 10);
		itoa(used, usedStr, 10);
		jclass stringClass = (*env)->FindClass(env, "java/lang/String");
		returnArray = (*env)->NewObjectArray(env, (jsize)4, stringClass, NULL);
		(*env)->SetObjectArrayElement(env, returnArray, 0, (*env)->NewStringUTF(env, name));
		(*env)->SetObjectArrayElement(env, returnArray, 1, (*env)->NewStringUTF(env, initString));
		(*env)->SetObjectArrayElement(env, returnArray, 2, (*env)->NewStringUTF(env, okStr));
		(*env)->SetObjectArrayElement(env, returnArray, 3, (*env)->NewStringUTF(env, usedStr));
	}
	return returnArray;
}

/*
 * Reinitialize device by deviceId
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_reinitializeDevice(JNIEnv *env, jclass clazz, jint deviceId) {
	return (vspe_reinitializeDevice((int)deviceId) ? JNI_TRUE : JNI_FALSE);
}

/*
 * Destroy all devices
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_destroyAllDevices(JNIEnv *env, jclass clazz) {
	return (vspe_destroyAllDevices() ? JNI_TRUE : JNI_FALSE);
}

/*
 * Start emulation
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_startEmulation(JNIEnv *env, jclass clazz) {
	return (vspe_startEmulation() ? JNI_TRUE : JNI_FALSE);
}

/*
 * Stop emulation
 */
JNIEXPORT jboolean JNICALL Java_vspe_VspeApi_stopEmulation(JNIEnv *env, jclass clazz) {
	return (vspe_stopEmulation() ? JNI_TRUE : JNI_FALSE);
}

/*
 * Release VSPE core
 */
JNIEXPORT void JNICALL Java_vspe_VspeApi_release(JNIEnv *env, jclass clazz) {
	vspe_release();
}

/*
 * Get VSPE API version information
 */
JNIEXPORT jstring JNICALL Java_vspe_VspeApi_getVersionInformation(JNIEnv *env, jclass clazz) {
	return (*env)->NewStringUTF(env, vspe_getVersionInformation());
}
