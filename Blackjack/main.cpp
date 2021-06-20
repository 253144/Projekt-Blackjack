#include <iostream>
#include "Kasyno.h"

using namespace std;

int main()
{
    Kasyno kasyno;

    int wybor1;
    char wybor2, wybor3;

    cout << "Witaj!";
    do{
        cout << "\nWybierz opcje:\n 1-Gra w blackjack\n 2-Symulacja gry wielu graczy\n 3-Wyjscie\n" << endl;
        do{
            cout << "Twoj wybor: ";
            cin >> wybor1;
        }while(wybor1!=1 && wybor1!=2 && wybor1!=3);

        if(wybor1==1)
        {
            do{
                kasyno.start();
                cout << "Czy chcesz grac dalej? (t/n)\n";
                do{
                    cout << "Twoj wybor: ";
                    cin >> wybor2;
                }while(wybor2!='n' && wybor2!='t');
            }while(wybor2!='n');
        }

        if(wybor1==2)
        {
            do{
                kasyno.symulacja();
                cout << "Czy chcesz przeprowadzic kolejna symulacje? (t/n)\n";
                do{
                    cout << "Twoj wybor: ";
                    cin >> wybor3;
                }while(wybor3!='n' && wybor3!='t');
            }while(wybor3!='n');
        }
    }while(wybor1!=3);
    return 0;
}
