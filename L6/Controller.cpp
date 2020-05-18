#include "Controller.h"

void Controller::CreateMenu() {
	//Menu Admin:

	this->menu.add("Add Film", [this]() {this->add_film_liste(); });
	this->menu.add("Remove Film", [this]() {this->remove_film_liste(); });
	this->menu.add("Update Film", [this]() {this->update(); });

	//this->menu.add(QuitMenuItem[10]);

}
void Controller::add_film_liste() {
	cout << "Adaugati informatii -> Titel Genre Jahr Likes Trailer";
	string titel, genre, trailer; int jahr, likes;
	cin >> titel >> genre >> jahr >> likes >> trailer;
	Film x(titel, genre, jahr, likes, trailer);
	repo.add_liste(x);
};

void Controller::remove_film_liste() {
	cout << "Introduceti titlu: ";
	string titel;
	cin >> titel;
	repo.remove_liste(titel);
};

void Controller::update() {
	cout << "Care? ";
	string old_titel;
	cin >> old_titel;
	cout << "Informatii noi: Titel Genre Jahr Likes Trailer";
	string new_titel, genre, trailer; int likes, jahr;
	cin >> new_titel >> genre >> jahr >> likes >> trailer;
	Film x(new_titel, genre, jahr, likes, trailer);
	repo.update(old_titel, x);
}

void Controller::Run() {
	this->CreateMenu();

	try {
		while (true) {
			this->menu.show();
			int option;
			cin >> option;

			auto menuItem = this->menu.find_item(option);
			menuItem.execute();
		}
	}
	/*
	catch (quitException qex) {
		//quits program
	}
	*/
	catch (exception ex) {
		cout << "Exception occured: " << ex.what() << endl;
	}
}