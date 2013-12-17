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
	char* tempRead = NULL;
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
	
	/*
	while((fgets(tempRead, 60, stopFile)) != EOF)
	{
		printf("%d\n", sizeof(tempRead));
		tempWord = (Word*)malloc(sizeof(Word));
		wordNew(tempWord, tempRead);
		vectorPushBack(stopWords, tempWord);
		printf("%s\n", tempRead);
	}
	*/

	//tempWord = (Word*)malloc(sizeof(Word));

	tempRead = "elena";

	wordNew(&tempWord, tempRead);
	vectorPushBack(stopWords, tempWord);
	printf("%s\n", vectorGet(stopWords, 0)->string);

	/*
	for (i=0; i < stopWords->size; i++)
	{
		printf("%s\n", vectorGet(stopWords, i)->string);
	}
	*/
	for (i = 0; i < stopWords->size; ++i)
		wordDelete(vectorGet(stopWords, i));

	vectorDelete(stopWords);
	fclose(stopFile);

	return 0;

}

