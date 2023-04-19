/*
 * Copyright (C) 2020 DJI.
 *
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-08-25     robomaster   first version
 */

#include "RMTT_Libs.h"
#include "RMTT_Protocol.h"

static uint16_t sdk_time = 0;

RMTT_Protocol::RMTT_Protocol()
{
}

RMTT_Protocol::RMTT_Protocol(uint16_t time)
{
  sdk_time = time;
}

RMTT_Protocol::~RMTT_Protocol()
{
}

void RMTT_Protocol::nonblockSendTelloCtrlMsg(char *cmd)
{
  Serial1.printf("[TELLO] %s", cmd);
  if (sdk_time)
  {
    delay(sdk_time);
  }
}

void RMTT_Protocol::SDKOn()
{
  nonblockSendTelloCtrlMsg((char *)"command");
}

void RMTT_Protocol::SDKOff()
{
}

void RMTT_Protocol::TakeOff()
{
  nonblockSendTelloCtrlMsg((char *)"takeoff");
}

void RMTT_Protocol::Land()
{
  nonblockSendTelloCtrlMsg((char *)"land");
}

void RMTT_Protocol::Emergency()
{
  nonblockSendTelloCtrlMsg((char *)"emergency");
}

void RMTT_Protocol::Up(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "up %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Down(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "down %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Left(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "left %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Right(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "right %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Forward(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "forward %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Back(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "res %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::CW(uint16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "cw %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::CCW(uint16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "ccw %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Flip(char x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "flip %c", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Go(int16_t x, int16_t y, int16_t z, uint16_t speed)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "go %d %d %d %d", x, y, z, speed);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "go %d %d %d %d %s", x, y, z, speed, mid);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Stop()
{
  nonblockSendTelloCtrlMsg((char *)"stop");
}

void RMTT_Protocol::Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d", x1, y1, z1, x2, y2, z2, speed);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d %s", x1, y1, z1, x2, y2, z2, speed, mid);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::Jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid1, char *mid2)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "jump %d %d %d %d %d %s %s", x, y, z, speed, yaw, mid1, mid2);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::SetSpeed(int16_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "speed %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::SetRC(int16_t a, int16_t b, int16_t c, int16_t d)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "rc %d %d %d %d", a, b, c, d);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::SetMon()
{
  nonblockSendTelloCtrlMsg((char *)"mon");
}

void RMTT_Protocol::SetMoff()
{
  nonblockSendTelloCtrlMsg((char *)"moff");
}

void RMTT_Protocol::SetMdirection(uint8_t x)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "mdirection %d", x);
  nonblockSendTelloCtrlMsg((char *)s);
}

void RMTT_Protocol::ReadSpeed()
{
  nonblockSendTelloCtrlMsg((char *)"speed?");
}

void RMTT_Protocol::ReadBattery()
{
  nonblockSendTelloCtrlMsg((char *)"battery?");
}

void RMTT_Protocol::ReadTime()
{
  nonblockSendTelloCtrlMsg((char *)"time?");
}

void RMTT_Protocol::ReadSN()
{
  nonblockSendTelloCtrlMsg((char *)"sn?");
}

void RMTT_Protocol::ReadSDKVersion()
{
  nonblockSendTelloCtrlMsg((char *)"sdk?");
}

void RMTT_Protocol::startUntilControl()
{
  pinMode(34, INPUT_PULLUP);
  RMTT_RGB::Init();
  while (!(getTelloMsgString("[TELLO] command", 1000) == String("ETT ok")))
  {
  }
  RMTT_RGB::SetRGB(0, 255, 0);
  while (!((digitalRead(34)) == 0))
  {
  }
  RMTT_RGB::SetRGB(0, 0, 0);
  delay(1000);
  RMTT_RGB::SetRGB(0, 255, 0);
  delay(1000);
  RMTT_RGB::SetRGB(0, 0, 0);
}

// 静态函数
String RMTT_Protocol::getTelloMsgString(char *cmd, uint32_t timeout)
{
  while (Serial1.available())
  {
    Serial1.read();
  }
  String res;
  Serial1.printf(cmd);
  long oldtime = millis();
  while (!Serial1.available())
  {
    long newtime = millis();
    if ((newtime - oldtime) > timeout)
    {
      res = "timeout";
      return res;
    }
  }
  while (Serial1.available())
  {
    res += String(char(Serial1.read()));
  }
  if (res.endsWith("\r\n"))
  {
    res = res.substring(0, res.indexOf("\r\n"));
  }
  return res;
}

int RMTT_Protocol::getTelloMsgInt(char *cmd, uint32_t timeout)
{
  while (Serial1.available())
  {
    Serial1.read();
  }
  Serial1.printf(cmd);
  long oldtime = millis();
  while (!Serial1.available())
  {
    long newtime = millis();
    if ((newtime - oldtime) > timeout)
    {
      return -1;
    }
  }
  String res;
  while (Serial1.available())
  {
    res += String(char(Serial1.read()));
  }
  if (res.endsWith("\r\n"))
  {
    res = res.substring(0, res.indexOf("\r\n"));
  }
  return res.substring(res.indexOf(' ') + 1, res.length()).toInt();
}

String RMTT_Protocol::getTelloResponseString(uint32_t timeout)
{
  String res;
  long oldtime = millis();
  while (!Serial1.available())
  {
    long newtime = millis();
    if ((newtime - oldtime) > timeout)
    {
      res = "timeout";
      return res;
    }
  }
  while (Serial1.available())
  {
    res += String(char(Serial1.read()));
  }
  if (res.endsWith("\r\n"))
  {
    res = res.substring(0, res.indexOf("\r\n"));
  }
  return res;
}

int RMTT_Protocol::getTelloResponseInt(uint32_t timeout)
{
  String res;
  long oldtime = millis();
  while (!Serial1.available())
  {
    long newtime = millis();
    if ((newtime - oldtime) > timeout)
    {
      return -1;
    }
  }
  while (Serial1.available())
  {
    res += String(char(Serial1.read()));
  }
  if (res.endsWith("\r\n"))
  {
    res = res.substring(0, res.indexOf("\r\n"));
  }
  return res.substring(res.indexOf(' ') + 1, res.length()).toInt();
}

// Number of sent commands
uint8_t cmdId = 0;
// Number of tries to send the same command
uint8_t tryCount = 0;

String RMTT_Protocol::blockSendTelloCtrlMsg(char *cmd_str, uint32_t timeout)
{
  long blockedTime = millis();
  tryCount = 0;
  String res;
  while (millis() - blockedTime <= timeout)
  {
    // discard the previous command responses/debris
    while (Serial1.available())
      Serial1.read();

    Serial1.printf("[TELLO] Re%02x%02x %s", cmdId, tryCount++, cmd_str);

    // While there is no response and blockedTime is less than timeout, send the command again
    while (!Serial1.available())
    {
      if (millis() - blockedTime >= timeout)
        return String("timeout");
      delay(100);
      Serial1.printf("[TELLO] Re%02x%02x %s", cmdId, tryCount++, cmd_str);
    }

    res = "";
    while (Serial1.available())
      res += String(char(Serial1.read()));

    char *hasError = strstr(res.c_str(), "error");
    // ETT Re[tag][id] ok/error
    // ETT Rexxxx ok/error
    if (hasError != NULL)
    {
      delay(100);
      tryCount++;
      continue;
    }

    cmdId++;
    return res;
  }
  res = res == String("") ? String("timeout") : res;
  return res;
}
