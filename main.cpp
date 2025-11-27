#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
#include "filtragemorpho.h"
using namespace std;

int main(){
    int s;
    bool Ok;

    t_Image *imageseuillage = new t_Image;
    t_Image *imagediff1 = new t_Image;
    t_Image *imagediff2 = new t_Image;


    cout << endl;
    cout << "SEUILLAGE DE L'IMAGE" << endl;
    cout << endl; 

    string Nomimage;
    cout << "Nom de l'image  : ";
    cin >> Nomimage;
    string NomimageExt = Nomimage + ".pgm";

    loadPgm(NomimageExt, imageseuillage, Ok);

    cout << "Taille de l'image : ";
    cout << imageseuillage->w << "x" << imageseuillage->h << endl;

    cout << "Valeur de seuillage : " ;
    cin >> s;
    seuillage(imageseuillage,s);
    cout << "Sauvegarde de la version seuillée..." << endl;
    savePgm("seuillée_" + Nomimage + ".pgm",  imageseuillage);
    
    delete imageseuillage;

    cout << "DIFFERENCE DE NIVEAU DE GRIS ENTRE DEUX IMAGES PAR PIXEL : " << endl;
    cout << endl;
    cout << "Différence entre monarch512x512 et mri512x512 pour le pixel (153, 85)  :" << endl;
    cout << endl;
    cout << "monarch512x512.pgm  : ";
    loadPgm("monarch512x512.pgm", imagediff1, Ok);
    cout << "mri512x512  : ";
    loadPgm("mri512x512.pgm", imagediff2, Ok);

    cout << endl;
    cout << "Taille moarch512x512.pgm : "<< imagediff1->w << "x" << imagediff1->h << endl; 
    cout << "Taille mri512x512.pgm : "<< imagediff2->w << "x" << imagediff2->h << endl; 

    cout << "La valeur absolue de la différence du niveaux de gris en (153, 85) est : ";
    cout << diff(imagediff1, imagediff2, 153, 85) << endl;
    cout << endl;

    delete imagediff1;
    delete imagediff2;

    cout << "OPERATION DE FILTRAGE MORPHOLOGIQUE :" << endl;
    cout << endl;

    cout << "Définition de votre élément structurant en croix : " << endl;

    structelem *structure = new structelem;
    int d;
    int x;
    int y; 


    cout << "Dimension de l'élément structurant : ";
    cin >> d;

    structure->h = d;
    structure->w = d;

    for (int i = 0; i < structure->h; i++){
        for (int j = 0; j < structure->w; j++){
            structure->val[i][j] = 0;
        }
    }

    cout << "Centre de l'élément structurant  : " << endl;

    cout << "x : ";
    cin >> x;
    cout << "y : ";
    cin >> y;
    
    
    structure->x = x;
    structure->y = y;

    for (int i = 0; i < structure->h; i++) {
    structure->val[i][i] = 1;
    structure->val[i][(structure->h)-1-i] = 1;
    } 

    cout << endl;
    cout << "Dilatation : " << endl;
    cout << endl;

    cout << dilatation(structure,NomimageExt,s);


    cout << endl;
    cout << "Erosion : " <<endl;
    cout << endl;

    cout << erosion(structure, NomimageExt,s) << endl;


    delete structure;
    structelem *structure2 = new structelem;
    int s2;
    string Nomimage2;
    d = 0;
    t_Image *image2 = new t_Image;
    
    cout << "Nom de la seconde image : ";
    cin >> Nomimage2;
    string Nomimage2Ext = Nomimage2 + ".pgm";
    loadPgm(Nomimage2Ext,image2, Ok);
    cout << "Nouvelle valeur de seuillage :";
    cin >> s2;
    seuillage(image2,s2);
    savePgm("seuillée_" + Nomimage2 + ".pgm",  image2);
    delete image2;
    cout << "Dimension du second élément structurant : ";
    cin >> d;

    
    structure2->h = d;
    structure2->w = d;

    cout << "Centre du sencond élément structurant : " << endl;

    cout << "x : ";
    cin >> x;
    cout << "y : ";
    cin >> y;
    
    
    structure2->x = x;
    structure2->y = y;

    for (int i = 0; i < structure2->h; i++){
        for (int j = 0; j < structure2->w; j++){
            structure2->val[i][j] = 0;
        }
    }

    for (int i = 0; i < structure2->h; i++) {
        structure2->val[i][i] = 1;
        structure2->val[i][(structure2->h)-1-i] = 1;
    } 


    cout << endl;
    cout << "Ouverture : " <<endl;
    cout << endl;

    cout << ouverture(structure2, Nomimage2Ext, s2) << endl;


    cout << endl;
    cout << "Fermeture : " <<endl;
    cout << endl;

    cout << fermeture(structure2, Nomimage2Ext, s2) << endl;
} 