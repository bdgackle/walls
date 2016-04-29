/**
 *  @file unit_types.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains types used for various measurements
 */

#ifndef UNIT_TYPES_HPP
#define UNIT_TYPES_HPP

namespace walls {

/** Difference between two points in time, measured in seconds */
typedef int TimeDelta;

/** Distance between two points on the map, measured in one meter voxels */
typedef int MapDelta;

/** Map coordinate type; intended to be roughly one meter */
typedef int MapCoordinate;

/** Type used to represent display coordinates */
typedef int DisplayCoordinate;

} // namespace walls

#endif // UNIT_TYPES_HPP
