#version 330 core
layout (location = 0) in vec3 aPos; // λ�ñ���������λ��ֵΪ0
layout (location = 1) in vec3 aColor; // ��ɫ����������λ��ֵΪ 1
layout (location = 2) in vec2 aTexCoord;
out vec4 vertexColor; // ΪƬ����ɫ��ָ��һ����ɫ���
out vec2 TexCoord;
void main()
{
    gl_Position = vec4(aPos, 1.0); // ע��������ΰ�һ��vec3��Ϊvec4�Ĺ������Ĳ���
    vertexColor = vec4(aColor, 1.0);
    TexCoord = aTexCoord;
}