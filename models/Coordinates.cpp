#include "Coordinate.h"

Coordinate::Coordinate(char *unit, float x, float y, float z)
{
    this->unit = new char[strlen(unit) + 1];
    strcpy(this->unit, unit);
    this->x = x;
    this->y = y;
    this->z = z;
}

float Coordinate::getX()
{
    return x * getUnitScalar();
}

float Coordinate::getY()
{
    return y * getUnitScalar();
}

float Coordinate::getZ()
{
    return z * getUnitScalar();
}

float Coordinate::getUnitScalar()
{
    if (strcmp(unit, "mm") == 0)
    {
        return 1 / 10.0;
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
    sprintf(buffer, "(x = %.2f, y = %.2f, z = %.2f, unit = %s)", x, y, z, unit);
}

void Coordinate::printPoints(std::queue<Coordinate> points)
{
    uint8_t size = points.size();
    for (uint8_t i = 0; i < size; i++)
    {
        char buffer[60];
        Coordinate point = points.front();
        point.toString(buffer);
        Serial.println(buffer);
        points.pop();
    }
}

uint8_t Coordinate::getPointScalar(float xDistance, float yDistance, float zDistance)
{
    float max = 0, min = 0;

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
        return (uint8_t)ceil(max / (float)MAX_DISTANCE);
    else if (min != 0)
        return (uint8_t)ceil(min / (float)MIN_DISTANCE);
    else
        return 1;
}