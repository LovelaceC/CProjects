#version 330 core

layout (location = 0) in vec3 Position;

uniform float g_scale;

void main()
{
	gl_Position = vec4(g_scale * Position.x, g_scale * Position.y, Position.z, 1.0);
}