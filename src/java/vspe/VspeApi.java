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

package vspe;

/**
 *
 * @author scream3r
 */
public class VspeApi {

    /**
     * Activate VSPE API using activation key
     */
    public static native boolean activate(String key);

    /**
     * Initialize VSPE core
     */
    public static native boolean initialize();

    /**
     * Load configuration file
     */
    public static native boolean loadConfiguration(String fileName);

    /**
     * Save configuration
     */
    public static native boolean saveConfiguration(String fileName);

    /**
     * Create device
     * @param deviceName Device name. For example "Connector", "Splitter", "Pair" etc.
     * @param initString device initialization string
     *
     * @return Device id
     */
    public static native int createDevice(String deviceName, String initString);

    /**
     * Destroy device by deviceId
     * @param deviceId Device id
     */
    public static native boolean destroyDevice(int deviceId);

    /**
     * Get VSPE devices count
     */
    public static native int getDevicesCount();

    /**
     * Get VSPE deviceId by device index
     * @param idx device index
     *
     * @return deviceId
     */
    public static native int getDeviceIdByIdx(int idx);

    /**
     * Get VSPE deviceId by COM port index
     */
    public static native int getDeviceIdByComPortIndex(int comPortIdx);

    /**
     * Get device information
     *
     * @return String array with length == 4<br>
     * [0] - Device name<br>
     * [1] - Device initString<br>
     * [2] - Device state (1 = good)<br>
     * [3] - Device clients count (0 - not used)<br>
     *
     * If error occurred <b>null</b> will be returned
     */
    public static native String[] getDeviceInfo(int deviceId);

    /**
     * Reinitialize device by deviceId
     */
    public static native boolean reinitializeDevice(int deviceId);

    /**
     * Destroy all devices
     */
    public static native boolean destroyAllDevices();

    /**
     * Start emulation
     */
    public static native boolean startEmulation();

    /**
     * Stop emulation
     */
    public static native boolean stopEmulation();

    /**
     * Release VSPE core
     */
    public static native void release();

    /**
     * Get VSPE API version information
     */
    public static native String getVersionInformation();
}
