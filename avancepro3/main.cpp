//
//  main.cpp
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Reserva.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void cargaM(ifstream &archent, Material *arrma[], int &cont, char arrch[]){
    int iId;
    char tipo;
    string meanws, titu;
    int meanwi;
    while(archent>>iId){
        archent>>titu;
        archent>>tipo;
        arrch[cont]=tipo;
        if (tipo == 'L'){
            archent>>meanwi;
            archent>>meanws;
            arrma[cont]=new Libro(iId, titu, meanwi, meanws);
        }
        else
            if (tipo == 'D'){
                archent>>meanwi;
                arrma[cont]= new Disco(iId, titu, meanwi);
            }
        else
            if (tipo == 'S'){
                archent>>meanws;
                arrma[cont]= new Software(iId, titu, meanws);
            }
        cont++;
    }
}


void cargaR(ifstream &fRes, Reserva arrr[], int &cont){
    Reserva rRes;
    Fecha fa;
    int d, m, y, idm, idc;
    while(fRes>>d){
        fRes>>m>>y>>idm>>idc;
        rRes.setMaterial(idm);
        rRes.setCliente(idc);
        fa.setFecha(d, m, y);
        rRes.setFechaReservacion(fa);
        arrr[cont]=rRes;
        cont++;
    }
}

bool materialV(int cont, int iId, Material *arrma[]){
    bool band=false;
    for(int i=0; i<cont; i++){
        if(arrma[i]->getidMaterial()==iId){
            band=true;
            i=cont;
        }
    }
    return band;
}

bool fechaV(Fecha fa){
    bool band=true;
    int dotm[12]={31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31};
    if(fa.getYear()%4==0){
        dotm[1]++;
    }
    if(fa.getMonth()>12){
        cout << "este mes no exisate, intente de nuevo" << endl;
        band=false;
    }
    else
        if(fa.getDay()>dotm[fa.getMonth()-1]){
            cout << "el mes cuenta con " << dotm[fa.getMonth()-1] << " dias, intente de nuevo" << endl;
            band=false;
        }
    else
        if(fa.getDay()<1 || fa.getMonth()<1 || fa.getYear()<1){
            cout << "no se encuentra en el rango" << endl;
            band=false;
        }
    return band;
}

int itoindex(int iId, int cma, Material *arrma[]){
    int ind;
    for (int i=0; cma; i++){
        if(iId==arrma[i]->getidMaterial()){
            ind=i;
            i=cma;
    }
    }
    return ind;
    }

void mostrarM(int cont, char arrch[], Material *arrma[]){
    for(int i=0; i<cont; i++){
        arrma[i]->muestraDatos();
        cout<<endl;
    }
}

void mostrarR(int contres, int cma, Reserva arrr[], Material *arrma[]){
    int ind;
    for (int i=0; i < contres; i++){
        ind=itoindex(arrr[i].getMaterial(), cma, arrma);
        cout << "Inicio de reserva " << arrr[i].getFechaReservacion() << " final de reserva " << arrr[i].calculaFechaFinReserva(arrma[ind]->cantidadDiasPrestamo()) << " id " << arrr[i].getCliente() << " titulo " << arrma[ind]->getTitulo() << endl;
    }
}

void mostrarRM(int contres, int cma, int matid, Reserva arrr[], Material *arrma[]){
    int ind;
    bool band=false;
    for(int i=0; i<contres; i++){
        ind=itoindex(arrr[i].getMaterial(), cma, arrma);
        if(arrr[i].getMaterial()==matid){
            cout << "inicio de reserva " << arrr[i].getFechaReservacion() << " fin de la reservacion " << arrr[i].calculaFechaFinReserva(arrma[ind]->cantidadDiasPrestamo()) << " id " << arrr[i].getCliente() << " titulo " << arrma[ind]->getTitulo() << endl;
            band=true;
        }
    }
    if (!(band)){
        cout << "no existe el material con el id " << matid << endl;
    }
}

void mostrarRF(int contres, int cma, Fecha fx, Reserva arrr[], Material *arrma[]){
    int ind;
    bool band=false;
    for (int i=0; i<contres; i++){
        ind=itoindex(arrr[i].getMaterial(), cma, arrma);
        if(fx >= arrr[i].getFechaReservacion() && fx <= arrr[i].calculaFechaFinReserva(arrma[ind]->cantidadDiasPrestamo())){
            cout << "inicio de reserva " << arrr[i].getFechaReservacion() << " fin de la reservacion " << arrr[i].calculaFechaFinReserva(arrma[ind]->cantidadDiasPrestamo()) << " id " << arrr[i].getCliente() << " titulo " << arrma[ind]->getTitulo() << endl;
            band=true;
    }
}
    if (!(band)){
       cout << "no existe el material reservado con la fecha " << fx << endl;
    }
}

bool disponible(int contres, int cma, int iId, Fecha fa, Reserva arrr[], Material *arrma[]){
    int ind;
    bool band=true;
    Fecha ff;
    for(int i=0; i<contres; i++){
        if(arrr[i].getMaterial()==iId){
        ind=itoindex(arrr[i].getMaterial(), cma, arrma);
        ff=arrr[i].calculaFechaFinReserva(arrma[ind]->cantidadDiasPrestamo());
        if(fa >= arrr[i].getFechaReservacion() && fa <= ff){
            band=false;
        }
        }
    }
    if(!(band)){
        cout << "No se puede separar para esa fecha" << endl;
    }
    return band;
}

int main(){
    int cma=0, contres=0, cont, meanwi, meanwo;
    Fecha fx;
    char opc;
    char arrch[20];
    Material *arrma[20];
    Reserva arrr[50];
    ifstream archent("Materiales.txt");
    cargaM(archent, arrma, cma, arrch);
    archent.close();
    ifstream fRes("Reserva.txt");
    cargaR(fRes, arrr, contres);
    fRes.close();
    cout << "sistema de reservaciones" << endl;
    do{
        cout << "Presione A para Consultar los materiales disponibles" << endl;
        cout << "Presione B para mostrar todas las reservaciones" << endl;
        cout << "Presione C para mostrar las reservaciones de un material" << endl;
        cout << "Presione D para mostrar materiales en reserva en una fecha" << endl;
        cout << "Presione E para hacer una reservacion" << endl;
        cout << "Presione cualquier otra cosa para salir y guardar" << endl;
        cin >> opc;
        switch (opc){
            case 'A':
                mostrarM(cma, arrch, arrma);
                cout << endl;
                break;
            case 'B':
                mostrarR(contres, cma, arrr, arrma);
                cout << endl;
                break;
            case 'C':
                cout << "Id a revisar" << endl;
                cin >> cont;
                while(!(materialV(cma, cont, arrma))){
                    cout << "Id no valido ingrese de nuevo" << endl;
                    cin >> cont;
                }
                mostrarRM(contres, cma, cont, arrr, arrma);
                cout << endl;
                break;
            case 'D':
                cout << "Fecha dd mm aaaa" << endl;
                int d, m, a;
                cin >> d;
                cin >> m;
                cin >> a;
                fx.setFecha(d, m, a);
                while(!(fechaV(fx))){
                    cin >> fx;
                }
                mostrarRF(contres, cma, fx, arrr, arrma);
                cout << endl;
                break;
            case 'E':
                cout << "Id del cliente" << endl;
                cin >> meanwi;
                cout << "Id del material" << endl;
                cin >> meanwo;
                while(!(materialV(cma, meanwo, arrma))){
                    cout << "Id no valido intenta de nuevo" << endl;
                    cin >> meanwo;
                }
                cout << "Fecha dd mm aaaa";
                int db, mb, ab;
                cin >> db;
                cin >> mb;
                cin >> ab;
                fx.setFecha(db, mb, ab);
                while(!(fechaV(fx))){
                    cout << "Fecha no valida intente de nuevo" << endl;
                    cin >> db;
                    cin >> mb;
                    cin >> ab;
                    fx.setFecha(db, mb, ab);
                }
                
                //Validando la disponibilidad de la fecha
                while(!(disponible(contres, cma, meanwo, fx, arrr, arrma))){
                    cout << "FFecha no disponible intente otra fecha" << endl;
                    cin >> db;
                    cin >> mb;
                    cin >> ab;
                    fx.setFecha(db, mb, ab);
                }
                arrr[contres].setCliente(meanwi);
                arrr[contres].setMaterial(meanwo);
                arrr[contres].setFechaReservacion(fx);
                contres++;
                break;
            default:
                ofstream archsal("Reserva.txt");
                for (int i=0; i<contres; i++){
                    archsal << arrr[i].getFechaReservacion().getDay();
                    archsal << " ";
                    archsal << arrr[i].getFechaReservacion().getMonth();
                    archsal << " ";
                    archsal << arrr[i].getFechaReservacion().getYear();
                    archsal << " ";
                    archsal << arrr[i].getMaterial();
                    archsal<< " ";
                    archsal << arrr[i].getCliente();
                    if(i < contres -1)
                    {
                        archsal << endl;
                    }
                }
    }
    }while(opc=!'F');
    return 0;
    }
