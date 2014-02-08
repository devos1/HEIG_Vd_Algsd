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

// Enleve un element de la liste
// Resultat VRAI si l'element est dans la liste et FAUX sinon
int enlever (typeElt **ptPrem, int val);

// Détruire l'élément placé derrière l'élément courant
// ptPrem est l'adresse du pointeur sur le premier de la liste
// courant vaut NULL s'il faut enlever le premier
void detruireElt (typeElt **ptPrem, typeElt *courant);


//---------EXERCICE 2----------
// Insérer un élément directement dans l'ordre croissant
// Rend VRAI si insertion  OK, FAUX sinon
int insereEltOrdreC (typeElt **ptPrem, typeDonnee val);


//---------EXERCICE 3----------
// Suppression des éléments pairs d'une liste et les insèrer dans une nouvelle
// RESULAT: Pointeur sur la liste paire
typeElt *enlevePair(typeElt **premier);

// Fusion de 2 listes en gardant l'ordre croissant
// RESULTAT: pointeur sur la nouvelle liste
typeElt *fusionListes (typeElt *liste1, typeElt *liste2);

// Valeur mini (a,b)
int mini (int a, int b);

// Concaténation de 2 listes
// ptPrem2 : pointeur sur le premier élément de la liste 2
// ptPrem1 : adresse du pointeur sur le 1er de la liste 1
// RESULTAT : la liste 2 sera ajoutée à la liste 1
void concatener (typeElt **ptPrem1, typeElt *ptPrem2);
