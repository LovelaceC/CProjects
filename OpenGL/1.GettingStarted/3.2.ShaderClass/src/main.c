#include <glad/glad.h>

#include <stddef.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

#include <math.h>

#include "shader/shader.h"

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
  glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);

  if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
    {
      fprintf (stderr, "Failed to initialise GLAD.\n");
      return -1;
    }

  // Build and compile our shader program
  struct shader *shader = shader_create ("src/shader/shaders/shader.vs",
                                         "src/shader/shaders/shader.fs");

  // Setup vertex data
  float vertices[] = {
    // positions        // colors
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
  };

  unsigned int VBO, VAO;
  glGenVertexArrays (1, &VAO);
  glGenBuffers (1, &VBO);

  // Bind vertex array object
  glBindVertexArray (VAO);

  // Copy our vertices array in a buffer for OpenGL to use
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

  // Color attribute
  glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof (float),
                         (void *)(3 * sizeof (float)));
  glEnableVertexAttribArray (1);

  // Render loop
  while (!glfwWindowShouldClose (window))
    {
      // Process input
      processInput (window);

      // Render

      // Clear the colorbuffer
      glClearColor (0.2f, 0.3f, 0.3f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      // Render the triangle
      shader_use (*shader);
      glBindVertexArray (VAO);
      glDrawArrays (GL_TRIANGLES, 0, 3);

      glBindVertexArray (VAO);
      glDrawArrays (GL_TRIANGLES, 0, 3);

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glDeleteVertexArrays (1, &VAO);
  glDeleteBuffers (1, &VBO);

  glfwTerminate ();

  return 0;
}
