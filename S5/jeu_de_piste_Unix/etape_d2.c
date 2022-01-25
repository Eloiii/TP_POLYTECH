/* Fichier source pour l 'etape D2. */
/* Le programme est coup√© en 3 morceaux. */
/* Assemblez-les puis ex√©cutez le programme (apr√®s l' avoir compil √ ©si besoin). */
#include <stdio.h>
#include <string.h>
void dprint (char *str)
{
  while (str)
    {
      unsigned val;
      if (sscanf (str, "%u", &val) == EOF)
	{
	  break;
	}
      str = strchr (str, ' ');
      if (str != NULL)
	str++;
      else
	break;
      printf ("%c", val);
    }
  printf ("\n");
}

int main (void)
{
  dprint ("86 105 115 105 98 108 101 109 101 110 116 44 32 108 "
	  "101 32 99 111 112 105 101 114 45 99 111 108 108 101 "
	  "114 32 97 32 109 97 114 99 104 101 32 33 ");
  dprint (" ");
  dprint ("76 97 32 115 117 105 116 101 32 115 101 32 116 114 "
	  "111 117 118 101 32 105 99 105 32 58 ");
  dprint (" ");
  dprint ("104 116 116 112 58 47 47 103 111 101 100 101 108 46 "
	  "101 46 117 106 102 45 103 114 101 110 111 98 108 101 "
	  "46 102 114 47 126 112 97 108 105 120 110 47 106 101 "
	  "117 45 100 101 45 112 105 115 116 101 47 52 98 97 51 "
	  "47 116 101 120 116 45 101 100 105 116 111 114 45 102 "
	  "114 46 112 104 112 ");
  dprint (" ");
  dprint ("79 117 118 114 101 122 32 99 101 116 116 101 32 112 "
	  "97 103 101 32 100 97 110 115 32 118 111 116 114 101 "
	  "32 110 97 118 105 103 97 116 101 117 114 32 101 116 "
	  "32 108 97 105 115 115 101 122 45 118 111 117 115 32 "
	  "103 117 105 100 101 114 46 ");
  return 0;
}
