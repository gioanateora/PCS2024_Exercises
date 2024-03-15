#include <iostream>
#include <fstream>

unsigned int sumFirstNSquare(unsigned int N)
{
    return N * (N + 1) * (2 * N + 1) / 6;
}

int main()
{

    std::string fileName = "data.csv"; // file name
    std::ifstream ifstr(fileName); // create istream object and open file

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    unsigned int val = 0;
    unsigned int sumSquare = 0;
    unsigned int countVal = 0;

    std::string header;
    ifstr >> header; // ignore header of the file

    while(ifstr >> val)
    {
        sumSquare += val * val;
        countVal++;
    }

    ifstr.close();

    unsigned int ss = sumFirstNSquare(countVal);

    if(ss != sumSquare)
    {
        std::cerr << "Something is wrong" << std::endl;
        return 2;
    }


    std::cout << "The sum of square of the first N = " << countVal << " values is: " << sumSquare <<
        ". This sum is equal to: N * (N + 1) * (2 * N + 1) / 6, i.e. " << ss << std::endl;

    return 0;
}
