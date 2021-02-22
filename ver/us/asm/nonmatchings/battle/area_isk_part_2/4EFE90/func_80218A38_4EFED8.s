.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A38_4EFED8
/* 4EFED8 80218A38 3C048022 */  lui       $a0, %hi(D_80220760)
/* 4EFEDC 80218A3C 8C840760 */  lw        $a0, %lo(D_80220760)($a0)
/* 4EFEE0 80218A40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFEE4 80218A44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFEE8 80218A48 0C016914 */  jal       remove_effect
/* 4EFEEC 80218A4C 00000000 */   nop
/* 4EFEF0 80218A50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFEF4 80218A54 24020002 */  addiu     $v0, $zero, 2
/* 4EFEF8 80218A58 03E00008 */  jr        $ra
/* 4EFEFC 80218A5C 27BD0018 */   addiu    $sp, $sp, 0x18
