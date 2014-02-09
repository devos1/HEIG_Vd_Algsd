//
//  fonctions.c
//  Liste_Chainee_Tests
//
//  Created by Oscar on 09.02.14.
//  Copyright (c) 2014 Oscar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


#define VRAI 1
#define FAUX 0

/***********************************************************
 FONCTIONS LISTES CHAINEES
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
void printListeChar(typeElement *pPremier){
    
    typeElement *courant;
    courant = pPremier;
    
    while (courant != NULL) {
        printf("%c", lireValeurElement(courant));
        courant = elementSuivant(courant);
    }
    
    puts("");
}

//  7.1  Imprime toutes les valeurs d'une liste
void printListeInt(typeElement *pPremier){
    
    typeElement *courant;
    courant = pPremier;
    
    while (courant != NULL) {
        printf("%d ", lireValeurElement(courant));
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

//  9.  Detruire une liste
void detruireListe(typeElement **premier){
    
    while (*premier != NULL) {
        detruireElement(premier, NULL);            //  Destruction à chaque fois du premier de la liste
    }
}

//  10. Insérer un élément directement dans l'ordre croissant
//      Rend VRAI si insertion  OK, FAUX sinon
int insereEltOrdreC (typeElement **premier, typeDonnee val){
    typeElement *precedent, *courant, *nouveau;
    int retour = FAUX;
    int trouve = FAUX;
    
    courant = *premier;      //Se placer en tête de liste
    precedent = NULL;
    
    while (courant != NULL && !trouve) {
        if (val <= lireValeurElement(courant)) {
            trouve = VRAI;
        }else{
            precedent = courant;                        //On mémorise le courant
            courant = elementSuivant(courant);          //On passe au suivant
        }
        
    }
    
    // A la fin de la boucle precedent pointe sur l'élément derrière lequel
	// on doit insèrer un nouvel élément ou est Ègal à NULL si on insère
	// en début de liste
    nouveau = creerElement(val);
    
    if (nouveau != NULL) {
        insererElement(premier, precedent, nouveau);      //Le courant est precedent car on veut insère avan le vrai courant
        retour = VRAI;                                  //étant donné qu'on veut insèrer dans l'ordre croissant!!
    }
    
    return retour;
}

//  11. Passer les valeurs d'un tableau d'entiers vers une nouvelle liste d'entiers
//      Retourne un pointeur sur la nouvelle liste
typeElement *iArrayTolist(const int tab[], int taille){
    
    typeElement *premier, *courant, *nouveau;
    int i = 0;
    
    //Init nouvelle liste
    initListe(&premier);
    courant = NULL;
    nouveau = NULL;
    
    for (i = 0; i < taille; i++) {
        nouveau = creerElement(tab[i]);
        insererElement(&premier, courant, nouveau);
        courant = nouveau;
    }
    
    return premier;
}

//  12. Fusion de 2 listes en gardant l'ordre croissant
//      RESULTAT: pointeur sur la nouvelle liste
typeElement *fusionListe(typeElement *liste1, typeElement *liste2){
    
    typeElement *listeFusionee, *courant1, *courant2, *courant3, *nouveau;
    typeDonnee val1, val2;
    
    //Initialiser la nouvelle liste
    initListe(&listeFusionee);
    
    //Initialiser les pointeurs sour les curseurs
    courant1 = liste1;
    courant2 = liste2;
    courant3 = NULL;
    
    while (courant1 != NULL && courant2 != NULL) {
        val1 = lireValeurElement(courant1);
        val2 = lireValeurElement(courant2);
        nouveau = creerElement(iMin(val1, val2));                   //Création d'un nouvel élément en prennant le plus petite des 2 listes
        insererElement(&listeFusionee, courant3, nouveau);
        courant3 = nouveau;
        
        if (val1 < val2) {                                          //On fait avancer le curseur sur le nb le plus petit
            courant1 = elementSuivant(courant1);
        }else{
            courant2 = elementSuivant(courant2);
        }
    }
    
    //Raccorder la fin de la dernière liste
    if (courant2 != NULL) {                                         //Cette étape consiste dans le cas ou la liste 1 est plus petite que la 2 à
        courant1 = courant2;                                        //Le pointeur de la 1 récupère le pointeur de la 2 et avance comme si c'était courant2
    }                                                               //Si c'est la 2 qui est plus petite, rien besoin de faire, on passe directe à la suite
    while (courant1 != NULL) {                                      //Et courant1 finit le parcours de sa liste
        val1 = lireValeurElement(courant1);
        nouveau = creerElement(val1);
        insererElement(&listeFusionee, courant3, nouveau);
        courant3 = nouveau;
        courant1 = elementSuivant(courant1);
    }
    
    return listeFusionee;
}

//  13. Concaténation de 2 listes (la liste 2 à la suite de la liste 1
void concatListe(typeElement **liste1,typeElement *liste2){
    
    typeElement *courant;
    
    if (*liste1 == NULL) {                          //Si la liste 1 est vide, on pointe directement sur la 2ème
        *liste1 = liste2;
    }else{                                          //Si la liste n'est pas vide
        courant = *liste1;
        while (courant->suivant != NULL) {
            courant = courant->suivant;             //On avance dans la liste jusqu'à trouver le dernier éléments
        }
        courant->suivant = liste2;                  //On attache la liste 2 à la liste1
    }
}

/***********************************************************
 FONCTIONS DIVERSES
 ***********************************************************/

//  20. Saisie d'un entier
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

//  21. Afficher menu
void printMenu(){
    puts("MENU: ");
    puts("0: Quitter");
    puts("1: Insérer valeur");
    puts("2: Suppriemr valeur");
    puts("3: Afficher liste");
    printf("Choix: ");
}

//  22. Afficher menu exercices
void printMenuEx(){
    puts("MENU: ");
    puts("0: Quitter");
    puts("1: Exercice 1 - liste de caractères");
    puts("2: Exercice 2 - liste d'entiers isérés par ordre croissante");
    printf("Choix: ");
}

//  23. Imprimer un tableau
void printTableau(int tableau[], int n){
    
	int i;
    
	for (i = 0; i < n; i++)
	{
		printf("%d ", tableau[i]);
	}
	puts("");
}

//  24. Retourne le MIN de 2 entier
int iMin(int nb1, int nb2){
    
    if (nb1 < nb2) {
        return  nb1;
    }else{
        return  nb2;
    }
}

