#include "saveInFile.c"


char * serialize(membre mb);
void ajoutMembreFichier(membre mb , FILE * fichier);
membre lireMembreFichier(FILE * fichier);
membre deserialize(char * chaine);
