/*
 * Copyright (C) 2020 DJI.
 *
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-08-25     robomaster   first version
 */

#pragma once

#include <Arduino.h>

class RMTT_Protocol
{
public:
    RMTT_Protocol();
    RMTT_Protocol(uint16_t time);
    ~RMTT_Protocol();

    void SDKOn(std::function<void(char *cmd, String res)> callback = NULL);
    void SDKOff(std::function<void(char *cmd, String res)> callback = NULL);

    void TakeOff(std::function<void(char *cmd, String res)> callback = NULL);
    void Land(std::function<void(char *cmd, String res)> callback = NULL);
    void Emergency(std::function<void(char *cmd, String res)> callback = NULL);
    void Up(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Down(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Left(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Right(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Forward(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Back(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void CW(uint16_t x ,std::function<void(char *cmd, String res)> callback = NULL);
    void CCW(uint16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void Flip(char x, std::function<void(char *cmd, String res)> callback = NULL);
    void Go(int16_t x, int16_t y, int16_t z, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    void Go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    void Stop(std::function<void(char *cmd, String res)> callback = NULL);
    void Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, std::function<void(char *cmd, String res)> callback = NULL);
    void Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback = NULL);
    void Jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid, char *mid2, std::function<void(char *cmd, String res)> callback = NULL);

    void SetSpeed(int16_t x, std::function<void(char *cmd, String res)> callback = NULL);
    void SetRC(int16_t a, int16_t b, int16_t c, int16_t d, std::function<void(char *cmd, String res)> callback = NULL);
    void SetMon(std::function<void(char *cmd, String res)> callback = NULL);
    void SetMoff(std::function<void(char *cmd, String res)> callback = NULL);
    void SetMdirection(uint8_t x, std::function<void(char *cmd, String res)> callback = NULL);

    void ReadSpeed(std::function<void(char *cmd, String res)> callback = NULL);
    void ReadBattery(std::function<void(char *cmd, String res)> callback = NULL);
    void ReadTime(std::function<void(char *cmd, String res)> callback = NULL);
    void ReadSN(std::function<void(char *cmd, String res)> callback = NULL);
    void ReadSDKVersion(std::function<void(char *cmd, String res)> callback = NULL);

    // 函数声明
    String getTelloMsgString(char *cmd, uint32_t timeout);
    int getTelloMsgInt(char *cmd, uint32_t timeout);
    String getTelloResponseString(uint32_t timeout);
    int getTelloResponseInt(uint32_t timeout);
    void startUntilControl();
   
    void sendCmd(char *cmd, std::function<void(char *cmd,  String res)> callback = NULL);
};
