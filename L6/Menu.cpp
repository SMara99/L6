#include "Menu.h"

Menu::Menu(bool i) {
    if (i) {
        Controller Admin;
        Repository Liste;

        int option;
        bool on = true;

        while (on) {
            cout << "1) Display all films\n";
            cout << "2) Add a new film\n";
            cout << "3) Remove a film\n";
            cout << "4) Update a film\n";
            cout << "0) Exit\n";

            cin >> option;

            switch (option) {
            case 1: {
                Admin.liste_ansehen();
            }   
            case 2: {
                string titel_add, genre_add, trailer_add;
                int jahr_add, likes_add;
                cout << "\nTitel: "; cin >> titel_add;
                cout << "\nGenre: "; cin >> genre_add;
                cout << "\nJahr: "; cin >> jahr_add;
                cout << "\nLikes: "; cin >> likes_add;
                cout << "\nTrailer: "; cin >> trailer_add;

                Film x(titel_add, genre_add, jahr_add, likes_add, trailer_add);
                Liste.add(x);
            }
            case 3: {
                string de_sters;
                cout << "\nCare film doriti sa il stergem?\n"; cin >> de_sters;
                Liste.remove(de_sters);
            }
            case 4: {
                string nume_vechi, nume_nou, genre_nou, trailer_nou;
                int jahr_nou, likes_nou;
                cout << "\nCare film?\n"; cin >> nume_vechi;
                cout << "\nCompletati: \n";
                cout << "\nTitel: "; cin >> nume_nou;
                cout << "\nGenre: "; cin >> genre_nou;
                cout << "\nJahr: "; cin >> jahr_nou;
                cout << "\nLikes: "; cin >> likes_nou;
                cout << "\nTrailer: "; cin >> trailer_nou;

                Film y(nume_nou, genre_nou, jahr_nou, likes_nou, trailer_nou);
                Liste.update(nume_vechi, y);
            }
            case 0: {
                cout << "\nO zi placuta in continuare!";
                on = false; 
                break;
            }  
              
            }
        }
    }
}

Menu::~Menu() {};