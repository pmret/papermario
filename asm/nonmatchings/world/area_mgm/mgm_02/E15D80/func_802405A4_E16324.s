.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A4_E16324
/* E16324 802405A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E16328 802405A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* E1632C 802405AC 0C00FB3A */  jal       get_enemy
/* E16330 802405B0 0000202D */   daddu    $a0, $zero, $zero
/* E16334 802405B4 8C42006C */  lw        $v0, 0x6c($v0)
/* E16338 802405B8 0C0441B4 */  jal       delete_entity
/* E1633C 802405BC 8C44001C */   lw       $a0, 0x1c($v0)
/* E16340 802405C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E16344 802405C4 24020002 */  addiu     $v0, $zero, 2
/* E16348 802405C8 03E00008 */  jr        $ra
/* E1634C 802405CC 27BD0018 */   addiu    $sp, $sp, 0x18
