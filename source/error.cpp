//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								PCLError
// SUBSYSTEM:						Physics Class Library Exception subsystem
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	GCL
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2011-2018 Gavin Blakeman.
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
// OVERVIEW:            This file implements exceptions that are used for error reporting by the PCL library.
//
// CLASSES INCLUDED:    CPCLError
//
// NOTES:               1) The error strings are hard coded into the class by the pre-initialised array.
//                      2)
//
// HISTORY:             2018-09-20 GGB - Updated to new style error handling.
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRAS
//
//*********************************************************************************************************************************

#include "../include/error.h"

// Standard C++ library headers

#include <string>
#include <vector>

namespace PCL
{
  class CLoader
  {
  private:
    void loadErrorMessages();
  public:
    CLoader();
  };

  static CLoader executeLoader;

  CLoader::CLoader()
  {
    loadErrorMessages();
  }

  /// @brief Adds the PCL library error codes into the GCL error object.
  /// @throws None.
  /// @version  2018-09-20/GGB - Function created.

  void CLoader::loadErrorMessages()
  {
    std::vector<std::pair<GCL::TErrorCode, std::string>> errors =
    {
      {0x0100, std::string("PRESSURE: Invalid Units")},
      {0x0200, std::string("Velocity: Invalid Units")},
      {0x1000, std::string("TEMPERATURE: Invalid Units")},
      {0x2000, std::string("LENGTH: Invalid Units")},
      {0x3000, std::string("MASS: Invalid Units")}
    };

    std::for_each(errors.begin(), errors.end(),
                  [] (std::pair<GCL::TErrorCode, std::string> p) { GCL::CError::addErrorMessage("ACL", p.first, p.second); });
  }


}  // namespace PCL
