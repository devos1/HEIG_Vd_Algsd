//
//  liste.h
//  Liste_Chainee_02
//
//  Created by Oscar on 07.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#ifndef Liste_Chainee_01_liste_h
#define Liste_Chainee_01_liste_h
#endif

// Type des éléments stockés dans le champ donnée
typedef int typeDonnee;

// Structure pour représenter un élément de la liste
typedef struct elt {
	typeDonnee val;        // Champ donnée
	struct elt *suivant;   // Pointeur sur l'élément suivant
} typeElt;

// Initialise la liste : pas d'éléments
void initListe (typeElt **ptPrem);

// Allouer la mémoire pour un nouvel élément
// Initialiser le champ val
typeElt *creerElt (typeDonnee valeur);

// Lire la valeur stockée dans l'élément
typeDonnee valElt (typeElt *element);

// Lire le pointeur suivant dans l'élément
typeElt *suivantElt (typeElt *element);

// Insérer un élément après l'élément courant
// ptPrem est l'adresse du pointeur sur le premier de la liste
// courant sera Ègal à NULL si on veut insérer en début de liste
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau);

// Détruire l'élément placé derrière l'élément courant
// ptPrem est l'adresse du pointeur sur le premier de la liste
// courant vaut NULL s'il faut enlever le premier
void detruireElt (typeElt **ptPrem, typeElt *courant);



