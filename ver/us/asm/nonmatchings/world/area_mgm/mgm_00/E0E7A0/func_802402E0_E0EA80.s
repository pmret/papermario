.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_E0EA80
/* E0EA80 802402E0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* E0EA84 802402E4 AFB50024 */  sw        $s5, 0x24($sp)
/* E0EA88 802402E8 0080A82D */  daddu     $s5, $a0, $zero
/* E0EA8C 802402EC AFBF002C */  sw        $ra, 0x2c($sp)
/* E0EA90 802402F0 AFB60028 */  sw        $s6, 0x28($sp)
/* E0EA94 802402F4 AFB40020 */  sw        $s4, 0x20($sp)
/* E0EA98 802402F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* E0EA9C 802402FC AFB20018 */  sw        $s2, 0x18($sp)
/* E0EAA0 80240300 AFB10014 */  sw        $s1, 0x14($sp)
/* E0EAA4 80240304 AFB00010 */  sw        $s0, 0x10($sp)
/* E0EAA8 80240308 F7B80040 */  sdc1      $f24, 0x40($sp)
/* E0EAAC 8024030C F7B60038 */  sdc1      $f22, 0x38($sp)
/* E0EAB0 80240310 F7B40030 */  sdc1      $f20, 0x30($sp)
/* E0EAB4 80240314 8EB30148 */  lw        $s3, 0x148($s5)
/* E0EAB8 80240318 86640008 */  lh        $a0, 8($s3)
/* E0EABC 8024031C 0C00EABB */  jal       get_npc_unsafe
/* E0EAC0 80240320 00A0B02D */   daddu    $s6, $a1, $zero
/* E0EAC4 80240324 0040A02D */  daddu     $s4, $v0, $zero
/* E0EAC8 80240328 AEA00074 */  sw        $zero, 0x74($s5)
/* E0EACC 8024032C C6980038 */  lwc1      $f24, 0x38($s4)
/* E0EAD0 80240330 C6960040 */  lwc1      $f22, 0x40($s4)
/* E0EAD4 80240334 0000902D */  daddu     $s2, $zero, $zero
/* E0EAD8 80240338 AEA00078 */  sw        $zero, 0x78($s5)
/* E0EADC 8024033C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* E0EAE0 80240340 8C620000 */  lw        $v0, ($v1)
/* E0EAE4 80240344 3C0146FF */  lui       $at, 0x46ff
/* E0EAE8 80240348 3421FE00 */  ori       $at, $at, 0xfe00
/* E0EAEC 8024034C 4481A000 */  mtc1      $at, $f20
/* E0EAF0 80240350 18400018 */  blez      $v0, .L802403B4
/* E0EAF4 80240354 0240802D */   daddu    $s0, $s2, $zero
/* E0EAF8 80240358 0240882D */  daddu     $s1, $s2, $zero
.L8024035C:
/* E0EAFC 8024035C 02231021 */  addu      $v0, $s1, $v1
/* E0EB00 80240360 4600C306 */  mov.s     $f12, $f24
/* E0EB04 80240364 C4440004 */  lwc1      $f4, 4($v0)
/* E0EB08 80240368 46802120 */  cvt.s.w   $f4, $f4
/* E0EB0C 8024036C 44062000 */  mfc1      $a2, $f4
/* E0EB10 80240370 C444000C */  lwc1      $f4, 0xc($v0)
/* E0EB14 80240374 46802120 */  cvt.s.w   $f4, $f4
/* E0EB18 80240378 44072000 */  mfc1      $a3, $f4
/* E0EB1C 8024037C 0C00A7B5 */  jal       dist2D
/* E0EB20 80240380 4600B386 */   mov.s    $f14, $f22
/* E0EB24 80240384 4614003C */  c.lt.s    $f0, $f20
/* E0EB28 80240388 00000000 */  nop
/* E0EB2C 8024038C 45000003 */  bc1f      .L8024039C
/* E0EB30 80240390 2631000C */   addiu    $s1, $s1, 0xc
/* E0EB34 80240394 46000506 */  mov.s     $f20, $f0
/* E0EB38 80240398 AEB20078 */  sw        $s2, 0x78($s5)
.L8024039C:
/* E0EB3C 8024039C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* E0EB40 802403A0 26100001 */  addiu     $s0, $s0, 1
/* E0EB44 802403A4 8C620000 */  lw        $v0, ($v1)
/* E0EB48 802403A8 0202102A */  slt       $v0, $s0, $v0
/* E0EB4C 802403AC 1440FFEB */  bnez      $v0, .L8024035C
/* E0EB50 802403B0 26520001 */   addiu    $s2, $s2, 1
.L802403B4:
/* E0EB54 802403B4 8E6200CC */  lw        $v0, 0xcc($s3)
/* E0EB58 802403B8 8C420004 */  lw        $v0, 4($v0)
/* E0EB5C 802403BC AE820028 */  sw        $v0, 0x28($s4)
/* E0EB60 802403C0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* E0EB64 802403C4 8C42007C */  lw        $v0, 0x7c($v0)
/* E0EB68 802403C8 04410004 */  bgez      $v0, .L802403DC
/* E0EB6C 802403CC 00000000 */   nop
/* E0EB70 802403D0 C6C00000 */  lwc1      $f0, ($s6)
/* E0EB74 802403D4 080900FF */  j         .L802403FC
/* E0EB78 802403D8 E6800018 */   swc1     $f0, 0x18($s4)
.L802403DC:
/* E0EB7C 802403DC 3C018024 */  lui       $at, %hi(D_80243DF0_E12590)
/* E0EB80 802403E0 D4223DF0 */  ldc1      $f2, %lo(D_80243DF0_E12590)($at)
/* E0EB84 802403E4 44820000 */  mtc1      $v0, $f0
/* E0EB88 802403E8 00000000 */  nop
/* E0EB8C 802403EC 46800021 */  cvt.d.w   $f0, $f0
/* E0EB90 802403F0 46220003 */  div.d     $f0, $f0, $f2
/* E0EB94 802403F4 46200020 */  cvt.s.d   $f0, $f0
/* E0EB98 802403F8 E6800018 */  swc1      $f0, 0x18($s4)
.L802403FC:
/* E0EB9C 802403FC 24020001 */  addiu     $v0, $zero, 1
/* E0EBA0 80240400 AEA20070 */  sw        $v0, 0x70($s5)
/* E0EBA4 80240404 8FBF002C */  lw        $ra, 0x2c($sp)
/* E0EBA8 80240408 8FB60028 */  lw        $s6, 0x28($sp)
/* E0EBAC 8024040C 8FB50024 */  lw        $s5, 0x24($sp)
/* E0EBB0 80240410 8FB40020 */  lw        $s4, 0x20($sp)
/* E0EBB4 80240414 8FB3001C */  lw        $s3, 0x1c($sp)
/* E0EBB8 80240418 8FB20018 */  lw        $s2, 0x18($sp)
/* E0EBBC 8024041C 8FB10014 */  lw        $s1, 0x14($sp)
/* E0EBC0 80240420 8FB00010 */  lw        $s0, 0x10($sp)
/* E0EBC4 80240424 D7B80040 */  ldc1      $f24, 0x40($sp)
/* E0EBC8 80240428 D7B60038 */  ldc1      $f22, 0x38($sp)
/* E0EBCC 8024042C D7B40030 */  ldc1      $f20, 0x30($sp)
/* E0EBD0 80240430 03E00008 */  jr        $ra
/* E0EBD4 80240434 27BD0048 */   addiu    $sp, $sp, 0x48
