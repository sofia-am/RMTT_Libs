/*
Esta clase toma las coordenadas x,y,z que recibe en un json y las devuelve en cm, ya que es la unidad que se utiliza en las coordenadas del drone.
*/
#pragma once
#include <stdio.h>
#include <queue>
#include <Arduino.h>

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
    float getScalar();
    void toString(char *buffer);
    static void printPoints(std::queue<Coordinate> points);
};