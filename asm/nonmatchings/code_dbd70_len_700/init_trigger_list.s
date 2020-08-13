.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel init_trigger_list
/* 0DBE28 80145728 3C028007 */  lui   $v0, 0x8007
/* 0DBE2C 8014572C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DBE30 80145730 80420070 */  lb    $v0, 0x70($v0)
/* 0DBE34 80145734 14400005 */  bnez  $v0, .L8014574C
/* 0DBE38 80145738 00000000 */   nop   
/* 0DBE3C 8014573C 3C028016 */  lui   $v0, 0x8016
/* 0DBE40 80145740 24429190 */  addiu $v0, $v0, -0x6e70
/* 0DBE44 80145744 080515D5 */  j     .L80145754
/* 0DBE48 80145748 00000000 */   nop   

.L8014574C:
/* 0DBE4C 8014574C 3C028016 */  lui   $v0, 0x8016
/* 0DBE50 80145750 24429290 */  addiu $v0, $v0, -0x6d70
.L80145754:
/* 0DBE54 80145754 3C018016 */  lui   $at, 0x8016
/* 0DBE58 80145758 AC229390 */  sw    $v0, -0x6c70($at)
/* 0DBE5C 8014575C 3C018015 */  lui   $at, 0x8015
/* 0DBE60 80145760 A4201334 */  sh    $zero, 0x1334($at)
/* 0DBE64 80145764 03E00008 */  jr    $ra
/* 0DBE68 80145768 00000000 */   nop   

