.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EE8_D7C188
/* D7C188 80240EE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7C18C 80240EEC AFBF0010 */  sw        $ra, 0x10($sp)
/* D7C190 80240EF0 0C00EAD2 */  jal       get_npc_safe
/* D7C194 80240EF4 2404FFFC */   addiu    $a0, $zero, -4
/* D7C198 80240EF8 0040202D */  daddu     $a0, $v0, $zero
/* D7C19C 80240EFC 10800004 */  beqz      $a0, .L80240F10
/* D7C1A0 80240F00 3C030008 */   lui      $v1, 8
/* D7C1A4 80240F04 8C820000 */  lw        $v0, ($a0)
/* D7C1A8 80240F08 00431025 */  or        $v0, $v0, $v1
/* D7C1AC 80240F0C AC820000 */  sw        $v0, ($a0)
.L80240F10:
/* D7C1B0 80240F10 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7C1B4 80240F14 03E00008 */  jr        $ra
/* D7C1B8 80240F18 27BD0018 */   addiu    $sp, $sp, 0x18
