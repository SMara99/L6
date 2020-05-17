#pragma once
#include "Film.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Repo_file
{
private:
	fstream Repository;
	struct film_line {
		string film;
		int line;
	};

public:
	Repo_file();
	~Repo_file();

	void add(Film film);
	void remove(string titel);
	void update(string titel, Film film);

};

