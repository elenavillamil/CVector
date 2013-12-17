/*EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/
/*																				*/
/*   To run from command line: gcc ./Headers ./Source ./main.cpp				*/
/*																				*/
/*EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"

int main()
{
	int i = 0;

	Vector* stopWords = NULL;
	char* tempStopWord;
	char* tempRead[60];
	Word* tempWord = NULL;
	
	
	/*create vector*/
	//stopWords = (Vector*)malloc(sizeof(Vector));
	vectorNew(&stopWords);

	/* Open file */
	
	/* If running windows */
	#ifdef _WIN32 

	FILE* stopFile = NULL;
	fopen_s(&stopFile, "../../Inputs/StopWords.txt", "r");
	
	/* If POSIX */
	#else 

		FILE* stopFile = fopen("./Inputs/StopWords.txt", "r");

	#endif
	
	/*If the file wasn't properly opened*/
	if (!stopFile)
	{
		printf("Couldn't open the stop words file\n");
		exit(0);
	}
	
	/*Read file with stop words*/
	while((fgets(tempRead, 60, stopFile)) != NULL)
	{
		wordNew(&tempWord, tempRead);
		vectorPushBack(stopWords, tempWord);
	}

	/*print the words pushed into the vector*/
	for (i=0; i < stopWords->size; i++)
		printf("%s\n", vectorGet(stopWords, i)->string);

	/*free the memory allocated for each element in the vector*/
	for (i = 0; i < stopWords->size; i++)
		wordDelete(vectorGet(stopWords, i));

	/*Free memory allocated for the vector object*/
	vectorDelete(stopWords);
	
	fclose(stopFile);

	return 0;

}

