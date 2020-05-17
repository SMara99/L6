#include "Repository.h"

Repository::Repository() {};
Repository::~Repository() {};

vector<Film> Repository::get_liste() {
	return Liste;
}

void Repository::add(Film film) {
	int index = -1;
	for (int i = 0; i < Liste.size(); i++) {
		if (film.get_titel() == Liste[i].get_titel())
			index = i;
	}
	if (index < 0) Liste.push_back(film);
}

void Repository::remove(string titel) {
	int index = -1;
	for (int i = 0; i < Liste.size(); i++) {
		if (titel == Liste[i].get_titel())
			index = i;
	}
	if (index > -1) Liste.erase(Liste.begin() + index);
}

void Repository::update(string name, Film film) {
	int index = -1;
	for (int i = 0; i < Liste.size(); i++) {
		if (name == Liste[i].get_titel()) {
			index = i;
		}
	}
	if (index > -1) Liste[index] = film;
}
