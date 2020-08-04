.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024EEA8
/* 17D788 8024EEA8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D78C 8024EEAC AFB10014 */  sw    $s1, 0x14($sp)
/* 17D790 8024EEB0 0000882D */  daddu $s1, $zero, $zero
/* 17D794 8024EEB4 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D798 8024EEB8 3C10802A */  lui   $s0, 0x802a
/* 17D79C 8024EEBC 2610F2C0 */  addiu $s0, $s0, -0xd40
/* 17D7A0 8024EEC0 AFBF0018 */  sw    $ra, 0x18($sp)
.L8024EEC4:
/* 17D7A4 8024EEC4 86020010 */  lh    $v0, 0x10($s0)
/* 17D7A8 8024EEC8 50400007 */  beql  $v0, $zero, .L8024EEE8
/* 17D7AC 8024EECC 26310001 */   addiu $s1, $s1, 1
/* 17D7B0 8024EED0 8E020008 */  lw    $v0, 8($s0)
/* 17D7B4 8024EED4 50400004 */  beql  $v0, $zero, .L8024EEE8
/* 17D7B8 8024EED8 26310001 */   addiu $s1, $s1, 1
/* 17D7BC 8024EEDC 0040F809 */  jalr  $v0
/* 17D7C0 8024EEE0 0200202D */  daddu $a0, $s0, $zero
/* 17D7C4 8024EEE4 26310001 */  addiu $s1, $s1, 1
.L8024EEE8:
/* 17D7C8 8024EEE8 2A220020 */  slti  $v0, $s1, 0x20
/* 17D7CC 8024EEEC 1440FFF5 */  bnez  $v0, .L8024EEC4
/* 17D7D0 8024EEF0 2610001C */   addiu $s0, $s0, 0x1c
/* 17D7D4 8024EEF4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17D7D8 8024EEF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D7DC 8024EEFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D7E0 8024EF00 03E00008 */  jr    $ra
/* 17D7E4 8024EF04 27BD0020 */   addiu $sp, $sp, 0x20

