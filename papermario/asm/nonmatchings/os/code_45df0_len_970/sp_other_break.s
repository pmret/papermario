.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sp_other_break
.L8006AD2C:
/* 04612C 8006AD2C 0C01ABDF */  jal   send_mesg
/* 046130 8006AD30 24040058 */   addiu $a0, $zero, 0x58
/* 046134 8006AD34 1220003E */  beqz  $s1, .L8006AE30
/* 046138 8006AD38 00000000 */   nop   
