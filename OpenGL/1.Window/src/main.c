#include <GL/freeglut.h>
#include <stdio.h>

static void
render_scene ()
{
  glClear (GL_COLOR_BUFFER_BIT);
  glutSwapBuffers ();
}

int
main (int argc, char **argv)
{
  glutInit (&argc, argv);

  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

  glutInitWindowSize (1024, 768);
  glutInitWindowPosition (100, 100);
  int window = glutCreateWindow ("Simple window");
  printf ("Window id: %d\n", window);

  glClearColor (0.0f, 0.0f, 0.0f, 0.0f);

  glutDisplayFunc (render_scene);

  glutMainLoop ();

  return 0;
}
