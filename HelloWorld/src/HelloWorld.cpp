//============================================================================
// Name        : HelloWorld.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main () {
	// Say Hello five times
	for (int index = 0; index < 5; ++index)
		cout << "HelloWorld!" << endl;
	char input = 'i';
	cout << "To exit, press 'm'" << endl;
	while(input != 'm') {
		cin  >> input;
		cout << "You just entered " << input
			 << " you need to enter m to exit." << endl;
	}
	return(0);
}
