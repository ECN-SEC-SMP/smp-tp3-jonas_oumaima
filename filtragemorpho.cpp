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

string erosion(structelem *structure, t_Image *image){
    for (int i = 0; i < image->h; i++ ){
        for (int k = 0; k< image->w; k++){
            for (int m = 0; m < structure->h; m++){
                for (int l = 0; l < structure->w; l++){
                    if ((image->im[i-(structure->y)+m+1][k-(structure->x)+l+1] < 255) && image->im[i][k] == 255){
                        image->im[i][k] = 0;
                    }
                }
            }
        }
    }  
    return "Erosée !";
    
}

string ouverture(string Nomimage,structelem *structure, t_Image *image){
    bool Ok;
    loadPgm(Nomimage,image, Ok);
    erosion(structure,image);
    dilatation(structure,image);
    savePgm(Nomimage + "_ouverture.pgm",image);
    return "Ouverture effectuée !";
} 

string fermeture(string Nomimage,structelem *structure, t_Image *image){
    bool Ok;
    loadPgm(Nomimage,image, Ok);
    dilatation(structure,image);
    erosion(structure,image);
    savePgm(Nomimage + "_fermeture.pgm",image);
    return "Fermeture effectuée !";
} 