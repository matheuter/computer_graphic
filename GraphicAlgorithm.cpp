#include "GraphicAlgorithm.h"

void GraphicAlgorithm::Bresenham(int begin_x, int begin_y, int end_x, int end_y)
{
    glBegin(GL_POINTS);
    int dx = fabsf(begin_x - end_x);
    int dy = fabsf(begin_y - end_y);
    int n = dy * 2;
    int m = 2 * (dy - dx);
    int p = 2 * dy - dx;
    int x = begin_x;
    int y = begin_y;
    if (begin_x > end_x)
    {
        x = end_x;
        y = end_y;
        end_x = begin_x;
    }
    setPixel(x, y);
    while (x++ < end_x)
    {
        if (p < 0)
            p += n;
        else
        {
            y++;
            p += m;
        }
        setPixel(x, y);
    }
    glEnd();
}

void GraphicAlgorithm::Circle(int pos_x, int pos_y)
{
    setPixel(- pos_y,- pos_x); setPixel(- pos_x, - pos_y);
    setPixel( pos_y,- pos_x);  setPixel( pos_x,- pos_y);
    setPixel(pos_y, pos_x);    setPixel(pos_x,pos_y);
    setPixel(- pos_y, pos_x);  setPixel( -pos_x, pos_y);

}

void GraphicAlgorithm::MiddleCircle(int pos_x, int pos_y, int redis)
{
    glBegin(GL_POINTS);
    glPointSize(0.5f);
    int x = 0;
    int y = redis;
    int d = 1 - redis;
    while (x < y)
    {
        Circle(x, y);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}

void GraphicAlgorithm::setPixel(int x, int y)
{
    glVertex2f((GLfloat)x / 1000, (GLfloat)y / 1000);
}
