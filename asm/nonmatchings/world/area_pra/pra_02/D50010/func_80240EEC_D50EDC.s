.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_D50EDC
/* D50EDC 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D50EE0 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D50EE4 80240EF4 0C00EAD2 */  jal       get_npc_safe
/* D50EE8 80240EF8 2404FFFC */   addiu    $a0, $zero, -4
/* D50EEC 80240EFC 0040202D */  daddu     $a0, $v0, $zero
/* D50EF0 80240F00 10800004 */  beqz      $a0, .L80240F14
/* D50EF4 80240F04 3C030002 */   lui      $v1, 2
/* D50EF8 80240F08 8C820000 */  lw        $v0, ($a0)
/* D50EFC 80240F0C 00431025 */  or        $v0, $v0, $v1
/* D50F00 80240F10 AC820000 */  sw        $v0, ($a0)
.L80240F14:
/* D50F04 80240F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D50F08 80240F18 03E00008 */  jr        $ra
/* D50F0C 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
