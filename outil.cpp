#include <iostream>
#include <fstream>
#include <string>
#include "chargesauve.h"
#include "image.h"
#include <assert.h>
using namespace std;


void seuillage(t_Image * image, unsigned int s){
    for (int i = 0; i < image->h; i++ ){ // On parcourt l'ensemble des pixels de l'image
        for (int k = 0; k< image ->w; k++){
            if (image->im[i][k] < s){ // On verifie si le niveau de gris est inferieur à la valeur de seuillage
                image->im[i][k] = 0; // Si oui : le niveau de gris passe à 0
            }
            else {
                image->im[i][k] = 255; // Sinon : le niveau de gris passe à 255
            }
        }
    }
}

int diff(t_Image *image1, t_Image *image2, int i, int j){
    assert(image1->h == image2->h && image1->w == image2->w); // On vérifie bien que les deux images sont de même taille
    int d = 0; // On initialise la valeur de la difference 
    d = image1->im[i][j] - image2->im[i][j]; // on calcule la différence des niveau de gris 
    if (d < 0){
        return -d; // On renvoie l'opposé de la valeur si d < 0, pour que ce soit positif
    }
    else {
        return d; // On renvoie la valeur si d > 0
    }
}
