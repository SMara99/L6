#pragma once
#include "Film.h"
#include <fstream>
#include <iostream>
#include <vector>

//the following class builds a vector whose lines will be added
class Watchlist
{
protected:
	vector<Film> watchlist;
	fstream film_file;

public:
	Watchlist();
	//adds a new film to the watchlist vector
	void add_to_vector(Film film);
	//removes a film from the watchlist vector
	void remove_from_vector(string title);
	//updates a film from the vector - if the values remain as the default ones, then no changes will occur
	void update_in_vector(string title, string new_title = "", string new_genre = "", int new_year = NULL, int new_likes = NULL, string new_trailer = "");
	//creates a new file which will contain all the movies within a genre - the method will allow the client to then add the movie to their watchlist
	void filter_by_genre(string genre);
	//creates a vector that reads the "Genre.txt" folder's lines as film objects
	void genre_to_vector();
};

class Watchlist_CSV : public Watchlist
{
private:
	fstream csv_file;
public:
	//writes the contents of the watchlist vector in a csv format
	void write_to_csv();
	void open_csv();
};

class Wachlist_HTML : public Watchlist
{
private:
	fstream html_file;
public:
	void write_to_html();
	void open_html();
};
