/***************************************************************************//**
 *   @file   platform_drivers.h
 *   @brief  Header file of Xilinx Platform Drivers.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2018(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef PLATFORM_DRIVERS_H_
#define PLATFORM_DRIVERS_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include <stdint.h>
#include <xparameters.h>
#ifdef _XPARAMETERS_PS_H_
#include <xspips.h>
#include <xgpiops.h>
#else
#include <xspi.h>
#include <xgpio.h>
#endif

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/
#define ADI_REG_VERSION			0x0000

#define ADI_REG_ID				0x0004

#define ADI_REG_RSTN			0x0040
#define ADI_RSTN				(1 << 0)
#define ADI_MMCM_RSTN			(1 << 1)

#define ADI_REG_CNTRL			0x0044
#define ADI_R1_MODE				(1 << 2)
#define ADI_DDR_EDGESEL			(1 << 1)
#define ADI_PIN_MODE			(1 << 0)

#define ADI_REG_STATUS			0x005C
#define ADI_MUX_PN_ERR			(1 << 3)
#define ADI_MUX_PN_OOS			(1 << 2)
#define ADI_MUX_OVER_RANGE		(1 << 1)
#define ADI_STATUS				(1 << 0)

#define ADI_REG_DELAY_CNTRL		0x0060	/* <= v8.0 */
#define ADI_DELAY_SEL			(1 << 17)
#define ADI_DELAY_RWN			(1 << 16)
#define ADI_DELAY_ADDRESS(x)	(((x) & 0xFF) << 8)
#define ADI_TO_DELAY_ADDRESS(x)	(((x) >> 8) & 0xFF)
#define ADI_DELAY_WDATA(x)		(((x) & 0x1F) << 0)
#define ADI_TO_DELAY_WDATA(x)	(((x) >> 0) & 0x1F)

#define ADI_REG_CHAN_CNTRL(c)	(0x0400 + (c) * 0x40)
#define ADI_PN_SEL				(1 << 10) /* !v8.0 */
#define ADI_IQCOR_ENB			(1 << 9)
#define ADI_DCFILT_ENB			(1 << 8)
#define ADI_FORMAT_SIGNEXT		(1 << 6)
#define ADI_FORMAT_TYPE			(1 << 5)
#define ADI_FORMAT_ENABLE		(1 << 4)
#define ADI_PN23_TYPE			(1 << 1) /* !v8.0 */
#define ADI_ENABLE				(1 << 0)

#define ADI_REG_CHAN_STATUS(c)	(0x0404 + (c) * 0x40)
#define ADI_PN_ERR				(1 << 2)
#define ADI_PN_OOS				(1 << 1)
#define ADI_OVER_RANGE			(1 << 0)

#define ADI_REG_CHAN_CNTRL_1(c)		(0x0410 + (c) * 0x40)
#define ADI_DCFILT_OFFSET(x)		(((x) & 0xFFFF) << 16)
#define ADI_TO_DCFILT_OFFSET(x)		(((x) >> 16) & 0xFFFF)
#define ADI_DCFILT_COEFF(x)			(((x) & 0xFFFF) << 0)
#define ADI_TO_DCFILT_COEFF(x)		(((x) >> 0) & 0xFFFF)

#define ADI_REG_CHAN_CNTRL_2(c)		(0x0414 + (c) * 0x40)
#define ADI_IQCOR_COEFF_1(x)		(((x) & 0xFFFF) << 16)
#define ADI_TO_IQCOR_COEFF_1(x)		(((x) >> 16) & 0xFFFF)
#define ADI_IQCOR_COEFF_2(x)		(((x) & 0xFFFF) << 0)
#define ADI_TO_IQCOR_COEFF_2(x)		(((x) >> 0) & 0xFFFF)

#define PCORE_VERSION(major, minor, letter) ((major << 16) | (minor << 8) | letter)
#define PCORE_VERSION_MAJOR(version) (version >> 16)
#define PCORE_VERSION_MINOR(version) ((version >> 8) & 0xff)
#define PCORE_VERSION_LETTER(version) (version & 0xff)

#define ADI_REG_CHAN_CNTRL_3(c)		(0x0418 + (c) * 0x40) /* v8.0 */
#define ADI_ADC_PN_SEL(x)			(((x) & 0xF) << 16)
#define ADI_TO_ADC_PN_SEL(x)		(((x) >> 16) & 0xF)
#define ADI_ADC_DATA_SEL(x)			(((x) & 0xF) << 0)
#define ADI_TO_ADC_DATA_SEL(x)		(((x) >> 0) & 0xF)

/* PCORE Version > 8.00 */
#define ADI_REG_DELAY(l)			(0x0800 + (l) * 0x4)

#define SUCCESS		0
#define FAILURE		-1

#define	SPI_CPHA	0x01
#define	SPI_CPOL	0x02

#define	SPI_CS_DECODE	0x01

#define GPIO_OUT	0x01
#define GPIO_IN		0x00

#define GPIO_HIGH	0x01
#define GPIO_LOW	0x00

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

typedef enum i2c_type {
	XILINX_I2C
} i2c_type;

typedef struct i2c_init_param {
	enum i2c_type	type;
	uint32_t	id;
	uint32_t	max_speed_hz;
	uint8_t		slave_address;
} i2c_init_param;

typedef struct i2c_desc {
	enum i2c_type	type;
	uint32_t	id;
	uint32_t	max_speed_hz;
	uint8_t		slave_address;
} i2c_desc;

typedef enum spi_type {
	XILINX_SPI
} spi_type;

typedef enum spi_mode {
	SPI_MODE_0 = (0 | 0),
	SPI_MODE_1 = (0 | SPI_CPHA),
	SPI_MODE_2 = (SPI_CPOL | 0),
	SPI_MODE_3 = (SPI_CPOL | SPI_CPHA)
} spi_mode;

typedef struct spi_init_param {
	enum spi_type	type;
	uint32_t	id;
	uint32_t	max_speed_hz;
	enum spi_mode	mode;
	uint8_t		chip_select;
} spi_init_param;

typedef struct spi_desc {
	enum spi_type	type;
	uint32_t		id;
	uint32_t		max_speed_hz;
	enum spi_mode	mode;
	uint8_t			chip_select;
#ifdef _XPARAMETERS_PS_H_
	XSpiPs_Config	*config;
	XSpiPs			instance;
#else
	XSpi			instance;
#endif
} spi_desc;

typedef enum gpio_type {
	XILINX_GPIO
} gpio_type;

typedef struct gpio_desc {
	enum gpio_type	type;
	uint32_t		id;
	uint8_t			number;
#ifdef _XPARAMETERS_PS_H_
	XGpioPs_Config	*config;
	XGpioPs			instance;
#else
	XGpio			instance;
#endif
} gpio_desc;

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

/* Initialize the I2C communication peripheral. */
int32_t i2c_init(struct i2c_desc **desc,
		 const struct i2c_init_param *param);

/* Free the resources allocated by i2c_init(). */
int32_t i2c_remove(struct i2c_desc *desc);

/* Write data to a slave device. */
int32_t i2c_write(struct i2c_desc *desc,
		  uint8_t *data,
		  uint8_t bytes_number,
		  uint8_t stop_bit);

/* Read data from a slave device. */
int32_t i2c_read(struct i2c_desc *desc,
		 uint8_t *data,
		 uint8_t bytes_number,
		 uint8_t stop_bit);

/* Initialize the SPI communication peripheral. */
int32_t spi_init(struct spi_desc **desc,
		 const struct spi_init_param *param);

/* Free the resources allocated by spi_init() */
int32_t spi_remove(struct spi_desc *desc);

/* Write and read data to/from SPI. */
int32_t spi_write_and_read(struct spi_desc *desc,
			   uint8_t *data,
			   uint8_t bytes_number);

/* Obtain the GPIO decriptor. */
int32_t gpio_get(struct gpio_desc **desc,
		 uint8_t gpio_number);

/* Free the resources allocated by gpio_get() */
int32_t gpio_remove(struct gpio_desc *desc);

/* Enable the input direction of the specified GPIO. */
int32_t gpio_direction_input(struct gpio_desc *desc);

/* Enable the output direction of the specified GPIO. */
int32_t gpio_direction_output(struct gpio_desc *desc,
			      uint8_t value);

/* Get the direction of the specified GPIO. */
int32_t gpio_get_direction(struct gpio_desc *desc,
			   uint8_t *direction);

/* Set the value of the specified GPIO. */
int32_t gpio_set_value(struct gpio_desc *desc,
		       uint8_t value);

/* Get the value of the specified GPIO. */
int32_t gpio_get_value(struct gpio_desc *desc,
		       uint8_t *value);

/* Generate microseconds delay. */
void udelay(uint32_t usecs);

/* Generate miliseconds delay. */
void mdelay(uint32_t msecs);

#endif // PLATFORM_DRIVERS_H_
