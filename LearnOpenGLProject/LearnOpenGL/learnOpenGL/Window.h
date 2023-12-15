#pragma once
#include <iostream>
#include <glad/glad.h> //openGL����ָ��󶨿�
//GLAD��ͷ�ļ���������ȷ��OpenGLͷ�ļ�������GL/gl.h����������Ҫ������������OpenGL��ͷ�ļ�֮ǰ����GLAD��
#include <GLFW/glfw3.h> //�������ڣ�����OpenGL�������Լ������û�����


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
		
		glfwMakeContextCurrent(this->window);//֪ͨGLFW�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳�����������
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
		glfwInit();//��ʼ��GLFW
		//����GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//���汾��
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//openGLģʽ��core
		_haveInitGLFW = true;
		return;
	}

	static void _FrameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

};


