.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel play_sound_at_player
/* 0E03D8 80149CD8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E03DC 80149CDC 3C028011 */  lui   $v0, 0x8011
/* 0E03E0 80149CE0 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 0E03E4 80149CE4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E03E8 80149CE8 C4400030 */  lwc1  $f0, 0x30($v0)
/* 0E03EC 80149CEC E7A00010 */  swc1  $f0, 0x10($sp)
/* 0E03F0 80149CF0 8C460028 */  lw    $a2, 0x28($v0)
/* 0E03F4 80149CF4 0C052757 */  jal   play_sound_at_position
/* 0E03F8 80149CF8 8C47002C */   lw    $a3, 0x2c($v0)
/* 0E03FC 80149CFC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E0400 80149D00 03E00008 */  jr    $ra
/* 0E0404 80149D04 27BD0020 */   addiu $sp, $sp, 0x20

