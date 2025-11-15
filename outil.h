#include "image.h"
// Fonction seuillage à un niveau s d'une image
// Remplace les pixels d'un niveau de gris inférieur à s par 0 
// Remplace les pixels d'un niveau de gris supérieur à s par 255
void seuillage(t_Image *image, unsigned int s);
// Fonction différence entre deux images de même taille 
// Renvoie la valeur absolue des valeurs de chaque pixels 
int diff(t_Image *image1, t_Image *image2, int i, int j);
