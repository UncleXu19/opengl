//
//#include "Window.h"
//#include "Triangle.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include "Box.h"
//#include "SingleBox.h"
//void processInput(Window* window);
//
//
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//int main() {
//
//	Window* window = new Window();
//    Triangle* triangle = new Triangle();
//    //Box* box = new Box();
//    SingleBox* box = new SingleBox();
//
//    glfwSetCursorPosCallback(window->window, mouse_callback);
//    glfwSetScrollCallback(window->window, scroll_callback);
//
//    glEnable(GL_DEPTH_TEST);
//    while (!glfwWindowShouldClose(window->window))
//    {
//        // per-frame time logic
//// --------------------
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        //输入
//        processInput(window);
//
//        //渲染指令
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清glClear所用的颜色
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//参数可以是GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT
//        
//        // pass projection matrix to shader (note that in this case it could change every frame)
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        box->shader->setMat4("projection", projection);
//
//        // camera/view transformation
//        glm::mat4 view = camera.GetViewMatrix();
//        box->shader->setMat4("view", view);
//        
//        //triangle->Draw();
//        box->Draw();
//
//
//        //检查并调用事件交换缓冲
//        glfwSwapBuffers(window->window);
//        glfwPollEvents();
//    }
//
//    delete window;
//    return 0;
//}
//
//void processInput(Window* myWindow) {
//    GLFWwindow* window = myWindow->window;
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
//
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//    lastX = xpos;
//    lastY = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}