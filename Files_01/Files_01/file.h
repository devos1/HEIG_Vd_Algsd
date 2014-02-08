/* Type des données stockées */
typedef char* typedonnee;

/* Définition d'un objet File */
typedef struct {
	int max;     /* Nombre d'élément max d'une file */
	int nb;      /* Nombre d'élément dans la file   */
	int premier; /* Indice du premier element de la file */
	typedonnee *fileAtt; /* Pointeur sur le tableau representant la file */
} typeFile;

/* Réservation de memoire pour la file */
/* et initilisation de la structure    */
/* Entrée : taille max de la file en nombre de places dans la file */
/* Resultat : pointeur sur une structure typeFile     */
typeFile *initFile (int taille);

/* Resultat : Vrai (1) si la file est vide et Faux (0) sinon */
int fileVide   (typeFile *file);

/* Resultat : Vrai (1) si la file est pleine et Faux (0) sinon */
int filePleine (typeFile *file);

/* Range l'élément en fin de file */
void ajouteElem (typeFile *file, typedonnee nouveau);

/* Résultat : Elément rangé en premier de file */
/* L'élément est enlevé de la file             */
typedonnee suppElem (typeFile *file);

/* Liberer la zone memoire allouee */
void detruireFile (typeFile *file);