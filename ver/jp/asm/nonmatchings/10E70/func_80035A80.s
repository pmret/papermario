.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035A80
/* 10E80 80035A80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10E84 80035A84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10E88 80035A88 3C01800A */  lui       $at, %hi(D_8009E758)
/* 10E8C 80035A8C A420E758 */  sh        $zero, %lo(D_8009E758)($at)
/* 10E90 80035A90 0C00D6B5 */  jal       func_80035AD4
/* 10E94 80035A94 00000000 */   nop
/* 10E98 80035A98 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10E9C 80035A9C 03E00008 */  jr        $ra
/* 10EA0 80035AA0 27BD0018 */   addiu    $sp, $sp, 0x18
