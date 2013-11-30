/*EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE//
//                                                                              //
//	Class Name: Vector                                                      //
//	Version: 1.0.11.14.2013                                                 //
//	Description: my own vector class                                        //
//                                                                              //
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/

/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//									 	//
//	Creates a new vector object, initializes the array containing the data	//
//	and returns a pointer to the vector object				//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
Vector* newVector()
{
	Vector* myVector = (Vector*)malloc (sizeof(Vector));
	myVector->size = 0;
	myVector->capacity = increase;
	myVector->data = (myType*) malloc (sizeof(myType)*increase);
        return myVector;
}


/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//										//
//	Adds an object to the end of the vector					//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
void pushBack (Vector* self, myType object)
{
	self->data[self->size++] = object;
	
	if (self->size == self->capacity)
	{
		resize (self);
	}
}


/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//										//
//	Resize the array that contains the vectos data. Increases the size by 	//
//	the value define in "increase".						//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
void resize (Vector* self)
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


/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//										//
//	Inserts a value in the position passed in. 				//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
void insert(Vector* self, int position, myType object)
{
	while (self->capacity <= position)
	{
		resize(self);	
	}
	self->data[position] = object;
}


/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//										//
//	Return the element in the position passed in.				//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
myType get(Vector* self, int position)
{
	if (position >= self->size)
	{
		printf("The program is trying to access an element that is outside the bondurais of the vector\n");
		exit(1);
	}

	return self->data[position];
}


/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee//
//										//
//	Frees the memory allocated for the data array. Assumes that if the array//
//	holds pointers they will get free in main				//
//										//
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
void delete(Vector* myVector)
{
	free (myVector->data);
}

