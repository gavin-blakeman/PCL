//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Length.h
// SUBSYSTEM:						Length Classes
// LANGUAGE:						C++
// TARGET OS:						All
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2011-2018 Gavin Blakeman.
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
// CLASSES INCLUDED:    CLength
//
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef PCL_LENGTH_H
#define PCL_LENGTH_H

#include "common.h"
#include "error.h"

#ifdef _MSC_VER
#pragma warning( disable : 4290 )  /* Disable the warning about C++ exception specifications. */
#endif

namespace PCL
{
  double const IN_to_MM    (25.4);

  enum class DU
  {
    NONE,
    METER,
    INCH,
    YARD,
    ANGSTOM,
    FATHOM,
    FOOT,
    LEAGUE,
    MILE
  };

  class CDistance
  {
  private:
    FP_t _length;     ///< Distance stored in meters.

    void create(double, DU);

  protected:
    static FP_t InchToMeter(FP_t);
    static FP_t YardToMeter(FP_t);
    static FP_t AngstromToMeter(FP_t);
    static FP_t FathomToMeter(FP_t);
    static FP_t FootToMeter(FP_t);
    static FP_t LeagueToMeter(FP_t);
    static FP_t MileToMeter(FP_t);

    static FP_t MeterToInch(FP_t);
    static FP_t MeterToYard(FP_t);
    static FP_t MeterToAngstrom(FP_t);
    static FP_t MeterToFathom(FP_t);
    static FP_t MeterToFoot(FP_t);
    static FP_t MeterToLeague(FP_t);
    static FP_t MeterToMile(FP_t);

  public:
    CDistance(FP_t, DU = DU::METER);

    FP_t operator ()(DU) const;

    static FP_t convert(FP_t, DU, DU);
  };

}

#endif // PCL__LENGTH
