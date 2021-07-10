#version 330 core

out vec4 FragColor;

in vec3 our_color;
in vec2 TexCoord;

uniform sampler2D our_texture;

void
main ()
{
	FragColor = texture (our_texture, TexCoord);
}
