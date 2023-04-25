#ifndef UNORDEREDARRAYLISTTYPE_H
#define UNORDEREDARRAYLISTTYPE_H

#include "arrayLisType.h"

template<class elemType>
class unorderedArrayListType : public arrayLisType<elemType>
{
    public:
        unorderedArrayListType(int size = 100);//constructor
        int seqSearch(const elemType& searchItem)const;
        void insertAt(int location, const elemType& insertItem);
        void insertEnd(const elemType& insertItem);
        void replaceAt(int location, const elemType& repItem);
        void remove(const elemType& removeItem);
};

template<class elemType>
int unorderedArrayListType<elemType>::seqSearch(const elemType& searchItem)const
{
    int loc;
    bool found = false;
    for (loc = 0; loc<this->length; loc++)
        if (this->list[loc]== searchItem)
        {
            found = true;
            break;
        }
    if(found)
        return loc;
    else
        return -1;
}


template<class elemType>
void unorderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if(location < 0 || location >= this->maxSize)
        cout<<"Location requested is out of range!! "<<endl;
    else if(this->length >= this->maxSize)
        cout<<"Regrettably array is full..."<<endl;
    else
    {
        for(int i = this->length; i>location; i--)
            this->list[i]=this->list[i-1];//copy forward
        this->list[location]= insertItem;
        this->length++;
    }
}

template<class elemType>
void unorderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    //length points to next empty space
    if(this->length >= this->maxSize)
        cout<<"Regrettably array is full..."<<endl;
    else
    {
        this->list[this->length] = insertItem;
        this->length++;
    }
}

template<class elemType>
void unorderedArrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if(location < 0 || location >= this->length)
        cout<<"Location requested is out of range!! "<<endl;
    else
        this->list[location] = repItem;
}

template<class elemType>
void unorderedArrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    if(this->length == 0)
        cout << "Can only deleter fresh air from an empty container . . ." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if(loc != -1)
            this->removeAt(loc);
        else cout << "Item to be deleted is not in the list!!" << endl;
    }
}

template<class elemType>
unorderedArrayListType<elemType>::unorderedArrayListType(int size)
: arrayLisType<elemType>(size)
{
    if(size<=0)
    {
        cout << "Insufficient size to make an array" << endl;
        cout << "Creating an array of 100 . . . " << endl;
        this->maxSize = 100;
    }
    else
        this->maxSize = size;

    this->length = 0;

    this->list = new elemType[this->maxSize];
}

#endif // UNORDEREDARRAYLISTTYPE_H
