#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
using namespace std;

int main(){
    int s;
    string Nomimage;
    cout << "Nom de l'image :";
    cin >> Nomimage;
    t_Image image;
    bool Ok;
    loadPgm(Nomimage, &image, Ok);

    cout << "Taille de l'image : ";
    cout << image.w << "x" << image.h << endl;

    cout << "Valeur de seuillage : " ;
    cin >> s;
    seuillage(&image,s);
    savePgm(Nomimage + "_seuillé",  &image);

}