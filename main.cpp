#include "Chat.h"
#include <iostream>

using namespace std;


int main() {

	Chat VK;

	VK.reg((char*)"Sergiy", 123);
	VK.reg((char*)"Valentin", 4123);
	VK.reg((char*)"Georgy", 123253);
	VK.reg((char*)"Anna", 56457623);
	VK.reg((char*)"Maria", 12435);
	VK.reg((char*)"Denis", 23547);
	VK.reg((char*)"Oleg", 231246);


	if (VK.login((char*)"Sergiy", 123)) cout << "Welcome!" << endl;
	else cout << "error";

	if (VK.login((char*)"Sergiy", 123)) cout << "Welcome!" << endl;
	return 0;
}
