#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GL/freeglut.h>

#include <lib/math.h>
#include <lib/util.h>

GLuint VBO;

static void
render_scene ()
{
  glClear (GL_COLOR_BUFFER_BIT);

  glBindBuffer (GL_ARRAY_BUFFER, VBO);

  glEnableVertexAttribArray (0);

  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays (GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray (0);

  glutSwapBuffers ();
}

static void
create_vertex_buffer ()
{
  struct vector3f vertices[3];
  vertices[0] = vector3f_create (-1.0f, -1.0f, 0.0f); // Bottom left
  vertices[1] = vector3f_create (1.0f, -1.0f, 0.0f);  // Bottom right
  vertices[2] = vector3f_create (0.0f, 1.0f, 0.0f);   // Top

  glGenBuffers (1, &VBO);
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);
}

static void
add_shader (GLuint shader_program, const char *shader_text, GLenum shader_type)
{
  GLuint shader_obj = glCreateShader (shader_type);

  if (shader_obj == 0)
    {
      fprintf (stderr, "Error creating shader type %d\n", shader_type);
      exit (EXIT_FAILURE);
    }

  const GLchar *p[1];
  p[0] = shader_text;

  GLint lengths[1];
  lengths[0] = (GLint)strlen (shader_text);

  glShaderSource (shader_obj, 1, p, lengths);

  glCompileShader (shader_obj);

  GLint res;
  glGetShaderiv (shader_obj, GL_COMPILE_STATUS, &res);

  if (!res)
    {
      GLchar log[1024] = { 0 };
      glGetShaderInfoLog (shader_obj, 1024, NULL, log);
      fprintf (stderr, "Error compiling shader type %d: '%s'\n", shader_type,
               log);
      exit (EXIT_FAILURE);
    }

  glAttachShader (shader_program, shader_obj);
}

const char *vertex = "src/shaders/shader.vs";
const char *fragment = "src/shaders/shader.fs";

static void
compile_shaders ()
{
  GLuint shader_program = glCreateProgram ();

  if (shader_program == 0)
    {
      fprintf (stderr, "Error creating shader program.\n");
      exit (EXIT_FAILURE);
    }

  char vs[1024] = { 0 }, fs[1024] = { 0 };

  if (!read_file (vertex, vs))
    {
      exit (EXIT_FAILURE);
    }

  add_shader (shader_program, vs, GL_VERTEX_SHADER);

  if (!read_file (fragment, fs))
    {
      exit (EXIT_FAILURE);
    }

  add_shader (shader_program, fs, GL_FRAGMENT_SHADER);

  GLint res = 0;
  GLchar log[1024] = { 0 };

  glLinkProgram (shader_program);

  glGetProgramiv (shader_program, GL_LINK_STATUS, &res);
  if (!res)
    {
      glGetProgramInfoLog (shader_program, sizeof (log), NULL, log);
      fprintf (stderr, "Error linking shader program: '%s'\n", log);
      exit (EXIT_FAILURE);
    }

  glValidateProgram (shader_program);
  glGetProgramiv (shader_program, GL_VALIDATE_STATUS, &res);
  if (!res)
    {
      glGetProgramInfoLog (shader_program, sizeof (log), NULL, log);
      fprintf (stderr, "Invalid shader program: '%s'\n", log);
      exit (EXIT_FAILURE);
    }

  glUseProgram (shader_program);
}

int
main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

  glutInitWindowSize (1024, 768);
  glutInitWindowPosition (100, 100);
  int window = glutCreateWindow ("Shaders");
  printf ("Window id: %d\n", window);

  // Must be done after glut is initialised!
  GLenum res = glewInit ();
  if (res != GLEW_OK)
    {
      fprintf (stderr, "Error: '%s'\n", glewGetErrorString (res));
      return 1;
    }

  glClearColor (0.0f, 0.0f, 0.0f, 0.0f);

  create_vertex_buffer ();
  compile_shaders ();

  glutDisplayFunc (render_scene);
  glutMainLoop ();

  return 0;
}
