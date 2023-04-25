#include <iostream>
#include <fstream>
#include "stockListType.h"
using namespace std;

int main()
{
    ifstream input;
    string filename;
    cout << "Enter your .txt file with your stocks: ";
    cin >> filename;

    input.open(filename);
    stockListType stockList;

    if(input.fail())
    {
        cerr << "Fail could not open! Terminating!" << endl;
        exit(1);
    }
    else
    {
        stockList.getListStockObject(input);
        cout << "File has been opened and recorded!" << endl << endl;
        input.close();
    }

    stockList.printStockList();
    cout << endl;
    stockList.sort();
    stockList.printStockList();
    cout << endl;
    stockList.sortListByGainLoss();
    stockList.printSortIndicesGainLoss();
    cout << endl;

    return 0;
}
