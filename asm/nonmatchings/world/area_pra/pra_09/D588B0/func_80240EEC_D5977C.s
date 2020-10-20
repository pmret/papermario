.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_D5977C
/* D5977C 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59780 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D59784 80240EF4 0C00EAD2 */  jal       get_npc_safe
/* D59788 80240EF8 2404FFFC */   addiu    $a0, $zero, -4
/* D5978C 80240EFC 0040202D */  daddu     $a0, $v0, $zero
/* D59790 80240F00 10800004 */  beqz      $a0, .L80240F14
/* D59794 80240F04 3C030002 */   lui      $v1, 2
/* D59798 80240F08 8C820000 */  lw        $v0, ($a0)
/* D5979C 80240F0C 00431025 */  or        $v0, $v0, $v1
/* D597A0 80240F10 AC820000 */  sw        $v0, ($a0)
.L80240F14:
/* D597A4 80240F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D597A8 80240F18 03E00008 */  jr        $ra
/* D597AC 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
