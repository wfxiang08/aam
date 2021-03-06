/**
This file is part of Active Appearance Models (AAM).

Copyright Christoph Heindl 2015
Copyright Sebastian Zambal 2015

AAM is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AAM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AAM.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AAM_DELAUNAY_H
#define AAM_DELAUNAY_H

#include <aam/types.h>

namespace aam {

    /** Find a suitable delaunay triangulation for the given set of points */
    RowVectorXi findDelaunayTriangulation(Eigen::Ref<const RowVectorX> points);

}

#endif