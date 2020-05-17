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
                Admin.liste_ansehen(Liste);
                break;
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
                break;
            }
            case 3: {
                string de_sters;
                cout << "\nCare film doriti sa fie sters?\n"; cin >> de_sters;
                Liste.remove(de_sters);
                break;
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
                break;
            }
            case 0: {
                cout << "\nO zi placuta in continuare!";
                on = false; 
                break;
            }  
            default:{
                      cin >> option;
            }
            }
        }
    }
    else {
        Controller Client;
        Repo_Watch Watchlist;
        Repository Liste;

        int option;
        bool on = true;

        while (on) {
            cout << "1) Browse and Add\n";
            cout << "2) Show watchlist\n";
            cout << "3) Remove from watchlist\n";
            cout << "0) Exit\n";

            cin >> option;

            switch (option) {
            case 1: {
                
                break;
            }
            case 2: {
                Client.watchliste_ansehen(Watchlist);
                break;
            }
            case 3: {
                string de_sters, seen, like;
                cout << "\nCare film doriti sa il stergeti?\n"; cin >> de_sters;
                cout << "\nCompletati: "; 
                cout << "\nSeen? ";  cin >> seen;
                cout << "\nLike?"; cin >> like;
                if (seen == "Yes") {
                    if (like == "Yes") {
                        Client.anzahl_likes();
                        Watchlist.remove(de_sters);
                    }
                    else Watchlist.remove(de_sters);
                }
                break;
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