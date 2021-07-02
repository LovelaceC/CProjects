#ifndef __MATH_H
#define __MATH_H

#include <math.h>

#include <assimp/vector3.h>

#include <assimp/matrix3x3.h>
#include <assimp/matrix4x4.h>

// TODO: Finish this

#define to_radian(x) (float)(((x)*M_PI / 180.0f))
#define to_degree(x) (float)(((x)*180.0f / M_PI))

struct vector2i
{
  int x, y;
};

struct vector2f
{
  float x, y;
};

struct vector3f
{
  float x, y, z;
};

struct vector4f
{
  float x, y, z, w;
};

struct pers_proj_info
{
  float fov, width, height, z_near, z_far;
};

struct ortho_proj_info
{
  float r, l, b, t, n, f;
};

struct matrix4f
{
  float m[4][4];
};

struct vector2i vector2i_create (int x, int y);

struct vector2f vector2f_create (float x, float y);

struct vector3f vector3f_create (float x, float y, float z);
struct vector3f vector3f_from_arr (float *arr);
struct vector3f vector3f_create_all (float val);
void vector3f_add_vectors (struct vector3f *vec1, const struct vector3f vec2);
void vector3f_sub_vectors (struct vector3f *vec1, const struct vector3f vec2);

struct vector4f vector4f_create (float x, float y, float z, float w);

struct matrix4f matrix4f_create (float, float, float, float, // 1
                                 float, float, float, float, // 2
                                 float, float, float, float, // 3
                                 float, float, float, float);

#endif
