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
    - Fusionner les 2 listes dans une 3ème
 ***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define MAX_TAB 6

int main(){
    
    //Pointeur sur les nouvelles listes
    typeElement *liste1 = NULL, *liste2 = NULL, *liste3 = NULL;
    
    //Déclaration de 2 tableaux statiquex
    int tab1[MAX_TAB] = {1, 3, 6, 10, 14, 15};
    int tab2[MAX_TAB] = {2, 7, 8, 12, 16, 20};
    
    //Afficher tableau 1
    printf("Tableau 1: ");
    printTableau(tab1, MAX_TAB);
    
    //Afficher tableau 2
    printf("Tableau 2: ");
    printTableau(tab2, MAX_TAB);
    
    //Passage du tableau 2 vers liste 1
    liste1 = iArrayTolist(tab1, MAX_TAB);
    printf("Liste 1: ");
    printListeInt(liste1);
    
    //Passage du tableau 2 vers liste 2
    liste2 = iArrayTolist(tab2, MAX_TAB);
    printf("Liste 2: ");
    printListeInt(liste2);
    
    //Fusion des 2 listes dans une 3ème
    liste3 = fusionListe(liste1, liste2);
    printf("Liste fusionée: ");
    printListeInt(liste3);
    
    //Listes concaténées
    concatListe(&liste1, liste2);
    printf("Liste concatenées: ");
    printListeInt(liste1);
    
    return 0;
}