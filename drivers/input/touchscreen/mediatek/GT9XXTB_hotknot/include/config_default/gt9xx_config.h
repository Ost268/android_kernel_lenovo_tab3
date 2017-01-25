/* drivers/input/touchscreen/gt1x_generic.h
 *
 * 2010 - 2014 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Version: 1.0
 * Revision Record:
 *      V1.0:  first release. 2014/09/28.
 *
 */

#ifndef _GT9XX_CONFIG_H_
#define _GT9XX_CONFIG_H_

//***************************PART2:TODO define**********************************
//STEP_1(REQUIRED):Change config table.
/*TODO: puts the config info corresponded to your TP here, the following is just
a sample config, send this config should cause the chip cannot work normally*/

/* from KK1.MP1 mt6582_evbp1
#define CTP_CFG_GROUP1 {\
0x41,0x00,0x03,0x00,0x04,0x0A,0x35,0x66,\
0x01,0x08,0x1E,0x05,0x50,0x3C,0x03,0x05,\
0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x17,\
0x19,0x1B,0x14,0x8C,0x2B,0x66,0x22,0x20,\
0xA0,0x0F,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x96,0x94,0x85,0x02,\
0x08,0x00,0x00,0x05,0x0D,0x21,0xA0,0x0F,\
0x22,0x99,0x12,0x24,0x8F,0x14,0x28,0xAC,\
0x17,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x0A,0x0A,0x03,0x07,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x04,0x05,0x06,0x07,0x08,0x09,\
0x0C,0x0D,0x0E,0x0F,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,\
0x00,0x00,0x00,0x00,0x00,0x00,0x25,0x24,\
0x23,0x22,0x21,0x20,0x1F,0x1E,0x1C,0x1B,\
0x19,0x00,0x02,0x04,0x06,0x07,0x08,0x0A,\
0x0C,0x0F,0x10,0x11,0x12,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x12,0x01,\
}
*/

//From K2DEV gt9xx_notknot
/*#define CTP_CFG_GROUP1 {\
0x41,0x20,0x03,0x00,0x05,0x05,0xF5,0x40,\
0x01,0x0A,0x1E,0x08,0x4B,0x37,0x0F,0x04,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,\
0x16,0x20,0x14,0x8D,0x2D,0xAA,0x64,0x66,\
0xD3,0x07,0x00,0x00,0x00,0x03,0x02,0x1D,\
0x32,0x01,0x00,0x0F,0x14,0x1E,0x01,0x00,\
0x00,0x01,0x0A,0x32,0x82,0x94,0xC5,0x02,\
0x08,0x00,0x00,0x04,0xB6,0x37,0x00,0xA1,\
0x42,0x00,0x90,0x50,0x00,0x81,0x62,0x00,\
0x76,0x76,0x00,0x76,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0xA9,0x01\
}*/

// O_film V66
#define CTP_CFG_GROUP1 {\
0x42,0x20,0x03,0x00,0x05,0x0A,0x05,0x40,\
0x01,0x08,0x28,0x08,0x55,0x3C,0x03,0x05,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x8D,0x2D,0xAA,0x50,0x52,\
0x0F,0x0A,0x0F,0x0A,0x00,0x22,0x33,0x1D,\
0x00,0x01,0x00,0x00,0x00,0x00,0x03,0x32,\
0x00,0x00,0x00,0x32,0x78,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x99,0x36,0x00,0x8B,\
0x41,0x00,0x81,0x4D,0x00,0x79,0x5C,0x00,\
0x74,0x6E,0x00,0x74,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x6F,0x03,0x14,0x50,0x32,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0xD2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x0A,0x00,0x00,0x1E,0x14,0x14,0x28,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0xC8,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x02,0x01\
}

// O_film V68
/*#define CTP_CFG_GROUP1 {\
0x44,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x08,0x28,0x08,0x55,0x3C,0x03,0x05,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x14,0x1D,0x14,0x8D,0x2D,0xAA,0x50,0x52,\
0x0F,0x0A,0x0F,0x0A,0x00,0x22,0x33,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x03,0x32,\
0x00,0x01,0x0A,0x32,0x78,0x94,0xD5,0x02,\
0x07,0x00,0x00,0x04,0x99,0x36,0x00,0x8B,\
0x41,0x00,0x81,0x4D,0x00,0x79,0x5C,0x00,\
0x74,0x6E,0x00,0x74,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x6F,0x2B,0x0A,0x4B,0x32,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0xC8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x0A,0x00,0x00,0x28,0x14,0x14,0x1E,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0xD2,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xF4,0x01\
}*/




//default config for K82

#define CTP_CFG_GROUP1_CHARGER {\
}

//TODO puts your group2 config info here,if need.
// MUDONG V80 support gesture
#define CTP_CFG_GROUP2 {\
0x50,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x09,0x1E,0x0B,0x50,0x32,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x40,0x22,0x08,0x14,\
0x14,0x21,0x14,0x8D,0x2D,0xAA,0x30,0x32,\
0xB8,0x08,0x85,0x0C,0x00,0x24,0x32,0x1D,\
0x5A,0x2D,0x00,0x47,0x17,0x19,0x19,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x04,0x00,0x00,0x04,0x97,0x26,0x00,0x86,\
0x2D,0x00,0x77,0x35,0x00,0x6C,0x3E,0x00,\
0x62,0x49,0x00,0x62,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x2C,0x05,0x32,0x19,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF1,0x02,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x14,0x1E,0x00,0x00,0x14,0x32,0x14,0x14,\
0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x14,\
0x1E,0x14,0x19,0x00,0x00,0x14,0x41,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xA3,0x01\
}
/*#define CTP_CFG_GROUP2 {\
0x4F,0x20,0x03,0x00,0x05,0x0A,0x35,0x70,\
0x01,0x09,0x1E,0x0B,0x50,0x32,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x40,0x22,0x08,0x14,\
0x14,0x21,0x14,0x8D,0x2D,0xAA,0x30,0x32,\
0xD3,0x07,0x85,0x0C,0x00,0x24,0x32,0x1D,\
0x5A,0x2D,0x00,0x47,0x17,0x19,0x19,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x04,0x00,0x00,0x04,0x97,0x26,0x00,0x86,\
0x2D,0x00,0x77,0x35,0x00,0x6C,0x3E,0x00,\
0x62,0x49,0x00,0x62,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x2C,0x05,0x32,0x19,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF1,0x02,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x14,0x1E,0x00,0x00,0x14,0x32,0x14,0x14,\
0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x14,\
0x1E,0x14,0x19,0x00,0x00,0x14,0x41,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x8C,0x46,0x74,0x01\
}*/
/*#define CTP_CFG_GROUP2 {\
0x4E,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x09,0x1E,0x0B,0x50,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x40,0x22,0x0B,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x30,0x32,\
0xB8,0x08,0x85,0x0C,0x00,0x24,0x32,0x1D,\
0x5A,0x2D,0x00,0x47,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x04,0x00,0x00,0x04,0x97,0x26,0x00,0x86,\
0x2D,0x00,0x77,0x35,0x00,0x6C,0x3E,0x00,\
0x62,0x49,0x00,0x62,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x2C,0x05,0x32,0x19,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF1,0x02,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x50,0x00,0x00,0x50,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0x54,0x01\
}*/
/*#define CTP_CFG_GROUP2 {\
0x4D,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x09,0x1E,0x0B,0x5A,0x46,0x0F,0x35,\
0x00,0x00,0x00,0x00,0x40,0x22,0x0B,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2A,0x2C,\
0xB8,0x08,0x85,0x0C,0x00,0x04,0x32,0x1D,\
0x5A,0x2D,0x00,0x47,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x07,0x00,0x00,0x04,0x8A,0x26,0x00,0x79,\
0x2D,0x00,0x6B,0x35,0x00,0x60,0x3E,0x00,\
0x56,0x49,0x00,0x56,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x24,0x05,0x32,0x1E,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF1,0x02,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x50,0x00,0x00,0x50,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0x7C,0x01\
}*/
/*#define CTP_CFG_GROUP2 {\
0x4B,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x60,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x26,0x28,\
0xB8,0x08,0x85,0x0C,0x00,0x04,0x32,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x24,0x05,0x28,0x14,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x50,0x00,0x00,0x50,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0x92,0x01\
}*/
/*#define CTP_CFG_GROUP2 {\
0x4A,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x60,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x04,0x32,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x2C,0x0F,0x3C,0x2D,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x50,0x00,0x00,0x50,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xCF,0x01\
}*/
/*#define CTP_CFG_GROUP2 {\
0x49,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x60,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x04,0x32,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x2C,0x0F,0x3C,0x2D,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x2A,0x29,0x01,0x00,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x50,0x00,0x00,0x50,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xD1,0x01\
}*/

// MUDONG V71 support gesture
/*#define CTP_CFG_GROUP2 {\
0x46,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x04,0x32,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x53,0x19,0x50,0x3C,0x23,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x50,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xF7,0x01\
}*/
// MUDONG V70
/*#define CTP_CFG_GROUP2 {\
0x46,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x00,0x00,0x00,0x04,0x02,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x50,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xE9,0x01\
}*/
// MUDONG V69
/*#define CTP_CFG_GROUP2 {\
0x45,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x00,0x00,0x00,0x04,0x02,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x32,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0x8C,0x26,0x00,0x7B,\
0x2D,0x00,0x6E,0x35,0x00,0x62,0x3E,0x00,\
0x59,0x49,0x00,0x59,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x50,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xB8,0x01\
}*/
/* MUDONG V68
#define CTP_CFG_GROUP2 {\
0x44,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x01,0x0A,0x28,0x0A,0x41,0x32,0x0F,0x05,\
0x01,0x01,0x00,0x00,0x0A,0x22,0x05,0x14,\
0x14,0x1C,0x14,0x8D,0x2D,0xAA,0x28,0x2A,\
0xA0,0x0B,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x78,0x01,0x00,0x55,0x00,0x0A,0x0A,0x00,\
0x00,0x01,0x0A,0x14,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0xDF,0x17,0x00,0xB5,\
0x1E,0x00,0x93,0x28,0x00,0x7B,0x35,0x00,\
0x6A,0x46,0x00,0x6A,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x78,0x00,0x28,0x00,\
0x00,0x00,0x96,0x00,0x96,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x4C,0x01\
}
*/
/* MUDONG V67
#define CTP_CFG_GROUP2 {\
0x43,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x01,0x0A,0x1E,0x0A,0x50,0x3C,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x16,\
0x17,0x1C,0x14,0x8D,0x2D,0xAA,0x32,0x34,\
0xA4,0x0B,0x00,0x00,0x01,0x03,0x03,0x1D,\
0x1E,0x01,0x00,0x55,0x00,0x0A,0x0A,0x32,\
0x00,0x01,0x0A,0x14,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0xDF,0x17,0x00,0xB5,\
0x1E,0x00,0x93,0x28,0x00,0x7B,0x35,0x00,\
0x6A,0x46,0x00,0x6A,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x1E,0x28,0x28,0x28,0x32,\
0x37,0x14,0x00,0x14,0x14,0x00,0x00,0x14,\
0x1E,0x37,0x46,0x6E,0x6E,0x55,0x4B,0x4B,\
0x4B,0x28,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x56,0x01	\
}
*/
/* MUDONG V66
#define CTP_CFG_GROUP2 {\
0x42,0x20,0x03,0x00,0x05,0x05,0x35,0x40,\
0x01,0x0A,0x1E,0x0A,0x50,0x3C,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x16,\
0x17,0x1C,0x14,0x8D,0x2D,0xAA,0x32,0x34,\
0xA4,0x0B,0x00,0x00,0x01,0x03,0x03,0x1D,\
0x1E,0x01,0x00,0x55,0x00,0x0A,0x0A,0x32,\
0x00,0x01,0x0A,0x14,0x50,0x94,0xC5,0x02,\
0x07,0x00,0x00,0x04,0xDF,0x17,0x00,0xB5,\
0x1E,0x00,0x93,0x28,0x00,0x7B,0x35,0x00,\
0x6A,0x46,0x00,0x6A,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x01,0x00,0x2A,0x29,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x1E,0x28,0x28,0x28,0x32,\
0x37,0x14,0x00,0x14,0x14,0x00,0x00,0x14,\
0x1E,0x37,0x46,0x6E,0x6E,0x55,0x4B,0x4B,\
0x4B,0x28,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x5C,0x01\
    }
*/
//TODO puts your group2 config info here,if need.
#define CTP_CFG_GROUP2_CHARGER {\
    }

//TODO puts your group3 config info here,if need.
#define CTP_CFG_GROUP3 {\
    }

//TODO puts your group3 config info here,if need.
#define CTP_CFG_GROUP3_CHARGER {\
    }

// TODO: define your config for Sensor_ID == 3 here, if needed
#define CTP_CFG_GROUP4 {\
    }

// TODO: define your config for Sensor_ID == 4 here, if needed
#define CTP_CFG_GROUP5 {\
    }

// TODO: define your config for Sensor_ID == 5 here, if needed
// AVC V87 support gesture
#define CTP_CFG_GROUP6 {\
0x57,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x50,0x03,0x08,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x85,0x0C,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x66,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x24,0x05,0x32,0x28,0x28,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x5A,0x00,0x00,0x00,0x00,0x00,0x00,0x28,\
0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,\
0x00,0x1E,0x00,0x00,0x5A,0x3C,0x00,0x00,\
0x00,0x50,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xDD,0x01\
}

/*#define CTP_CFG_GROUP6 {\
0x56,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x85,0x0C,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x66,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xC5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x24,0x05,0x32,0x28,0x28,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x64,0x00,0x00,0x00,0x28,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x5A,0x50,0x00,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0x2C,0x01\
    }*/

/*#define CTP_CFG_GROUP6 {\
0x55,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x14,0x00,0x0F,0x45,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x85,0x0C,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x66,0x00,0x00,0x00,0x1E,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x24,0x05,0x32,0x28,0x28,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x64,0x00,0x00,0x00,0x28,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x5A,0x50,0x00,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xAE,0x01\
    }*/

/*#define CTP_CFG_GROUP6 {\
0x52,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x02,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x55,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x66,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x3A,0x0F,0x3C,0x23,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x64,0x00,0x00,0x00,0x28,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x5A,0x50,0x00,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0x98,0x01\
    }*/

/*#define CTP_CFG_GROUP6 {\
0x51,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x02,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x55,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x3B,0x0F,0x3C,0x2D,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x64,0x00,0x00,0x00,0x28,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x5A,0x50,0x00,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xAD,0x01\
    }*/

/*#define CTP_CFG_GROUP6 {\
0x4F,0x20,0x03,0x00,0x05,0x0A,0x35,0x50,\
0x01,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x55,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x03,0x33,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x3B,0x0F,0x3C,0x2D,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x13,0x12,0x11,0x10,0x0F,0x0E,0x0D,0x0C,\
0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,\
0x03,0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0C,0x0B,\
0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,\
0x02,0x00,0x01,0x29,0x2A,0x28,0x27,0x26,\
0x25,0x24,0x23,0x22,0x21,0x20,0x1F,0x1E,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x64,0x00,0x00,0x00,0x28,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x32,0x5A,0x50,0x00,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xAF,0x01\
    }*/

// AVC V73 support gesture
/*#define CTP_CFG_GROUP6 {\
0x49,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x0F,0x0A,0x00,0x02,0x33,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,\
0x7F,0x52,0x19,0x46,0x28,0x23,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x00,0x50,0x5A,0x32,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x28,0x00,0x00,0x00,0x64,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0xCC,0x01\
    }*/
// AVC V72
/*#define CTP_CFG_GROUP6 {\
0x48,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x4B,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x51,0x03,0x05,0x14,\
0x16,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0xAC,0x26,0x00,0x96,\
0x2D,0x00,0x86,0x35,0x00,0x79,0x3E,0x00,\
0x6D,0x49,0x00,0x6D,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x78,0x00,0x00,0x00,0x50,0x5A,0x32,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x28,0x00,0x00,0x00,0x64,0x00,\
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0x96,0x3C,0x90,0x01\
    }*/
// AVC V71
/*#define CTP_CFG_GROUP6 {\
0x47,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x00,0x00,0x00,0x04,0x02,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x00,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0x8F,0x26,0x00,0x7D,\
0x2D,0x00,0x70,0x35,0x00,0x65,0x3E,0x00,\
0x5B,0x49,0x00,0x5B,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0x19,0x01\
    }*/
// AVC V70
/*#define CTP_CFG_GROUP6 {\
0x46,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x02,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x14,\
0x18,0x1D,0x14,0x8D,0x2D,0xAA,0x2B,0x2D,\
0xB8,0x08,0x00,0x00,0x00,0x04,0x02,0x1D,\
0x64,0x2D,0x00,0x47,0x00,0x32,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x50,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0x8F,0x26,0x00,0x7D,\
0x2D,0x00,0x70,0x35,0x00,0x65,0x3E,0x00,\
0x5B,0x49,0x00,0x5B,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x07,\
0xA0,0x3C,0xE8,0x01\
    }*/
// AVC V68
/*#define CTP_CFG_GROUP6 {\
0x44,0x20,0x03,0x00,0x05,0x0A,0x35,0x40,\
0x01,0x0A,0x1E,0x09,0x5A,0x41,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x53,0x01,0x00,0x14,\
0x18,0x22,0x14,0x8D,0x2D,0xAA,0x26,0x28,\
0xA4,0x0B,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x1E,0x21,0x00,0x55,0x00,0x14,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x55,0x94,0xD5,0x02,\
0x08,0x00,0x00,0x04,0x97,0x26,0x00,0x88,\
0x2D,0x00,0x7A,0x36,0x00,0x6F,0x41,0x00,\
0x66,0x4E,0x00,0x66,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x5B,0x01\
    }*/
/* AVC V67
#define CTP_CFG_GROUP6 {\
0x43,0x20,0x03,0x00,0x05,0x0A,0xF5,0x40,\
0x01,0x0A,0x1E,0x09,0x50,0x32,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x53,0x01,0x00,0x14,\
0x18,0x22,0x14,0x8D,0x2D,0xAA,0x26,0x28,\
0xA4,0x0B,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x1E,0x01,0x00,0x55,0x00,0x14,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x55,0x94,0xC5,0x02,\
0x08,0x00,0x00,0x04,0x97,0x26,0x00,0x88,\
0x2D,0x00,0x7A,0x36,0x00,0x6F,0x41,0x00,\
0x66,0x4E,0x00,0x66,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0xE5,0x01\
    }
*/
/* AVC V66
#define CTP_CFG_GROUP6 {\
0x42,0x20,0x03,0x00,0x05,0x05,0xF5,0x40,\
0x01,0x0A,0x1E,0x09,0x50,0x32,0x0F,0x05,\
0x00,0x00,0x00,0x00,0x53,0x01,0x00,0x14,\
0x18,0x22,0x14,0x8D,0x2D,0xAA,0x26,0x28,\
0xA4,0x0B,0x00,0x00,0x00,0x02,0x03,0x1D,\
0x1E,0x01,0x00,0x55,0x00,0x14,0x00,0x00,\
0x00,0x01,0x0A,0x23,0x55,0x94,0xC5,0x02,\
0x08,0x00,0x00,0x04,0x97,0x26,0x00,0x88,\
0x2D,0x00,0x7A,0x36,0x00,0x6F,0x41,0x00,\
0x66,0x4E,0x00,0x66,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,\
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
0x10,0x11,0x12,0x13,0xFF,0xFF,0xFF,0xFF,\
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1E,0x1F,\
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,\
0x28,0x29,0x2A,0x00,0x01,0x02,0x03,0x04,\
0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0xEB,0x01\
    }
*/

#endif /* _GT1X_CONFIG_H_ */