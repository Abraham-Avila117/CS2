#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <iterator>
#include <fstream>
#include <stdexcept>

using namespace std;

int main()
{
    ifstream input_1, input_2;
    string* temp = new string;

    try{//check if file is good
        input_1.open("in1.txt");
        input_2.open("in2.txt");
    }
    catch(const system_error& ex){
        cout << "one file could not be opened" << endl;
        ofstream output;
        output.open("file_error.txt", ios::out);
        streambuf* stream_buffer_output = output.rdbuf();
        cerr.rdbuf(stream_buffer_output);
        cerr << "Exception thrown: File Error at " << ex.what() << endl;
        cerr << "Result: Termination of Program" << endl;
        exit(1);
    }

    list<string> strList;
    vector<string> strVector;
    vector<string>::iterator vIter;

    //get data to each list and vector containers
    while(!input_1.eof()){
        input_1 >> *temp;
        strList.push_front(*temp);
        strVector.push_back(*temp);
    }
    while(!input_2.eof()){
        input_2 >> *temp;
        strList.push_front(*temp);
        strVector.push_back(*temp);
    }

    //sort and remove duplicates in list
    strList.sort();
    strList.unique();

    cout << "Print the merged and non-repeating list: " << endl;
    for(auto e = strList.begin(); e != strList.end(); e++)
        cout << *e << endl;

    //sort and remove duplicates from vector using std::unique
    sort(strVector.begin(), strVector.end());
    vIter = unique(strVector.begin(), strVector.end());
    strVector.resize(distance(strVector.begin(), vIter));

    cout << endl << "Print the merged and non-repeating vector: " << endl;
    for(auto e = strVector.begin(); e != strVector.end(); e++)
        cout << *e << endl;

    delete temp;

    return 0;
}
