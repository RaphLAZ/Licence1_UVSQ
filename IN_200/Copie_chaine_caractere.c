#include <stdio.h>

void copie(char source[], char dest[])

{
	int i;

	i = 0;

	while (source[i] !='\0')
{
	dest[i] = source[i];
	i = i + 1;
}

	dest[i] ='\0';
}

int main()
{

	char chaine[128];
	char chaine2[128];

	scanf("%s",chaine);
	copie(chaine,chaine2);
	printf("la chaine de départ est :%s\n",chaine);
	printf("la chaine d’arrivée est :%s\n",chaine2);

	return 1;
}
