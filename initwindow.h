#pragma once

GLFWwindow* initWindow(int widge, int height,const char *title)
{
    glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//主版本号
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//子版本号
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//设置模式
    GLFWwindow* window = glfwCreateWindow(widge, height, title, NULL, NULL);//创建窗口
    
    return window;
}