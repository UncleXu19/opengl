#version 330 core
out vec4 FragColor;
//uniform vec4 ourColor;//声明了一个uniform却在GLSL代码中没用过，编译器会静默移除这个变量，导致最后编译出的版本中并不会包含它
in vec4 vertexColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）

in vec2 TexCoord;
uniform sampler2D mainTexture;
uniform sampler2D secondTexture;
void main()
{
    FragColor = mix(texture( mainTexture, TexCoord), texture(secondTexture, TexCoord), 0.2);
}