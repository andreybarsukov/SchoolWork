/*

Author: Andrey Barsukov
Date: 2/3/2015
About:


*/

\
#include<iostream>
#include<vector> //package to include vectors, a DYNAMIC ARRAY

using namespace std;

//CONSTANT  declared outside of class;
const double PI = 3.14;

//NEW FUNCTION
void test1 (int, double){
	
}
//-------------------
//Test function
double is_even(int x){
	//identifiers of a function (return type, input data
}
//-----------------

//NEW CLASS
class myTestClass{
	
};

//TYPE DEFINE
//can carate an alias of an existing data type
//make your program easier ot modify and read

//ex
typedef in typeOfAge;



int main(){
	
	double temperature = 0.0;
	int ary[100];
	bool isHot = true;  //NOT BOOLEAN, just bool
						//BOOL can take ANY int. (0, 1, ...)
	bool intBool = 0; 	//false. NON-ZERO = TRUE

	vector<int> v_int(10);
	vector<double> d_int(100);
	
	int temp = 0;
	char ch = 'a';
	
	
//-----------------------------------------------------------//

										
	if(intBool == 4){
		//can cause hard to spot bug, need ==
		//compiler will assign 4, will always true
	}
	
//-----------------------------------------------------------//

						//Can use int as bool
	
	if(temp){
		//this will be false;
		cout << "Temp is true" << endl;
	}	
	else{
		cout << "Temp is false" << endl;
	}
	
	cout << "intBool: " << intBool << endl;
	
	for (int i = 0; i < 100; i++){  //initialize the whole array
									//will not give error is try to access memory outside of array
		ary[i] = 0;
	}
	
	
	cout << "What's today's temperature? ";
	cin >> temperature;
	cout << "\nYou have just typed: " << temperature << endl;
	
	return 0;
	
}

//AUTO DETECT
//in C++11
//auto myint = 0.1;  //will declare as a double 
