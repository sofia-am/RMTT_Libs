#include "CmdResponse.h"

CmdResponse::CmdResponse(int16_t x, int16_t y, int16_t z, uint16_t speed, TickType_t time)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->speed = speed;
    this->time = time;
}

int16_t CmdResponse::getX()
{
    return x;
}

int16_t CmdResponse::getY()
{
    return y;
}

int16_t CmdResponse::getZ()
{
    return z;
}

uint16_t CmdResponse::getSpeed()
{
    return speed;
}

TickType_t CmdResponse::getTime()
{
    return time;
}



