/*

Author: Andrey Barsukov
Date:   Jan 30, 2015
About: Program 1:
	Write a C++ program that reads temperature in Celcius
	and displays it in Fahreniet. 
	(Temperature has decimals, use float)

Version 1.0 
	-working

*/

#include <iostream>

using namespace std;

int main(){
	float cel = 0.0;
	float feh = 0.0;
	
	
	cout << "Hello, welcome to the Temperature Converter Program.\n ";
	cout << "Ok, enter temperature in Celcius to be converted: ";
	cin >> cel;
		feh = ((cel *9)/5 ) + 32;
		
		cout << "\nThat will be: " << feh << " in Fehreniet.";
		
	return 0;
}
