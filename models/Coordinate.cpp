#include "Coordinate.h"

Coordinate::Coordinate(char *unit, int16_t x, int16_t y, int16_t z)
{
    this->unit = new char[strlen(unit) + 1];
    strcpy(this->unit, unit);
    this->x = x;
    this->y = y;
    this->z = z;
}

char *Coordinate::getUnit()
{
    return unit;
}

int16_t Coordinate::getX()
{
    return x * getUnitScalar();
}

int16_t Coordinate::getY()
{
    return y * getUnitScalar();
}

int16_t Coordinate::getZ()
{
    return z * getUnitScalar();
}

float Coordinate::getUnitScalar()
{
    if (strcmp(unit, "mm") == 0)
    {
        return 1 / 10;
    }
    else if (strcmp(unit, "cm") == 0)
    {
        return 1;
    }
    else if (strcmp(unit, "m") == 0)
    {
        return 1 * 100;
    }
    else if (strcmp(unit, "km") == 0)
    {
        return 1 * 100 * 1000;
    }
    else
    {
        return 1;
    }
}

void Coordinate::toString(char *buffer)
{
    sprintf(buffer, "(x = %d, y = %d, z = %d, unit = %s)", x, y, z, unit);
}

void Coordinate::printPoints(std::vector<Coordinate> points)
{
    uint8_t size = points.size();
    for (uint8_t i = 0; i < size; i++)
    {
        char buffer[60];
        Coordinate point = points.at(i);
        point.toString(buffer);
        Serial.println(buffer);
    }
}

uint8_t Coordinate::getPointScalar(int16_t xDistance, int16_t yDistance, int16_t zDistance)
{
    int16_t max = 0, min = 0;

    if (xDistance > max)
        max = xDistance;
    else if (xDistance < min)
        min = xDistance;
    if (yDistance > max)
        max = yDistance;
    else if (yDistance < min)
        min = yDistance;
    if (zDistance > max)
        max = zDistance;
    else if (zDistance < min)
        min = zDistance;

    if (max != 0)
        return (uint8_t)ceil(max / MAX_DISTANCE);
    else if (min != 0)
        return (uint8_t)ceil(min / MIN_DISTANCE);
    else
        return 1;
}