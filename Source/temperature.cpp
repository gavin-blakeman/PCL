//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Temperature.cpp
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

#include "../Include/temperature.h"

#include "../Include/constants.h"

namespace PCL
{
  //********************************************************************************************************************************
  //
  // CTemperature
  //
  //********************************************************************************************************************************

  /// @brief Constructor for a temperature object.
  /// @param[in] temperature - Temperature to assign to this instance.
  /// @param[in] units - The units of temperature.
  /// @throws None
  /// Calls the create function.
  /// @version 2011-07-29/GGB - Function created.

  CTemperature::CTemperature(FP_t temperature, ETemperatureUnits units)
  {
    create(temperature, units);
  }

  /// @brief Assignment operator.
  /// @param[in] toCopy - The temperature object to copy from.
  /// @returns Reference to this object
  /// @throws None.
  /// @version 2015-09-18/GGB - Function created.

  CTemperature &CTemperature::operator =(CTemperature const &toCopy)
  {
    temperature_ = toCopy.temperature_;

    return *this;
  }

  /// @brief Comparison function for class.
  /// @param[in] rhs - The temperature value to compare.
  /// @returns true - Values are equal
  /// @returns false - Values are not equal
  /// @throws None.
  /// @version 2015-09-17/GGB - Function created.

  bool CTemperature::operator ==(CTemperature const &rhs) const
  {
    return temperature_ == rhs.temperature_;
  }

  /// @brief Comparison function for class.
  /// @param[in] temperature - The temperature value to compare.
  /// @returns true - Values are equal
  /// @returns false - Values are not equal
  /// @throws None.
  /// @version 2015-09-17/GGB - Function created.

  bool CTemperature::operator ==(FP_t temperature) const
  {
    return temperature_ == temperature;
  }


  /// Function operator.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::operator ()(ETemperatureUnits units) const
  {
    FP_t retVal;

    switch (units)
    {
    case TU_NONE:
      PCL_ERROR(0x1000);
      break;
    case TU_C:
      retVal = KelvinToCelsius(temperature_);
      break;
    case TU_K:
      retVal = temperature_;
      break;
    case TU_F:
      retVal = KelvinToFarenheit(temperature_);
      break;
    default:
      PCL_ERROR(0x1000);
      break;
    };

    return retVal;
  }

  // Converts a temperaure from one unit to another.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::convert(FP_t toConvert, ETemperatureUnits unitS, ETemperatureUnits unitF)
  {
    CTemperature temp(toConvert, unitS);

    return temp(unitF);
  }

  /// Creates the object and stores the temperature as K.
  //
  // 2014-12-29/GGB - Removed throw specifier
  // 2011-07-29/GGB - Function created.

  void CTemperature::create(FP_t newTemperature, ETemperatureUnits units)
  {
    switch (units)
    {
    case TU_NONE:
      PCL_ERROR(0x1000);
      break;
    case TU_C:
      temperature_ = CelsiusToKelvin(newTemperature);
      break;
    case TU_K:
      temperature_ = newTemperature;
      break;
    case TU_F:
      temperature_ = FarenheitToKelvin(newTemperature);
      break;
    default:
      PCL_ERROR(0x1000);
      break;
    };
  }

  // Converts celsius to Kelvin
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::CelsiusToKelvin(FP_t toConvert)
  {
    return toConvert + DKELVIN;
  }

  // Convert Farenheit to Kelvin
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::FarenheitToKelvin(FP_t toConvert)
  {
    return (toConvert + 459.67) * 5/9;
  }

  // Converts Rankine to Kelvin.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::RankineToKelvin(FP_t toConvert)
  {
    return toConvert * 5/9;
  }

  // Converts Kelvin to Celsius
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::KelvinToCelsius(FP_t toConvert)
  {
    return toConvert - DKELVIN;
  }

  // Converts Kelvin to Farenheit.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::KelvinToFarenheit(FP_t toConvert)
  {
    return toConvert * 9/5 - 459.67;
  }

  // Converts Kelvin to Rankine
  //
  // 2011-07-29/GGB - Function created.

  FP_t CTemperature::KelvinToRankine(FP_t toConvert)
  {
    return toConvert * 9/5;
  }

}	// namespace PCL
