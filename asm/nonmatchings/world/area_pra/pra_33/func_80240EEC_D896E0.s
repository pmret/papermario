.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_D8A5CC
/* D8A5CC 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8A5D0 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D8A5D4 80240EF4 0C00EAD2 */  jal       get_npc_safe
/* D8A5D8 80240EF8 2404FFFC */   addiu    $a0, $zero, -4
/* D8A5DC 80240EFC 0040202D */  daddu     $a0, $v0, $zero
/* D8A5E0 80240F00 10800004 */  beqz      $a0, .L80240F14
/* D8A5E4 80240F04 3C030002 */   lui      $v1, 2
/* D8A5E8 80240F08 8C820000 */  lw        $v0, ($a0)
/* D8A5EC 80240F0C 00431025 */  or        $v0, $v0, $v1
/* D8A5F0 80240F10 AC820000 */  sw        $v0, ($a0)
.L80240F14:
/* D8A5F4 80240F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D8A5F8 80240F18 03E00008 */  jr        $ra
/* D8A5FC 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
