

//include file
#include"dsA3.h"


//FunctionName:	copyContents(char *buffer, char* finalString)
//Project:		dsA2	
//Parameters:	char *buffer, char* finalString
//Description:	This function copies the contents of one buffer into another
//				through the use of a for loop.  During the transfer of characters, 
//				if the buffer containing the information being transfered encounters a 
//				"\", an extra backslash is appended and copied into finalString.
void copyContents( char buffer[], char finalString[] )
{
	//while loop to control function flow
	while( kTrue )
	{
		//variables used in program
		int i = 0;
		int r = 0;
		int c = 0;


		//find the number of characters and place into c variable
		c = strlen( buffer );

		//This loop copies the characters found in buffer to finalString one variable 
		//at a time.  If buffer contains a "\", place into finalString and place an extra "\" 
		//into finalString to prepare string for correct file path format. once finished, exit the loop
		for( i = 0; i <= (c); ++i )
		{
			finalString[r] = buffer[i];
			if( buffer[i] == '\\' )
			{
				++r;
				finalString[r] = '\\';
			}
			r++;
		}
		break;
	}
}

//FunctionName:	addFileExtension(char* addressOfLastCharacter, char *p, char* buffer, char* finalString)
//Project:		dsA2	
//Parameters:	char* addressOfLastCharacter, char *p, char* buffer, char* finalString
//Description:	This function uses pointers to locate the addres of the last character in buffer.
//				Once found, if the last character is a ".", "\*.mp3" is added to the string.
//				If "\" is found as the last character, "*.mp3" is added and if a regular letter or 
//				any other character is found, "\\*.mp3" is appended to the end of the string
void addFileExtension( char *p, char buffer[], char finalString[] )
{
	//variables initialized
	int c = 0;
	char* addressOfLastCharacter = NULL;

	//string length determined and placed into c
	c = strlen( buffer );
	
	while( kTrue )
	{
		//This section of code assigns the address of buffer to p
		//and is then used in an expression to calculate the address 
		//of the last character. Once found,  a series of if statements
		//will append the proper file extension to the matching case.
		p = buffer;
		addressOfLastCharacter = p + ( c - 1 );
		if(*addressOfLastCharacter == '.')
		{
			strcat( finalString, "\\\\*.mp3" );
			break;
		}
		if( *addressOfLastCharacter == '\\' )
		{
			strcat( finalString, "*.mp3" );
			break;
		}
		if( *addressOfLastCharacter != '\\' )
		{
			strcat( finalString, "\\\\*.mp3" );
			break;
		}
	}
}

//FunctionName:	void replaceAllDashesAndDots( char string[] )
//Project:		dsA2	
//Parameters:	char string[]
//Description:	This function finds any occureences of a dot or dash in the string parameter and replaces
//				it with a space.  When the end of the string is reached, Null is appended.
void replaceAllDashesAndDots( char string[] )
{
	int i = 0;
	int textCount = 0;

	//get the legnth of the string
	i = strlen( string );


	//go through the string and remove all dashes and dots and replace with a space.
	for( textCount = 0; textCount < i; ++textCount )
	{	
		/*if(string[textCount] == '-' )
		{
			string[textCount] = ' ';
		}*/
		if( string[textCount] == '.' )
		{
			string[textCount] = ' ';
		}
	}

	//if at the end, put a NULL at the end of the string
	if( textCount == i )
	{
		string[textCount] = '\0';
	}
}


// FUNCTION : correctNameFormat
// DESCRIPTION :
// This function will take in a name as a char and check to see if it is written in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains a name.
// char correctedFormat : This passes in a char with the corrected name format
// RETURNS : This function returns a status code depending on whether the input is valid or not.

void separateStrings( char string[], char artist[], char song[] )
{
	//variables initialized
	int c = 0;
	char buffer1[kBuffer] = {NULL};
	char *ptr = NULL;

	//use strtok to separate the input data into tokens
	if((ptr = strtok(string, "-")) != NULL )
	{
		strcpy( artist, ptr );
		//while there are more tokens to get....
		while(ptr != NULL )
		{
			if((ptr = strtok(NULL, ".")) != NULL )
			{
				//only want two names, song and artist so break
				strcpy( song, ptr );
				break;
			}
		}
	}
}
