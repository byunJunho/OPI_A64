/*
 *
 * This file is part of pyA20.
 * mapping.h is python GPIO extension.
 *
 * Copyright (c) 2014 Stefan Mavrodiev @ OLIMEX LTD, <support@olimex.com>
 *
 * pyA20 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef __MAPPING_H
#define __MAPPING_H

#include "gpio_lib.h"

/**
Structure that describe all gpio
*/
typedef struct _pin {
    char name[10];          // The processor pin
    int offset;             // Memory offset for the pin
    int pin_number;         // Number on the connector
}pin_t;

typedef struct _gpio {
    char connector_name[10];
    pin_t pins[41];
}gpio_t;


gpio_t gpio[] = {
	{"gpio1",
        {
            {   "IO2",   SUNXI_GPH(3),    3  },	// I2C SDA
            {   "IO3",   SUNXI_GPH(2),    5  },	// I2C SCL
            {   "IO4",   SUNXI_GPL(10),   7  }, // PWM       
            {   "IO17",  SUNXI_GPH(5),   11  },
            {   "IO27",  SUNXI_GPH(4),   13  },
            {   "IO22",  SUNXI_GPH(7),   15  },
            {   "IO10",  SUNXI_GPD(2),   19  },	// SPI MOSI
			{   "IO9",   SUNXI_GPD(3),   21  },	// SPI MISO
            {   "IO11",  SUNXI_GPD(1),   23  },	// SPI CLK
            {   "IO31",  SUNXI_GPE(15),  27  },
            {   "IO5",   SUNXI_GPB(4),   29  },
            {   "IO6",   SUNXI_GPB(5),   31  },
            {   "IO13",  SUNXI_GPB(6),   33  },
            {   "IO19",  SUNXI_GPB(7),   35  },
            {   "IO26",  SUNXI_GPD(5),   37  },
            {   "IO14",  SUNXI_GPL(2),    8  },	// UART TX
            {   "IO15",  SUNXI_GPL(3),   10  },	// UART RX
            {   "IO18",  SUNXI_GPD(4),   12  },
            {   "IO23",  SUNXI_GPL(9),   16  },
            {   "IO24",  SUNXI_GPC(4),   18  },
            {   "IO25",  SUNXI_GPH(6),   22  },
            {   "IO8",   SUNXI_GPD(0),   24  },	// SPI CSO
            {   "IO7",   SUNXI_GPD(6),   26  },
            {   "IO32",  SUNXI_GPE(14),  28  },
            {   "IO12",  SUNXI_GPB(2),   32  },
            {   "IO16",  SUNXI_GPB(3),   36  },
            {   "IO20",  SUNXI_GPB(0),   38  },
            {   "IO21",  SUNXI_GPB(1),   40  },
            {
                {   0,  0,  0}
            },
        }
    },
	{"LED",
        {
            {   "STATUS_LED",  SUNXI_GPH(11),  2 },
            {
                {   0,  0,  0}
            },
        }
    },
};
#endif
