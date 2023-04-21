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

RMTT_Protocol::~RMTT_Protocol()
{
}

void RMTT_Protocol::SDKOn(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"command", callback);
}

void RMTT_Protocol::SDKOff(std::function<void(char *cmd, String res)> callback)
{
}

void RMTT_Protocol::TakeOff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"takeoff", callback);
}

void RMTT_Protocol::Land(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"land", callback);
}

void RMTT_Protocol::Emergency(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"emergency", callback);
}

void RMTT_Protocol::Up(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "up %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Down(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "down %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Left(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "left %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Right(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "right %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Forward(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "forward %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Back(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "res %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::CW(uint16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "cw %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::CCW(uint16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "ccw %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Flip(char x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "flip %c", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Go(int16_t x, int16_t y, int16_t z, uint16_t speed, std::function<void(char *cmd, String res)> callback)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "go %d %d %d %d", x, y, z, speed);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "go %d %d %d %d %s", x, y, z, speed, mid);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Stop(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"stop", callback);
}

void RMTT_Protocol::Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, std::function<void(char *cmd, String res)> callback)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d", x1, y1, z1, x2, y2, z2, speed);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d %s", x1, y1, z1, x2, y2, z2, speed, mid);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::Jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid1, char *mid2, std::function<void(char *cmd, String res)> callback)
{
  char s[60] = {0};
  snprintf(s, sizeof(s), "jump %d %d %d %d %d %s %s", x, y, z, speed, yaw, mid1, mid2);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::SetSpeed(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "speed %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::SetRC(int16_t a, int16_t b, int16_t c, int16_t d, std::function<void(char *cmd, String res)> callback)
{
  char s[40] = {0};
  snprintf(s, sizeof(s), "rc %d %d %d %d", a, b, c, d);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::SetMon(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"mon", callback);
}

void RMTT_Protocol::SetMoff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"moff", callback);
}

void RMTT_Protocol::SetMdirection(uint8_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20] = {0};
  snprintf(s, sizeof(s), "mdirection %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::ReadSpeed(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"speed?", callback);
}

void RMTT_Protocol::ReadBattery(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"battery?", callback);
}

void RMTT_Protocol::ReadTime(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"time?", callback);
}

void RMTT_Protocol::ReadSN(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"sn?", callback);
}

void RMTT_Protocol::ReadSDKVersion(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"sdk?", callback);
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
void RMTT_Protocol::sendCmd(char *cmd, std::function<void(char *cmd, String res)> callback)
{
  while (Serial1.available())
    Serial1.read();

  Serial1.printf("[TELLO] Re%02x%02x %s", cmdId, 1, cmd);
  cmdId++;

  delay(10);

  String res = "";
  while (Serial1.available())
    res += String(char(Serial1.read()));

  callback(cmd, res);
}

