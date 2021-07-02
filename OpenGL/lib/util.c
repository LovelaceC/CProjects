#include "util.h"

_Bool
read_file (const char *fname, char *dest)
{
  FILE *f = fopen (fname, "r");
  _Bool res = 0;

  if (!f)
    {
      fprintf (stderr, "Error opening `%s'.\n", fname);
      goto out;
    }

  fseek (f, 0, SEEK_END);
  int len = ftell (f);
  fseek (f, 0, SEEK_SET);

  fread (dest, 1, len, f);

  // if we reach this point, then, the operation was successful
  res = 1;

out:
  fclose (f);
  f = NULL;

  return res;
}
