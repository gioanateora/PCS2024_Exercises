#ifndef __UCD_test_HPP__
#define __UCD_test_HPP__

#include "UCDUtilities.hpp"
#include <gtest/gtest.h>

// ***************************************************************************
TEST(TestUCDUtilities, UCDUtilities_Test0Ds)
{
    std::string exportFolder = "./";

    Gedim::UCDUtilities exporter;
    const Eigen::MatrixXd points = (Eigen::MatrixXd(3, 4)<< 0.0, 1.0, 1.0, 0.0,
                                    0.0, 0.0, 1.0, 1.0,
                                    2.0, 2.0, 2.0, 2.0).finished();

    exporter.ExportPoints(exportFolder + "/Geometry0Ds.inp",
                          points);

}
// ***************************************************************************
TEST(TestUCDUtilities, UCDUtilities_Test1Ds)
{
    std::string exportFolder = "./";

    Gedim::UCDUtilities exporter;
    const Eigen::MatrixXd points = (Eigen::MatrixXd(3, 4)<< 0.0, 1.0, 1.0, 0.0,
                                    0.0, 0.0, 1.0, 1.0,
                                    2.0, 2.0, 2.0, 2.0).finished();
    const Eigen::MatrixXi edges = (Eigen::MatrixXi(2, 5)<< 0, 1, 2, 3, 0,
                                   1, 2, 3, 0, 2).finished();

    exporter.ExportSegments(exportFolder + "/Geometry1Ds.inp",
                            points,
                            edges);
}
// ***************************************************************************
TEST(TestUCDUtilities, UCDUtilities_Test2Ds)
{
    std::string exportFolder = "./";

    Gedim::UCDUtilities exporter;
    const Eigen::MatrixXd points = (Eigen::MatrixXd(3, 8)<< 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
                                    0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
                                    2.0, 2.0, 2.0, 2.0, 4.0, 4.0, 4.0, 4.0).finished();
    const std::vector<std::vector<unsigned int>> polygons =
        {
            { 0, 1, 2 },
            { 0, 2, 3 },
            { 4, 5, 6, 7 }
        };

    exporter.ExportPolygons(exportFolder + "/Geometry2Ds.inp",
                            points,
                            polygons);
}
// ***************************************************************************

#endif // __UCD_test_HPP__
