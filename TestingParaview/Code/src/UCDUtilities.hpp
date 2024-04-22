// ------------------------------------------------------------------------------
//
// Copyright (C) 2024 by the GeDiM authors.
// This file is part of GeDiM.
//
// GeDiM is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// GeDiM is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with GeDiM.  If not, see <http://www.gnu.org/licenses/>.
// ------------------------------------------------------------------------------

// Author: Fabio Vicini <fabio.vicini@polito.it>

#ifndef __UCDUtilities_H
#define __UCDUtilities_H

#include "Eigen/Eigen"
#include <list>
#include <string>

namespace Gedim
{
  template <typename T>
  struct UCDProperty final
  {
      std::string Label;
      std::string UnitLabel;

      unsigned int Size;
      unsigned int NumComponents;
      const T* Data;
  };


  class UCDCell final
  {
    public:
      enum struct Types
      {
        Unknown = -1,
        Point = 0,
        Line = 1,
        Triangle = 2,
        Quadrilateral = 3,
        Hexahedron = 4,
        Prism = 5,
        Tetrahedron = 6,
        Pyramid = 7
      };

      const Types Type;
      const std::vector<unsigned int> PointIds;
      const unsigned int MaterialId;

      UCDCell(const Types type,
              const std::vector<unsigned int> pointIds,
              const unsigned int materialId) :
        Type(type),
        PointIds(pointIds),
        MaterialId(materialId)
      { }

      const std::string CellLabel(const UCDCell::Types type) const;
  };

  class UCDUtilities final
  {
    public:
      enum ExportFormats
      {
        Ascii = 0
      };

    private:
      std::vector<UCDCell> CreatePointCells(const Eigen::MatrixXd& points,
                                            const Eigen::VectorXi& materials) const;
      std::vector<UCDCell> CreateLineCells(const Eigen::MatrixXi& lines,
                                           const Eigen::VectorXi& materials) const;
      std::vector<UCDCell> CreatePolygonCells(const std::vector<std::vector<unsigned int>>& polygons_vertices,
                                              const Eigen::VectorXi& materials) const;
      std::vector<UCDCell> CreatePolyhedraCells(const std::vector<std::vector<unsigned int>>& polyhedra_vertices,
                                                const Eigen::VectorXi& materials) const;

      void ExportUCDAscii(const Eigen::MatrixXd& points,
                          const std::vector<UCDProperty<double>>& point_properties,
                          const std::vector<UCDCell>& cells,
                          const std::vector<UCDProperty<double>>& cell_properties,
                          const std::string& filePath) const;

    public:
      UCDUtilities() { }
      virtual ~UCDUtilities() { }

      void ExportPoints(const std::string& filePath,
                        const Eigen::MatrixXd& points,
                        const std::vector<UCDProperty<double>>& points_properties = {},
                        const Eigen::VectorXi& materials = {}) const;

      void ExportSegments(const std::string& filePath,
                          const Eigen::MatrixXd& points,
                          const Eigen::MatrixXi& segments,
                          const std::vector<UCDProperty<double>>& points_properties = {},
                          const std::vector<UCDProperty<double>>& segmnents_properties = {},
                          const Eigen::VectorXi& materials = {}) const;

      void ExportPolygons(const std::string& filePath,
                          const Eigen::MatrixXd& points,
                          const std::vector<std::vector<unsigned int>>& polygons_vertices,
                          const std::vector<UCDProperty<double>>& points_properties = {},
                          const std::vector<UCDProperty<double>>& polygons_properties = {},
                          const Eigen::VectorXi& materials = {}) const;

      void ExportPolyhedra(const std::string& filePath,
                           const Eigen::MatrixXd& points,
                           const std::vector<std::vector<unsigned int>>& polyhedra_vertices,
                           const std::vector<UCDProperty<double>>& points_properties = {},
                           const std::vector<UCDProperty<double>>& polyhedra_properties = {},
                           const Eigen::VectorXi& materials = {}) const;
  };
}

#endif // __UCDUtilities_H
