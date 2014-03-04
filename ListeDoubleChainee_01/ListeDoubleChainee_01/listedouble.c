//
//  listedouble.c
//  ListeDoubleChainee_01
//
//  Created by Oscar da Silva on 04.03.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "listedouble.h"


// Initialise la liste sans élément
void initListe (typeElt **ptPrem){
    *ptPrem = NULL;
}

// Créer un élément sans insertion dans la liste
typeElt *creerElt (typeDonnee valeur){
    typeElt *nouveau;
    
    // Allocation de la mémoire pour le nouvel élément
    nouveau = (typeElt *) malloc (sizeof (typeElt));
    
	if (nouveau != NULL) {
		nouveau->val = valeur;  // Insertion de la valeur donnée
	}
	return nouveau;             // On retourne un pointeur sur ce nouvel élément
}

// Donne la valeur de l'élément courant
typeDonnee valElt (typeElt *courant){
    return courant->val;
}

// Donne le pointeur sur l'élément suivant
typeElt *suivantElt (typeElt *courant){
    return courant->suivant;
}

// Donne le pointeur sur l'élément précédent
typeElt *precedantElt (typeElt *courant){
    return courant->precedent;
}

// Insére l'élément nouveau dans la liste après le courant */
// Insére en premier quand courant == NULL
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau){
    
    // Insertion en tête de liste
    if (courant == NULL) {
        courant->precedent = nouveau;
        nouveau->precedent = NULL;
        nouveau->suivant = courant;
    }else if (courant->suivant == NULL){        // Fin de liste
        courant->suivant = nouveau;
        nouveau->suivant = NULL;
        nouveau->precedent = courant;
    }else {
        nouveau->suivant = courant->suivant;
        nouveau->precedent = courant;
        courant->suivant->precedent = nouveau;
        courant->suivant = nouveau;
    }
}

/* Détruire l'élément courant */
/* Détruire le 1er si courant == *ptPrem  */
void detruireElt (typeElt **ptPrem, typeElt *courant){
    
    if (courant == *ptPrem) {
        // Enlever le 1er de la liste
        *ptPrem = (*ptPrem)->suivant;                               // Le pointeur du premier passe au suivant
        if (*ptPrem != NULL) {
            (*ptPrem)->suivant = NULL;                              // Si c'était le seul élément
        }
    }else{
        // Modifier le pointeur du précédent pour lui donner celui après celui qu'on supprime
        (courant->precedent)->suivant = courant->suivant;
        if (courant->suivant != NULL) {
            (courant->suivant)->precedent = courant->precedent;     // Courant n'est pas le dernier de la liste
        }
    }
    free(courant);         // Libérer la mémoire
}