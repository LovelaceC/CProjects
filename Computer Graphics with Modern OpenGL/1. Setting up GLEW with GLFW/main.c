/* Copyright (C) 2021 Jinx.
   This file is part of CProjects.
   Created by Jinx CGCO <HermadesCGCO@disroot.org>, 2021.

   CProjects is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License V3 as published by the
   Free Software Foundation.

   CProjects is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRAMTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License V3
   for more details.

   You should have received a copy of the GNU General Public License V3
   along with CProjects; if not, see
   <https://www.gnu.org/licenses/>. */

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/* Dimensions of our window. */
const GLint WIDTH = 800, HEIGHT = 600;

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

  // Loop until window should close
  while (!glfwWindowShouldClose (main_window))
    {
      // Get and handle user input events
      glfwPollEvents ();

      // Clear window
      glClearColor (1.0f, 0.0f, 0.0f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers (main_window);
    }

  return 0;
}
