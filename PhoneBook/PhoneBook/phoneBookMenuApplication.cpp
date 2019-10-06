#include <iostream>
#include "phoneBookEntry.h"
using namespace std;

int main() {
	//TODO: Start working on the menu
	cout << "Hello, world!" << endl;

	phoneBookEntry entry("Nolan Davenport", "2812032172");
	cout << entry.name();
}