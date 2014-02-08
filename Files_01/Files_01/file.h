/* Type des donn�es stock�es */
typedef char* typedonnee;

/* D�finition d'un objet File */
typedef struct {
	int max;     /* Nombre d'�l�ment max d'une file */
	int nb;      /* Nombre d'�l�ment dans la file   */
	int premier; /* Indice du premier element de la file */
	typedonnee *fileAtt; /* Pointeur sur le tableau representant la file */
} typeFile;

/* R�servation de memoire pour la file */
/* et initilisation de la structure    */
/* Entr�e : taille max de la file en nombre de places dans la file */
/* Resultat : pointeur sur une structure typeFile     */
typeFile *initFile (int taille);

/* Resultat : Vrai (1) si la file est vide et Faux (0) sinon */
int fileVide   (typeFile *file);

/* Resultat : Vrai (1) si la file est pleine et Faux (0) sinon */
int filePleine (typeFile *file);

/* Range l'�l�ment en fin de file */
void ajouteElem (typeFile *file, typedonnee nouveau);

/* R�sultat : El�ment rang� en premier de file */
/* L'�l�ment est enlev� de la file             */
typedonnee suppElem (typeFile *file);

/* Liberer la zone memoire allouee */
void detruireFile (typeFile *file);