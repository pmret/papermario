.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_C
/* 7E1C2C 80280DAC 28620002 */   slti  $v0, $v1, 2
/* 7E1C30 80280DB0 10400005 */  beqz  $v0, .L80280DC8
/* 7E1C34 80280DB4 24020002 */   addiu $v0, $zero, 2
/* 7E1C38 80280DB8 10600009 */  beqz  $v1, .L80280DE0
/* 7E1C3C 80280DBC 00000000 */   nop   
/* 7E1C40 80280DC0 080A03B6 */  j     .L80280ED8
/* 7E1C44 80280DC4 00000000 */   nop   

