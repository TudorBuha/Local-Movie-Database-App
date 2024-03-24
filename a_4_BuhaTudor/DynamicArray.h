#pragma once


template <typename TElem>
class DynamicArray
{
private:
	
	int capacity, size;
	TElem* elements;
	void resize();


public:

	//constructor 
	DynamicArray(int initialCapacity = 10);

	//destructor
	~DynamicArray();

	//copy constructor
	DynamicArray(const DynamicArray& dynaicArrayToCopy);

	//assignment operator
	DynamicArray& operator=(const DynamicArray& dynamicArrayToCopy);


	//methods for the DynamicArray

	void addElement(const TElem& elementToBeAdded);
	void removeElement(int indexFromWhereToBeRemoved);
	void updateElement(int indexOfElementToBeUpdated, TElem updatedElement);
	int getSize();
	TElem getElement(int indexOfElementToGet);
	int findPositionOfElement(TElem elementToFindPosistion);
};


///////////////
template <typename TElem>
void DynamicArray<TElem>::resize()
{
	int tempCapacity = this->capacity * 2;
	TElem* tempElems = new TElem[tempCapacity];
	if (tempElems == nullptr)
	{
		return;
	}
	this->capacity = tempCapacity;
	for (int index = 0; index < this->size; index++)
	{
		tempElems[index] = this->elements[index];
	}
	delete[] this->elements;
	this->elements = tempElems;
}

template <typename TElem>
DynamicArray<TElem>::DynamicArray(int initialCapacity)
{
	this->size = 0;
	this->capacity = initialCapacity;
	this->elements = new TElem[initialCapacity];
	//this->elems = new TElem[this->capacity];
}

template <typename TElem>
DynamicArray<TElem>::~DynamicArray()
{
	delete[] this->elements;
}

template <typename TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray& dynamicArrayToCopy)
{
	this->size = dynamicArrayToCopy.size;
	this->capacity = dynamicArrayToCopy.capacity;
	this->elements = new TElem[this->capacity];
	for (int index = 0; index < this->size; index++)
	{
		this->elements[index] = dynamicArrayToCopy.elements[index];
	}
}

template <typename TElem>
DynamicArray<TElem>& DynamicArray<TElem>::operator=(const DynamicArray& dynamicArrayToCopy) // makes a deep copy of the dynamic array
{
	this->size = dynamicArrayToCopy.size;
	this->capacity = dynamicArrayToCopy.capacity;
	delete[] this->elements;

	this->elements = new TElem[this->capacity];

	for (int index = 0; index < this->size; index++)
	{
		this->elements[index] = dynamicArrayToCopy.elements[index];
	}

	return *this; // returns a reference to the current object
}

template <typename TElem>
void DynamicArray<TElem>::addElement(const TElem& elementToBeAdded)
{
	if (this->size == this->capacity)
		this->resize();

	this->elements[this->size] = elementToBeAdded;
	this->size++;
}

template <typename TElem>
void DynamicArray<TElem>::removeElement(int indexFromWhereToRemove)
{
	if (indexFromWhereToRemove < 0 || indexFromWhereToRemove>this->size)
		return;
	TElem* tempElements = new TElem[this->capacity];
	for (int index = 0; index < indexFromWhereToRemove; index++)
		tempElements[index] = this->elements[index];
	for (int index = indexFromWhereToRemove + 1; index < this->size; index++)
		tempElements[index - 1] = this->elements[index];

	delete[] this->elements;
	this->elements = tempElements;
	this->size--;
}

template<typename TElem>
void DynamicArray<TElem>::updateElement(int indexOfElementToBeUpdated, TElem updatedElement)
{
	this->elements[indexOfElementToBeUpdated] = updatedElement;
}

template<typename TElem>
int DynamicArray<TElem>::getSize()
{
	return this->size;
}

template<typename TElem>
TElem DynamicArray<TElem>::getElement(int indexOfElementToGet)
{
	return this->elements[indexOfElementToGet];
}

template<typename TElem>
int DynamicArray<TElem>::findPositionOfElement(TElem elementToFindPosistion)
{
	for (int index = 0; index < this->size; index++)
		if (elementToFindPosistion == this->elements[index])
			return index;

	return -1;
}
