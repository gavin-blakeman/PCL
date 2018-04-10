//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								velocity.h
// SUBSYSTEM:						Velocity class
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
// OVERVIEW:            Implements a class for handling lengths.
//
// CLASSES INCLUDED:    CVelocity
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2015-05-23 GGB - Development of classes
//
//*********************************************************************************************************************************

#ifndef PCL_VELOCITY_H
#define PCL_VELOCITY_H

#include "PCLError.h"

#ifdef _MSC_VER
#pragma warning( disable : 4290 )  /* Disable the warning about C++ exception specifications. */
#endif

namespace PCL
{
  enum EVelocityUnit
  {
    VU_NONE,
    VU_MPS,
    VU_MPH,
    VU_KPH,
  };

  class CVelocity
  {
  private:
    double velocity_;

    void create(double, EVelocityUnit);

  protected:
  public:
    CVelocity(double, EVelocityUnit = VU_MPS);

    double operator ()(EVelocityUnit) const;

    static double convert(double, EVelocityUnit, EVelocityUnit);
  };

}

#endif // PCL__Velocity
