#ifndef KASYNO_H
#define KASYNO_H

#include"Uczestnik.h"
#include"Karta.h"

#include<iostream>
#include<vector>
#include <time.h>
#include <stdlib.h>

class Kasyno
{
    public:

        Kasyno();
        ~Kasyno();
        void start();
        int hit(Gracz *gracz);
        int stand(Gracz *gracz);
        int double_down(Gracz *gracz);
        bool insure();
        int koniec_tury(Gracz *gracz);
        Karta losuj_karty();
        void symulacja();

    private:

        double wygrana;
        vector<Karta>talia_kart;
        vector<Gracz>gracze;
        Karta *talia;
        Gracz *gracz;
        Krupier *krupier;

        int symuluj(Gracz *gracz, double stawka, int prog);

};

#endif // KASYNO_H
