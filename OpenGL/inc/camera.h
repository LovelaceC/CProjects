#ifndef __CAMERA_H
#define __CAMERA_H

#include <cglm/cglm.h>

#include <math.h>

// Default camera values
#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 2.5f
#define SENSITIVITY 0.1f
#define ZOOM 45.0f

enum camera_movement
{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

struct camera
{
  // Camera attributes
  vec3 position;
  vec3 front;
  vec3 up;
  vec3 right;
  vec3 world_up;

  // Euler angles
  float yaw;
  float pitch;

  // Camera options
  float movement_speed;
  float mouse_sensitivity;
  float zoom;
};

void camera_init (struct camera *cam);
void camera_get_view_matrix (struct camera cam, mat4 dest);
void camera_process_keyboard (struct camera *cam,
                              enum camera_movement direction,
                              float delta_time);
void camera_process_mouse_movement (struct camera *cam, float xoffset,
                                    float yoffset, _Bool constrain_pitch);
void camera_process_mouse_scroll (struct camera *cam, float yoffset);

#endif
