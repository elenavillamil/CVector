/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*                                                                               *
*	Module Name: Vector                                                         *
*	File type: implementation													*
*	Version: 1.0.11.14.2013														*
*																				*
*	Description: implementation for a word object								*
*                                                                               *
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#include "word.h";

/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*									 											*
*	newWord: sets the adress of the	variable named string of type char* to the 	*
*	address of the char* passed in. This is a sallow copy; it is faster than	*
*	deep copy, and in this case deep copy isn't needed 							*
*	Parameters: a pointer to a word object and a poine to a char array with the *
*	word																		*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void wordNew(Word** myWord, char* myString)
{
	*myWord = (Word*)malloc(sizeof(Word*));
	(*myWord)->string = (char*)malloc((strlen(myString) + 1) * sizeof(char));
	strcpy_s((*myWord)->string, (strlen(myString) + 1) * sizeof(myString), myString);

	free((*myWord)->string);
}



/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	wordDelete: frees the memory allocated for the "string" array and for the  	*
*	word object																	*
*	Assumtion: assumes char* string points to a memory dinamically allocated	*
*	Parameter: a pointer to the word											*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void wordDelete(Word* tempWord)
{
	free(tempWord->string);
	free(tempWord);
}
