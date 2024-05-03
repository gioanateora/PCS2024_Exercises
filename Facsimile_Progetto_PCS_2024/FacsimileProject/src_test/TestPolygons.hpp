#ifndef __TESTPOLYGONS_H
#define __TESTPOLYGONS_H

#include <gtest/gtest.h>
#include "Polygons.hpp"
#include "Eigen/Eigen"
#include <iostream>
#include "UCDUtilities.hpp"

using namespace Eigen;
using namespace std;

namespace GeometryLibrary {
//********************************
TEST(TRIANGLETEST, TestComputeArea){

    Matrix3d vertices = Matrix3d::Zero();

    vertices << 0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        0.0, 0.0, 0.0;

    Triangle t(vertices);

    double area = t.computeArea();
    EXPECT_EQ(area, 0.5);
}
//********************************
TEST(POLYGONTEST, TestPlotParaviewTriangles){

    MatrixXd points = MatrixXd::Zero(3, 4);

    points << 0.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 1.0,
        0.0, 0.0, 0.0, 0.0;

    const std::vector<std::vector<unsigned int>> triangles =
        {
            { 0, 1, 3 },
            { 1, 2, 3 }
        };

    Eigen::VectorXi materials(2);
    materials << 0, 1;

    Gedim::UCDUtilities exporter;

    const std::vector<Gedim::UCDProperty<double> > points_properties = {};
    const std::vector<Gedim::UCDProperty<double> > polygons_properties = {};

    exporter.ExportPolygons("./Geometry2Ds.inp",
                            points,
                            triangles,
                            points_properties,
                            polygons_properties,
                            materials);


}
//********************************
TEST(POLYGONTEST, TestPlotParaviewPolygons){

    MatrixXd points = MatrixXd::Zero(3, 4);

    points << 0.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 1.0,
        0.0, 0.0, 0.0, 0.0;

    vector<vector<unsigned int>> pol_vertices = { {0, 1, 2, 3}};

    Polygons polygons(points,
                     pol_vertices);
    std::vector<std::vector<unsigned int>> triangles;
    Eigen::VectorXi materials;

    polygons.GedimInterface(triangles, materials);

    Gedim::UCDUtilities exporter;

    exporter.ExportPolygons("./Geometry2Ds.inp",
                            points,
                            triangles,
                            {},
                            {},
                            materials);
}
//********************************
}



#endif
