/*
Esta clase toma las coordenadas x,y,z que recibe en un json y las devuelve en cm, ya que es la unidad que se utiliza en las coordenadas del drone.
*/
#pragma once
#include <stdio.h>
#include <queue>
#include <Arduino.h>
#include <math.h>

#define MAX_DISTANCE (float)500
#define MIN_DISTANCE (float)-500

class Coordinate
{
private:
    char *unit;
    float x;
    float y;
    float z;

public:
    Coordinate(char *, float, float, float);
    float getX();
    float getY();
    float getZ();
    float getUnitScalar();
    void toString(char *buffer);
    static uint8_t getPointScalar(float xDistance, float yDistance, float zDistance);
    static void printPoints(std::queue<Coordinate> points);
};