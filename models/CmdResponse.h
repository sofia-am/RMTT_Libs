#pragma once
#include <stdio.h>
#include <Arduino.h>

class CmdResponse {
private:
    int16_t x;
    int16_t y;
    int16_t z;
    uint16_t speed;
    TickType_t time;

public:
    CmdResponse(int16_t x, int16_t y, int16_t z, uint16_t speed, TickType_t time);
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    uint16_t getSpeed();
    TickType_t getTime();
};