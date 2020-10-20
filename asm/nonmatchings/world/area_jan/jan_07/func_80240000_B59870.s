.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B59870
/* B59870 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B59874 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* B59878 80240008 0080882D */  daddu     $s1, $a0, $zero
/* B5987C 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* B59880 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* B59884 80240014 8E300148 */  lw        $s0, 0x148($s1)
/* B59888 80240018 0C00EABB */  jal       get_npc_unsafe
/* B5988C 8024001C 86040008 */   lh       $a0, 8($s0)
/* B59890 80240020 3C054387 */  lui       $a1, 0x4387
/* B59894 80240024 0040202D */  daddu     $a0, $v0, $zero
/* B59898 80240028 0C00ECD0 */  jal       set_npc_yaw
/* B5989C 8024002C A480008E */   sh       $zero, 0x8e($a0)
/* B598A0 80240030 24020003 */  addiu     $v0, $zero, 3
/* B598A4 80240034 AE00006C */  sw        $zero, 0x6c($s0)
/* B598A8 80240038 AE220070 */  sw        $v0, 0x70($s1)
/* B598AC 8024003C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B598B0 80240040 8FB10014 */  lw        $s1, 0x14($sp)
/* B598B4 80240044 8FB00010 */  lw        $s0, 0x10($sp)
/* B598B8 80240048 03E00008 */  jr        $ra
/* B598BC 8024004C 27BD0020 */   addiu    $sp, $sp, 0x20
