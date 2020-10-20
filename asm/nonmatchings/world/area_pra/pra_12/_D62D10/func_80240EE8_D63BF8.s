.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EE8_D63BF8
/* D63BF8 80240EE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D63BFC 80240EEC AFBF0010 */  sw        $ra, 0x10($sp)
/* D63C00 80240EF0 0C00EAD2 */  jal       get_npc_safe
/* D63C04 80240EF4 2404FFFC */   addiu    $a0, $zero, -4
/* D63C08 80240EF8 0040202D */  daddu     $a0, $v0, $zero
/* D63C0C 80240EFC 10800004 */  beqz      $a0, .L80240F10
/* D63C10 80240F00 3C030008 */   lui      $v1, 8
/* D63C14 80240F04 8C820000 */  lw        $v0, ($a0)
/* D63C18 80240F08 00431025 */  or        $v0, $v0, $v1
/* D63C1C 80240F0C AC820000 */  sw        $v0, ($a0)
.L80240F10:
/* D63C20 80240F10 8FBF0010 */  lw        $ra, 0x10($sp)
/* D63C24 80240F14 03E00008 */  jr        $ra
/* D63C28 80240F18 27BD0018 */   addiu    $sp, $sp, 0x18
