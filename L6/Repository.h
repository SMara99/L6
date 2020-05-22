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
	vector<Film> genres;

public:

	void add_liste(Film film);
	void remove_liste(string titel);
	void update(string titel, Film film);

	//filters out the movies that belong to a certain genre and creates a new file that contains them - if the file already exist it will be overwritten
	void filter_by_genre(string genre);
	//enables a user to rate a movie once they have removed it from the list
	void rate_movie(string title, string rating, Film film);
};

