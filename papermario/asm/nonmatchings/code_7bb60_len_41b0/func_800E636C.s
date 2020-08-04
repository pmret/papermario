.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E636C
/* 07F81C 800E636C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07F820 800E6370 AFB00010 */  sw    $s0, 0x10($sp)
/* 07F824 800E6374 0080802D */  daddu $s0, $a0, $zero
/* 07F828 800E6378 3C048011 */  lui   $a0, 0x8011
/* 07F82C 800E637C 8C84C96C */  lw    $a0, -0x3694($a0)
/* 07F830 800E6380 04800004 */  bltz  $a0, .L800E6394
/* 07F834 800E6384 AFBF0014 */   sw    $ra, 0x14($sp)
/* 07F838 800E6388 0C00E2B7 */  jal   get_npc_by_index
/* 07F83C 800E638C 00000000 */   nop   
/* 07F840 800E6390 AC500028 */  sw    $s0, 0x28($v0)
.L800E6394:
/* 07F844 800E6394 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07F848 800E6398 8FB00010 */  lw    $s0, 0x10($sp)
/* 07F84C 800E639C 03E00008 */  jr    $ra
/* 07F850 800E63A0 27BD0018 */   addiu $sp, $sp, 0x18

/* 07F854 800E63A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07F858 800E63A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 07F85C 800E63AC 3C108011 */  lui   $s0, 0x8011
/* 07F860 800E63B0 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 07F864 800E63B4 10800005 */  beqz  $a0, .L800E63CC
/* 07F868 800E63B8 AFBF0014 */   sw    $ra, 0x14($sp)
/* 07F86C 800E63BC 0C039769 */  jal   set_action_state
/* 07F870 800E63C0 24040019 */   addiu $a0, $zero, 0x19
/* 07F874 800E63C4 08039906 */  j     .L800E6418
/* 07F878 800E63C8 00000000 */   nop   

.L800E63CC:
/* 07F87C 800E63CC 2403DFFF */  addiu $v1, $zero, -0x2001
/* 07F880 800E63D0 8E020004 */  lw    $v0, 4($s0)
/* 07F884 800E63D4 3C048007 */  lui   $a0, 0x8007
/* 07F888 800E63D8 8C84419C */  lw    $a0, 0x419c($a0)
/* 07F88C 800E63DC 00431024 */  and   $v0, $v0, $v1
/* 07F890 800E63E0 AE020004 */  sw    $v0, 4($s0)
/* 07F894 800E63E4 9082007E */  lbu   $v0, 0x7e($a0)
/* 07F898 800E63E8 304200FD */  andi  $v0, $v0, 0xfd
/* 07F89C 800E63EC A082007E */  sb    $v0, 0x7e($a0)
/* 07F8A0 800E63F0 3C048011 */  lui   $a0, 0x8011
/* 07F8A4 800E63F4 8C84C96C */  lw    $a0, -0x3694($a0)
/* 07F8A8 800E63F8 0C00E228 */  jal   func_800388A0
/* 07F8AC 800E63FC A200000C */   sb    $zero, 0xc($s0)
/* 07F8B0 800E6400 0C039769 */  jal   set_action_state
/* 07F8B4 800E6404 0000202D */   daddu $a0, $zero, $zero
/* 07F8B8 800E6408 24020037 */  addiu $v0, $zero, 0x37
/* 07F8BC 800E640C A60200B0 */  sh    $v0, 0xb0($s0)
/* 07F8C0 800E6410 24020026 */  addiu $v0, $zero, 0x26
/* 07F8C4 800E6414 A60200B2 */  sh    $v0, 0xb2($s0)
.L800E6418:
/* 07F8C8 800E6418 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07F8CC 800E641C 8FB00010 */  lw    $s0, 0x10($sp)
/* 07F8D0 800E6420 03E00008 */  jr    $ra
/* 07F8D4 800E6424 27BD0018 */   addiu $sp, $sp, 0x18

