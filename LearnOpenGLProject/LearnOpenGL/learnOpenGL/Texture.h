#pragma once
#include<iostream>

#include<glad/glad.h>
#include "stb_image.h"


class Texture
{
public:

	int width;
	int height;
	int nrChannels;
	unsigned int ID = 0;

	Texture(const char* imgPath, GLint internalformat = GL_RGB) {
		stbi_set_flip_vertically_on_load(true);
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);
		// 设置环绕、过滤方式
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		unsigned char* data = stbi_load(imgPath, &width, &height, &nrChannels, 0);
		if (data) {
			//只生成了0级别的mipmap
			glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, 0, internalformat, GL_UNSIGNED_BYTE, data);
			//调用generateMipMap为当前绑定的纹理自动生成所有需要的多级渐远纹理。
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

	}

};

