.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel StartRumble
/* 182AF8 80254218 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 182AFC 8025421C AFBF0010 */  sw    $ra, 0x10($sp)
/* 182B00 80254220 8C82000C */  lw    $v0, 0xc($a0)
/* 182B04 80254224 0C0B1EAF */  jal   get_variable
/* 182B08 80254228 8C450000 */   lw    $a1, ($v0)
/* 182B0C 8025422C 0C099F7D */  jal   start_rumble_type
/* 182B10 80254230 0040202D */   daddu $a0, $v0, $zero
/* 182B14 80254234 8FBF0010 */  lw    $ra, 0x10($sp)
/* 182B18 80254238 24020002 */  addiu $v0, $zero, 2
/* 182B1C 8025423C 03E00008 */  jr    $ra
/* 182B20 80254240 27BD0018 */   addiu $sp, $sp, 0x18

/* 182B24 80254244 00000000 */  nop   
/* 182B28 80254248 00000000 */  nop   
/* 182B2C 8025424C 00000000 */  nop   
