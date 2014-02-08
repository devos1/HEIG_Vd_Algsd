//
//  main.c
//  Files_01
//
//  Created by Oscar on 08.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Utilisation d'une file pour gèrer une file d'attente à un guichet
//  MENU:
//          0: Arrêter
//          1: Arrivée d'une personne
//          2: Départ d'une personne

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define LGL 80                  //Taille pour une ligne de caractères
#define TAILLEFILE 10           //Taille max d'une file

//  PROTOTYPES DE FONCTIONS
//  Saisie d'un entier
int saisieEntier();

//  Saisie d'un nom et allocation de mémoire pour le stocker
char *saisieNom ();



/***********************************************************
 ------------------------MAIN-------------------------------
 ***********************************************************/

int main()
{
    printf("Exercice 1 sur les files\n");
    puts("----------------------------");
    
    //  Declaration d'un objet file
	typeFile *file;
	char *nom;                          //Pointeur sur le nom de la personne
	int cde;
    
	file = initFile (TAILLEFILE);       //Initialiser la file
	if (file == NULL) {
		puts ("La file d'attente ne peut pas etre allouee");
	} else {
		cde = saisieEntier ();
		while ( cde != 0) {
			switch (cde) {
                case 1 :
                    if (filePleine(file)) {
                        printf ("Entree impossible car la file est pleine\n\n");
                    } else {
                        //  Saisir le nom de la personne
                        printf ("Nom de la personne en attente : ");
                        nom = saisieNom();
                        ajouteElem (file, nom);
                    }
                    break;
                case 2 :
                    if (fileVide(file)) {
                        printf ("Il n'y a personne dans la file d'attente\n");
                    } else {
                        nom = suppElem (file);  //Enlever le premier
                        printf ("%s peut se presenter au guichet\n", nom);
                        free (nom);             //Libèrer l'espace mÈmoire du nom
                    }
                    break;
                default: puts ("Erreur");
			}
			cde = saisieEntier();
		}
        
        //  CAS OU IL RESTE DES PERSONNES DANS LA FILE QUI N'ONT PAS ETE PRISES
		if (!fileVide(file)) {
			printf ("Il reste des personnes en file d'attente\n");
			while (!fileVide (file)) {      // libèrer la mémoire pour les noms
				nom = suppElem (file);      // Enlever le premier
				free (nom);                 // Libérer l'espace mémoire du nom
			}
		}
        
		detruireFile (file); // DÈtruire la structure de la file
	}
    
    
    
    return 0;
}

/***********************************************************
 ----------------------FONCTIONS----------------------------
 ***********************************************************/

//  Saisie d'un entier

int saisieEntier () {
	int valeur, n ;
	char ligne [LGL];
    
	printf ("\nChoix (1 pour arriver, 2 pour depart, 0 pour fin) : ");
	fgets (ligne, LGL, stdin);
	n = sscanf (ligne,"%d", &valeur);
	while (n != 1) { // Tant que la saisie n'est pas une valeur numÈrique
		printf ("Choix (1 pour arriver, 2 pour depart, 0 pour fin) : ");
		fgets (ligne, LGL, stdin);
		n = sscanf (ligne, "%d", &valeur);
	}
	return valeur;
}

//  Saisie un nom dans un tableau local (ligne) et
//  alloue la mémoire nécessaire pour stocker le nom
//  puis recopie le nom dans cette mémoire dynamique */
char *saisieNom () {
	char ligne [LGL];
	char *nom;
	
	fgets (ligne, LGL, stdin);                          // Saisie d'une ligne au clavier
	ligne [strlen(ligne)-1] = '\0';                     // enlever \n
	nom = (char *)malloc (strlen (ligne) + 1);          // allouer la mémoire nÈcessaire
	strcpy (nom, ligne);                                // Recopier le nom dans cette mémoire
	return nom;
}

