.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045A58
/* 20E58 80045A58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20E5C 80045A5C AFB10014 */  sw        $s1, 0x14($sp)
/* 20E60 80045A60 0080882D */  daddu     $s1, $a0, $zero
/* 20E64 80045A64 AFBF0018 */  sw        $ra, 0x18($sp)
/* 20E68 80045A68 AFB00010 */  sw        $s0, 0x10($sp)
/* 20E6C 80045A6C 8E30000C */  lw        $s0, 0xc($s1)
/* 20E70 80045A70 8E050000 */  lw        $a1, ($s0)
/* 20E74 80045A74 0C0B1EAF */  jal       get_variable
/* 20E78 80045A78 26100004 */   addiu    $s0, $s0, 4
/* 20E7C 80045A7C 0220202D */  daddu     $a0, $s1, $zero
/* 20E80 80045A80 8E050000 */  lw        $a1, ($s0)
/* 20E84 80045A84 0C0B1EAF */  jal       get_variable
/* 20E88 80045A88 0040802D */   daddu    $s0, $v0, $zero
/* 20E8C 80045A8C 0200202D */  daddu     $a0, $s0, $zero
/* 20E90 80045A90 0C00FB3A */  jal       get_enemy
/* 20E94 80045A94 0040802D */   daddu    $s0, $v0, $zero
/* 20E98 80045A98 AC5000D8 */  sw        $s0, 0xd8($v0)
/* 20E9C 80045A9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20EA0 80045AA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 20EA4 80045AA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 20EA8 80045AA8 24020002 */  addiu     $v0, $zero, 2
/* 20EAC 80045AAC 03E00008 */  jr        $ra
/* 20EB0 80045AB0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 20EB4 80045AB4 00000000 */  nop       
/* 20EB8 80045AB8 00000000 */  nop       
/* 20EBC 80045ABC 00000000 */  nop       
