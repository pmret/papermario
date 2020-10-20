.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D9A868
/* D9A868 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9A86C 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D9A870 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D9A874 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D9A878 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D9A87C 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D9A880 80240ED0 3C030008 */   lui      $v1, 8
/* D9A884 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D9A888 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D9A88C 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D9A890 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D9A894 80240EE4 03E00008 */  jr        $ra
/* D9A898 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
