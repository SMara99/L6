#include "Controller.h"

Controller::Controller() {};
Controller::~Controller() {};

void Controller::liste_ansehen() {
	Repository Liste;

	vector<Film> list = Liste.get_liste();

	for (int i = 0; i < list.size(); i++) {
		show(list[i]);
	}
}

void Controller::show(Film film) {
	cout << "\n" << film.get_titel() << " ";
	cout << film.get_genre() << " ";
	cout << film.get_jahr() << " ";
	cout << film.get_likes() << " ";

	//transform string Trailer in LPCWSTR pt a deschide in browser
	string beta = film.get_trailer();
	wstring t(beta.begin(), beta.end());
	LPCWSTR trailer = t.c_str();
	//la fel si pt "open"
	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();
	//rulare in browser;
	ShellExecute(NULL, status, trailer, NULL, NULL, SW_SHOWNORMAL);
}

void Controller::anzahl_likes() {

}

void Controller::watchliste_ansehen() {

	Repo_Watch Watchlist;

	vector<Film> list = Watchlist.get_liste();

	for (int i = 0; i < list.size(); i++) {
		show(list[i]);
	}

}