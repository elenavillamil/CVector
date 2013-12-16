/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*																				*
*	Module Name: Vetor															*
*	File type: header															*
*	Version: 1.0.11.14.2013														*
*																				*					
*	Description: defines the function and variables of the vector object		*
*																				*
*	Notes: #define myType should be set to whatever type the vectoy will contain*
*	and #define increase determine the increae on the size of hte vector every	*
*	time it has to be resized.													*
*																				*
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#ifndef VECTOR
#define VECTOR

#include "Word.h"
#include <stdlib.h>
#include <stdio.h>

#define myType Word*
#define increase 50

typedef struct Vector
{
        int size;
        int capacity;
        myType* data;
} Vector;


void vectorPushBack (Vector*, myType);
void vectorResize(Vector*);
void vectorInsert(Vector*, int, myType);
myType vectorGet(Vector*, int);
void vectorDelete(Vector*);
void vectorNew(Vector*);

#endif
