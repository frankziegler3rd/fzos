
#include "console.h"

void main() {

	clear_terminal();
	for(int i = 0; i<20; i++) {
		print_line("fuck");
	}
	clear_terminal();
	print_string("HELLO");
	print_line("WORLD");	
	print_string("TODAY");
	return;
}
