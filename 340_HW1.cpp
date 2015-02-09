/*
Author: Andrey Barsukov
Date: 02, 08, 2015
About:
HW No. 1
About: HW No. 1

Problem 1
1. Reads in a paragraph of English text up to 100 words from the keyboard and stores this paragraph in a string object. 
Feel free to include this task in the main() function.

2. Identifies the least frequent letter (case insensitive) in the above paragraph. Implement a separate function getLeastFreqLetter() for this task. 
The main() function then calls this function to find out the least frequent letter and its frequency.

3. Calculate the frequency of each unique word (case insensitive). Implement another function countWordFreq() for this task. Use white spaces and 
punctuation marks such as comma, period, semicolon and question mark as word delimiters. Please define a global struct that contains two fields, 
word and its count for this task. You can then define an array of this struct to store all the unique words and its counts. The main() function will 
call this function to print out each word and its corresponding frequency.

4. Identify the most frequently occurring word in the paragraph. Implement another stand-alone function getMostFreqWord() for this purpose. 
This function will be called in main() to identify the most frequent word and its respective frequency.

Please provide a simple yet flexible user interface so other people can use & test your program.

Updates:

Version 1.0
	-started
*/

#include<iostream>
#include<string> //used for getline
#include<algorithm> //needed for transform
#include<sstream> //stream getline string
#include<vector>
#include<iomanip>  //needed to allignment 


using namespace std;

/* ---------------------------------------
STRUCT

Used to keep track of the frequency of each work in input string

------------------------------------------*/

struct wordStruct{
	
	int freq = 0;
	string word;
	
};

/*
Standalone class
Pre: must have #include<vector>

*/
void countWordFreq(vector<string> strVector){
	vector<wordStruct> wordStructVector;
	//wordStruct wordStructArray[100];
	//wordStructArray[0].freq = 1;
	if(!strVector.empty()){
	
		wordStruct temp;
		temp.word = strVector[0];
		temp.freq += 1;
		wordStructVector.push_back(temp);
		
		for(int i = 1; i < strVector.size(); i++){
			bool newWord = true;
			for(int j = 0; j < wordStructVector.size(); j++){
				if(strVector[i] == wordStructVector[j].word){
					wordStructVector[j].freq += 1;
					newWord = false;
				}
			}
			if(newWord){
				temp.word = strVector[i];
				temp.freq = 1;
				wordStructVector.push_back(temp);
			}
		}
	}
	else{
		cout << "The string was empty." << endl;
	}
	
	cout << "This is the FREQUENCY TABLE: \n" << endl;
	cout << "WORD                     FREQUENCY   " << endl;
	cout << "===================================" << endl;
	for(int k = 0; k < wordStructVector.size(); k++){
		
		cout << setw(20) << left << wordStructVector[k].word;
		cout << setw(10) << right << wordStructVector[k].freq << endl;
	}
};

void leastFreqLetter(vector<string> ){
	
}

int main(){
	string paragraph;
	wordStruct wordArray[100];
	vector<string> wordVector;
	vector<wordStruct> wordStructVector;
	char removeChars[] = {',' , ';' , ':' , '.' , '!' , '?' };
	
	cout << "Hello, please type in a paragraph of up to 100 words, anything over will be cut. (dont press enter until done)\n";
	
	getline(cin, paragraph);
	transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
	for(int j = 0; j<6; j++){
	paragraph.erase(remove(paragraph.begin(), paragraph.end(), removeChars[j] ), paragraph.end());
	}
	
	
	istringstream wordSS(paragraph);
	
	int wordCount = 0;
	while(wordSS){
		string word;
		wordSS >> word;
		//cout << word << endl;
		wordVector.push_back(word);
		wordCount++;
		if(wordCount > 100){
			break;
		}
	}
	
	countWordFreq(wordVector);
	
	//wordStruct wordStructArray[wordVector.size()];
	
	cout << "Words used in calculations: \n\n" << paragraph;
	
	return 0;
}







