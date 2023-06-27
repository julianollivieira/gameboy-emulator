#include <stdio.h>
#include "gameboy.h"

// registers (8-bit)
u8 R_A;
u8 R_B;
u8 R_C;
u8 R_D;
u8 R_E;
u8 R_H;
u8 R_L;

// registers (16-bit)
u16 SP;
u16 PC;

#define R_BC (R_B << 8) | R_C
#define R_DE (R_D << 8) | R_E
#define R_HL (R_H << 8) | R_L

// flag bits (zero, subtraction, half carry, carry)
u8 R_Z;
u8 R_N;
u8 R_H;
u8 R_C;

// memory
u8 RAM[0xFFFF];

// cpu
u8 OP;

int main() {
	// read rom file and loop over it to print instructions
	char rom[8096] = {};
	FILE* fptr = fopen("cpu_instrs.gb", "rb");
	fread(rom, 1, 8096, fptr);
	fclose(fptr);

	// loop over rom and execute instructions
	for(;;) {
		OP = rom[PC++];
		switch (OP) {
			// 8-bit load instructions
			case 0x02:
				printf("LD (BC),A");
				RAM[R_BC] = R_A;
				break;
			case 0x12:
				printf("LD (DE),A");
				RAM[R_DE] = R_A;
				break;
			case 0x22:
				printf("LD (HL+),A");
				// TODO: RAM[R_HL] = R_A;
				break;
			case 0x32: 
				printf("LD (HL-),A");
				// TODO: RAM[R_HL] = R_A;
				break;
			case 0x06:
				// printf("LD B,%02X", rom[PC++]);
				// TODO: R_B = rom[PC++];
				break;
			case 0x16:
				// TODO: printf("LD D,%02X", rom[PC++]);
				break;
			case 0x26:
				// TODO: printf("LD H,%02X", rom[PC++]);
				break;
			case 0x36:
				// TODO: printf("LD (HL),%02X", rom[PC++]);
				break;
			case 0x0A:
				printf("LD A,(BC)");
				R_A = RAM[R_BC];
				break;
			case 0x1A:
				printf("LD A,(DE)");
				R_A = RAM[R_DE];
				break;
			case 0x2A:
				printf("LD A,(HL+)");
				// TODO: R_A = RAM[R_HL];
				break;
			case 0x3A:
				printf("LD A,(HL-)");
				// TODO: R_A = RAM[R_HL];
				 break;
			case 0x0E:
				// printf("LD C,%02X", rom[PC++]);
				// TODO: R_C = rom[PC++];
				break;
			case 0x1E:
				// printf("LD E,%02X", rom[PC++]);
				// TODO: R_E = rom[PC++];
				break;
			case 0x2E:
				// printf("LD L,%02X", rom[PC++]);
				// TODO: R_L = rom[PC++];
				break;
			case 0x3E:
				// printf("LD A,%02X", rom[PC++]);
				// TODO: R_A = rom[PC++];
				break;
			case 0x40:
				printf("LD B,B");
				break;
			case 0x41:
				printf("LD B,C");
				R_B = R_C;
				break;
			case 0x42:
				printf("LD B,D");
				R_B = R_D;
				break;
			case 0x43:
				printf("LD B,E");
				R_B = R_E;
				break;
			case 0x44:
				printf("LD B,H");
				R_B = R_H;
				break;
			case 0x45:
				printf("LD B,L");
				R_B = R_L;
				break;
			case 0x46:
				printf("LD B,(HL)");
				R_B = RAM[R_HL];
				break;
			case 0x47:
				printf("LD B,A");
				R_B = R_A;
				break;
			case 0x48:
				printf("LD C,B");
				R_C = R_B;
				break;
			case 0x49:
				break;
			case 0x4A:
				printf("LD C,D");
				R_C = R_D;
				break;
			case 0x4B:
				printf("LD C,E");
				R_C = R_E;
				break;
			case 0x4C:
				printf("LD C,H");
				R_C = R_H;
				break;
			case 0x4D:
				printf("LD C,L");
				R_C = R_L;
				break;
			case 0x4E:
				printf("LD C,(HL)");
				R_C = RAM[R_HL];
				break;
			case 0x4F:
				printf("LD C,A");
				R_C = R_A;
				break;
			case 0x50:
				printf("LD D,B");
				R_D = R_B;
				break;
			case 0x51:
				printf("LD D,C");
				R_D = R_C;
				break;
			case 0x52:
				printf("LD D,D");
				break;
			case 0x53:
				printf("LD D,E");
				R_D = R_E;
				break;
			case 0x54:
				printf("LD D,H");
				R_D = R_H;
				break;
			case 0x55:
				printf("LD D,L");
				R_D = R_L;
				break;
			case 0x56:
				printf("LD D,(HL)");
				R_D = RAM[R_HL];
				break;
			case 0x57:
				printf("LD D,A");
				R_D = R_A;
				break;
			case 0x58:
				printf("LD E,B");
				R_E = R_B;
				break;
			case 0x59:
				printf("LD E,C");
				R_E = R_C;
				break;
			case 0x5A:
				printf("LD E,D");
				R_E = R_D;
				break;
			case 0x5B:
				printf("LD E,E");
				break;
			case 0x5C:
				printf("LD E,H");
				R_E = R_H;
				break;
			case 0x5D:
				printf("LD E,L");
				R_E = R_L;
				break;
			case 0x5E:
				printf("LD E,(HL)");
				R_E = RAM[R_HL];
				break;
			case 0x5F:
				printf("LD E,A");
				R_E = R_A;
				break;
			case 0x60:
				printf("LD H,B");
				R_H = R_B;
				break;
			case 0x61:
				printf("LD H,C");
				R_H = R_C;
				break;
			case 0x62:
				printf("LD H,D");
				R_H = R_D;
				break;
			case 0x63:
				printf("LD H,E");
				R_H = R_E;
				break;
			case 0x64:
				printf("LD H,H");
				break;
			case 0x65:
				printf("LD H,L");
				R_H = R_L;
				break;
			case 0x66:
				printf("LD H,(HL)");
				R_H = RAM[R_HL];
				break;
			case 0x67:
				printf("LD H,A");
				R_H = R_A;
				break;
			case 0x68:
				printf("LD L,B");
				R_L = R_B;
				break;
			case 0x69:
				printf("LD L,C");
				R_L = R_C;
				break;
			case 0x6A:
				printf("LD L,D");
				R_L = R_D;
				break;
			case 0x6B:
				printf("LD L,E");
				R_L = R_E;
				break;
			case 0x6C:
				printf("LD L,H");
				R_L = R_H;
				break;
			case 0x6D:
				printf("LD E,L");
				R_E = R_L;
				break;
			case 0x6E:
				printf("LD E,(HL)");
				R_E = RAM[R_HL];
				break;
			case 0x6F:
				printf("LD E,A");
				R_E = R_A;
				break;
			case 0x70:
				printf("LD H,B");
				R_H = R_B;
				break;
			case 0x71:
				printf("LD H,C");
				R_H = R_C;
				break;
			case 0x72:
				printf("LD H,D");
				R_H = R_D;
				break;
			case 0x73:
				printf("LD H,E");
				R_H = R_E;
				break;
			case 0x74:
				printf("LD H,H");
				break;
			case 0x75:
				printf("LD H,L");
				R_H = R_L;
				break;
			case 0x76:
				printf("LD H,(HL)");
				R_H = RAM[R_HL];
				break;
			case 0x77:
				printf("LD H,A");
				R_H = R_A;
				break;
			case 0x78:
				printf("LD L,B");
				R_L = R_B;
				break;
			case 0x79:
				printf("LD L,C");
				R_L = R_C;
				break;
			case 0x7A:
				printf("LD L,D");
				R_L = R_D;
				break;
			case 0x7B:
				printf("LD L,E");
				R_L = R_E;
				break;
			case 0x7C:
				printf("LD L,H");
				R_L = R_H;
				break;
			case 0x7D:
				printf("LD L,L");
				break;
			case 0x7E:
				printf("LD L,(HL)");
				R_L = RAM[R_HL];
				break;
			case 0x7F:
				printf("LD L,A");
				R_L = R_A;
				break;
			case 0xE0:
				printf("LDH (a8),A");
				// TODO: RAM[0xFF00 + a8] = R_A;
				break;
			case 0xF0:
				printf("LDH A,(a8)");
				// TODO: R_A = RAM[0xFF00 + a8];
				break;
			case 0xE2:
				printf("LD (C),A");
				// TODO: RAM[0xFF00 + R_C] = R_A;
				break;
			case 0xF2:
				printf("LD A,(C)");
				// TODO: R_A = RAM[0xFF00 + R_C];
				break;
			case 0xEA:
				printf("LD (a16),A");
				// TODO: RAM[a16] = R_A;
				break;
			case 0xFA:
				printf("LD A,(a16)");
				// TODO: R_A = RAM[a16];
				break;
		}

		printf("\n");
		PC++;
	}

	return 0;
}
