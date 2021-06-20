#include "Uczestnik.h"

#include<vector>


void Uczestnik::dobierz(Karta karta)
{
    karty_dobrane.push_back(karta);
    this->sumuj();
}

void Uczestnik::wyczysc()
{
    karty_dobrane.clear();
}

void Uczestnik::pokaz_karty()
{
    if(id=='g')
        cout << "Twoje karty: ";
    if(id=='k')
        cout << "Krupier: ";
    for(unsigned int i=0 ; i<karty_dobrane.size(); i++)
    {
        if(karty_dobrane[i].getFigura()=='0')
            cout << "10 " << karty_dobrane[i].getKolor() << "| ";
        else
            cout << karty_dobrane[i].getFigura() << " " << karty_dobrane[i].getKolor() << " | ";
    }

    this->sumuj();
    cout << " (" << suma << ")" << endl;
}

void Uczestnik::sumuj()
{
    suma=0;
    for(unsigned int i=0 ; i<karty_dobrane.size(); i++) //Sumowanie wartosci kart
    {
        suma=suma+karty_dobrane[i].getWartosc();
    }

    for(unsigned int i=0 ; i<karty_dobrane.size(); i++) //Poprawienie sumy jesli gracz ma Asa (zmiana wartosci asa z 11 na 1)
    {
        if(karty_dobrane[i].getFigura()=='A' && suma>21)
            suma=suma-10;
    }
}

bool Krupier::jedenascie()
{
    if(karty_dobrane[0].getWartosc()==11)
        return true;
    else
        return false;
}




