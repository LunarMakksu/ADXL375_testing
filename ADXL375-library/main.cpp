// Created by Max Bird on 10/10/22

#include <iostream>
#ifndef ADXL375_H
#define ADXL375_H

#include "protocol.h"
#include "Vector.h"
#include "ADXL375_registers.h"
#include "ADXL375_constants.h"

class ADXL375{
    protected:
        protocol *device;
    public:
        ADXL375(TwoWire *pipe, uint32_t freq) { // constructor for I2C protocol
            device = new I2CProtocol(ADXL375_DEFAULT_I2C_ADDRESS, pipe, freq);
        }

        ADXL375(byte chipSelect, SPIClass& spi, SPISettings settings) {// constructor overload for SPI protocol
            device = new SPIProtocol(chipSelect, spi, settings, READ_BYTE, WRITE_BYTE);
        }
};