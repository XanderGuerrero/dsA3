//FileName: mini2.cpp
//Project:	mini2
//Author:	Alex Guerrero
//Date:		March 11, 2014
//Description:	This program uses a standard template library vector to store words inputted by the user.
//				The program then asks the user to enter words to search for in the vector.  If a match is
//				found, The program displays "Success!". If no match is found, the program displays "Not there!".



//Include files
#include<string>
#include<vector>
#include<iostream>
using namespace std;



//Defined constants
#define kOne 1



int main(void)
{
	//Variables initialized
	vector<string> words;
	vector<string>::iterator element = words.begin();
	string userInput;
	int i = 0;
	const int kStringLength = 100;

	while( kOne )
	{
		//This section of code prompts the user to enter a word to store inside the vector
		// or to exit the program by entering the "." character.
		//The user input is stored in a buffer called userInput. 
		cout << "Enter a word to store\nTo exit press \".\"\n" << endl;
	
		getline(cin, userInput);
		//if the "." character is found, exit the loop and proceed to the search section of the program
		if( userInput == "." )
		{
			break;
		}
		//if the word is acceptale, add the word to the vector 
		words.push_back(userInput);
	}
	//set the userInput buffer to empty
	userInput = '\0';

	cout << "\n" << endl;

	while( kOne )
	{
		//this isection of code prompts the user to search for words stored in the vector.
		//to exit the search the user must press ".".  The user input is placed into the userInput
		//buffer.
		cout << "Enter a word to search for inside the vector\nTo exit press \".\"\n" << endl;

		getline(cin, userInput);
		//if the "." is the only thing in the buffer, exit the loop, exit the program
		if( userInput == "." )
		{
			break;
		}
		//if a word is entered to search for, enter the for loop and go through the vector
		// and look for a match using the value of the iterator as comparison
		for(element = words.begin(); element != words.end(); ++element )
		{
			//if a match is found, display "Success!" and break out of the loop 
			//to search for more words
			if( *element == userInput )
			{
				cout << "\n";
				cout << "Success!\n" << endl;
				break;
			}
			//if you reach the last word in the vector, exit the loop
			if( element == words.end() - 1 )
			{
				break;
			}
		}
		//if the value of the last iterator in the list is not the same as the users search word,
		// display "Not there!"
		if( *element != userInput )
		{
			cout << "\n";
			cout << "Not there!\n" << endl;
		}
		//Set userInput buffer to empty
		userInput = '\0';
	}

	return 0;
}