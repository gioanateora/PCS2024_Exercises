#include <iomanip> // include libraries
#include <iostream>
#include <limits>
#include <math.h>
#include <fstream>
#include <sstream>

int main()
{
    // This is a comment written on one line

    /** This is a comment written
     *  on more
     *  than one line.**/

    // Built-in types

    int a = -5;
    unsigned int b = 5;
    bool c = false; // or true
    double d = 3.5;
    double pi = M_PI; // M_PI stands for pi greco
    std::string s = "Hello world!"; // :: is the scope operator. It tells us in what namespace type "string" is defined.

    // Variable scope

    std::cout << "outer scope: a = " << a << std::endl;

    for(int a = 0; a < 3; a++)
    {
        std::cout << "inner scope: a = " << a << std::endl;
    }

    std::cout << "outer scope: a = " << a << std::endl;


    // Type Conversions

    int a1 = a + d;
    std::string s1 = s + " " + std::to_string(a1); // to sum two strings means concatenation

    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "s1 = " << s1 << std::endl;

    // Type - memory size

    std::cout << "size of bool: " << sizeof(bool) << std::endl;
    std::cout << "size of int: " << sizeof(int) << std::endl;
    std::cout << "size of unsigned int: " << sizeof(unsigned int) << std::endl;


    std::cout << std::fixed << std::setprecision(0) << "interval of values of int: [" << std::numeric_limits<int>::min() << ","
              << std::numeric_limits<int>::max() << "]" << std::endl;
    std::cout << "interval of values of unsigned int: [" << std::numeric_limits<unsigned int>::min() << ","
              << std::numeric_limits<unsigned int>::max() << "]" << std::endl;

    std::cout << "interval of values of int: [" << 0 << ","
              << pow(2, 32) -1 << "]" << std::endl;
    std::cout << "interval of values of unsigned int: [" << pow(2, 31) << ","
              << pow(2, 31) - 1 << "]" << std::endl;

    std::cout << std::defaultfloat << std::setprecision(6); // restore default

    std::cout << "Value of pi: " << pi << std::endl;

    // Read operations

//    int val = 0;
//    std::cin >> val;
//    std::cout << "val = " << val << std::endl;

//    // By default, cin ignores any leading whitespace (e.g. spaces, newline, tabs,...)
//    int val1 = 0, val2 = 0, val3 = 0;
//    std::cin >> val1 >> val2 >> val3;
//    std::cout << "val1 = " << val1 << ", val2 = " << val2
//              << ", val3 = " << val3 << std::endl;

//    char separator = ';';
//    std::cin >> val1 >> separator >> val2 >> separator >> val3;
//    std::cout << "val1 = " << val1 << ", val2 = " << val2
//              << ", val3 = " << val3 << std::endl;


    std::string str = "";
//    std::cin >> str;
//    std::cout << "cin -> str = " << str << std::endl;

    getline(std::cin, str); // Insert in terminal the string "0.0000034 1.0"
    std::cout << "getline - > str = " << str << std::endl;

    // Using String Stream Objects
    std::istringstream istrm(str); // create an istringstream object and bound it to string str
    std::string str1 = istrm.str(); // returns a copy of the string that istrm holds

    std::cout << "str1: " << str1 << std::endl;

    double d1, d2;
    istrm >> d1 >> d2;
    std::cout << "1. d1 + d2 = " << d1 + d2 << std::endl;

    // Some manipulator
    std::cout << "2. d1 + d2 = " << std::setprecision(16) << std::scientific << d1 + d2 << std::endl;
    std::cout << "3. d1 + d2 = " << d1 + d2 << std::endl;
    std::cout << "4. d1 + d2 = " << std::defaultfloat << d1 + d2 << std::endl;

    // Type Conversions using <<, >> operators

    // I can do this -> std::string s1 = s + " " + std::to_string(a1); by writing
    std::string s2;
    std::ostringstream ostrm(s2);
    ostrm << s << " " << a1;

    std::cout << "s2: " << ostrm.str() << std::endl;

    // Using File Stream Objects

    std::ifstream inFile("file.txt"); // create an ifstream object and open the given file

    std::ifstream inFile1; // create an ifstream object
    inFile1.open("file.txt"); // open the specified file

    if (inFile1.fail())
        std::cerr << "File does not exist" << std::endl;
    else
        std::cerr << "We create it in a previous execution" << std::endl;

    inFile1.close();

    std::ofstream outFile("file.txt"); // if file does not exist, it is created
    outFile << s << std::endl; // write s on file
    outFile.close();

    std::ofstream outFile1("file.txt", std::ofstream::trunc); // the file is truncated : trunc is the default
    outFile1 << s << std::endl;
    outFile1.close();

    // After closing the previous file, I can reuse the ofstream object
    outFile.open("file.txt", std::ofstream::app); // to preserve the file's content, open it in app mode
    outFile << s << std::endl;
    outFile.close();

    return 0;
}
