//
//  header.h
//  Liste_Chainee_Tests
//
//  Created by Oscar on 09.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#ifndef Liste_Chainee_Tests_header_h
#define Liste_Chainee_Tests_header_h
#endif

/***********************************************************
 DEFINITION DES TYPES
 ***********************************************************/

//	Définition du type de données qu'il y aura dans la pile
typedef int typeDonnee;					// Dans ce cas un CHAR

// Structure pour répresenter un élément de la liste
typedef struct element{
	typeDonnee val;						// Valeur dans l'élément
	struct	element *suivant;			// Pointeur sur l'élément suivant de la liste
}typeElement;

/***********************************************************
 FONCTIONS LISTES CHAINEES
 ***********************************************************/

//  1.  Initialiser la liste sans aucun élément
void initListe(typeElement **pPremier);         //  Pointeur sur le début de la liste

//  2.  Allouer la mémoire pour un nouvel élément
//      Initialiser le champ val
typeElement *creerElement(typeDonnee val);

//  3.  Lire la valeur stockée dans un élément
typeDonnee lireValeurElement(typeElement *element);

//  4.  Lire le pointeur du suivant dans l'élément
typeElement *elementSuivant(typeElement *element);

//  5.  Insérer un élément après l'élément courant
//      pPremier est l'adresse du pointeur sur le premier de la liste
//      courant sera Ègal à NULL si on veut insérer en début de liste
void insererElement(typeElement **pPremier, typeElement *courant, typeElement *nouveau);

//  6.  Détruire l'élément placé derrière l'élément courant
//      pPremier est l'adresse du pointeur sur le premier de la liste
//      courant vaut NULL s'il faut enlever le premier
void detruireElement(typeElement **pPremier, typeElement *courant);

//  7.  Imprime toutes les valeurs d'une liste
void printListeChar(typeElement *pPremier);

//  7.1  Imprime toutes les valeurs d'une liste
void printListeInt(typeElement *pPremier);

//  8.  Enleve un element de la liste
//      Resultat VRAI si l'element est dans la liste et FAUX sinon
int enleverElement(typeElement **premier, typeDonnee val);

//  9.  Detruire une liste
void detruireListe(typeElement **premier);

//  10. Insérer un élément directement dans l'ordre croissant
//      Rend VRAI si insertion  OK, FAUX sinon
int insereEltOrdreC (typeElement **premier, typeDonnee val);

//  11. Passer les valeurs d'un tableau d'entiers vers une nouvelle liste d'entiers
//      Retourne un pointeur sur la nouvelle liste
typeElement *iArrayTolist(const int tab[], int taille);

/***********************************************************
 FONCTIONS DIVERSES
 ***********************************************************/

//  20. Saisie d'un entier
int saisieEntier();

//  21. Afficher menu pour travail sur listes
void printMenu();

//  22. Afficher menu exercices
void printMenuEx();

//  23. Imprimer un tableau
void printTableau(int tab[], int n);

