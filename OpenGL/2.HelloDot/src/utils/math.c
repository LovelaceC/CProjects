#include "math.h"

struct vector2i
vector2i_create (int x, int y)
{
  struct vector2i v = { .x = x, .y = y };
  return v;
}

struct vector2f
vector2f_create (float x, float y)
{
  struct vector2f v = { .x = x, .y = y };
  return v;
}

struct vector3f
vector3f_create (float x, float y, float z)
{
  struct vector3f v = { .x = x, .y = y, .z = z };
  return v;
}

struct vector3f
vector3f_from_arr (float *arr)
{
  // TODO: Improve this
  struct vector3f v = { .x = arr[0], .y = arr[1], .z = arr[2] };
  return v;
}

struct vector3f
vector3f_create_all (float val)
{
  struct vector3f v = { .x = val, .y = val, .z = val };
  return v;
}

void
vector3f_add_vectors (struct vector3f *vec1, const struct vector3f vec2)
{
  vec1->x += vec2.x;
  vec1->y += vec2.y;
  vec1->z += vec2.z;
}

void
vector3f_sub_vectors (struct vector3f *vec1, const struct vector3f vec2)
{
  vec1->x -= vec2.x;
  vec1->y -= vec2.y;
  vec1->z -= vec2.z;
}

struct vector4f
vector4f_create (float x, float y, float z, float w)
{
  struct vector4f v = { .x = x, .y = y, .z = z, .w = w };
  return v;
}

struct matrix4f
matrix4f_create (float a00, float a01, float a02, float a03, float a10,
                 float a11, float a12, float a13, float a20, float a21,
                 float a22, float a23, float a30, float a31, float a32,
                 float a33)
{
  struct matrix4f m;

  m.m[0][0] = a00;
  m.m[0][1] = a01;
  m.m[0][2] = a02;
  m.m[0][3] = a03;

  m.m[1][0] = a10;
  m.m[1][1] = a11;
  m.m[1][2] = a12;
  m.m[1][3] = a13;

  m.m[2][0] = a20;
  m.m[2][1] = a21;
  m.m[2][2] = a22;
  m.m[2][3] = a23;

  m.m[3][0] = a30;
  m.m[3][1] = a31;
  m.m[3][2] = a32;
  m.m[3][3] = a33;

  return m;
}
