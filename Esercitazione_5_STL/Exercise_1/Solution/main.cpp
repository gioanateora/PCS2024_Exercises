#include <iostream>
#include "TriangularMesh.hpp"
#include "Utils.hpp"

using namespace std;
using namespace Eigen;
using namespace TriangularLibrary;

int main()
{
    TriangularMesh mesh;

    string filepath = "TriangularMesh";
    if(!ImportMesh(filepath,
                    mesh))
    {
        return 1;
    }

    return 0;
}

