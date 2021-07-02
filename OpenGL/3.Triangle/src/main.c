#include <stdio.h>

#include <GL/glew.h>

#include <GL/freeglut.h>

#include <lib/math.h>

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

int
main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

  glutInitWindowSize (1024, 768);
  glutInitWindowPosition (100, 100);
  int window = glutCreateWindow ("Triangles!");
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
