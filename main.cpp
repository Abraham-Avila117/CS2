//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//  Main program infix to postfix
 
#include <iostream>
//#include <fstream>
#include <string>
#include "myStack.h"
#include "infixToPostfix.h"
  
using namespace std; 

int main(int argc, const char * argv[])
{
    infixToPostfix  InfixExp;
    string infix;
/*
    ifstream infile;

    infile.open("infixData.txt");

    if (!infile)
    {
        cout << "Cannot open input file. Program terminates!!!" << endl;
        return 1;
    }

    getline(infile, infix);

    while (infile)
    {
        InfixExp.getInfix(infix);
        InfixExp.showInfix();
        InfixExp.showPostfix();
        cout << endl;

        getline(infile, infix);
    }

    infile.close();
*/
    cout << "Enter an Infix expression followed by a semicolon:\n";
    getline(cin, infix);
    InfixExp.getInfix(infix);
    InfixExp.showInfix();
    InfixExp.showPostfix();
    cout << endl;
    return 0;
}
