#pragma once
#include<iostream>
#include "Texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include "shader.h"

class Triangle
{

public :
	float vertices[32] = {
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
	};
	unsigned int indices[6] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1,2,3,
	};


	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int vertexShader;
	unsigned int fragmentShader;
	//unsigned int shaderProgram;
	Shader* shader;
	//const char* vertexShaderSource = "#version 330 core\n"
	//	"layout (location = 0) in vec3 aPos;\n"
	//	"void main()\n"
	//	"{\n"
	//	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	//	"}\0";
	//const char* fragmentShaderSource = "#version 330 core\n"
	//	"out vec4 FragColor;\n"
	//	"void main()\n"
	//	"{\n"
	//	"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	//	"}\n\0";

	Texture* tex1;
	Texture* tex2;
	Triangle() {
		_InitRender();
	}

	~Triangle() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		//glDeleteProgram(shaderProgram);
		delete(shader);
	}
	

	void Draw() {

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glUseProgram(shaderProgram);
		shader->use();
		
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		// 
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex1->ID);
		glActiveTexture(GL_TEXTURE1); 
		glBindTexture(GL_TEXTURE_2D, tex2->ID);

		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
	}

private:
	void _InitRender() {

		//this->_CompileVerticesShader();
		//this->_CompileFragmentShader();
		//this->_LinkShaderProgram();
		shader = new Shader("basic.vert", "basic.frag");
		shader->use(); // 不要忘记在设置uniform变量之前激活着色器程序！
		shader->setInt("mainTexture", 0); // 或者使用着色器类设置
		shader->setInt("secondTexture", 1); // 或者使用着色器类设置
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		// 它们之间也是通过上下文，只有唯一的激活VAO，在VAO后创建的VBO都属于该VAO。
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		
		//告知VAO该如何解释VBO的信息
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		tex1 = new Texture("Resource/Texture/wall.jpg");
		tex2 = new Texture("Resource/Texture/smile.png", GL_RGBA);
	}

	//void _CompileVerticesShader() {

	//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//	//glShaderSource函数把要编译的着色器对象作为第一个参数。
	//	// 第二参数指定了传递的源码字符串数量，这里只有一个。
	//	// 第三个参数是顶点着色器真正的源码，
	//	// 第四个参数我们先设置为NULL。
	//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//	glCompileShader(vertexShader);

	//	int  success;
	//	char infoLog[512];
	//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//	if (!success)
	//	{
	//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//	}
	//}

	//void _CompileFragmentShader() {

	//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//	glCompileShader(fragmentShader);

	//	int  success;
	//	char infoLog[512];
	//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	//	if (!success)
	//	{
	//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//	}
	//}
	//	


	//void _LinkShaderProgram() {
	//	
	//	shaderProgram = glCreateProgram();
	//	glAttachShader(shaderProgram, vertexShader);
	//	glAttachShader(shaderProgram, fragmentShader);
	//	glLinkProgram(shaderProgram);

	//	int  success;
	//	char infoLog[512];
	//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//	if (!success) {
	//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	//		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	//	}

	//	glDeleteShader(vertexShader);
	//	glDeleteShader(fragmentShader);
	//}
};

