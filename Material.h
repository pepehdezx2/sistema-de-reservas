//
//  Material.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Material_h
#define Material_h
#include <iostream>
#include <string>
using namespace std;
class Material{
public:
    Material();
    Material(int idm, string tit);
    void setidMaterial(int idm);
    void setTitulo(string tit);
    int getidMaterial();
    string getTitulo();
    virtual void muestraDatos()=0;
    virtual int cantidadDiasPrestamo()=0;
protected:
    int idmat;
    string titu;
};
Material::Material(){
    idmat=0;
    titu=" ";
}
Material::Material(int idm, string tit){
    idmat=idm;
    titu=tit;
}
void Material::setidMaterial(int idm){
    idmat=idm;
}
void Material::setTitulo(string tit){
    titu=tit;
}
int Material::getidMaterial(){
    return idmat;
}
string Material::getTitulo(){
    return titu;
}
#endif /* Material_h */
