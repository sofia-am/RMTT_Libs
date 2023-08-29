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
#include "models/Coordinate.h"

static uint16_t sdk_time = 0;
RMTT_Protocol *RMTT_Protocol::instance = NULL;
SemaphoreHandle_t RMTT_Protocol::xCmdMutex;

RMTT_Protocol *RMTT_Protocol::getInstance()
{
  if (instance == NULL)
  {
    instance = new RMTT_Protocol;
    xCmdMutex = xSemaphoreCreateMutex();
    if (xSemaphoreGive(xCmdMutex) == pdTRUE)
    {
      Serial.println("Semaphore released");
    }
    else
    {
      Serial.println("Semaphore not released");
    };
    return instance;
  }
  else
  {
    return instance;
  }
}

void RMTT_Protocol::sdkOn(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"command", callback);
}

void RMTT_Protocol::takeOff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"takeoff", callback);
}

void RMTT_Protocol::land(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"land", callback);
}

void RMTT_Protocol::streamOn(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"streamon", callback);
}

void RMTT_Protocol::streamOff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"streamoff", callback);
}

void RMTT_Protocol::emergency(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"emergency", callback);
}

void RMTT_Protocol::up(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "up %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::down(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "down %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::left(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "left %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::right(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "right %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::forward(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "forward %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::back(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "res %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::clockWise(uint16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "cw %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::counterClockWise(uint16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "ccw %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::motorOn(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"motoron", callback);
}

void RMTT_Protocol::motorOff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"motoroff", callback);
}

void RMTT_Protocol::throwFly(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"throwfly", callback);
}

void RMTT_Protocol::flip(char x, std::function<void(char *cmd, String res)> callback)
{
  char s[15];
  snprintf(s, sizeof(s), "flip %c", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::go(int16_t x, int16_t y, int16_t z, uint16_t speed, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "go %d %d %d %d", x, y, z, speed);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::go(int16_t x, int16_t y, int16_t z, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "go %d %d %d %d %s", x, y, z, speed, mid);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::moveRealtiveTo(Coordinate p1, Coordinate p2, uint16_t speed, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  int16_t pointX = p2.getX() - p1.getX();
  int16_t pointY = p2.getY() - p1.getY();
  int16_t pointZ = p2.getZ() - p1.getZ();
  snprintf(s, sizeof(s), "go %d %d %d %d", pointX, pointY, pointZ, speed);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::stop(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"stop", callback);
}

void RMTT_Protocol::curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d", x1, y1, z1, x2, y2, z2, speed);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::curve(int16_t x1, int16_t y1, int16_t z1, int16_t x2, int16_t y2, int16_t z2, uint16_t speed, char *mid, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "curve %d %d %d %d %d %d %d %s", x1, y1, z1, x2, y2, z2, speed, mid);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::jump(int16_t x, int16_t y, int16_t z, uint16_t speed, int16_t yaw, char *mid1, char *mid2, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "jump %d %d %d %d %d %s %s", x, y, z, speed, yaw, mid1, mid2);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setSpeed(int16_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[30];
  snprintf(s, sizeof(s), "speed %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setRC(int16_t a, int16_t b, int16_t c, int16_t d, std::function<void(char *cmd, String res)> callback)
{
  char s[50];
  snprintf(s, sizeof(s), "rc %d %d %d %d", a, b, c, d);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setDroneWifi(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "wifi %s %s", ssid, pass);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setMon(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"mon", callback);
}

void RMTT_Protocol::setMoff(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"moff", callback);
}

void RMTT_Protocol::setOneDirection(uint8_t x, std::function<void(char *cmd, String res)> callback)
{
  char s[30];
  snprintf(s, sizeof(s), "mdirection %d", x);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setAP(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "ap %s %s", ssid, pass);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setWiFiChannel(uint16_t channel, std::function<void(char *cmd, String res)> callback)
{
  char s[30];
  snprintf(s, sizeof(s), "wifisetchannel %d", channel);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setPortStatusStreaming(uint16_t portStatus, uint16_t portStreaming, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "port %d %d", portStatus, portStreaming);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setFPS(char *fps, std::function<void(char *cmd, String res)> callback)
{
  char s[20];
  snprintf(s, sizeof(s), "fps %s", fps);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setBitrate(uint8_t bitrate, std::function<void(char *cmd, String res)> callback)
{
  char s[30];
  snprintf(s, sizeof(s), "setbitrate %d", bitrate);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::setResolution(char *resolution, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "setresolution %s", resolution);
  sendCmd(s, callback);
}

void RMTT_Protocol::setMultiFiwiSSIDPass(char *ssid, char *pass, std::function<void(char *cmd, String res)> callback)
{
  char s[100];
  snprintf(s, sizeof(s), "multiwifi %s %s", ssid, pass);
  sendCmd((char *)s, callback);
}

void RMTT_Protocol::getSpeed(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"speed?", callback);
}

void RMTT_Protocol::getBattery(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"battery?", callback);
}

void RMTT_Protocol::getWiFi(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"wifi?", callback);
}

void RMTT_Protocol::getMotorTime(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"time?", callback);
}

void RMTT_Protocol::getSN(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"sn?", callback);
}

void RMTT_Protocol::getSDKVersion(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"sdk?", callback);
}

void RMTT_Protocol::getHardwareInfo(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"hardware?", callback);
}

void RMTT_Protocol::getWiFiVersion(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"wifiversion?", callback);
}

void RMTT_Protocol::getApInfo(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"ap?", callback);
}

void RMTT_Protocol::getSSID(std::function<void(char *cmd, String res)> callback)
{
  sendCmd((char *)"ssid?", callback);
}

void RMTT_Protocol::startUntilControl()
{
  pinMode(34, INPUT_PULLUP);
  // RMTT_RGB::Init();
  while (!(getTelloMsgString((char *)"[TELLO] command", 1000) == String("ETT ok")))
  {
    delay(500);
  }
  while (!((digitalRead(34)) == 0))
  {
    delay(500);
  }
  RMTT_RGB::SetRGB(0, 255, 0);
  // RMTT_RGB::SetRGB(0, 0, 0);
  // delay(1000);
  // RMTT_RGB::SetRGB(0, 255, 0);
  // delay(1000);
  // RMTT_RGB::SetRGB(0, 0, 0);
}

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
  TickType_t xBlockTimeMax((TickType_t)500 / portTICK_PERIOD_MS);

  const unsigned long TIMEOUT_DURATION = 20000;
  unsigned long start = millis();

  if (xSemaphoreTake(xCmdMutex, xBlockTimeMax) == pdFAIL)
  {
    callback(cmd, "Not able to take mutex");
    return;
  }

  while (Serial1.available())
  {
    Serial1.read();
  }

  if (strcmp(cmd, "command") == 0)
  {
    Serial1.printf("[TELLO] command", cmdId, 1, cmd);
    cmdId++;
  }
  else
  {
    Serial1.printf("[TELLO] Re%02x%02x %s", cmdId, 1, cmd);
    cmdId++;
  }
  String res = "";

  while (!Serial1.available())
  {
    if (millis() - start < TIMEOUT_DURATION)
      continue;
    else
    {
      Serial.println("TIMEOUT"); // do something
    }
  }

  while (Serial1.available())
    res += String(char(Serial1.read()));

  callback(cmd, res);

  if (xSemaphoreGive(xCmdMutex) == pdFAIL)
  {
    callback(cmd, "Not able to give mutex");
    return;
  }
}