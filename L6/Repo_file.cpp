#include "Repo_file.h"

Repo_file::Repo_file() {};
Repo_file::~Repo_file() {};

void Repo_file::add(Film film) {

	bool gef = true;
	
	Repository.open("Liste.txt");

	string line;
	while (getline(Repository, line)) {
		string titel = line.substr(0, line.find_first_of(" "));
		if (titel == film.get_titel()) gef = false;
	}

	if (gef) Repository << "\n%s %s %d %d \n%s" << 
		film.get_titel() << film.get_genre() << film.get_jahr() << film.get_likes() << film.get_trailer();

	Repository.close();
};

void Repo_file::remove(string film) {
	fstream temp;
	temp.open("temp.txt");

	Repository.open("Liste.txt");
	string line1, line2;
	while (getline(Repository, line1) && getline(Repository, line2)) {
		string titel = line1.substr(0, line1.find_first_of(" "));
		if (titel == film);
		else temp << "\n" << line1 << "\n" << line2;
	}
	Repository.close();

	temp.close();

	remove("Liste.txt");
	rename("temp.txt", "Liste.txt");
};

void Repo_file::update(string titel, Film film) {
	fstream temp;
	temp.open("temp.txt");

	Repository.open("Liste.txt");
	string line1, line2;
	while (getline(Repository, line1) && getline(Repository, line2)) {
		string name = line1.substr(0, line1.find_first_of(" "));
		if (name == titel) temp << "\n%s %s %d %d \n%s" <<
			film.get_titel() << film.get_genre() << film.get_jahr() << film.get_likes() << film.get_trailer();
		else temp << "\n" << line1 << "\n" << line2;
	}
	Repository.close();

	temp.close();

	remove("Liste.txt");
	rename("temp.txt", "Liste.txt");
};