#ifndef __SHADER_H
#define __SHADER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cglm/cglm.h>

struct shader
{
  unsigned int id;
};

struct shader *shader_create (const char *vertex_path,
                              const char *fragment_path);
void shader_use (struct shader shader);

void shader_set_bool (struct shader shader, const char *name, _Bool val);
void shader_set_int (struct shader shader, const char *name, int val);
void shader_set_float (struct shader shader, const char *name, float val);
void shader_set_vec2 (struct shader shader, const char *name, vec2 val);
void shader_set_vec3 (struct shader shader, const char *name, vec3 val);
void shader_set_vec4 (struct shader shader, const char *name, vec4 val);
void shader_set_mat2 (struct shader shader, const char *name, mat2 val);
void shader_set_mat3 (struct shader shader, const char *name, mat3 val);
void shader_set_mat4 (struct shader shader, const char *name, mat4 val);

#endif
