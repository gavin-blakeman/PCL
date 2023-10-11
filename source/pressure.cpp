//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Pressure.cpp
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

#include "include/pressure.h"

#include "include/constants.h"

#include <GCL>

namespace PCL
{
  //*******************************************************************************************************************************
  //
  // CPressure
  //
  //*******************************************************************************************************************************

  /// @brief Class constructor
  /// @param[in] newPressure: The new pressure value.
  /// @param[in] units: The type of units associated with the new value.
  /// @version 2011-07-29/GGB - Function created.

  CPressure::CPressure(FP_t newPressure, PU units)
  {
    create(newPressure, units);
  }

  /// @brief Comparison function for class.
  /// @param[in] rhs - The pressure value to compare.
  /// @returns true - Values are equal
  /// @returns false - Values are not equal
  /// @throws None.
  /// @version 2015-09-17/GGB - Function created.

  bool CPressure::operator==(CPressure const &rhs) const
  {
    return pressure_ == rhs.pressure_;
  }

  /// @brief Comparison function for class.
  /// @param[in] pressure - The pressure value to compare.
  /// @returns true - Values are equal
  /// @returns false - Values are not equal
  /// @throws None.
  /// @version 2015-09-17/GGB - Function created.

  bool CPressure::operator==(FP_t pressure) const
  {
    return pressure_ == pressure;
  }

  /// @brief Returns the pressure in the specified units.
  /// @param[in] units: The units to use for the return value.
  /// @returns The Pressure in the specified units.
  /// @throws 0x0100
  /// @version 2011-07-29/GGB - Function created

  FP_t CPressure::operator ()(PU units) const
  {
    FP_t retVal;

    switch (units)
    {
      case PU::NONE:
      {
        ERRORMESSAGE("PRESSURE: Invalid Units");
        break;
      };
      case PU::PA:
      {
        retVal = pressure_;
        break;
      };
    case PU::BAR:
      retVal = PaToBar(pressure_);
      break;
    case PU::ATM:
      retVal = PaToAtm(pressure_);
      break;
    case PU::TORR:
      retVal = PaToTorr(pressure_);
      break;
    case PU::PSI:
      retVal = PaToPsi(pressure_);
      break;
    case PU::INHG:
      retVal = PaToInHg(pressure_);
      break;
    default:
      ERRORMESSAGE("PRESSURE: Invalid Units");
      break;
    };

    return retVal;
  }

  // Converts pressure in one scale to another scale.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::convert(FP_t Pressure, PU unitS, PU unitF)
  {
    CPressure p(Pressure, unitS);

    return p(unitF);
  }

  /// @brief Creates the object correctly.
  /// @param[in] Pressure - The new pressure of the instance.
  /// @param[in] units - The units of the pressure value.
  /// @throws GCL::CError(PCL, 0x0100)
  /// @note Pressure is always stored as Pascals (Pa)
  /// @version 2014-12-29/GGG - Removed throw specifier.
  /// @version 2011-07-29/GGB - Function created.

  void CPressure::create(FP_t Pressure, PU units)
  {
    switch (units)
    {
    case PU::NONE:
      ERRORMESSAGE("PRESSURE: Invalid Units");
      break;
    case PU::PA:
      pressure_ = Pressure;
      break;
    case PU::BAR:
      pressure_ = BarToPa(Pressure);
      break;
    case PU::ATM:
      pressure_ = AtmToPa(Pressure);
      break;
    case PU::TORR:
      pressure_ = TorrToPa(Pressure);
      break;
    case PU::PSI:
      pressure_ = PsiToPa(Pressure);
      break;
    case PU::INHG:
      pressure_ = InHgToPa(Pressure);
      break;
    default:
      ERRORMESSAGE("PRESSURE: Invalid Units");
      break;
    };
  }

  // Converts Atm to Pascal
  //
  // 2011-07-29/GGB - Fynction created.

  FP_t CPressure::AtmToPa(FP_t toConvert)
  {
    return toConvert * DPAATM;
  }

  // Converts Bar to Pascal
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::BarToPa(FP_t toConvert)
  {
    return toConvert * DBARPA;
  }

  // Converts InHg to Pa.
  //
  // 2011-07-31/GGB - Function created.

  FP_t CPressure::InHgToPa(FP_t toConvert)
  {
    return toConvert * DINHGPA;
  }

  // Converts Pascal to Atm
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::PaToAtm(FP_t toConvert)
  {
    return toConvert / DPAATM;
  }

  // Converts Pascal to Bar
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::PaToBar(FP_t toConvert)
  {
    return toConvert / DBARPA;
  }

  // Converts Pa to InHg.
  //
  // 2011-07-31/GGB - Function created.

  FP_t CPressure::PaToInHg(FP_t toConvert)
  {
    return toConvert / DINHGPA;
  }

  // Converts Pascal to PSI
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::PaToPsi(FP_t toConvert)
  {
    return toConvert / DPAPSI;
  }

  // Converts Pascal to Torr
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::PaToTorr(FP_t toConvert)
  {
    return toConvert / DPATORR;
  }

  // Converts PSI to Pascal
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::PsiToPa(FP_t toConvert)
  {
    return toConvert * DPAPSI;
  }

  // Converts Torr to Pascal
  //
  // 2011-07-29/GGB - Function created.

  FP_t CPressure::TorrToPa(FP_t toConvert)
  {
    return toConvert * DPATORR;
  }

}  // namespace PCL
