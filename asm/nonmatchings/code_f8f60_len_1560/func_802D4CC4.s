.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D4CC4
/* 0F9674 802D4CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9678 802D4CC8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F967C 802D4CCC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F9680 802D4CD0 0C0B1EAF */  jal   get_variable
/* 0F9684 802D4CD4 8C450000 */   lw    $a1, ($v0)
/* 0F9688 802D4CD8 04410004 */  bgez  $v0, .L802D4CEC
/* 0F968C 802D4CDC 2404000A */   addiu $a0, $zero, 0xa
/* 0F9690 802D4CE0 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9694 802D4CE4 080B533F */  j     .L802D4CFC
/* 0F9698 802D4CE8 240400FF */   addiu $a0, $zero, 0xff

.L802D4CEC:
/* 0F969C 802D4CEC 44820000 */  mtc1  $v0, $f0
/* 0F96A0 802D4CF0 00000000 */  nop   
/* 0F96A4 802D4CF4 46800020 */  cvt.s.w $f0, $f0
/* 0F96A8 802D4CF8 44050000 */  mfc1  $a1, $f0
.L802D4CFC:
/* 0F96AC 802D4CFC 0C04DF69 */  jal   func_80137DA4
/* 0F96B0 802D4D00 00000000 */   nop   
/* 0F96B4 802D4D04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F96B8 802D4D08 24020002 */  addiu $v0, $zero, 2
/* 0F96BC 802D4D0C 03E00008 */  jr    $ra
/* 0F96C0 802D4D10 27BD0018 */   addiu $sp, $sp, 0x18