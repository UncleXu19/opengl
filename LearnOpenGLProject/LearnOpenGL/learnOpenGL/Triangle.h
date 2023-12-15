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
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ����
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ����
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ����
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
		shader->use(); // ��Ҫ����������uniform����֮ǰ������ɫ������
		shader->setInt("mainTexture", 0); // ����ʹ����ɫ��������
		shader->setInt("secondTexture", 1); // ����ʹ����ɫ��������
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		// ����֮��Ҳ��ͨ�������ģ�ֻ��Ψһ�ļ���VAO����VAO�󴴽���VBO�����ڸ�VAO��
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		
		//��֪VAO����ν���VBO����Ϣ
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
	//	//glShaderSource������Ҫ�������ɫ��������Ϊ��һ��������
	//	// �ڶ�����ָ���˴��ݵ�Դ���ַ�������������ֻ��һ����
	//	// �����������Ƕ�����ɫ��������Դ�룬
	//	// ���ĸ���������������ΪNULL��
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

