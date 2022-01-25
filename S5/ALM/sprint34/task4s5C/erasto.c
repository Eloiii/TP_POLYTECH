#define N 30

// --------------------------------------------
// void affectab (char *tab, int i, int val)
// Affecte au n ieme element de tab la valeur val
// --------------------------------------------
void affecttab(char *tab, int i, int val)
{
    *(tab+i)= val;
}

// --------------------------------------------
// Effectue le crible d'Erastothene à l'aide d'un tableau à N elements
// --------------------------------------------
int main()
{
char tab[N];
int i, j;

for (i=0; i<N; i++)
affecttab(tab,i,1);
    
i=2;
while (i<N)
{
	if(tab[i])
	{
	j=i*2;
	while (j<N)
		{
		affecttab(tab,j,0);
		j=j+i;
		}
		}
	i++;
}		
}

