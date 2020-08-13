.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel play_sound
/* 0E03B4 80149CB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E03B8 80149CB8 0000282D */  daddu $a1, $zero, $zero
/* 0E03BC 80149CBC 00A0302D */  daddu $a2, $a1, $zero
/* 0E03C0 80149CC0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E03C4 80149CC4 0C0526AE */  jal   _play_sound
/* 0E03C8 80149CC8 00A0382D */   daddu $a3, $a1, $zero
/* 0E03CC 80149CCC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E03D0 80149CD0 03E00008 */  jr    $ra
/* 0E03D4 80149CD4 27BD0018 */   addiu $sp, $sp, 0x18

