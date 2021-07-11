#version 330 core
out vec4 FragColor;

struct material
{
	sampler2D diffuse;
	vec3 specular;
	float shininess;
};

struct light
{
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 view_pos;
uniform material mat;
uniform light l;

void
main ()
{
	// ambient
	vec3 ambient = l.ambient * texture (mat.diffuse, TexCoords).rgb;

	// diffuse
	vec3 norm = normalize(Normal);
	vec3 light_dir = normalize(l.position - FragPos);
	float diff = max(dot(norm, light_dir), 0.0);
	vec3 diffuse = l.diffuse * diff * texture (mat.diffuse, TexCoords).rgb;

	// specular
	vec3 view_dir = normalize(view_pos - FragPos);
	vec3 reflect_dir = reflect(-light_dir, norm);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), mat.shininess);
	vec3 specular = l.specular * (spec * mat.specular);

	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
} 