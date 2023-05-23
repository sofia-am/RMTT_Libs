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
    return x * getScalar();
}

float Coordinate::getY()
{
    return y * getScalar();
}

float Coordinate::getZ()
{
    return z * getScalar();
}

float Coordinate::getScalar()
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

    for (int i = 0; i < points.size(); i++)
    {
        char buffer[60];
        Coordinate point = points.front();
        points.pop();
        point.toString(buffer);
        Serial.println(buffer);
    }
}