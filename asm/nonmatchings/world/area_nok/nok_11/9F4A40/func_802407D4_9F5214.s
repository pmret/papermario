.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D4_9F5214
/* 9F5214 802407D4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9F5218 802407D8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 9F521C 802407DC 0080982D */  daddu     $s3, $a0, $zero
/* 9F5220 802407E0 AFBF0030 */  sw        $ra, 0x30($sp)
/* 9F5224 802407E4 AFB20028 */  sw        $s2, 0x28($sp)
/* 9F5228 802407E8 AFB10024 */  sw        $s1, 0x24($sp)
/* 9F522C 802407EC AFB00020 */  sw        $s0, 0x20($sp)
/* 9F5230 802407F0 8E710148 */  lw        $s1, 0x148($s3)
/* 9F5234 802407F4 86240008 */  lh        $a0, 8($s1)
/* 9F5238 802407F8 0C00EABB */  jal       get_npc_unsafe
/* 9F523C 802407FC 00A0902D */   daddu    $s2, $a1, $zero
/* 9F5240 80240800 8E440004 */  lw        $a0, 4($s2)
/* 9F5244 80240804 0040802D */  daddu     $s0, $v0, $zero
/* 9F5248 80240808 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9F524C 8024080C 00832021 */  addu      $a0, $a0, $v1
/* 9F5250 80240810 00042043 */  sra       $a0, $a0, 1
/* 9F5254 80240814 0C00A67F */  jal       rand_int
/* 9F5258 80240818 24840001 */   addiu    $a0, $a0, 1
/* 9F525C 8024081C 8E430004 */  lw        $v1, 4($s2)
/* 9F5260 80240820 000327C2 */  srl       $a0, $v1, 0x1f
/* 9F5264 80240824 00641821 */  addu      $v1, $v1, $a0
/* 9F5268 80240828 00031843 */  sra       $v1, $v1, 1
/* 9F526C 8024082C 00621821 */  addu      $v1, $v1, $v0
/* 9F5270 80240830 A603008E */  sh        $v1, 0x8e($s0)
/* 9F5274 80240834 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9F5278 80240838 C6000040 */  lwc1      $f0, 0x40($s0)
/* 9F527C 8024083C C4640000 */  lwc1      $f4, ($v1)
/* 9F5280 80240840 46802120 */  cvt.s.w   $f4, $f4
/* 9F5284 80240844 C4620008 */  lwc1      $f2, 8($v1)
/* 9F5288 80240848 468010A0 */  cvt.s.w   $f2, $f2
/* 9F528C 8024084C E7A00010 */  swc1      $f0, 0x10($sp)
/* 9F5290 80240850 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9F5294 80240854 44061000 */  mfc1      $a2, $f2
/* 9F5298 80240858 C440000C */  lwc1      $f0, 0xc($v0)
/* 9F529C 8024085C 46800020 */  cvt.s.w   $f0, $f0
/* 9F52A0 80240860 E7A00014 */  swc1      $f0, 0x14($sp)
/* 9F52A4 80240864 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9F52A8 80240868 44052000 */  mfc1      $a1, $f4
/* 9F52AC 8024086C C4400010 */  lwc1      $f0, 0x10($v0)
/* 9F52B0 80240870 46800020 */  cvt.s.w   $f0, $f0
/* 9F52B4 80240874 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9F52B8 80240878 8C640018 */  lw        $a0, 0x18($v1)
/* 9F52BC 8024087C 0C0123F5 */  jal       is_point_within_region
/* 9F52C0 80240880 8E070038 */   lw       $a3, 0x38($s0)
/* 9F52C4 80240884 1040000E */  beqz      $v0, .L802408C0
/* 9F52C8 80240888 00000000 */   nop
/* 9F52CC 8024088C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9F52D0 80240890 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9F52D4 80240894 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9F52D8 80240898 C4460000 */  lwc1      $f6, ($v0)
/* 9F52DC 8024089C 468031A0 */  cvt.s.w   $f6, $f6
/* 9F52E0 802408A0 44063000 */  mfc1      $a2, $f6
/* 9F52E4 802408A4 C4460008 */  lwc1      $f6, 8($v0)
/* 9F52E8 802408A8 468031A0 */  cvt.s.w   $f6, $f6
/* 9F52EC 802408AC 44073000 */  mfc1      $a3, $f6
/* 9F52F0 802408B0 0C00A720 */  jal       atan2
/* 9F52F4 802408B4 00000000 */   nop
/* 9F52F8 802408B8 0809023C */  j         .L802408F0
/* 9F52FC 802408BC E600000C */   swc1     $f0, 0xc($s0)
.L802408C0:
/* 9F5300 802408C0 0C00A67F */  jal       rand_int
/* 9F5304 802408C4 2404003C */   addiu    $a0, $zero, 0x3c
/* 9F5308 802408C8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9F530C 802408CC 44820000 */  mtc1      $v0, $f0
/* 9F5310 802408D0 00000000 */  nop
/* 9F5314 802408D4 46800020 */  cvt.s.w   $f0, $f0
/* 9F5318 802408D8 46006300 */  add.s     $f12, $f12, $f0
/* 9F531C 802408DC 3C0141F0 */  lui       $at, 0x41f0
/* 9F5320 802408E0 44810000 */  mtc1      $at, $f0
/* 9F5324 802408E4 0C00A6C9 */  jal       clamp_angle
/* 9F5328 802408E8 46006301 */   sub.s    $f12, $f12, $f0
/* 9F532C 802408EC E600000C */  swc1      $f0, 0xc($s0)
.L802408F0:
/* 9F5330 802408F0 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9F5334 802408F4 8C420004 */  lw        $v0, 4($v0)
/* 9F5338 802408F8 AE020028 */  sw        $v0, 0x28($s0)
/* 9F533C 802408FC AE600074 */  sw        $zero, 0x74($s3)
/* 9F5340 80240900 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9F5344 80240904 8C420014 */  lw        $v0, 0x14($v0)
/* 9F5348 80240908 04410004 */  bgez      $v0, .L8024091C
/* 9F534C 8024090C 00000000 */   nop
/* 9F5350 80240910 C6400000 */  lwc1      $f0, ($s2)
/* 9F5354 80240914 0809024F */  j         .L8024093C
/* 9F5358 80240918 E6000018 */   swc1     $f0, 0x18($s0)
.L8024091C:
/* 9F535C 8024091C 3C018024 */  lui       $at, %hi(D_80245D50)
/* 9F5360 80240920 D4225D50 */  ldc1      $f2, %lo(D_80245D50)($at)
/* 9F5364 80240924 44820000 */  mtc1      $v0, $f0
/* 9F5368 80240928 00000000 */  nop
/* 9F536C 8024092C 46800021 */  cvt.d.w   $f0, $f0
/* 9F5370 80240930 46220003 */  div.d     $f0, $f0, $f2
/* 9F5374 80240934 46200020 */  cvt.s.d   $f0, $f0
/* 9F5378 80240938 E6000018 */  swc1      $f0, 0x18($s0)
.L8024093C:
/* 9F537C 8024093C C600003C */  lwc1      $f0, 0x3c($s0)
/* 9F5380 80240940 3C014059 */  lui       $at, 0x4059
/* 9F5384 80240944 44811800 */  mtc1      $at, $f3
/* 9F5388 80240948 44801000 */  mtc1      $zero, $f2
/* 9F538C 8024094C 46000021 */  cvt.d.s   $f0, $f0
/* 9F5390 80240950 46220002 */  mul.d     $f0, $f0, $f2
/* 9F5394 80240954 00000000 */  nop
/* 9F5398 80240958 24020001 */  addiu     $v0, $zero, 1
/* 9F539C 8024095C 4620018D */  trunc.w.d $f6, $f0
/* 9F53A0 80240960 E626007C */  swc1      $f6, 0x7c($s1)
/* 9F53A4 80240964 AE620070 */  sw        $v0, 0x70($s3)
/* 9F53A8 80240968 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9F53AC 8024096C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 9F53B0 80240970 8FB20028 */  lw        $s2, 0x28($sp)
/* 9F53B4 80240974 8FB10024 */  lw        $s1, 0x24($sp)
/* 9F53B8 80240978 8FB00020 */  lw        $s0, 0x20($sp)
/* 9F53BC 8024097C 03E00008 */  jr        $ra
/* 9F53C0 80240980 27BD0038 */   addiu    $sp, $sp, 0x38
