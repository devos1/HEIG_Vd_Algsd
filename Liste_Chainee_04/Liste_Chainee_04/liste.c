//
//  liste.c
//  Liste_Chainee_04
//
//  Created by Oscar on 18.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Initialise la liste : pas d'ÈlÈment */
void initListe (typeElt **ptPrem) {
	*ptPrem = NULL;
}

/* Allouer la mÈmoire pour un nouvel ÈlÈment */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur){
	typeElt *nouveau;
    
	/* Allocation de la mÈmoire pour le nouvel ÈlÈment */
	nouveau = (typeElt *) malloc (sizeof (typeElt));
	if (nouveau != NULL) {
		nouveau->val = valeur; // Initialisation de la donnÈe
	}
	return nouveau;
}

/* Lire la valeur stockÈe dans l'ÈlÈment */
typeDonnee valElt (typeElt *element) {
	return (element->val);
}

/* Lire le pointeur suivant dans l'ÈlÈment */
typeElt *suivantElt (typeElt *element){
	return (element->suivant);
}


/* InsËrer un ÈlÈment aprËs l'ÈlÈment courant */
/* Resultat : 1 si ok 0 si allocation mÈmoire impossible */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera Ègal ‡ NULL si on veut insÈrer en dÈbut de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau) {
    
	if (courant == NULL) {
		/* Le nouvel ÈlÈment doit Ítre insÈrÈ en dÈbut de liste */
		nouveau->suivant = *ptPrem;
		*ptPrem = nouveau;
	} else {
		/* Le nouvel ÈlÈment est insÈrÈ derriËre l'elt courant */
		nouveau->suivant = courant->suivant;
		courant->suivant = nouveau;
	}
}

/* DÈtruire l'ÈlÈment placÈ derriËre l'ÈlÈment courant */
/* RÈsultat : valeur stockÈe dans l'ÈlÈment dÈtruit */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* Courant sera Ègal ‡ NULL pour dÈtruire le premier de la liste */
void detruireElt (typeElt **ptPrem, typeElt *courant){
	typeElt *elt;
    
	if (courant == NULL) {
		/* Enlever le premier de la liste */
		elt = *ptPrem;                        /* Garder l'adresse du premier ÈlÈment */
		*ptPrem = elt->suivant;               /* Premier pointera sur le 2Ëme ÈlÈment */
	} else {
		elt = courant->suivant;                /* Element ‡ enlever */
		courant->suivant = elt->suivant;       /* Modifier le pointeur du precedent */
	}
	free (elt);  /* Liberer la mÈmoire pour l'ÈlÈment dÈtruit */
}
