#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

// Passage by reference allows for multiple outputs and to save memory storage
void foo(const int j, // by value
         int d, // by value
         int &i, // by reference
         double &s) // by reference
{
    i+= d * j;
    s = 3.0 * j;
}



int main()
{

    // Const qualifier
    //    const int k; // error: k is unintialized const
    const int i = 12;
    //    i = 4; // error: attempt to write to const object

    int val = 24;
    int copyVal = val; // it's a copy of val
    int &refVal = val; // it's an alias for val
    //    int &refVal1; // error: a reference must be initialized

    refVal = 5; //
    cout << "val: " << val << endl;
    val = 7;
    cout << "refVal: " << refVal << endl;

    //    int &refVal2 = 10; // error: cannot initialize reference with literal
    double d = 3.14;
    //    int &refVal3 = d; // error: intializer must be integer

    // functionVoid result
    double s1 = 0.0;
    int ii = 2.0;
    foo(1, ii, val, s1);
    cout << "result of functionVoid: " << val << " and " << s1 << endl;
    // Pay attention: I cannot write "cout << functionVoid(val) << endl;" since functionVoid does not return any value


    // Function call:
    // Step 1: intialize function's parameters:
    // const int j = 1; // j cannot be edit by foo
    // int d = ii; // copy
    // int &i = val; // i is a reference for val
    // double &s = s1; // s1 and i can be thought as output since they can be edited by foo


    // Eigen library: documentation available at https://eigen.tuxfamily.org/dox/GettingStarted.html

    // Matrix:
    Matrix2d Ad = Matrix2d::Identity(); // fixed dimenional matrix 2x2 of double : intiailized as the identiyt matrix
    Matrix2i Ai = Matrix2i::Zero(); // fixed dimensions available: 2x2 3x3 4x4

    MatrixXd B = MatrixXd::Ones(2, 2); // variable dimensional matrix: this is initialized as an all-ones matrix 2x2

    cout << "B matrix:" << endl;
    cout << B << endl;

    B.resize(3, 3); // a dynamic matrix can be resized -> resize is not conservative!Try the conservativeResize() method.

    cout << "B matrix after resize:" << endl;
    cout << B << endl;

    MatrixXd C = MatrixXd::Constant(2, 2, 1.5); // input: numRows, numCols

    srand(2); // set seed for random matrix initialization
    MatrixXd D = MatrixXd::Random(2, 2);

    cout << "D matrix:" << endl;
    cout << D << endl;

    // comma initialization
    D << 2.0, 3.0,
        1.0, 4.0;

    cout << "D matrix:" << endl;
    cout << D << endl;

    // Column Vector:
    Vector2d v1 = Vector2d::Ones();
    VectorXd v2 = VectorXd::LinSpaced(10, 0.0, 90.0); // 10 equispaced numbers between 0 and 90

    cout << "v2 (column vector):" << endl;
    cout << v2 << endl;

    // Row vector
    RowVector2d v3 = RowVector2d::Ones();
    RowVectorXd v4(2);
    v4 << 1.0, 2.0;

    cout << "v4 (row vector):" << endl;
    cout << v4 << endl;


    // Some useful operation
    cout << "C * v1" << endl;
    cout << C * v1 << endl;

    cout << "C * v3' " << endl;
    cout << C * v3.transpose() << endl;

    // Block operation: https://eigen.tuxfamily.org/dox/group__TutorialBlockOperations.html

    // https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html

    return 0;
}
