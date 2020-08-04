.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fio_init_flash
/* 006C4C 8002B84C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006C50 8002B850 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006C54 8002B854 0C01BBDA */  jal   osFlashInit
/* 006C58 8002B858 00000000 */   nop   
/* 006C5C 8002B85C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006C60 8002B860 03E00008 */  jr    $ra
/* 006C64 8002B864 27BD0018 */   addiu $sp, $sp, 0x18

