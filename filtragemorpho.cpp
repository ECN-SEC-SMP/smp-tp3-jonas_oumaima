#include <iostream>
#include "image.h"
#include "outil.h"
#include "chargesauve.h"
using namespace std;


string dilatation(structelem *structure, t_Image *image){
    for (int i = 0; i < image->h; i++ ){
        for (int k = 0; k< image->w; k++){
            for (int m = 0; m < structure->h; m++){
                for (int l = 0; l < structure->w; l++){
                    if ((image->im[i-(structure->y)+m+1][k-(structure->x)+l+1] > 0) && image->im[i][k] == 0){
                        image->im[i][k] = 255;
                    }
                }
            }
        }
    }  
    return "Dilatée !";
 }
