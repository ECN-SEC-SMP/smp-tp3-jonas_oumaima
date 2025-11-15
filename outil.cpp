#include <iostream>
#include <fstream>
#include <string>
#include "chargesauve.h"
#include "image.h"
#include <assert.h>
using namespace std;

void seuillage(t_Image * image, int s){
    for (int i = 0; i < image->h; i++ ){
        for (int k = 0; k< image ->w; k++){
            if (image->im[i][k] < s){
                image->im[i][k] = 0;
            }
            else {
                image->im[i][k] = 255;
            }
        }
    }
}

int diff(t_Image *image1, t_Image *image2, int i, int j){
    assert(image1->h == image2->h && image1->w == image2->w);
    int d = 0;
    d = image1->im[i][j] - image2->im[i][j];
    if (d < 0){
        return -d;
    }
    else {
        return d;
    }
}
