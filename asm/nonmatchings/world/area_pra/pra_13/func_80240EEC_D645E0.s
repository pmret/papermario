.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_D654CC
/* D654CC 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D654D0 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D654D4 80240EF4 0C00EAD2 */  jal       get_npc_safe
/* D654D8 80240EF8 2404FFFC */   addiu    $a0, $zero, -4
/* D654DC 80240EFC 0040202D */  daddu     $a0, $v0, $zero
/* D654E0 80240F00 10800004 */  beqz      $a0, .L80240F14
/* D654E4 80240F04 3C030002 */   lui      $v1, 2
/* D654E8 80240F08 8C820000 */  lw        $v0, ($a0)
/* D654EC 80240F0C 00431025 */  or        $v0, $v0, $v1
/* D654F0 80240F10 AC820000 */  sw        $v0, ($a0)
.L80240F14:
/* D654F4 80240F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D654F8 80240F18 03E00008 */  jr        $ra
/* D654FC 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
