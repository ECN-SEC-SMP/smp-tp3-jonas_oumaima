#include <iostream>
#include "image.h"
#include "outil.h"
#include "chargesauve.h"
using namespace std;


string dilatation(structelem *structure, string Nomimage, unsigned int s){
    
    // Initialisation des parametres avant la dilatation

    bool Ok; // Initialisation du booléen pour load une image
    t_Image *imageEntree = new t_Image; // Allocation mémoire pour l'image d'entree
    t_Image *imageSortie = new t_Image; // Allocation mémoire pour l'image de sortie

    loadPgm(Nomimage,imageEntree,Ok); // Chargement de l'image à dilater
    seuillage(imageEntree, s); // Seuillage de l'image (nécessaire pour la dilatation)

    imageSortie->h = imageEntree->h; // Affectation de la hauteur de l'image de sortie
    imageSortie->w = imageEntree->w; // Affectation de la largeur de l'image de sortie

    for (int i = 0; i < imageEntree->h; i++){ // Initialisation de l'image de sortie
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0; // Image rempli de 0
        }
    }

    // Dilatation : On verifie si l'ES "tient" au moins un pixel allumé
    // Si oui, on allume le pixel de sortie concernée (i,k)

    for (int i = 0; i < imageEntree->h; i++ ){ // Déplacement sur la hauteur de l'image d'entrée
        for (int k = 0; k< imageEntree->w; k++){ // Déplacement sur la largeur de l'image d'entrée
            for (int m = 0; m < structure->h; m++){ // Déplacement sur la hauteur de l'élément structurant
                for (int l = 0; l < structure->w; l++){ // Déplacement sur la largeur de l'élément structurant

                    // Analyse de la valeur prise des pixels voisin du pixel (i,k)
                    if ((imageEntree->im[i-(structure->y)+m+1][k-(structure->x)+l+1] > 0) && structure->val[m][l] == 1){
            // Si au moins un pixel voisin est allumée et qu'en même temps le pixel de l'élément structurant vaut 1
                        imageSortie->im[i][k] = 255; // Le pixel concerné s'allume
                    }
                }
            }
        }
    }

    savePgm("dilatée_" + Nomimage,imageSortie);  // Sauvegarde de la version dilatée de l'imageEntree
    delete imageSortie; // Suppression de l'image de sortie de la mémoire
    delete imageEntree; // Suppression de l'image d'entrée de la mémoire

    return "Dilatée !"; // Validation de la procédure de dilatation
}

string erosion(structelem *structure, string Nomimage, unsigned int s){

    // Initialisation des parametres avant l'érosion (similaire à la dilatation)

    bool Ok; // Initialisation du booléen pour load une image
    t_Image *imageEntree = new t_Image; // Allocation mémoire pour l'image d'entree
    t_Image *imageSortie = new t_Image; // Allocation mémoire pour l'image de sortie

    loadPgm(Nomimage,imageEntree,Ok); // Chargement de l'image à dilater
    seuillage(imageEntree, s); // Seuillage de l'image (nécessaire pour l'érosion)

    imageSortie->h = imageEntree->h; // Affectation de la hauteur de l'image de sortie
    imageSortie->w = imageEntree->w; // Affectation de la largeur de l'image de sortie

    for (int i = 0; i < imageEntree->h; i++){ // Initialisation de l'image de sortie
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0; // Image rempli de 0
        }
    }

    // Érosion : pour chaque pixel, on vérifie si l'ES "tient" entièrement sur des pixels allumés.
    // Si oui, on allume le pixel de sortie (i,k)

    bool filtreactif = false; // Initialisation booléen de l'etat de l'ES, true si tous les pixels de l'ES sont allumé sur l'image d'enrée
    for (int i = 0; i < imageEntree->h; i++ ){ // Déplacement sur la hauteur de l'image d'entrée 
        for (int k = 0; k< imageEntree->w; k++){ // Déplacement sur la largeur de l'image d'entrée
            for (int m = 0; m < structure->h; m++){ // Déplacement sur la hauteur de l'ES
                for (int l = 0; l < structure->w; l++){ // Déplacement sur la largeur de l'ES
                    if ((imageEntree->im[i-(structure->y)+m+1][k-(structure->x)+l+1] == 0) && structure->val[m][l] == 1){
    // Si au moins un pixels de l'ES n'est pas dans le même état que l'image d'entrée 
                        filtreactif = false; // Le pixel (i, k) n'est pas "validé" 
                        imageSortie->im[i][k] = 0; // Le pixel (i,k) ne vaut pas la peine d'être allumé
                        break; // Arrêt du déplacement dans la largeur de l'ES (condition non validée)
                    }
    // L'ES et l'image d'entree sont dans le même etat, le pixel (i,k) est validé
                    else{ 
                        filtreactif = true; // Validation du pixel pour continuer le déplacement dans l'ES
                        imageSortie->im[i][k] = 255; // Allumage du pixel 
                    }
                }
            if (filtreactif == false){
                    break; // Arrêt du déplacement dans la hauteur de l'ES (condition non validée)
                }
            }
        }
    }
    savePgm("érodée_"+Nomimage,imageSortie); // Sauvegarde de l'image érodée
    delete imageSortie; // Suppression de l'image de sortie de la mémoire
    delete imageEntree;  // Suppression de l'image d'entrée de la mémoire
    return "Erodée !"; // Validation de l'érosion
}

string ouverture(structelem *structure, string Nomimage, unsigned int s){
    // Initialisation des parametres avant l'érosion (similaire à la dilatation et l'érosion)

    bool Ok; // Initialisation du booléen pour load une image
    t_Image *imageEntree = new t_Image; // Allocation mémoire pour l'image d'entree
    t_Image *imageSortie = new t_Image; // Allocation mémoire pour l'image de sortie

    loadPgm(Nomimage,imageEntree,Ok); // Chargement de l'image à dilater
    seuillage(imageEntree, s); // Seuillage de l'image (nécessaire pour l'érosion et la dilatation)

    imageSortie->h = imageEntree->h; // Affectation de la hauteur de l'image de sortie
    imageSortie->w = imageEntree->w; // Affectation de la largeur de l'image de sortie

    for (int i = 0; i < imageEntree->h; i++){ // Initialisation de l'image de sortie
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0; // Image rempli de 0
        }
    }


    erosion(structure,Nomimage, s); // Erosion de l'image d'entrée
    dilatation(structure, "érodée_" + Nomimage, s); // Dilatation de l'image d'entrée érodée
    delete imageEntree; // Suppression de l'image d'entrée
    delete imageSortie;// Suppression de l'image de sortie
    return "Ouverture effectuée !";// Validation de l'ouverture
} 

string fermeture(structelem *structure, string Nomimage, unsigned int s){
    // Initialisation des parametres avant l'érosion (similaire à la dilatation et l'érosion)

    bool Ok; // Initialisation du booléen pour load une image
    t_Image *imageEntree = new t_Image; // Allocation mémoire pour l'image d'entree
    t_Image *imageSortie = new t_Image; // Allocation mémoire pour l'image de sortie

    loadPgm(Nomimage,imageEntree,Ok); // Chargement de l'image à dilater
    seuillage(imageEntree, s); // Seuillage de l'image (nécessaire pour l'érosion et la dilatation)

    imageSortie->h = imageEntree->h; // Affectation de la hauteur de l'image de sortie
    imageSortie->w = imageEntree->w; // Affectation de la largeur de l'image de sortie

    for (int i = 0; i < imageEntree->h; i++){ // Initialisation de l'image de sortie
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0; // Image rempli de 0
        }
    }


    dilatation(structure,Nomimage, s);// Dilatation de l'image d'entrée
    erosion(structure,"dilatée_" + Nomimage, s);// Erosion de l'image d'entrée dilatée
    delete imageEntree; // Suppression de l'image d'entrée
    delete imageSortie; // SUppression de l'image de sortie
    return "Fermeture effectuée !"; // Validation de la fermeture
}