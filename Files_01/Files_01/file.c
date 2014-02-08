/*
 * file.cpp : fonctions de gestion d'une file d'entiers
 */
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

typeFile *initFile (int taille) {
	typeFile *file;

	/* Allouer une zone memoire pour la structure file */
	file =  malloc (sizeof (typeFile));
	if (file != NULL) {
		/* Allocation de memoire pour le tableau de pointeurs */
		/* dans lequel seront stockés les noms des personnes */
		file->fileAtt = (typedonnee *) malloc (taille * sizeof(typedonnee));
		if (file->fileAtt != NULL) {
			/* Sommet pointe sur le premier element du tableau alloue */
			file->max = taille; // Nombre max d'elements dans la file
			file->nb = 0;       // Nombre d'elements en attente
			file->premier = 0;
		} else {
			free (file); // Il a été alloué 
			file = NULL;
		}
	}
	return file;
}

int fileVide (typeFile *file) {
	/* retourne 1 s'il n'y a pas d'elements et 0 sinon */
	return (file->nb == 0);
}

int filePleine (typeFile *file) {
	/* retourne 1 si le nombre d'elements est egal au max */
	return (file->nb == file->max);
}

/* Range l'élément en fin de file */
/* Condition d'appel : La file n'est pas pleine */
void ajouteElem (typeFile *file, typedonnee nouveau){
	int dernier;

	/* Calculer l'indice ou ranger le nouveau */
	dernier = (file->premier + file->nb) % file->max;
	file->fileAtt[dernier] = nouveau;
	file->nb++; /* Incrementer le nombre de personnes en attente */
}

/* Résultat : Elément rangé en premier de file */
/* L'élément est enlevé de la file             */
/* Condition d'appel : La file n'est pas vide */
typedonnee suppElem (typeFile *file){
	typedonnee data;

	/* Prendre le nom stocké en premier */
	data = file->fileAtt[file->premier];
	file->premier = (file->premier + 1) % file->max; /* Incrémenter premier*/
	file->nb--;    /* Decrementer le nombre d'elements */
	return data;
}

/* Liberation de la zone memoire allouee pour la file */
void detruireFile (typeFile *file) {
	free (file->fileAtt);
	free (file);
}





