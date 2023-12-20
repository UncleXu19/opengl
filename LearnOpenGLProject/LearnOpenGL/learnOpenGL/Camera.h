#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h> 


class Camera
{
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::normalize(position - cameraTarget);
	glm::vec3 cameraRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), direction));
	glm::vec3 cameraUp = glm::cross(direction, cameraRight);


public:
	glm::mat4 view = glm::mat4(1.0f);
	Camera() {

	}
	void update() {

		float radius = 10.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		//lookAt:一个摄像机位置，一个目标位置和一个表示世界空间中的上向量的向量
		view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	}
};

