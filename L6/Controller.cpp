#include "Controller.h"
#include "QuitMenuItem.h"

void Controller::CreateMenu()
{
	this->menu.add("Log in as admin", [this]() {this->CreateMenuAdmin(); });
	this->menu.add("Log in as admin", [this]() {this->CreateMenuClient(); });
	this->menu.add(QuitMenuItem(3));
}

void Controller::CreateMenuAdmin() {
	//Menu Admin:

	this->menu.add("Add Film", [this]() {this->add_film_liste(); });
	this->menu.add("Remove Film", [this]() {this->remove_film_liste(); });
	this->menu.add("Update Film", [this]() {this->update(); });
	this->menu.add(QuitMenuItem(4));

}

void Controller::CreateMenuClient()
{
	this->menu.add("View films by genre", [this]() {this->filter_by_genre(); });
	this->menu.add("Remove film from watchlist", [this]() {this->remove_from_watchlist(); });
	this->menu.add("Update watchlist", [this]() {this->update_watchlist(); });
	this->menu.add("Open watchlist as csv", [this]() {this->open_csv(); });
	this->menu.add("Open watchlist as html", [this]() {this->open_html(); });
	this->menu.add(QuitMenuItem(6));
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

void Controller::remove_from_watchlist()
{
	string auxtitle, opinion;
	Film last;
	cout << "Which movie would you like to remove?\n";
	cin >> auxtitle;
	
	to_watch.remove_from_vector(auxtitle);

	last = to_watch.get_lastremoved();

	cout << "Did you enjoy the movie?\n Type:\n 'Y' to leave a like\n 'N' to leave a dislike\n Typing anything else will skip the rating of the film.";
	cin >> opinion;

	repo.rate_movie(auxtitle, opinion, last);

	to_watch.update_watchlist_file();
}

void Controller::update_watchlist()
{
	string title, newtitle, newgenre, newtrailer;
	int newyear, newlikes;

	cout << "Which movie would you like to update?\n";
	cin >> title;

	cout << "New title: ";
	cin >> newtitle;
	cout << "\nNew genre: ";
	cin >> newgenre;
	cout << "\nNew year: ";
	cin >> newyear;
	cout << "\nNew likes: ";
	cin >> newlikes;
	cout << "\nNew trailer: ";
	cin >> newtrailer;

	to_watch.update_in_vector(title, newtitle, newgenre, newyear, newlikes, newtrailer);
	to_watch.update_watchlist_file();
}

void Controller::filter_by_genre()
{
	int it = 0;
	vector<Film> temp;
	string genre, option = "Y", addfilm;
	cout << "Enter desired genre: ";
	cin >> genre;
	to_watch.filter_by_genre(genre);
	temp = to_watch.genre_to_vector();
	
	while (option == "Y" && it < temp.size() || option == "y" && it < temp.size())
	{
		play_trailer(temp[it].get_trailer());

		cout << "\n Add film to watchlist?\n Type 'Y' to confirm\n (typing anything else will result in the movie not being added)";
		cin >> addfilm;

		if (addfilm == "Y" || addfilm == "y")
			to_watch.add_to_vector(temp[it]);

		cout << "\n Play the next trailer?\n Type 'Y' to confirm\n (typing anything else will result in the movie not being added)";
		cin >> option;

		it++;
	}

	to_watch.update_watchlist_file();
}

void Controller::open_csv()
{
	system("notepad.exe Watchlist.csv");
}

void Controller::open_html()
{
	string helpfile = "Watchlist.html";
	wstring helpfile2(helpfile.begin(), helpfile.end());
	LPCTSTR htmlfile = helpfile2.c_str();

	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();

	ShellExecute(NULL, status, htmlfile, NULL, NULL, SW_SHOWNORMAL);
	system("PAUSE");
}

void Controller::play_trailer(string trailer)
{
	//transform string Trailer in LPCWSTR pt a deschide in browser
	wstring beta(trailer.begin(), trailer.end());
	LPCWSTR aux = beta.c_str();
	//la fel si pt "open"
	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();
	//rulare in browser;
	ShellExecute(NULL, status, aux, NULL, NULL, SW_SHOWNORMAL);
}

void Controller::Run() {
	this->CreateMenuAdmin();

	try {
		while (true) {
			this->menu.show();
			int option;
			cin >> option;

			auto menuItem = this->menu.find_item(option);
			menuItem.execute();
		}
	}
	catch (quitException qex) {
		//quits program
	}
	catch (exception ex) {
		cout << "Exception occured: " << ex.what() << endl;
	}
}

