.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB4_D964A4
/* D964A4 80240EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D964A8 80240EB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D964AC 80240EBC 0C00EAD2 */  jal       get_npc_safe
/* D964B0 80240EC0 2404FFFC */   addiu    $a0, $zero, -4
/* D964B4 80240EC4 0040202D */  daddu     $a0, $v0, $zero
/* D964B8 80240EC8 10800004 */  beqz      $a0, .L80240EDC
/* D964BC 80240ECC 3C03000A */   lui      $v1, 0xa
/* D964C0 80240ED0 8C820000 */  lw        $v0, ($a0)
/* D964C4 80240ED4 00431025 */  or        $v0, $v0, $v1
/* D964C8 80240ED8 AC820000 */  sw        $v0, ($a0)
.L80240EDC:
/* D964CC 80240EDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D964D0 80240EE0 03E00008 */  jr        $ra
/* D964D4 80240EE4 27BD0018 */   addiu    $sp, $sp, 0x18
