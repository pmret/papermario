.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemovePartShadow
/* 19DE7C 8026F59C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19DE80 8026F5A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 19DE84 8026F5A4 0080902D */  daddu $s2, $a0, $zero
/* 19DE88 8026F5A8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19DE8C 8026F5AC AFB10014 */  sw    $s1, 0x14($sp)
/* 19DE90 8026F5B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19DE94 8026F5B4 8E50000C */  lw    $s0, 0xc($s2)
/* 19DE98 8026F5B8 8E050000 */  lw    $a1, ($s0)
/* 19DE9C 8026F5BC 0C0B1EAF */  jal   get_variable
/* 19DEA0 8026F5C0 26100004 */   addiu $s0, $s0, 4
/* 19DEA4 8026F5C4 0040882D */  daddu $s1, $v0, $zero
/* 19DEA8 8026F5C8 8E050000 */  lw    $a1, ($s0)
/* 19DEAC 8026F5CC 0C0B1EAF */  jal   get_variable
/* 19DEB0 8026F5D0 0240202D */   daddu $a0, $s2, $zero
/* 19DEB4 8026F5D4 0040282D */  daddu $a1, $v0, $zero
/* 19DEB8 8026F5D8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19DEBC 8026F5DC 16220002 */  bne   $s1, $v0, .L8026F5E8
/* 19DEC0 8026F5E0 00000000 */   nop   
/* 19DEC4 8026F5E4 8E510148 */  lw    $s1, 0x148($s2)
.L8026F5E8:
/* 19DEC8 8026F5E8 0C099CE8 */  jal   remove_part_shadow
/* 19DECC 8026F5EC 0220202D */   daddu $a0, $s1, $zero
/* 19DED0 8026F5F0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19DED4 8026F5F4 8FB20018 */  lw    $s2, 0x18($sp)
/* 19DED8 8026F5F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19DEDC 8026F5FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19DEE0 8026F600 24020002 */  addiu $v0, $zero, 2
/* 19DEE4 8026F604 03E00008 */  jr    $ra
/* 19DEE8 8026F608 27BD0020 */   addiu $sp, $sp, 0x20

/* 19DEEC 8026F60C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19DEF0 8026F610 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19DEF4 8026F614 8C82000C */  lw    $v0, 0xc($a0)
/* 19DEF8 8026F618 0C0B1EAF */  jal   get_variable
/* 19DEFC 8026F61C 8C450000 */   lw    $a1, ($v0)
/* 19DF00 8026F620 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19DF04 8026F624 3C01800E */  lui   $at, 0x800e
/* 19DF08 8026F628 A022C0FD */  sb    $v0, -0x3f03($at)
/* 19DF0C 8026F62C 24020002 */  addiu $v0, $zero, 2
/* 19DF10 8026F630 03E00008 */  jr    $ra
/* 19DF14 8026F634 27BD0018 */   addiu $sp, $sp, 0x18

