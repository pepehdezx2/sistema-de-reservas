//
//  Software.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Software_h
#define Software_h
#include "Material.h"
#include <iostream>
#include <string>
using namespace std;
class Software : public Material{
public:
    Software();
    Software(int, string, string os);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    string sistema;
};
Software::Software():Material(){
    sistema=" ";
}
Software::Software(int idm, string tit, string os):Material(idm, tit){
    sistema=os;
}
void Software::muestraDatos(){
    cout << "material: software id del material: " << idmat << " titulo: " << titu << " sistema operativo: " << sistema << endl;
}
int Software::cantidadDiasPrestamo(){
    return 1;
}


#endif /* Software_h */
