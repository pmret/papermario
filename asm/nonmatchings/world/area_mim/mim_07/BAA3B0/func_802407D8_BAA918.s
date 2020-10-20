.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D8_BAA918
/* BAA918 802407D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BAA91C 802407DC AFB3001C */  sw        $s3, 0x1c($sp)
/* BAA920 802407E0 0080982D */  daddu     $s3, $a0, $zero
/* BAA924 802407E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* BAA928 802407E8 AFB20018 */  sw        $s2, 0x18($sp)
/* BAA92C 802407EC AFB10014 */  sw        $s1, 0x14($sp)
/* BAA930 802407F0 AFB00010 */  sw        $s0, 0x10($sp)
/* BAA934 802407F4 8E720148 */  lw        $s2, 0x148($s3)
/* BAA938 802407F8 86440008 */  lh        $a0, 8($s2)
/* BAA93C 802407FC 0C00EABB */  jal       get_npc_unsafe
/* BAA940 80240800 00A0882D */   daddu    $s1, $a1, $zero
/* BAA944 80240804 8E240008 */  lw        $a0, 8($s1)
/* BAA948 80240808 0040802D */  daddu     $s0, $v0, $zero
/* BAA94C 8024080C 00041FC2 */  srl       $v1, $a0, 0x1f
/* BAA950 80240810 00832021 */  addu      $a0, $a0, $v1
/* BAA954 80240814 00042043 */  sra       $a0, $a0, 1
/* BAA958 80240818 0C00A67F */  jal       rand_int
/* BAA95C 8024081C 24840001 */   addiu    $a0, $a0, 1
/* BAA960 80240820 8E230008 */  lw        $v1, 8($s1)
/* BAA964 80240824 240400B4 */  addiu     $a0, $zero, 0xb4
/* BAA968 80240828 00032FC2 */  srl       $a1, $v1, 0x1f
/* BAA96C 8024082C 00651821 */  addu      $v1, $v1, $a1
/* BAA970 80240830 00031843 */  sra       $v1, $v1, 1
/* BAA974 80240834 00621821 */  addu      $v1, $v1, $v0
/* BAA978 80240838 0C00A67F */  jal       rand_int
/* BAA97C 8024083C A603008E */   sh       $v1, 0x8e($s0)
/* BAA980 80240840 C60C000C */  lwc1      $f12, 0xc($s0)
/* BAA984 80240844 44820000 */  mtc1      $v0, $f0
/* BAA988 80240848 00000000 */  nop       
/* BAA98C 8024084C 46800020 */  cvt.s.w   $f0, $f0
/* BAA990 80240850 46006300 */  add.s     $f12, $f12, $f0
/* BAA994 80240854 3C0142B4 */  lui       $at, 0x42b4
/* BAA998 80240858 44810000 */  mtc1      $at, $f0
/* BAA99C 8024085C 0C00A6C9 */  jal       clamp_angle
/* BAA9A0 80240860 46006301 */   sub.s    $f12, $f12, $f0
/* BAA9A4 80240864 E600000C */  swc1      $f0, 0xc($s0)
/* BAA9A8 80240868 8E4200CC */  lw        $v0, 0xcc($s2)
/* BAA9AC 8024086C 8C420000 */  lw        $v0, ($v0)
/* BAA9B0 80240870 AE020028 */  sw        $v0, 0x28($s0)
/* BAA9B4 80240874 24020003 */  addiu     $v0, $zero, 3
/* BAA9B8 80240878 AE620070 */  sw        $v0, 0x70($s3)
/* BAA9BC 8024087C 8FBF0020 */  lw        $ra, 0x20($sp)
/* BAA9C0 80240880 8FB3001C */  lw        $s3, 0x1c($sp)
/* BAA9C4 80240884 8FB20018 */  lw        $s2, 0x18($sp)
/* BAA9C8 80240888 8FB10014 */  lw        $s1, 0x14($sp)
/* BAA9CC 8024088C 8FB00010 */  lw        $s0, 0x10($sp)
/* BAA9D0 80240890 03E00008 */  jr        $ra
/* BAA9D4 80240894 27BD0028 */   addiu    $sp, $sp, 0x28
