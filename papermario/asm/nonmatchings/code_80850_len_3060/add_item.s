.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_item
/* 080A24 800E7574 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 080A28 800E7578 AFB10014 */  sw    $s1, 0x14($sp)
/* 080A2C 800E757C 0080882D */  daddu $s1, $a0, $zero
/* 080A30 800E7580 AFBF0018 */  sw    $ra, 0x18($sp)
/* 080A34 800E7584 0C039DB3 */  jal   sort_items
/* 080A38 800E7588 AFB00010 */   sw    $s0, 0x10($sp)
/* 080A3C 800E758C 0000182D */  daddu $v1, $zero, $zero
/* 080A40 800E7590 3C108011 */  lui   $s0, 0x8011
/* 080A44 800E7594 2610F290 */  addiu $s0, $s0, -0xd70
/* 080A48 800E7598 0200202D */  daddu $a0, $s0, $zero
.L800E759C:
/* 080A4C 800E759C 848201B4 */  lh    $v0, 0x1b4($a0)
/* 080A50 800E75A0 10400006 */  beqz  $v0, .L800E75BC
/* 080A54 800E75A4 2402000A */   addiu $v0, $zero, 0xa
/* 080A58 800E75A8 24630001 */  addiu $v1, $v1, 1
/* 080A5C 800E75AC 2862000A */  slti  $v0, $v1, 0xa
/* 080A60 800E75B0 1440FFFA */  bnez  $v0, .L800E759C
/* 080A64 800E75B4 24840002 */   addiu $a0, $a0, 2
/* 080A68 800E75B8 2402000A */  addiu $v0, $zero, 0xa
.L800E75BC:
/* 080A6C 800E75BC 10620005 */  beq   $v1, $v0, .L800E75D4
/* 080A70 800E75C0 00031040 */   sll   $v0, $v1, 1
/* 080A74 800E75C4 02021021 */  addu  $v0, $s0, $v0
/* 080A78 800E75C8 A45101B4 */  sh    $s1, 0x1b4($v0)
/* 080A7C 800E75CC 08039D76 */  j     .L800E75D8
/* 080A80 800E75D0 0060102D */   daddu $v0, $v1, $zero

.L800E75D4:
/* 080A84 800E75D4 2402FFFF */  addiu $v0, $zero, -1
.L800E75D8:
/* 080A88 800E75D8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 080A8C 800E75DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 080A90 800E75E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 080A94 800E75E4 03E00008 */  jr    $ra
/* 080A98 800E75E8 27BD0020 */   addiu $sp, $sp, 0x20

