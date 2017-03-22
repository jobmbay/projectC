#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membres/membre.h"
//#include "saveInFile/saveInFile.h"
//#include "authent/authent.h"


int main()
{
	membre l = creerListeMembreLC(); 
	membre m = creerMembreLC ("772186320","Diop", "Mbaye", "Malika");
	formation f1 = creerFormationLC("info1", "DUT1Iformatique", 2014);
	formation f2 = creerFormationLC("info2", "DUT2Iformatique", 2015);
	formation f3 = creerFormationLC("info3", "DIC1 Iformatique", 2016);
	m= insererClasseLC(m, f1);
	m= insererClasseLC(m, f2);
	m= insererClasseLC(m, f3);
	l = insererMembreLC(l, m);
	m = creerMembreLC ("771720455","Ndiaye", "Souaibou", "Mbour");
	f1 = creerFormationLC("info1", "DUT1Iformatique", 2014);
	f2 = creerFormationLC("info2", "DUT2Iformatique", 2015);
	f3 = creerFormationLC("info3", "DIC1 Iformatique", 2016);
	m= insererClasseLC(m, f1);
	m= insererClasseLC(m, f2);
	m= insererClasseLC(m, f3);
	l = insererMembreLC(l, m);

	l = modifierMembreLC(l,"771720455");

	while(l!=NULL)
	{
		printf("numero %s", l->numero);
		printf("nom %s", l->nom);
		printf("prenom %s", l->prenom);
		printf("adresse %s", l->adresse);
		l=l->suiv;
	}
	/*//FILE * auth = fopen(cheminauth, "a+");
	//FILE * membres = fopen(cheminmembres, "a+");*/ 
	return 0;
}