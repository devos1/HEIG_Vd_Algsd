//
//  Test_02.c
//  Liste_Chainee_Tests
//
//  Created by Oscar on 09.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Divers tests sur les listes chainnées
//  MENU:
//          - 0: Quitter
//          - 1: Insérer valeur
//          - 2: Supprimer valeur
//          - 3: Afficher liste
//
//  REMARQUE: Ne pas oublier de changer le typeDonne
//
/***********************************************************
 TEST 02:
    - Travail sur une liste d'entier
    - Insertion d'entiers dans l'ordre croissant
    - Suppression d'entier
    - Affichage de la liste
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define VRAI 1
#define FAUX 0


int main2()
{
    int choix;
    typeDonnee val;
    typeElement *premier;                       //Correspond à l'emplacement de la liste
    
    initListe(&premier);                        //Initialisation de la liste
    
    
    printMenu();
    choix = saisieEntier();
    
    while (choix != 0) {
        switch (choix) {
            case 1:
                printf("Insertion valeur \n");
                printf("Entrer valeur: ");
                val = saisieEntier();
                if (!(insereEltOrdreC(&premier, val))) {
                    puts("Impossible d'inserer la valeur");
                }
                break;
            case 2:
                printf("Enlever une valeur \n");
                printf("Valeur a enlever: ");
                val = saisieEntier();
                if (!(enleverElement(&premier, val))) {
                    puts("La valeur n'est pas dans la liste");
                }
                break;
            case 3:
                puts("AFFICHER LISTE:");
                puts("---------------");
                printListeInt(premier);
                puts("---------------");
                break;
            default:
                printf("Erreur de saisie\n");
                break;
        }
        
        printMenu();
        choix = saisieEntier();
    }
    
    puts("Detruire la liste...\n");
    detruireListe(&premier);
    
    
    return 0;
}
