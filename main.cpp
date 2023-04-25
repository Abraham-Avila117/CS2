#include <iostream>
#include <string>
#include "arrayLisType.h"
#include "orderedArrayListType.h"

using namespace std;

void showMenu();
void listMenu();
template<class elemType>
elemType elemTypeFunction(orderedArrayListType<elemType>& typeList, int len);
template<class elemType>
elemType elemTypeMain(orderedArrayListType<elemType>& listType, int len);

int main()
{
    int len, type;

    cout << "Enter size of list: ";
    cin >> len;

    orderedArrayListType<int> intList(len);
    orderedArrayListType<double> doubleList(len);
    orderedArrayListType<char> charList(len);
    orderedArrayListType<string> stringList(len);
    orderedArrayListType<float> floatList(len);

    listMenu();
    cin >> type;
    switch(type)
    {
    case 1:
        elemTypeFunction(intList, len);
        elemTypeMain(intList, len);
        break;
    case 2:
        elemTypeFunction(doubleList, len);
        elemTypeMain(doubleList, len);
        break;
    case 3:
        elemTypeFunction(charList, len);
        elemTypeMain(charList, len);
        break;
    case 4:
        elemTypeFunction(stringList, len);
        elemTypeMain(stringList, len);
        break;
    case 5:
        elemTypeFunction(floatList, len);
        elemTypeMain(floatList, len);
        break;
    }

    return 0;
}

void showMenu()
{
    cout << endl<< "Congratulations! You made a list!" << endl;
    cout <<"How would you like to manipulate your list?" << endl;
    cout << "select (1) to insert a item somewhere in the list" << endl;
    cout << "select (2) to insert a item at the end of the list" << endl;
    cout << "select (3) to replace item somewhere in the list" << endl;
    cout << "select (4) to remove an item somewhere in the list" << endl;
    cout << "select (5) to check if list is full" << endl;
    cout << "select (6) to check if list is empty" << endl;
    cout << "select (7) to search for an item in the list" << endl;
    cout << "select (8) to clear list" << endl;
    cout << "select (9) to print your list" << endl;
    cout << "select (10) to exit" << endl;
    cout << "Choose: ";
}



void listMenu()
{
    cout << "Which type of list would you like to work with?" << endl;
    cout << "Select (1) for integers" << endl;
    cout << "Select (2) for double-precision (real numbers)" << endl;
    cout << "Select (3) for characters" << endl;
    cout << "Select (4) for string" << endl;
    cout << "Select (5) for float (also real numbers just less decimal places)" << endl;
    cout << "Choose: ";
}

template<class elemType>
elemType elemTypeFunction(orderedArrayListType<elemType>& typeList, int len)
{
    elemType item;
    cout << endl << "Filling a list of chosen type. . . " << endl;
    for(int i=0; i<len; i++)
    {
        cout << "Insert an item: ";
        cin >> item;
        typeList.insertAt(i, item);
    }
    cout << endl << "printing your ordered list" << endl;
    typeList.print();
    return item;
}

template<class elemType>
elemType elemTypeMain(orderedArrayListType<elemType>& listType, int len)
{
    elemType item;
    int choice, loc;

    showMenu();
    cin >> choice;
    cin.ignore();
    while(choice != 10)
    {
        switch(choice)
        {
        case 1:
            cout << "Enter location [0 - size]: ";
            cin >> loc;
            cout << "Enter item: ";
            cin >> item;
            listType.insertAt(loc, item);
            listType.print();
            cout << "Returning to main menu. . . " << endl;
            break;
        case 2:
            cout << "Enter item: ";
            cin >> item;
            listType.insertEnd(item);
            listType.print();
            cout << "Returning to main menu. . . " << endl;
            break;
        case 3:
            cout << "Enter location [0 - size]: ";
            cin >> loc;
            cout << "Enter item: ";
            cin >> item;
            listType.replaceAt(loc, item);
            listType.print();
            cout << "Returning to main menu. . . " << endl;
            break;
        case 4:
            cout << "Enter item: ";
            cin >> item;
            listType.remove(item);
            listType.print();
            cout << "Returning to main menu. . . " << endl;
            break;
        case 5:
            if(listType.isFull())
                cout << "List is full!" << endl;
            else
                cout << "List is not full. Add more stuff!" << endl;
            cout << "Returning to main menu. . . " << endl;
            break;
        case 6:
            if(listType.isEmpty())
                cout << "List is empty" << endl;
            else
                cout << "list is not empty. . .unfortunately" << endl;
            cout << "Returning to main menu. . . " << endl;
            break;
        case 7:
            cout << "Enter item to search: ";
            cin >> item;
            if(listType.seqSearch(item) != -1)
                cout << "There is an item of this kind in the list!" << endl;
            else
                cout << "There is not such item in the list" << endl;
            cout << "Returning to main menu. . . " << endl;
            break;
        case 8:
            listType.clearList();
            if(listType.isEmpty())
                cout << "List is now empty" << endl;
            else
            {
                cout << "for some reason the list is not empty????" << endl;
                cout << "terminating program!" << endl;
                exit(1);
            }
            cout << "Returning to main menu. . . " << endl;
            break;
        case 9:
            if(listType.isEmpty())
                cout << "Nothing here!" << endl;
            listType.print();
            cout << "Returning to main menu. . . " << endl;
            break;
        }
        showMenu();
        cin >> choice;
        cin.ignore();
    }
    return item;
}

