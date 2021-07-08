#include "camera.h"
#include <cglm/vec3.h>

static void
camera_update_vectors (struct camera *cam)
{
  vec3 front = { 0 };

  front[0] = cos (glm_rad (cam->yaw)) * cos (glm_rad (cam->pitch)); // X
  front[1] = sin (glm_rad (cam->pitch));                            // Y
  front[2] = sin (glm_rad (cam->yaw)) * cos (glm_rad (cam->pitch)); // Z

  glm_normalize_to (front, cam->front);

  vec3 temp_right = { 0 };
  vec3 temp_up = { 0 };

  glm_cross (cam->front, cam->world_up, temp_right);
  glm_normalize_to (temp_right, cam->right);

  glm_cross (cam->right, cam->front, temp_up);
  glm_normalize_to (temp_up, cam->up);
}

void
camera_init (struct camera *cam)
{
  cam->position[0] = 0.0f; // X
  cam->position[1] = 0.0f; // Y
  cam->position[2] = 3.0f; // Z

  cam->world_up[0] = 0.0f; // X
  cam->world_up[1] = 1.0f; // Y
  cam->world_up[2] = 0.0f; // Z

  cam->yaw = YAW;
  cam->pitch = PITCH;

  cam->front[0] = 0.0f;  // X
  cam->front[1] = 0.0f;  // Y
  cam->front[2] = -1.0f; // Z

  cam->movement_speed = SPEED;
  cam->mouse_sensitivity = SENSITIVITY;
  cam->zoom = ZOOM;

  camera_update_vectors (cam);
}

void
camera_get_view_matrix (struct camera cam, mat4 dest)
{
  vec3 temp = { 0 };
  glm_vec3_add (cam.position, cam.front, temp);

  glm_lookat (cam.position, temp, cam.up, dest);
}

void
camera_process_keyboard (struct camera *cam, enum camera_movement direction,
                         float delta_time)
{
  float velocity = cam->movement_speed * delta_time;

  vec3 temp = { 0 };

  if (direction == FORWARD)
    {
      glm_vec3_muladds (cam->front, velocity, cam->position);
    }

  if (direction == BACKWARD)
    {
      glm_vec3_muladds (cam->front, velocity, temp);
      glm_vec3_sub (cam->position, temp, cam->position);
    }

  if (direction == LEFT)
    {
      glm_vec3_muladds (cam->right, velocity, temp);
      glm_vec3_sub (cam->position, temp, cam->position);
    }

  if (direction == RIGHT)
    {
      glm_vec3_muladds (cam->right, velocity, temp);
      glm_vec3_add (cam->position, temp, cam->position);
    }
}

void
camera_process_mouse_movement (struct camera *cam, float xoffset,
                               float yoffset, _Bool constrain_pitch)
{
  xoffset *= cam->mouse_sensitivity;
  yoffset *= cam->mouse_sensitivity;

  cam->yaw += xoffset;
  cam->pitch += yoffset;

  if (constrain_pitch)
    {
      if (cam->pitch > 89.0f)
        {
          cam->pitch = 89.0f;
        }

      if (cam->pitch < -89.0f)
        {
          cam->pitch = -89.0f;
        }
    }

  camera_update_vectors (cam);
}

void
camera_process_mouse_scroll (struct camera *cam, float yoffset)
{
  cam->zoom -= (float)yoffset;

  if (cam->zoom < 1.0f)
    {
      cam->zoom = 1.0f;
    }

  if (cam->zoom > 45.0f)
    {
      cam->zoom = 45.0f;
    }
}
