/*
 * Copyright (C) 2023 LCD.
 *
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 *
 * Change Logs:
 * Date           Authors                           Notes
 * 2023-05-05     Amallo, Sofía / Gil Juan Manuel   second version
 */

#pragma once

#include <Arduino.h>
#include <queue>
#include "models/Coordinate.h"

class RMTT_Protocol
{
private:
    static RMTT_Protocol *instance;
    RMTT_Protocol() {}
    RMTT_Protocol(uint16_t time) {}
    RMTT_Protocol(RMTT_Protocol const &) {}
    RMTT_Protocol &operator=(RMTT_Protocol const &) {} 

public:
    static RMTT_Protocol *getInstance();
    ~RMTT_Protocol();

    /**********************     Flight Control      **********************/
    /**
     * @brief Enter SDK mode
     */
    void sdkOn(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Auto take off
     */
    void takeOff(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Auto landing
     */
    void land(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Turn on the video stream
     */
    void streamOn(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Turn off the video stream
     */
    void streamOff(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Stop the motor from running
     */
    void emergency(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly upwards by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void up(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly downwards by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void down(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly to the left by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void left(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly to the right by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void right(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly forward by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void forward(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly backwards by x cm.
     * @param x: distance in cm. Can be between 20 and 500.
     */
    void back(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Rotate clockwise by x degrees.
     * @param x: degrees. Can be between 1 and 360.
     */
    void clockWise(uint16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Rotate counter clockwise by x degrees.
     * @param x: degrees. Can be between 1 and 360.
     */
    void counterClockWise(uint16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Enter motoron mode.
     * The Motor-On mode is a new low-speed rotation state of TT propellers. Entering Motor-On mode indicates that the TT is ready for takeoff. After the drone takes off, it automatically exits Motor-On mode.
     */
    void motorOn(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Exit motoron mode.
     */
    void motorOff(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Throw to launch. Throw the drone horizontally within 5s of sending the command.
     */
    void throwFly(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Roll in the x direction.
     * @param x: direction. 'l': left, 'r': right, 'f': forward, 'b': back.
     */
    void flip(char x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly to the coordinates (x, y, z) at speed (cm/s)[x, y and z cannot be between -20 and 20 at the same time]
     * @param x: x coordinate. Can be between -500 and 500.
     * @param y: y coordinate. Can be between -500 and 500.
     * @param z: z coordinate. Can be between -500 and 500.
     * @param speed: speed in cm/s. Can be between 10 and 100.
     *
     */
    void go(int16_t x, int16_t y, int16_t z, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly to the coordinates (x, y, z) in the coordinate system of the mission pad with the specified ID at the set speed (m/s)
     * @param x: x coordinate. Can be between -500 and 500.
     * @param y: y coordinate. Can be between -500 and 500.
     * @param z: z coordinate. Can be between 0 and 500.
     * @param speed: speed in cm/s. Can be between 10 and 100.
     * @param mid: mission pad ID. Can be between 1 and 9.
     */
    void go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Executes "go" command relative to the starting point.
     * @param p1: Coordinate object containing the x, y and z coordinates of the origin point.
     * @param p2: Coordinate object containing the x, y and z coordinates of the destination point.
     * @param speed: speed in cm/s. Can be between 10 and 100.
     */
    void moveRealtiveTo(Coordinate p1, Coordinate p2, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Stop moving and hover immediatly.
     */
    void stop(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly in a curve from (x1, y1, z1) to (x2, y2, z2) at the set speed (cm/s).
     * If the radius of the curve is not within 0.5-10 meters the corresponding reminder will be returned.
     * @param x1: x coordinate of the starting point. Can be between -500 and 500.
     * @param y1: y coordinate of the starting point. Can be between -500 and 500.
     * @param z1: z coordinate of the starting point. Can be between -500 and 500.
     * @param x2: x coordinate of the end point. Can be between -500 and 500.
     * @param y2: y coordinate of the end point. Can be between -500 and 500.
     * @param z2: z coordinate of the end point. Can be between -500 and 500.
     * @param speed: speed in cm/s. Can be between 10 and 60.
     */
    void curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly in a curve from (x1, y1, z1) to (x2, y2, z2) in the coordinate system of the mission pad with the specified ID at the set speed (cm/s). If the radius of the curve is not within 0.5-10 meters the corresponding reminder will be returned.
     * @param x1: x coordinate of the starting point. Can be between -500 and 500.
     * @param y1: y coordinate of the starting point. Can be between -500 and 500.
     * @param z1: z coordinate of the starting point. Can be between -500 and 500.
     * @param x2: x coordinate of the end point. Can be between -500 and 500.
     * @param y2: y coordinate of the end point. Can be between -500 and 500.
     * @param z2: z coordinate of the end point. Can be between -500 and 500.
     * @param speed: speed in cm/s. Can be between 10 and 60.
     * @param mid: ID of the mission pad. Can be between 1 and 9.
     */
    void curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Fly to the poing (x, y, z) in the mid1 coordinate system and hovers. Then, it identifies the mission pad of mid2 and rotates to the position (0,0,z) in the mid2 coodrinate system to set the yaw value (z>0).
     */
    void jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid, char *mid2, std::function<void(char *cmd, String res)> callback = NULL);

    /*******************     Setters     *******************/

    /**
     * @brief Set the current speed to x (cm/s).
     * @param x: speed in cm/s. Can be between 10 and 100.
     */
    void setSpeed(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the lever force values for the four channels of the remote control.
     * @param a: roll. Can be between -100 and 100.
     * @param b: pitch. Can be between -100 and 100.
     * @param c: throttle. Can be between -100 and 100.
     * @param d: yaw. Can be between -100 and 100.
     */
    void setRC(int16_t a, int16_t b, int16_t c, int16_t d, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Change the Tello Wi-Fi SSID and password. If an open-source controller is connecter, ssid adds the RMTT- prefix by default. Otherwise, it adds the TELLO- prefix.
     * @param ssid: new SSID.
     * @param pass: new password.
     *
     */
    void setDroneWifi(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Enables mission pad. By default, downward detection is enabled.
     */
    void setMon(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Disables mission pad detection.
     */
    void setMoff(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the direction of the detection.
     * @param x: 0, 1, 2. 0: downward detection enabled. 1: forward detection enabled. 2: both downward and forward detection enabled.
     */
    void setOneDirection(uint8_t x, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Switch Tello to Station mode and connect to the AP.
     * @param ssid: SSID of the AP.
     * @param pass: password of the AP.
     */
    void setAP(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set tie Wi-Fi channel of the open-source controller.
     * @param channel: Wi-Fi channel to be set.
     */
    void setWiFiChannel(uint16_t channel, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the ports for pushing status information and video streams.
     * @param portStatus: port for status information. Can be between 1025 and 65535.
     * @param portStreaming: port for video stream. Can be between 1025 and 65535.
     */
    void setPortStatusStreaming(uint16_t portStatus, uint16_t portStreaming, std::function<void(char *cmd, String res)> callback);
    /**
     * @brief Set the video stream frame rate.
     * @param fps: frame rate. Can be "high", "middle" or "low" indicanting 30fps, 15fps or 5fps respectively.
     */
    void setFPS(char *fps, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the video stream bitrate.
     * @param bitrate: bitrate. It has a value range of 0 to 5, indicating auto, 1MBps, 2MBps, 3MBps, 4MBps and 5MBps respectively.
     */
    void setBitrate(uint8_t bitrate, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the video stream resolution.
     * @param resolution: resolution. Can be "high" or "low" indicanting 720p and 480p respectively.
     */
    void setResolution(char *resolution, std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Set the SSID and password of the open-source controller. This feature supports connection to multiple devices as a router.
     */
    void setMultiFiwiSSIDPass(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);

    /*******************     Getters     *******************/

    /**
     * @brief Get the current speed (cm/s).
     * @returns speed in cm/s. Can be between 10 and 100.
     */
    void getSpeed(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the current battery percentage.
     * @returns battery percentage. Can be between 0 and 100.
     */
    void getBattery(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the current flight time (s).
     * @returns flight time in s.
     */
    void getMotorTime(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the Wi-Fi SNR.
     */
    void getWiFi(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the Tello's Serial Number.
     */
    void getSN(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the Tello's SDK version.
     */
    void getSDKVersion(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get whether TT is connected to an open-source controller.
     * @returns TELLO: not connected. RMTT: connected.
     */
    void getHardwareInfo(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Query the Wi-Fi version of the open-source controller. (Only applies to the open-source controller)
     * @returns wifivx.x.x.x
     */
    void getWiFiVersion(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the name and password of the current router to be connected. (Only applies to the open-source controller)
     */
    void getApInfo(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Get the current SSID and password of the drone. (Only applies to the open-source controller)
     */
    void getSSID(std::function<void(char *cmd, String res)> callback = NULL);
    /**
     * @brief Sends command and waits for it's response to return it as String. If the response is not available within the timeout, "timeout" is returned.
     */
    String getTelloMsgString(char *cmd, uint32_t timeout);
    /**
     * @brief Sends command and waits for it's response to return it as int. If the response is not available within the timeout, -1 is returned,  else the response is parsed and it's size is returned.
     */
    int getTelloMsgInt(char *cmd, uint32_t timeout);
    /**
     * @brief Get the response as String. If the response is not available within the timeout, "timeout" is returned, else
     */
    String getTelloResponseString(uint32_t timeout);
    /**
     * @brief Get the response as int. If the response is not available within the timeout, -1 is returned,  else the response is parsed and it's size is returned.
     */
    int getTelloResponseInt(uint32_t timeout);
    /**
     * @brief Sends the "command" command to enter SDK mode, then blocks until the button on the open-source controller is pressed.
     */
    void startUntilControl();
    /**
     * @brief Sends the command in the [TELLO] Re%02x%02x %s format, then waits for a response. If the response is not available within the timeout, the drone lands, else the respective callback function is called.
     */
    void sendCmd(char *cmd, std::function<void(char *cmd, String res)> callback = NULL);

    /**********************     Utils Control      **********************/

    void preProcessingRoute(Coordinate point, const char *unit);
};
