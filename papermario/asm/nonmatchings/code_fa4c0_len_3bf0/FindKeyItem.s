.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FindKeyItem
/* 0FB3C4 802D6A14 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB3C8 802D6A18 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB3CC 802D6A1C 0080882D */  daddu $s1, $a0, $zero
/* 0FB3D0 802D6A20 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB3D4 802D6A24 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB3D8 802D6A28 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB3DC 802D6A2C 8E050000 */  lw    $a1, ($s0)
/* 0FB3E0 802D6A30 0C0B1EAF */  jal   get_variable
/* 0FB3E4 802D6A34 26100004 */   addiu $s0, $s0, 4
/* 0FB3E8 802D6A38 0040302D */  daddu $a2, $v0, $zero
/* 0FB3EC 802D6A3C 0000182D */  daddu $v1, $zero, $zero
/* 0FB3F0 802D6A40 3C048011 */  lui   $a0, 0x8011
/* 0FB3F4 802D6A44 2484F290 */  addiu $a0, $a0, -0xd70
/* 0FB3F8 802D6A48 8E050000 */  lw    $a1, ($s0)
.L802D6A4C:
/* 0FB3FC 802D6A4C 84820074 */  lh    $v0, 0x74($a0)
/* 0FB400 802D6A50 10460006 */  beq   $v0, $a2, .L802D6A6C
/* 0FB404 802D6A54 24020020 */   addiu $v0, $zero, 0x20
/* 0FB408 802D6A58 24630001 */  addiu $v1, $v1, 1
/* 0FB40C 802D6A5C 28620020 */  slti  $v0, $v1, 0x20
/* 0FB410 802D6A60 1440FFFA */  bnez  $v0, .L802D6A4C
/* 0FB414 802D6A64 24840002 */   addiu $a0, $a0, 2
/* 0FB418 802D6A68 24020020 */  addiu $v0, $zero, 0x20
.L802D6A6C:
/* 0FB41C 802D6A6C 10620002 */  beq   $v1, $v0, .L802D6A78
/* 0FB420 802D6A70 2406FFFF */   addiu $a2, $zero, -1
/* 0FB424 802D6A74 0060302D */  daddu $a2, $v1, $zero
.L802D6A78:
/* 0FB428 802D6A78 0C0B2026 */  jal   set_variable
/* 0FB42C 802D6A7C 0220202D */   daddu $a0, $s1, $zero
/* 0FB430 802D6A80 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB434 802D6A84 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB438 802D6A88 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB43C 802D6A8C 24020002 */  addiu $v0, $zero, 2
/* 0FB440 802D6A90 03E00008 */  jr    $ra
/* 0FB444 802D6A94 27BD0020 */   addiu $sp, $sp, 0x20

