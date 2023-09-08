#include "MoveRelativeRes.h"

MoveRelativeRes::MoveRelativeRes(uint16_t speed, int16_t x, int16_t y, int16_t z, TickType_t time)
{
    this->speed = speed;
    this->x = x;
    this->y = y;
    this->z = z;
    this->time = time;
}

uint16_t MoveRelativeRes::getSpeed()
{
    return speed;
}

TickType_t MoveRelativeRes::getTime()
{
    return time;
}

int16_t MoveRelativeRes::getX()
{
    return x;
}

int16_t MoveRelativeRes::getY()
{
    return y;
}

int16_t MoveRelativeRes::getZ()
{
    return z;
}