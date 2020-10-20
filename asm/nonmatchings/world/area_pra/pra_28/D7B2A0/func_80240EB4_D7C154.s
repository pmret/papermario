.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB4_D7C154
/* D7C154 80240EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7C158 80240EB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7C15C 80240EBC 0C00EAD2 */  jal       get_npc_safe
/* D7C160 80240EC0 2404FFFC */   addiu    $a0, $zero, -4
/* D7C164 80240EC4 0040202D */  daddu     $a0, $v0, $zero
/* D7C168 80240EC8 10800004 */  beqz      $a0, .L80240EDC
/* D7C16C 80240ECC 3C03000A */   lui      $v1, 0xa
/* D7C170 80240ED0 8C820000 */  lw        $v0, ($a0)
/* D7C174 80240ED4 00431025 */  or        $v0, $v0, $v1
/* D7C178 80240ED8 AC820000 */  sw        $v0, ($a0)
.L80240EDC:
/* D7C17C 80240EDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7C180 80240EE0 03E00008 */  jr        $ra
/* D7C184 80240EE4 27BD0018 */   addiu    $sp, $sp, 0x18
