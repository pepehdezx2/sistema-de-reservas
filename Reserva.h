//
//  Reserva.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h
#include "Fecha.h"
#include <iostream>
#include <string>
using namespace std;
class Reserva{
public:
    Reserva();
    Reserva(int idm, int idc, Fecha fr);
    void setMaterial(int);
    void setCliente(int);
    void setFechaReservacion(Fecha);
    int getMaterial();
    int getCliente();
    Fecha getFechaReservacion();
    Fecha calculaFechaFinReserva(int di);
private:
    int idmat, idcl;
    Fecha fechar;
};
Reserva::Reserva(){
    Fecha x(0, 0, 0);
    idmat=0;
    idcl=0;
    fechar=x;
}
Reserva::Reserva(int idm, int idc, Fecha fr){
    idmat=idm;
    idcl=idc;
    fechar=fr;
}
void Reserva::setCliente(int idcl){
    this->idcl=idcl;
}
void Reserva::setMaterial(int idmat){
    this->idmat=idmat;
}
void Reserva::setFechaReservacion(Fecha fr){
    this->fechar=fechar;
}
int Reserva::getCliente(){
    return idcl;
}
int Reserva::getMaterial(){
    return idmat;
}
Fecha Reserva::getFechaReservacion(){
    return fechar;
}
Fecha Reserva::calculaFechaFinReserva(int di){
    int year, month, day, dias;
    dias=di;
    year=fechar.getYear();
    month=fechar.getMonth();
    day=fechar.getDay();
    if(month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day+dias>31){
            day-=31;
            month+=1;
            if(month>12)
            {
                month=1;
                year+=1;
            }
        }
        else
            day+=dias;
    }
    else
        if(month == 2){
            if(year%4==0){
                if(day+dias>29)
                {
                    day-=29;
                    month+=1;
                }
                else
                    day+=dias;
            }
            else{
                if(day+dias>28){
                    day-=28;
                    month+=1;
                }
                else
                    day+=dias;
            }
        }
        else
            if(day+dias>30){
                day-=30;
                month+=1;
            }
            else
                day+=dias;
    Fecha x(day, month, year);
    return x;
}
#endif /* Reserva_h */
