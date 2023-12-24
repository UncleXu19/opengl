#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    //用于贴图3D立方体的立方体贴图可以使用立方体的位置作为纹理坐标来采样。
    //当立方体处于原点(0, 0, 0)时，它的每一个位置向量都是从原点出发的方向向量。这个方向向量正是获取立方体上特定位置的纹理值所需要的。
    //正是因为这个，我们只需要提供位置向量而不用纹理坐标了。
    TexCoords = aPos;//本地坐标
    vec4 pos = projection * view * vec4(aPos, 1.0);
    gl_Position = pos.xyww;//利用透视除法永远让天空盒的z深度为1,从而提前利用提前深度测试
}  