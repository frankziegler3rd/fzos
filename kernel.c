
#include "console.h"
#include "keyboard.h"
#include "portmap.h"

#include <stdint.h>

void main() {

	clear_terminal();
	uint8_t byte;
	while (1) {
		while (byte = scan()) {
			print_character(charmap[byte]);
		}
	}
	print_string_with_color("HELLO", YELLOW, CYAN);
	print_line_with_color("World", MAGENTA, GREEN);	
	print_string("TODAY");
	return;
}
