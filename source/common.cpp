//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								common
// SUBSYSTEM:						Common definitions
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2015-2018 Gavin Blakeman.
//                      This file is part of the Physics Class Library (PCL)
//
//                      PCL is free software: you can redistribute it and/or modify it under the terms of the GNU General
//                      Public License as published by the Free Software Foundation, either version 2 of the License, or
//                      (at your option) any later version.
//
//                      PCL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
//                      implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//                      for more details.
//
//                      You should have received a copy of the GNU General Public License along with PCL.  If not,
//                      see <http://www.gnu.org/licenses/>.
//
//
// OVERVIEW:						Common definitions that can be used by multiple files
//
//
// CLASSES INCLUDED:		None
//
// CLASS HIERARCHY:     None.
//
// FUNCTIONS INCLUDED:  std::string getVersionString()
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2015-06-29 GGB - File created.
//
//*********************************************************************************************************************************

#include "../include/common.h"

  // Standard libraries

#include <iomanip>
#include <sstream>
#include <string>

  // Boost Library

#include <boost/algorithm/string.hpp>

namespace PCL
{

  unsigned int const PCL_MAJORVERSION = 2015;           ///< The Major version number (yyyy)
  unsigned int const PCL_MINORVERSION = 9;              ///< The Minor version number (mm)
  unsigned int const PCL_BUILDNUMBER  = 0x0000;         ///< The build numnber - incremented on each build.

  /// @brief Returns the library version and build number.
  /// @returns A string with the application name, version, build.
  /// @throws Nothing.
  /// @version 2015-06-29/GGB - Function created.

  std::string getVersionString()
  {
    std::stringstream s;

    s << PCL_MAJORVERSION << "." << std::setfill('0') << std::setw(2) << PCL_MINORVERSION << std::setw(4) << std::hex << PCL_BUILDNUMBER << std::endl;

    std::string returnValue = s.str();
    boost::algorithm::to_upper(returnValue);

    return returnValue;
  }
}
