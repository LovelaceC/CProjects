#ifndef __SHADER_H
#define __SHADER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif
