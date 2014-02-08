//
//  liste.c
//  Liste_Chainee_02
//
//  Created by Oscar on 07.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

#define VRAI 1
#define FAUX 0

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

// Enleve un element de la liste
// Resultat VRAI si l'element est dans la liste et FAUX sinon
int enlever (typeElt **ptPrem, int val){
    int trouve = FAUX;
    typeElt *courant, *precedent;
    
    courant = *ptPrem;                  //Start au début de liste
    precedent = NULL;                   //Init à NULL puisque rien avec le premier élément de la liste
    
    while (courant != NULL && !trouve) {
        if (valElt(courant) == val) {
            trouve = VRAI;
        }else{
            precedent = courant;            //On mémorise le courant
            courant = suivantElt(courant);  //On passe au suivant
        }
    }
    
    if (trouve) {
        detruireElt(ptPrem, precedent);     //On passe le precedent pour pouvoir supprimer celui juste après, comme ça
        //il est possible de modifier precedent->suivant afin qu'il pointe sur celui après l'élément enlevé!
    }
    
    return trouve;
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

//---------EXERCICE 2----------
// Insérer un élément directement dans l'ordre croissant
// Rend VRAI si insertion  OK, FAUX sinon
int insereEltOrdreC (typeElt **ptPrem, typeDonnee val){
    
    typeElt *precedent, *courant, *nouveau;
    int retour = FAUX;
    int trouve = FAUX;
    
    courant = *ptPrem;      //Se placer en tête de liste
    precedent = NULL;
    
    while (courant != NULL && !trouve) {
        if (val <= valElt(courant)) {
            trouve = VRAI;
        }else{
            precedent = courant;                    //On mémorise le courant
            courant = suivantElt(courant);          //On passe au suivant
        }
        
    }
    
    // A la fin de la boucle precedent pointe sur l'élément derrière lequel
	// on doit insèrer un nouvel élément ou est Ègal à NULL si on insère
	// en début de liste
    nouveau = creerElt(val);
    
    if (nouveau != NULL) {
        insereElt(ptPrem, precedent, nouveau);  //Le courant est precedent car on veut insère avan le vrai courant
        retour = VRAI;                          //étant donné qu'on veut insèrer dans l'ordre croissant!!
    }
    
    return retour;
}

//---------EXERCICE 3----------
// Suppression des éléments pairs d'une liste et les insèrer dans une nouvelle
// RESULAT: Pointeur sur la liste paire
typeElt *enlevePair(typeElt **premier){
    
    typeElt *precedent1,  *courant1, *courant2, *premier2, *nouveau;
    int val;
    
    // Initialiser la liste 2 (nb paires)
    initListe(&premier2);
    
    courant1 = *premier;
    courant2 = NULL;
    precedent1 = NULL;
    
    while (courant1 != NULL) {
        val = valElt(courant1);
        if (val % 2 == 0) {
            courant1 = suivantElt(courant1);
            nouveau = creerElt(val);
            insereElt(&premier2, courant2, nouveau);
            detruireElt(premier, precedent1);
            courant2 = nouveau;
        }else{
            // Faire avancer les 2 pointeurs
            precedent1 = courant1;
            courant1 = suivantElt(courant1);
        }
    }
    
    return premier2;
}

// Fusion de 2 listes en gardant l'ordre croissant
// RESULTAT: pointeur sur la nouvelle liste
typeElt *fusionListes (typeElt *liste1, typeElt *liste2){
    
    typeElt *listeFusionee, *courant1, *courant2, *courant3, *nouveau;
    int val1, val2;
    
    //Initialier la nouvelle liste
    initListe(&listeFusionee);
    
    courant1 = liste1;
    courant2 = liste2;
    courant3 = NULL;
    
    while (courant1 != NULL && courant2 != NULL) {
        val1 = valElt(courant1);
        val2 = valElt(courant2);
        nouveau = creerElt(mini(val1, val2));
        insereElt(&listeFusionee, courant3, nouveau);
        courant3 = nouveau;
        
        if (val1 < val2) {
            courant1 = suivantElt(courant1);
        }else{
            courant2 = suivantElt(courant2);
        }
    }
    
    //Raccorder la fin de la dernière liste
    if (courant2 != NULL) {
        courant1 = courant2;
    }
    while (courant1 != NULL) {
        val1 = valElt(courant1);
        nouveau = creerElt(val1);
        insereElt(&listeFusionee, courant3, nouveau);
        courant3 = nouveau;
        courant1 = suivantElt(courant1);
    }
    
    return listeFusionee;
}

// Valeur mini (a,b)
int mini (int a, int b){
    if (a < b) {
		return a;
	} else {
		return b;
	}
}

// Concaténation de 2 listes
void concatener (typeElt **ptPrem1, typeElt *ptPrem2) {
	typeElt *courant;
    
	if (*ptPrem1 == NULL) {   // 1 - La liste 1 est vide
		*ptPrem1 = ptPrem2;
	} else {                  // 2 - La liste 1 n'est pas vide
		courant = *ptPrem1;
		while (courant->suivant != NULL) {
			courant = courant->suivant;
		}
		courant->suivant = ptPrem2;
	}
}


