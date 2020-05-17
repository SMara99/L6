#include "Menu.h"

int main() {
	int x;
	cout << "Bine ati venit! \n Introduceti: \n1 -> Admin \n2 -> Client\n"; cin >> x;

	if 
		(x == 1) Menu(true);
	else 
		if (x == 2) Menu(false);
		else 
			cout << "Va rog introduceti 1 sau 2";

	return 0;
}