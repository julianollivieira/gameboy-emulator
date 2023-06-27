#include <stdio.h>

typedef struct CPU {
	int memory[0xFFFF];
	int registers[8];
} CPU;

int main() {
	// initialize the CPU
	CPU cpu = {
		.memory = {},
		.registers = {}
	};

	// read the rom file and store it in memory
	char rom[8096] = {};
	FILE* fptr = fopen("rom.bin", "rb");
	fread(rom, 1, 8096, fptr);
	fclose(fptr);

	// loop over rom and execute instructions

	// print the rom content
	printf("%s", rom);

	return 0;
}
