.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802497D8
/* 13CB18 802497D8 00021080 */  sll   $v0, $v0, 2
/* 13CB1C 802497DC 3C018027 */  lui   $at, 0x8027
/* 13CB20 802497E0 00220821 */  addu  $at, $at, $v0
/* 13CB24 802497E4 902204D2 */  lbu   $v0, 0x4d2($at)
/* 13CB28 802497E8 14400002 */  bnez  $v0, .L802497F4
/* 13CB2C 802497EC 00A2001A */   div   $zero, $a1, $v0
/* 13CB30 802497F0 0007000D */  break 7
.L802497F4:
/* 13CB34 802497F4 2401FFFF */  addiu $at, $zero, -1
/* 13CB38 802497F8 14410004 */  bne   $v0, $at, .L8024980C
/* 13CB3C 802497FC 3C018000 */   lui   $at, 0x8000
/* 13CB40 80249800 14A10002 */  bne   $a1, $at, .L8024980C
/* 13CB44 80249804 00000000 */   nop   
/* 13CB48 80249808 0006000D */  break 6
.L8024980C:
/* 13CB4C 8024980C 00001810 */  mfhi  $v1
/* 13CB50 80249810 00031040 */  sll   $v0, $v1, 1
/* 13CB54 80249814 00431021 */  addu  $v0, $v0, $v1
/* 13CB58 80249818 00021100 */  sll   $v0, $v0, 4
/* 13CB5C 8024981C 00431021 */  addu  $v0, $v0, $v1
/* 13CB60 80249820 03E00008 */  jr    $ra
/* 13CB64 80249824 00021040 */   sll   $v0, $v0, 1

