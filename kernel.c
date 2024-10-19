void clear_terminal(char* VGA_BUFFER);

void main() {

	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "Hello World";
	
	clear_terminal(VGA_BUFFER);

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}

	return;
}

void clear_terminal(char* VGA_BUFFER) {
	
	for(int i = 0; i < 2000; i += 2) {
		VGA_BUFFER[i] = ' ';
		VGA_BUFFER[i+1] = 0x07;
	}
}
