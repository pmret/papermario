.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240370_8B03E0
/* 8B03E0 80240370 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B03E4 80240374 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B03E8 80240378 0C00D77C */  jal       func_80035DF0
/* 8B03EC 8024037C 24040001 */   addiu    $a0, $zero, 1
/* 8B03F0 80240380 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B03F4 80240384 24020002 */  addiu     $v0, $zero, 2
/* 8B03F8 80240388 03E00008 */  jr        $ra
/* 8B03FC 8024038C 27BD0018 */   addiu    $sp, $sp, 0x18
