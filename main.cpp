#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    //start runtime
    auto start = high_resolution_clock::now();

    ofstream output;
    output.open("rawData.txt", ios::out);
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_output = output.rdbuf();
    cout.rdbuf(stream_buffer_output);

    bSearchTreeType<long int> tree;

    //seed is last four digits of student 700 number
    srand(8621);
    long int rand_num, format = 2;

    for(int i=0; i<100000; i++)
    {
        rand_num = rand();
        if(rand_num >= 100 && rand_num <= 100000000)
        {
            cout << rand_num << "\t\t";
            if(format > 5)
            {
                cout << endl;
                format = 1;
            }
            tree.insert(rand_num);
            format++;
        }
        else
            --i;

    }
    output.close();

    fstream file;
    file.open(argv[1], ios::out);
    streambuf* stream_buffer_file = file.rdbuf();
    cout.rdbuf(stream_buffer_file);

    cout << endl << "Printing tree using function: inorderTraversal()" << endl << endl;
    tree.inorderTraversal();

    cout <<endl<< endl<< "Search in tree for 22468825: " << (tree.search(22468825) ? "True" : "False") << endl;

    cout << "Height of tree: " << tree.treeHeight() << endl;

    cout << "Number of node: " << tree.treeNodeCount() <<  endl;

    cout << "Number of leaves: " << tree.treeLeavesCount() << endl;

    binaryTreeType<long int> tree2;
    cout << "Copying tree one to two: tree2 = tree " << endl;
    tree2 = tree;

    cout << "Deleting a node 22468825" << endl;
    tree.deleteNode(22468825);

    cout << "destroy the first tree" << endl;
    tree.destroyTree();

    //stop runtime
    auto stop = high_resolution_clock::now();
    auto duration_min = duration_cast<minutes>(stop - start);
    auto duration_sec = duration_cast<seconds>(stop - start);
    auto duration_mil = duration_cast<milliseconds>(stop - start);
    cout <<endl << endl<<"duration was: " << duration_min.count() << "m:" <<duration_sec.count() << "s:" << duration_mil.count() << "ms"<< endl;

    cout.rdbuf(stream_buffer_cout);
    cout << "End of program. file is outputted to bst.txt \nhave a good day" <<endl;

    //input.close();
    file.close();
    return 0;
}
