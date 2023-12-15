
#include "Window.h"
#include "Triangle.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
void processInput(Window* window);

int main() {

	Window* window = new Window();
    Triangle* triangle = new Triangle();

    while (!glfwWindowShouldClose(window->window))
    {
        //����
        processInput(window);

        //��Ⱦָ��
        glClearColor(0.f, 0.f, 0.f, 1.0f);//������glClear���õ���ɫ
        glClear(GL_COLOR_BUFFER_BIT);//����������GL_COLOR_BUFFER_BIT��GL_DEPTH_BUFFER_BIT��GL_STENCIL_BUFFER_BIT
        triangle->Draw();

        //��鲢�����¼���������
        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    delete window;
    return 0;
}

void processInput(Window* window) {
	if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window->window, true);
}