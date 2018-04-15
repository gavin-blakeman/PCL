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
//                      Copyright 2011-2016 Gavin Blakeman.
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
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29/GGB - Development of classes for openAIRAS
//
//*********************************************************************************************************************************

#include "../Include/PCLError.h"

#include "boost/lexical_cast.hpp"

#include <GCL>

namespace PCL
{
  TErrorStore CPCLError::errorMessages;

  struct SErrorCodes
  {
    size_t errorCode;
    std::string errorMessage;
  };

  SErrorCodes errorArray[] =
  {
    {0x0100, std::string("PRESSURE: Invalid Units")},
    {0x0200, std::string("Velocity: Invalid Units")},
    {0x1000, std::string("TEMPERATURE: Invalid Units")},
    {0x2000, std::string("LENGTH: Invalid Units")},
    {0x3000, std::string("MASS: Invalid Units")}
  };

  /// Returns the string of the error message.
  //
  // 2011-03-13/GGB - Function created.

  std::string CPCLError::getErrorMessage() const
  {
    TErrorStore:: const_iterator errorData;

    if ((errorData = errorMessages.find(errorCode_)) == errorMessages.end() )
    {
        // Error message not found - Error code has not been defined.
        // This is a non-recoverable error.

      exit(0xFFFE);		// Non-recoverable error within an error
    }
    else
    {
      return (errorData->second);
    };
  }

  /// Static function to copy all the error messages from the array into the map.
  /// The error messages do not have to be in order or contiguous in the array.
  //
  // 2011-03-13/GGB - Function created.

  void CPCLError::loadErrorMessages()
  {
    size_t elements = sizeof(errorArray) / sizeof(SErrorCodes);   // Work out how many elements stored.
    size_t index;

    for (index = 0; index < elements; index++)
      errorMessages[errorArray[index].errorCode] = errorArray[index].errorMessage;
  }

  /// Function to write the error message to a logFile.
  /// This is not automatically done in the library when an exception is thrown as the library may be able to recover from the
  /// exception without having to terminate.
  //
  // 2014-12-24/GGB - Function created.

  void CPCLError::logErrorMessage() const
  {
    TErrorStore::const_iterator errorData;

    if ((errorData = errorMessages.find(errorCode_)) == errorMessages.end() )
    {
        // Error message not found - Error code has not been defined.
        // This is a non-recoverable error.

      GCL::logger::defaultLogger().logMessage(GCL::logger::error,
                                           "Non recoverable error within an error in PCL. Error Code: " +
                                           boost::lexical_cast<std::string>(errorCode_) + ". Terminating");
      exit(0xFFFE);		// Non-recoverable error within an error
    }
    else
      GCL::logger::defaultLogger().logMessage(GCL::logger::warning,
                                           "PCL Error Code: " + boost::lexical_cast<std::string>(errorData->first) +
                                           " - " + errorData->second);
  }

  //********************************************************************************************************************************
  //
  // CPCLCodeError
  //
  //********************************************************************************************************************************

  /// Displays the error message in a QMessageBox.
  //
  // 2011-02-26/GGB - Function created.

  std::string CPCLCodeError::getErrorMessage() const
  {
    std::string msgText;

    //msgText << "A code error has occurred.\n\nVersion: " << MAJORVERSION << "." << MINORVERSION;
              //"Build Number: %3\n" \
              //"File Name: %4 dated: %5\n" \
              //"Line Number: %6").arg(MAJORVERSION).
              //arg(MINORVERSION).
              //arg(BUILDNUMBER).
              //arg(fileName.c_str()).
              //arg(timeStamp.c_str()).
              //arg(lineNo);

    return msgText;
  }

  /// Function to write the error message to a logFile.
  /// This is not automatically done in the library when an exception is thrown as the library may be able to recover from the
  /// exception without having to terminate.
  //
  // 2014-12-24/GGB - Function created.

  void CPCLCodeError::logErrorMessage() const
  {
    GCL::logger::defaultLogger().logMessage(GCL::logger::error,
                                         "A Code Error has occurred in the PCL library File Name: " + fileName +
                                         ". Line Number: " + boost::lexical_cast<std::string>(lineNo));
  }

}  // namespace PCL
