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
	/*membre l = creerListeMembreLC();
    membre p = creerListeMembreLC();
    //membre recupereMembreFichier = creerListeMembreLC();
    membre m = creerMembreLC ("772186320","Diop", "Mbaye", "Malika");
    
    formation f1 = NULL,f2 = NULL,f3 = NULL;
    f1 = creerFormationLC("info1", "DUT1Iformatique", "2014/2015");
    f2 = creerFormationLC("info2", "DUT2Iformatique", "2015/2016");
    f3 = creerFormationLC("info3", "DIC1Iformatique", "2016/2017");
    
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
    
    m = creerMembreLC ("771720455","Ndiaye", "kuko", "Mbour");
    
    f1 = creerFormationLC("info1", "DUT1Iformatique", "2014/2015");
    f2 = creerFormationLC("info2", "DUT2Iformatique", "2015/2016");
    f3 = creerFormationLC("info3", "DIC1Iformatique", "2016/2017");
    
    m = insererClasseLC(m, f1);
    m = insererClasseLC(m, f2);
    m = insererClasseLC(m, f3);
    
    l = insererMembreLC(l, m);
    
    p = l;
    
    
    l = modifierMembreLC(l,"771720455");
    //l = supprimerMembreLC(l, "771720455");
    
    while(l != NULL)
    {
        afficherMembre(l);
        l=l->suiv;
    }*/
    
    /*FILE * membres = fopen(cheminTextMembre, "w+");
    FILE * chaineMembre;
    membre recupereMembreFichier;
    
    ajoutMembreFichier(p,membres);
    
    printf("recuperation membre dans le fichier : \n\n");
     
    recupereMembreFichier = lireMembreFichier(chaineMembre);
     
     while(recupereMembreFichier != NULL)
     {
         afficherMembre(recupereMembreFichier);
         recupereMembreFichier = recupereMembreFichier->suiv;
     }*/
    
    //inscription(1, "ndiaye", "souaibou", "souaibou94@live.fr", "passer");
    /*inscription(2, "diop", "mbaye", "jobmbay@gmail.com", "passer");
     */
    /*utilisateur u ;
    u = deserializeUtilisateur("1:ndiaye:souaibou:souaibou94@live.fr:passer");
    */
    /*_Bool trouve = verifierLoginMdp("souaibou94@live.fr", "passer");
    
    printf("trouver : %d \n",trouve );*/
    
    
    
    return 0;

}
