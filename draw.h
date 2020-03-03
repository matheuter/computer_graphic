#pragma once
#include"stdafx.h"
#include"Matrix.h"
#include<vector>
const double pi = 3.1425926;

class OpenGLTest
{
private:
    Matrix<GLfloat> m_matrix;
public:
    OpenGLTest();
    ~OpenGLTest(){}

    void glDrawLine();
    void glDrawPoint();
    void DrawAngle(int angle);
    void Rander();
};

