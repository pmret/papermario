.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D7ED80
/* D7ED80 80240020 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7ED84 80240024 AFB10014 */  sw        $s1, 0x14($sp)
/* D7ED88 80240028 0080882D */  daddu     $s1, $a0, $zero
/* D7ED8C 8024002C AFBF0018 */  sw        $ra, 0x18($sp)
/* D7ED90 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* D7ED94 80240034 8E30000C */  lw        $s0, 0xc($s1)
/* D7ED98 80240038 8E050000 */  lw        $a1, ($s0)
/* D7ED9C 8024003C 0C0B1EAF */  jal       get_variable
/* D7EDA0 80240040 26100004 */   addiu    $s0, $s0, 4
/* D7EDA4 80240044 0C00EAD2 */  jal       get_npc_safe
/* D7EDA8 80240048 0040202D */   daddu    $a0, $v0, $zero
/* D7EDAC 8024004C 10400005 */  beqz      $v0, .L80240064
/* D7EDB0 80240050 00000000 */   nop      
/* D7EDB4 80240054 8E050000 */  lw        $a1, ($s0)
/* D7EDB8 80240058 844600A8 */  lh        $a2, 0xa8($v0)
/* D7EDBC 8024005C 0C0B2026 */  jal       set_variable
/* D7EDC0 80240060 0220202D */   daddu    $a0, $s1, $zero
.L80240064:
/* D7EDC4 80240064 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7EDC8 80240068 8FB10014 */  lw        $s1, 0x14($sp)
/* D7EDCC 8024006C 8FB00010 */  lw        $s0, 0x10($sp)
/* D7EDD0 80240070 24020002 */  addiu     $v0, $zero, 2
/* D7EDD4 80240074 03E00008 */  jr        $ra
/* D7EDD8 80240078 27BD0020 */   addiu    $sp, $sp, 0x20
