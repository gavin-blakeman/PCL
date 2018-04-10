//*********************************************************************************************************************************
//
// PROJECT:							Physics Class Library
// FILE:								constants.h
// SUBSYSTEM:						Constants
// LANGUAGE:						C++
// TARGET OS:						All
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
// OVERVIEW:            Physics constants.
//
// CLASSES INCLUDED:    None.
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2013-09-30 GGB - AIRDAS 2013.09 release.
//                      2013-03-22 GGB - AIRDAS 2013.03 release.
//                      2013-01-20 GGB - AIRDAS 0000.00 release.
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef PCL_CONSTANTS
#define PCL_CONSTANTS

namespace PCL
{

    // TIme

  double const SecondsPerMinute = 60;                                 ///< Seconds per minute
  double const MinutesPerHour = 60;                                   ///< Minutes per hour
  double const SecondsPerHour = SecondsPerMinute * MinutesPerHour;    ///< Seconds in an hour
  double const HoursPerDay = 24;                                      ///< Hours in a day
  double const DaysPerYear = 365.25;                                  ///< Days in a year

    // Length

  double const DINCH = 0.0254;                                        ///< meters per inch
  double const DYARD = 0.9144;                                        ///< meters per yard
  double const DANGSTROM = 1E-10;                                     ///< meters per angstrom
  double const DFATHOM = 1.8288;                                      ///< meters per fathom
  double const DFOOT = 0.3048;                                        ///< meters per foot
  double const DLEAGUE = 4828.032;                                    ///< meters per league
  double const DMILE = 1609.344;                                      ///< meters per mile

    // Temperature

  double const DKELVIN	= 273.15;                                     ///< Kelvin at 0 C

    // Pressure

  double const DPAPSI = 6.895E3;
  double const DPAATM = 1.01325E5;
  double const DPATORR = 133.322;
  double const DBARPA = 1E5;                                          ///< Pascals per bar
  double const DINHGPA = 3386.389;                                    ///< Pascals per inHg

    // Dimensionless

  double const DSQRT2 = 1.41421356237;                                ///< Square root of two

}	// namespace PCL

#endif // PCL_CONSTANTS
