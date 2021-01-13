.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_ABB340
/* ABB340 802400B0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* ABB344 802400B4 AFB50024 */  sw        $s5, 0x24($sp)
/* ABB348 802400B8 0080A82D */  daddu     $s5, $a0, $zero
/* ABB34C 802400BC AFBF002C */  sw        $ra, 0x2c($sp)
/* ABB350 802400C0 AFB60028 */  sw        $s6, 0x28($sp)
/* ABB354 802400C4 AFB40020 */  sw        $s4, 0x20($sp)
/* ABB358 802400C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* ABB35C 802400CC AFB20018 */  sw        $s2, 0x18($sp)
/* ABB360 802400D0 AFB10014 */  sw        $s1, 0x14($sp)
/* ABB364 802400D4 AFB00010 */  sw        $s0, 0x10($sp)
/* ABB368 802400D8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* ABB36C 802400DC F7B60038 */  sdc1      $f22, 0x38($sp)
/* ABB370 802400E0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* ABB374 802400E4 8EB30148 */  lw        $s3, 0x148($s5)
/* ABB378 802400E8 86640008 */  lh        $a0, 8($s3)
/* ABB37C 802400EC 0C00EABB */  jal       get_npc_unsafe
/* ABB380 802400F0 00A0B02D */   daddu    $s6, $a1, $zero
/* ABB384 802400F4 0040A02D */  daddu     $s4, $v0, $zero
/* ABB388 802400F8 AEA00074 */  sw        $zero, 0x74($s5)
/* ABB38C 802400FC C6980038 */  lwc1      $f24, 0x38($s4)
/* ABB390 80240100 C6960040 */  lwc1      $f22, 0x40($s4)
/* ABB394 80240104 0000902D */  daddu     $s2, $zero, $zero
/* ABB398 80240108 AEA00078 */  sw        $zero, 0x78($s5)
/* ABB39C 8024010C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* ABB3A0 80240110 8C620000 */  lw        $v0, ($v1)
/* ABB3A4 80240114 3C0146FF */  lui       $at, 0x46ff
/* ABB3A8 80240118 3421FE00 */  ori       $at, $at, 0xfe00
/* ABB3AC 8024011C 4481A000 */  mtc1      $at, $f20
/* ABB3B0 80240120 18400018 */  blez      $v0, .L80240184
/* ABB3B4 80240124 0240802D */   daddu    $s0, $s2, $zero
/* ABB3B8 80240128 0240882D */  daddu     $s1, $s2, $zero
.L8024012C:
/* ABB3BC 8024012C 02231021 */  addu      $v0, $s1, $v1
/* ABB3C0 80240130 4600C306 */  mov.s     $f12, $f24
/* ABB3C4 80240134 C4440004 */  lwc1      $f4, 4($v0)
/* ABB3C8 80240138 46802120 */  cvt.s.w   $f4, $f4
/* ABB3CC 8024013C 44062000 */  mfc1      $a2, $f4
/* ABB3D0 80240140 C444000C */  lwc1      $f4, 0xc($v0)
/* ABB3D4 80240144 46802120 */  cvt.s.w   $f4, $f4
/* ABB3D8 80240148 44072000 */  mfc1      $a3, $f4
/* ABB3DC 8024014C 0C00A7B5 */  jal       dist2D
/* ABB3E0 80240150 4600B386 */   mov.s    $f14, $f22
/* ABB3E4 80240154 4614003C */  c.lt.s    $f0, $f20
/* ABB3E8 80240158 00000000 */  nop
/* ABB3EC 8024015C 45000003 */  bc1f      .L8024016C
/* ABB3F0 80240160 2631000C */   addiu    $s1, $s1, 0xc
/* ABB3F4 80240164 46000506 */  mov.s     $f20, $f0
/* ABB3F8 80240168 AEB20078 */  sw        $s2, 0x78($s5)
.L8024016C:
/* ABB3FC 8024016C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* ABB400 80240170 26100001 */  addiu     $s0, $s0, 1
/* ABB404 80240174 8C620000 */  lw        $v0, ($v1)
/* ABB408 80240178 0202102A */  slt       $v0, $s0, $v0
/* ABB40C 8024017C 1440FFEB */  bnez      $v0, .L8024012C
/* ABB410 80240180 26520001 */   addiu    $s2, $s2, 1
.L80240184:
/* ABB414 80240184 8E6200CC */  lw        $v0, 0xcc($s3)
/* ABB418 80240188 8C420004 */  lw        $v0, 4($v0)
/* ABB41C 8024018C AE820028 */  sw        $v0, 0x28($s4)
/* ABB420 80240190 8E6200D0 */  lw        $v0, 0xd0($s3)
/* ABB424 80240194 8C42007C */  lw        $v0, 0x7c($v0)
/* ABB428 80240198 04410004 */  bgez      $v0, .L802401AC
/* ABB42C 8024019C 00000000 */   nop
/* ABB430 802401A0 C6C00000 */  lwc1      $f0, ($s6)
/* ABB434 802401A4 08090073 */  j         .L802401CC
/* ABB438 802401A8 E6800018 */   swc1     $f0, 0x18($s4)
.L802401AC:
/* ABB43C 802401AC 3C018025 */  lui       $at, %hi(D_80249D30)
/* ABB440 802401B0 D4229D30 */  ldc1      $f2, %lo(D_80249D30)($at)
/* ABB444 802401B4 44820000 */  mtc1      $v0, $f0
/* ABB448 802401B8 00000000 */  nop
/* ABB44C 802401BC 46800021 */  cvt.d.w   $f0, $f0
/* ABB450 802401C0 46220003 */  div.d     $f0, $f0, $f2
/* ABB454 802401C4 46200020 */  cvt.s.d   $f0, $f0
/* ABB458 802401C8 E6800018 */  swc1      $f0, 0x18($s4)
.L802401CC:
/* ABB45C 802401CC 24020001 */  addiu     $v0, $zero, 1
/* ABB460 802401D0 AEA20070 */  sw        $v0, 0x70($s5)
/* ABB464 802401D4 8FBF002C */  lw        $ra, 0x2c($sp)
/* ABB468 802401D8 8FB60028 */  lw        $s6, 0x28($sp)
/* ABB46C 802401DC 8FB50024 */  lw        $s5, 0x24($sp)
/* ABB470 802401E0 8FB40020 */  lw        $s4, 0x20($sp)
/* ABB474 802401E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* ABB478 802401E8 8FB20018 */  lw        $s2, 0x18($sp)
/* ABB47C 802401EC 8FB10014 */  lw        $s1, 0x14($sp)
/* ABB480 802401F0 8FB00010 */  lw        $s0, 0x10($sp)
/* ABB484 802401F4 D7B80040 */  ldc1      $f24, 0x40($sp)
/* ABB488 802401F8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* ABB48C 802401FC D7B40030 */  ldc1      $f20, 0x30($sp)
/* ABB490 80240200 03E00008 */  jr        $ra
/* ABB494 80240204 27BD0048 */   addiu    $sp, $sp, 0x48
