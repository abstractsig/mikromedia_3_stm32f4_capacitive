/*
 *
 * Micro stm32f407 touch display board configuration
 *
 *                        .--------------------.
 *                        | 1 5V       NRST   1|
 *                        | 2 0V       3V3    2|
 *                        | 3 PA4      Audio  3|
 *                        | 4 PB0             4|
 *                        | 5 PB1             5| 
 *                        | 6 PC0             6| 
 *                        | 7 PC2       PD12  7| 
 *                        | 8 PC3       PD13  8| 
 *                        | 9 PA1       PD14  9|            
 *                        |10 PA2       PD15 10| 
 *                        |11 PB12      PE9  11| 
 *                        |12 PB13      PE10 12| 
 *                        |13 PB14      PC4  13| 
 *                        |14 PB15      PC5  14| 
 *                        |15 PD0       PB2  15| 
 *                        |16 PD1       PA8  16| 
 *                        |17 PA15      PB10 17| 
 *                        |18 PA5       PB11 18| 
 *                        |19 PA6       PC7  19| 
 *                        |20 PA7       PC6  20| 
 *                        |21 PC13      PA3  21| 
 *                        |22 PB3       PD5  22| 
 *                        |23 PB4       PB6  23| 
 *                        |24 PB5       PB7  24| 
 *                        |25 3V3       0V   25| 
 *                        |26 0V        PD7  26| 
 *                        `--------------------'
 *
 *
 * On Board Peripheral Chips
 * =========================
 *
 *  PTN5150			USB-C configuration chanel detection and indication
 *						PA9 & PA10
 *  
 *  SSD1963			display controller
 *						8-bit parallel bus
 *
 *  FT5316			capacitive touch detector
 *						I2C1_SCL (PB6) I2C1_SDA (PB7) PH1 Interrupt
 *
 *  VS1053			audio codec
 *						(should be an adafruit lib for this)
 *
 *  SST26VF064		8Mbyte SPI flash
 *						SPI2: PB13(SCK) PB14(MISO) PB15(MOSI) PE8(CS)
 *
 *  MCP1501			voltage reference
 *
 *  MCP9700			temperature sensor
 *						(I2C)
 *
 *  FXOS8700		acceleration
 *						(I2C)
 *
 *  LTR-329ALS		ambient light sensor
 *						(I2C)
 *
 */
#ifndef io_board_H_
#define io_board_H_
#include <io_cpu.h>

void io_board_panic (io_t*,int);

#define SPECIALISE_IO_BOARD_IMPLEMENTATION(S) \
    SPECIALISE_IO_CPU_IMPLEMENTATION(S) \
	 .panic = io_board_panic,\
    /**/


#ifdef IMPLEMENT_IO_BOARD
//-----------------------------------------------------------------------------
//
// Implementation
//
//-----------------------------------------------------------------------------
void
io_board_panic (io_t *io,int code) {
	DISABLE_INTERRUPTS;
	
	while (1) {
//		toggle_io_pin (io,LED1);
//		SHORT_DELAY(1000);
	}
}

void
initialise_io_board (io_t *io) {
	initialise_cpu_io (io);

}

#endif /* IMPLEMENT_IO_BOARD */
#endif
