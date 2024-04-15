#include <iostream>
#include <cmath>

using namespace std;

int foo(int& a)
{
    a++;
    return a;
}

int fooPtr(int* &ptrA)
{
    (*ptrA)++; // change the value of the object

    int c = 3;
    ptrA = &c;

    return (*ptrA);
}

int main()
{
    /// Differences between float and double

    double d = 1.24834935395739;
    float f = 1.24834935395739;
    cout.precision(16);
    cout << scientific << "d: " << d << endl;
    cout << scientific << "f: " << f << endl;

    /// Pointer

    // Uninitialized pointers are a common source of run-time errors.
    // If there is no object to bind a pointer, then initialize it with nullptr.
    // That way the program can detect that the pointer does not point to an object.
    int *ptrNull = nullptr;

    int a = 2;
    int* ptrA = &a; // ptrA holds the address of a

    cout << "ptrA: " << ptrA << endl;

    (*ptrA) = 2; // change the value of a;

    cout << "a: " << a << endl;

    const int* ptrConstA = &a;
    const int* &ptrRef = ptrConstA; // reference to pointer to int
    const int* const ptrConst = ptrA; // const pointer to const int


    int b = 0;
    int *ptr = &b; // ptr holds the address of b
    cout << "ptr: " << ptr << endl;
    cout << "b: " << (*ptr) << endl; // retrieve the value of b through ptr

    cout << "foo(b): " << foo(b) << endl; // b is passed by reference
    cout << "b: " << b << endl; // foo can change the value of b

    cout << "fooPtr(ptr): " << fooPtr(ptr) << endl; // ptr is passed by reference
    cout << "ptr: " << ptr << endl; // fooPtr can change the value of ptr
    cout << "b : "<< b << endl; // fooPtr can change the value of b through ptr


    /// Array

    const int i = 3;
    const size_t n = i;
    int arr[n] = {1, 2, 3}; // C-Style array with fix size equals to 3, intialized with 1,2,3

    cout << "second element of arr: " << arr[1] << endl;

    int *ptrArr = &arr[0]; // ptrArr point to the first element of arr

    cout << "ptrArr: " << ptrArr << endl;
    cout << "arr: " << arr << endl; // In most case, you can use the name of an array as the pointer to its first element
    cout << "ptrArr[2]: " << ptrArr[2] << endl;
    cout << "arr[2]: " << arr[2] << endl;
    cout << "*(ptrArr + 1): " << *(ptrArr + 1) << endl; // Equivalent to say arr[1]
    cout << "*(arr + 1): " << *(arr + 1) << endl; // Equivalent to say arr[1]
    cout << "*(ptrArr++): " << *(ptrArr++) << endl;
    //        cout << *(arr++) << endl; // error


    /// Dynamic allocation

    int *ptrNewInt = new int(2);

    size_t m = 3;
    int *ptrNewArr = new int[m]{1,2,3};

    cout << "ptrNewArr[0]: " << ptrNewArr[0] << endl;
    cout << "ptrNewArr[1]: " << ptrNewArr[1] << endl;
    cout << "ptrNewArr[2]: " << ptrNewArr[2] << endl;

    delete ptrNewInt; // delete an object
    delete [] ptrNewArr; // delete an array

    return 0;
}

