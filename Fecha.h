//
//  Fecha.h
//  avancepro3
//
//  Created by Pepe Hdez hdez on 4/13/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h
#include <iostream>
#include <string>
using namespace std;
class Fecha{
public:
    Fecha();
    Fecha(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setFecha(int day, int motnh, int year);
    friend int operator*(Fecha x);
    friend bool operator>(Fecha a, Fecha b);
    friend bool operator >= (Fecha a,Fecha b);
    friend bool operator < (Fecha a, Fecha b);
    friend bool operator <= (Fecha a, Fecha b);
    friend bool operator == (Fecha a, Fecha b);
    friend ostream& operator <<(ostream &os, Fecha show);
    friend istream& operator >>(istream &is, Fecha & read);
    Fecha operator + (int days);
    string nombreMes();
private:
    int dd, mm, aa;
};
Fecha::Fecha(){
    dd=0;
    mm=0;
    aa=0;
}
Fecha::Fecha(int day, int month, int year){
    dd=day;
    mm=month;
    aa=year;
}
int Fecha::getDay(){
    return dd;
}
int Fecha::getMonth(){
    return mm;
}
int Fecha::getYear(){
    return aa;
}
void Fecha::setDay(int day){
    dd=day;
}
void Fecha::setMonth(int month){
    mm=month;
}
void Fecha::setYear(int year){
    aa=year;
}
void Fecha::setFecha(int day, int month, int year){
    dd=day;
    mm=month;
    aa=year;
}
int operator*(Fecha x){
    int bi, y;
    bi=x.getYear()%4;
    switch (x.getMonth()){
        case 1:
            y=x.getDay();
            break;
        case 2:
            y=31+x.getDay();
            break;
        case 3:
            if (bi==0){
                y=60+x.getDay();
            }
            else
                y=59+x.getDay();
            break;
        case 4:
            if (bi==0){
                y=91+x.getDay();
            }
            else
                y=90+x.getDay();
            break;
        case 5:
            if (bi==0){
                y=121+x.getDay();
            }
            else
                y=120+x.getDay();
            break;
        case 6:
            if (bi==0){
                y=152+x.getDay();
            }
            else
                y=151+x.getDay();
            break;
        case 7:
            if (bi==0){
                y=182+x.getDay();
            }
            else
                y=181+x.getDay();
            break;
        case 8:
            if (bi==0){
                y=213+x.getDay();
            }
            else
                y=212+x.getDay();
            break;
        case 9:
            if (bi==0){
                y=244+x.getDay();
            }
            else
                y=243+x.getDay();
            break;
        case 10:
            if (bi==0){
                y=274+x.getDay();
            }
            else
                y=273+x.getDay();
            break;
        case 11:
            if (bi==0){
                y=305+x.getDay();
            }
            else
                y=304+x.getDay();
            break;
        case 12:
            if (bi==0){
                y=335+x.getDay();
            }
            else
                y=334+x.getDay();
    }
    return y;
}
bool operator>(Fecha a, Fecha b){
    if((*a+(a.getYear())-1)*365> *b){
        return true;
    }
    else
        return false;
}
bool operator>=(Fecha a, Fecha b){
    if((*a+(a.getYear())-1)*365>= *b){
        return true;
    }
    else
        return false;
}
bool operator<(Fecha a, Fecha b){
    if((*a+(a.getYear())-1)*365< *b){
        return true;
    }
    else
        return false;
}
bool operator<=(Fecha a, Fecha b){
    if((*a+(a.getYear())-1)*365<= *b){
        return true;
    }
    else
        return false;
}
bool operator==(Fecha a, Fecha b){
    if((*a+(a.getYear())-1)*365== *b){
        return true;
    }
    else
        return false;
}
Fecha Fecha::operator+(int days){
    if(mm == 1 || mm == 3 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
        if(dd+days>31){
            dd-=31;
            mm+=1;
            if(mm>12)
            {
                mm=1;
                aa+=1;
            }
        }
        else
            dd+=days;
    }
    else
        if(mm == 2){
        if(aa%4==0){
            if(dd+days>29)
            {
                dd-=29;
                mm+=1;
            }
            else
                dd+=days;
        }
        else{
            if(dd+days>28){
                dd-=28;
                mm+=1;
            }
            else
                dd+=days;
        }
        }
        else
            if(dd+days>30){
                dd-=30;
                mm+=1;
            }
            else
                dd+=days;
    Fecha x(dd, mm, aa);
    return x;
}
ostream& operator<<(ostream &os, Fecha show){
    if(show.getDay()<10){
        cout<<0;
    }
    cout<<show.getDay()<<"/";
    switch(show.getMonth()){
        case 1:
            cout << "Ene/";
            break;
        case 2:
            cout << "Feb/";
            break;
        case 3:
            cout << "Mar/";
            break;
        case 4:
            cout << "Abr/";
            break;
        case 5:
            cout << "May/";
            break;
        case 6:
            cout << "Jun/";
            break;
        case 7:
            cout << "Jul/";
            break;
        case 8:
            cout << "Ago/";
            break;
        case 9:
            cout << "Sep/";
            break;
        case 10:
            cout << "Oct/";
            break;
        case 11:
            cout << "Nov/";
            break;
        case 12:
            cout << "Dic/";
            break;
    }
    cout<<show.getYear()<<endl;
    return os;
}







istream& operator >> (istream &is, Fecha & read){
    cout << "Inserta el mes: ";
    int fecha, dia;
    while(cin >> fecha &&(fecha < 0 || fecha > 12)){
        cout << "Invalido";
    }
    read.setMonth(fecha);
    cout << "Inserta el dia: ";
    if(fecha == 1 || fecha == 3 || fecha == 5 || fecha == 7 || fecha == 8 || fecha == 10 || fecha == 12){
        while(cin >> dia &&(dia < 0 || dia > 31))
            cout << "Invalido";
    }
    if(fecha == 2){
        while(cin >> dia &&(dia < 0 || dia > 29))
            cout << "Invalido";
    }
    else{
        while(cin >> dia &&(dia < 0 || dia > 30))
            cout << "Invalido";
    }
    return is;
}
string Fecha :: nombreMes()
{
    string mt;
    switch(mm)
    {
        case 1:
            mt="Ene";
            break;
        case 2:
            mt="Feb";
            break;
        case 3:
            mt="Mar";
            break;
        case 4:
            mt="Abr";
            break;
        case 5:
            mt="May";
            break;
        case 6:
            mt="Jun";
            break;
        case 7:
            mt="Jul";
            break;
        case 8:
            mt="Ago";
            break;
        case 9:
            mt="Sep";
            break;
        case 10:
            mt="Oct";
            break;
        case 11:
            mt="Nov";
            break;
        case 12:
            mt="Dic";
            break;
    }
    return mt;
}

#endif /* Fecha_h */
