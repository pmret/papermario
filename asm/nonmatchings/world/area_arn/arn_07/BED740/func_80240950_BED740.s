.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240950_BED740
/* BED740 80240950 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BED744 80240954 AFB3002C */  sw        $s3, 0x2c($sp)
/* BED748 80240958 0080982D */  daddu     $s3, $a0, $zero
/* BED74C 8024095C AFBF0030 */  sw        $ra, 0x30($sp)
/* BED750 80240960 AFB20028 */  sw        $s2, 0x28($sp)
/* BED754 80240964 AFB10024 */  sw        $s1, 0x24($sp)
/* BED758 80240968 AFB00020 */  sw        $s0, 0x20($sp)
/* BED75C 8024096C 8E710148 */  lw        $s1, 0x148($s3)
/* BED760 80240970 86240008 */  lh        $a0, 8($s1)
/* BED764 80240974 0C00EABB */  jal       get_npc_unsafe
/* BED768 80240978 00A0902D */   daddu    $s2, $a1, $zero
/* BED76C 8024097C 8E440004 */  lw        $a0, 4($s2)
/* BED770 80240980 0040802D */  daddu     $s0, $v0, $zero
/* BED774 80240984 00041FC2 */  srl       $v1, $a0, 0x1f
/* BED778 80240988 00832021 */  addu      $a0, $a0, $v1
/* BED77C 8024098C 00042043 */  sra       $a0, $a0, 1
/* BED780 80240990 0C00A67F */  jal       rand_int
/* BED784 80240994 24840001 */   addiu    $a0, $a0, 1
/* BED788 80240998 8E430004 */  lw        $v1, 4($s2)
/* BED78C 8024099C 000327C2 */  srl       $a0, $v1, 0x1f
/* BED790 802409A0 00641821 */  addu      $v1, $v1, $a0
/* BED794 802409A4 00031843 */  sra       $v1, $v1, 1
/* BED798 802409A8 00621821 */  addu      $v1, $v1, $v0
/* BED79C 802409AC A603008E */  sh        $v1, 0x8e($s0)
/* BED7A0 802409B0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BED7A4 802409B4 C6000040 */  lwc1      $f0, 0x40($s0)
/* BED7A8 802409B8 C4640000 */  lwc1      $f4, ($v1)
/* BED7AC 802409BC 46802120 */  cvt.s.w   $f4, $f4
/* BED7B0 802409C0 C4620008 */  lwc1      $f2, 8($v1)
/* BED7B4 802409C4 468010A0 */  cvt.s.w   $f2, $f2
/* BED7B8 802409C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* BED7BC 802409CC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BED7C0 802409D0 44061000 */  mfc1      $a2, $f2
/* BED7C4 802409D4 C440000C */  lwc1      $f0, 0xc($v0)
/* BED7C8 802409D8 46800020 */  cvt.s.w   $f0, $f0
/* BED7CC 802409DC E7A00014 */  swc1      $f0, 0x14($sp)
/* BED7D0 802409E0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BED7D4 802409E4 44052000 */  mfc1      $a1, $f4
/* BED7D8 802409E8 C4400010 */  lwc1      $f0, 0x10($v0)
/* BED7DC 802409EC 46800020 */  cvt.s.w   $f0, $f0
/* BED7E0 802409F0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BED7E4 802409F4 8C640018 */  lw        $a0, 0x18($v1)
/* BED7E8 802409F8 0C0123F5 */  jal       is_point_within_region
/* BED7EC 802409FC 8E070038 */   lw       $a3, 0x38($s0)
/* BED7F0 80240A00 1040000E */  beqz      $v0, .L80240A3C
/* BED7F4 80240A04 00000000 */   nop      
/* BED7F8 80240A08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BED7FC 80240A0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BED800 80240A10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BED804 80240A14 C4460000 */  lwc1      $f6, ($v0)
/* BED808 80240A18 468031A0 */  cvt.s.w   $f6, $f6
/* BED80C 80240A1C 44063000 */  mfc1      $a2, $f6
/* BED810 80240A20 C4460008 */  lwc1      $f6, 8($v0)
/* BED814 80240A24 468031A0 */  cvt.s.w   $f6, $f6
/* BED818 80240A28 44073000 */  mfc1      $a3, $f6
/* BED81C 80240A2C 0C00A720 */  jal       atan2
/* BED820 80240A30 00000000 */   nop      
/* BED824 80240A34 0809029B */  j         .L80240A6C
/* BED828 80240A38 E600000C */   swc1     $f0, 0xc($s0)
.L80240A3C:
/* BED82C 80240A3C 0C00A67F */  jal       rand_int
/* BED830 80240A40 2404003C */   addiu    $a0, $zero, 0x3c
/* BED834 80240A44 C60C000C */  lwc1      $f12, 0xc($s0)
/* BED838 80240A48 44820000 */  mtc1      $v0, $f0
/* BED83C 80240A4C 00000000 */  nop       
/* BED840 80240A50 46800020 */  cvt.s.w   $f0, $f0
/* BED844 80240A54 46006300 */  add.s     $f12, $f12, $f0
/* BED848 80240A58 3C0141F0 */  lui       $at, 0x41f0
/* BED84C 80240A5C 44810000 */  mtc1      $at, $f0
/* BED850 80240A60 0C00A6C9 */  jal       clamp_angle
/* BED854 80240A64 46006301 */   sub.s    $f12, $f12, $f0
/* BED858 80240A68 E600000C */  swc1      $f0, 0xc($s0)
.L80240A6C:
/* BED85C 80240A6C 8E2200CC */  lw        $v0, 0xcc($s1)
/* BED860 80240A70 8C420004 */  lw        $v0, 4($v0)
/* BED864 80240A74 AE020028 */  sw        $v0, 0x28($s0)
/* BED868 80240A78 AE600074 */  sw        $zero, 0x74($s3)
/* BED86C 80240A7C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BED870 80240A80 8C420014 */  lw        $v0, 0x14($v0)
/* BED874 80240A84 04410004 */  bgez      $v0, .L80240A98
/* BED878 80240A88 00000000 */   nop      
/* BED87C 80240A8C C6400000 */  lwc1      $f0, ($s2)
/* BED880 80240A90 080902AE */  j         .L80240AB8
/* BED884 80240A94 E6000018 */   swc1     $f0, 0x18($s0)
.L80240A98:
/* BED888 80240A98 3C018024 */  lui       $at, %hi(D_80247950)
/* BED88C 80240A9C D4227950 */  ldc1      $f2, %lo(D_80247950)($at)
/* BED890 80240AA0 44820000 */  mtc1      $v0, $f0
/* BED894 80240AA4 00000000 */  nop       
/* BED898 80240AA8 46800021 */  cvt.d.w   $f0, $f0
/* BED89C 80240AAC 46220003 */  div.d     $f0, $f0, $f2
/* BED8A0 80240AB0 46200020 */  cvt.s.d   $f0, $f0
/* BED8A4 80240AB4 E6000018 */  swc1      $f0, 0x18($s0)
.L80240AB8:
/* BED8A8 80240AB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* BED8AC 80240ABC 3C014059 */  lui       $at, 0x4059
/* BED8B0 80240AC0 44811800 */  mtc1      $at, $f3
/* BED8B4 80240AC4 44801000 */  mtc1      $zero, $f2
/* BED8B8 80240AC8 46000021 */  cvt.d.s   $f0, $f0
/* BED8BC 80240ACC 46220002 */  mul.d     $f0, $f0, $f2
/* BED8C0 80240AD0 00000000 */  nop       
/* BED8C4 80240AD4 24020001 */  addiu     $v0, $zero, 1
/* BED8C8 80240AD8 4620018D */  trunc.w.d $f6, $f0
/* BED8CC 80240ADC E626007C */  swc1      $f6, 0x7c($s1)
/* BED8D0 80240AE0 AE620070 */  sw        $v0, 0x70($s3)
/* BED8D4 80240AE4 8FBF0030 */  lw        $ra, 0x30($sp)
/* BED8D8 80240AE8 8FB3002C */  lw        $s3, 0x2c($sp)
/* BED8DC 80240AEC 8FB20028 */  lw        $s2, 0x28($sp)
/* BED8E0 80240AF0 8FB10024 */  lw        $s1, 0x24($sp)
/* BED8E4 80240AF4 8FB00020 */  lw        $s0, 0x20($sp)
/* BED8E8 80240AF8 03E00008 */  jr        $ra
/* BED8EC 80240AFC 27BD0038 */   addiu    $sp, $sp, 0x38
