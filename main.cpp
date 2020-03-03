
#include"stdafx.h"
#include"initwindow.h"
#include"draw.h"
#include"GraphicAlgorithm.h"
#include"Matrix.h"

int main(int argc, char* argv)
{
    GLFWwindow* window = initWindow(1000, 1000, "opengl");
    if (window == nullptr)
        glfwTerminate();
    glfwMakeContextCurrent(window);
    Matrix<int> k, m;
    Reflection(k, 1, -1, 1);
   // k = Reflection(1, -1, 1);
    OpenGLTest* pOpenGLTest = new OpenGLTest();
    GraphicAlgorithm* pAlgorithm = new GraphicAlgorithm();
    while (!glfwWindowShouldClose(window))//是否关闭窗口
    {
        pOpenGLTest->glDrawPoint();
        pOpenGLTest->DrawAngle(10);
        /*pAlgorithm->Bresenham(-900, -900, 900, 900);
        pAlgorithm->MiddleCircle(NULL, NULL, 600);*/
        //pOpenGLTest->glDrawPoint();
        glfwSwapBuffers(window);//交换缓冲区
        glfwPollEvents();       //等待事件
    }
}


