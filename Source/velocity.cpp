//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								velocity
// SUBSYSTEM:						Velocity Class
// LANGUAGE:						C++
// TARGET OS:						All
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2015 Gavin Blakeman.
//                      This file is part of the Physics Class Library (PCL)
//
//                      PCL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
//                      License as published by the Free Software Foundation, either version 2 of the License, or (at your option)
//                      any later version.
//
//                      PCL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//                      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//                      more details.
//
//                      You should have received a copy of the GNU General Public License along with PCL.  If not, see
//                      <http://www.gnu.org/licenses/>.
//
// OVERVIEW:            Implements a class for handling lengths.B
//
// CLASSES INCLUDED:    CVelocity
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2015-05-23 GGB - Development of classes
//
//*********************************************************************************************************************************

#include "../Include/velocity.h"

#include "../Include/constants.h"
#include "../Include/distance.h"

namespace PCL
{
  //*******************************************************************************************************************************
  //
  // CVelocity
  //
  //*******************************************************************************************************************************

  /// @brief Constructor for the class.
  /// @param[in] velocity The velocity to be stored in the class.
  /// @param[in] unit The unit that the velocity is referred to.
  /// @throws none.
  //
  // 2015-05-23/GGB - Function created

  CVelocity::CVelocity(double velocity, EVelocityUnit unit)
  {
    create(velocity, unit);
  }

  /// @brief Returns the value in the specified units.
  /// @param[in] unit The desired output unit.
  /// @returns The velocity value converted to the appropriate units.
  /// @throws PCLError(0x0200) - Undefined velocity unit.
  //
  // 2015-05-23/GGB - Function created

  double CVelocity::operator ()(EVelocityUnit unit) const
  {
    double retVal;

    switch (unit)
    {
      case VU_NONE:
      {
        PCL_ERROR(0x0200);
        break;
      };
      case VU_MPS:
      {
        retVal = velocity_;
        break;
      };
      case VU_MPH:
      {
        retVal = CDistance::convert(velocity_, DU_METER, DU_MILE);
        retVal *= SecondsPerHour;
        break;
      };
      case VU_KPH:
      {
        retVal = velocity_ / 1000;
        retVal *= SecondsPerHour;
        break;
      };
      default:
      {
        PCL_ERROR(0x0200);
        break;
      };
    };

    return retVal;
  }

  // Converts one unit to another.
  //
  // 2015-05-23/GGB - Function created

  double CVelocity::convert(double velocity, PCL::EVelocityUnit unitS, PCL::EVelocityUnit unitF)
  {
    CVelocity l(velocity, unitS);

    return l(unitF);
  }

  /// @brief Creates the object and converts the length to meters/second.
  /// @param[in] velocity The velocity that is to be stored.
  /// @param[in] unit The unit that the velocity is referred to.
  /// @throws 0x0200 - Unknown unit.
  //
  // 2015-05-23/GGB - Function created.

  void CVelocity::create(double velocity, EVelocityUnit unit)
  {
    switch (unit)
    {
      case VU_NONE:
      {
        PCL_ERROR(0x0200);
        break;
      };
      case VU_MPS:
      {
        velocity_ = velocity;
        break;
      };
      case VU_MPH:
      {
        velocity_ = CDistance::convert(velocity, DU_MILE, DU_METER);
        velocity_ /= SecondsPerHour;
        break;
      };
      case VU_KPH:
      {
        velocity_ = velocity * 1000;
        velocity_ /= SecondsPerHour;
        break;
      };
      default:
      {
        PCL_ERROR(0x0200);
        break;
      };
    };
  }

}  // namespace PCL
