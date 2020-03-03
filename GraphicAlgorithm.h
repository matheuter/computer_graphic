#pragma once
#include<cmath>
#include"stdafx.h"
class GraphicAlgorithm
{
public:
    GraphicAlgorithm(){}
    ~GraphicAlgorithm(){}

    void Bresenham(int begin_x, int begin_y, int end_x, int end_y);
    void Circle(int pos_x, int pos_y); 
    void MiddleCircle(int pos_x, int pos_y, int redis);
    void setPixel(int x, int y);
};

