#include "../include/console.h"

char* const VGA_BUFFER = (char*) 0xb8000;
static int term_pos = 0;

void clear_terminal();

void print_character(char c);

void print_string(char* str);

void print_line(char* str);

void clear_terminal() {	
        
	for(int i=0; i < VGA_WIDTH*VGA_HEIGHT; i+=2) {
                VGA_BUFFER[i] = ' ';
                VGA_BUFFER[i+1] = 0x07;
        }
}

void print_character(char c) {

	if (c == '\n') {
		term_pos += (VGA_WIDTH*2 - (term_pos%(VGA_WIDTH*2)));
	}	
	else {
		VGA_BUFFER[term_pos] = c;
		VGA_BUFFER[term_pos+1] = 0x07;
		term_pos += 2;
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


