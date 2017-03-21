#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct formation
{
	char * code;
	char * intitule;
	int annee;	
} * formation;

typedef struct membre
{
	char * numero;
	char * nom;
	char * prenom;
	char * adresse;
	int nombreClasse;
	formation classe;
	struct membre * suiv;
} * membre;


 //cette fonction nous permet de creer une liste vide des membres
membre creerListeMembreLC(){
	membre l = (membre)malloc(sizeof(struct membre));
	l = NULL;
	return l;
}

//insertion d'une classe de formation pour un mebmre
/*membre insererClasseLC(membre m, formation f)
{
	m->classe[m->nombreClasse]=f;
	m->nombreClasse++;
	return m;
	//for(i=0;i<m.nombreClasse;i++)
}

//creer une nouvelle formation
membre creerFormationLC (char * code, char * intitule, int annee)
{
	formation f;
	f->code = code;
	f->intitule = intitule;
	f->annee = annee;
	return f;
}
*/
//creer un nouveau membre
membre creerMembreLC (char * numero, char * nom, char * prenom, char * adresse)
{	
	membre m = (membre)malloc(sizeof(struct membre));
	m->numero=numero;
	m->nom=nom;
	m->prenom=prenom;
	m->adresse = adresse;
	m->nombreClasse = 0;
	m->suiv=NULL;
	printf("gggggbbbbbb %s\n",m->n);
	return m;
}
/*
//inserer un membre dans la liste
membre insererMembreLC(membre l, membre m)
{
	membre tete = l;
	while(tete->suiv != NULL)
		tete = tete->suiv;
	tete->suiv = m;
        m->suiv = NULL;
	return l;
}*/