.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D59748
/* D59748 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D5974C 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D59750 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D59754 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D59758 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D5975C 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D59760 80240ED0 3C030008 */   lui      $v1, 8
/* D59764 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D59768 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D5976C 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D59770 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59774 80240EE4 03E00008 */  jr        $ra
/* D59778 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
