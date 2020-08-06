.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel collision_heap_free
/* 0061F4 8002ADF4 3C028007 */  lui   $v0, 0x8007
/* 0061F8 8002ADF8 8C42419C */  lw    $v0, 0x419c($v0)
/* 0061FC 8002ADFC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006200 8002AE00 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006204 8002AE04 80420070 */  lb    $v0, 0x70($v0)
/* 006208 8002AE08 0080282D */  daddu $a1, $a0, $zero
/* 00620C 8002AE0C 3C04803E */  lui   $a0, 0x803e
/* 006210 8002AE10 2484A800 */  addiu $a0, $a0, -0x5800
/* 006214 8002AE14 14400003 */  bnez  $v0, .L8002AE24
/* 006218 8002AE18 00000000 */   nop   
/* 00621C 8002AE1C 3C048027 */  lui   $a0, 0x8027
/* 006220 8002AE20 24848000 */  addiu $a0, $a0, -0x8000
.L8002AE24:
/* 006224 8002AE24 0C00A487 */  jal   _heap_free
/* 006228 8002AE28 00000000 */   nop   
/* 00622C 8002AE2C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006230 8002AE30 03E00008 */  jr    $ra
/* 006234 8002AE34 27BD0018 */   addiu $sp, $sp, 0x18

/* 006238 8002AE38 00000000 */  nop   
/* 00623C 8002AE3C 00000000 */  nop   


