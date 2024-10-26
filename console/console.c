#include "console.h"

char* const VGA_BUFFER = (char*) 0xb8000;
static int term_pos = 0;

void clear_terminal() {	
       	
	int buff_size = VGA_WIDTH*VGA_HEIGHT*VGA_BYTES_PER_CHARACTER; 
	for(int i=0; i <= buff_size; i+=VGA_BYTES_PER_CHARACTER) {
                VGA_BUFFER[i] = ' ';
                VGA_BUFFER[i+1] = 0x07;
        }
	term_pos = 0;
}

void print_character(char c) {

	if (c == '\n') {
		term_pos += (VGA_WIDTH*VGA_BYTES_PER_CHARACTER - (term_pos%(VGA_WIDTH*VGA_BYTES_PER_CHARACTER)));
	}	
	else {
		VGA_BUFFER[term_pos] = c;
		VGA_BUFFER[term_pos+1] = 0x07;
		term_pos += VGA_BYTES_PER_CHARACTER;
	}
}

void print_string(char* str) {

	for(int i=0; str[i] != '\0'; i++) {
		print_character(str[i]);
	}	
}

void print_line(char* str) {
	
	print_string(str);
	print_character('\n');
}
