.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A9C_886E5C
/* 886E5C 80240A9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 886E60 80240AA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 886E64 80240AA4 8C82000C */  lw        $v0, 0xc($a0)
/* 886E68 80240AA8 0C0B1EAF */  jal       get_variable
/* 886E6C 80240AAC 8C450000 */   lw       $a1, ($v0)
/* 886E70 80240AB0 0C03AC5A */  jal       func_800EB168
/* 886E74 80240AB4 0040202D */   daddu    $a0, $v0, $zero
/* 886E78 80240AB8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 886E7C 80240ABC 24020002 */  addiu     $v0, $zero, 2
/* 886E80 80240AC0 03E00008 */  jr        $ra
/* 886E84 80240AC4 27BD0018 */   addiu    $sp, $sp, 0x18
