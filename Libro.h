//
//  Libro.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Libro_h
#define Libro_h
#include "Material.h"
#include <iostream>
#include <string>
using namespace std;
class Libro : public Material{
public:
    Libro();
    Libro(int, string, int num, string aut);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    int numpag;
    string autor;
};
Libro::Libro():Material(){
    numpag=0;
    autor=" ";
}
Libro::Libro(int idm, string tit, int num, string aut):Material(idm, tit){
    numpag=num;
    autor=aut;
}
void Libro::muestraDatos(){
    cout << "material: libro id del material: " << idmat << " titulo: " << titu << " numero de paginas: " << numpag << " autor: " << autor << endl;
}
int Libro::cantidadDiasPrestamo(){
    return 10;
}
#endif /* Libro_h */
