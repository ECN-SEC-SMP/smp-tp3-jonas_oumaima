#include <iostream>
#include "image.h"
#include "outil.h"
#include "chargesauve.h"
using namespace std;


string dilatation(structelem *structure, string Nomimage, unsigned int s){
    bool Ok;
    t_Image *imageEntree = new t_Image;
    t_Image *imageSortie = new t_Image;

    loadPgm(Nomimage,imageEntree,Ok);
    seuillage(imageEntree, s);

    imageSortie->h = imageEntree->h;
    imageSortie->w = imageEntree->w;

    for (int i = 0; i < imageEntree->h; i++){
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0;
        }
    }


    for (int i = 0; i < imageEntree->h; i++ ){
        for (int k = 0; k< imageEntree->w; k++){
            for (int m = 0; m < structure->h; m++){
                for (int l = 0; l < structure->w; l++){
                    if ((imageEntree->im[i-(structure->y)+m+1][k-(structure->x)+l+1] > 0) && structure->val[m][l] == 1){
                        imageSortie->im[i][k] = 255;
                    }
                }
            }
        }
    }

    savePgm("dilatée_" + Nomimage,imageSortie);  
    delete imageSortie;
    delete imageEntree;   

    return "Dilatée !";
}

string erosion(structelem *structure, string Nomimage, unsigned int s){
    bool Ok;
    t_Image *imageEntree = new t_Image;
    t_Image *imageSortie = new t_Image;

    loadPgm(Nomimage,imageEntree,Ok);
    seuillage(imageEntree, s);


    imageSortie->h = imageEntree->h;
    imageSortie->w = imageEntree->w;

    for (int i = 0; i < imageEntree->h; i++){
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0;
        }
    }

    bool filtreactif = false;
    for (int i = 0; i < imageEntree->h; i++ ){
        for (int k = 0; k< imageEntree->w; k++){
            for (int m = 0; m < structure->h; m++){
                for (int l = 0; l < structure->w; l++){
                    if ((imageEntree->im[i-(structure->y)+m+1][k-(structure->x)+l+1] == 0) && structure->val[m][l] == 1){
                        filtreactif = false;
                        imageSortie->im[i][k] = 0;
                        break;
                    }
                    else{
                        filtreactif = true;
                        imageSortie->im[i][k] = 255;
                    }
                }
            if (filtreactif == false){
                    break;
                }
            }
        }
    }
    savePgm("erosée_"+Nomimage,imageSortie);
    delete imageSortie;
    delete imageEntree;   
    return "Erosée !";
}

string ouverture(structelem *structure, string Nomimage, unsigned int s){
    bool Ok;
    t_Image *imageEntree = new t_Image;
    t_Image *imageSortie = new t_Image;

    loadPgm(Nomimage,imageEntree,Ok);


    imageSortie->h = imageEntree->h;
    imageSortie->w = imageEntree->w;

    for (int i = 0; i < imageEntree->h; i++){
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0;
        }
    }

    erosion(structure,Nomimage, s);
    dilatation(structure, "erosée_" + Nomimage, s);
    delete imageEntree;
    delete imageSortie;
    return "Ouverture effectuée !";
} 

string fermeture(structelem *structure, string Nomimage, unsigned int s){
    bool Ok;
    t_Image *imageEntree = new t_Image;
    t_Image *imageSortie = new t_Image;

    loadPgm(Nomimage,imageEntree,Ok);


    imageSortie->h = imageEntree->h;
    imageSortie->w = imageEntree->w;

    for (int i = 0; i < imageEntree->h; i++){
        for (int j = 0; j < imageEntree->w; j++){
            imageSortie->im[i][j] = 0;
        }
    }

    dilatation(structure,Nomimage, s);
    erosion(structure,"dilatée_" + Nomimage, s);
    delete imageEntree;
    delete imageSortie;
    return "Fermeture effectuée !";
}