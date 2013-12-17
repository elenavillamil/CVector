/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*                                                                               *
*	Module Name: Vector                                                          *
*	File type: implementation                                                    *
*	Version: 1.0.11.14.2013                                                      *
*                                                                               *
*	Description: implementation for a word object                                * 
*                                                                               *
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#include "Word.h"

/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	newWord:                                                                     *
*     allocated the memory for the word object, and allocates memory for the    *
*	   char* that the word object will hold. It copies the char* passed in into  *
*	   the memory allocated for the char* string                                 *
*                                                                               *
*	Parameters:                                                                  *
*     Word** myWord: adress of a pointer to a word object                       *
*     char* myString: char array with the word                                  *
*                                                                               *
*  Note:                                                                        *
*     If in windows it uses strcpy_s, safe mode that windows provide. Else, if  *
*     POSIX it uses strcpy                                                      *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void wordNew(Word** myWord, char* myString)
{
	*myWord = (Word*)malloc(sizeof(Word*));
	(*myWord)->string = (char*)malloc((strlen(myString) + 1) * sizeof(char));
	
	#ifdef _WIN32

	strcpy_s((*myWord)->string, (strlen(myString) + 1) * sizeof(char), myString);

	#else

	strcpy((*myWord)->string, myString);

	#endif
}



/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	wordDelete:                                                                  *
*     Frees the memory allocated for the "string" array and for the word object *
*	                                                                             *
*	Assumtion:                                                                   *
*     Assumes char* string points to a memory dinamically allocated             *
*	                                                                             *
*	Parameter:                                                                   *
*     Word* myWord: a pointer to the word                                       *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void wordDelete(Word* myWord)
{
	free(myWord->string);
	free(myWord);
}
