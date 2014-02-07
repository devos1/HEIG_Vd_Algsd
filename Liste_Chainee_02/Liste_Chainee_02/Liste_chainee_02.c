//
//  main.c
//  Liste_Chainee_02
//
//  Created by Oscar on 07.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Insertion, suppression et affichage de valeurs entières dans une liste triées par ordre croissant
//  MENU:
//          0. fin - détruire la liste
//          1. insérer une valeur
//          2. enlèver une valeur (si elle existe dans la liste)
//          3. imprimer la liste

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

#define VRAI 1
#define FAUX 0

//Prototypes de fonctions
int saisieEntier();

// Enleve un element de la liste
// Resultat VRAI si l'element est dans la liste et FAUX sinon
int enlever (typeElt **ptPrem, int val);

// Imprime toutes les valeurs de la liste
void imprimerListe (typeElt *premier);

// Détruire la liste
void detruireListe (typeElt **premier);

/***********************************************************
 ------------------------MAIN-------------------------------
 ***********************************************************/

int main(int argc, const char * argv[])
{

    int choix;
    typeDonnee val;
    typeElt *premier, *nouveau, *courant;   //Correspond à l'emplacement de la liste
    
    initListe(&premier);                    //Initialisation de la liste
    nouveau = NULL;                         //Init du nouvel élément
    courant = NULL;                         //Init de l'élément courant
    
    
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
                nouveau = creerElt(val);
                if (nouveau == NULL) {
                    printf("Impossible d'inserer un element: plus de memoire");
                }else{
                    insereElt(&premier, courant , nouveau);
                    courant = nouveau;
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
    
    puts("Detruire la liste...\n");
    detruireListe(&premier);
    
    
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

// Enleve un element de la liste
// Resultat VRAI si l'element est dans la liste et FAUX sinon
int enlever (typeElt **ptPrem, int val){
    int trouve = FAUX;
    typeElt *courant, *precedent;
    
    courant = *ptPrem;                  //Start au début de liste
    precedent = NULL;                   //Init à NULL puisque rien avec le premier élément de la liste
    
    while (courant != NULL && !trouve) {
        if (valElt(courant) == val) {
            trouve = VRAI;
        }else{
            precedent = courant;            //On mémorise le courant
            courant = suivantElt(courant);  //On passe au suivant
        }
    }
    
    if (trouve) {
        detruireElt(ptPrem, precedent);     //On passe le precedent pour pouvoir supprimer celui juste après, comme ça
        //il est possible de modifier precedent->suivant afin qu'il pointe sur celui après l'élément enlevé!
    }
    
    return trouve;
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