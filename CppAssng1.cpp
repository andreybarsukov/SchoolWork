/*

Author: Andrey Barsukov
Date: Jan 30, 2015
About: trying a program


*/

#include <iostream>
using namespace std;
int main(){
	
	int digOne = 0;
	int digTwo = 0;
	int digitSum = 0;
	
	cout << "Hello, this is my second program, I am just trying something here\n";
	cout << "Ok, enter digit one:\n";
	cin >> digOne;
	cout << "Great, now enter digit two: \n";
	cin >> digTwo;
	digitSum = digOne + digTwo;
	
	cout << "Ok now, the sum of the two digits you have entered is: " << digitSum;
	
	return 0;
}
