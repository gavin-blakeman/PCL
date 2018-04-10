//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								PCLError.h
// SUBSYSTEM:						Physics Class Library Exception subsystem
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	GCL
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
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
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2013-09-30/GGB - AIRDAS 2013.09 release.
//                      2013-03-22/GGB - AIRDAS 2013.03 release.
//                      2013-01-20/GGB - AIRDAS 0000.00 release.
//                      2011-07-29/GGB - Development of classes for openAIRAS
//
//*********************************************************************************************************************************

#ifndef PCL_PCLERROR_H
#define PCL_PCLERROR_H

#include <stdexcept>
#include <string>
#include <map>

namespace PCL
{

  typedef std::map<size_t, std::string> TErrorStore;

  class CPCLError : public std::runtime_error
  {
  private:
    static TErrorStore errorMessages;
    unsigned int errorCode_;

  public:
    inline explicit CPCLError(unsigned int newError) : std::runtime_error("PCL Error"), errorCode_(newError) {}
    inline virtual ~CPCLError() throw() {}

    virtual unsigned int getErrorCode() const { return errorCode_;}
    virtual std::string getErrorMessage() const;
    virtual void logErrorMessage() const;

    static void loadErrorMessages();
  };

  class CPCLCodeError : public CPCLError
  {
  private:
    std::string fileName;
    long lineNo;
    std::string timeStamp;

  public:
    inline explicit CPCLCodeError(const std::string newFile, const std::string newTime, long newLine)
      : CPCLError(0xFFFF), fileName(newFile), lineNo(newLine), timeStamp(newTime) {}
    inline virtual ~CPCLCodeError() throw() {}

    virtual std::string getErrorMessage() const;
    virtual void logErrorMessage() const;
  };

#define PCL_ERROR(errorNo) (throw(CPCLError(errorNo)))
#define PCL_CODE_ERROR throw (CPCLCodeError( __FILE__, __TIMESTAMP__, (long) __LINE__) )

}	// namespace PCL

#endif // PCL_PCLERROR_H
