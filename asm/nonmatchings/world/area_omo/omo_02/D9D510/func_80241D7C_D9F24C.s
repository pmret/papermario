.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkSetDurationFunc
/* D9F24C 80241D7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D9F250 80241D80 AFB10014 */  sw        $s1, 0x14($sp)
/* D9F254 80241D84 0080882D */  daddu     $s1, $a0, $zero
/* D9F258 80241D88 AFBF0018 */  sw        $ra, 0x18($sp)
/* D9F25C 80241D8C AFB00010 */  sw        $s0, 0x10($sp)
/* D9F260 80241D90 8E300148 */  lw        $s0, 0x148($s1)
/* D9F264 80241D94 0C00EABB */  jal       get_npc_unsafe
/* D9F268 80241D98 86040008 */   lh       $a0, 8($s0)
/* D9F26C 80241D9C 96030076 */  lhu       $v1, 0x76($s0)
/* D9F270 80241DA0 A443008E */  sh        $v1, 0x8e($v0)
/* D9F274 80241DA4 24020021 */  addiu     $v0, $zero, 0x21
/* D9F278 80241DA8 AE220070 */  sw        $v0, 0x70($s1)
/* D9F27C 80241DAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D9F280 80241DB0 8FB10014 */  lw        $s1, 0x14($sp)
/* D9F284 80241DB4 8FB00010 */  lw        $s0, 0x10($sp)
/* D9F288 80241DB8 03E00008 */  jr        $ra
/* D9F28C 80241DBC 27BD0020 */   addiu    $sp, $sp, 0x20
