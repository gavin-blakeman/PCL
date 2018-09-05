//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Temperature.h
// SUBSYSTEM:						Temperature Classes
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
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
// OVERVIEW:            Implements a class for handling temperatures
//
// CLASSES INCLUDED:    CTemperature
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef PCL_TEMPERATURE_H
#define PCL_TEMPERATURE_H

#include "PCLError.h"

#include "common.h"

#ifdef _MSC_VER
#pragma warning( disable : 4290 )  /* Disable the warning about C++ exception specifications. */
#endif

namespace PCL
{
  enum ETemperatureUnits
  {
    TU_NONE,
    TU_C,
    TU_K,
    TU_F,
    TU_R
  };


  /// @brief Class to represent a physical temperature value.
  /// @details The class is used to represent temperature values. The temperature is always specified as a temperature::unit pair
  /// when accessing the class. The underlying storage in the class is always in Kelvin.

  class CTemperature
  {
  private:
    FP_t temperature_;

    CTemperature() = delete;

  protected:
    void create(FP_t, ETemperatureUnits);
    static FP_t CelsiusToKelvin(FP_t);
    static FP_t FarenheitToKelvin(FP_t);
    static FP_t RankineToKelvin(FP_t);

    static FP_t KelvinToCelsius(FP_t);
    static FP_t KelvinToFarenheit(FP_t);
    static FP_t KelvinToRankine(FP_t);

  public:
    CTemperature(FP_t , ETemperatureUnits = TU_C);
    CTemperature(CTemperature const &toCopy) : temperature_(toCopy.temperature_) {}

    CTemperature &operator =(CTemperature const &);
    bool operator ==(CTemperature const &) const;
    bool operator ==(FP_t) const;

    FP_t operator ()(ETemperatureUnits = TU_C) const;

    static FP_t convert(FP_t, ETemperatureUnits, ETemperatureUnits);
  };

} // namespace PCL

#endif // PCL_TEMPERATURE_H
