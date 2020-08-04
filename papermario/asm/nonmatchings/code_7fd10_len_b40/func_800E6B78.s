.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E6B78
/* 080028 800E6B78 3C0B8011 */  lui   $t3, 0x8011
/* 08002C 800E6B7C 256BF290 */  addiu $t3, $t3, -0xd70
/* 080030 800E6B80 0000502D */  daddu $t2, $zero, $zero
/* 080034 800E6B84 24090001 */  addiu $t1, $zero, 1
/* 080038 800E6B88 24180005 */  addiu $t8, $zero, 5
/* 08003C 800E6B8C 3C0F8009 */  lui   $t7, 0x8009
/* 080040 800E6B90 25EFEF20 */  addiu $t7, $t7, -0x10e0
/* 080044 800E6B94 3C0E800F */  lui   $t6, 0x800f
/* 080048 800E6B98 25CE7F00 */  addiu $t6, $t6, 0x7f00
/* 08004C 800E6B9C 0120682D */  daddu $t5, $t1, $zero
/* 080050 800E6BA0 3C0C800F */  lui   $t4, 0x800f
/* 080054 800E6BA4 258C7F40 */  addiu $t4, $t4, 0x7f40
/* 080058 800E6BA8 3C088009 */  lui   $t0, 0x8009
/* 08005C 800E6BAC 2508EEC4 */  addiu $t0, $t0, -0x113c
.L800E6BB0:
/* 080060 800E6BB0 8D050000 */  lw    $a1, ($t0)
/* 080064 800E6BB4 000510C0 */  sll   $v0, $a1, 3
/* 080068 800E6BB8 01623021 */  addu  $a2, $t3, $v0
/* 08006C 800E6BBC 90C20014 */  lbu   $v0, 0x14($a2)
/* 080070 800E6BC0 5040001B */  beql  $v0, $zero, .L800E6C30
/* 080074 800E6BC4 25290001 */   addiu $t1, $t1, 1
/* 080078 800E6BC8 50B80019 */  beql  $a1, $t8, .L800E6C30
/* 08007C 800E6BCC 25290001 */   addiu $t1, $t1, 1
/* 080080 800E6BD0 00053880 */  sll   $a3, $a1, 2
/* 080084 800E6BD4 00EE1021 */  addu  $v0, $a3, $t6
/* 080088 800E6BD8 00051900 */  sll   $v1, $a1, 4
/* 08008C 800E6BDC 8C420000 */  lw    $v0, ($v0)
/* 080090 800E6BE0 006F1821 */  addu  $v1, $v1, $t7
/* 080094 800E6BE4 AC850108 */  sw    $a1, 0x108($a0)
/* 080098 800E6BE8 AC8D018C */  sw    $t5, 0x18c($a0)
/* 08009C 800E6BEC AC820000 */  sw    $v0, ($a0)
/* 0800A0 800E6BF0 8C620000 */  lw    $v0, ($v1)
/* 0800A4 800E6BF4 AC820084 */  sw    $v0, 0x84($a0)
/* 0800A8 800E6BF8 8C620008 */  lw    $v0, 8($v1)
/* 0800AC 800E6BFC AC820294 */  sw    $v0, 0x294($a0)
/* 0800B0 800E6C00 80C20015 */  lb    $v0, 0x15($a2)
/* 0800B4 800E6C04 AC820210 */  sw    $v0, 0x210($a0)
/* 0800B8 800E6C08 81620012 */  lb    $v0, 0x12($t3)
/* 0800BC 800E6C0C 54450006 */  bnel  $v0, $a1, .L800E6C28
/* 0800C0 800E6C10 24840004 */   addiu $a0, $a0, 4
/* 0800C4 800E6C14 00EC1021 */  addu  $v0, $a3, $t4
/* 0800C8 800E6C18 AC80018C */  sw    $zero, 0x18c($a0)
/* 0800CC 800E6C1C 8C420000 */  lw    $v0, ($v0)
/* 0800D0 800E6C20 AC820000 */  sw    $v0, ($a0)
/* 0800D4 800E6C24 24840004 */  addiu $a0, $a0, 4
.L800E6C28:
/* 0800D8 800E6C28 254A0001 */  addiu $t2, $t2, 1
/* 0800DC 800E6C2C 25290001 */  addiu $t1, $t1, 1
.L800E6C30:
/* 0800E0 800E6C30 2922000C */  slti  $v0, $t1, 0xc
/* 0800E4 800E6C34 1440FFDE */  bnez  $v0, .L800E6BB0
/* 0800E8 800E6C38 25080004 */   addiu $t0, $t0, 4
/* 0800EC 800E6C3C 03E00008 */  jr    $ra
/* 0800F0 800E6C40 0140102D */   daddu $v0, $t2, $zero

