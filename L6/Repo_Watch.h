#pragma once
#include "Film.h"
#include <vector>

class Repo_Watch
{
	friend class Controller;
private:
	vector<Film> Watchlist;
private:
	Repo_Watch();
	~Repo_Watch();

	vector<Film> get_liste();

	void add(Film film);
	void remove(Film film);

};

