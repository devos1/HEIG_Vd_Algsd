/*
 * arbres.cpp
 * Creation des noeuds de l'arbre binaire
 * representant une expression arithmétique
 * Parcours infixé avec parenthèsage
 * Parcours préfixé
 * Evaluation de l'expression arithmétique
 */
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

/* Creer une feuille de l'arbre */
typeNoeud *creerFeuille(int val) {
  typeNoeud *noeud;

  noeud = (typeNoeud *)malloc (sizeof (typeNoeud));
  if (noeud != NULL) {
	  noeud->data.val = val;
	  noeud->gauche = NULL;
	  noeud->droit = NULL;
  }
  return (noeud);
}

/* Creer un noeud de l'arbre */
typeNoeud *creerNoeud (char oper, typeNoeud *gauche, 
					              typeNoeud *droit) {
  typeNoeud *noeud;

  noeud = (typeNoeud *) malloc (sizeof (typeNoeud));
  if (noeud != NULL) {
	  noeud->data.oper = oper;
	  noeud->gauche = gauche;
	  noeud->droit = droit;
  }
  return (noeud);
}

/* Parcours infixe de l'arbre avec impression de 
 * l'expression infixee completement parenthesee
 */
void infixe (typeNoeud *noeud) {
	if (noeud != NULL) {
		if (noeud->gauche == NULL) {
			/* On a une feuille */
			printf ("%d",noeud->data.val);
		} else {
			/* On a un noeud */
			printf ("(");
			infixe (noeud->gauche); /* Parcours infixe du sous arbre gauche */
			printf ("%c",noeud->data.oper); /* Impression du noeud */
			infixe (noeud->droit);  /* Parcours infixe du sous arbre droit */
			printf (")");
		}
	}
}

/* Parcours prefixe de l'arbre */
void prefixe (typeNoeud *noeud) {
	if (noeud != NULL) {
		if (noeud->gauche == NULL) {
			/* On a une feuille */
			printf ("%d ",noeud->data.val);
		} else {
			/* On a un noeud */
			printf ("%c ",noeud->data.oper); /* Impression du noeud */
			prefixe (noeud->gauche); /* Parcours infixe du sous arbre gauche */
			prefixe (noeud->droit);  /* Parcours infixe du sous arbre droit */
		}
	}
}

/* Evaluation de l'expression postfixée */
int eval (typeNoeud *noeud) {
	int res;
	int valg, vald;

	if (noeud != NULL) {
		/* Est-ce une feuille ? */
		if (noeud->droit == NULL && noeud->gauche == NULL) {
			res = noeud->data.val;
		} else {
			valg = eval (noeud->gauche);
			vald = eval (noeud->droit);
			switch (noeud->data.oper) {
			case '+' :
				res = valg + vald;
				break;
			case '-' :
				res = valg - vald;
				break;
			case '*' :
				res = valg * vald;
				break;
			case '/' :
				res = valg / vald;
			}
		}
	}
	return res;
}
