/*
 * bitmap_sample.h
 *
 *  Created on: 2018. 8. 3.
 *      Author: Jason
 */

#ifndef BITMAP_SAMPLE_H_
#define BITMAP_SAMPLE_H_

static const uint8_t title[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x60,
		0x30, 0x08, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x02, 0x06, 0x04,
		0x08, 0x58, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x86, 0x03, 0x00, 0x00,
		0x00, 0x80, 0x40, 0x80, 0xC0, 0x70, 0x18, 0x06, 0x00, 0x00, 0x80, 0x60, 0x20, 0x00, 0x00, 0x02,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x60, 0x64, 0x03, 0x00, 0x04, 0xF0,
		0xFE, 0xFE, 0xFF, 0xF3, 0xF8, 0x88, 0x84, 0x86, 0x80, 0x01, 0x41, 0x00, 0x00, 0x20, 0x30, 0x10,
		0x10, 0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x1C, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xFF, 0xFF, 0x18, 0x30, 0x20, 0x30, 0x38, 0x1C, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFE,
		0xFE, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x60, 0x70, 0x58, 0x6C, 0x6C,
		0x26, 0x22, 0x23, 0x21, 0xE1, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0xC0, 0x60,
		0x30, 0x18, 0x0C, 0x0C, 0x06, 0x06, 0xC2, 0xC0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xA0, 0xA0, 0xF0, 0x90, 0x88, 0x88, 0x88,
		0x84, 0x84, 0x8C, 0xFE, 0xEE, 0xEF, 0xEF, 0xAB, 0xEA, 0xA5, 0xE5, 0xE5, 0xCC, 0xE0, 0x20, 0x3F,
		0xFF, 0xFF, 0xFF, 0xF9, 0xFB, 0xC9, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x07,
		0x07, 0x04, 0x04, 0x04, 0x06, 0x06, 0x03, 0x03, 0x00, 0x00, 0x00, 0x02, 0x06, 0x04, 0x04, 0x04,
		0x04, 0x06, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x07, 0x07, 0x04,
		0x04, 0x06, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xFF, 0x7F, 0xC7, 0xFF, 0xFF, 0x50, 0x70, 0x61, 0x29,
		0x3D, 0x1D, 0x1D, 0x09, 0x79, 0x59, 0xF3, 0xF3, 0xF3, 0xC3, 0x03, 0x03, 0x07, 0x07, 0x00, 0x00,
		0x03, 0x0F, 0x8F, 0x0F, 0x0F, 0x08, 0x19, 0x31, 0x61, 0x41, 0x02, 0x02, 0x06, 0x04, 0x0C, 0x08,
		0x08, 0x10, 0x30, 0x20, 0x40, 0x00, 0x00, 0x80, 0x80, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00,
		0x00, 0xFC, 0xFC, 0x44, 0x44, 0x44, 0x44, 0x6C, 0x28, 0x20, 0x00, 0x00, 0xFE, 0xFE, 0x6C, 0x24,
		0x24, 0x24, 0x34, 0x14, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x30, 0x30, 0x60, 0xE0, 0xE9, 0xEF, 0xEF, 0xEF, 0xCC, 0xDC, 0xDE, 0xFE, 0xBE,
		0xBE, 0xBE, 0xBE, 0xBE, 0x3E, 0xBE, 0x3E, 0xBE, 0xBF, 0xBE, 0xBE, 0x9E, 0x9E, 0xDE, 0x8E, 0xCE,
		0xCC, 0x44, 0xE4, 0xE7, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3C, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x1F, 0x1F, 0x10, 0x10, 0x18, 0x08, 0x08, 0x0C, 0x04, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00,
		0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x08, 0x08,
		0x08, 0x08, 0x0C, 0x04, 0x04, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F, 0x6F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x9F, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00,
		0x00, 0x00, 0xFF, 0x7F, 0x7F, 0xF0, 0x81, 0x03, 0x02, 0x06, 0x04, 0x04, 0x00, 0x04, 0x04, 0x06,
		0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x06, 0x0E, 0x0E, 0x0F, 0x0D, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x6F, 0x7E, 0x7E,
		0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFD, 0xFC, 0x68, 0x7C, 0x74, 0x76, 0x7E, 0x3E, 0x3A,
		0x3A, 0x1E, 0x1F, 0x1D, 0x0D, 0x0F, 0x0F, 0x0F, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif /* BITMAP_SAMPLE_H_ */
