.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_D
.L80280DC8:
/* 7E1C48 80280DC8 10620018 */  beq   $v1, $v0, .L80280E2C
/* 7E1C4C 80280DCC 24020003 */   addiu $v0, $zero, 3
/* 7E1C50 80280DD0 1062002D */  beq   $v1, $v0, .L80280E88
/* 7E1C54 80280DD4 00000000 */   nop   
/* 7E1C58 80280DD8 080A03B6 */  j     .L80280ED8
/* 7E1C5C 80280DDC 00000000 */   nop   

.L80280DE0:
/* 7E1C60 80280DE0 0C0A005F */  jal   func_8028017C
