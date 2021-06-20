#include "Kasyno.h"

Kasyno::Kasyno()
{
    talia_kart.resize(52);

    krupier=new Krupier;

    Karta dwaKi(2,"kier",'2');
    Karta trzyKi(3,"kier",'3');
    Karta czteryKi(4,"kier",'4');
    Karta piecKi(5,"kier",'5');
    Karta szescKi(6,"kier",'6');
    Karta siedemKi(7,"kier",'7');
    Karta osiemKi(8,"kier",'8');
    Karta dziewiecKi(9,"kier",'9');
    Karta dziesiecKi(10,"kier",'0');
    Karta waletKi(10,"kier",'J');
    Karta damaKi(10,"kier",'Q');
    Karta krolKi(10,"kier",'K');
    Karta asKi(11,"kier",'A');

    Karta dwaKa(2,"karo",'2');
    Karta trzyKa(3,"karo",'3');
    Karta czteryKa(4,"karo",'4');
    Karta piecKa(5,"karo",'5');
    Karta szescKa(6,"karo",'6');
    Karta siedemKa(7,"karo",'7');
    Karta osiemKa(8,"karo",'8');
    Karta dziewiecKa(9,"karo",'9');
    Karta dziesiecKa(10,"karo",'0');
    Karta waletKa(10,"karo",'J');
    Karta damaKa(10,"karo",'Q');
    Karta krolKa(10,"karo",'K');
    Karta asKa(11,"karo",'A');

    Karta dwaT(2,"trefl",'2');
    Karta trzyT(3,"trefl",'3');
    Karta czteryT(4,"trefl",'4');
    Karta piecT(5,"trefl",'5');
    Karta szescT(6,"trefl",'6');
    Karta siedemT(7,"trefl",'7');
    Karta osiemT(8,"trefl",'8');
    Karta dziewiecT(9,"trefl",'9');
    Karta dziesiecT(10,"trefl",'0');
    Karta waletT(10,"trefl",'J');
    Karta damaT(10,"trefl",'Q');
    Karta krolT(10,"trefl",'K');
    Karta asT(11,"trefl",'A');

    Karta dwaP(2,"pik",'2');
    Karta trzyP(3,"pik",'3');
    Karta czteryP(4,"pik",'4');
    Karta piecP(5,"pik",'5');
    Karta szescP(6,"pik",'6');
    Karta siedemP(7,"pik",'7');
    Karta osiemP(8,"pik",'8');
    Karta dziewiecP(9,"pik",'9');
    Karta dziesiecP(10,"pik",'0');
    Karta waletP(10,"pik",'J');
    Karta damaP(10,"pik",'Q');
    Karta krolP(10,"pik",'K');
    Karta asP(11,"pik",'A');

    talia_kart[0]=dwaKi;
    talia_kart[1]=trzyKi;
    talia_kart[2]=czteryKi;
    talia_kart[3]=piecKi;
    talia_kart[4]=szescKi;
    talia_kart[5]=siedemKi;
    talia_kart[6]=osiemKi;
    talia_kart[7]=dziewiecKi;
    talia_kart[8]=dziesiecKi;
    talia_kart[9]=waletKi;
    talia_kart[10]=damaKi;
    talia_kart[11]=krolKi;
    talia_kart[12]=asKi;

    talia_kart[13]=dwaKa;
    talia_kart[14]=trzyKa;
    talia_kart[15]=czteryKa;
    talia_kart[16]=piecKa;
    talia_kart[17]=szescKa;
    talia_kart[18]=siedemKa;
    talia_kart[19]=osiemKa;
    talia_kart[20]=dziewiecKa;
    talia_kart[21]=dziesiecKa;
    talia_kart[22]=waletKa;
    talia_kart[23]=damaKa;
    talia_kart[24]=krolKa;
    talia_kart[25]=asKa;

    talia_kart[26]=dwaT;
    talia_kart[27]=trzyT;
    talia_kart[28]=czteryT;
    talia_kart[29]=piecT;
    talia_kart[30]=szescT;
    talia_kart[31]=siedemT;
    talia_kart[32]=osiemT;
    talia_kart[33]=dziewiecT;
    talia_kart[34]=dziesiecT;
    talia_kart[35]=waletT;
    talia_kart[36]=damaT;
    talia_kart[37]=krolT;
    talia_kart[38]=asT;

    talia_kart[39]=dwaP;
    talia_kart[40]=trzyP;
    talia_kart[41]=czteryP;
    talia_kart[42]=piecP;
    talia_kart[43]=szescP;
    talia_kart[44]=siedemP;
    talia_kart[45]=osiemP;
    talia_kart[46]=dziewiecP;
    talia_kart[47]=dziesiecP;
    talia_kart[48]=waletP;
    talia_kart[49]=damaP;
    talia_kart[50]=krolP;
    talia_kart[51]=asP;

    srand (time(NULL));

}

Kasyno::~Kasyno()
{
    delete krupier;
}

int Kasyno::koniec_tury(Gracz *gracz)
{
    if(gracz->getSuma()<=21)
    {
        while((krupier->getSuma()<17 && krupier->getSuma()<gracz->getSuma()) || krupier->getSuma()<gracz->getSuma())
        {
            krupier->dobierz(losuj_karty());
            if(gracze.size()==1)
            {
                cout << "\n*krupier dobiera karte*\n";
                cout << endl;
                krupier->pokaz_karty();
                gracz->pokaz_karty();
                cout << endl;
            }
        }
    }


    if(gracz->getSuma()==21 && krupier->getSuma()!=21)
    {
        gracz->balans_dodaj(wygrana);
        krupier->wyczysc();
        gracz->wyczysc();
        return 0; //Blackjack
    }

    if(gracz->getSuma()==krupier->getSuma())
    {
        gracz->balans_dodaj(wygrana/2);
        krupier->wyczysc();
        gracz->wyczysc();
        return 1; //Remis
    }

    if((gracz->getSuma()>krupier->getSuma() && gracz->getSuma()<=21) || krupier->getSuma()>21)
    {
        gracz->balans_dodaj(wygrana);
        krupier->wyczysc();
        gracz->wyczysc();
        return 2; //Wygrales
    }

    if((gracz->getSuma()<krupier->getSuma() && krupier->getSuma()<=21) || gracz->getSuma()>21)
    {
        krupier->wyczysc();
        gracz->wyczysc();
        return 3; //Przegrales
    }

    return 4;
}

void Kasyno::start()
{
    if(gracze.size()==0)
    {
        gracze.resize(1);
        gracz= new Gracz;
        gracze[0]=*gracz;
        delete gracz;
    }

    int wynik;
    double stawka;
    char koniec;

    if(gracze[0].getBalans()==0)
    {
        cout << "\nZbankrutowales :(\nOtwieranie nowego rachunku...\n" << endl;
        gracze.clear();
        return;
    }

    cout << "\nBalans: " << gracze[0].getBalans() << endl;
    do
    {
        cout << "Podaj stawke: ";
        cin >> stawka;
        if(stawka>gracze[0].getBalans())
        {
            cout << "\nNiewystarczajacy balans!" << endl << endl;
        }
    }while(stawka>gracze[0].getBalans());
    gracze[0].balans_odejmij(stawka);

    wygrana=2*stawka;

    krupier->dobierz(losuj_karty());

    gracze[0].dobierz(losuj_karty());
    gracze[0].dobierz(losuj_karty());

    cout << endl;
    krupier->pokaz_karty();
    gracze[0].pokaz_karty();
    cout << endl;

    int wybor;
    int opcje=2;
    if(gracze[0].getBalans()>=stawka)
        opcje++;

  do{
    cout << " 1- hit\n 2- stand" << endl;
    if(opcje==3)
        cout << " 3- double down" << endl;

    cout << "Twoj wybor: ";
    do{
        cin >> wybor;
    }while(wybor>opcje);

    switch(wybor)
    {
    case 1: wynik=this->hit(&gracze[0]);
            break;

    case 2: if(krupier->jedenascie()==true && gracze[0].getBalans()>=stawka/2)
            {
                char wybor2;
                cout<< "\nCzy chcesz zabezpieczyc sie na przypadek blackjacka? (t/n): ";
                do{
                    cin>>wybor2;
                }while(wybor2!='n' && wybor2!='t');
                if(wybor2=='t')
                {
                    bool temp=insure();
                    if(temp==false)
                    {
                        cout << endl;
                        krupier->pokaz_karty();
                        gracze[0].pokaz_karty();
                        cout << endl;
                        cout<< "Krupier nie ma blackjacka." << endl;
                        gracze[0].balans_odejmij(stawka/2);
                    }
                    if(temp==true)
                    {
                        cout << endl;
                        krupier->pokaz_karty();
                        gracze[0].pokaz_karty();
                        cout << endl;
                        cout << "Krupier ma blackjacka." << endl;
                        gracze[0].balans_dodaj(stawka);
                    }
                }
            }
            wynik=this->stand(&gracze[0]);
            break;

    case 3: wynik=this->double_down(&gracze[0]);
            break;
    }
    if(wynik==0)
        cout << "Blackjack!" << endl;
    if(wynik==1)
        cout << "Remis!" << endl;
    if(wynik==2)
        cout << "Wygrales!" << endl;
    if(wynik==3)
        cout << "Przegrales!" << endl;
    opcje=2;
  }while(wynik==4 && koniec!='n');
}

int Kasyno::symuluj(Gracz *gracz , double stawka, int prog)
{
    gracz->balans_odejmij(stawka);

    wygrana=2*stawka;

    krupier->dobierz(losuj_karty());

    gracz->dobierz(losuj_karty());
    gracz->dobierz(losuj_karty());

    do
    {
        gracz->dobierz(losuj_karty());
    }while(gracz->getSuma()<prog);

    return this->koniec_tury(gracz);
}

int Kasyno::hit(Gracz *gracz)
{
    gracz->dobierz(losuj_karty());
    if(gracze.size()==1)
    {
        cout << endl;
        krupier->pokaz_karty();
        gracze[0].pokaz_karty();
        cout << endl;
    }
    if(gracz->getSuma()>=21)
    {
        return this->koniec_tury(gracz);
    }
    else
        return 4;
}

int Kasyno::stand(Gracz *gracz)
{
    return this->koniec_tury(gracz);
}

int Kasyno::double_down(Gracz *gracz)
{
    gracz->balans_odejmij(wygrana/2);
    wygrana = 2* wygrana;
    gracz->dobierz(losuj_karty());
    return this->koniec_tury(gracz);
}

bool Kasyno::insure()
{
    krupier->dobierz(losuj_karty());
    if(krupier->getSuma()==21)
        return true;
    else
        return false;

}

Karta Kasyno::losuj_karty()
{
    int k;
    k= rand() % 52;
    return talia_kart[k];
}

void Kasyno::symulacja()
{
    int n, l;
    double stawka;
    int outcome, prog;
    vector<int>wygrane;
    vector<int>przegrane;
    vector<int>remisy;
    vector<int>blackjack;
    cout << "\nPodaj liczbe graczy do symulacji: " ;
    cin >> n;
    cout << "Podaj stawke podczas gier: ";
    cin >> stawka;
    cout << "Podaj liczbe gier (na gracza): ";
    cin >> l;
    do{
        cout << "Podaj prog przy ktorym gracze maja zakonczyc dobieranie (min 2, max 21): ";
        cin >> prog;
    }while(prog<2 || prog>21);


    wygrane.resize(n);
    przegrane.resize(n);
    remisy.resize(n);
    blackjack.resize(n);

    gracze.resize(n);
    for(int i=0; i<n; i++)
    {
        gracz= new Gracz;
        gracze[i]=*gracz;
        delete gracz;
    }

    for(int i=0; i<n; i++)
    {
        przegrane[i]=0;
        remisy[i]=0;
        blackjack[i]=0;
    }

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(gracze[j].getBalans()>=stawka)
            {
                outcome=symuluj(&gracze[j], stawka, prog);
                if(outcome==0)
                    blackjack[j]++;
                if(outcome==1)
                    remisy[j]++;
                if(outcome==2)
                    wygrane[j]++;
                if(outcome==3)
                    przegrane[j]++;
            }
        }
    }

    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Gracz " << i+1 << ": ";
        cout << "wygrane(" << wygrane[i] + blackjack[i] << ") | ";
        cout << "przegrane(" << przegrane[i] << ") | ";
        cout << "remisy(" << remisy[i] << ") | ";
        cout << "blackjacki(" << blackjack[i] << ") | ";
        cout << "balans(" << gracze[i].getBalans() << ")" << endl;
    }
    gracze.clear();
}
