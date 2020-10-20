.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_8EC130
/* 8EC130 80240310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EC134 80240314 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EC138 80240318 0C04E0A8 */  jal       set_map_transition_effect
/* 8EC13C 8024031C 24040004 */   addiu    $a0, $zero, 4
/* 8EC140 80240320 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EC144 80240324 24020002 */  addiu     $v0, $zero, 2
/* 8EC148 80240328 03E00008 */  jr        $ra
/* 8EC14C 8024032C 27BD0018 */   addiu    $sp, $sp, 0x18
