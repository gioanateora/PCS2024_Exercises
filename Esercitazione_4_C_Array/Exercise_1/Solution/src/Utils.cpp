#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int*& v1,
                   unsigned int*& v2)
{
    // Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // Get number elements
    string line;
    while (!file.eof())
    {
        getline(file, line);

        // Skip Comment Line
        if(line[0] != '#')
            break;
    }

    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    // Get first vector
    while (!file.eof())
    {
        getline(file, line);

        // Skip Comment Line
        if(line[0] != '#')
            break;
    }
    istringstream convertV1;
    convertV1.str(line);

    v1 = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++)
        convertV1 >> v1[i];

    // Get second vector
    while (!file.eof())
    {
        getline(file, line);

        // Skip Comment Line
        if(line[0] != '#')
            break;
    }
    istringstream convertV2;
    convertV2.str(line);

    v2 = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++)
        convertV2 >> v2[i];

    // Close File
    file.close();

    return true;
}


unsigned int DotProduct(const size_t& n,
                        const unsigned int* const& v1,
                        const unsigned int* const& v2)
{
    unsigned int dotProduct = 0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];

    return dotProduct;
}


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int* const& v1,
                  const unsigned int* const& v2,
                  const unsigned int& dotProduct)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file<< "# Size of the two vectors"<< endl;
    file<< n<< endl;

    file<< "# vector 1"<< endl;
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< v1[i];
    file<< endl;

    file<< "# vector 2 "<< endl;
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< v2[i];
    file<< endl;

    file<< "# dot product"<< endl;
    file<< dotProduct<< endl;

    // Close File
    file.close();

    return true;
}

string ArrayToString(const size_t& n,
                     const unsigned int* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
