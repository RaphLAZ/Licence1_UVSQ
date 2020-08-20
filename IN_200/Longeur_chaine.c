#include <stdio.h>

int Longueur(char chaine[])
{
	int longueur = 0;
	char caractere;
	
	caractere = chaine[0];
	while (caractere !='\0')
	{
	longueur = longueur + 1;
	caractere= chaine[longueur];
	}
	return longueur;
}


int main()
{

	char chaine[128];
	scanf("%s",chaine);
	printf("la longueur de chaine est :%d\n",Longueur(chaine));

	return 1;
}
