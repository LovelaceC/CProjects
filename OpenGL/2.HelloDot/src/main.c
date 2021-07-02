#include <stdio.h>

#include <GL/glew.h>

#include <GL/freeglut.h>

#include <lib/math.h>

GLuint VBO;

static void
create_vertex_buffer ()
{
  struct vector3f vertices[1];
  vertices[0] = vector3f_create (0.0f, 0.0f, 0.0f);

  glGenBuffers (1, &VBO);
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);
}

static void
render_scene ()
{
  glClear (GL_COLOR_BUFFER_BIT);

  glBindBuffer (GL_ARRAY_BUFFER, VBO);

  glEnableVertexAttribArray (0);

  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays (GL_POINTS, 0, 1);

  glDisableVertexAttribArray (0);

  glutSwapBuffers ();
}

int
main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

  glutInitWindowSize (1024, 768);
  glutInitWindowPosition (100, 100);
  int window = glutCreateWindow ("Hello dot");
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

  glutDisplayFunc (render_scene);
  glutMainLoop ();

  return 0;
}
