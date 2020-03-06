#include "draw.h"


OpenGLTest::OpenGLTest()
{
    m_matrix = Matrix<GLfloat>(4,1,1);
    m_matrix(1, 1) = 0.2;
    m_matrix(2, 1) = 0.3;
    m_matrix(3, 1) = 1.0;
}

void OpenGLTest::glDrawLine()
{
    int vec[] = { 100,100 };
    glBegin(GL_POINTS);
    glVertex2iv(vec);
    glEnd();
}

void OpenGLTest::glDrawPoint()
{
    glBegin(GL_LINES);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
}
int n = 0;
void OpenGLTest::DrawAngle(int angle)
{
    std::vector<GLfloat> a = {
        cosf(angle * pi / 180), -sinf(angle * pi / 180), 0.0, 0,
        sinf(angle * pi / 180), cosf(angle * pi / 180), 0,0,
        0,0,1.0f,0,
        0,0,0,1

    };

    Matrix<GLfloat> mat(4, 4, a);
    Matrix<GLfloat> m = mat * m_matrix;
    m = mat * m;
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(m_matrix(1, 1), m_matrix(2, 1), m_matrix(3, 1));
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(m(1, 1), m(2, 1), m(3, 1));
    glEnd();
    
    if (n++ == 1) {
        std::cout << m;
        std::cout << m_matrix;
    }
}

