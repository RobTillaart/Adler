//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2022-01-25
// PURPOSE: unit tests for the GAMMA library
//          https://github.com/RobTillaart/GAMMA
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "Adler.h"



unittest_setup()
{
  fprintf(stderr, "ADLER_LIB_VERSION: %s\n", (char *) ADLER_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_adler32)
{
  char str1[24] = "abcde";
  char str2[24] = "abcdef";
  char str3[24] = "abcdefgh";

  fprintf(stderr, "%d\n", adler32(str1, 5));
  fprintf(stderr, "%d\n", adler32(str2, 6));
  fprintf(stderr, "%d\n", adler32(str3, 8));
  
  assertEqual(4031760169UL, adler32(str1, 5));
  assertEqual(1448095018UL, adler32(str2, 6));
  assertEqual(3957429649UL, adler32(str3, 8));
}


unittest_main()

// --------
