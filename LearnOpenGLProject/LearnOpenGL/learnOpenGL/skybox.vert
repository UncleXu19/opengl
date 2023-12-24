#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    //������ͼ3D���������������ͼ����ʹ���������λ����Ϊ����������������
    //�������崦��ԭ��(0, 0, 0)ʱ������ÿһ��λ���������Ǵ�ԭ������ķ�����������������������ǻ�ȡ���������ض�λ�õ�����ֵ����Ҫ�ġ�
    //������Ϊ���������ֻ��Ҫ�ṩλ���������������������ˡ�
    TexCoords = aPos;//��������
    vec4 pos = projection * view * vec4(aPos, 1.0);
    gl_Position = pos.xyww;//����͸�ӳ�����Զ����պе�z���Ϊ1,�Ӷ���ǰ������ǰ��Ȳ���
}  