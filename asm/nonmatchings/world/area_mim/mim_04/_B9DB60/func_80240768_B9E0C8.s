.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240768_B9E0C8
/* B9E0C8 80240768 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B9E0CC 8024076C AFB3001C */  sw        $s3, 0x1c($sp)
/* B9E0D0 80240770 0080982D */  daddu     $s3, $a0, $zero
/* B9E0D4 80240774 AFBF0020 */  sw        $ra, 0x20($sp)
/* B9E0D8 80240778 AFB20018 */  sw        $s2, 0x18($sp)
/* B9E0DC 8024077C AFB10014 */  sw        $s1, 0x14($sp)
/* B9E0E0 80240780 AFB00010 */  sw        $s0, 0x10($sp)
/* B9E0E4 80240784 8E720148 */  lw        $s2, 0x148($s3)
/* B9E0E8 80240788 86440008 */  lh        $a0, 8($s2)
/* B9E0EC 8024078C 0C00EABB */  jal       get_npc_unsafe
/* B9E0F0 80240790 00A0882D */   daddu    $s1, $a1, $zero
/* B9E0F4 80240794 8E240008 */  lw        $a0, 8($s1)
/* B9E0F8 80240798 0040802D */  daddu     $s0, $v0, $zero
/* B9E0FC 8024079C 00041FC2 */  srl       $v1, $a0, 0x1f
/* B9E100 802407A0 00832021 */  addu      $a0, $a0, $v1
/* B9E104 802407A4 00042043 */  sra       $a0, $a0, 1
/* B9E108 802407A8 0C00A67F */  jal       rand_int
/* B9E10C 802407AC 24840001 */   addiu    $a0, $a0, 1
/* B9E110 802407B0 8E230008 */  lw        $v1, 8($s1)
/* B9E114 802407B4 240400B4 */  addiu     $a0, $zero, 0xb4
/* B9E118 802407B8 00032FC2 */  srl       $a1, $v1, 0x1f
/* B9E11C 802407BC 00651821 */  addu      $v1, $v1, $a1
/* B9E120 802407C0 00031843 */  sra       $v1, $v1, 1
/* B9E124 802407C4 00621821 */  addu      $v1, $v1, $v0
/* B9E128 802407C8 0C00A67F */  jal       rand_int
/* B9E12C 802407CC A603008E */   sh       $v1, 0x8e($s0)
/* B9E130 802407D0 C60C000C */  lwc1      $f12, 0xc($s0)
/* B9E134 802407D4 44820000 */  mtc1      $v0, $f0
/* B9E138 802407D8 00000000 */  nop       
/* B9E13C 802407DC 46800020 */  cvt.s.w   $f0, $f0
/* B9E140 802407E0 46006300 */  add.s     $f12, $f12, $f0
/* B9E144 802407E4 3C0142B4 */  lui       $at, 0x42b4
/* B9E148 802407E8 44810000 */  mtc1      $at, $f0
/* B9E14C 802407EC 0C00A6C9 */  jal       clamp_angle
/* B9E150 802407F0 46006301 */   sub.s    $f12, $f12, $f0
/* B9E154 802407F4 E600000C */  swc1      $f0, 0xc($s0)
/* B9E158 802407F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* B9E15C 802407FC 8C420000 */  lw        $v0, ($v0)
/* B9E160 80240800 AE020028 */  sw        $v0, 0x28($s0)
/* B9E164 80240804 24020003 */  addiu     $v0, $zero, 3
/* B9E168 80240808 AE620070 */  sw        $v0, 0x70($s3)
/* B9E16C 8024080C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B9E170 80240810 8FB3001C */  lw        $s3, 0x1c($sp)
/* B9E174 80240814 8FB20018 */  lw        $s2, 0x18($sp)
/* B9E178 80240818 8FB10014 */  lw        $s1, 0x14($sp)
/* B9E17C 8024081C 8FB00010 */  lw        $s0, 0x10($sp)
/* B9E180 80240820 03E00008 */  jr        $ra
/* B9E184 80240824 27BD0028 */   addiu    $sp, $sp, 0x28
