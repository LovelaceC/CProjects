#include "shader.h"

struct shader *
shader_create (const char *vertex_path, const char *fragment_path)
{
  // First, we define the variables
  struct shader *shader;

  char *vertex_code = NULL;
  char *fragment_code = NULL;

  FILE *fragment_file = NULL;
  FILE *vertex_file = NULL;

  shader = malloc (sizeof (struct shader));

  if (!shader)
    {
      fprintf (stderr, "Error allocating memory for `shader'.\n");
      goto out;
    }

  vertex_file = fopen (vertex_path, "r");
  if (!vertex_file)
    {
      fprintf (stderr, "Error opening `%s'\n", vertex_path);
      goto out;
    }

  fseek (vertex_file, 0, SEEK_END);
  int vertex_len = ftell (vertex_file);
  fseek (vertex_file, 0, SEEK_SET);

  vertex_code = malloc (sizeof (char) * vertex_len + 1);

  if (!vertex_code)
    {
      fprintf (stderr, "Error allocating memory for `vertex_code'.\n");
      goto out;
    }

  memset (vertex_code, 0, sizeof (char) * vertex_len + 1);
  if (!vertex_code)
    {
      fprintf (stderr, "Error allocating memory for `vertex_code'.\n");
      goto out;
    }

  fread (vertex_code, vertex_len, 1, vertex_file);

  // Vertex shader successfully read
  fclose (vertex_file);

  fragment_file = fopen (fragment_path, "r");
  if (!fragment_file)
    {
      fprintf (stderr, "Error opening `%s'\n", fragment_path);
      goto out;
    }

  fseek (fragment_file, 0, SEEK_END);
  int fragment_len = ftell (fragment_file);
  fseek (fragment_file, 0, SEEK_SET);

  fragment_code = malloc (sizeof (char) * fragment_len + 1);

  if (!fragment_code)
    {
      fprintf (stderr, "Error allocating memory for `fragment_code'.\n");
      goto out;
    }

  memset (fragment_code, 0, sizeof (char) * fragment_len + 1);
  if (!fragment_code)
    {
      fprintf (stderr, "Error allocating memory for `fragment_code'.\n");
      goto out;
    }

  fread (fragment_code, fragment_len, 1, fragment_file);

  // Fragment shader read successfully
  fclose (fragment_file);

  // Create some other variables that are needed wtf
  const char *v_shader_source = vertex_code;
  const char *f_shader_source = fragment_code;

  // Compile shaders
  unsigned int vertex, fragment;
  int res;
  char log[512];

  // Vertex shader
  vertex = glCreateShader (GL_VERTEX_SHADER);
  glShaderSource (vertex, 1, &v_shader_source, NULL);
  glCompileShader (vertex);

  // Print errors, if any
  glGetShaderiv (vertex, GL_COMPILE_STATUS, &res);
  if (res == 0)
    {
      glGetShaderInfoLog (vertex, 512, NULL, log);
      fprintf (stderr,
               "Vertex shader `%s' compilation failed.\nError msg: `%s'\n",
               vertex_path, log);
      goto out;
    }

  // Fragment shader
  fragment = glCreateShader (GL_FRAGMENT_SHADER);
  glShaderSource (fragment, 1, &f_shader_source, NULL);
  glCompileShader (fragment);

  // Print errors, if any
  glGetShaderiv (fragment, GL_COMPILE_STATUS, &res);
  if (res == 0)
    {
      glGetShaderInfoLog (fragment, 512, NULL, log);
      fprintf (stderr,
               "Fragment shader `%s' compilation failed.\nError msg: `%s'\n",
               fragment_path, log);
      goto out;
    }

  // Shader program
  shader->id = glCreateProgram ();
  glAttachShader (shader->id, vertex);
  glAttachShader (shader->id, fragment);
  glLinkProgram (shader->id);

  // Print linking errors, if any
  glGetProgramiv (shader->id, GL_LINK_STATUS, &res);
  if (res == 0)
    {
      glGetProgramInfoLog (shader->id, 512, NULL, log);
      fprintf (stderr, "Linking failed for `%d'.\nError msg `%s'\n",
               shader->id, log);
      goto out;
    }

  // Delete the shaders, as they are no longer necessary
  glDeleteShader (vertex);
  glDeleteShader (fragment);

out:

  // Free allocations
  if (vertex_code != NULL)
    {
      free (vertex_code);
      vertex_code = NULL;
    }

  if (fragment_code != NULL)
    {
      free (fragment_code);
      fragment_code = NULL;
    }

  vertex_file = NULL;
  fragment_file = NULL;

  return shader;
}

void
shader_use (struct shader shader)
{
  glUseProgram (shader.id);
}

void
shader_set_bool (struct shader shader, const char *name, _Bool val)
{
  glUniform1i (glGetUniformLocation (shader.id, name), (int)val);
}

void
shader_set_int (struct shader shader, const char *name, int val)
{
  glUniform1i (glGetUniformLocation (shader.id, name), val);
}

void
shader_set_float (struct shader shader, const char *name, float val)
{
  glUniform1f (glGetUniformLocation (shader.id, name), val);
}

void
shader_set_vec2 (struct shader shader, const char *name, vec2 val)
{
  glUniform2fv (glGetUniformLocation (shader.id, name), 1, val);
}

void
shader_set_vec3 (struct shader shader, const char *name, vec3 val)
{
  glUniform3fv (glGetUniformLocation (shader.id, name), 1, val);
}

void
shader_set_vec4 (struct shader shader, const char *name, vec4 val)
{
  glUniform4fv (glGetUniformLocation (shader.id, name), 1, val);
}

void
shader_set_mat2 (struct shader shader, const char *name, mat2 val)
{
  glUniformMatrix2fv (glGetUniformLocation (shader.id, name), 1, GL_FALSE,
                      val[0]);
}

void
shader_set_mat3 (struct shader shader, const char *name, mat3 val)
{
  glUniformMatrix3fv (glGetUniformLocation (shader.id, name), 1, GL_FALSE,
                      val[0]);
}

void
shader_set_mat4 (struct shader shader, const char *name, mat4 val)
{
  glUniformMatrix4fv (glGetUniformLocation (shader.id, name), 1, GL_FALSE,
                      val[0]);
}
