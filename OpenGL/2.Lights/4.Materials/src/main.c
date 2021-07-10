#include <cglm/mat4.h>
#include <cglm/vec3.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

#include <cglm/cglm.h>

#include <shader.h>

#include <camera.h>

// Camera
struct camera camera = { 0 };
float last_x = 1280.0f / 2.0f;
float last_y = 720.0f / 2.0f;
_Bool first_mouse = 0;

// Timing
float delta = 0.0f;
float last_frame = 0.0f;

// Lighting
vec3 light_pos = { 1.2f, 1.0f, 2.0f };

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

  // Load all OpenGL function pointers
  if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
    {
      fprintf (stderr, "Failed to initialise GLAD.\n");
      return -1;
    }

  // Configure global OpenGL state
  glEnable (GL_DEPTH_TEST);

  // Build and compile our shader programs
  struct shader *shader
      = shader_create ("src/shaders/shader.vs", "src/shaders/shader.fs");
  struct shader *light_cube_shader = shader_create (
      "src/shaders/light_cube.vs", "src/shaders/light_cube.fs");

  // Create camera
  camera_init (&camera);

  float vertices[]
      = { -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  -0.5f, -0.5f,
          0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
          0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f, -0.5f, 0.5f,  -0.5f,
          0.0f,  0.0f,  -1.0f, -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,

          -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f, 0.5f,
          0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  -0.5f, 0.5f,  0.5f,
          0.0f,  0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,

          -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  -0.5f,
          -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,
          -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, 0.5f,
          -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,

          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  -0.5f,
          1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
          0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,
          1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

          -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, -0.5f,
          0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,
          0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,  -0.5f, -0.5f, 0.5f,
          0.0f,  -1.0f, 0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,

          -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f,
          0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,
          0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f };

  unsigned int VBO, cube_vao;
  glGenVertexArrays (1, &cube_vao);
  glGenBuffers (1, &VBO);

  glBindBuffer (GL_ARRAY_BUFFER, VBO);
  glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray (cube_vao);

  // Position attribute
  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

  // Normal attribute
  glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof (float),
                         (void *)(3 * sizeof (float)));
  glEnableVertexAttribArray (1);

  // Also, let's configure the light's VAO
  unsigned int light_cube_vao;
  glGenVertexArrays (1, &light_cube_vao);
  glBindVertexArray (light_cube_vao);

  // We only need to bind to the VBO, no need to fill it
  glBindBuffer (GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof (float),
                         (void *)0);
  glEnableVertexAttribArray (0);

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
      glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // Get matrix's uniform location and set matrix
      shader_use (*shader);
      shader_set_vec3 (*shader, "l.position", light_pos);
      shader_set_vec3 (*shader, "view_pos", camera.position);

      // Light properties
      vec3 light_color = { 0 };
      light_color[0] = sin (glfwGetTime () * 2.0f);
      light_color[1] = sin (glfwGetTime () * 0.7f);
      light_color[2] = sin (glfwGetTime () * 1.3f);
      vec3 diffuse_color = { 0 };
      glm_vec3_muladds (light_color, 0.5f, diffuse_color);
      vec3 ambient_color = { 0 };
      glm_vec3_muladds (diffuse_color, 0.2f, ambient_color);
      shader_set_vec3 (*shader, "l.ambient", ambient_color);
      shader_set_vec3 (*shader, "l.diffuse", diffuse_color);
      shader_set_vec3 (*shader, "l.specular", (vec3){ 1.0f, 1.0f, 1.0f });

      // Material properties
      shader_set_vec3 (*shader, "mat.ambient", (vec3){ 1.0f, 0.5f, 0.31f });
      shader_set_vec3 (*shader, "mat.diffuse", (vec3){ 1.0f, 0.5f, 0.31f });
      shader_set_vec3 (*shader, "mat.specular", (vec3){ 0.5f, 0.5f, 0.5f });
      shader_set_float (*shader, "mat.shininess", 32.0f);

      // View/projection transformations
      mat4 projection = GLM_MAT4_IDENTITY_INIT;
      glm_perspective (glm_rad (camera.zoom), 1280.0f / 720.0f, 0.1f, 100.0f,
                       projection);
      mat4 view = GLM_MAT4_ZERO_INIT;
      camera_get_view_matrix (camera, view);
      shader_set_mat4 (*shader, "projection", projection);
      shader_set_mat4 (*shader, "view", view);

      // World transformation
      mat4 model = GLM_MAT4_IDENTITY_INIT;
      shader_set_mat4 (*shader, "model", model);

      // Render the cube
      glBindVertexArray (cube_vao);
      glDrawArrays (GL_TRIANGLES, 0, 36);

      // Also, draw the lamp object
      shader_use (*light_cube_shader);
      shader_set_mat4 (*light_cube_shader, "projection", projection);
      shader_set_mat4 (*light_cube_shader, "view", view);

      mat4 model_light = GLM_MAT4_IDENTITY_INIT;
      glm_translate (model_light, light_pos);
      glm_scale (model_light, (vec3){ 0.2f, 0.2f, 0.2f });
      shader_set_mat4 (*light_cube_shader, "model", model_light);

      glBindVertexArray (light_cube_vao);
      glDrawArrays (GL_TRIANGLES, 0, 36);

      // Check and call events and swap the buffers
      glfwSwapBuffers (window);
      glfwPollEvents ();
    }

  glDeleteVertexArrays (1, &cube_vao);
  glDeleteVertexArrays (1, &light_cube_vao);
  glDeleteBuffers (1, &VBO);

  glfwTerminate ();

  return 0;
}
