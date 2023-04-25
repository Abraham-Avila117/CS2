#ifndef ARRAYLISTYPE_H
#define ARRAYLISTYPE_H

#include<iostream>
using namespace std;

template<class elemType>
class arrayLisType
{
    public:
        const arrayLisType<elemType>& operator=(const arrayLisType<elemType>&);

        arrayLisType(const arrayLisType& otherList);
        bool isEmpty()const;
        bool isFull()const;
        int listSize()const;
        int maxListSize() const;
        void print()const;
        bool isItemAtEqual(int location, const elemType& item)const;
        void removeAt(int location);
        void retrieveAt(int location, elemType& retItem) const;
        void clearList();

        arrayLisType(int size = 100);
        virtual ~arrayLisType();

        virtual void insertAt(int location, const elemType& insertItem) = 0;
        virtual void insertEnd(const elemType& insertItem) = 0;
        virtual void replaceAt(int location, const elemType& repItem) = 0;
        virtual int seqSearch(const elemType& searchItem) const = 0;
        virtual void remove(const elemType& removeItem) = 0;

    protected:
        elemType *list;
        int length;
        int maxSize;
};

template<class elemType>
const arrayLisType<elemType>& arrayLisType<elemType>::operator=(const arrayLisType<elemType>& otherList)
{
    if(this != otherList)
    {
        delete [] list;
        this->maxSize = otherList.maxSize;
        this->length = otherList.length;
        list = new elemType[this->maxSize];
        for(int i = 0; i< this->length; i++)
            list[i]=otherList[i];
    }
    return *this;
}


template<class elemType>
bool arrayLisType<elemType>::isEmpty()const
{
    return (this->length == 0);
}

template<class elemType>
bool arrayLisType<elemType>::isFull()const
{
    return (this ->length==this->maxSize);
}

template<class elemType>
int arrayLisType<elemType>::listSize()const
{
    return this->length;
}

template<class elemType>
int arrayLisType<elemType>::maxListSize()const
{
    return this->maxSize;
}

template<class elemType>
void arrayLisType<elemType>::print()const
{
    for(int i = 0; i<this->length; i++)
        cout<<list[i]<<"\t";
    cout<<endl;
}

template<class elemType>
bool arrayLisType<elemType>::isItemAtEqual(int location, const elemType& item)const
{
    if(location < 0 || location >=this->length)
    {
        cout<<"The location requested is out of range...."<<endl;
        return false;
    }
    else
        return (list[location]==item);
}

template<class elemType>
void arrayLisType<elemType>::removeAt(int location)
{
    if(location < 0 || location >=this->length)
    {
        cout<<"The location requested is out of range...."<<endl;
        return;
    }
    else
    {
        for (int i = location; i<this->length; i++)
            list[i]=list[i+1];
        this->length--;
    }
}

template<class elemType>
void arrayLisType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if(location < 0 || location >=this->length)
        cout<<"The location requested is out of range...."<<endl;
    else
        retItem = list[location];
}


template<class elemType>
void arrayLisType<elemType>::clearList()
{
    this->length = 0;
}

template<class elemType>
arrayLisType<elemType>::arrayLisType(int size)
{
    if(size < 0)
    {
        cout<<"The array size requested is invalid....Creating an array of size 100"<<endl;
        this->maxSize = 100;
    }
    else
    {
        this -> maxSize = size;
    }
    this -> length = 0;
    list = new elemType[this->maxSize];
}

template<class elemType>
arrayLisType<elemType>::~arrayLisType()
{
    delete [] list;
}

//copy constructor
template<class elemType>
arrayLisType<elemType>::arrayLisType(const arrayLisType<elemType>& otherList)
{
    this ->maxSize = otherList.maxSize;
    this ->length = otherList.length;

    list = new elemType[this->maxSize];
    for(int i = 0; i<otherList.maxSize; i++)
        list[i] = otherList.list[i];
}

#endif // ARRAYLISTYPE_H
