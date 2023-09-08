#pragma once
#include <stdio.h>
#include <Arduino.h>
#include "Coordinate.h"

class MoveRelativeRes {
private:
    uint16_t speed;
    int16_t x;
    int16_t y;
    int16_t z;
    TickType_t time;

public:
    MoveRelativeRes(uint16_t speed, int16_t x, int16_t y, int16_t z, TickType_t time);
    uint16_t getSpeed();
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    TickType_t getTime();
    // Coordinate getCoordinate();
};