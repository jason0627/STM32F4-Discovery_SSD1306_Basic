#include "ssd1306.h"
#include "stm32f4xx_hal_spi.h"
#include <stdio.h>
#include <string.h>

extern SPI_HandleTypeDef hspi2;
static uint8_t ssd1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];   // Screenbuffer
static SSD1306_t ssd1306;          // Screen object

void ssd1306_WriteCommand(uint8_t byte)         // Send a byte to the command register
{
    HAL_GPIO_WritePin(ssd1306_DC_GPIO_Port, ssd1306_DC_Pin, GPIO_PIN_RESET); // command
    HAL_SPI_Transmit(&hspi2, (uint8_t *) &byte, 1, 1);
}

void ssd1306_WriteData(uint8_t* buffer, size_t buff_size)    // Send data
{
    HAL_GPIO_WritePin(ssd1306_DC_GPIO_Port, ssd1306_DC_Pin, GPIO_PIN_SET); // data
    HAL_SPI_Transmit(&hspi2, buffer, buff_size, 1);
}

void ssd1306_Init(void)    // Initialize the oled screen
{
	HAL_GPIO_WritePin(ssd1306_RST_GPIO_Port, ssd1306_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(ssd1306_RST_GPIO_Port, ssd1306_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	ssd1306_WriteCommand(0xAE); //display off
	ssd1306_WriteCommand(0x20); //Set Memory Addressing Mode
	ssd1306_WriteCommand(0x02); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	ssd1306_WriteCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
	ssd1306_WriteCommand(0xC8); //Set COM Output Scan Direction         should be C0
	ssd1306_WriteCommand(0x00); //---set low column address
	ssd1306_WriteCommand(0x10); //---set high column address
	ssd1306_WriteCommand(0x40); //--set start line address
	ssd1306_WriteCommand(0x81); //--set contrast control register
	ssd1306_WriteCommand(0xFF);
	ssd1306_WriteCommand(0xA1); //--set segment re-map 0 to 127         should be A0
	ssd1306_WriteCommand(0xA6); //--set normal display
	ssd1306_WriteCommand(0xA8); //--set multiplex ratio(1 to 64)
	ssd1306_WriteCommand(0x3F); //
	ssd1306_WriteCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	ssd1306_WriteCommand(0xD3); //-set display offset
	ssd1306_WriteCommand(0x00); //-not offset
	ssd1306_WriteCommand(0xD5); //--set display clock divide ratio/oscillator frequency
	ssd1306_WriteCommand(0xF0); //--set divide ratio
	ssd1306_WriteCommand(0xD9); //--set pre-charge period
	ssd1306_WriteCommand(0x22); //
	ssd1306_WriteCommand(0xDA); //--set com pins hardware configuration
	ssd1306_WriteCommand(0x12);

	ssd1306_WriteCommand(0xDB); //--set vcomh
	ssd1306_WriteCommand(0x20); //0x20,0.77xVcc
	ssd1306_WriteCommand(0x8D); //--set DC-DC enable
	ssd1306_WriteCommand(0x14); //
	ssd1306_WriteCommand(0xAF); //--turn on ssd1306 panel
    // Clear screen
    ssd1306_Fill(Black);
    
    // Flush buffer to screen
    ssd1306_UpdateScreen();
    
    // Set default values for screen object
//    ssd1306.CurrentX = 0;
//    ssd1306.CurrentY = 0;
    
    ssd1306.Initialized = 1;
}

void ssd1306_Fill(SSD1306_COLOR color)
{
  uint32_t i;

  for(i = 0; i < sizeof(ssd1306_Buffer); i++)
  {
    ssd1306_Buffer[i] = (color == Black) ? 0x00 : 0xFF;
  }
  ssd1306_UpdateScreen();
}

// Write the screenbuffer with changed to the screen
void ssd1306_UpdateScreen(void)
{
    uint8_t i;
    for(i = 0; i < 8; i++)
    {
        ssd1306_WriteCommand(0xB0 + i);
        ssd1306_WriteCommand(0x00);
        ssd1306_WriteCommand(0x10);
        ssd1306_WriteData(&ssd1306_Buffer[SSD1306_WIDTH*i],SSD1306_WIDTH);
    }
}

//    Draw one pixel in the screenbuffer
//    X => X Coordinate
//    Y => Y Coordinate
//    color => Pixel color
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color) {
    if(x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        // Don't write outside the buffer
        return;
    }
    
    // Check if pixel should be inverted
    if(ssd1306.Inverted) {
        color = (SSD1306_COLOR)!color;
    }
    
    // Draw in the right color
    if(color == White) {
        ssd1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
    } else { 
        ssd1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }
}

// Draw 1 char to the screen buffer
// ch         => char om weg te schrijven
// Font     => Font waarmee we gaan schrijven
// color     => Black or White
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color) {
    uint32_t i, b, j;
    
    // Check remaining space on current line
    if (SSD1306_WIDTH <= (ssd1306.CurrentX + Font.FontWidth) ||
        SSD1306_HEIGHT <= (ssd1306.CurrentY + Font.FontHeight))
    {
        // Not enough space on current line
        return 0;
    }
    
    // Use the font to write
    for(i = 0; i < Font.FontHeight; i++) {
        b = Font.data[(ch - 32) * Font.FontHeight + i];
        for(j = 0; j < Font.FontWidth; j++) {
            if((b << j) & 0x8000)  {
                ssd1306_DrawPixel(ssd1306.CurrentX + j, (ssd1306.CurrentY + i), (SSD1306_COLOR) color);
            } else {
                ssd1306_DrawPixel(ssd1306.CurrentX + j, (ssd1306.CurrentY + i), (SSD1306_COLOR)!color);
            }
        }
    }
    
    // The current space is now taken
    ssd1306.CurrentX += Font.FontWidth;
    
    // Return written char for validation
    return ch;
}

// Write full string to screenbuffer
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color)
{
    // Write until null-byte
    while (*str) {
        if (ssd1306_WriteChar(*str, Font, color) != *str) {
            // Char could not be written
            return *str;
        }
        
        // Next char
        str++;
    }
    
    // Everything ok
    return *str;
}

// Position the cursor
void ssd1306_SetCursor(uint8_t x, uint8_t y) {
    ssd1306.CurrentX = x;
    ssd1306.CurrentY = y;
}

void ssd1306_DrawBitmap(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, const uint8_t* pBMP)
{
    uint8_t pX;
    uint8_t pY;
    uint8_t tmpCh;
    uint8_t bL;

    pY = Y;
    while (pY < Y + H)
    {
	pX = X;
	while (pX < X + W)
	{
	    bL = 0;
	    tmpCh = *pBMP++;
	    if (tmpCh)
	    {
		while (bL < 8)
		{
		    if (tmpCh & 0x01) ssd1306_DrawPixel(pX, pY+bL, White); // LCD_PixelMode
		    tmpCh >>= 1;
		    if (tmpCh) 	bL++;
		    else
		    {
			pX++;
			break;
		    }
		}
	    }
	    else pX++;
	 }
	 pY += 8;
     }
}


