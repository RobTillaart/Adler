
[![Arduino CI](https://github.com/RobTillaart/Adler/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/Adler/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/Adler/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/Adler/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/Adler/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/Adler/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/Adler.svg?maxAge=3600)](https://github.com/RobTillaart/Adler/releases)


# Adler

Arduino Library for Adler-32 and experimental Adler-16 checksum.


## Description

This library provides a Adler32 checksum of a data array.
Furthermore since 0.2.0 an experimental Adler-16 implementation is added.
This one is faster as it has a smaller checksum than the Adler32,
and the price is that it is less sensitive than the Adler32.
Still it might have its niches where it will be useful.

Relates to https://github.com/RobTillaart/CRC

Relates to https://github.com/RobTillaart/Fletcher

Tested on Arduino UNO only.

0.2.0 is a breaking change, file names have been changed to be more
in line with the CRC library.
- Adler.h for the static functions
- Adler32.h for the Adler32 class
- Adler16.h for the Adler16 class.

## Interface


## Adler class

Use **\#include "Adler32.h"** or **\#include "Adler16.h"**

The interface for the Adler16 is very similar. 

- **Adler32()** Constructor, initializes internals.
- **void begin(uint8_t s1 = 1, uint8_t s2 = 0)** resets the internals.
optional setting start values for s1 and s2. Note this is not part of the standard.
This allows a restart from a specific index in a buffer.
- **void add(uint8_t value)** add a single value to the checksum.
- **void add(const uint8_t \* array, uint8_t length)** add an array of values to the checksum.
- **void addFast(const uint8_t \* array, uint8_t length)** add an array of values to the checksum. Is faster by trading PROGMEM for performance.
- **uint32_t getAdler()** get the current checksum.
- **uint32_t count()** get the number of items added. Merely a debugging feature, can overflow without affecting checksum.

The class is typically used for streaming very large blocks of data,
optional with intermediate checksum tests.


## Performance Adler32

Not tested ESP32 (and many other platforms) yet.

Numbers measured with **Adler32_performance.ino**.


#### add(value)

The **add(value)** adds one byte and does a subtraction
instead of a modulo.

| Version | Function | UNO 16 MHz | ESP32 240 MHz |
|:-------:|:---------|:----------:|:-------------:|
| 0.1.0   | add      |   5.6 us   |               |
| 0.1.2   | add      |   6.6 us   |               |
| 0.2.0   | add      |   5.9 us   |               |


#### add(lorem) 868 chars

The **add(array, length)** is a straightforward loop
over the array and has a small footprint.

| Version | Function | UNO 16 MHz | ESP32 240 MHz |
|:-------:|:---------|:----------:|:-------------:|
| 0.1.0   | add      |            |               |
| 0.1.2   | add      |  6392 us   |               |
| 0.2.0   | add      |  5748 us   |               |

Note: **add()** is about 6.6 us per byte.


#### addFast(lorem) 868 chars

(since 0.1.2) 

The **addFast(array, length)** is faster than the 
reference **add(array, length)** and uses 108 bytes more.
So the function has a larger footprint. 
Depending on your needs, choose performance or footprint. 

See **Adler32_performance_addFast.ino**


| Version | Function | UNO 16 MHz | ESP32 240 MHz |
|:-------:|:---------|:----------:|:-------------:|
| 0.1.0   | addFast  |            |               |
| 0.1.2   | addFast  |  1348 us   |               |
| 0.2.0   | addFast  |  1348 us   |               |

Note: **addFast()** is less than 2 us per byte.


## Interface static functions

The functions are straightforward.

Use **\#include "Adler.h"**

- **uint32_t adler32(uint8_t \*data, uint16_t length)** length in units of 1 byte = 8 bits.
- **uint16_t adler16(uint8_t \*data, uint16_t length)** length in units of 1 byte = 8 bits.

The functions are typically used for an in memory buffer to calculate the checksum once. 
Think of packets in a network, records in a database, or a checksum for an configuration in EEPROM.


#### Performance

Not tested ESP32 (and many other platforms) yet.

Numbers measured with **Adler_performance.ino**.

Lorem Ipsum text = 868 bytes.

| Version | Function | UNO 16 MHz | ESP32 240 MHz |
|:-------:|:---------|:----------:|:-------------:|
| 0.1.0   | Adler32  |  1116 us   |               |
| 0.1.2   | Adler32  |  1116 us   |               |
| 0.2.0   | Adler32  |  1116 us   |               |
| 0.2.0   | Adler16  |  1736 us   |               |


Adler32 average 1116 / 868 = 1.29 us per byte.
Adler16 average 1736 / 868 = 2.00 us per byte.

Adler16 does more often the modulo math as it reaches halfway uint16_t 
faster than Adler32 reaches halfway uint32_t.


## Operation

See examples.


## Future

- test other platforms



