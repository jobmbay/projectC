#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct formation
{
	char * code;
	char * intitule;
	char * annee;	
	struct formation * suiv;
} * formation;

typedef struct membre
{
	char *numero;
	char *nom;
	char *prenom;
	char *adresse;
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
membre insererClasseLC(membre m, formation f)
{
    if(m->classe!=NULL)
    {
        formation tete = m->classe;
        while(tete->suiv != NULL){
            tete = tete->suiv;
        }
        tete->suiv = f;
    }
    else
    {
        m->classe=f;
    }
    
    return m;
}

//creer une nouvelle formation
formation creerFormationLC (char * code, char * intitule, char * annee)
{
    formation f =(formation)malloc(sizeof(struct formation));
    f->code = code;
    f->intitule = intitule;
    f->annee = annee;
    f->suiv = NULL;
    return f;
}

//creer un nouveau membre
membre creerMembreLC (char * numero, char * nom, char * prenom, char * adresse)
{
    membre m = (membre)malloc(sizeof(struct membre));
    m->numero=numero;
    m->nom = nom;
    m->prenom=prenom;
    m->adresse = adresse;
    m->nombreClasse = 0;
    m->classe=NULL;
    m->suiv=NULL;
    return m;
}

//rechercher membre
membre rechercherMembreLC(membre mb, char *numero)
{
    membre m=mb;
    if(m!=NULL)
    {
        while(m!=NULL)
        {
            if(strcmp(m->numero,numero)==0)
            {
                return m;
            }
            m=m->suiv;
        }
    }
    return NULL;
}

//modifier membre
membre modifierMembreLC(membre mb, char *numero)
{
    membre m=mb;
    if(m!=NULL)
    {
        while(m!=NULL)
        {
            if(strcmp(m->numero,numero)==0)
            {
                int nb;
                char chaine[10];
                do
                {
                    printf("Choisir le champ de modification\n");
                    printf("1 - Nom\n");
                    printf("2 - Prenom\n");
                    printf("3 - Adresse\n");
                    printf("4 - Annuler\n");
                    scanf("%d",&nb);
                }
                while(nb<=0 || nb >4);
                switch (nb) {
                    case 1: printf("Entrer le nouveau nom\n");
                        scanf("%s",chaine);
                        m->nom=chaine;
                        return m;
                        break;
                    case 2: printf("Entrer le nouveau prenom\n");
                        scanf("%s",m->prenom);
                        return m;
                        break;
                    case 3: printf("Entrer le nouveau adresse\n");
                        scanf("%s",m->adresse);
                        return m;
                        break;
                    case 4: return m;
                        break;
                    default : printf("Pas de modification\n");
                        break;
                        
                }
                return m;
            }
            m=m->suiv;
        }
    }
    return NULL;
}

//supprimer membre
membre supprimerMembreLC(membre mb, char *numero)
{
    membre m=mb;
    if(m!=NULL)
    {
        if(strcmp(m->numero,numero)==0)
        {
            mb= m->suiv;
            return mb;
        }
        while(m->suiv!=NULL)
        {
            if(m->suiv->suiv!=NULL)
            {
                if(strcmp(m->suiv->numero,numero)==0)
                {
                    printf("1\n");
                    m->suiv= m->suiv->suiv;
                    return mb;
                }
            }
            else
            {
                if(strcmp(m->suiv->numero,numero)==0)
                {
                    printf("2\n");
                    m->suiv=NULL;
                    return mb;
                }
            }
            m=m->suiv;
        }
        
    }
    return mb;
}
//inserer un membre dans la liste
membre insererMembreLC(membre l, membre m)
{
    if(l!=NULL)
    {
        membre tete = l;
        while(tete->suiv != NULL)
            tete = tete->suiv;
        tete->suiv = m;
        m->suiv = NULL;
    }
    else
    {
        l=m;
    }
    return l;
}

//afficher formation
void afficherFormation(formation f){
    formation form = (formation)malloc(sizeof(struct formation));
    form = f;
    if (form != NULL)
    {
        while(form != NULL){
            printf("Code Formation :  %s\n",form->code );
            printf("\n");
            printf("Intitule Formation :  %s\n",form->intitule );
            printf("\n");
            printf("Année Formation :  %s\n",form->annee );
            printf("\n");
            form = form->suiv;
        }
    }
}

//afficher un membre 
void afficherMembre(membre mb){
    
    membre tmp = (membre)malloc(sizeof(struct membre)*1000);
    tmp = mb;
    printf("\n");
    printf("------------------------------------\n");
    printf("Code membre : %s \n", tmp->numero );
    printf("------------------------------------\n");
    if (tmp != NULL)
    {
        printf("\n");
        printf("Nom :  %s\n", tmp->nom);
        printf("\n");
        printf("Prenom :  %s\n", tmp->prenom);
        printf("\n");
        printf("Adresse :  %s\n", tmp->adresse);
        printf("\n");
        afficherFormation(tmp->classe);
        printf("--------------------------------\n");
        printf("\n");
    }
    
}
