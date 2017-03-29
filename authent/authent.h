#include "authent.c"

typedef struct utilisateur {
    char * identifiant;
    char * nom;
    char * prenom;
    char * login;
    char * mdp;
    struct utilisateur * suiv;
} * utilisateur;

_Bool verifierLoginMdp(char* login,char* mdp);
void inscription(int id,char * nom , char * prenom , char * login, char * mdp);
char** str_split(char* a_str, const char a_delim);
utilisateur deserializeUtilisateur(char * chaine);

