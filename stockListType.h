/*
header "stockListType.h" created by Abraham Avila
class: CSCI-112
Assignment 2
Instructor: Professor Antoun
*/

#ifndef STOCKLISTTYPE_H
#define STOCKLISTTYPE_H
#include "listType.h"
#include "stockType.h"
#include <fstream>
#include <iomanip>

class stockListType : public listType<stockType>
{
    public:
        //constructors
        stockListType();
        stockListType(int len);

        //get data functions
        void getListStockObject(ifstream&);

        //sortPercentGainLoss function
        void sortListByGainLoss();

        //print function
        void printStockList();
        void printSortIndicesGainLoss();
        void header();
        void belowHeader();
        void bottom();

        //calculate total closing assets
        int calculateTotalClosingAssets();

        //deconstructor
        ~stockListType();

    protected:
        int *sortIndicesGainLoss;
};

void stockListType::getListStockObject(ifstream& ins)
{
    length = 7;
    maxSize = 7;
    getList(ins);
}

void stockListType::sortListByGainLoss()
{
    int temp;

    for(int i=0; i<length; i++)
        sortIndicesGainLoss[i] = i;

    for(int i=0; i<length; i++)
    {
        for(int j=i; j<length; j++)
        {
            if(elements[sortIndicesGainLoss[i]].calculatePercentGL() < elements[sortIndicesGainLoss[j]].calculatePercentGL())
            {
                temp = sortIndicesGainLoss[i];
                sortIndicesGainLoss[i] = sortIndicesGainLoss[j];
                sortIndicesGainLoss[j] = temp;
            }
        }
    }
}

void stockListType::printStockList()
{
    header();
    belowHeader();
    print();
    bottom();
}

void stockListType::printSortIndicesGainLoss()
{
    header();
    belowHeader();
//    cout << "check1" << endl;
    for(int i=0; i<length; i++)
    {
//        cout << "check2" << endl;
//        cout << sortIndicesGainLoss[i] << endl;
//        cout << "check3" << endl;
//        cout << elements[sortIndicesGainLoss[i]] << endl;
        elements[sortIndicesGainLoss[i]].printStock();
        cout << endl;
    }
    bottom();
}

void stockListType::header()
{
    for(int i=0; i<27; i++)
    {
        cout <<"*";
        if(i==13)
            cout << " Aussie Foreign Investor's Heaven ";
    }
    cout << endl;

    for(int i=0; i<43; i++)
    {
        cout <<"*";
        if(i==21)
            cout << " Financial Report ";
    }
    cout << endl;
}

void stockListType::belowHeader()
{
    cout << "Stock\t\t\tToday\t" << setw(22) << "Previous Percent" << endl;

    cout << "Symbol\tOpen\tClose\tHigh\tLow\tClose\tGain\tVolume" << endl;

    for(int i=0; i<8; i++)
        cout << "-----\t";
    cout << endl;
}

void stockListType::bottom()
{
    cout << "Closing Assets: AU$" << calculateTotalClosingAssets() << endl;

    for(int i=0; i<30; i++)
        cout << "#-";
    cout << "#";
    cout << endl;
}

int stockListType::calculateTotalClosingAssets()
{
    int total;
    for(int i=0; i<length; i++)
        total += elements[i].closingAssetTotal();
    return total;

}

stockListType::stockListType(int len) : listType(len)
{
    sortIndicesGainLoss = new int[len];
}


stockListType::stockListType() : listType()
{
    sortIndicesGainLoss = new int[50];
}

stockListType::~stockListType()
{
    delete [] sortIndicesGainLoss;
}

#endif // STOCKLISTTYPE_H
