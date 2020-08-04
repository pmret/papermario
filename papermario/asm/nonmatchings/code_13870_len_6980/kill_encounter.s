.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel kill_encounter
/* 019B30 8003E730 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 019B34 8003E734 AFBF001C */  sw    $ra, 0x1c($sp)
/* 019B38 8003E738 AFB20018 */  sw    $s2, 0x18($sp)
/* 019B3C 8003E73C AFB10014 */  sw    $s1, 0x14($sp)
/* 019B40 8003E740 AFB00010 */  sw    $s0, 0x10($sp)
/* 019B44 8003E744 80820004 */  lb    $v0, 4($a0)
/* 019B48 8003E748 00021080 */  sll   $v0, $v0, 2
/* 019B4C 8003E74C 3C12800B */  lui   $s2, 0x800b
/* 019B50 8003E750 02429021 */  addu  $s2, $s2, $v0
/* 019B54 8003E754 8E520F38 */  lw    $s2, 0xf38($s2)
/* 019B58 8003E758 8E420000 */  lw    $v0, ($s2)
/* 019B5C 8003E75C 1840000D */  blez  $v0, .L8003E794
/* 019B60 8003E760 0000882D */   daddu $s1, $zero, $zero
/* 019B64 8003E764 0240802D */  daddu $s0, $s2, $zero
.L8003E768:
/* 019B68 8003E768 8E040004 */  lw    $a0, 4($s0)
/* 019B6C 8003E76C 10800004 */  beqz  $a0, .L8003E780
/* 019B70 8003E770 00000000 */   nop   
/* 019B74 8003E774 0C00F9EB */  jal   kill_enemy
/* 019B78 8003E778 00000000 */   nop   
/* 019B7C 8003E77C AE000004 */  sw    $zero, 4($s0)
.L8003E780:
/* 019B80 8003E780 8E420000 */  lw    $v0, ($s2)
/* 019B84 8003E784 26310001 */  addiu $s1, $s1, 1
/* 019B88 8003E788 0222102A */  slt   $v0, $s1, $v0
/* 019B8C 8003E78C 1440FFF6 */  bnez  $v0, .L8003E768
/* 019B90 8003E790 26100004 */   addiu $s0, $s0, 4
.L8003E794:
/* 019B94 8003E794 8FBF001C */  lw    $ra, 0x1c($sp)
/* 019B98 8003E798 8FB20018 */  lw    $s2, 0x18($sp)
/* 019B9C 8003E79C 8FB10014 */  lw    $s1, 0x14($sp)
/* 019BA0 8003E7A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 019BA4 8003E7A4 03E00008 */  jr    $ra
/* 019BA8 8003E7A8 27BD0020 */   addiu $sp, $sp, 0x20

