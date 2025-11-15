#include <iostream>
#include "image.h"
#include "outil.h"
#include "chargesauve.h"
using namespace std;


string dilatation(structelem *structure, t_Image *image, int s){
    seuillage(image,s);
    for (int i = 0; i < image->h; i++ ){
        for (int k = 0; k< image->w; k++){
           if (image->im[i][k] == 255){
                for (int j = 0; j< structure->h; j++){
                    for (int n = 0; n< structure->w; n++){
                        if (structure->val[j][n] == 1){
                            image->im[(structure->y)+j][(structure->x)+n] = structure->val[j][n]*255;
                        }
                    }
                } 
            }
        }
    }
    return "Dilatée !";
}   
