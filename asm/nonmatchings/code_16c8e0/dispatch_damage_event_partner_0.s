.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dispatch_damage_event_partner_0
/* 1AE460 8027FB80 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AE464 8027FB84 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1AE468 8027FB88 0C09FE73 */  jal   dispatch_damage_event_partner
/* 1AE46C 8027FB8C 0000302D */   daddu $a2, $zero, $zero
/* 1AE470 8027FB90 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1AE474 8027FB94 03E00008 */  jr    $ra
/* 1AE478 8027FB98 27BD0018 */   addiu $sp, $sp, 0x18

