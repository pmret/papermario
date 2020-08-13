.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EB658
/* 084B08 800EB658 3C028011 */  lui   $v0, 0x8011
/* 084B0C 800EB65C 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084B10 800EB660 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 084B14 800EB664 AFBF0014 */  sw    $ra, 0x14($sp)
/* 084B18 800EB668 10400012 */  beqz  $v0, .L800EB6B4
/* 084B1C 800EB66C AFB00010 */   sw    $s0, 0x10($sp)
/* 084B20 800EB670 3C108011 */  lui   $s0, 0x8011
/* 084B24 800EB674 2610CFDC */  addiu $s0, $s0, -0x3024
/* 084B28 800EB678 0C0B1059 */  jal   does_script_exist
/* 084B2C 800EB67C 8E040000 */   lw    $a0, ($s0)
/* 084B30 800EB680 10400003 */  beqz  $v0, .L800EB690
/* 084B34 800EB684 00000000 */   nop   
/* 084B38 800EB688 0C0B102B */  jal   kill_script_by_ID
/* 084B3C 800EB68C 8E040000 */   lw    $a0, ($s0)
.L800EB690:
/* 084B40 800EB690 3C028011 */  lui   $v0, 0x8011
/* 084B44 800EB694 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084B48 800EB698 8C420034 */  lw    $v0, 0x34($v0)
/* 084B4C 800EB69C 10400005 */  beqz  $v0, .L800EB6B4
/* 084B50 800EB6A0 00000000 */   nop   
/* 084B54 800EB6A4 3C048011 */  lui   $a0, 0x8011
/* 084B58 800EB6A8 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 084B5C 800EB6AC 0040F809 */  jalr  $v0
/* 084B60 800EB6B0 00000000 */  nop   
.L800EB6B4:
/* 084B64 800EB6B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 084B68 800EB6B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 084B6C 800EB6BC 03E00008 */  jr    $ra
/* 084B70 800EB6C0 27BD0018 */   addiu $sp, $sp, 0x18

