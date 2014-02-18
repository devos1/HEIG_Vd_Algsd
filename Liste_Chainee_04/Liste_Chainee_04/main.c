//
//  main.c
//  Liste_Chainee_04
//
//  Created by Oscar on 18.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

/*
 * Pile exercice 1
 * Utilisation d'une pile pour empiler des valeurs entières
 * et pour les restituer dans l'ordre inverse
 */

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

#define LGL 80   /* Taille d'une ligne de caractËres */

int saisie ();

int main () {
	/* Declaration d'un objet pile */
	typePile *pile;
	typeDonnee valeur;
    
	pile = initpile (); /* Initialiser la pile */
    
	valeur = saisie ();
	/* Tant que la valeur saisie n'est pas 0 */
	/* et que la pile n'est pas pleine       */
	while ( valeur != 0 ) {
		if (!pilepleine (pile)) {
			empiler (&pile, valeur);      /* Empiler l'ÈlÈment */
		} else {
			puts ("La pile est pleine");
		}
		valeur = saisie ();
	}
	/* Tant qu'il reste un ÈlÈment dans la pile*/
	while (!pilevide (pile)) {
		valeur = depiler(&pile);      /* DÈpiler l'ÈlÈment */
		printf ("%d\n", valeur);
	}

	detruirePile (&pile);

    return 0;
}

/* Saisie une valeur entiËre */
int saisie () {
	int valeur, n ;
	char ligne [LGL];
    
	printf ("Entrer une valeur : ");
	fgets (ligne, LGL, stdin);
	n = sscanf (ligne,"%d", &valeur);
	while (n != 1) {
		printf ("Erreur entrer une valeur entiere : ");
		fgets (ligne, LGL, stdin);
		n = sscanf (ligne, "%d", &valeur);
	}
	return valeur;
}

