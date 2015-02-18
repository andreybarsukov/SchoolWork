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
#include<limits> //used for cin.limits in UI

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
vector<wordStruct> countWordFreq(vector<string> strVector){
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
	
	return wordStructVector;
};

vector<char> getLeastFreqLetter(string passedStr){
	//vector<char> charOnlyVector;
	//copy(passedStr.begin(), passedStr.end(), ::back_inserter(charOnlyVector));
	int arySize = 26;
	int charFreqArray[arySize];
	char curChar;
	char leastFreqChar;
	int curCharInt = 0;
	int leastFreqCharPos = 0;
	int leastFreqCharCount = passedStr.size(); //declared to max size of possible repeating chars to have something to compqare to
	vector<char> charFreqTie;   //returns a vector is chars that are tied for least frequent
	
	for(int i = 0; i<arySize; i++){
		charFreqArray[i] = 0;
	}
	
	for(int j = 0; j<passedStr.size(); j++){
		curCharInt = (int)(passedStr[j]);
		if(curCharInt >= 'a' && curCharInt <= 'z'){
			charFreqArray[curCharInt - 'a'] += 1;
		}
	}
	
	for (int k = 0; k<arySize; k++){
		
		if((leastFreqCharCount > charFreqArray[k]) && (charFreqArray[k] > 0)){
			leastFreqCharCount = charFreqArray[k];
			leastFreqCharPos = k;
		}
	}
	
	//cout << "LEAST FREQ LETTER COUNT: " << leastFreqCharCount << endl;
	
	for (int h = 0; h<arySize; h++){
		if(charFreqArray[h] == leastFreqCharCount){
			charFreqTie.push_back(h + 'a');
		}
	}
	
	//leastFreqChar = leastFreqCharPos + 'a';
	return charFreqTie;
};

string getMostFreqWord(vector<wordStruct> structVector){
	wordStruct mostFreqWordCount = structVector[0];  //loads the first word for comparison
	
	for(int i = 0; i<structVector.size(); i++){
		if(mostFreqWordCount.freq < structVector[i].freq){
			mostFreqWordCount = structVector[i];
		}
	}
	
	return mostFreqWordCount.word;
};

void displayOptions(){
		cout << "\n\nPlease select one: " << endl;
		cout << "COMMAND                      KEY" << endl;
		cout << "================================" << endl;
		cout << "Get least frequent letter     1" << endl;
		cout << "Display word freqency table   2" << endl;
		cout << "Display most freqent word     3" << endl;
		cout << "Display all of the above      4" << endl;
		cout << "QUIT                          5" << endl;
};


int main(){
	string paragraph;
	wordStruct wordArray[100];
	vector<string> wordVector;
	vector<wordStruct> wordStructVector;
	vector<char> leastFreqLettersVector;
	char removeChars[] = {',' , ';' , ':' , '.' , '!' , '?' };
	string mostFreqWord;
	int option = 0;
	
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
	
/*
	do{
		//displayOptions();
		//cin >> option;
		bool displayAll = false;
		while ( !(cin >> option) || option < 1 || option > 5){
			cout << "INVALID SELECTION" << endl;
			displayOptions();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if(option = 4){
			displayAll = true;
		}
		
		if(option = 1 || displayAll){
			cout << "DO WHILE: The least freqent letter is: " << leastFreqLetter(paragraph) << "\n\n";
		}
		if(option = 2 || displayAll){
			wordStructVector = countWordFreq(wordVector);
			cout << "DO WHILE: This is the FREQENCY TABLE: \n" << endl;
			cout << "WORD                     FREQENCY   " << endl;
			cout << "===================================" << endl;
			for(int k = 0; k < wordStructVector.size(); k++){
			
			cout << setw(20) << left << wordStructVector[k].word;
			cout << setw(10) << right << wordStructVector[k].freq << endl;
			}
		}
		if(option = 3 || displayAll) {
			cout << "\n\nDO WHILE: The MOST FREQENT word is:  " << getMostFreqWord(wordStructVector) << endl;
		}
		
	}while(option != 5);
*/
	//START display least freq letter
	leastFreqLettersVector = getLeastFreqLetter(paragraph);
	cout << "The least Freq letter(s) is(are): " << endl <<"[";
		
	for(int w = 0; w<leastFreqLettersVector.size()-1; w++){
		cout << leastFreqLettersVector[w] << ", ";
	}
	cout << leastFreqLettersVector[leastFreqLettersVector.size() - 1 ]<< "]" << endl << endl;  //display the last letter in tie WITHOUT ',' (camma)
	
	//END display least freq letter
		
	wordStructVector = countWordFreq(wordVector);
	
	cout << "This is the FREQUENCY TABLE: \n" << endl;
	cout << "WORD                     FREQUENCY   " << endl;
	cout << "===================================" << endl;
	for(int k = 0; k < wordStructVector.size(); k++){
		
		cout << setw(20) << left << wordStructVector[k].word;
		cout << setw(10) << right << wordStructVector[k].freq << endl;
	}
	
	cout << "\n\n The MOST FREQ word is:  " << getMostFreqWord(wordStructVector) << endl;
	
	cout << "Words used in calculations: \n\n[";
	for(int t = 0; t<wordVector.size(); t++){
		cout << wordVector[t] << " ";
	}
	cout << "]" << endl;
	
	
	return 0;
}







