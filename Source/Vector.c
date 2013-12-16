/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*                                                                               *
*	Class Name: Vector                                                          *
*	File Type: implementation													*
*	Version: 1.0.11.14.2013														*
*																				*
*	Description: implementation for vector functionallity						*
*                                                                               *
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#include "Vector.h"


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*									 											*
*	vectorNew: allocates space for a vector's data array and it sets its the 	*
*	vector size and capacity													*
*	Parameters: a pointer to a vector											*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorNew(Vector* myVector)
{
	myVector->size = 0;
	myVector->capacity = increase;
	myVector->data = (myType*) malloc (sizeof(myType)*increase);
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	vectorPushBack: pushes am object to the end of the vector					*
*	Parameters: a pointer to the vector and an object of the type the vector 	*
*	holds																		*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorPushBack (Vector* self, myType object)
{
	self->data[self->size++] = object;
	
	if (self->size == self->capacity)
	{
		vectorResize (self);
	}
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	vectorResize: resize the data array in the vector. Increases the size by 	*
*	the value define in "increase".												*
*	Parameters: a pointer to the Vector containg the array to be resized		*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorResize (Vector* self)
{
	int i;
	myType* temp = self->data;
    self->capacity += increase;
    self->data = (myType*) malloc (sizeof(myType)*self->capacity);
    for (i = 0; i < self->capacity - increase; ++i)
    {
        self->data[i] = temp[i];
    }
    free (temp);
} 


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	vectorInsert: inserts an ob ject of the type the vector holds in the		*
*	specifiec position															*
*	Parameters: a pointer to the vector, the position in which the value will	*
*	be inserted, and the object of the type the vector suports					*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorInsert(Vector* self, int position, myType object)
{
	while (self->capacity <= position)
	{
		vectorResize(self);	
	}
	self->data[position] = object;
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	vectorGet: return the value in the specified position						*
*	Parameters: a pointer to the vector, the position that contains the element	*
*	Return type: an object of the type that the vector holds					*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
myType vectorGet(Vector* self, int position)
{
	if (position >= self->size)
	{
		printf("The program is trying to access an element that is outside the bondurais of the vector\n");
		exit(1);
	}

	return self->data[position];
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*																				*
*	vectorDelete: frees the memory allocated for the data array of the vector. 	*
*	Assumtion: if the array holds pointers they would have been previously freed*
*	Parameter: a pointer to he vector											*
*																				*
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorDelete(Vector* myVector)
{
	free (myVector->data);
}

