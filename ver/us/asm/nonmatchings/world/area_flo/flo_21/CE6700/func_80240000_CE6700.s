.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CE6700
/* CE6700 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CE6704 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* CE6708 80240008 AFB00018 */  sw        $s0, 0x18($sp)
/* CE670C 8024000C 8C900084 */  lw        $s0, 0x84($a0)
/* CE6710 80240010 C6000008 */  lwc1      $f0, 8($s0)
/* CE6714 80240014 240400A2 */  addiu     $a0, $zero, 0xa2
/* CE6718 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* CE671C 8024001C 8E060000 */  lw        $a2, ($s0)
/* CE6720 80240020 8E070004 */  lw        $a3, 4($s0)
/* CE6724 80240024 0C05267B */  jal       sfx_adjust_env_sound_pos
/* CE6728 80240028 0000282D */   daddu    $a1, $zero, $zero
/* CE672C 8024002C 86020044 */  lh        $v0, 0x44($s0)
/* CE6730 80240030 8FBF001C */  lw        $ra, 0x1c($sp)
/* CE6734 80240034 8FB00018 */  lw        $s0, 0x18($sp)
/* CE6738 80240038 28420002 */  slti      $v0, $v0, 2
/* CE673C 8024003C 38420001 */  xori      $v0, $v0, 1
/* CE6740 80240040 00021040 */  sll       $v0, $v0, 1
/* CE6744 80240044 03E00008 */  jr        $ra
/* CE6748 80240048 27BD0020 */   addiu    $sp, $sp, 0x20
