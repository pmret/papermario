.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dispatch_damage_event_actor_1
/* 1A71F4 80278914 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1A71F8 80278918 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1A71FC 8027891C 0C09E1B5 */  jal   dispatch_damage_event_actor
/* 1A7200 80278920 24070001 */   addiu $a3, $zero, 1
/* 1A7204 80278924 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1A7208 80278928 03E00008 */  jr    $ra
/* 1A720C 8027892C 27BD0018 */   addiu $sp, $sp, 0x18

