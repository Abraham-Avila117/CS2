/*
Final Assignment task 1
Code produced by Abraham Avila
STL practice
professor: Sherine Antoun
*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <chrono>
#include <time.h>
#include <iterator>

using namespace std;
using namespace chrono;

int main()
{
    srand(time(0));//making true random numbers
    ostream_iterator<int> output(cout, "\t");
    list<int> List;

    for(int i=0; i<100; i++) //allocating numbers to the list
        List.push_front(rand());

    auto start = high_resolution_clock::now();
    List.sort();
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(finish - start);//timing the sort
    auto duration_mil = duration_cast<milliseconds>(finish - start);

    cout << "List after being sorted with List.sort(): " << endl;
    copy(List.begin(), List.end(), output); //output the list
    cout << endl << "Run Time was: " << duration.count() << " ns" << endl;

    vector<int> Vector;
    list<int> newList(100);
    for(int i=0; i<100;i++)
        Vector.push_back(rand());

    auto start1 = high_resolution_clock::now();
    sort(Vector.begin(), Vector.end());
    auto finish1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(finish1 - start1);
    auto duration_mil_1 = duration_cast<milliseconds>(finish1 - start1);
    copy(Vector.begin(), Vector.end(), newList.begin());

    cout << endl << "newList after sorting the vector then copying to newList: " << endl;
    copy(newList.begin(), newList.end(), output);

    cout << endl << "Run Time for list sort was: " << duration_mil.count() << " ms: " << duration.count() << " ns" << endl;
    cout << endl << "Run time for vector sort was: " << duration_mil_1.count() << " ms: " << duration1.count() << " ns" << endl;

    return 0;
}
