.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_D7DA3C
/* D7DA3C 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7DA40 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7DA44 80240EF4 0C00EAD2 */  jal       get_npc_safe
/* D7DA48 80240EF8 2404FFFC */   addiu    $a0, $zero, -4
/* D7DA4C 80240EFC 0040202D */  daddu     $a0, $v0, $zero
/* D7DA50 80240F00 10800004 */  beqz      $a0, .L80240F14
/* D7DA54 80240F04 3C030002 */   lui      $v1, 2
/* D7DA58 80240F08 8C820000 */  lw        $v0, ($a0)
/* D7DA5C 80240F0C 00431025 */  or        $v0, $v0, $v1
/* D7DA60 80240F10 AC820000 */  sw        $v0, ($a0)
.L80240F14:
/* D7DA64 80240F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7DA68 80240F18 03E00008 */  jr        $ra
/* D7DA6C 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
