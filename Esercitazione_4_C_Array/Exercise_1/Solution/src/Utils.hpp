#pragma once
#include "iostream"



using namespace std;

// ImportVectors reads the input vectors from file for dot product
// filePath: path name of the input file
// n: resulting size of the vectors
// v1: resulting vector1
// v2: resulting vector2
// return the result of the reading, true is success, false is error
bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int*& v1,
                   unsigned int*& v2);

// DotProduct performs the dot product between two vectors
// n: size of the vectors
// v1: the first vector
// v2: the second vector
// return the resulting dot product
unsigned int DotProduct(const size_t& n,
                        const unsigned int* const& v1,
                        const unsigned int* const& v2);

// ExportResult export the result obtained in file
// outputFilePath: path name of the output file
// v1: vector1
// v2: vector2
// dotProduct: the dot product
// return the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int* const& v1,
                  const unsigned int* const& v2,
                  const unsigned int& dotProduct);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const unsigned int* const& v);


