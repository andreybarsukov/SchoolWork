/*

Author: Andrey Barsukov
Date:   Jan 30, 2015
About: Program 1:
	7. Write a C++ program to find factorial of a 
	given number using WHILE Loop.

Version 1.0 
	-working

*/

#include<iostream>

using namespace std;

int main(){
	
	int num = 0;
	int factorial = 0;
	
	cout << "Factorial Number Calculator \n Please enter a number: ";
	cin >> num;
	
	while (num < 1 ){
		cout << "\nPlease enter a number above zero: ";
		cin >> num;
	}
	
	factorial = num;
	
	while(num > 1){
		num--;
		factorial = factorial * num;
		
		
	}
	
	cout << "\nThe factorial is: " << factorial;
	
	return 0;
}
