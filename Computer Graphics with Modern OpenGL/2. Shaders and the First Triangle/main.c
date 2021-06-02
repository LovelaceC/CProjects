/* Copyright (C) 2021 Bassara.
   This file is part of CProjects.
   Created by Bassara <HermadesCGCO@disroot.org>, 2021.

   CProjects is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License V3 as published by the
   Free Software Foundation.

   CProjects is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License V3
   for more details.

   You should have received a copy of the GNU General Public License V3
   along with CProjects; if not, see
   <https://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/* Dimensions of our window. */
const GLint WIDTH = 800, HEIGHT = 600;

GLuint VAO, VBO, shader;

// Vertex shader
static const char *vertex_shader = "\n\
      #version 330\n\
      layout (location = 0) in vec3 pos;\n\
      void\n\
      main ()\n\
      {\n\
      gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);\n\
      }\n";

// Fragment shader
static const char *fragment_shader = "\n\
                                     #version 330\n\
                                     out vec4 colour;\n\
                                     void\n\
                                     main ()\n\
                                     {\n\
                                     colour = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n\
                                     }\n";

void
create_triangle ()
{
  GLfloat vertices[]
      = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };

  glGenVertexArrays (1, &VAO);
  glBindVertexArray (VAO);

  glGenBuffers (1, &VBO);
  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray (0);

  glBindBuffer (GL_ARRAY_BUFFER, 0);

  glBindVertexArray (0);
}

void
add_shader (GLuint program, const char *shader_code, GLenum shader_type)
{
  GLuint the_shader = glCreateShader (shader_type);

  const GLchar *code[1];
  code[0] = shader_code;

  GLint code_length[1];
  code_length[0] = strlen (shader_code);

  glShaderSource (the_shader, 1, code, code_length);
  glCompileShader (the_shader);

  GLint result = 0;
  GLchar error_log[1024] = { 0 };

  glGetShaderiv (the_shader, GL_COMPILE_STATUS, &result);

  if (!result)
    {
      glGetShaderInfoLog (the_shader, sizeof (error_log), NULL, error_log);
      printf ("Error compiling the %d shader: %s\n", shader_type, error_log);
      return;
    }

  glAttachShader (program, the_shader);
}

void
compile_shaders ()
{
  shader = glCreateProgram ();

  if (!shader)
    {
      printf ("Error creating shader program!\n");
      return;
    }

  add_shader (shader, vertex_shader, GL_VERTEX_SHADER);
  add_shader (shader, fragment_shader, GL_FRAGMENT_SHADER);

  GLint result = 0;
  GLchar error_log[1024] = { 0 };

  glLinkProgram (shader);
  glGetProgramiv (shader, GL_LINK_STATUS, &result);

  if (!result)
    {
      glGetProgramInfoLog (shader, sizeof (error_log), NULL, error_log);
      printf ("Error linking program: %s\n", error_log);
      return;
    }

  glValidateProgram (shader);
  glGetProgramiv (shader, GL_VALIDATE_STATUS, &result);

  if (!result)
    {
      glGetProgramInfoLog (shader, sizeof (error_log), NULL, error_log);
      printf ("Error validating program: %s\n", error_log);
      return;
    }
}

int
main ()
{
  // Initialise GLFW
  if (!glfwInit ())
    {
      printf ("GLFW Initialisation failed.\n");
      glfwTerminate ();
      return 1;
    }

  // Setup GLFW window properties
  // OpenGL version
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);

  // Core profile = No backwards compatibility
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Allow forward compatibility
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *main_window
      = glfwCreateWindow (WIDTH, HEIGHT, "Test Window", NULL, NULL);

  if (!main_window)
    {
      printf ("GLFW window creation failed.\n");
      glfwTerminate ();
      return 1;
    }

  // Get buffer size information
  int buffer_width, buffer_height;
  glfwGetFramebufferSize (main_window, &buffer_width, &buffer_height);

  // Set context for GLEW to use
  glfwMakeContextCurrent (main_window);

  // Allow modern extension features
  glewExperimental = GL_TRUE;

  if (glewInit () != GLEW_OK)
    {
      printf ("GLEW Initialisation failed!\n");
      glfwDestroyWindow (main_window);
      glfwTerminate ();
      return 1;
    }

  // Setup Viewport size
  glViewport (0, 0, buffer_width, buffer_height);

  create_triangle ();
  compile_shaders ();

  // Loop until window should close
  while (!glfwWindowShouldClose (main_window))
    {
      // Get and handle user input events
      glfwPollEvents ();

      // Clear window
      glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      glUseProgram (shader);

      glBindVertexArray (VAO);

      glDrawArrays (GL_TRIANGLES, 0, 3);

      glBindVertexArray (0);

      glUseProgram (0);

      glfwSwapBuffers (main_window);
    }

  return 0;
}
