//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								Length.cpp
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

#include "include/distance.h"

#include "include/constants.h"

#include <GCL>

namespace PCL
{
  //*******************************************************************************************************************************
  //
  // CLength
  //
  //*******************************************************************************************************************************

  /// @brief Constructor for the class.
  /// @param[in] length: The length to intialise the class with.
  /// @param[in] unit: The units of length
  /// @throws None.
  /// @version 2011-07-29/GGB - Function created.

  CDistance::CDistance(FP_t length, DU unit)
  {
    create(length, unit);
  }

  /// @brief Returns the value in the specified units.
  /// @param[in] unit: The units to return.
  /// @returns The stored length in the specified units.
  /// @throws CError(PCL, 0x2000)
  /// @version 2015-06-21/GGB - Removed throw() specifier.
  /// @version 2011-07-11/GGB - Function created.

  FP_t CDistance::operator ()(DU unit) const
  {
    FP_t retVal;

    switch (unit)
    {
    case DU::NONE:
      ERRORMESSAGE("LENGTH: Invalid Units");
      break;
    case DU::METER:
      retVal = _length;
      break;
    case DU::INCH:
      retVal = MeterToInch(_length);
      break;
    case DU::YARD:
      retVal = MeterToYard(_length);
      break;
    case DU::ANGSTOM:
      retVal = MeterToAngstrom(_length);
      break;
    case DU::FATHOM:
      retVal = MeterToFathom(_length);
      break;
    case DU::FOOT:
      retVal = MeterToFoot(_length);
      break;
    case DU::LEAGUE:
      retVal = MeterToLeague(_length);
      break;
    case DU::MILE:
      retVal = MeterToMile(_length);
      break;
    default:
      ERRORMESSAGE("LENGTH: Invalid Units");
      break;
    };

    return retVal;
  }

  /// @brief Converts angstroms to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::AngstromToMeter(FP_t toConvert)
  {
    return toConvert * DANGSTROM;
  }

  // Converts one unit to another.
  //
  // 2011-07-31/GGB - Function created.

  FP_t CDistance::convert(FP_t length, DU unitS, DU unitF)
  {
    CDistance l(length, unitS);

    return l(unitF);
  }

  // Creates the object and converts the length to meters.
  //
  // 2015-06-21/GGB - Removed throw() specification.
  // 2011-07-29/GGB - Function created.

  void CDistance::create(FP_t length, DU unit)
  {
    switch (unit)
    {
    case DU::NONE:
      ERRORMESSAGE("LENGTH: Invalid Units");
      break;
    case DU::METER:
      _length = length;
      break;
    case DU::INCH:
      _length = InchToMeter(length);
      break;
    case DU::YARD:
      _length = YardToMeter(length);
      break;
    case DU::ANGSTOM:
      _length = AngstromToMeter(length);
      break;
    case DU::FATHOM:
      _length = FathomToMeter(length);
      break;
    case DU::FOOT:
      _length = FootToMeter(length);
      break;
    case DU::LEAGUE:
      _length = LeagueToMeter(length);
      break;
    case DU::MILE:
      _length = MileToMeter(length);
      break;
    default:
      ERRORMESSAGE("LENGTH: Invalid Units");
      break;
    };
  }

  // Converts fathoms to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::FathomToMeter(FP_t toConvert)
  {
    return (toConvert * DFATHOM);
  }

  // Converts international foot to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::FootToMeter(FP_t toConvert)
  {
    return (toConvert * DFOOT);
  }

  // Converts from inches to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::InchToMeter(FP_t toConvert)
  {
    return toConvert * DINCH;
  }

  // Converts Leagues to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::LeagueToMeter(FP_t toConvert)
  {
    return (toConvert * DLEAGUE);
  }

  // Converts meters to Angstroms.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::MeterToAngstrom(FP_t toConvert)
  {
    return (toConvert / DANGSTROM);
  }

  // Converts meters to fathoms.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::MeterToFathom(FP_t toConvert)
  {
    return (toConvert / DFATHOM);
  }

  // Converts meters to foot
  //
  // R/D/A: 1.00/2011-07-29/GGB

  FP_t CDistance::MeterToFoot(FP_t toConvert)
  {
    return (toConvert / DFOOT);
  }

  // Converts meters to inch
  //
  // 2011-07-29/GGB - Function created.

  double CDistance::MeterToInch(double toConvert)
  {
    return (toConvert / DINCH);
  }

  // Converts meters to leagues
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::MeterToLeague(FP_t toConvert)
  {
    return (toConvert / DLEAGUE);
  }

  // Converts Meters to Miles.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::MeterToMile(FP_t toConvert)
  {
    return (toConvert / DMILE);
  }

  // Converts Meters to Yards.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::MeterToYard(FP_t toConvert)
  {
    return (toConvert / DYARD);
  }

  /// @brief Converts miles to meters.
  /// @param[in] toConvert: The value to convert.
  /// @returns The converted value.
  /// @throws
  /// @version 2011-07-29/GGB - Function created.

  FP_t CDistance::MileToMeter(FP_t toConvert)
  {
    return (toConvert * DMILE);
  }

  // Converts from Yards to meters.
  //
  // 2011-07-29/GGB - Function created.

  FP_t CDistance::YardToMeter(FP_t toConvert)
  {
    return toConvert * DYARD;
  }

}  // namespace PCL
