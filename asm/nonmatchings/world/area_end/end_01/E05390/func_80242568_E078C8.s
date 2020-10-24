.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242568_E078C8
/* E078C8 80242568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E078CC 8024256C AFBF0010 */  sw        $ra, 0x10($sp)
/* E078D0 80242570 0C090944 */  jal       func_80242510_E07870
/* E078D4 80242574 00000000 */   nop      
/* E078D8 80242578 0C048DCD */  jal       load_font
/* E078DC 8024257C 24040001 */   addiu    $a0, $zero, 1
/* E078E0 80242580 8FBF0010 */  lw        $ra, 0x10($sp)
/* E078E4 80242584 24020002 */  addiu     $v0, $zero, 2
/* E078E8 80242588 03E00008 */  jr        $ra
/* E078EC 8024258C 27BD0018 */   addiu    $sp, $sp, 0x18
