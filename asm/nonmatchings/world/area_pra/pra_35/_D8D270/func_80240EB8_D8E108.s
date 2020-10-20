.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D8E108
/* D8E108 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8E10C 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D8E110 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D8E114 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D8E118 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D8E11C 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D8E120 80240ED0 3C030008 */   lui      $v1, 8
/* D8E124 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D8E128 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D8E12C 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D8E130 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D8E134 80240EE4 03E00008 */  jr        $ra
/* D8E138 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
