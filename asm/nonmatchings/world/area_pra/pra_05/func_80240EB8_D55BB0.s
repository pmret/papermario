.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D56A68
/* D56A68 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D56A6C 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D56A70 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D56A74 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D56A78 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D56A7C 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D56A80 80240ED0 3C030008 */   lui      $v1, 8
/* D56A84 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D56A88 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D56A8C 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D56A90 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D56A94 80240EE4 03E00008 */  jr        $ra
/* D56A98 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
