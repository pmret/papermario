.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9AE700
/* 9AE700 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9AE704 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9AE708 80240008 0C00D77C */  jal       func_80035DF0
/* 9AE70C 8024000C 24040005 */   addiu    $a0, $zero, 5
/* 9AE710 80240010 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9AE714 80240014 24020002 */  addiu     $v0, $zero, 2
/* 9AE718 80240018 03E00008 */  jr        $ra
/* 9AE71C 8024001C 27BD0018 */   addiu    $sp, $sp, 0x18
