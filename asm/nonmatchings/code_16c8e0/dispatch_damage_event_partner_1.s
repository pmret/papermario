.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dispatch_damage_event_partner_1
/* 1AE47C 8027FB9C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AE480 8027FBA0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1AE484 8027FBA4 0C09FE73 */  jal   dispatch_damage_event_partner
/* 1AE488 8027FBA8 24060001 */   addiu $a2, $zero, 1
/* 1AE48C 8027FBAC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1AE490 8027FBB0 03E00008 */  jr    $ra
/* 1AE494 8027FBB4 27BD0018 */   addiu $sp, $sp, 0x18

