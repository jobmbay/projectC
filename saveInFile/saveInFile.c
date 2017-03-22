#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille_max 100000

char * cheminMembre = "fichiers/membres.txt";

char * serialize(membre mb){

	char * chaine = (char *)malloc(sizeof(char) * 10);

	strcat(chaine,mb->numero);
	strcat(chaine,":");
	strcat(chaine,mb->nom);
	strcat(chaine,":");
	strcat(chaine,mb->prenom);
	strcat(chaine,":");
	strcat(chaine,mb->adresse);
	while(mb->classe != NULL){

		strcat(chaine,":");
		strcat(chaine,mb->classe->code);
		strcat(chaine,":");
		strcat(chaine,mb->classe->intitule);
		strcat(chaine,":");
		strcat(chaine,mb->classe->annee);

		mb->classe = mb->classe->suiv;
	}

	return chaine;
}

void deserialize(char * chaine){

	membre mb = creerListeMembreLC();
	int i,k=0;
	char * tab[taille_max] = "";
	char * str = malloc(strlen(chaine)+1);
	
	for (i = 0; i < strlen(chaine); ++i)
	{
		strcat(str,chaine[i]);
		if (strcmp(chaine[i],":") == 0)
		{
			continue;
		}
		tab[k] = str;
		k++;
		str = "";
	}
	int j;
	for (int j = 0; j < strlen(chaine); ++j)
	{
		printf("%s \n", tab[i]);
	}
}

/*
* fonction : ajoutMembreFichier() >> permet d'ajouter un membre dans le fichier membre
* param : structure membre et le fichier 
* return : void
*/
void ajoutMembreFichier(membre mb, FILE * fichier){

	membre tmp;
	tmp = mb;
	if (mb != NULL)
	{
		while(tmp != NULL){
			char *str2 = serialize(tmp);
			char *str = malloc(strlen(str2) + 1);
			str = str2;
			if (fichier != NULL )	
			{
				fputs(str , fichier);
			}else{
				printf("Erreur d'ouverture \n");
				exit(0);
			}
			str2 = "";
			tmp = tmp->suiv;
		}
	}
	fclose(fichier);
}

/*
* fonction : lireMembreFichier() >> lire les données du fichier et le mettre dans une liste chainée  
* param : le fichier 
* return : une chaine
*/
char * lireMembreFichier(FILE * fichier){
	fichier = fopen(cheminMembre, "r");
	char chaine[taille_max] = "";
	if (fichier == NULL )
	{
		printf("Erreur d'ouverture du fichier \n");
		exit(0);
	}
	if (fichier != NULL)
	{
		fgets(chaine,taille_max, fichier);
	}
	fclose(fichier);

	return chaine;
}
