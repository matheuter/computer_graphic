#pragma once

GLFWwindow* initWindow(int widge, int height,const char *title)
{
    glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//�Ӱ汾��
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//����ģʽ
    GLFWwindow* window = glfwCreateWindow(widge, height, title, NULL, NULL);//��������
    
    return window;
}