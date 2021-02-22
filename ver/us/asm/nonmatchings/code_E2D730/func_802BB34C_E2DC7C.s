.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB34C_E2DC7C
/* E2DC7C 802BB34C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2DC80 802BB350 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2DC84 802BB354 0C05272D */  jal       play_sound
/* E2DC88 802BB358 24040791 */   addiu    $a0, $zero, 0x791
/* E2DC8C 802BB35C 24040391 */  addiu     $a0, $zero, 0x391
/* E2DC90 802BB360 0C05269B */  jal       func_80149A6C
/* E2DC94 802BB364 24050001 */   addiu    $a1, $zero, 1
/* E2DC98 802BB368 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2DC9C 802BB36C 03E00008 */  jr        $ra
/* E2DCA0 802BB370 27BD0018 */   addiu    $sp, $sp, 0x18
