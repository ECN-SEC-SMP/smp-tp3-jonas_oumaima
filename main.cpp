#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
using namespace std;

int main(){
    int s;
    string Nomimage;
    //cout << "Nom de l'image :";
    //cin >> Nomimage;
    t_Image *image = new t_Image;
    t_Image *image1 = new t_Image;
    t_Image *image2 = new t_Image;
    bool Ok;
    loadPgm("paysage.pgm", image, Ok);

    cout << "Taille de l'image : ";
    cout << image->w << "x" << image->h << endl;

    cout << "Valeur de seuillage : " ;
    cin >> s;
    seuillage(image,s);
    savePgm(Nomimage + "_seuillée   ",  image);

    cout << "Dfférence entre monarch512x512 et mri512x512" << endl;
    loadPgm("monarch512x512.pgm", image1, Ok);
    loadPgm("mri512x512.pgm", image2, Ok);
    cout << "Taille moarch512x512.pgm : "<< image1->w << "x" << image1->h << endl; 
    cout << "image1 -> h = " << image1->h;
    cout << "Taille mri512x512.pgm : "<< image2->w << "x" << image2->h << endl; 

    diff(image1, image2);

    delete image;
    delete image1;
    delete image2;
}