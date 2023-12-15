#pragma once
#include <iostream>
#include <glad/glad.h> //openGL函数指针绑定库
//GLAD的头文件包含了正确的OpenGL头文件（例如GL/gl.h），所以需要在其它依赖于OpenGL的头文件之前包含GLAD。
#include <GLFW/glfw3.h> //创建窗口，定义OpenGL上下文以及处理用户输入


class Window
{
	
public:
	GLFWwindow* window;
	void CreateWindow() {
		this->window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
		if (this->window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		
		glfwMakeContextCurrent(this->window);//通知GLFW将我们窗口的上下文设置为当前线程的主上下文了
		gladLoadGL();
		glfwSetFramebufferSizeCallback(this->window, _FrameBufferSizeCallBack);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}
	}



	Window() {
		_InitGLFW();
		this->CreateWindow();
	}
	~Window() {
		glfwTerminate();
	}



private:
	static bool _haveInitGLFW;
	static void _InitGLFW() {
		if (_haveInitGLFW) {
			return;
		}
		glfwInit();//初始化GLFW
		//配置GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//主版本号
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//副版本号
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//openGL模式：core
		_haveInitGLFW = true;
		return;
	}

	static void _FrameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

};


