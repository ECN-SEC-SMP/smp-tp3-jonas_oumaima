#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
using namespace std;

int main(){
    int s;
    //cout << "Nom de l'image :";
    //cin >> Nomimage;
    t_Image *image = new t_Image;
    t_Image *image1 = new t_Image;
    t_Image *image2 = new t_Image;
    bool Ok;
    string Nomimage = "paysage";
    string NomimageExt = Nomimage + ".pgm";
    loadPgm(NomimageExt, image, Ok);

    cout << "Taille de l'image : ";
    cout << image->w << "x" << image->h << endl;

    cout << "Valeur de seuillage : " ;
    cin >> s;
    seuillage(image,s);
    cout << "Sauvegarde de la version seuillée..." << endl;
    savePgm(Nomimage + "_seuillée.pgm",  image);

    cout << endl;
    cout << "Dfférence entre monarch512x512 et mri512x512 pour le pixel (153, 85)  :" << endl;
    cout << "monarch512x512.pgm  :";
    loadPgm("monarch512x512.pgm", image1, Ok);
    cout << "mri512x512  :";
    loadPgm("mri512x512.pgm", image2, Ok);
    cout << "Taille moarch512x512.pgm : "<< image1->w << "x" << image1->h << endl; 
    cout << "Taille mri512x512.pgm : "<< image2->w << "x" << image2->h << endl; 

    cout << "La valeur absolue de la différence des niveaux de gris en (153, 85) est : ";
    cout << diff(image1, image2, 153, 85) << endl;

    delete image;
    delete image1;
    delete image2;
}