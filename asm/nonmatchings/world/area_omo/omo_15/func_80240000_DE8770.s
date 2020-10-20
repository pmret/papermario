.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DE8770
/* DE8770 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE8774 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* DE8778 80240008 AFB00018 */  sw        $s0, 0x18($sp)
/* DE877C 8024000C 8C900084 */  lw        $s0, 0x84($a0)
/* DE8780 80240010 C6000008 */  lwc1      $f0, 8($s0)
/* DE8784 80240014 240400A2 */  addiu     $a0, $zero, 0xa2
/* DE8788 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* DE878C 8024001C 8E060000 */  lw        $a2, ($s0)
/* DE8790 80240020 8E070004 */  lw        $a3, 4($s0)
/* DE8794 80240024 0C05267B */  jal       func_801499EC
/* DE8798 80240028 0000282D */   daddu    $a1, $zero, $zero
/* DE879C 8024002C 86020044 */  lh        $v0, 0x44($s0)
/* DE87A0 80240030 8FBF001C */  lw        $ra, 0x1c($sp)
/* DE87A4 80240034 8FB00018 */  lw        $s0, 0x18($sp)
/* DE87A8 80240038 28420002 */  slti      $v0, $v0, 2
/* DE87AC 8024003C 38420001 */  xori      $v0, $v0, 1
/* DE87B0 80240040 00021040 */  sll       $v0, $v0, 1
/* DE87B4 80240044 03E00008 */  jr        $ra
/* DE87B8 80240048 27BD0020 */   addiu    $sp, $sp, 0x20
