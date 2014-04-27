/* Traitement d'une expression postfixÈe */
/* CrÈation d'un arbre binaire pour la reprÈsenter */
/* Impression de l'arbre sous forme infixÈe et prÈfixÈe */
/* Evaluation de l'expression ‡ partir de sa reprÈsentations */
/* sous forme d'arbre binaire */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arbre.h"
#include "pile.h"

#define TAILLEMAX 80   /* Taille d'une ligne de caractËres */
#define TAILLEPILE 50  /* Taille max d'une pile */

int main (void) {
    
	/* Declaration d'un objet pile */
	typePile *pile;
    
    // VARIABLES STD
	char expr [TAILLEMAX];
	int val;
	char *ptexpr;
    
    // VARIABLES DE L'ARBRE
	typeNoeud *feuille, *noeud, *droit, *gauche;
	typeNoeud *racine; // Pointe sur la racine de l'arbre
    
    // INIT PILE
	pile = initpile (TAILLEPILE);
    
    // POINTEUR SUR L'EXPRESSION ENTREE
	ptexpr = expr;
    
    // DEMANDE EXPRESSION A L'UTILISATEUR
	printf ("Entrer une expression postfixee\n");
	fgets (expr, TAILLEMAX, stdin);
    
    //-------------------------------------------------
    // COMMENCER LE TRAITEMENT DE L'OPERATION POSTFIXEE
    //-------------------------------------------------
    
    // SAUTER LES BLANCS DU DEBUT
	while (*ptexpr == ' ') ptexpr++;
    
    
	/* L'expression se termine sur = ou \n */
	while ( *ptexpr != '=' && *ptexpr != '\n' ) {
		if (!isdigit (*ptexpr)) {
			/* On a un operateur dans *ptexpr */
			droit = depiler(pile); /* Depiler le fils droit */    //3
			gauche = depiler(pile); /* Depiler le fils gauche */  //4
			noeud = creerNoeud (*ptexpr, gauche, droit);          //5
			empiler (pile, noeud); /* Empiler le sous arbre */    //6
			ptexpr++;
		} else {
			/* On a un operande dont la valeur est dans val */
			sscanf (ptexpr, "%d", &val);
			while (isdigit(*ptexpr)) ptexpr++; /* Sauter les digits */
			feuille = creerFeuille (val);                         //1
			empiler (pile, feuille); /* Empiler le noeud */       //2
		}
		while (*ptexpr == ' ') ptexpr++; /* Sauter les blancs */
	}
	racine = depiler(pile);  // La racine est le dernier ÈlÈment de la pile
    
	printf ("\nExpression infixee : \n");
	infixe (racine); /* Parcours infixe de l'arbre obtenu */
	printf ("\n\n");
	printf ("Expression prefixee : \n");
	prefixe (racine); /* Parcours prÈfixe de l'arbre obtenu */
	printf ("\n\n");
	printf ("Valeur de l'expression : %d\n", eval (racine));
	system ("pause");
}
