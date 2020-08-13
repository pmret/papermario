.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_G
/* 7E1BBC 80280D3C 1062018C */  beq   $v1, $v0, .L80281370
/* 7E1BC0 80280D40 0000102D */   daddu $v0, $zero, $zero
/* 7E1BC4 80280D44 080A0506 */  j     .L80281418
/* 7E1BC8 80280D48 00000000 */   nop   

.L80280D4C:
/* 7E1BCC 80280D4C 240201F5 */  addiu $v0, $zero, 0x1f5
/* 7E1BD0 80280D50 106200EA */  beq   $v1, $v0, .L802810FC
/* 7E1BD4 80280D54 240202BD */   addiu $v0, $zero, 0x2bd
