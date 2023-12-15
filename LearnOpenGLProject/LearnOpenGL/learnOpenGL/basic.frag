#version 330 core
out vec4 FragColor;
//uniform vec4 ourColor;//������һ��uniformȴ��GLSL������û�ù����������ᾲĬ�Ƴ����������������������İ汾�в����������
in vec4 vertexColor; // �Ӷ�����ɫ�����������������������ͬ��������ͬ��

in vec2 TexCoord;
uniform sampler2D mainTexture;
uniform sampler2D secondTexture;
void main()
{
    FragColor = mix(texture( mainTexture, TexCoord), texture(secondTexture, TexCoord), 0.2);
}