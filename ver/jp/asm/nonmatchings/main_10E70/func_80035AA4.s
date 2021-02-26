.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035AA4
/* 10EA4 80035AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10EA8 80035AA8 24020001 */  addiu     $v0, $zero, 1
/* 10EAC 80035AAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 10EB0 80035AB0 3C01800A */  lui       $at, %hi(D_8009E758)
/* 10EB4 80035AB4 A422E758 */  sh        $v0, %lo(D_8009E758)($at)
/* 10EB8 80035AB8 0C04F4D4 */  jal       func_8013D350
/* 10EBC 80035ABC 24040008 */   addiu    $a0, $zero, 8
/* 10EC0 80035AC0 0C00D6B5 */  jal       func_80035AD4
/* 10EC4 80035AC4 00000000 */   nop
/* 10EC8 80035AC8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10ECC 80035ACC 03E00008 */  jr        $ra
/* 10ED0 80035AD0 27BD0018 */   addiu    $sp, $sp, 0x18
