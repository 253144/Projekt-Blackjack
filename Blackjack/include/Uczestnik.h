#ifndef UCZESTNIK_H
#define UCZESTNIK_H

#include"Karta.h"

#include<iostream>
#include<vector>

using namespace std;

class Uczestnik
{
    public:
        Uczestnik() : suma(0) {}
        virtual ~Uczestnik() = default;
        virtual void pokaz_karty();
        virtual void dobierz(Karta karta);
        virtual void wyczysc();

        int getSuma() {return suma;}

    protected:
        char id;
        vector<Karta>karty_dobrane;
        int suma;

        virtual void sumuj();
    private:

};

class Gracz : public Uczestnik
{
    public:
        Gracz() : balans(1000) {id='g';}
        Gracz(double _balans) : balans(_balans) {id='g';}
        double getBalans() {return balans;}
        void balans_odejmij(double x) {balans=balans-x;}
        void balans_dodaj(double x) {balans=balans+x;}

    private:
        double balans;
};

class Krupier : public Uczestnik
{
    public:
        Krupier() {id='k';}
        bool jedenascie();

    private:
};

#endif // UCZESTNIK_H
