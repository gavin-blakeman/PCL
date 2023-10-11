//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Pressure.h
// SUBSYSTEM:						Physics Class Library Pressure Classes
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
// OVERVIEW:            Implements a class for handling Pressures.
//
// CLASSES INCLUDED:    CPressure
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef PCL_PRESSURE_H
#define PCL_PRESSURE_H

#include "error.h"
#include "common.h"

#ifdef _MSC_VER
#pragma warning( disable : 4290 )  /* Disable the warning about C++ exception specifications. */
#endif

namespace PCL
{
  enum class PU
  {
    NONE,                  ///< No pressure specified. Results in an error.
    PA,                    ///< Pascals
    BAR,                   ///< Bar
    ATM,                   ///< Atmospheres
    TORR,                  ///< Torr
    PSI,                   ///< Pounds per square inch
    INHG                   ///< inches of mercury
  };

  class CPressure
  {
  private:
    FP_t pressure_;

    CPressure() = delete;

    void create(FP_t, PU);

  protected:
    static FP_t PsiToPa(FP_t);
    static FP_t BarToPa(FP_t);
    static FP_t AtmToPa(FP_t);
    static FP_t TorrToPa(FP_t);
    static FP_t InHgToPa(FP_t);

    static FP_t PaToPsi(FP_t);
    static FP_t PaToBar(FP_t);
    static FP_t PaToAtm(FP_t);
    static FP_t PaToTorr(FP_t);
    static FP_t PaToInHg(FP_t);

  public:
    CPressure(FP_t, PU = PU::PA);

    bool operator==(CPressure const &) const;
    bool operator==(FP_t) const;
    FP_t operator ()(PU = PU::PA) const;

    static FP_t convert(FP_t, PU, PU);
  };
}  // namespace PCL

#endif // PCL_PRESSURE_H
