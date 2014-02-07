//
//  liste.c
//  Liste_Chainee_01
//
//  Created by Oscar da Silva on 07.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

// Initialise la liste : pas d'éléments
void initListe (typeElt **ptPrem) {
	*ptPrem = NULL;
}

// Allouer la mémoire pour un nouvel élément
// Initialiser le champ val
typeElt *creerElt (typeDonnee valeur){
	typeElt *nouveau;
    
	// Allocation de la mémoire pour le nouvel élément
	nouveau = (typeElt *) malloc (sizeof (typeElt));
    
	if (nouveau != NULL) {
		nouveau->val = valeur;  // Insertion de la valeur donnée
	}
	return nouveau;             // On retourne un pointeur sur ce nouvel élément
}

// Lire la valeur stockée dans l'ÈlÈment
typeDonnee valElt (typeElt *element) {
	return (element->val);
}

// Lire le pointeur suivant dans l'élément
typeElt *suivantElt (typeElt *element){
	return (element->suivant);
}

// Insérer un élément après l'élément courant
// ptPrem est l'adresse du pointeur sur le premier de la liste
// courant sera Ègal à NULL si on veut insérer en début de liste
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau) {
    
	if (courant == NULL) {
		//Le nouvel élément doit être inséré en tête de liste
		nouveau->suivant = *ptPrem;
		*ptPrem = nouveau;                  //Le nouveau est en tête de liste
	} else {
		// Le nouvel élément est inséré derrière l'elt courant
		nouveau->suivant = courant->suivant;
		courant->suivant = nouveau;
	}
}

// Détruire l'élément placé derrière l'élément courant
// ptPrem est l'adresse du pointeur sur le premier de la liste
// courant vaut NULL s'il faut enlever le premier
void detruireElt (typeElt **ptPrem, typeElt *courant){
	typeElt *elt;
    
	if (courant == NULL) {
		// Enlever le premier de la liste
		elt = *ptPrem;                          // Garder l'adresse du premier élément
		*ptPrem = elt->suivant;                 // Premier pointera sur le 2ème élément
	} else {
		elt = courant->suivant;                 // Element à enlever
		courant->suivant = elt->suivant;        // Modifier le pointeur du precedent
	}
	free (elt);                                 // Liberer la mémoire pour l'élément détruit
}
