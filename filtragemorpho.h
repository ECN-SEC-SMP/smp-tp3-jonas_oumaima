#include "image.h"
#include "outil.h"

/*
Action dilatation(structure,Nomimage,s)
Paramètre d'entrée : 
- structelem : la structure de l'élément structurant
- string : le nom de l'image à dilater
- unsigned int : valeur de seuillage

But : Elle permet d'effectuer une dilatation sur une image donnée en sauvegardant une nouvelle image avec le préfixe "dilatée_".
*/
string dilatation(structelem *structure, string Nomimage, unsigned int s);
/*
Action erosion(structure,Image,s)
Paramètre d'entrée : 
- structelem : la structure de l'élément structurant
- string : le nom de l'image à dilater
- unsigned int : valeur de seuillage

But : Elle permet d'effectuer une érosion sur une image donnée en sauvegardant une nouvelle image avec le préfixe "erosée_".
*/
string erosion(structelem *structure, string Nomimage, unsigned int s);
/*
Action ouverture(structure,Image,s)
Paramètre d'entrée : 
- structelem : la structure de l'élément structurant
- string : le nom de l'image à dilater
- unsigned int : valeur de seuillage

But : Elle permet d'effectuer une érosion suivie d'une dilatation sur une image donnée en sauvegardant une nouvelle image avec le préfixe "érodée_dilatée_"
*/
string ouverture(structelem *structure, string Nomimage, unsigned int s);
/*
Action fermeture(structure,Image,s)
Paramètre d'entrée : 
- structelem : la structure de l'élément structurant
- string : le nom de l'image à dilater
- unsigned int : valeur de seuillage

But : Elle permet d'effectuer une dilatation suivie d'une érosion sur une image donnée en sauvegardant une nouvelle image avec le préfixe "dilatée_érodée_".
*/
string fermeture(structelem *structure, string Nomimage, unsigned int s);
