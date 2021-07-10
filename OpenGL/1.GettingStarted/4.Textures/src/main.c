#include <glad/glad.h>

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include <shader.h>

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

  GLFWwindow *window = glfwCreateWindow (640, 480, "Viewport", NULL, NULL);
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
  struct shader *shader
      = shader_create ("src/shaders/shader.vs", "src/shaders/shader.fs");

  // Setup vertex data
  float vertices[] = {
    // positions          // colors           // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };

  unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays (1, &VAO);
  glGenBuffers (1, &VBO);
  glGenBuffers (1, &EBO);

  // Bind vertex array object
  glBindVertexArray (VAO);

  // Copy our vertices array in a buffer for OpenGL to use
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (indices), indices,
                GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

  // Color attribute
  glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof (float),
                         (void *)(3 * sizeof (float)));
  glEnableVertexAttribArray (1);

  // Texture attribute
  glVertexAttribPointer (2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof (float),
                         (void *)(6 * sizeof (float)));
  glEnableVertexAttribArray (2);

  // Create texture
  unsigned int texture;
  glGenTextures (1, &texture);
  glBindTexture (GL_TEXTURE_2D, texture);

  // Set the texture wrapping parameters
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Load and generate the texture
  int width, height, nr_channels;
  unsigned char *data
      = stbi_load ("res/container.jpg", &width, &height, &nr_channels, 0);

  // If there was any error
  if (!data)
    {
      fprintf (stderr, "Failed to load texture.\n");
      return -1;
    }

  glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                GL_UNSIGNED_BYTE, data);
  glGenerateMipmap (GL_TEXTURE_2D);

  // Free the image
  stbi_image_free (data);

  // Render loop
  while (!glfwWindowShouldClose (window))
    {
      // Process input
      processInput (window);

      // Render

      // Clear the colorbuffer
      glClearColor (0.2f, 0.3f, 0.3f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      // Bind texture
      glBindTexture (GL_TEXTURE_2D, texture);

      // Render the triangle
      shader_use (*shader);
      glBindVertexArray (VAO);
      glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glDeleteVertexArrays (1, &VAO);
  glDeleteBuffers (1, &VBO);

  glfwTerminate ();

  return 0;
}
