#include <glad/glad.h>

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include <cglm/cglm.h>

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
  unsigned int texture1, texture2;
  glGenTextures (1, &texture1);
  glBindTexture (GL_TEXTURE_2D, texture1);

  // Load and generate the texture
  int width, height, nr_channels;

  stbi_set_flip_vertically_on_load (1);

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

  // Texture 2
  glGenTextures (1, &texture2);
  glBindTexture (GL_TEXTURE_2D, texture2);

  data = stbi_load ("res/awesomeface.png", &width, &height, &nr_channels, 0);

  if (!data)
    {
      fprintf (stderr, "Failed to load second texture.\n");
      return -1;
    }

  glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                GL_UNSIGNED_BYTE, data);
  glGenerateMipmap (GL_TEXTURE_2D);

  // Free the image
  stbi_image_free (data);

  // We have to set the shader before setting uniforms
  shader_use (*shader);

  shader_set_int (*shader, "texture1", 0);
  shader_set_int (*shader, "texture2", 1);

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
      glActiveTexture (GL_TEXTURE0);
      glBindTexture (GL_TEXTURE_2D, texture1);
      glActiveTexture (GL_TEXTURE1);
      glBindTexture (GL_TEXTURE_2D, texture2);

      // Create transformations
      mat4 transform = GLM_MAT4_IDENTITY_INIT;
      glm_translate (transform, (vec3){ 0.5f, -0.5f, 0.0f });
      glm_rotate (transform, (float)glfwGetTime (),
                  (vec3){ 0.0f, 0.0f, 1.0f });

      // Get matrix's uniform location and set matrix
      shader_use (*shader);

      // Create transformations
      mat4 model = GLM_MAT4_IDENTITY_INIT;
      glm_rotate (model, glm_rad (-55.0f), (vec3){ 1.0f, 0.0f, 0.0f });

      mat4 view = GLM_MAT4_IDENTITY_INIT;
      glm_translate (view, (vec3){ 0.0f, 0.0f, -3.0f });

      mat4 projection = GLM_MAT4_IDENTITY_INIT;
      glm_perspective (glm_rad (45.0f), 640.0f / 480.0f, 0.1f, 100.0f,
                       projection);

      int model_loc = glGetUniformLocation (shader->id, "model");
      glUniformMatrix4fv (model_loc, 1, GL_FALSE, model[0]);

      int view_loc = glGetUniformLocation (shader->id, "view");
      glUniformMatrix4fv (view_loc, 1, GL_FALSE, view[0]);

      int projection_loc = glGetUniformLocation (shader->id, "projection");
      glUniformMatrix4fv (projection_loc, 1, GL_FALSE, projection[0]);

      // Render container
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
