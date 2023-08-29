/*
Esta clase toma las coordenadas x,y,z que recibe en un json y las devuelve en cm, ya que es la unidad que se utiliza en las coordenadas del drone.
*/
#pragma once
#include <stdio.h>
#include <queue>
#include <Arduino.h>
#include <math.h>

#define MAX_DISTANCE 500
#define MIN_DISTANCE -500

class Coordinate
{
private:
    char *unit;
    int16_t x;
    int16_t y;
    int16_t z;

public:
    Coordinate(char *, int16_t, int16_t, int16_t);
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    float getUnitScalar();
    void toString(char *buffer);
    static uint8_t getPointScalar(int16_t xDistance, int16_t yDistance, int16_t zDistance);
    static void printPoints(std::vector<Coordinate> points);
};