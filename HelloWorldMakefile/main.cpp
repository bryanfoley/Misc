/*
 * main.cpp
 *
 *  Created on: Apr 29, 2013
 *      Author: bfoley
 */

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
    exit(0);
}


