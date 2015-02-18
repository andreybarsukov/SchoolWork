/*

Author: Andrey Barsukov
Date: 02/11/2015
About: 340 HW1 Problem 2

Problem 2: Implement another C++ program to sort a list of integers using the selection sort algorithm. You are required to:
	1. use an integer vector to store the input numbers typed from the keyboard. The declaration of this vector will be in main(). 
	   You'll need to implement a separate function readData() to read numbers from the keyboard;
	
	2. implement a separate function called selectionSort(), which will be called by the main() function to sort the afore-mentioned vector;
	
	3. implement another function printVector() to print out the content of the vector. This function will be called by main() right after 
		calling readData() and selectionSort(), respectively, to print out the vector content before and after being sorted.
		
version 1.0
 - started
 
 */
 
 
 #include<iostream>
 #include<vector>
 #include<limits> //used for cin.limits
 
using namespace std;

void readData(vector<int> &refVector){
	cout << "How many numbers would you like to sort? (2-100)\n ";
	int input = 0;
	int sortAmount = 0; 
		
	while(!(cin >> sortAmount) || sortAmount < 2 || sortAmount > 100){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Please try again (2-100): \n";
	}
	cout << "You want to sort: " << sortAmount << " numbers. \nPlease enter each number followed by the [ENTER] key."<< endl;
			
	
	for(int i = 0; i<sortAmount; i++){
		input = 0;
		while(!(cin >> input)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter your number again: \n";
		}
		refVector.push_back(input);
	}
};


void printVector(vector<int> &refVector){
	cout << "[";
	for(int j = 0; j<refVector.size()- 1; j++){
		cout << refVector[j] << ",";
	}
	cout << refVector[refVector.size() - 1]<< "]";
};

void selectionSort(vector<int> &refVector){
	int minIndex = 0;
	int temp = 0;
	
	for (int i = 0; i < refVector.size(); i++){
		minIndex = i;
		for(int j = i+1; j<refVector.size(); j++){
			if(refVector[j] < refVector[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex != i){
			temp = refVector[i];
			refVector[i] = refVector[minIndex];
			refVector[minIndex] = temp;
		}
	}
	
};

int main(){
	vector<int> intVector;
	
	readData(intVector);
	printVector(intVector);
	cout << endl;
	selectionSort(intVector);
	printVector(intVector);
	
	
	
	
}
