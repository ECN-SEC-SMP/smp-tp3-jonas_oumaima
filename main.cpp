#include <iostream>
#include "outil.h"
#include "chargesauve.h"
#include "image.h"
#include <string>
using namespace std;

void main(){
    string Nomimage;
    cout << "Nom de l'image :";
    cin >> Nomimage;
    t_Image * image;
    bool Ok;
    loadPgm(Nomimage, image, Ok);


}