#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<Windows.h>
#include<iostream>
#include<list>
#include<new.h>


using namespace std;



//disables a warning to allow the use of depreciated functions
#pragma warning(disable: 4996)



#define kTrue 1
#define kBuffer 256
#define kALL_GOOD 2



struct songInfo
{
	char artist[kBuffer];
	char song[kBuffer];
};



void copyContents( char buffer[], char finalString[] );
void addFileExtension( char *p, char buffer[], char finalString[] );
void replaceAllDashesAndDots( char string[] );
void separateStrings( char string[], char artist[], char song[] );



