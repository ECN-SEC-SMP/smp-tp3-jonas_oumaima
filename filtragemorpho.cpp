#include <iostream>
#include "image.h"
#include "outil.h"
#include "chargesauve.h"
using namespace std;

string filtre(t_Image *image,structelem *structure, int j, int i){
    for (int k = 0; k < structure->h; k++){
            for (int l = 0; l < structure->w; l++){
                if ((image->im[j-(structure->y)+k+1][i-(structure->x)+l+1] > 0) && image->im[j][i] == 0){
                    image->im[j][i] = 255;
                }
            }
    }
    return "Filtrée !";
}

string dilatation(structelem *structure, t_Image *image){
    for (int i = 0; i < image->h; i++ ){
        for (int k = 0; k< image->w; k++){
                filtre(image, structure, i, k);
        }
    }  
    return "Dilatée !";
 }
