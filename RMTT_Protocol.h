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
#include "models/Coordinate.h"

class RMTT_Protocol
{
public:
    RMTT_Protocol();
    RMTT_Protocol(uint16_t time);
    ~RMTT_Protocol();

    void sdkOn(std::function<void(char *cmd, String res)> callback = NULL);

    void takeOff(std::function<void(char *cmd, String res)> callback = NULL);
    void land(std::function<void(char *cmd, String res)> callback = NULL);
    void streamOn(std::function<void(char *cmd, String res)> callback = NULL);
    void streamOff(std::function<void(char *cmd, String res)> callback = NULL);
    void emergency(std::function<void(char *cmd, String res)> callback = NULL);
    void up(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void down(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void left(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void right(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void forward(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void back(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void clockWise(uint16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void counterClockWise(uint16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void motorOn(std::function<void(char *cmd, String res)> callback = NULL);
    void motorOff(std::function<void(char *cmd, String res)> callback = NULL);
    void throwFly(std::function<void(char *cmd, String res)> callback = NULL);
    void flip(char x, std::function<void(char *cmd, String res)> callback = NULL);
    void go(int16_t x, int16_t y, int16_t z, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    void go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    void moveRealtiveTo(Coordinate p1, Coordinate p2, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    void stop(std::function<void(char *cmd, String res)> callback = NULL);
    void curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    void curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    void jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid, char *mid2, std::function<void(char *cmd, String res)> callback = NULL);

    void setSpeed(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void setRC(int16_t a, int16_t b, int16_t c, int16_t d, std::function<void(char *cmd, String res)> callback = NULL);
    void setDroneWifi(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);
    void setMon(std::function<void(char *cmd, String res)> callback = NULL);
    void setMoff(std::function<void(char *cmd, String res)> callback = NULL);
    void setOneDirection(uint8_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void setAP(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);
    void setWiFiChannel(uint16_t channel, std::function<void(char *cmd, String res)> callback = NULL);
    void setPortStatusStreaming(uint16_t portStatus, uint16_t portStreaming, std::function<void(char *cmd, String res)> callback);
    void setFPS(char *fps, std::function<void(char *cmd, String res)> callback = NULL);
    void setBitrate(uint8_t bitrate, std::function<void(char *cmd, String res)> callback = NULL);
    // resolution solo puede ser "high" o "low"
    void setResolution(char *resolution, std::function<void(char *cmd, String res)> callback = NULL);
    void setMultiFiwiSSIDPass(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback = NULL);

    void getSpeed(std::function<void(char *cmd, String res)> callback = NULL);
    void getBattery(std::function<void(char *cmd, String res)> callback = NULL);
    void getMotorTime(std::function<void(char *cmd, String res)> callback = NULL);
    void getWiFi(std::function<void(char *cmd, String res)> callback = NULL);
    void getSN(std::function<void(char *cmd, String res)> callback = NULL);
    void getSDKVersion(std::function<void(char *cmd, String res)> callback = NULL);
    void getHardwareInfo(std::function<void(char *cmd, String res)> callback = NULL);
    void getWiFiVersion(std::function<void(char *cmd, String res)> callback = NULL);
    void getApInfo(std::function<void(char *cmd, String res)> callback = NULL);
    void getSSID(std::function<void(char *cmd, String res)> callback = NULL);

    String getTelloMsgString(char *cmd, uint32_t timeout);
    int getTelloMsgInt(char *cmd, uint32_t timeout);
    String getTelloResponseString(uint32_t timeout);
    int getTelloResponseInt(uint32_t timeout);
    void startUntilControl();

    void sendCmd(char *cmd, std::function<void(char *cmd, String res)> callback = NULL);
};
