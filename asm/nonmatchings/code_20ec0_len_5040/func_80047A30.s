.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80047A30
/* 022E30 80047A30 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 022E34 80047A34 0080302D */  daddu $a2, $a0, $zero
/* 022E38 80047A38 AFB10014 */  sw    $s1, 0x14($sp)
/* 022E3C 80047A3C 00A0882D */  daddu $s1, $a1, $zero
/* 022E40 80047A40 00061040 */  sll   $v0, $a2, 1
/* 022E44 80047A44 00461021 */  addu  $v0, $v0, $a2
/* 022E48 80047A48 00021080 */  sll   $v0, $v0, 2
/* 022E4C 80047A4C 00461023 */  subu  $v0, $v0, $a2
/* 022E50 80047A50 3C03800A */  lui   $v1, 0x800a
/* 022E54 80047A54 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022E58 80047A58 00021100 */  sll   $v0, $v0, 4
/* 022E5C 80047A5C AFBF0018 */  sw    $ra, 0x18($sp)
/* 022E60 80047A60 AFB00010 */  sw    $s0, 0x10($sp)
/* 022E64 80047A64 00628021 */  addu  $s0, $v1, $v0
/* 022E68 80047A68 2403FFEF */  addiu $v1, $zero, -0x11
/* 022E6C 80047A6C 8E020000 */  lw    $v0, ($s0)
/* 022E70 80047A70 82040058 */  lb    $a0, 0x58($s0)
/* 022E74 80047A74 00431024 */  and   $v0, $v0, $v1
/* 022E78 80047A78 10910006 */  beq   $a0, $s1, .L80047A94
/* 022E7C 80047A7C AE020000 */   sw    $v0, ($s0)
/* 022E80 80047A80 0C011EAA */  jal   func_80047AA8
/* 022E84 80047A84 00C0202D */   daddu $a0, $a2, $zero
/* 022E88 80047A88 24020001 */  addiu $v0, $zero, 1
/* 022E8C 80047A8C A2110058 */  sb    $s1, 0x58($s0)
/* 022E90 80047A90 A202005A */  sb    $v0, 0x5a($s0)
.L80047A94:
/* 022E94 80047A94 8FBF0018 */  lw    $ra, 0x18($sp)
/* 022E98 80047A98 8FB10014 */  lw    $s1, 0x14($sp)
/* 022E9C 80047A9C 8FB00010 */  lw    $s0, 0x10($sp)
/* 022EA0 80047AA0 03E00008 */  jr    $ra
/* 022EA4 80047AA4 27BD0020 */   addiu $sp, $sp, 0x20

