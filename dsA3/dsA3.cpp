

//include file
#include"dsA3.h"

int main(int argc, char* argv[])
{
	//variables for use in the program initialized
	char finalString[kBuffer] = {0};
	char buffer[kBuffer] = {0};
	char string[kBuffer] = {0};
	char *p = NULL;
	char artist[kBuffer] = {0};
	char song[kBuffer] = {0};
	int count = 1;
	int c = 0;
	WIN32_FIND_DATA fileData = {0};
	HANDLE h = NULL;
	int exit = 0;
	int num = 0;
	int totalNum = 0;
	list<songInfo> myList;
	list<songInfo>::iterator i = myList.begin();

	//if agrument count is only 1 or no argument is detected
	//display error message and set exit to 1
	if(  argc == kTrue )
	{
		exit = 1;
		printf("Error: Usage dsAssignment1<directory...>\n");
	}
	else
	{
		//While loop to control program flow
		while( argv[ count ] != '\0' )
		{	
			//copy argument string into buffer
			strcpy( buffer, argv[ count ] );
			//if the buffer is empty, display message to the user
			//break out of the loop and try next directory
			if( buffer == NULL )
			{
				printf("String not copied\n");
				break;
			}

			//copy buffer contents to final string using the copyContents
			//ex.will copy C:\temp and create C:\\temp in finalString
			copyContents( buffer, finalString );

			//String is passed to addFileExtension to add the .mp3
			//extension
			addFileExtension( p, buffer, finalString );

			//will contain a proper directory name parameter
			//ex.C:\\temp\\*.mp3
			h = FindFirstFile( finalString, &fileData );
			if( h == INVALID_HANDLE_VALUE )
			{
				printf("nope no file found\n");
			}
			else
			{
				//Once the string has been prepared for file searching, it is passed to fileSearchAttachToList()
				//variables initialzed
				//function used to find file information passing handle to h
				//While .mp3 file data was found
				while( h != INVALID_HANDLE_VALUE )
				{
					struct songInfo *newEntry = NULL;
					++num;
					//This section of code allocates space in memory for string and copies the filename found
					//by findFirstFile into string.  The length of string is calculated and the file name is processed
					//to determine if any dashes or dot's appear in the file name.  Id they do, they are replaced with 
					//spaces.  
					//The size of string is determined and assigned to size, which is used to allocate space in memory for 3 three strings
					//to hold the artist name, song title and mp3 file extension
					strcpy( string, fileData.cFileName );
					//replaceAllDashesAndDots( string );

					//This section of code, scans the string and places the artist name, song title into
					//the 2 strings artist and song found in main.
					//flush the contents of stdin and calculate the index, add the words to the linked list and
					//hashtable
					separateStrings( string, artist, song );

					newEntry = (songInfo*)malloc(sizeof(songInfo));
					strcpy( newEntry->artist, artist );
					strcpy( newEntry->song, song );
					myList.push_back(*newEntry);
					//printf("%d: ARTIST: %s     SONG: %s%s\n", num, artist, song, ".mp3");

					//if could not find anymore files, set h to invalid handle value and exit loop
					if ( !FindNextFile( h, &fileData ))
					{
						FindClose(h);
						h = INVALID_HANDLE_VALUE;
						break;
					}
				} 
			}
			//Increment the argument count and proceed to find next directories mp3 files
			++count;
			//If there are no more arguments on the command line, list the linked list
			//information, free allocated memory and break out of final loop
			//to exit the program
			if(argv[count] == NULL)
			{
				//myList.sort();
				num = 0;
				for(i = myList.begin(); i != myList.end(); ++i) 
				{
					totalNum++;
					if( num == 20 )
					{
						num = 0;
						getch();
					}
					cout << totalNum << " " << num << " ARTIST: " << (*i).artist << " " << "SONG: " << (*i).song << endl; // print member
					cout << endl;
					++num;
				}

				break;
			}
		}
	}

	return 0;
}