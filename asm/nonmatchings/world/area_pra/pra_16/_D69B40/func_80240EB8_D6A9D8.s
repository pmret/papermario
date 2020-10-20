.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D6A9D8
/* D6A9D8 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6A9DC 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D6A9E0 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D6A9E4 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D6A9E8 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D6A9EC 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D6A9F0 80240ED0 3C030008 */   lui      $v1, 8
/* D6A9F4 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D6A9F8 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D6A9FC 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D6AA00 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D6AA04 80240EE4 03E00008 */  jr        $ra
/* D6AA08 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
