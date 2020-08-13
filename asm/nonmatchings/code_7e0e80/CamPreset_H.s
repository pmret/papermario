.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_H
/* 7E1BF4 80280D74 0000102D */   daddu $v0, $zero, $zero
/* 7E1BF8 80280D78 3C04001E */  lui   $a0, 0x1e
/* 7E1BFC 80280D7C 34840003 */  ori   $a0, $a0, 3
/* 7E1C00 80280D80 26250078 */  addiu $a1, $s1, 0x78
/* 7E1C04 80280D84 080A04D5 */  j     .L80281354
/* 7E1C08 80280D88 24020029 */   addiu $v0, $zero, 0x29

.L80280D8C:
/* 7E1C0C 80280D8C 8E240078 */  lw    $a0, 0x78($s1)
