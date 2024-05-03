#include "Polygons.hpp"
#include "Eigen/Eigen"
#include "UCDUtilities.hpp"

int main()
{

    string filepath = "./ListPolygons/ListPolygons_25.txt";
    GeometryLibrary::Polygons polygons;

    GeometryLibrary::importPolygonsList(filepath, polygons);

    Gedim::UCDUtilities exporter;
    std::vector<std::vector<unsigned int>> triangles;
    Eigen::VectorXi materials;
    polygons.GedimInterface(triangles, materials);
    exporter.ExportPolygons("./Polygons_25.inp",
                            polygons.VerticesCoordinates,
                            triangles,
                            {},
                            {},
                            materials);

    return 0;
}
