#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

_Bool checklogin(char* login,char* password){
    FILE* fichierlogin = NULL ;
    _Bool trouve = false;
    char* loginfound = malloc(40*sizeof(char));
    char* passwordfound = malloc(40*sizeof(char));
   // Adapation des informations reçues
    // On convertit le login et le mot de passe au format du fichier
    strcpy(passwordfound,login);
    strcat(passwordfound, ":");
    strcat(passwordfound,password);
    // On ouvre le fichier 
    fichierlogin = fopen("../fichiers/authentification.txt", "r");
    if (fichierlogin == NULL) {
        // On arrete le prggramme car il y a erreur d'ouverture
        printf("Erreur Ouverture");
        return false ;
    }
    while (!feof(fichierlogin) && trouve == false) {
        // On parcourt chaque ligne
        fscanf(fichierlogin,"%s\n",loginfound);
        // On compare chaque ligne a la combinaison entree
        if(strcmp(loginfound, passwordfound)==0) trouve = true;
    }
    // On ferme le fichier et on libere les pointeurs
    fclose(fichierlogin);
    free(loginfound);
    free(passwordfound);
    // retourne vrai si combinaison trouvée sinon faux
    return trouve;
}

void inscription(FILE * fichier){

}
