//
//  listedouble.h
//  ListeDoubleChainee_01
//
//  Created by Oscar da Silva on 04.03.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#ifndef ListeDoubleChainee_01_listedouble_h
#define ListeDoubleChainee_01_listedouble_h
#endif


// Type d'élément stocké
typedef int typeDonnee;

// Définition d'un élément de la liste
typedef struct elt{
    typeDonnee val;
    struct elt *suivant;
    struct elt *precedent;
} typeElt;

// Initialise la liste sans élément
void initListe (typeElt **ptPrem);

// Créer un élément sans insertion dans la liste
typeElt *creerElt (typeDonnee valeur);

// Donne la valeur de l'élément courant
typeDonnee valElt (typeElt *courant);

// Donne le pointeur sur l'élément suivant
typeElt *suivantElt (typeElt *courant);

// Donne le pointeur sur l'élément précédent
typeElt *precedantElt (typeElt *courant);

// Insére l'élément nouveau dans la liste après le courant */
// Insére en premier quand courant == NULL
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau);

/* Détruire l'élément courant */
/* Détruire le 1er si courant == *ptPrem  */
void detruireElt (typeElt **ptPrem, typeElt *courant);