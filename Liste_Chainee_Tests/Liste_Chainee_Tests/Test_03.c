//
//  Test_03.c
//  Liste_Chainee_Tests
//
//  Created by Oscar da Silva on 09.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Divers tests sur les listes chainnées
//  MENU:
//
//  REMARQUE: Ne pas oublier de changer le typeDonne
//
/***********************************************************
 TEST 03:
    - Passer les valeurs de 2 tableaux à 2 listes différentes
    -
 ***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define MAX_TAB 6

int main(){
    
    //Pointeur sur les nouvelles listes
    typeElement *liste1 = NULL, *liste2 = NULL;
    
    //Déclaration de 2 tableaux statiquex
    int tab1[MAX_TAB] = {1, 2, 3, 4, 5, 6};
    int tab2[MAX_TAB] = {10, 11, 12, 13, 14, 15};
    
    //Afficher tableau 1
    printf("Tableau 1: ");
    printTableau(tab1, MAX_TAB);
    
    //Afficher tableau 2
    printf("Tableau 2: ");
    printTableau(tab2, MAX_TAB);
    
    //Passage du tableau vers liste 1
    liste1 = iArrayTolist(tab1, MAX_TAB);
    printf("Liste 1: ");
    printListeInt(liste1);
    
    
    return 0;
}