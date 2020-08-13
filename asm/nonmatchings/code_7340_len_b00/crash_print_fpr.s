.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel crash_print_fpr
/* 0076B8 8002C2B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0076BC 8002C2BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0076C0 8002C2C0 8CE30000 */  lw    $v1, ($a3)
/* 0076C4 8002C2C4 000315C2 */  srl   $v0, $v1, 0x17
/* 0076C8 8002C2C8 304200FF */  andi  $v0, $v0, 0xff
/* 0076CC 8002C2CC 2442FFFF */  addiu $v0, $v0, -1
/* 0076D0 8002C2D0 2C4200FE */  sltiu $v0, $v0, 0xfe
/* 0076D4 8002C2D4 14400003 */  bnez  $v0, .L8002C2E4
/* 0076D8 8002C2D8 00C0402D */   daddu $t0, $a2, $zero
/* 0076DC 8002C2DC 1460000A */  bnez  $v1, .L8002C308
/* 0076E0 8002C2E0 00000000 */   nop   
.L8002C2E4:
/* 0076E4 8002C2E4 3C06800A */  lui   $a2, 0x800a
/* 0076E8 8002C2E8 24C68034 */  addiu $a2, $a2, -0x7fcc
/* 0076EC 8002C2EC C4E00000 */  lwc1  $f0, ($a3)
/* 0076F0 8002C2F0 46000021 */  cvt.d.s $f0, $f0
/* 0076F4 8002C2F4 F7A00010 */  sdc1  $f0, 0x10($sp)
/* 0076F8 8002C2F8 0C00B082 */  jal   crash_printf_string
/* 0076FC 8002C2FC 0100382D */   daddu $a3, $t0, $zero
/* 007700 8002C300 0800B0C6 */  j     .L8002C318
/* 007704 8002C304 00000000 */   nop   

.L8002C308:
/* 007708 8002C308 3C06800A */  lui   $a2, 0x800a
/* 00770C 8002C30C 24C68040 */  addiu $a2, $a2, -0x7fc0
/* 007710 8002C310 0C00B082 */  jal   crash_printf_string
/* 007714 8002C314 0100382D */   daddu $a3, $t0, $zero
.L8002C318:
/* 007718 8002C318 8FBF0018 */  lw    $ra, 0x18($sp)
/* 00771C 8002C31C 03E00008 */  jr    $ra
/* 007720 8002C320 27BD0020 */   addiu $sp, $sp, 0x20

