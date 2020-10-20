.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E84_D77224
/* D77224 80240E84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D77228 80240E88 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7722C 80240E8C 0C00EAD2 */  jal       get_npc_safe
/* D77230 80240E90 2404FFFC */   addiu    $a0, $zero, -4
/* D77234 80240E94 0040202D */  daddu     $a0, $v0, $zero
/* D77238 80240E98 10800004 */  beqz      $a0, .L80240EAC
/* D7723C 80240E9C 3C03000A */   lui      $v1, 0xa
/* D77240 80240EA0 8C820000 */  lw        $v0, ($a0)
/* D77244 80240EA4 00431025 */  or        $v0, $v0, $v1
/* D77248 80240EA8 AC820000 */  sw        $v0, ($a0)
.L80240EAC:
/* D7724C 80240EAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D77250 80240EB0 03E00008 */  jr        $ra
/* D77254 80240EB4 27BD0018 */   addiu    $sp, $sp, 0x18
