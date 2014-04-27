#include <stdio.h>
#include <stdlib.h>
#include "arbreABR.h"
#define _CRT_SECURE_NO_DEPRECATE

/* Comparaison des donnÈes                          */
/* RÈsultat : 0 si v1 = v2,                         */
/*            <0 si v1 < v2                         */
/*            >0 si v1 > v2                          */
int compareData (typedonnee v1, typedonnee v2);

/* Fonction ‡ Ècrire dans le module application     */
/* Impression de la donnÈe stockÈe dans le noeud    */
void printData (typedonnee v);

// Utile pour compter tous les noeuds
int compteNoeud (typedonnee v);

// Utile pour compter tous les noeuds avec des valeurs paires
int compteNoeudPair (typedonnee v);

/* Saisie une valeur entiËre au clavier */
int saisieEntier ();

int main () {
	int cde;
	typedonnee val;
	typeNoeud *racine;
	int haut;
    
	/* Initialisation de l'arbre binaire */
	initArbre (&racine);
	initFonctions (compareData, printData);
	printf ("1 pour inserer, 2 pour enlever, 3 pour imprimer, 0 pour sortir : ");
	cde = saisieEntier();
	while (cde != 0) {
		switch (cde) {
            case 1:
                printf ("Valeur a inserer : ");
                val = saisieEntier ();
                insereNoeud (&racine, val);
                break;
            case 2:
                printf ("Valeur a enlever : ");
                val = saisieEntier ();
                if (detruireNoeud (&racine, val) != 0) {
                    printf ("Valeur enlevee\n");
                } else {
                    printf ("Valeur pas trouvee\n");
                }
                break;
            case 3:
                puts ("\n\nArbre sous forme parenthesee");
                parcoursInfixe (racine);
                puts ("\n\nArbre sous forme arborescente");
                parcoursPrefixe (racine);
                puts ("");
                haut = 0; // Indispensable pour appler hautArbre
                hautArbre (racine, &haut);
                printf ("Hauteur de l'arbre : %d\n", haut);
                printf ("Nombre de noeuds : %d\n", nbNoeud(racine));
                break;
            case 4:
//                printf ("Min : %d, Max : %d\n", valMin (racine),
//                        valMax (racine));
//                printf ("Nonbre de noeuds : %d\n", nbNoeud (racine, compteNoeud));
//                printf ("Nonbre de noeuds pairs : %d\n", nbNoeud (racine, compteNoeudPair));
                puts ("");
                break;
            default:
                printf ("Erreur\n");
		}
		printf ("1 pour inserer, 2 pour enlever, 3 pour imprimer, 0 pour sortir : ");
		cde = saisieEntier ();
	}
	printf ("\nLa plus petite valeur est %d\n", valMin (racine));
	system ("pause");
}

/* Saisie une valeur entiere au clavier */
int saisieEntier () {
	int n, val;
	char ligne [100];
    
	fgets (ligne, 100, stdin);
	n = sscanf (ligne, "%d", &val);
	while (n == 0) {
		printf ("Entrer une valeur entiËre : ");
		fgets (ligne, 100, stdin);
		n = sscanf (ligne, "%d", &val);
	}
	return (val);
}

/* Comparaison des donnÈes stockÈes dans les noeuds */
/* RÈsultat : 0 si v1 = v2,                         */
/*            <0 si v1 < v2                         */
/*            >0 si v1 > v2                          */
int compareData (typedonnee v1, typedonnee v2) {
	return v1 - v2;
}

/* Fonction ‡ Ècrire dans le module application     */
/* Impression de la donnÈe stockÈe dans le noeud    */
void printData (typedonnee v) {
	printf ("%3d ", v);
}

// Utile pour compter tous les noeuds
int compteNoeud (typedonnee v) {
	return 1;
}

// Utile pour compter tous les noeuds avec des valeurs paires
int compteNoeudPair (typedonnee v) {
	return (v+1) % 2;
}