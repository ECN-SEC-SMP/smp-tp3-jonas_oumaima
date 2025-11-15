#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
#include "filtragemorpho.h"
using namespace std;

int main(){
    int s;

    t_Image *imageseuillage = new t_Image;
    t_Image *imagediff1 = new t_Image;
    t_Image *imagediff2 = new t_Image;
    t_Image *imagedilat = new t_Image;
    bool Ok;
    string Nomimage;
    cout << "Nom de l'image :";
    cin >> Nomimage;
    string NomimageExt = Nomimage + ".pgm";
    structelem *structure = new structelem;

    for (int i = 0; i < structure->h; i++){
        for (int j = 0; j < structure->w; j++){
            structure->val[i][j] = 0;
        }
    }
    
        


    loadPgm(NomimageExt, imageseuillage, Ok);

    cout << "Taille de l'image : ";
    cout << imageseuillage->w << "x" << imageseuillage->h << endl;

    cout << "Valeur de seuillage : " ;
    cin >> s;
    seuillage(imageseuillage,s);
    cout << "Sauvegarde de la version seuillée..." << endl;
    savePgm(Nomimage + "_seuillée.pgm",  imageseuillage);

    cout << endl;
    cout << "Dfférence entre monarch512x512 et mri512x512 pour le pixel (153, 85)  :" << endl;
    cout << "monarch512x512.pgm  :";
    loadPgm("monarch512x512.pgm", imagediff1, Ok);
    cout << "mri512x512  :";
    loadPgm("mri512x512.pgm", imagediff2, Ok);
    cout << "Taille moarch512x512.pgm : "<< imagediff1->w << "x" << imagediff1->h << endl; 
    cout << "Taille mri512x512.pgm : "<< imagediff2->w << "x" << imagediff2->h << endl; 

    cout << "La valeur absolue de la différence du niveaux de gris en (153, 85) est : ";
    cout << diff(imagediff1, imagediff2, 153, 85) << endl;

    cout << "Définition de votre élément de structure  : " << endl;
    structure->h = 3;
    structure->w = 3;
    structure->x = 1;
    structure->y = 1;

    structure->val[0][0]=0;
    structure->val[0][1]=1;
    structure->val[1][1]=1;
    structure->val[1][0]=1;
    structure->val[0][2]=0;
    structure->val[2][2]=0;
    structure->val[2][0]=0;
    structure->val[1][2]=1;
    structure->val[2][1]=1;
    cout << endl;
    cout << "Dilatation : " << endl;

    loadPgm(Nomimage + "_seuillée.pgm",imagedilat,Ok);
    cout << "structure->h = " << structure->h << ", structure->w = " << structure->w << endl;
    cout << "Taille image : " << imagedilat->h << " x " << imagedilat->w << endl;
    cout << "Premier pixel : " << imagedilat->im[0][0] << endl;
    cout << dilatation(structure,imagedilat,s);
    savePgm(Nomimage + "_dilatée",imagedilat);


    delete imageseuillage;
    delete imagediff1;
    delete imagediff2;
    delete imagedilat;
    delete structure;
}