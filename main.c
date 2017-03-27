#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "design/design.h"
#include "membres/membre.h"
#include "saveInFile/saveInFile.h"
#include "authent/authent.h"

char * cheminAuthent = "fichiers/authentification.txt";
char * cheminMembre = "fichiers/membres.txt";

int main()
{
	membre l = creerListeMembreLC();
	membre p = creerListeMembreLC();
	membre recupereMembreFichier = creerListeMembreLC();
	membre m = creerMembreLC ("772186320","Diop", "Mbaye", "Malika");

	formation f1 = creerFormationLC("info1", "DUT1Iformatique", "2014/2015");
	formation f2 = creerFormationLC("info2", "DUT2Iformatique", "2015/2016");
	formation f3 = creerFormationLC("info3", "DIC1Iformatique", "2016/2017");

	m = insererClasseLC(m, f1);
	m = insererClasseLC(m, f2);
	m = insererClasseLC(m, f3);

	l = insererMembreLC(l, m);

	m = creerMembreLC ("773017129","Ndiaye", "Adji", "Dahra");

	f1 = creerFormationLC("info1", "DUT1Iformatique", "2014/2015");
	f2 = creerFormationLC("info2", "DUT2Iformatique", "2015/2016");
	f3 = creerFormationLC("info3", "DIC1Iformatique", "2016/2017");

	m = insererClasseLC(m, f1);
	m = insererClasseLC(m, f2);
	m = insererClasseLC(m, f3);

	l = insererMembreLC(l, m);
	p = l;

	//l = modifierMembreLC(l,"771720455");

	while(l!=NULL)
	{
		afficherMembre(l);
		l=l->suiv;
	}

	//FILE * authent = fopen(cheminAuthent, "w+");
	FILE * membres = fopen(cheminMembre, "w+");
	//FILE * chaineMembre;

	ajoutMembreFichier(p,membres);

	/*printf("recuperation membre dans le fichier : \n\n");

	recupereMembreFichier = lireMembreFichier(chaineMembre);

	while(recupereMembreFichier != NULL)
	{
		afficherMembre(recupereMembreFichier);
		recupereMembreFichier = recupereMembreFichier->suiv;
	}*/

	return 0;
}
