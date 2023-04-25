/*
Header file "stockType.h" created by Abraham Avila
Class: CSCI-112
Assignment 2
Instructor: Professor Antoun
*/

#ifndef STOCKTYPE_H
#define STOCKTYPE_H
#include <iostream>
#include <iomanip>
using namespace std;

class stockType
{
    public:
        stockType();
        stockType(string symbol, double open, double close,
                  double high, double low, double prevClose, int noOfShares);
        //mutators
        void setStockSymbol(string symbol);
        void setOpeningPrice(double open);
        void setClosingPrice(double close);
        void setHighPrice(double high);
        void setLowPrice(double low);
        void setPreviousClose(double prevClose);
        void setNumOfShares(int noOfShares);
        //accessors
        string getSymbol() const;
        double getOpeningPrice() const;
        double getClosingPrice() const;
        double getHighPrice() const;
        double getLowPrice() const;
        double getPreviousClose() const;
        double getPercentGL() const;
        double calculatePercentGL() const;  // calculate gain/loss percentage
        double closingAssetTotal() const;
        int getNumShares() const;
        //print
        void printStock() const;
        //overloading functions
        bool operator==(const stockType& stock);
        bool operator!=(const stockType& stock);
        bool operator<(const stockType& stock);
        bool operator>(const stockType& stock);
        friend ostream& operator<<(ostream&, const stockType&);
        friend istream& operator>>(istream&, stockType&);
        stockType& operator=(const stockType&);
//        ~stockType(); //deconstructor

    protected:
        string stockSymbol;
        int numShares;
        double openingPrice;
        double closingPrice;
        double highPrice;
        double lowPrice;
        double previousClose;
};
//default constructor
stockType::stockType()
{
    stockSymbol = " ";
    numShares = 0;
    openingPrice = 0.0;
    closingPrice = 0.0;
    highPrice = 0.0;
    lowPrice = 0.0;
    previousClose = 0.0;
}

//parameterized constructor
stockType::stockType(string symbol, double open,
                  double close, double high, double low, double prevClose, int noOfShares)
{
    stockSymbol = symbol;
    openingPrice = open;
    closingPrice = close;
    highPrice = high;
    lowPrice = low;
    previousClose = prevClose;
    numShares = noOfShares;
}
//mutators
void stockType::setStockSymbol(string symbol)
{
    stockSymbol = symbol;
}

void stockType::setOpeningPrice(double open)
{
    openingPrice = open;
}

void stockType::setClosingPrice(double close)
{
    closingPrice = close;
}

void stockType::setHighPrice(double high)
{
    highPrice = high;
}

void stockType::setLowPrice(double low)
{
    lowPrice = low;
}

void stockType::setPreviousClose(double prevClose)
{
    previousClose = prevClose;
}

void stockType::setNumOfShares(int noOfShares)
{
    numShares = noOfShares;
}

//accessors
string stockType::getSymbol() const
{
    return stockSymbol;
}

int stockType::getNumShares() const
{
    return numShares;
}

double stockType::getOpeningPrice() const
{
    return openingPrice;
}

double stockType::getClosingPrice() const
{
    return closingPrice;
}

double stockType::getHighPrice() const
{
    return highPrice;
}

double stockType::getLowPrice() const
{
    return lowPrice;
}

double stockType::getPreviousClose() const
{
    return previousClose;
}

//print
void stockType::printStock() const
{
    cout << fixed << showpoint << setprecision(2);
    cout << this->stockSymbol << "\t" <<this->openingPrice << "\t" << this->closingPrice
    << "\t" << this->highPrice << "\t" << this->lowPrice << "\t" << this->previousClose << "\t" << this->calculatePercentGL() << "%\t"  << this->numShares << endl;
}

double stockType::calculatePercentGL() const  // (gain/loss) * 100
{
    return ((closingPrice-previousClose)/previousClose) * 100;
}

double stockType::closingAssetTotal() const
{
    return closingPrice*numShares;
}

//overloading functions
bool stockType::operator==(const stockType& otherStock)
{
    return (stockSymbol==otherStock.stockSymbol);
}

bool stockType::operator!=(const stockType& otherStock)
{
    return (this->stockSymbol!=otherStock.stockSymbol);
}

bool stockType::operator<(const stockType& otherStock)
{
    return (this->stockSymbol<otherStock.stockSymbol);
}

bool stockType::operator>(const stockType& otherStock)
{
    return (this->stockSymbol>otherStock.stockSymbol);
}

ostream& operator<<(ostream& out, const stockType& stock)
{
    out << fixed << showpoint << setprecision(2);
    out << stock.stockSymbol << "\t" << stock.openingPrice << "\t" << stock.closingPrice << "\t" << stock.highPrice
    << "\t" << stock.lowPrice << "\t" << stock.previousClose << "\t" << stock.calculatePercentGL() << "%\t" << stock.numShares <<endl;
    return out;
}

istream& operator>>(istream& ins, stockType& stock)
{
    ins >> stock.stockSymbol;
    ins >> stock.openingPrice;
    ins >> stock.closingPrice;
    ins >> stock.highPrice;
    ins >> stock.lowPrice;
    ins >> stock.previousClose;
    ins >> stock.numShares;
    return ins;
}

stockType& stockType::operator=(const stockType& stockObject)
{
    this->stockSymbol = stockObject.stockSymbol;
    this->openingPrice = stockObject.openingPrice;
    this->closingPrice = stockObject.closingPrice;
    this->highPrice = stockObject.highPrice;
    this->lowPrice = stockObject.lowPrice;
    this->previousClose = stockObject.previousClose;
    this->numShares = stockObject.numShares;

    return *this;
}

//deconstructor
//stockType::~stockType()
//{
//
//}

#endif // STOCKTYPE_H
