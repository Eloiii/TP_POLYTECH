/* Fichier source pour l'etape D1. */
/* Ce programme doit etre dans un fichier etape_d1.c */
/* Corrigez les erreurs, puis */
/* compilez-le et executez-le pour continuer. */
/*  */
/* Le fichier est volontairement illisible pour rendre l'exercice plus */
/* "amusant". */
#include <stdio.h>
#include <string.h>

void dprint(char *str) {
	while (str) {
		unsigned val;
		if (sscanf(str, "%u", &val) == EOF) {
			break;
		}
		str = strchr(str, ' ');
		if (str != NULL)
			str++;
		else
			break;
		printf("%c", val);
	}
	printf("\n");
}
int main(void)
{
	dprint("66 111 110 106 111 117 114 44 ");
	dprint(" ");
	dprint("83 105 32 118 111 117 115 32 108 105 115 101 122 32 "
	       "99 101 99 105 44 32 99 39 101 115 116 32 112 114 111 "
	       "98 97 98 108 101 109 101 110 116 32 113 117 101 32 "
	       "118 111 117 115 32 97 118 101 122 32 114 101 117 115 "
	       "115 105 32 97 ");
	dprint("99 111 109 112 105 108 101 114 32 108 101 32 102 105 "
	       "99 104 105 101 114 32 101 116 97 112 101 95 100 49 "
	       "46 99 46 ");

	dprint("");

	dprint("76 39 101 116 97 112 101 32 115 117 105 118 97 110 "
	       "116 101 32 101 115 116 32 97 117 115 115 105 32 117 "
	       "110 32 112 114 111 103 114 97 109 109 101 32 67 32 "
	       "97 32 99 111 109 112 105 108 101 114 44 ");
	dprint("109 97 105 115 32 105 108 32 97 32 101 116 101 32 100 "
	       "101 99 111 117 112 101 32 101 110 32 112 108 117 115 "
	       "105 101 117 114 115 32 109 111 114 99 101 97 117 120 "
	       "46 32 76 101 32 112 114 101 109 105 101 114 32 101 "
	       "115 116 ");
	dprint("100 97 110 115 32 117 110 32 102 105 99 104 105 101 "
	       "114 32 79 112 101 110 68 111 99 117 109 101 110 116 "
	       "32 40 76 105 98 114 101 79 102 102 105 99 101 44 32 "
	       "79 112 101 110 79 102 102 105 99 101 46 111 114 103 "
	       "44 32 46 46 46 41 32 113 117 105 32 115 101 ");
	dprint("116 114 111 117 118 101 32 105 99 105 32 58 ");
	dprint(" ");
	dprint("104 116 116 112 58 47 47 103 111 101 100 101 108 46 "
	       "101 46 117 106 102 45 103 114 101 110 111 98 108 101 "
	       "46 102 114 47 126 112 97 108 105 120 110 47 106 101 "
	       "117 45 100 101 45 112 105 115 116 101 47 101 116 97 "
	       "112 101 95 100 50 45 49 45 99 46 111 100 116 ");
	dprint(" ");
	dprint("76 101 32 115 101 99 111 110 100 32 101 115 116 32 "
	       "100 97 110 115 32 117 110 32 102 105 99 104 105 101 "
	       "114 32 116 101 120 116 101 32 113 117 105 32 115 101 "
	       "32 116 114 111 117 118 101 32 100 97 110 115 ");
	dprint(" ");
	dprint("126 112 97 108 105 120 110 47 106 101 117 45 100 101 "
	       "45 112 105 115 116 101 47 101 116 97 112 101 95 100 "
	       "50 45 50 45 99 46 116 120 116 ");
	dprint(" ");
	dprint("69 116 32 108 101 32 100 101 114 110 105 101 114 32 "
	       "101 115 116 32 105 99 105 32 58 ");
	dprint(" ");
	dprint(" ");
	dprint("34 51 50 32 49 49 48 32 57 55 32 49 49 56 32 49 48 53 "
	       "32 49 48 51 32 57 55 32 49 49 54 32 49 48 49 32 49 49 "
	       "55 32 49 49 52 32 51 50 32 49 48 49 32 49 49 54 32 34 ");
	dprint("34 51 50 32 49 48 56 32 57 55 32 49 48 53 32 49 49 53 "
	       "32 49 49 53 32 49 48 49 32 49 50 50 32 52 53 32 49 49 "
	       "56 32 49 49 49 32 49 49 55 32 49 49 53 32 51 50 32 34 ");
	dprint("34 49 48 51 32 49 49 55 32 49 48 53 32 49 48 48 32 "
	       "49 48 49 32 49 49 52 32 52 54 32 34 41 59 ");
	dprint("114 101 116 117 114 110 32 48 59 ");
	dprint("125 ");

	dprint("");

	dprint("65 32 118 111 117 115 32 100 101 32 102 97 105 114 "
	       "101 32 108 101 115 32 99 111 112 105 101 114 45 99 "
	       "111 108 108 101 114 32 112 111 117 114 32 114 101 109 "
	       "101 116 116 114 101 32 108 101 32 116 111 117 116 32 "
	       "101 110 115 101 109 98 108 101 ");
} /* Ce crochet devrait être une accolade */
