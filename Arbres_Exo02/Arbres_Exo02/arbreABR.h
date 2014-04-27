/* Fichier arbreABR.h */

typedef int typedonnee; // type des donn�es

/*----------Ne rien modifier en dessous -------------------*/

/* D�finition d'un noeud */
typedef struct n {
  typedonnee val;
  struct n *gauche;
  struct n *droit;
} typeNoeud;

/* Initialise la racine de l'arbre */
void initArbre (typeNoeud **racine);

/* Initialise les fonctions de comparaison et d'impression */
/* R�sultat cp : 0 si d1=d2, <0 si d1 < d2 et >0 si d1 > d2 */
void initFonctions (int (*cp)(typedonnee d1, typedonnee d2),
					void (*pr) (typedonnee));

/* Introduit un nouveau noeud dans l'arbre */
/* Racine : adresse du pointeur sur la racine de l'arbre */
/* val : Valeur du noeud qui doit �tre cr�� et ins�r�    */
void insereNoeud (typeNoeud **racine, typedonnee val);

/* D�truit le noeud dont la valeur est val */
/* R�sultat vrai si val trouv� et faux sinon */
int detruireNoeud (typeNoeud **racine, typedonnee val);

/* Imprime l'arbre parenthese */
void parcoursInfixe (typeNoeud *racine);

/* Imprime l'arborescence en pr�fix� */
void parcoursPrefixe (typeNoeud *racine);

/* Recherche la plus petite valeur de l'arbre */
typedonnee valMin (typeNoeud *racine);

/* Recherche la plus grande valeur de l'arbre */
typedonnee valMax (typeNoeud *racine);

/* Calcul de la hauteur de l'arbre binaire */
void hautArbre (typeNoeud *racine, int *prof);

/* Calcul du nombre de noeuds */
int nbNoeud (typeNoeud *racine);