.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_DAD7A0
/* DAD7A0 802403A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DAD7A4 802403A4 AFB3002C */  sw        $s3, 0x2c($sp)
/* DAD7A8 802403A8 0080982D */  daddu     $s3, $a0, $zero
/* DAD7AC 802403AC AFBF0030 */  sw        $ra, 0x30($sp)
/* DAD7B0 802403B0 AFB20028 */  sw        $s2, 0x28($sp)
/* DAD7B4 802403B4 AFB10024 */  sw        $s1, 0x24($sp)
/* DAD7B8 802403B8 AFB00020 */  sw        $s0, 0x20($sp)
/* DAD7BC 802403BC 8E710148 */  lw        $s1, 0x148($s3)
/* DAD7C0 802403C0 86240008 */  lh        $a0, 8($s1)
/* DAD7C4 802403C4 0C00EABB */  jal       get_npc_unsafe
/* DAD7C8 802403C8 00A0902D */   daddu    $s2, $a1, $zero
/* DAD7CC 802403CC 8E440004 */  lw        $a0, 4($s2)
/* DAD7D0 802403D0 0040802D */  daddu     $s0, $v0, $zero
/* DAD7D4 802403D4 00041FC2 */  srl       $v1, $a0, 0x1f
/* DAD7D8 802403D8 00832021 */  addu      $a0, $a0, $v1
/* DAD7DC 802403DC 00042043 */  sra       $a0, $a0, 1
/* DAD7E0 802403E0 0C00A67F */  jal       rand_int
/* DAD7E4 802403E4 24840001 */   addiu    $a0, $a0, 1
/* DAD7E8 802403E8 8E430004 */  lw        $v1, 4($s2)
/* DAD7EC 802403EC 000327C2 */  srl       $a0, $v1, 0x1f
/* DAD7F0 802403F0 00641821 */  addu      $v1, $v1, $a0
/* DAD7F4 802403F4 00031843 */  sra       $v1, $v1, 1
/* DAD7F8 802403F8 00621821 */  addu      $v1, $v1, $v0
/* DAD7FC 802403FC A603008E */  sh        $v1, 0x8e($s0)
/* DAD800 80240400 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DAD804 80240404 C6000040 */  lwc1      $f0, 0x40($s0)
/* DAD808 80240408 C4640000 */  lwc1      $f4, ($v1)
/* DAD80C 8024040C 46802120 */  cvt.s.w   $f4, $f4
/* DAD810 80240410 C4620008 */  lwc1      $f2, 8($v1)
/* DAD814 80240414 468010A0 */  cvt.s.w   $f2, $f2
/* DAD818 80240418 E7A00010 */  swc1      $f0, 0x10($sp)
/* DAD81C 8024041C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DAD820 80240420 44061000 */  mfc1      $a2, $f2
/* DAD824 80240424 C440000C */  lwc1      $f0, 0xc($v0)
/* DAD828 80240428 46800020 */  cvt.s.w   $f0, $f0
/* DAD82C 8024042C E7A00014 */  swc1      $f0, 0x14($sp)
/* DAD830 80240430 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DAD834 80240434 44052000 */  mfc1      $a1, $f4
/* DAD838 80240438 C4400010 */  lwc1      $f0, 0x10($v0)
/* DAD83C 8024043C 46800020 */  cvt.s.w   $f0, $f0
/* DAD840 80240440 E7A00018 */  swc1      $f0, 0x18($sp)
/* DAD844 80240444 8C640018 */  lw        $a0, 0x18($v1)
/* DAD848 80240448 0C0123F5 */  jal       is_point_within_region
/* DAD84C 8024044C 8E070038 */   lw       $a3, 0x38($s0)
/* DAD850 80240450 1040000E */  beqz      $v0, .L8024048C
/* DAD854 80240454 00000000 */   nop      
/* DAD858 80240458 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DAD85C 8024045C C60C0038 */  lwc1      $f12, 0x38($s0)
/* DAD860 80240460 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DAD864 80240464 C4460000 */  lwc1      $f6, ($v0)
/* DAD868 80240468 468031A0 */  cvt.s.w   $f6, $f6
/* DAD86C 8024046C 44063000 */  mfc1      $a2, $f6
/* DAD870 80240470 C4460008 */  lwc1      $f6, 8($v0)
/* DAD874 80240474 468031A0 */  cvt.s.w   $f6, $f6
/* DAD878 80240478 44073000 */  mfc1      $a3, $f6
/* DAD87C 8024047C 0C00A720 */  jal       atan2
/* DAD880 80240480 00000000 */   nop      
/* DAD884 80240484 0809012F */  j         .L802404BC
/* DAD888 80240488 E600000C */   swc1     $f0, 0xc($s0)
.L8024048C:
/* DAD88C 8024048C 0C00A67F */  jal       rand_int
/* DAD890 80240490 2404003C */   addiu    $a0, $zero, 0x3c
/* DAD894 80240494 C60C000C */  lwc1      $f12, 0xc($s0)
/* DAD898 80240498 44820000 */  mtc1      $v0, $f0
/* DAD89C 8024049C 00000000 */  nop       
/* DAD8A0 802404A0 46800020 */  cvt.s.w   $f0, $f0
/* DAD8A4 802404A4 46006300 */  add.s     $f12, $f12, $f0
/* DAD8A8 802404A8 3C0141F0 */  lui       $at, 0x41f0
/* DAD8AC 802404AC 44810000 */  mtc1      $at, $f0
/* DAD8B0 802404B0 0C00A6C9 */  jal       clamp_angle
/* DAD8B4 802404B4 46006301 */   sub.s    $f12, $f12, $f0
/* DAD8B8 802404B8 E600000C */  swc1      $f0, 0xc($s0)
.L802404BC:
/* DAD8BC 802404BC 8E2200CC */  lw        $v0, 0xcc($s1)
/* DAD8C0 802404C0 8C420004 */  lw        $v0, 4($v0)
/* DAD8C4 802404C4 AE020028 */  sw        $v0, 0x28($s0)
/* DAD8C8 802404C8 AE600074 */  sw        $zero, 0x74($s3)
/* DAD8CC 802404CC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DAD8D0 802404D0 8C420014 */  lw        $v0, 0x14($v0)
/* DAD8D4 802404D4 04410004 */  bgez      $v0, .L802404E8
/* DAD8D8 802404D8 00000000 */   nop      
/* DAD8DC 802404DC C6400000 */  lwc1      $f0, ($s2)
/* DAD8E0 802404E0 08090142 */  j         .L80240508
/* DAD8E4 802404E4 E6000018 */   swc1     $f0, 0x18($s0)
.L802404E8:
/* DAD8E8 802404E8 3C018024 */  lui       $at, 0x8024
/* DAD8EC 802404EC D4224CB0 */  ldc1      $f2, 0x4cb0($at)
/* DAD8F0 802404F0 44820000 */  mtc1      $v0, $f0
/* DAD8F4 802404F4 00000000 */  nop       
/* DAD8F8 802404F8 46800021 */  cvt.d.w   $f0, $f0
/* DAD8FC 802404FC 46220003 */  div.d     $f0, $f0, $f2
/* DAD900 80240500 46200020 */  cvt.s.d   $f0, $f0
/* DAD904 80240504 E6000018 */  swc1      $f0, 0x18($s0)
.L80240508:
/* DAD908 80240508 C600003C */  lwc1      $f0, 0x3c($s0)
/* DAD90C 8024050C 3C014059 */  lui       $at, 0x4059
/* DAD910 80240510 44811800 */  mtc1      $at, $f3
/* DAD914 80240514 44801000 */  mtc1      $zero, $f2
/* DAD918 80240518 46000021 */  cvt.d.s   $f0, $f0
/* DAD91C 8024051C 46220002 */  mul.d     $f0, $f0, $f2
/* DAD920 80240520 00000000 */  nop       
/* DAD924 80240524 24020001 */  addiu     $v0, $zero, 1
/* DAD928 80240528 4620018D */  trunc.w.d $f6, $f0
/* DAD92C 8024052C E626007C */  swc1      $f6, 0x7c($s1)
/* DAD930 80240530 AE620070 */  sw        $v0, 0x70($s3)
/* DAD934 80240534 8FBF0030 */  lw        $ra, 0x30($sp)
/* DAD938 80240538 8FB3002C */  lw        $s3, 0x2c($sp)
/* DAD93C 8024053C 8FB20028 */  lw        $s2, 0x28($sp)
/* DAD940 80240540 8FB10024 */  lw        $s1, 0x24($sp)
/* DAD944 80240544 8FB00020 */  lw        $s0, 0x20($sp)
/* DAD948 80240548 03E00008 */  jr        $ra
/* DAD94C 8024054C 27BD0038 */   addiu    $sp, $sp, 0x38
