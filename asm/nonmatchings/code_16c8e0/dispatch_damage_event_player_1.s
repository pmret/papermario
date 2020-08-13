.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel dispatch_damage_event_player_1
/* 1A1C88 802733A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1A1C8C 802733AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 1A1C90 802733B0 0C09CC6F */  jal   dispatch_damage_event_player
/* 1A1C94 802733B4 24060001 */   addiu $a2, $zero, 1
/* 1A1C98 802733B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1A1C9C 802733BC 03E00008 */  jr    $ra
/* 1A1CA0 802733C0 27BD0018 */   addiu $sp, $sp, 0x18

