#version 330 core

layout (location = 0) in vec3 a_pos;
layout (location = 2) in vec2 a_tex_coord;

out vec2 TexCoord;

uniform mat4 transform;

void
main ()
{
	gl_Position = transform * vec4 (a_pos, 1.0f);
	TexCoord = a_tex_coord;
}
