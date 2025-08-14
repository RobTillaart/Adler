#pragma once
//
//    FILE: Adler32.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.6
//    DATE: 2022-01-27
// PURPOSE: Arduino Library for calculating Adler-32 checksum
//     URL: https://github.com/RobTillaart/Adler
//          https://en.wikipedia.org/wiki/Adler-32


#include "Arduino.h"


#define ADLER64_LIB_VERSION        (F("0.2.6"))


//  largest prime below 2^32
const uint32_t ADLER64_MOD_PRIME = 4294967291;


class Adler64
{
public:
  Adler64();

  void     begin(uint64_t s1 = 1, uint64_t s2 = 0);


  void     add(uint8_t value);
  //  returns current Adler value
  uint64_t add(uint8_t * array, uint16_t length);
  //  trade PROGMEM for speed
  //  returns current Adler value
  uint64_t addFast(uint8_t * array, uint16_t length);


  //  wrappers for char array's / strings
  void     add(char value);
  //  returns current Adler value
  uint64_t add(char * array, uint16_t length);
  //  returns current Adler value
  uint64_t addFast(char * array, uint16_t length);


  uint64_t getAdler();
  uint64_t count();


private:
  uint64_t _s1;
  uint64_t _s2;
  uint64_t _count;
};


//  -- END OF FILE --

