#include <glad/glad.h>

#include <stddef.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

void
processInput (GLFWwindow *window)
{
  if (glfwGetKey (window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose (window, 1);
    }
}

// callback function when window resized.
void
framebuffer_size_callback (GLFWwindow *window, int width, int height)
{
  glViewport (0, 0, width, height);
}

int
main (int argc, char **argv)
{
  glfwInit ();
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow (1280, 720, "Viewport", NULL, NULL);
  if (window == NULL)
    {
      fprintf (stderr, "Failed to create a GLFW window.\n");
      glfwTerminate ();

      return -1;
    }

  glfwMakeContextCurrent (window);

  if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
    {
      fprintf (stderr, "Failed to initialise GLAD.\n");
      return -1;
    }

  glViewport (0, 0, 1280, 720);
  glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);

  // Render loop
  while (!glfwWindowShouldClose (window))
    {
      glClearColor (0.2f, 0.3f, 0.3f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      // Process input
      processInput (window);

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glfwTerminate ();

  return 0;
}
