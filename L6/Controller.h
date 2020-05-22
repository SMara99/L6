#pragma once
#include "Film.h"
#include "Repository.h"
#include "Watchlist.h"
#include "Menu.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <vector>


using namespace std;

class Controller {

private:
	Repository repo;
	Menu menu;

	void CreateMenu();

public:
	
	void add_film_liste();
	void remove_film_liste();
	void update();

	void add_watchlist();

	void Run();
};

