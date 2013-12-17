/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *
*                                                                               *
*	Class Name: Vector                                                           *
*	File Type: implementation                                                    *
*	Version: 1.0.11.14.2013                                                      *
*                                                                               *
*	Description: implementation for vector functionallity                        *
*                                                                               *
* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

#include "Vector.h"


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	vectorNew:                                                                   *
*     allocates space for a vector's data array and it sets its the             *
*	   vector size and capacity                                                  *
*                                                                               *
*	Parameters:                                                                  *
*      Vector** myVector: address of the pointer to the Vector object           *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorNew(Vector** myVector)
{
	*myVector = (Vector*)malloc(sizeof(Vector));

	(*myVector)->size = 0;
	(*myVector)->capacity = increase;
	(*myVector)->data = (myType*) malloc (sizeof(myType)*increase);
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	vectorPushBack:                                                              *
*     Pushes am object to the end of the vector                                 *
*                                                                               *
*	Parameters:                                                                  *                                                                           *
*     Vector* self: a pointer to the vector to push back                        *
*     myType object: object of the type the vector holds                        *
*                                                                               *
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
*                                                                               *
*	vectorResize:                                                                *
*                                                                               *
*     Resize the data array in the vector. Increases the size by the value      *
*	   define in "increase".                                                     *
*                                                                               *
*	Parameters:                                                                  *
*     Vector* self: pointer to the Vector containg the array to be resized      *
*                                                                               *
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
*                                                                               *
*	vectorInsert:                                                                *
*     inserts an object of the type the vector holds in the specifiec position  *
*	                                                                             *
*	Parameters:                                                                  *
*     Vector* self: a pointer to the vector                                     *
*     int position: position in wich the value will be inserted                 *
*     myType object: the object ot be inserted in that position                 *
*                                                                               *
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
*                                                                               *
*	vectorGetSafe:                                                               *
*     return the value in the specified position. Always check to make sure it  *
*     isn't trying to get something out of bounds                               *
*                                                                               *
*	Parameters:                                                                  *
*     Vector* self: pointer to the vector                                       *
*     int position: position of the element to be returned                      *
*                                                                               *
*	Return type:                                                                 *
*     myType: return an object of the type that the vector holds                *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
myType vectorGetSafe(Vector* self, int position)
{
   if (position >= self->size)
   {
      printf("The program is trying to access an element that is outside the bondurais of the vector\n");
      exit(1);
   }

   return self->data[position];
}



/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	vectorGet:                                                                   *
*     return the value in the specified position. If not in debug mode, it      *
*     returns without checking if the position is out of bounds (< safe, > fast)*
*                                                                               *
*	Parameters:                                                                  * 
*     Vetor* self: pointer to the vector                                        *
*     int position: the position that contains the element to be returned       *
*                                                                               *
*	Return type:                                                                 *                                                            
*     myType: an object of the type that the vector holds                       *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
myType vectorGet(Vector* self, int position)
{
   assert(position <= self->size);

	return self->data[position];
}


/* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee *
*                                                                               *
*	vectorDelete:                                                                *
*     frees the memory allocated for the vector and for the vector's data array *
*                                                                               *
*	Assumtion:                                                                   *
*     if each element of the array holds pointers they must be previously freed *
*                                                                               *
*	Parameter:                                                                   *
*     Vector* myVector: a pointer to the vector                                 *
*                                                                               *
* eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */
void vectorDelete(Vector* myVector)
{
	free (myVector->data);
	free(myVector);
}

