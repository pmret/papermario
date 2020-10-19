.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB4_D63BC4
/* D63BC4 80240EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D63BC8 80240EB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D63BCC 80240EBC 0C00EAD2 */  jal       get_npc_safe
/* D63BD0 80240EC0 2404FFFC */   addiu    $a0, $zero, -4
/* D63BD4 80240EC4 0040202D */  daddu     $a0, $v0, $zero
/* D63BD8 80240EC8 10800004 */  beqz      $a0, .L80240EDC
/* D63BDC 80240ECC 3C03000A */   lui      $v1, 0xa
/* D63BE0 80240ED0 8C820000 */  lw        $v0, ($a0)
/* D63BE4 80240ED4 00431025 */  or        $v0, $v0, $v1
/* D63BE8 80240ED8 AC820000 */  sw        $v0, ($a0)
.L80240EDC:
/* D63BEC 80240EDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D63BF0 80240EE0 03E00008 */  jr        $ra
/* D63BF4 80240EE4 27BD0018 */   addiu    $sp, $sp, 0x18
