#include "membre.c"

formation creerFormationLC (char * code, char * intitule, int annee);
membre creerListeMembreLC();
membre insererClasseLC(membre m, formation f);
membre creerMembreLC (char * numero, char * nom, char * prenom, char * adresse);
membre rechercherMembreLC(membre mb, char * numero);
membre insererMembreLC(membre l, membre m);
membre supprimerMembreLC(membre mb, char *numero);
membre modifierMembreLC(membre mb, char *numero);