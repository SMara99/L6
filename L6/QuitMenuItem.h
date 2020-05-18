#pragma once
#include "MenuItem.h"
#include "quitException.h"

class QuitMenuItem : public MenuItem{
public:

	QuitMenuItem(int option) :MenuItem(option, "Quit", []() {throw quitException(); }) {
	}
	
};

