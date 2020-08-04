.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D620
/* 18BF00 8025D620 8C8200C0 */  lw    $v0, 0xc0($a0)
/* 18BF04 8025D624 00052880 */  sll   $a1, $a1, 2
/* 18BF08 8025D628 00451021 */  addu  $v0, $v0, $a1
/* 18BF0C 8025D62C 8C4208B0 */  lw    $v0, 0x8b0($v0)
/* 18BF10 8025D630 8C43000C */  lw    $v1, 0xc($v0)
/* 18BF14 8025D634 24020005 */  addiu $v0, $zero, 5
/* 18BF18 8025D638 03E00008 */  jr    $ra
/* 18BF1C 8025D63C AC62002C */   sw    $v0, 0x2c($v1)

