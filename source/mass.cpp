//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Mass.cpp
// SUBSYSTEM:						Mass Classes
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2011-2023 Gavin Blakeman.
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
// OVERVIEW:            Implements a class for handling Mass.
//
// CLASSES INCLUDED:    CMass
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#include "include/mass.h"

#include <GCL>

namespace PCL
{
  //*******************************************************************************************************************************
  //
  // CMass
  //
  //*******************************************************************************************************************************

  // Constructor for the class.
  //
  // 2011-07-29/GGB - Function Created.

  CMass::CMass(double mass, EMassUnit unit)
  {
    create(mass, unit);
  }

  // Returns the value in the appropriate units.
  //
  // 2015-06-21/GGB - Removed throw() specification.
  // 2011-07-29/GGB - Function created.

  double CMass::operator ()(PCL::EMassUnit unit) const
  {
    double retVal;

    switch (unit)
    {
    case MU_NONE:
      ERRORMESSAGE("MASS: Invalid Units");
      break;
    case MU_KG:
      retVal = _kg;
      break;
    case MU_LB:
      retVal = KGtoLB(_kg);
      break;
    default:
      ERRORMESSAGE("MASS: Invalid Units");
      break;
    };

    return retVal;
  }

  // Converts a mass in one unit to another unit
  //
  // 2011-07-29/GGB - Function created.

  double CMass::convert(double mass, EMassUnit unitS, EMassUnit unitF)
  {
    CMass m(mass, unitS);

    return (m(unitF));
  }

  // Converts the mass to Kg and stores it.
  //
  // 2015-06-21/GGB - Removed throw() specification.
  // 2011-07-29/GGB - Function created.

  void CMass::create(double mass, EMassUnit unit)
  {
    switch (unit)
    {
    case MU_NONE:
      ERRORMESSAGE("MASS: Invalid Units");
      break;
    case MU_KG:
      _kg = mass;
      break;
    case MU_LB:
      _kg = LBtoKG(mass);
      break;
    default:
      ERRORMESSAGE("MASS: Invalid Units");
      break;
    };
  }

}  // namespace PCL
