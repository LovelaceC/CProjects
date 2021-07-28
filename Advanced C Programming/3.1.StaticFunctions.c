#include <stdio.h>

// A static function can only be called inside of the file where it's defined,
// that is, `func' can only be called in this file (as functions by default are
// `extern').
static void
func ()
{
  printf ("Heyyy, look at me, I am a static function!!!\n");
}

int
main ()
{
  func ();

  return 0;
}
