.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800554E8
/* 0308E8 800554E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0308EC 800554EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0308F0 800554F0 0080882D */  daddu $s1, $a0, $zero
/* 0308F4 800554F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0308F8 800554F8 00A0902D */  daddu $s2, $a1, $zero
/* 0308FC 800554FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 030900 80055500 0C01430C */  jal   func_80050C30
/* 030904 80055504 AFB00010 */   sw    $s0, 0x10($sp)
/* 030908 80055508 0040802D */  daddu $s0, $v0, $zero
/* 03090C 8005550C 16000005 */  bnez  $s0, .L80055524
/* 030910 80055510 0200102D */   daddu $v0, $s0, $zero
/* 030914 80055514 0220202D */  daddu $a0, $s1, $zero
/* 030918 80055518 0C0143D9 */  jal   func_80050F64
/* 03091C 8005551C 0240282D */   daddu $a1, $s2, $zero
/* 030920 80055520 0200102D */  daddu $v0, $s0, $zero
.L80055524:
/* 030924 80055524 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030928 80055528 8FB20018 */  lw    $s2, 0x18($sp)
/* 03092C 8005552C 8FB10014 */  lw    $s1, 0x14($sp)
/* 030930 80055530 8FB00010 */  lw    $s0, 0x10($sp)
/* 030934 80055534 03E00008 */  jr    $ra
/* 030938 80055538 27BD0020 */   addiu $sp, $sp, 0x20

