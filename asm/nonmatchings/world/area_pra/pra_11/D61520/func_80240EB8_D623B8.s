.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_D623B8
/* D623B8 80240EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D623BC 80240EBC AFBF0010 */  sw        $ra, 0x10($sp)
/* D623C0 80240EC0 0C00EAD2 */  jal       get_npc_safe
/* D623C4 80240EC4 2404FFFC */   addiu    $a0, $zero, -4
/* D623C8 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* D623CC 80240ECC 10800004 */  beqz      $a0, .L80240EE0
/* D623D0 80240ED0 3C030008 */   lui      $v1, 8
/* D623D4 80240ED4 8C820000 */  lw        $v0, ($a0)
/* D623D8 80240ED8 00431025 */  or        $v0, $v0, $v1
/* D623DC 80240EDC AC820000 */  sw        $v0, ($a0)
.L80240EE0:
/* D623E0 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D623E4 80240EE4 03E00008 */  jr        $ra
/* D623E8 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
