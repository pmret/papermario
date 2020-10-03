.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_damage_event_actor_0
/* 1A71D8 802788F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A71DC 802788FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A71E0 80278900 0C09E1B5 */  jal       dispatch_damage_event_actor
/* 1A71E4 80278904 0000382D */   daddu    $a3, $zero, $zero
/* 1A71E8 80278908 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A71EC 8027890C 03E00008 */  jr        $ra
/* 1A71F0 80278910 27BD0018 */   addiu    $sp, $sp, 0x18
