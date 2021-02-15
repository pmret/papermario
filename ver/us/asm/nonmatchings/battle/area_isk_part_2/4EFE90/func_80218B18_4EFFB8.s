.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B18_4EFFB8
/* 4EFFB8 80218B18 3C048022 */  lui       $a0, %hi(D_80220780)
/* 4EFFBC 80218B1C 8C840780 */  lw        $a0, %lo(D_80220780)($a0)
/* 4EFFC0 80218B20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFFC4 80218B24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFFC8 80218B28 0C016914 */  jal       remove_effect
/* 4EFFCC 80218B2C 00000000 */   nop
/* 4EFFD0 80218B30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFFD4 80218B34 24020002 */  addiu     $v0, $zero, 2
/* 4EFFD8 80218B38 03E00008 */  jr        $ra
/* 4EFFDC 80218B3C 27BD0018 */   addiu    $sp, $sp, 0x18
