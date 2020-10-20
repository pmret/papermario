.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D8_8D1CE8
/* 8D1CE8 802407D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8D1CEC 802407DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 8D1CF0 802407E0 0080982D */  daddu     $s3, $a0, $zero
/* 8D1CF4 802407E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8D1CF8 802407E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D1CFC 802407EC AFB10014 */  sw        $s1, 0x14($sp)
/* 8D1D00 802407F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D1D04 802407F4 8E720148 */  lw        $s2, 0x148($s3)
/* 8D1D08 802407F8 86440008 */  lh        $a0, 8($s2)
/* 8D1D0C 802407FC 0C00EABB */  jal       get_npc_unsafe
/* 8D1D10 80240800 00A0882D */   daddu    $s1, $a1, $zero
/* 8D1D14 80240804 8E240008 */  lw        $a0, 8($s1)
/* 8D1D18 80240808 0040802D */  daddu     $s0, $v0, $zero
/* 8D1D1C 8024080C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 8D1D20 80240810 00832021 */  addu      $a0, $a0, $v1
/* 8D1D24 80240814 00042043 */  sra       $a0, $a0, 1
/* 8D1D28 80240818 0C00A67F */  jal       rand_int
/* 8D1D2C 8024081C 24840001 */   addiu    $a0, $a0, 1
/* 8D1D30 80240820 8E230008 */  lw        $v1, 8($s1)
/* 8D1D34 80240824 240400B4 */  addiu     $a0, $zero, 0xb4
/* 8D1D38 80240828 00032FC2 */  srl       $a1, $v1, 0x1f
/* 8D1D3C 8024082C 00651821 */  addu      $v1, $v1, $a1
/* 8D1D40 80240830 00031843 */  sra       $v1, $v1, 1
/* 8D1D44 80240834 00621821 */  addu      $v1, $v1, $v0
/* 8D1D48 80240838 0C00A67F */  jal       rand_int
/* 8D1D4C 8024083C A603008E */   sh       $v1, 0x8e($s0)
/* 8D1D50 80240840 C60C000C */  lwc1      $f12, 0xc($s0)
/* 8D1D54 80240844 44820000 */  mtc1      $v0, $f0
/* 8D1D58 80240848 00000000 */  nop       
/* 8D1D5C 8024084C 46800020 */  cvt.s.w   $f0, $f0
/* 8D1D60 80240850 46006300 */  add.s     $f12, $f12, $f0
/* 8D1D64 80240854 3C0142B4 */  lui       $at, 0x42b4
/* 8D1D68 80240858 44810000 */  mtc1      $at, $f0
/* 8D1D6C 8024085C 0C00A6C9 */  jal       clamp_angle
/* 8D1D70 80240860 46006301 */   sub.s    $f12, $f12, $f0
/* 8D1D74 80240864 E600000C */  swc1      $f0, 0xc($s0)
/* 8D1D78 80240868 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8D1D7C 8024086C 8C420000 */  lw        $v0, ($v0)
/* 8D1D80 80240870 AE020028 */  sw        $v0, 0x28($s0)
/* 8D1D84 80240874 24020003 */  addiu     $v0, $zero, 3
/* 8D1D88 80240878 AE620070 */  sw        $v0, 0x70($s3)
/* 8D1D8C 8024087C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8D1D90 80240880 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8D1D94 80240884 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D1D98 80240888 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D1D9C 8024088C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D1DA0 80240890 03E00008 */  jr        $ra
/* 8D1DA4 80240894 27BD0028 */   addiu    $sp, $sp, 0x28
