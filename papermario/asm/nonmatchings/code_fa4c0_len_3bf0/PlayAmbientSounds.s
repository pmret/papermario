.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlayAmbientSounds
/* 0FAACC 802D611C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FAAD0 802D6120 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FAAD4 802D6124 8C82000C */  lw    $v0, 0xc($a0)
/* 0FAAD8 802D6128 0C0B1EAF */  jal   get_variable
/* 0FAADC 802D612C 8C450000 */   lw    $a1, ($v0)
/* 0FAAE0 802D6130 0040202D */  daddu $a0, $v0, $zero
/* 0FAAE4 802D6134 0C051CDA */  jal   play_ambient_sounds
/* 0FAAE8 802D6138 240500FA */   addiu $a1, $zero, 0xfa
/* 0FAAEC 802D613C 0002102B */  sltu  $v0, $zero, $v0
/* 0FAAF0 802D6140 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAAF4 802D6144 00021040 */  sll   $v0, $v0, 1
/* 0FAAF8 802D6148 03E00008 */  jr    $ra
/* 0FAAFC 802D614C 27BD0018 */   addiu $sp, $sp, 0x18

