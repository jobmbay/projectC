#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
			strcpy(str,str2);
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
* param : structure membre et le fichier 
* return : la liste
*/
membre lireMembreFichier(FILE * fichier){
	return NULL;
}
