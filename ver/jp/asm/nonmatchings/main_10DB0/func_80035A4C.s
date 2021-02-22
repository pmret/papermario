.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035A4C
/* 10E4C 80035A4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10E50 80035A50 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10E54 80035A54 0C00F8BF */  jal       func_8003E2FC
/* 10E58 80035A58 00000000 */   nop
/* 10E5C 80035A5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10E60 80035A60 03E00008 */  jr        $ra
/* 10E64 80035A64 27BD0018 */   addiu    $sp, $sp, 0x18
/* 10E68 80035A68 00000000 */  nop
/* 10E6C 80035A6C 00000000 */  nop
