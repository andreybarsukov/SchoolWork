#include <iostream>
#include <stdlib.h> // depending on your ide, you may need to include this line
using namespace std;


/*
 * returns the number of non \0 characters in the string
 */
int length(char *strPtr){
	int length = 0;
	while( *(strPtr++) != 0 )
		length++;
	return length;
}


char *copy(char *strPtr){
	int strLen = length(strPtr);	

	// initializes an array of chars the same length as the
	// array that is passed to the function.

	// malloc() allocates the memory, then returns a void pointer
	// to the new array in memory.  A void pointer is, essentially, 
	// a pointer without type info.  This void pointer is then
	// cast to the correct type of pointer before being assigned to
	// the copyStr.
	// The address that is returned by malloc() is the first address 
	// in the newly allocated array.  Checking for NULL ensures no 
	// error occurred with malloc() when called.
	
	char *copyPtr  = (char *)malloc(strLen * sizeof(char) + 1);
	if( copyPtr == NULL ){
		cout << "Error:  Cannot allocate new string, aborting." << endl;
		exit(1);
	}

	// +---
	// |
	// | Your code to copy the string from strPtr to copyPtr goes here
	// |
	// +---

	for(int i = 0; i<strLen; i++){
		strPtr[i] = copyPtr[i];
	}
	
	return copyPtr;
}

// reverse() reverses the string (NOT a copy!) that was passed to it.
void reverse(char *strPtr){
	//char *revPtr;
	
	// +---
	// |
	// | Your code to reverse the string goes here
	// |
	// +---
	int revStrLen = length(strPtr);
	char *revPtr = (char *)malloc(revStrLen * sizeof(char) + 1);
	if (revPtr == NULL ){
		cout << "Error: Cannot allocate new string, aborting." << endl;
		exit(1);
	}
	
	for(int i = 0; i<revStrLen; i++){
		revPtr[i] =  strPtr[revStrLen -1 - i];
	}
	
	
	//for(int j = 0; j<revStrLen; j++){
	//	revPtr[j] = strPtr[j];
	//}
	
}

// copyReverse() reverses a copy of the string that was passed to it.
char *copyReverse( char *strPtr ){
	char *cpyPtr;
	
	// +---
	// |
	// | Your code to reverse the string copy goes here
	// |
	// +---
	cpyPtr = copy(strPtr);
	reverse(strPtr);
	
	//reverse(cpyPtr = copy(strPtr));

	return cpyPtr;
}

/*
 * In-class exercise 1
 *
 * Submit a working copy of this on paper in class on Friday, Feb 13 at the
 * beginning of class.  Be sure to include your name and your partner's name
 * on the submission.
 *
 * The program should:
 *
 * 1) using the above functions copy str to a new string and print the new
 *    string out;
 * 2) reverse the copy of str and print it out
 * 3) copy and reverse the reversed string and print it out
 *
 * YOU MAY ONLY CALL FUNCTIONS THAT ARE PROVIDED ABOVE!  
 * 
 */
 
int main(){
	char *str = (char *)"Hello"; 	// cast to avoid deprecation warning
  
	char *newStr = copy(str);
	cout << "Copy of the string: " << newStr << endl;

	reverse(newStr);
	cout << "Reversed copy after reverse: " << newStr << endl;
	
	char *rightWayCopy = copyReverse(newStr);
	cout << "New string in correct direction: " << rightWayCopy << endl;

	return 0;
}
