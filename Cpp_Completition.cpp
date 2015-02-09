/*

Author: Andrey Barsukov
Date:   Jan 30, 2015
About: Program 1:
Try making the following program, In case you need 
some help, mail me at dhruvkumarverma@outlook.com

--> Write a C++ program for the following situation :-

Name of Class :- Competition

Private Members :-
event_no - integer type
description -char(30)
score - integer type
qualified - char(1)

Public Members :-
input() - To take input for event_no, description and score
award() - To award qualified as  'Y' if score is greater than cutoff, else 'N'.
show() - To show all details

Assumption :-
Assume cutoff to be a variable which will be entered by the user 
at time of program execution.

Version 1.0 
	-problems with scope

*/

#include<iostream>


using namespace std;

int main(){
comp.show();

}

class Competition{
		public:
			void input();
			void award();
			void show();
}comp;
	
	void Competition :: input(){
		int event_no = 0;
		string description = " (No entry)";
		int score = 0;
		
		cout << "Please enter the event number (enter zero (0) to finish input: )";
		cin >> event_no;
		cout << "Please enter description of the competition: ";
		cin >> description;
		cout << "\nEnter the score recieved (0-20): ";
		cin >> score;
	}
	
	void Competition :: award(){
		char qualified = 'N';
		if(score > 9){
			qualified = 'Y';
		}
	}
	
	void Competition :: show(){
		do{
			comp.input();
			comp.award();
			cout << "\nEvent number: " << event_no;
			cout << "\nCompetition: " << description;
			cout << "\nQualified?: " << qualified;
			
		}while(even_no > 0);
		cout >> "No more events.";
	} 

