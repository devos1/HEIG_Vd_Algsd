//
//  pile.h
//  Liste_Chainee_04
//
//  Created by Oscar on 18.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//



#include "liste.h"

/* DÈfinition d'un objet descripteur de pile */
typedef typeElt typePile;


/* Resultat : pointeur sur une structure typePile     */
typePile *initpile ();

/* Resultat : Vrai (1) si la pile est vide et Faux (0) sinon */
int pilevide   (typePile *pile);

/* Resultat : Vrai (1) si la pile est pleine et Faux (0) sinon */
int pilepleine (typePile *pile);

/* Range la valeur en sommet de pile */
void empiler   (typePile **sommet, typeDonnee valeur);

/* Resultat : valeur rangÈe en sommet de pile */
/* La valeur est enlevÈe de la pile           */
typeDonnee depiler (typePile **pile);

// LibÈrer la mÈmoire si la pile n'est pas vide */
void detruirePile (typePile **sommet);