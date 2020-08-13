.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel check_input_hammer
/* 07F590 800E60E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07F594 800E60E4 3C038011 */  lui   $v1, 0x8011
/* 07F598 800E60E8 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 07F59C 800E60EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 07F5A0 800E60F0 8C6200E0 */  lw    $v0, 0xe0($v1)
/* 07F5A4 800E60F4 3C048011 */  lui   $a0, 0x8011
/* 07F5A8 800E60F8 2484F290 */  addiu $a0, $a0, -0xd70
/* 07F5AC 800E60FC 30424000 */  andi  $v0, $v0, 0x4000
/* 07F5B0 800E6100 10400014 */  beqz  $v0, .L800E6154
/* 07F5B4 800E6104 0000102D */   daddu $v0, $zero, $zero
/* 07F5B8 800E6108 8C620000 */  lw    $v0, ($v1)
/* 07F5BC 800E610C 30420004 */  andi  $v0, $v0, 4
/* 07F5C0 800E6110 14400010 */  bnez  $v0, .L800E6154
/* 07F5C4 800E6114 0000102D */   daddu $v0, $zero, $zero
/* 07F5C8 800E6118 3C038011 */  lui   $v1, 0x8011
/* 07F5CC 800E611C 8063EBB0 */  lb    $v1, -0x1450($v1)
/* 07F5D0 800E6120 24020001 */  addiu $v0, $zero, 1
/* 07F5D4 800E6124 14620004 */  bne   $v1, $v0, .L800E6138
/* 07F5D8 800E6128 24020006 */   addiu $v0, $zero, 6
/* 07F5DC 800E612C 80830012 */  lb    $v1, 0x12($a0)
/* 07F5E0 800E6130 10620008 */  beq   $v1, $v0, .L800E6154
/* 07F5E4 800E6134 0000102D */   daddu $v0, $zero, $zero
.L800E6138:
/* 07F5E8 800E6138 80830001 */  lb    $v1, 1($a0)
/* 07F5EC 800E613C 2402FFFF */  addiu $v0, $zero, -1
/* 07F5F0 800E6140 10620004 */  beq   $v1, $v0, .L800E6154
/* 07F5F4 800E6144 0000102D */   daddu $v0, $zero, $zero
/* 07F5F8 800E6148 0C039769 */  jal   set_action_state
/* 07F5FC 800E614C 24040012 */   addiu $a0, $zero, 0x12
/* 07F600 800E6150 24020001 */  addiu $v0, $zero, 1
.L800E6154:
/* 07F604 800E6154 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07F608 800E6158 03E00008 */  jr    $ra
/* 07F60C 800E615C 27BD0018 */   addiu $sp, $sp, 0x18

