/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*																				*
*	Module Name: Word															*
*	File type: header															*
*	Version: 1.0.11.14.2013														*
*																				*
*	Description: defines the function and variables of the word object			*
*	Note: assumes that the char* string will point to char array in the heap	*
*																				*
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#ifndef WORD
#define WORD

#include <stdio.h>
#include <string.h>

typedef struct
{
        char* string;
} Word;

void wordNew(Word*, char*);
void wordDelete(Word*);


#endif