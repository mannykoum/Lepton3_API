#ifndef _SPI_H_
#define _SPI_H_
#include <fcntl.h>				//Needed for SPI port
#include <sys/ioctl.h>			//Needed for SPI port
#include <linux/spi/spidev.h>	//Needed for SPI port
#include <unistd.h>				//Needed for SPI port
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstring>

#define SPEED 200000000
#define BITS_PER_WORD 8

extern int spi_cs0_fd;
extern int spi_cs1_fd;
extern unsigned char spi_mode;
extern unsigned char spi_bitsPerWord;
extern unsigned int spi_speed;

int SpiOpenPort (int spi_device);
int SpiClosePort (int spi_device);

int SpiWriteAndRead (int spi_device, uint8_t *data, unsigned int length);
int SpiWrite (int spi_device, uint8_t *data, unsigned int length);
int SpiRead (int spi_device, uint8_t *data, unsigned int length);

#endif
