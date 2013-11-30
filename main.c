//#include <stdio.h>
#include "Vector.c"

int main()
{
	int i = 0;
	Vector* stopWords = newVector();
	char tempStopWord[200];
	Word* tempWord;
	FILE* stopFile = fopen ("StopWords.txt", "r");
	
	if (!stopFile)
	{
		printf("Couldn't open the stop words file\n");
		exit(0);
	}
	while(fgets(tempStopWord, 1000, stopFile) != NULL)
	{
		//printf("%d\n",i);
		//i = i + 1;
		tempWord = (Word*) malloc(sizeof(Word));
		tempWord->string = (char*) malloc(sizeof(tempStopWord));
		tempWord->string = tempStopWord;
		pushBack(stopWords, tempWord);
	}
	for (i=0; i < stopWords->size; i++)
	{
		printf("%s\n", get(stopWords, i)->string);
	}
	delete (stopWords);
	free (stopWords);
	fclose(stopFile);
}

