#ifndef KARTA_H
#define KARTA_H

#include<iostream>

using namespace std;

class Karta
{
    private:
        int wartosc;
        string kolor;
        char figura;

    public:
        Karta(): wartosc(0),kolor("brak"),figura('x') {};
        Karta(int wartosc, string kolor, char figura):wartosc(wartosc),kolor(kolor),figura(figura) {}

        int getWartosc() {return wartosc;}
        string getKolor() {return kolor;}
        char getFigura() {return figura;}
};

#endif // KARTA_H
