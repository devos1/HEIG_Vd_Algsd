#include <stdio.h>
#include <stdlib.h>
#include "arbreABR.h"
#define VRAI 1
#define FAUX 0

int niv = 0; // Niveau courant pour affichage arbre

/* Pointeur sur la fonction de comparaison de données */
/* Résultat : 0 si égalité, < 0 si d1 < d2, >0 si d1 > d2 */
int (*compDonnee)(typedonnee d1, typedonnee d2);

/* Pointeur sur la fonction d'impression des données */
void (*printDonnee) (typedonnee);

void initArbre (typeNoeud **racine) {
	*racine = NULL;
}

/* Initialise les fonctions de comparaison et d'impression */
void initFonctions (int (*cp)(typedonnee, typedonnee),
					void (*pr) (typedonnee)) {
	compDonnee = cp;
	printDonnee = pr;
}

/* Creation d'un noeud */
typeNoeud *creerNoeud (typedonnee val) {
	typeNoeud *nouveau = (typeNoeud *)malloc (sizeof (typeNoeud));
	if (nouveau != NULL) {
		nouveau->val = val;
		nouveau->droit = NULL;
		nouveau->gauche = NULL;
	}
	return nouveau;
}

/* Fonction insereNoeud qui appelle une fonction récursive */
void insereNoeud (typeNoeud **racine, typedonnee val) {
	typeNoeud *noeud = *racine;
	if (*racine == NULL) {/* sous-arbre vide ? */
		*racine = creerNoeud(val);
	} else if (compDonnee (val, noeud->val) < 0) {
		insereNoeud (&(noeud->gauche), val); // Insérer dans sous-arbre gauche
	} else {
		insereNoeud (&(noeud->droit), val);  // Insérer dans sous-arbre droit
	}
}

/* Fonction insèreNoeud sous forme itérative */
/* Résultat : nombre de recherche et <0 si valeur trouvée */
void insereNoeudIteratif (typeNoeud **racine, typedonnee val) {
	typeNoeud *courant, *parent, *nouveau;
	int cmp;  // Résultat de comparaison

	nouveau = creerNoeud(val);
	if (*racine == NULL) /* C'est le premier noeud */
		*racine = nouveau;
	else {
		// La recherche commence par la racine
		courant = *racine;
		while (courant != NULL) {
			parent = courant;
			cmp = compDonnee (val, courant->val);
			if (cmp < 0) {
				// On descend à gauche
				courant = courant->gauche;
			} else {
				// Sinon on va a droite
				courant = courant->droit;
			}
		}
		if (cmp < 0) {
			// Insertion à gauche
			parent->gauche = nouveau;
		} else {
			// Insertion à droite
			parent->droit = nouveau;
		}
	}
}

/* Detruire le noeud dont la valeur est val */
/* Résultat : FAUX si la valeur n'est pas dans l'arbre */
int detruireNoeud (typeNoeud **racine, typedonnee val) {
	typeNoeud *noeud, *pere;
	int res = FAUX;
	int cmp;

	if (*racine != NULL) {
		noeud = *racine;
		cmp = compDonnee (val, noeud->val);
		if ( cmp < 0) {
			detruireNoeud (&noeud->gauche, val);
		} else if (cmp > 0) {
			detruireNoeud (&noeud->droit, val);
		} else {
			res = VRAI;
			// On a trouve le noeud a detruire 
			if (noeud->gauche == NULL) { // Il n'a pas de fils gauche
				*racine = noeud->droit;
			} else if (noeud->droit == NULL) {// Il n'a pas de fils droit
				*racine = noeud->gauche;
			} else {
				// On va chercher le + grand noeud dans le sous arbre de gauche
				noeud = noeud->gauche;
				if (noeud->droit == NULL) {
					(*racine)->gauche = noeud->gauche;
				} else {
					while (noeud->droit != NULL) {
						pere = noeud;
						noeud = noeud->droit;
					}
					// noeud : pointeur sur la + grande valeur
					// fils gauche devient fils droit du père
					pere->droit = noeud->gauche;
				}
				// Recopier la valeur dans le noeud à détruire
				(*racine)->val = noeud->val;

			}
			free(noeud);
		}
	}
	return res;
}

void parcoursInfixe (typeNoeud *noeud) {
	if (noeud != NULL) {
		if (noeud->droit == NULL && noeud->gauche == NULL) {
			// On a une feuille
			printDonnee (noeud->val);
		} else {
			printf ("(");
			if (noeud->gauche == NULL) {
				printf (" - "); // Pas de sous arbre gauche
			} else{
				parcoursInfixe (noeud->gauche);
			}
			printDonnee (noeud->val); // Imprime le noeud
			if (noeud->droit == NULL) {
				printf (" - "); // Pas de sous arbre droit
			} else {
				parcoursInfixe (noeud->droit);
			}
			printf (")");
		}
	}
}


/* Imprime l'arbre sous forme arborescente */
void parcoursPrefixe (typeNoeud *noeud) {
	int i;
	niv++;
	if (noeud != NULL) {
		for (i = 1 ; i < niv ; i++) {
			printf ("---");
		}
		printDonnee (noeud->val); // Imprime le noeud
		if (noeud->gauche != NULL) {
			printf ("\ng");
			parcoursPrefixe (noeud->gauche);
		}
		if (noeud->droit != NULL) {
			printf ("\nd");
			parcoursPrefixe (noeud->droit);
		}
	}
	niv--;
}

/* Recherche de la plus petite valeur de l'arbre */
typedonnee valMin (typeNoeud *racine) {
	typeNoeud *noeud;
	typedonnee res;

	noeud = racine;
	/* Si l'arbre est vide */
	if (noeud == NULL) {
		res = 0;
	} else {
		while (noeud->gauche != NULL) {
			noeud = noeud->gauche;
		}
		res = noeud->val;
	}
	return res;
}


/* Recherche la plus grande valeur de l'arbre */
typedonnee valMax (typeNoeud *racine) {
	typeNoeud *noeud = racine;
	typedonnee res;

	if (noeud == NULL) {
		res = 0;
	} else {
		while (noeud->droit != NULL) {
			noeud = noeud->droit;
		}
		res = noeud->val;
	}
	return res;
}

// prof : pointeur sur une variable initialisée à 0
void hautArbre (typeNoeud *racine, int *prof) {
	if (racine != NULL) {
		niv++;
		if (niv > *prof) {
			*prof = niv;
		}
		hautArbre (racine->gauche, prof);
		hautArbre (racine->droit, prof);
		niv--;
	}
}

/* Calcul du nombre de noeuds */
int nbNoeud (typeNoeud *racine) {
	int res = 0;
	if (racine != NULL) {
		res = 1 + nbNoeud(racine->gauche) + nbNoeud(racine->droit);
	}
	return res;
}



