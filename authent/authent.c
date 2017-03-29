#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

_Bool verifierLoginMdp(char* login,char* mdp){
    FILE* fichierlogin = NULL ;
    _Bool trouve = false;
    char* loginfound = malloc(40*sizeof(char));
    char* mdpfound = malloc(40*sizeof(char));
    // Adapation des informations reçues
    // On convertit le login et le mot de passe au format du fichier
    strcpy(mdpfound,login);
    strcat(mdpfound, ":");
    strcat(mdpfound,mdp);
    // On ouvre le fichier
    fichierlogin = fopen(cheminAuthent, "r");
    if (fichierlogin == NULL) {
        // On arrete le prggramme car il y a erreur d'ouverture
        printf("Erreur Ouverture");
        return false ;
    }
    while (!feof(fichierlogin) && trouve == false) {
        // On parcourt chaque ligne
        fscanf(fichierlogin,"%s\n",loginfound);
        utilisateur u = deserializeUtilisateur(loginfound);
        
        // On compare chaque ligne a la combinaison entree
        if(strcmp(u->login, login)==0 && strcmp(u->mdp, mdp)==0) trouve = true;
    }
    // On ferme le fichier et on libere les pointeurs
    fclose(fichierlogin);
    free(loginfound);
    free(mdpfound);
    // retourne vrai si combinaison trouvée sinon faux
    return trouve;
}

void inscription(int id, char * nom , char * prenom , char * login, char * mdp){
    
    FILE * fichier = fopen(cheminAuthent, "a+");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier");
        exit(0);
    }
    if (fichier != NULL) {
        fprintf(fichier, "%d:%s:%s:%s:%s \n",id,nom,prenom,login,mdp);
        printf("inscription reussi \n");
    }

    fclose(fichier);
    
}


utilisateur deserializeUtilisateur(char * chaine){
    utilisateur u = (utilisateur)malloc(sizeof(struct utilisateur));
    u->identifiant = (char *) malloc(sizeof(char)*50);
    u->nom = (char *) malloc(sizeof(char)*50);
    u->prenom = (char *) malloc(sizeof(char)*50);
    u->login = (char *) malloc(sizeof(char)*50);
    u->mdp = (char *) malloc(sizeof(char)*50);
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
    strcpy(u->identifiant,tab[0]);
    strcpy(u->nom,tab[1]);
    strcpy(u->prenom,tab[2]);
    strcpy(u->login,tab[3]);
    strcpy(u->mdp,tab[4]);
    u->suiv = NULL;
    return u;
}