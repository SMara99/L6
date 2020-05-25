#include "Controller.h"

int main() {
	int x;
	auto controller = Controller();
	cout << "For Admin enter 1 and for Client enter 2\n";
	cin >> x;
	if (x == 1) { controller.Run_Admin(); }
	else if (x == 2) { controller.Run_Client(); }
		else cout << "Wrong digit";

	return 0;
}