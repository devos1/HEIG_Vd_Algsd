//
//  Liste_Chainee_03.c
//  Liste_Chainee_03
//
//  Created by Oscar on 08.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Enlever toutes les valeurs paires d'une liste et les insèrer dans une nouvelle par ordre croissant
//  MENU:
//          0. fin - détruire la liste
//          1. insérer une valeur
//          2. enlèver une valeur (si elle existe dans la liste)
//          3. imprimer le liste

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


#define VRAI 1
#define FAUX 0

//Prototypes de fonctions
int saisieEntier();

// Imprime toutes les valeurs de la liste
void imprimerListe (typeElt *premier);

// Détruire la liste
void detruireListe (typeElt **premier);

/***********************************************************
 ------------------------MAIN-------------------------------
 ***********************************************************/

int main()
{
    int choix;
    typeDonnee val;
    typeElt *premier;                       //Correspond à l'emplacement de la liste
    typeElt *premierListe2;                 //Correspond à l'emplacement de la liste 2
    typeElt *premierListeFusion;            //Correspond à l'emplacement de la liste fusionnée
    
    initListe(&premier);                    //Initialisation de la liste
    
    
    printf("Exercice: Liste chainee 01\n");
    puts("------------------------------");
    
    printf("Entre choix commande: ");
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
                if (!(enlever(&premier, val))) {
                    puts("La valeur n'est pas dans la liste");
                }
                break;
            case 3:
                printf("Impression liste \n");
                imprimerListe(premier);
                break;
            default:
                printf("Erreur de saisie\n");
                break;
        }
        
        printf("Entrer choix commande: ");
        choix = saisieEntier();
    }
    
    
    // PARTIE EXERCICE 3
    // Enlever pairs de la liste créée pour les mettre dans une nouvelle liste
    
    //Pointeur sur la nouvelle liste paire
    premierListe2 = enlevePair(&premier);
    
    //Pointeur sur la nouvelle liste fusionnée
    premierListeFusion = fusionListes(premier, premierListe2);
    
    //Imprimer les listes
    //Liste impaires
    printf("valeurs impaires: ");
    imprimerListe(premier);
    
    //Liste paires
    printf("valeurs paires: ");
    imprimerListe(premierListe2);
    
    //Liste fusionnée
    printf("Liste fusionnee: ");
    imprimerListe(premierListeFusion);
    
    //Liste concaténée
    concatener(&premier, premierListe2);
    printf("Liste concatenee: ");
    imprimerListe(premier);
    
    puts("Detruire les listes...\n");
    detruireListe(&premier);
    detruireListe(&premierListeFusion);
    
    
    return 0;
}

/***********************************************************
 ----------------------FONCTIONS----------------------------
 ***********************************************************/

// Saisie d'une valeur entière
int saisieEntier () {
	int n, val;
	char ligne [100];
    
	fgets (ligne, 100, stdin);
	n = sscanf (ligne, "%d", &val);
	while (n != 1) {
		printf ("Entrer une valeur entiere : ");
		fgets (ligne, 100, stdin);
		n = sscanf (ligne, "%d", &val);
	}
	return (val);
}



// Imprime toutes les valeurs de la liste
void imprimerListe (typeElt *premier){
    
    typeElt *courant;
    courant = premier;
    
    while (courant != NULL) {
        printf("%d ", valElt(courant));
        courant = suivantElt(courant);
    }
    
    puts("");
}

// Détruire la liste
void detruireListe (typeElt **premier){
    
    while (*premier != NULL) {              //Parcours de la liste jusqu'à que l'élément suivant soit NULL
        detruireElt(premier, NULL);         //Suppression à chaque fois du premier de la liste
    }
}



