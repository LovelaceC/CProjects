#include <glad/glad.h>

#include <stddef.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

const char *vertex_shader_source
    = "#version 330 core\n"
      "layout (location = 0) in vec3 a_pos;\n"
      "void main()\n"
      "{\n"
      "gl_Position = vec4 (a_pos.x, a_pos.y, a_pos.z, 1.0f);"
      "}\0";

const char *fragment_shader_source
    = "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main ()\n"
      "{\n"
      "FragColor = vec4 (1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n";

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

  // Define shaders
  unsigned int vertex_shader, fragment_shader;

  // Create and compile vertex shader
  vertex_shader = glCreateShader (GL_VERTEX_SHADER);

  glShaderSource (vertex_shader, 1, &vertex_shader_source, NULL);
  glCompileShader (vertex_shader);

  int res = 0;
  char info_log[512] = { 0 };
  glGetShaderiv (vertex_shader, GL_COMPILE_STATUS, &res);

  if (res == 0)
    {
      glGetShaderInfoLog (vertex_shader, 512, NULL, info_log);
      fprintf (stderr, "Error: vertex_shader compilation failed `%s'.\n",
               info_log);
    }

  // Create and compile fragment shader
  fragment_shader = glCreateShader (GL_FRAGMENT_SHADER);
  glShaderSource (fragment_shader, 1, &fragment_shader_source, NULL);
  glCompileShader (fragment_shader);

  glGetShaderiv (fragment_shader, GL_COMPILE_STATUS, &res);
  if (res == 0)
    {
      glGetShaderInfoLog (fragment_shader, 512, NULL, info_log);
      fprintf (stderr, "Error: fragment_shader compilation failed `%s'\n.",
               info_log);
    }

  // Link shaders
  unsigned int shader_program;
  shader_program = glCreateProgram ();
  glAttachShader (shader_program, vertex_shader);
  glAttachShader (shader_program, fragment_shader);
  glLinkProgram (shader_program);

  // Check for errors in the linking of the shaders
  glGetProgramiv (shader_program, GL_LINK_STATUS, &res);
  if (res == 0)
    {
      glGetProgramInfoLog (shader_program, 512, NULL, info_log);
      fprintf (stderr, "Error: error linking shaders `%s'\n", info_log);
    }

  glDeleteShader (vertex_shader);
  glDeleteShader (fragment_shader);

  glViewport (0, 0, 1280, 720);
  glfwSetFramebufferSizeCallback (window, framebuffer_size_callback);

  float vertices[]
      = { -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f };
  unsigned int VBO, VAO;

  glGenVertexArrays (1, &VAO);
  glGenBuffers (1, &VBO);

  // Bind vertex array object
  glBindVertexArray (VAO);

  // Copy our vertices array in a buffer for OpenGL to use
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  // Set the vertex attributes pointers
  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

  // Render loop
  while (!glfwWindowShouldClose (window))
    {
      glClearColor (0.2f, 0.3f, 0.3f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      // Process input
      processInput (window);

      // Draw the object
      glUseProgram (shader_program);
      glBindVertexArray (VAO);
      glDrawArrays (GL_TRIANGLES, 0, 3);

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glfwTerminate ();

  return 0;
}
