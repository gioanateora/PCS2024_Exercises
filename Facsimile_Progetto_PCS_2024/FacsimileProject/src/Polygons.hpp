#ifndef __POLYGONS_H
#define __POLYGONS_H

#include "Eigen/Eigen"
#include <iostream>

using namespace Eigen;
using namespace std;

namespace GeometryLibrary {

struct Triangle{

    Matrix3d Vertices;

    Triangle(const MatrixXd& Vertices): Vertices(Vertices) {}

    double computeArea()
    {
        double area = 0.0;
        for(unsigned int i = 0; i < 3; i++)
            area += Vertices(0, i) * Vertices(1, (i + 1) % 3) - Vertices(1, i) * Vertices(0, (i + 1) % 3);

        area *= 0.5;

        return area;
    }
};

struct Polygons{

    MatrixXd VerticesCoordinates;
    vector<vector<unsigned int>> listVertices;

    Polygons() = default;
    Polygons(const MatrixXd& VerticesCoordinates,
             const vector<vector<unsigned int>>& listVertices):
        VerticesCoordinates(VerticesCoordinates),
        listVertices(listVertices)
    {}

    vector<vector<vector<unsigned int>>> TriangulatePolygons();
    vector<double> computePolygonsArea();

    void GedimInterface(vector<vector<unsigned int>>& triangles,
                        VectorXi& materials);

};

void importPolygonsList(const string& filepath,
                        Polygons& polygons);

}

#endif
