.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249898
/* 13CBD8 80249898 00041040 */  sll   $v0, $a0, 1
/* 13CBDC 8024989C 00441021 */  addu  $v0, $v0, $a0
/* 13CBE0 802498A0 00021080 */  sll   $v0, $v0, 2
/* 13CBE4 802498A4 3C018027 */  lui   $at, 0x8027
/* 13CBE8 802498A8 00220821 */  addu  $at, $at, $v0
/* 13CBEC 802498AC 902204D2 */  lbu   $v0, 0x4d2($at)
/* 13CBF0 802498B0 14400002 */  bnez  $v0, .L802498BC
/* 13CBF4 802498B4 00A2001A */   div   $zero, $a1, $v0
/* 13CBF8 802498B8 0007000D */  break 7
.L802498BC:
/* 13CBFC 802498BC 2401FFFF */  addiu $at, $zero, -1
/* 13CC00 802498C0 14410004 */  bne   $v0, $at, .L802498D4
/* 13CC04 802498C4 3C018000 */   lui   $at, 0x8000
/* 13CC08 802498C8 14A10002 */  bne   $a1, $at, .L802498D4
/* 13CC0C 802498CC 00000000 */   nop   
/* 13CC10 802498D0 0006000D */  break 6
.L802498D4:
/* 13CC14 802498D4 00001010 */  mfhi  $v0
/* 13CC18 802498D8 03E00008 */  jr    $ra
/* 13CC1C 802498DC 00000000 */   nop   

