#ifndef _MIPS_H_
#define _MIPS_H_

#define JAL   0x03
#define ADDIU 0x09
#define LUI   0x0F
#define LW    0x23
#define LOWER(x) ((x) & 0xFFFF)
#define UPPER(x) ((x) >> 16)
#define OPCODE(x) ((x) >> 26)
#define GET_RS(x) ((x >> 0x15) & 0x1F)
#define GET_RT(x) (UPPER(x) & 0x1F)

#endif
