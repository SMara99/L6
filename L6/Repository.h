#pragma once
#include "Film.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Repository
{
private:
	fstream film_file;

public:

	void add_liste(Film film);
	void remove_liste(string titel);
	void update(string titel, Film film);

	//enables a user to rate a movie once they have removed it from the list
	void rate_movie(string title, string rating, Film film);
};

