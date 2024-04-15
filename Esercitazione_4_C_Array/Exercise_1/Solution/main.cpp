#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;


int main()
{
    string inputFileName = "./vectors.txt";
    size_t n = 0;
    unsigned int* v1 = nullptr;
    unsigned int* v2 = nullptr;

    if (!ImportVectors(inputFileName, n, v1, v2))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful: n= "<< n<< " v1= "<< ArrayToString(n, v1)<< " v2= "<< ArrayToString(n, v2)<< endl;

    unsigned int dotProduct = DotProduct(n, v1, v2);
    cout<< "dot product: "<< dotProduct << endl;

    string outputFileName = "./dotProduct.txt";
    if (!ExportResult(outputFileName, n, v1, v2, dotProduct))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] v1;
    delete[] v2;

    return 0;
}


