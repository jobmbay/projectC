#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille_max 100000


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


membre deserialize(char * chaine){
    membre m = (membre)malloc(sizeof(struct membre));
    m->nom = (char *) malloc(sizeof(char)*50);
    m->prenom = (char *) malloc(sizeof(char)*50);
    m->adresse = (char *) malloc(sizeof(char)*50);
    m->numero = (char *) malloc(sizeof(char)*50);
    int i,k=0,j;
    char * tab[1000];
    char caractere[2];
    char str[1000];
    str[0] = 0;
    caractere[1]='\0';
    int compte = 0;
    for (i = 0; i <= (strlen(chaine)); i++)
    {
        if (chaine[i] == ':') {
            compte ++;
            tab[k] = (char *) malloc(sizeof(str) +1);
            strcpy(tab[k],str);
            for(j =0 ; j<strlen(str); j++)
                str[j] = 0;
            k++;
        } else {
            caractere[0] = chaine[i];
            strcat(str,caractere);
            caractere[0] = 0;
            if(i == strlen(chaine)) {
                tab[k] = (char *) malloc(sizeof(str) +1);
                strcpy(tab[k],str);
            }
        }
    }
    strcpy(m->numero,tab[0]);
    strcpy(m->nom,tab[1]);
    strcpy(m->prenom,tab[2]);
    strcpy(m->adresse,tab[3]);
    j=4;
    while (j<k)
    {
        formation f = (formation)malloc(sizeof(struct formation));
        f= creerFormationLC(tab[j],tab[j+1],tab[j+2]);
        m=insererClasseLC(m,f);
        j=j+3;
    }
    m->suiv = NULL;
    return m;
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
            char *str = (char*)malloc(strlen(str2) + 1);
            str = str2;
            if (fichier != NULL )
            {
                fprintf(fichier, "%s \n", str2);
                printf("insert successful \n");
            }else{
                printf("Erreur d'ouverture du fichier \n");
                exit(0);
            }
            str2 = "";
            tmp = tmp->suiv;
            fclose(fichier);
        }
    }
}

/*
 * fonction : lireMembreFichier() >> lire les données du fichier et le mettre dans une liste chainée
 * param : le fichier
 * return : une chaine
 */
membre lireMembreFichier(FILE * fichier){
	
    membre liste = creerListeMembreLC();
    if (fichier == NULL )
    {
        printf("Erreur d'ouverture du fichier \n");
        exit(0);
    }
    while(!feof(fichier)){
        char chaine[taille_max];
        fgets(chaine,taille_max, fichier);
        if(strlen(chaine) != 0) {
            membre m = (membre)malloc(sizeof(struct membre));
            m = deserialize(chaine);
            liste = insererMembreLC(liste,m);		
        }
    }
    fclose(fichier);
    
    return liste;
}
