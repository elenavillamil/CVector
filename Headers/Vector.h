#ifndef VECTOR
#define VECTOR
#include "Word.h"
#include <stdlib.h>
#include <stdio.h>
#define myType Word*
#define increase 50

typedef struct
{
        int size;
        int capacity;
        myType* data;
} Vector;


void vectorPushBack (Vector*, myVector);
void vectorResize(Vector*);
void vectorInsert(Vector*, int, myType;
myType vectorGet(Vector*, int);
void deleteVector(Vector*);
Vector* newVector();

#endif
