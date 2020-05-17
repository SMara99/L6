#pragma once
#include "Film.h"
#include<vector>

class Repository
{
	friend class Controller;
private:
	vector<Film> Liste;

public:
	Repository();
	~Repository();

	vector<Film> get_liste();

	void add(Film film);
	void remove(string titel);
	void update(string name, Film film);

};

