//
//  Disco.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Disco_h
#define Disco_h
#include "Material.h"
#include <iostream>
#include <string>
using namespace std;
class Disco : public Material{
public:
    Disco();
    Disco(int, string, int dura);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    int duracion;
};
Disco::Disco():Material(){
    duracion=0;
}
Disco::Disco(int idm, string tit, int dura):Material(idm, tit){
    duracion=dura;
}
void Disco::muestraDatos(){
    cout << "material: disco id del material: " << idmat << " titulo: " << titu << " duracion: " << duracion << endl;
}
int Disco::cantidadDiasPrestamo(){
    return 3;
}

#endif /* Disco_h */
