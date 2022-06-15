#pragma once
//
//    FILE: Adler.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
//    DATE: 2022-01-27
// PURPOSE: Arduino Library for calculating Adler checksum
//     URL: https://github.com/RobTillaart/Adler
//          https://en.wikipedia.org/wiki/Adler-32


#include "Arduino.h"


#define ADLER_LIB_VERSION        (F("0.2.0"))


#ifndef ADLER32_MOD_PRIME
#define ADLER32_MOD_PRIME             65521
#endif

#ifndef ADLER16_MOD_PRIME
#define ADLER16_MOD_PRIME               251
#endif


/////////////////////////////////////////////////
//
//  STATIC FUNCTIONS
//
uint32_t adler32(uint8_t *data, uint16_t length);
uint16_t adler16(uint8_t *data, uint16_t length);


// -- END OF FILE -- 


