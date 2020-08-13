.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_B
/* 7E1B68 80280CE8 24020029 */   addiu $v0, $zero, 0x29
/* 7E1B6C 80280CEC 10620027 */  beq   $v1, $v0, .L80280D8C
/* 7E1B70 80280CF0 2402002A */   addiu $v0, $zero, 0x2a
/* 7E1B74 80280CF4 106201B3 */  beq   $v1, $v0, .L802813C4
/* 7E1B78 80280CF8 0000102D */   daddu $v0, $zero, $zero
/* 7E1B7C 80280CFC 080A0506 */  j     .L80281418
/* 7E1B80 80280D00 00000000 */   nop   

