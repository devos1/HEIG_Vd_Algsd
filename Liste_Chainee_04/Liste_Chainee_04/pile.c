//
//  pile.c
//  Liste_Chainee_04
//
//  Created by Oscar on 18.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdlib.h>
#include "pile.h"

/* =1 Si allocation mémoire impossible */
int memoirePleine = 0;

/* Resultat : pointeur sur une structure typePile     */
typePile *initpile (){
    typePile *sommet;
    initListe(&sommet);
    return sommet;
}

/* Resultat : Vrai (1) si la pile est vide et Faux (0) sinon */
int pilevide   (typePile *sommet){
    return  (sommet == NULL);
}

/* Resultat : Vrai (1) si la pile est pleine et Faux (0) sinon */
int pilepleine (typePile *pile){
    return memoirePleine;
}

/* Range la valeur en sommet de pile */
void empiler   (typePile **sommet, typeDonnee valeur){
    typeElt *nouveau;
    
    nouveau = creerElt(valeur);

	if (nouveau != NULL) {
		insereElt (sommet, NULL, nouveau);
	} else {
		memoirePleine = 1;
	}
}

/* Resultat : valeur rangÈe en sommet de pile */
/* La valeur est enlevÈe de la pile           */
typeDonnee depiler    (typePile **sommet){
    typeDonnee val;
    val = valElt(*sommet);
    detruireElt(sommet, NULL);
    memoirePleine = 0;
    return val;
}

// LibÈrer la mÈmoire si la pile n'est pas vide */
void detruirePile (typePile **sommet){
    while (*sommet != NULL) {
        detruireElt(sommet, NULL);
    }
}