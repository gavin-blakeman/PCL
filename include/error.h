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
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30/GGB - astroManager 2013.09 release.
//                      2013-03-22/GGB - astroManager 2013.03 release.
//                      2013-01-20/GGB - astroManager 0000.00 release.
//                      2011-07-29/GGB - Development of classes for openAIRAS
//
//*********************************************************************************************************************************

#ifndef PCL_PCLERROR_H
#define PCL_PCLERROR_H

// Miscellaneous libraries

#include "../GCL/include/error.h" //!!! If the full GCL package is included at this point, it creates cicular references and errors.

namespace PCL
{
#define PCL_ERROR(errorNo) (ERROR(PCL, errorNo))
#define PCL_CODE_ERROR CODE_ERROR(PCL)

}	// namespace PCL

#endif // PCL_PCLERROR_H
