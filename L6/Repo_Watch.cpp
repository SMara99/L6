#include "Repo_Watch.h"

Repo_Watch::Repo_Watch() {};

Repo_Watch::~Repo_Watch() {};

vector<Film> Repo_Watch::get_liste() {
	return Watchlist;
}

void Repo_Watch::add(Film film) {
	int index = -1;
	for (int i = 0; i < Watchlist.size(); i++) {
		if (film.get_titel() == Watchlist[i].get_titel())
			index = i;
	}
	if (index < 0) Watchlist.push_back(film);
}

void Repo_Watch::remove(Film film) {
	int index = -1;
	for (int i = 0; i < Watchlist.size(); i++) {
		if (film.get_titel() == Watchlist[i].get_titel())
			index = i;
	}
	if (index > -1) Watchlist.erase(Watchlist.begin() + index);
}