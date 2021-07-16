.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_Chest_start_bound_script
/* 1094F0 802E7C70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1094F4 802E7C74 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1094F8 802E7C78 0C04419E */  jal       entity_start_script
/* 1094FC 802E7C7C 00000000 */   nop
/* 109500 802E7C80 8FBF0010 */  lw        $ra, 0x10($sp)
/* 109504 802E7C84 03E00008 */  jr        $ra
/* 109508 802E7C88 27BD0018 */   addiu    $sp, $sp, 0x18
