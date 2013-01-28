/**
 **autor   alexander k
 **date    03.11.2012.15.40
*/

//=============================================================================
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

Geometry::Contour createStarContour(const cv::Mat& image);

void turningDrowContour(cv::Mat* image);
