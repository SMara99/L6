#pragma once
#include "Film.h"
#include "Repository.h"
#include "Repo_Watch.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <vector>

class Controller
{
	friend class Menu;

public:
	//Controller fur Admin

	//anzeigen der Liste
	void liste_ansehen(Repository Liste);

	//Controller fur Client

	//anzeigen der Film und trailer im Browser
	void show(Film film);
	//Nach dem Entfernen der Film wird die Bewertung durchgelaufen
	void anzahl_likes();
	//ansehen der ganzen Liste
	void watchliste_ansehen(Repo_Watch watchlist);

	Controller();
	~Controller();

};

