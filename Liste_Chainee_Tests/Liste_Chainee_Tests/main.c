//
//  main.c
//  Liste_Chainee_Tests
//
//  Created by Oscar da Silva on 08.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/***********************************************************
 ---------------PROTOTYPES DE FONCTIONS----------------------
 ***********************************************************/


//	Définition du type de données qu'il y aura dans la pile
typedef int typeDonnee;					// Dans ce cas un INTEGER

// Structure pour répresenter un élément de la liste
typedef struct element{
	typeDonnee val;						// Valeur dans l'élément
	struct	element *suivant;			// Pointeur sur l'élément suivant de la liste
}typeElement;

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


/***********************************************************
 ------------------------MAIN-------------------------------
 ***********************************************************/

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

/***********************************************************
 ----------------------FONCTIONS----------------------------
 ***********************************************************/

//  1.  Initialiser la liste sans aucun élément
void initListe(typeElement **pPremier){
    *pPremier = NULL;
}

//  2.  Allouer la mémoire pour un nouvel élément
//      Initialiser le champ val
typeElement *creerElement(typeDonnee val){
    
    typeElement *nouveau;
    
    nouveau = (typeElement *) malloc (sizeof(typeElement));
    
    if (nouveau != NULL) {
        nouveau->val = val;                         //  Insertion de la valeur dans l'élément
    }
    
    return  nouveau;                                //  On retourne un pointeur sur ce nouvel élément
}

//  3.  Lire la valeur stockée dans un élément
typeDonnee lireValeurElement(typeElement *element){
    return element->val;
}

//  4.  Lire le pointeur du suivant dans l'élément
typeElement *elementSuivant(typeElement *element){
    return element->suivant;
}

//  5.  Insérer un élément après l'élément courant
//      pPremier est l'adresse du pointeur sur le premier de la liste
//      courant sera Ègal à NULL si on veut insérer en début de liste
void insererElement(typeElement **pPremier, typeElement *courant, typeElement *nouveau){
    
    if (courant == NULL) {                          //  Le nouvel élément doit être inséré en tête de liste
        nouveau->suivant = *pPremier;               //  On déplace l'ancienne tête à la 2ème place
        *pPremier = nouveau;                        //  Puis on défini la nouvelle tête avec le nouvel élément ajouté
    }else{                                          //  SINON, On insère après l'élément courant
        nouveau->suivant = courant->suivant;        //  Le nouveau prend la place juste après le courant, donc il récupère le pointeur du suivant
        courant->suivant = nouveau;                 //  Le courant récupére le pointeur du nouveau qui est juste après lui maintenant
    }
}







