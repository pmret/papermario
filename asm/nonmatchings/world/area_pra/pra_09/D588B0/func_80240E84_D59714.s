.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E84_D59714
/* D59714 80240E84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59718 80240E88 AFBF0010 */  sw        $ra, 0x10($sp)
/* D5971C 80240E8C 0C00EAD2 */  jal       get_npc_safe
/* D59720 80240E90 2404FFFC */   addiu    $a0, $zero, -4
/* D59724 80240E94 0040202D */  daddu     $a0, $v0, $zero
/* D59728 80240E98 10800004 */  beqz      $a0, .L80240EAC
/* D5972C 80240E9C 3C03000A */   lui      $v1, 0xa
/* D59730 80240EA0 8C820000 */  lw        $v0, ($a0)
/* D59734 80240EA4 00431025 */  or        $v0, $v0, $v1
/* D59738 80240EA8 AC820000 */  sw        $v0, ($a0)
.L80240EAC:
/* D5973C 80240EAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59740 80240EB0 03E00008 */  jr        $ra
/* D59744 80240EB4 27BD0018 */   addiu    $sp, $sp, 0x18
