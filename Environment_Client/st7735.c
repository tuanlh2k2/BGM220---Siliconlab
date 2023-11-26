/*
 * st7735.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Luong Huu Tuan
 */

#include <st7735.h>
#include <st7735_spi.h>
#include <string.h>
#include "app_log.h"

// font 6 x 8.
const uint8_t my_font[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // space.
		////////////////////////////////////////////////// + 1
		0x70, 0x88, 0x98, 0xa8, 0xc8, 0x88, 0x70, 0x00,  // 0
		0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00,  // 1
		0x70, 0x88, 0x08, 0x70, 0x80, 0x80, 0xf8, 0x00,  // 2
		0xf8, 0x08, 0x10, 0x30, 0x08, 0x88, 0x70, 0x00,  // 3
		0x10, 0x30, 0x50, 0x90, 0xf8, 0x10, 0x10, 0x00,  // 4
		0xf8, 0x80, 0xf0, 0x08, 0x08, 0x88, 0x70, 0x00,  // 5
		0x38, 0x40, 0x80, 0xf0, 0x88, 0x88, 0x70, 0x00,  // 6
		0xf8, 0x08, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,  // 7
		0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00,  // 8
		0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0xe0, 0x00,  // 9
		/////////////////////////////////////////////////// + 11
		0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x00,   //A
		0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0xf0, 0x00,  // B
		0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00,  // C
		0xf0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x00,  // D
		0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x00,  // E
		0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x00,  // F
		0x78, 0x88, 0x80, 0x80, 0x98, 0x88, 0x78, 0x00,  // G
		0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00,  // H
		0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00,  // I
		0x38, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, 0x00,  // J
		0x88, 0x90, 0xa0, 0xc0, 0xa0, 0x90, 0x88, 0x00,  // K
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x00,  // L
		0x88, 0xd8, 0xa8, 0xa8, 0xa8, 0x88, 0x88, 0x00,  // M
		0x88, 0x88, 0xc8, 0xa8, 0x98, 0x88, 0x88, 0x00,  // N
		0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,  // O
		0xf0, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x00,  // P
		0x70, 0x88, 0x88, 0x88, 0xa8, 0x90, 0x68, 0x00,  // Q
		0xf0, 0x88, 0x88, 0xf0, 0xa0, 0x90, 0x88, 0x00,  // R
		0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00,  // S
		0xf8, 0xa8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,  // T
		0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,  // U
		0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00,  // V
		0x88, 0x88, 0x88, 0xa8, 0xa8, 0xa8, 0x50, 0x00,  // W
		0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00,  // X
		0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x20, 0x00,  // Y
		0xf8, 0x08, 0x10, 0x70, 0x40, 0x80, 0xf8, 0x00,  // Z
		// Ky tu dac biet				 + 	37
		0xC0, 0xDC, 0x22, 0x20, 0x20, 0x22, 0x1C, 0x00, // *C.
		0xC2, 0xC4, 0x08, 0x10, 0x20, 0x46, 0x86, 0x00,  // %
		0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x00, 0x00,  // :
		0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, // .
		0xFF, 0x40, 0x80, 0x80, 0x80, 0x80,  0x40, 0xFF, // nửa bên phải của on/ off
		0xFF, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0xFF,  // nửa bên trái.
		0x3C, 0x24, 0x66, 0x42, 0x81, 0xFF, 0x00, 0x18,  // hình trái chuông.
		0x06, 0x01, 0xFF, 0x81, 0x86, 0x80, 0x80, 0x80,  // vẽ biểu tượng inicate.

};

void st7735_set_window(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
	st7735_send_command(0x2A);
	st7735_send_data(0x00, 1);
	st7735_send_data(x + 0, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data((x + w), 1);

	st7735_send_command(0x2B);
	st7735_send_data(0x00, 1);
	st7735_send_data(y + 0, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data((y + h) + 0, 1);

	st7735_send_command(0x2C);
}

void st7735_clear(void)
{
	st7735_set_window(0, 0, 160, 128);
	for(unsigned int i = 0; i < (160 * (128)); i++)
	{
		st7735_send_data(0, 1);
		st7735_send_data(0, 1);
	}
}

void st7735_draw(uint16_t color)
{
	st7735_send_data(color >>8 , 1);
	st7735_send_data(color, 1);
}
void st7735_draw_pixel(int16_t x,int16_t y,uint16_t color)
{
	if(x<0)return;
	if(y<0)return;
	//if(x>=DEVICER_MAX_W) return;
	//if(y>=DEVICER_MAX_H) return;
	st7735_set_window(x,y,1,1);
	st7735_draw(color);
}

sl_status_t st7735_init(void)
{
	sl_status_t sc;

	st7735_spi_init();
	//sc = ssd1306_send_command(ptr, sizeof(cmd_buff));
	st7735_send_command(0x01); //Software Reset
	sl_sleeptimer_delay_millisecond(5);
	st7735_send_command(0x11); //exit  Sleep
	sl_sleeptimer_delay_millisecond(5);


	st7735_send_command(0xB1);  //Frame Rate Control (In normal mode/ Full colors)
	st7735_send_data(0x01, 1);
	st7735_send_data(0x2C, 1);
	st7735_send_data(0x2D, 1);


	st7735_send_command(0xB2);  //Frame Rate Control (In Idle mode/ 8-colors)
	st7735_send_data(0x01, 1);
	st7735_send_data(0x2C, 1);
	st7735_send_data(0x2D, 1);


	st7735_send_command(0xB3);  //Frame Rate Control (In Partial mode/ full colors)
	st7735_send_data(0x01, 1);
	st7735_send_data(0x2C, 1);
	st7735_send_data(0x2D, 1);
	st7735_send_data(0x01, 1);
	st7735_send_data(0x2C, 1);
	st7735_send_data(0x2D, 1);


	st7735_send_command(0xB4);  //Display Inversion Control
	st7735_send_data(0x07, 1);


	st7735_send_command(0xC0);  //Power Control 1
	st7735_send_data(0xA2, 1);
	st7735_send_data(0x02, 1);
	st7735_send_data(0x84, 1);


	st7735_send_command(0xC1); //Power Control 2
	st7735_send_data(0xC5, 1);


	st7735_send_command(0xC2);  //Power Control 3 (in Normal mode/ Full colors)
	st7735_send_data(0x0A, 1);
	st7735_send_data(0x00, 1);


	st7735_send_command(0xC3);  //Power Control 4 (in Idle mode/ 8-colors)
	st7735_send_data(0x8A, 1);
	st7735_send_data(0x2A, 1);


	st7735_send_command(0xC4);  //Power Control 5 (in Partial mode/ full-colors)
	st7735_send_data(0x8A, 1);
	st7735_send_data(0xEE, 1);


	st7735_send_command(0xC5);  //VCOM Control 1
	st7735_send_data(0x0E, 1);


	st7735_send_command(0x20);  //Display Inversion Off


	st7735_send_command(0x36);  //Memory Data Access Control
	st7735_send_data(0xA0, 1); //RGB mode + che do man hinh ngang


	st7735_send_command(0x3A); //Interface Pixel Format
	st7735_send_data(0x05, 1); //16-bit/pixel


	st7735_send_command(0x2A); //Column address set
	st7735_send_data(0x00, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(160, 1);


	st7735_send_command(0x2B); //Row address set
	st7735_send_data(0x00, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(128, 1);


	st7735_send_command(0xE0); //Gamm adjustment (+ polarity)
	st7735_send_data(0x02, 1);
	st7735_send_data(0x1C, 1);
	st7735_send_data(0x07, 1);
	st7735_send_data(0x12, 1);
	st7735_send_data(0x37, 1);
	st7735_send_data(0x32, 1);
	st7735_send_data(0x29, 1);
	st7735_send_data(0x2D, 1);
	st7735_send_data(0x29, 1);
	st7735_send_data(0x25, 1);
	st7735_send_data(0x2B, 1);
	st7735_send_data(0x39, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(0x01, 1);
	st7735_send_data(0x03, 1);
	st7735_send_data(0x10, 1);


	st7735_send_command(0xE1);  //Gamma adjustment(- polarity)
	st7735_send_data(0x03, 1);
	st7735_send_data(0x1D, 1);
	st7735_send_data(0x07, 1);
	st7735_send_data(0x06, 1);
	st7735_send_data(0x2E, 1);
	st7735_send_data(0x2C, 1);
	st7735_send_data(0x29, 1);
	st7735_send_data(0x2D, 1);
	st7735_send_data(0x2E, 1);
	st7735_send_data(0x2E, 1);
	st7735_send_data(0x37, 1);
	st7735_send_data(0x3F, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(0x00, 1);
	st7735_send_data(0x02, 1);
	st7735_send_data(0x10, 1);

	st7735_send_command(0x13); //Partial off (Normal)

	sc = st7735_send_command(0x29); //Display on
	st7735_clear();  // clear screen.
	st7735_set_window(0, 0, 160, 128); // set screen.
	return sc;
}

void draw_character(int coordinate_x, int coordinate_y, char data, uint16_t text_color, uint16_t background_color)
{
	// find code data.
	uint8_t offset = 0;
	if (data >= 'A') {
		offset = (data) - 'A' + 11;
	} else if(data >= '0' && data <= '9'){
		offset = (data) - '0' + 1;
	} else if (data == ' ') {
		offset = 0;
	} else if (data == '%') {
		offset = 38;
	} else if (data == '?') {
		offset = 37;
	} else if (data == ':') {
		offset = 39;
	} else if (data == '.') {
		offset = 40;
	} else if (data == '&') { // nửa kí tự bên phải on/off.
		offset = 41;
	} else if (data == '@') { // nữa bên trái on/off.
		offset = 42;
	} else if (data == "a") { // hình trái chuông.
		offset = 43;
	} else if (data == "b") {
		offset = 44;
	}

	// draw.
	for (int i = 0; i < 8; i++) {
		uint16_t pixelData = my_font[i + offset * 8];
		// Duyệt qua từng cột pixel trong font chữ 6x8
		for (int j = 0; j < 8; j++) {
			// Kiểm tra nếu bit tại vị trí j của pixelData bằng 1 (pixel bật)
			if ((pixelData >> (7 - j)) & 0x01) {
				// Vẽ pixel bật tại tọa độ (x + j, y + i) với màu của bạn (ví dụ: 0xFFFF - màu trắng)
				st7735_draw_pixel(coordinate_x + j, coordinate_y + i, text_color);
			}
			// Nếu bit tại vị trí j của pixelData bằng 0 (pixel tắt)
			else {
				// Vẽ pixel tắt tại tọa độ (x + j, y + i) với màu của bạn (ví dụ: 0x0000 - màu đen)
				st7735_draw_pixel(coordinate_x + j, coordinate_y + i, background_color);
			}
		}
	}
}

void draw_string(int coordinate_x, int coordinate_y, const char* str, uint16_t text_color, uint16_t background_color)
{
	uint8_t x = coordinate_x;
	while (*str) {
		draw_character(x, coordinate_y, *str, text_color, background_color);

		/* Adjust x and y coordinate */
		x += 8;

		// Next char
		str++;
	}
}

/**
 * This is the main display of the program.
 */
void displays_init()
{
	draw_string(0, 1, "STATUS", RED, BLACK);
	draw_string(64, 1, "SCANNING ...", RED, BLACK);
	draw_string(0, 15, "DEVICE 1", YELLOW, BLACK);
	// Vẽ turn off khi khởi động.
	draw_string(104, 15, "&", YELLOW, RED);
	draw_string(112, 15, "@", YELLOW, BLACK);
	// vẽ biểu tượng indicate.
	draw_string(128, 15, "b", RED, BLACK);

	// vẽ biểu tượng quả chuông.
	draw_string(144, 15, "a", RED, BLACK);
	//
	draw_string(8, 30, "HUMI  INV%", WHITE, BLACK);
	draw_string(8, 45, "TEMP  INV?", WHITE, BLACK);
	draw_string(8, 60, "LIGHT INV LUX", WHITE, BLACK);

	draw_string(0, 75, "DEVICE 2", YELLOW, BLACK);
	// Vẽ turn off khi khởi động.
	draw_string(104, 75, "&", YELLOW, RED);
	draw_string(112, 75, "@", YELLOW, BLACK);

	// vẽ biểu tượng indicate.
	draw_string(128, 75, "b", RED, BLACK);

	// vẽ biểu tượng quả chuông.
	draw_string(144, 75, "a", RED, BLACK);
	//

	draw_string(8, 90, "HUMI  INV%", WHITE, BLACK);
	draw_string(8, 105, "TEMP  INV?", WHITE, BLACK);
	draw_string(8, 120, "LIGHT INV LUX", WHITE, BLACK);
}

char* convert_to_string(uint16_t x)
{
	int num_digits = 1;
	int temp = x;

	// Determine the number of digits in the integer
	while (temp /= 10)
		num_digits++;

	// Allocate memory for the string
	char* str_s = (char*)malloc((num_digits + 1) * sizeof(char)); // +1 for the null terminator

	// Convert the integer to a string
	for (int i = num_digits - 1; i >= 0; i--) {
		str_s[i] = (x % 10) + '0';
		x /= 10;
	}
	str_s[num_digits] = '\0';
	return str_s;
}

char *update_value(uint16_t integer, uint8_t decimal)
{
	char* str_integer = convert_to_string(integer);
	char* str_decimal = convert_to_string(decimal);
	char dot[] = ".";

	// Calculate the total length of the combined string
	int total_length = strlen(str_integer) + strlen(str_decimal) + strlen(dot) + 2; // +1 for the null terminator.

	// Allocate memory for the combined string
	char* combined_str = (char*)malloc(total_length * sizeof(char));

	// Copy the first part (the original string) to the combined string
	strcpy(combined_str, str_integer);

	// Add the dot in the middle
	strcat(combined_str, dot);

	// Add the second part (the "125" string) after the dot
	strcat(combined_str, str_decimal);
	return combined_str;
}

/**
    This function is responsible for converting the original light intensity data
    consisting of 8 high data bits and 8 low data bits to a decimal number with 1 comma.
 */
char *convert_light_intensity_to_string(uint8_t light_hight, uint8_t light_low)
{
	float value = (uint16_t) (light_hight << 8 | light_low) * 1.0 / 1.2;
	int value_x = lround(value * 100);
	return update_value(value_x/100, value_x % 100);
}
