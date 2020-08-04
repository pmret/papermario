.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveKeyItemAt
/* 0FB208 802D6858 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB20C 802D685C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB210 802D6860 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB214 802D6864 0C0B1EAF */  jal   get_variable
/* 0FB218 802D6868 8C450000 */   lw    $a1, ($v0)
/* 0FB21C 802D686C 00021840 */  sll   $v1, $v0, 1
/* 0FB220 802D6870 3C018011 */  lui   $at, 0x8011
/* 0FB224 802D6874 00230821 */  addu  $at, $at, $v1
/* 0FB228 802D6878 A420F304 */  sh    $zero, -0xcfc($at)
/* 0FB22C 802D687C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB230 802D6880 24020002 */  addiu $v0, $zero, 2
/* 0FB234 802D6884 03E00008 */  jr    $ra
/* 0FB238 802D6888 27BD0018 */   addiu $sp, $sp, 0x18

