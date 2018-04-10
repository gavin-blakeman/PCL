//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Mass.h
// SUBSYSTEM:						Mass Classes
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2011-2016 Gavin Blakeman.
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
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2013-09-30 GGB - AIRDAS 2013.09 release.
//                      2013-03-22 GGB - AIRDAS 2013.03 release.
//                      2013-01-20 GGB - AIRDAS 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef PCL_MASS_H
#define PCL_MASS_H

#include "PCLError.h"

#ifdef _MSC_VER
#pragma warning( disable : 4290 )  /* Disable the warning about C++ exception specifications. */
#endif

namespace PCL
{
  enum EMassUnit
  {
    MU_NONE,
    MU_KG,
    MU_LB,
  };

  class CMass
  {
  private:
    double _kg;

    void create(double, EMassUnit);

  protected:
    static double LBtoKG(double);

    static double KGtoLB(double);

  public:
    CMass(double, EMassUnit);

    double operator ()(EMassUnit) const;

    static double convert(double, EMassUnit, EMassUnit);
  };
}

#endif  // PCL_MASS_H
