#pragma once
#include "Film.h"
#include <fstream>
using namespace std;

class Watch_file
{
private:
	fstream Watchliste;

public:
	Watch_file();
	~Watch_file();

	void add(Film film);
	void remove(string name);

};

