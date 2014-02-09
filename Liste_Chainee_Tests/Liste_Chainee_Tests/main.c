//
//  main.c
//  Liste_Chainee_Tests
//
//  Created by Oscar da Silva on 08.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//
//  Divers tests sur les listes chainnées
//  MENU:
//          - 0: Quitter
//          - 1: Insérer valeur
//          - 2: Supprimer valeur
//          - 3: Afficher liste
//

#include <stdio.h>
#include <stdlib.h>

#define VRAI 1
#define FAUX 0

/***********************************************************
 ---------------PROTOTYPES DE FONCTIONS----------------------
 ***********************************************************/


//	Définition du type de données qu'il y aura dans la pile
typedef char typeDonnee;					// Dans ce cas un CHAR

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

//  7.  Imprime toutes les valeurs d'une liste
void printListe(typeElement *pPremier);

//  8.  Enleve un element de la liste
//      Resultat VRAI si l'element est dans la liste et FAUX sinon
int enleverElement(typeElement **premier, typeDonnee val);

//  10. Saisie d'un entier
int saisieEntier();

//  11. Afficher menu
void printMenu();

/***********************************************************
 ------------------------MAIN-------------------------------
 ***********************************************************/

int main()
{
    int choix;
    typeDonnee valeur;
    typeElement *premier;                           //  Emplecement de la liste
    typeElement *courant, *nouveau;
    
    courant = NULL; nouveau = NULL;
    
    printf("Cration d'une liste chainee vide:\n");
    puts("-----------------------------------");
 
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
                printListe(premier);
                puts("---------------");
                break;
            default:
                puts("ERREUR");
                break;
        }
        
        printMenu();
        choix = saisieEntier();
    }
    
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

//  6.  Détruire l'élément placé derrière l'élément courant
//      pPremier est l'adresse du pointeur sur le premier de la liste
//      courant vaut NULL s'il faut enlever le premier
void detruireElement(typeElement **pPremier, typeElement *courant){
    
    typeElement *elementTmp;                    //  élément temporaire
    
    if (courant == NULL) {                      //  On veut supprimer l'élément de tête
        elementTmp = *pPremier;                 //  élément temporaire stocke l'adresse de l'élément de tête, celui à supprimer
        *pPremier = elementTmp->suivant;        //  la nouvelle tête est celui qui étaut en 2ème position
    }else{                                      //  SINON, si c'est pas l'élément de tête
        elementTmp = courant->suivant;          //  élément temporaire stocke l'élément à supprimer
        courant->suivant = elementTmp->suivant; //  le nouveau suivant de l'élément courant est celui qui était après celui qu'on supprime
    }
}

//  7.  Imprime toutes les valeurs d'une liste
void printListe(typeElement *pPremier){
    
    typeElement *courant;
    courant = pPremier;
    
    while (courant != NULL) {
        printf("%c", lireValeurElement(courant));
        courant = elementSuivant(courant);
    }
    
    puts("");
}

//  8.  Enleve un element de la liste
//      Resultat VRAI si l'element est dans la liste et FAUX sinon
//      ATTENTION: Cette fonction ne fait que chercher si la valeur est dans la liste
//      Si OUI, elle utilise la primitive "detruireElement" pour la destruction!
int enleverElement(typeElement **premier, typeDonnee val){
    
    int trouve = FAUX;
    typeElement *courant, *precedent;
    
    courant = *premier;                                  //  Positionnement du curseur en tête de liste
    precedent = NULL;                                   //  Au début précédent vaut NULL puique rien avant le premier
    
    while (courant != NULL && !trouve) {
        if (lireValeurElement(courant) == val) {
            trouve = VRAI;
        }else{
            precedent = courant;                        //  On mémoreise l'élément courant
            courant = elementSuivant(courant);          //  On passe au suivant
        }
    }
    
    if (trouve) {
        detruireElement(premier, precedent);            //  Si on a trouvé l'élément avec la valeur, on peut le détruire
    }
    
    return trouve;
}

//  10. Saisie d'un entier
int saisieEntier(){
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

//  11. Afficher menu
void printMenu(){
    
    puts("MENU: ");
    puts("0: Quitter");
    puts("1: Insérer valeur");
    puts("2: Suppriemr valeur");
    puts("3: Afficher liste");
    printf("Choix: ");
}

/***********************************************************
 --------------------------AUTRE----------------------------
 ***********************************************************/

//  1.

