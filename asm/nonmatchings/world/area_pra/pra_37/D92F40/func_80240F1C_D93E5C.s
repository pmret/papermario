.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F1C_D93E5C
/* D93E5C 80240F1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D93E60 80240F20 AFBF0010 */  sw        $ra, 0x10($sp)
/* D93E64 80240F24 0C00EAD2 */  jal       get_npc_safe
/* D93E68 80240F28 2404FFFC */   addiu    $a0, $zero, -4
/* D93E6C 80240F2C 0040202D */  daddu     $a0, $v0, $zero
/* D93E70 80240F30 10800004 */  beqz      $a0, .L80240F44
/* D93E74 80240F34 3C030002 */   lui      $v1, 2
/* D93E78 80240F38 8C820000 */  lw        $v0, ($a0)
/* D93E7C 80240F3C 00431025 */  or        $v0, $v0, $v1
/* D93E80 80240F40 AC820000 */  sw        $v0, ($a0)
.L80240F44:
/* D93E84 80240F44 8FBF0010 */  lw        $ra, 0x10($sp)
/* D93E88 80240F48 03E00008 */  jr        $ra
/* D93E8C 80240F4C 27BD0018 */   addiu    $sp, $sp, 0x18
