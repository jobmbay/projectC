#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membres/membre.h"
//#include "saveInFile/saveInFile.h"
//#include "authent/authent.h"


int main()
{
	membre l = creerListeMembreLC(); 
	membre m = (membre)malloc(sizeof(struct membre));
	m = creerMembreLC ('772186320','Diop', 'Mbaye', 'Malika');
	/*formation f1 = creerFormationLC('info1', 'DUT1Iformatique', 2014);
	formation f2 = creerFormationLC('info2', 'DUT2Iformatique', 2015);
	formation f3 = creerFormationLC('info3', 'DIC1 Iformatique', 2016);
	m= insererClasseLC(m, f1);
	m= insererClasseLC(m, f2);
	m= insererClasseLC(m, f3);
	l = insererMembreLC(l, m);

	printf("numero %s", m->numero);
	printf("nom %s", m->nom);
	printf("prenom %s", m->prenom);
	printf("adresse %s", m->adresse); 
	//FILE * auth = fopen(cheminauth, "a+");
	//FILE * membres = fopen(cheminmembres, "a+");*/

	return 0;
}