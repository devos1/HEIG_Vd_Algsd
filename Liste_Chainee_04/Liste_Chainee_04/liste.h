//
//  liste.h
//  Liste_Chainee_04
//
//  Created by Oscar on 18.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//




/* Type des ÈlÈments stockÈs dans le champ donnÈe */
typedef int typeDonnee;

/* Structure pour reprÈsenter un ÈlÈment de la liste */
typedef struct elt {
	typeDonnee val;        // Champ donnÈe
	struct elt *suivant;   // Pointeur sur l'ÈlÈment suivant
} typeElt;

/* Initialise la liste : pas d'ÈlÈment */
void initListe (typeElt **ptPrem);

/* Allouer la mÈmoire pour un nouvel ÈlÈment */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur);

/* Lire la valeur stockÈe dans l'ÈlÈment */
typeDonnee valElt (typeElt *element);

/* Lire le pointeur suivant dans l'ÈlÈment */
typeElt *suivantElt (typeElt *element);

/* InsËrer un ÈlÈment aprËs l'ÈlÈment courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera Ègal ‡ NULL si on veut insÈrer en dÈbut de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau);

/* DÈtruire l'ÈlÈment placÈ derriËre l'ÈlÈment courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant vaut NULL s'il faut enlever le premier */
void detruireElt (typeElt **ptPrem, typeElt *courant);


