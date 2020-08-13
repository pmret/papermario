.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_F
.L80280D04:
/* 7E1B84 80280D04 24020034 */  addiu $v0, $zero, 0x34
/* 7E1B88 80280D08 10620133 */  beq   $v1, $v0, .L802811D8
/* 7E1B8C 80280D0C 24020035 */   addiu $v0, $zero, 0x35
/* 7E1B90 80280D10 1062013B */  beq   $v1, $v0, .L80281200
/* 7E1B94 80280D14 0000102D */   daddu $v0, $zero, $zero
/* 7E1B98 80280D18 080A0506 */  j     .L80281418
/* 7E1B9C 80280D1C 00000000 */   nop   

