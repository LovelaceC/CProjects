#include <stdio.h>

static double static_double_var = 0;
float program_float = 0.0f;

static void
func ()
{
  printf ("Heyyy, I am only accessible from this file!\n");
}

int
main ()
{
  int block_scope = 0;
  printf ("Block scope: %d\n", block_scope);

  static float permament_storage = 0.0f;
  printf ("Permanent storage: %f\n", permament_storage);

  register int reg_int_var = 0;
  printf ("Register variable: %d\n", reg_int_var);

  printf ("Static double variable: %f\n", static_double_var);
  printf ("Global float accessible from the entire program: %f\n",
          program_float);

  func ();

  return 0;
}
