.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AA8_4EFF48
/* 4EFF48 80218AA8 3C048022 */  lui       $a0, %hi(D_80220770)
/* 4EFF4C 80218AAC 8C840770 */  lw        $a0, %lo(D_80220770)($a0)
/* 4EFF50 80218AB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFF54 80218AB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFF58 80218AB8 0C016914 */  jal       remove_effect
/* 4EFF5C 80218ABC 00000000 */   nop
/* 4EFF60 80218AC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFF64 80218AC4 24020002 */  addiu     $v0, $zero, 2
/* 4EFF68 80218AC8 03E00008 */  jr        $ra
/* 4EFF6C 80218ACC 27BD0018 */   addiu    $sp, $sp, 0x18
