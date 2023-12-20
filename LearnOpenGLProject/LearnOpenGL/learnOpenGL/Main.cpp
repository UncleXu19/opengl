
#include "Window.h"
#include "Triangle.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Box.h"
void processInput(Window* window);

int main() {

	Window* window = new Window();
    Triangle* triangle = new Triangle();
    Box* box = new Box();
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window->window))
    {
        //输入
        processInput(window);

        //渲染指令
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清glClear所用的颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//参数可以是GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT
        //triangle->Draw();
        box->Draw();


        //检查并调用事件交换缓冲
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
