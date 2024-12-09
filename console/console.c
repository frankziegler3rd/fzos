#include "console.h"
#include "keyboard.h"
#include "portmap.h"

char* const VGA_BUFFER = (char*) 0xb8000;
static int term_pos = 0;
static VGA_Color terminal_font_color = LIGHT_GRAY;
static VGA_Color terminal_background_color = BLACK;
static int buff_size = VGA_WIDTH*VGA_HEIGHT*VGA_BYTES_PER_CHARACTER;

void set_terminal_font_color(VGA_Color col) {
	terminal_font_color = col;
}

void set_terminal_background_color(VGA_Color col) {
	terminal_background_color = col;
}

void clear_terminal() {	
       	
	for(int i=0; i <= buff_size; i+=VGA_BYTES_PER_CHARACTER) {
                VGA_BUFFER[i] = '\0';
                VGA_BUFFER[i+1] = 0x07;
        }
	term_pos = 0;
}

void print_character(char c) {
	
	print_character_with_color(c, terminal_background_color, terminal_font_color);
}

void print_string(char* str) {

	print_string_with_color(str, terminal_background_color, terminal_font_color);
}	

void print_line(char* str) {

	print_line_with_color(str, terminal_background_color, terminal_font_color);
}

void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color) {

	if (c == '\n') {
		term_pos += (VGA_WIDTH*VGA_BYTES_PER_CHARACTER - (term_pos%(VGA_WIDTH*VGA_BYTES_PER_CHARACTER)));
	}	
	else {
		VGA_BUFFER[term_pos] = c;
		VGA_BUFFER[term_pos+1] = (bg_color << 4) | font_color;
		term_pos += VGA_BYTES_PER_CHARACTER;
	}
}

void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {
	
	for (int i = 0; str[i] != '\0'; i++) {
		print_character_with_color(str[i], bg_color, font_color);
	}
}

void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {

	print_string_with_color(str, bg_color, font_color);
	print_character_with_color('\n', bg_color, font_color);
}

void update_cursor() {
	
	uint16_t cursor_position = term_pos >> 1;
	outb(0x3D4, 0X0F);
	outb(0x3D5, (uint8_t) (cursor_position));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) (cursor_position >> 8));
}
