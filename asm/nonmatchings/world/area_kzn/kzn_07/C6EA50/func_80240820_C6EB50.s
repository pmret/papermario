.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240820_C6EB50
/* C6EB50 80240820 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C6EB54 80240824 AFB3002C */  sw        $s3, 0x2c($sp)
/* C6EB58 80240828 0080982D */  daddu     $s3, $a0, $zero
/* C6EB5C 8024082C AFBF0030 */  sw        $ra, 0x30($sp)
/* C6EB60 80240830 AFB20028 */  sw        $s2, 0x28($sp)
/* C6EB64 80240834 AFB10024 */  sw        $s1, 0x24($sp)
/* C6EB68 80240838 AFB00020 */  sw        $s0, 0x20($sp)
/* C6EB6C 8024083C 8E710148 */  lw        $s1, 0x148($s3)
/* C6EB70 80240840 86240008 */  lh        $a0, 8($s1)
/* C6EB74 80240844 0C00EABB */  jal       get_npc_unsafe
/* C6EB78 80240848 00A0902D */   daddu    $s2, $a1, $zero
/* C6EB7C 8024084C 8E440004 */  lw        $a0, 4($s2)
/* C6EB80 80240850 0040802D */  daddu     $s0, $v0, $zero
/* C6EB84 80240854 00041FC2 */  srl       $v1, $a0, 0x1f
/* C6EB88 80240858 00832021 */  addu      $a0, $a0, $v1
/* C6EB8C 8024085C 00042043 */  sra       $a0, $a0, 1
/* C6EB90 80240860 0C00A67F */  jal       rand_int
/* C6EB94 80240864 24840001 */   addiu    $a0, $a0, 1
/* C6EB98 80240868 8E430004 */  lw        $v1, 4($s2)
/* C6EB9C 8024086C 000327C2 */  srl       $a0, $v1, 0x1f
/* C6EBA0 80240870 00641821 */  addu      $v1, $v1, $a0
/* C6EBA4 80240874 00031843 */  sra       $v1, $v1, 1
/* C6EBA8 80240878 00621821 */  addu      $v1, $v1, $v0
/* C6EBAC 8024087C A603008E */  sh        $v1, 0x8e($s0)
/* C6EBB0 80240880 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C6EBB4 80240884 C6000040 */  lwc1      $f0, 0x40($s0)
/* C6EBB8 80240888 C4640000 */  lwc1      $f4, ($v1)
/* C6EBBC 8024088C 46802120 */  cvt.s.w   $f4, $f4
/* C6EBC0 80240890 C4620008 */  lwc1      $f2, 8($v1)
/* C6EBC4 80240894 468010A0 */  cvt.s.w   $f2, $f2
/* C6EBC8 80240898 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6EBCC 8024089C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6EBD0 802408A0 44061000 */  mfc1      $a2, $f2
/* C6EBD4 802408A4 C440000C */  lwc1      $f0, 0xc($v0)
/* C6EBD8 802408A8 46800020 */  cvt.s.w   $f0, $f0
/* C6EBDC 802408AC E7A00014 */  swc1      $f0, 0x14($sp)
/* C6EBE0 802408B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6EBE4 802408B4 44052000 */  mfc1      $a1, $f4
/* C6EBE8 802408B8 C4400010 */  lwc1      $f0, 0x10($v0)
/* C6EBEC 802408BC 46800020 */  cvt.s.w   $f0, $f0
/* C6EBF0 802408C0 E7A00018 */  swc1      $f0, 0x18($sp)
/* C6EBF4 802408C4 8C640018 */  lw        $a0, 0x18($v1)
/* C6EBF8 802408C8 0C0123F5 */  jal       is_point_within_region
/* C6EBFC 802408CC 8E070038 */   lw       $a3, 0x38($s0)
/* C6EC00 802408D0 1040000E */  beqz      $v0, .L8024090C
/* C6EC04 802408D4 00000000 */   nop      
/* C6EC08 802408D8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6EC0C 802408DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C6EC10 802408E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C6EC14 802408E4 C4460000 */  lwc1      $f6, ($v0)
/* C6EC18 802408E8 468031A0 */  cvt.s.w   $f6, $f6
/* C6EC1C 802408EC 44063000 */  mfc1      $a2, $f6
/* C6EC20 802408F0 C4460008 */  lwc1      $f6, 8($v0)
/* C6EC24 802408F4 468031A0 */  cvt.s.w   $f6, $f6
/* C6EC28 802408F8 44073000 */  mfc1      $a3, $f6
/* C6EC2C 802408FC 0C00A720 */  jal       atan2
/* C6EC30 80240900 00000000 */   nop      
/* C6EC34 80240904 0809024F */  j         .L8024093C
/* C6EC38 80240908 E600000C */   swc1     $f0, 0xc($s0)
.L8024090C:
/* C6EC3C 8024090C 0C00A67F */  jal       rand_int
/* C6EC40 80240910 2404003C */   addiu    $a0, $zero, 0x3c
/* C6EC44 80240914 C60C000C */  lwc1      $f12, 0xc($s0)
/* C6EC48 80240918 44820000 */  mtc1      $v0, $f0
/* C6EC4C 8024091C 00000000 */  nop       
/* C6EC50 80240920 46800020 */  cvt.s.w   $f0, $f0
/* C6EC54 80240924 46006300 */  add.s     $f12, $f12, $f0
/* C6EC58 80240928 3C0141F0 */  lui       $at, 0x41f0
/* C6EC5C 8024092C 44810000 */  mtc1      $at, $f0
/* C6EC60 80240930 0C00A6C9 */  jal       clamp_angle
/* C6EC64 80240934 46006301 */   sub.s    $f12, $f12, $f0
/* C6EC68 80240938 E600000C */  swc1      $f0, 0xc($s0)
.L8024093C:
/* C6EC6C 8024093C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C6EC70 80240940 8C420004 */  lw        $v0, 4($v0)
/* C6EC74 80240944 AE020028 */  sw        $v0, 0x28($s0)
/* C6EC78 80240948 AE600074 */  sw        $zero, 0x74($s3)
/* C6EC7C 8024094C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6EC80 80240950 8C420014 */  lw        $v0, 0x14($v0)
/* C6EC84 80240954 04410004 */  bgez      $v0, .L80240968
/* C6EC88 80240958 00000000 */   nop      
/* C6EC8C 8024095C C6400000 */  lwc1      $f0, ($s2)
/* C6EC90 80240960 08090262 */  j         .L80240988
/* C6EC94 80240964 E6000018 */   swc1     $f0, 0x18($s0)
.L80240968:
/* C6EC98 80240968 3C018024 */  lui       $at, %hi(func_80243090_C395C0)
/* C6EC9C 8024096C D4223090 */  ldc1      $f2, %lo(func_80243090_C395C0)($at)
/* C6ECA0 80240970 44820000 */  mtc1      $v0, $f0
/* C6ECA4 80240974 00000000 */  nop       
/* C6ECA8 80240978 46800021 */  cvt.d.w   $f0, $f0
/* C6ECAC 8024097C 46220003 */  div.d     $f0, $f0, $f2
/* C6ECB0 80240980 46200020 */  cvt.s.d   $f0, $f0
/* C6ECB4 80240984 E6000018 */  swc1      $f0, 0x18($s0)
.L80240988:
/* C6ECB8 80240988 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6ECBC 8024098C 3C014059 */  lui       $at, 0x4059
/* C6ECC0 80240990 44811800 */  mtc1      $at, $f3
/* C6ECC4 80240994 44801000 */  mtc1      $zero, $f2
/* C6ECC8 80240998 46000021 */  cvt.d.s   $f0, $f0
/* C6ECCC 8024099C 46220002 */  mul.d     $f0, $f0, $f2
/* C6ECD0 802409A0 00000000 */  nop       
/* C6ECD4 802409A4 24020001 */  addiu     $v0, $zero, 1
/* C6ECD8 802409A8 4620018D */  trunc.w.d $f6, $f0
/* C6ECDC 802409AC E626007C */  swc1      $f6, 0x7c($s1)
/* C6ECE0 802409B0 AE620070 */  sw        $v0, 0x70($s3)
/* C6ECE4 802409B4 8FBF0030 */  lw        $ra, 0x30($sp)
/* C6ECE8 802409B8 8FB3002C */  lw        $s3, 0x2c($sp)
/* C6ECEC 802409BC 8FB20028 */  lw        $s2, 0x28($sp)
/* C6ECF0 802409C0 8FB10024 */  lw        $s1, 0x24($sp)
/* C6ECF4 802409C4 8FB00020 */  lw        $s0, 0x20($sp)
/* C6ECF8 802409C8 03E00008 */  jr        $ra
/* C6ECFC 802409CC 27BD0038 */   addiu    $sp, $sp, 0x38
