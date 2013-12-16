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
	char* temp;
	Word* tempWord = NULL;
	
	
	/*create vector*/
	stopWords = (Vector*)malloc(sizeof(Vector));
	vectorNew(stopWords);

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
	while(fgets(tempStopWord, 1000, stopFile) != NULL)
	{
		temp = (char*) malloc(sizeof(tempStopWord));
		copy tempStopWord into temp
		tempWord = newWord(temp);
		vectorPushBack(stopWords, tempWord);
		printf("%s\n", tempStopWord);
	}
	*/
	tempStopWord = (char*)malloc(6 * sizeof(char));

	strcpy_s(tempStopWord, 6 * sizeof(char), "elena");
	tempWord = (Word*)malloc(sizeof(Word));
	wordNew(tempWord, tempStopWord);
	vectorPushBack(stopWords, tempWord);
	printf("%s\n", vectorGet(stopWords, 0)->string);
	/*
	for (i=0; i < stopWords->size; i++)
	{
		printf("%s\n", vectorGet(stopWords, i)->string);
	}
	*/
	for (i = 0; i < stopWords->size; i++)
		wordDelete(vectorGet(stopWords, i));

	vectorDelete(stopWords);
	free (stopWords);
	fclose(stopFile);

	return 0;

}

