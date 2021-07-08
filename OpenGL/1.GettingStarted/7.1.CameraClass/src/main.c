#include <glad/glad.h>

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <stdio.h>

#include <cglm/cglm.h>

#include "shader/shader.h"

#include "camera/camera.h"

// Camera
struct camera camera = { 0 };
float last_x = 1280.0f / 2.0f;
float last_y = 720.0f / 2.0f;
_Bool first_mouse = 0;

// Timing
float delta = 0.0f;
float last_frame = 0.0f;

void
mouse_callback (GLFWwindow *window, double xpos, double ypos)
{
  if (first_mouse)
    {
      last_x = xpos;
      last_y = ypos;
      first_mouse = 0;
    }

  float xoffset = xpos - last_x;
  float yoffset = last_y - ypos;

  last_x = xpos;
  last_y = ypos;

  camera_process_mouse_movement (&camera, xoffset, yoffset, 1);
}

void
scroll_callback (GLFWwindow *window, double xoffset, double yoffset)
{
  camera_process_mouse_scroll (&camera, yoffset);
}

void
processInput (GLFWwindow *window)
{
  if (glfwGetKey (window, GLFW_KEY_W) == GLFW_PRESS)
    {
      camera_process_keyboard (&camera, FORWARD, delta);
    }

  if (glfwGetKey (window, GLFW_KEY_S) == GLFW_PRESS)
    {
      camera_process_keyboard (&camera, BACKWARD, delta);
    }

  if (glfwGetKey (window, GLFW_KEY_A) == GLFW_PRESS)
    {
      camera_process_keyboard (&camera, LEFT, delta);
    }

  if (glfwGetKey (window, GLFW_KEY_D) == GLFW_PRESS)
    {
      camera_process_keyboard (&camera, RIGHT, delta);
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
  glfwSetCursorPosCallback (window, (GLFWcursorposfun)mouse_callback);
  glfwSetScrollCallback (window, scroll_callback);

  // Tell GLFW to capture our mouse
  glfwSetInputMode (window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
    {
      fprintf (stderr, "Failed to initialise GLAD.\n");
      return -1;
    }

  glEnable (GL_DEPTH_TEST);

  // Build and compile our shader program
  struct shader *shader = shader_create ("src/shader/shaders/shader.vs",
                                         "src/shader/shaders/shader.fs");

  // Create camera
  camera_init (&camera);

  float vertices[]
      = { -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 0.0f,
          0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
          -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

          -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
          -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,

          -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f,
          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  0.5f,  1.0f, 0.0f,

          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
          0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 0.0f, 1.0f,
          0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 1.0f,
          0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
          -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

          -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
          -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f };

  vec3 cube_position[] = { { 0.0f, 0.0f, 0.0f },     { 2.0f, 5.0f, -15.0f },
                           { -1.5, -2.2f, -2.5f },   { -3.8f, -2.0f, -12.3f },
                           { -3.8f, -2.0f, -12.3f }, { 2.4f, -0.4f, -3.5f },
                           { -1.7f, 3.0f, -7.5f },   { 1.3f, -2.0f, -2.5f },
                           { 1.5f, 2.0f, -2.5f },    { 1.5f, 0.2f, -1.5f },
                           { -1.3f, 1.0f, -1.5f } };

  unsigned int VBO, VAO;
  glGenVertexArrays (1, &VAO);
  glGenBuffers (1, &VBO);

  // Bind vertex array object
  glBindVertexArray (VAO);

  // Copy our vertices array in a buffer for OpenGL to use
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

  // Texture attribute
  glVertexAttribPointer (1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof (float),
                         (void *)(3 * sizeof (float)));
  glEnableVertexAttribArray (1);

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
      // Per-frame time logic
      float current_frame = glfwGetTime ();
      delta = current_frame - last_frame;
      last_frame = current_frame;

      // Process input
      processInput (window);

      // Render
      glClearColor (0.2f, 0.3f, 0.3f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // Bind texture
      glActiveTexture (GL_TEXTURE0);
      glBindTexture (GL_TEXTURE_2D, texture1);
      glActiveTexture (GL_TEXTURE1);
      glBindTexture (GL_TEXTURE_2D, texture2);

      // Get matrix's uniform location and set matrix
      shader_use (*shader);

      mat4 projection = GLM_MAT4_ZERO_INIT;
      glm_perspective (glm_rad (camera.zoom), 1280.0f / 720.0f, 0.1f, 100.0f,
                       projection);
      int proj_loc = glGetUniformLocation (shader->id, "projection");
      glUniformMatrix4fv (proj_loc, 1, GL_FALSE, projection[0]);

      // View
      mat4 view = GLM_MAT4_ZERO_INIT;
      camera_get_view_matrix (camera, view);

      int view_loc = glGetUniformLocation (shader->id, "view");
      glUniformMatrix4fv (view_loc, 1, GL_FALSE, view[0]);

      // Render boxes
      glBindVertexArray (VAO);

      for (unsigned int i = 0; i < 10; i++)
        {
          mat4 model = GLM_MAT4_IDENTITY_INIT;
          glm_translate (model, cube_position[i]);
          float angle = 20.0f * i;
          glm_rotate (model, glm_rad (angle), (vec3){ 1.0f, 0.3f, 0.5f });

          int model_loc = glGetUniformLocation (shader->id, "model");
          glUniformMatrix4fv (model_loc, 1, GL_FALSE, model[0]);

          glDrawArrays (GL_TRIANGLES, 0, 36);
        }

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glDeleteVertexArrays (1, &VAO);
  glDeleteBuffers (1, &VBO);

  glfwTerminate ();

  return 0;
}
