//
//  main.c
//  Liste_Chainee_Tests
//
//  Created by Oscar on 08.02.14.
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
 TEST 01:
    - Travail sur une liste de caractères
    - Insertion de caractères
    - Suppression de caractères
    - Affichage de la liste
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define VRAI 1
#define FAUX 0


int main1()
{
    int choix;
    typeDonnee valeur;
    typeElement *premier;                           //  Emplecement de la liste
    typeElement *courant, *nouveau;
    
    courant = NULL; nouveau = NULL;
 
    //  Init liste
    initListe(&premier);
    
    printMenu();
    choix = saisieEntier();

    while (choix != 0) {
        switch (choix) {
            case 0:
                puts("Fin du programme");
                break;
            case 1:
                puts("Insertion d'un element:");
                //  Demande user le caractère
                printf("Entrer un caractère: ");
                scanf("%c", &valeur);
                //  Création d'un nouvel élément
                nouveau = creerElement(valeur);
                //  Insertion de celui-ci
                if (nouveau == NULL) {
                    puts("Impossible d'insérer un élément...");
                }else{
                    insererElement(&premier, courant, nouveau);
                    courant = nouveau;
                }
                break;
            case 2:
                puts("Suppression d'un element:");
                printf("Entrer le caractère à supprimer: ");
                scanf("%c", &valeur);
                if (!(enleverElement(&premier, valeur))) {
                    puts("Valeur non trouvée dans la liste");
                }
                break;
            case 3:
                puts("AFFICHER LISTE:");
                puts("---------------");
                printListeChar(premier);
                puts("---------------");
                break;
            default:
                puts("ERREUR");
                break;
        }
        
        printMenu();
        choix = saisieEntier();
    }
    
    puts("Detruire la liste...\n");
    detruireListe(&premier);
    
    return 0;
}
