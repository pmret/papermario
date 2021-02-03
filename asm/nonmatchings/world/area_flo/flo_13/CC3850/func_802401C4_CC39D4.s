.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C4_CC39D4
/* CC39D4 802401C4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CC39D8 802401C8 AFB3002C */  sw        $s3, 0x2c($sp)
/* CC39DC 802401CC 0080982D */  daddu     $s3, $a0, $zero
/* CC39E0 802401D0 AFBF0030 */  sw        $ra, 0x30($sp)
/* CC39E4 802401D4 AFB20028 */  sw        $s2, 0x28($sp)
/* CC39E8 802401D8 AFB10024 */  sw        $s1, 0x24($sp)
/* CC39EC 802401DC AFB00020 */  sw        $s0, 0x20($sp)
/* CC39F0 802401E0 8E710148 */  lw        $s1, 0x148($s3)
/* CC39F4 802401E4 86240008 */  lh        $a0, 8($s1)
/* CC39F8 802401E8 0C00EABB */  jal       get_npc_unsafe
/* CC39FC 802401EC 00A0902D */   daddu    $s2, $a1, $zero
/* CC3A00 802401F0 8E440004 */  lw        $a0, 4($s2)
/* CC3A04 802401F4 0040802D */  daddu     $s0, $v0, $zero
/* CC3A08 802401F8 00041FC2 */  srl       $v1, $a0, 0x1f
/* CC3A0C 802401FC 00832021 */  addu      $a0, $a0, $v1
/* CC3A10 80240200 00042043 */  sra       $a0, $a0, 1
/* CC3A14 80240204 0C00A67F */  jal       rand_int
/* CC3A18 80240208 24840001 */   addiu    $a0, $a0, 1
/* CC3A1C 8024020C 8E430004 */  lw        $v1, 4($s2)
/* CC3A20 80240210 000327C2 */  srl       $a0, $v1, 0x1f
/* CC3A24 80240214 00641821 */  addu      $v1, $v1, $a0
/* CC3A28 80240218 00031843 */  sra       $v1, $v1, 1
/* CC3A2C 8024021C 00621821 */  addu      $v1, $v1, $v0
/* CC3A30 80240220 A603008E */  sh        $v1, 0x8e($s0)
/* CC3A34 80240224 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC3A38 80240228 C6000040 */  lwc1      $f0, 0x40($s0)
/* CC3A3C 8024022C C4640000 */  lwc1      $f4, ($v1)
/* CC3A40 80240230 46802120 */  cvt.s.w   $f4, $f4
/* CC3A44 80240234 C4620008 */  lwc1      $f2, 8($v1)
/* CC3A48 80240238 468010A0 */  cvt.s.w   $f2, $f2
/* CC3A4C 8024023C E7A00010 */  swc1      $f0, 0x10($sp)
/* CC3A50 80240240 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC3A54 80240244 44061000 */  mfc1      $a2, $f2
/* CC3A58 80240248 C440000C */  lwc1      $f0, 0xc($v0)
/* CC3A5C 8024024C 46800020 */  cvt.s.w   $f0, $f0
/* CC3A60 80240250 E7A00014 */  swc1      $f0, 0x14($sp)
/* CC3A64 80240254 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC3A68 80240258 44052000 */  mfc1      $a1, $f4
/* CC3A6C 8024025C C4400010 */  lwc1      $f0, 0x10($v0)
/* CC3A70 80240260 46800020 */  cvt.s.w   $f0, $f0
/* CC3A74 80240264 E7A00018 */  swc1      $f0, 0x18($sp)
/* CC3A78 80240268 8C640018 */  lw        $a0, 0x18($v1)
/* CC3A7C 8024026C 0C0123F5 */  jal       is_point_within_region
/* CC3A80 80240270 8E070038 */   lw       $a3, 0x38($s0)
/* CC3A84 80240274 1040000E */  beqz      $v0, .L802402B0
/* CC3A88 80240278 00000000 */   nop
/* CC3A8C 8024027C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC3A90 80240280 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CC3A94 80240284 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CC3A98 80240288 C4460000 */  lwc1      $f6, ($v0)
/* CC3A9C 8024028C 468031A0 */  cvt.s.w   $f6, $f6
/* CC3AA0 80240290 44063000 */  mfc1      $a2, $f6
/* CC3AA4 80240294 C4460008 */  lwc1      $f6, 8($v0)
/* CC3AA8 80240298 468031A0 */  cvt.s.w   $f6, $f6
/* CC3AAC 8024029C 44073000 */  mfc1      $a3, $f6
/* CC3AB0 802402A0 0C00A720 */  jal       atan2
/* CC3AB4 802402A4 00000000 */   nop
/* CC3AB8 802402A8 080900B8 */  j         .L802402E0
/* CC3ABC 802402AC E600000C */   swc1     $f0, 0xc($s0)
.L802402B0:
/* CC3AC0 802402B0 0C00A67F */  jal       rand_int
/* CC3AC4 802402B4 2404003C */   addiu    $a0, $zero, 0x3c
/* CC3AC8 802402B8 C60C000C */  lwc1      $f12, 0xc($s0)
/* CC3ACC 802402BC 44820000 */  mtc1      $v0, $f0
/* CC3AD0 802402C0 00000000 */  nop
/* CC3AD4 802402C4 46800020 */  cvt.s.w   $f0, $f0
/* CC3AD8 802402C8 46006300 */  add.s     $f12, $f12, $f0
/* CC3ADC 802402CC 3C0141F0 */  lui       $at, 0x41f0
/* CC3AE0 802402D0 44810000 */  mtc1      $at, $f0
/* CC3AE4 802402D4 0C00A6C9 */  jal       clamp_angle
/* CC3AE8 802402D8 46006301 */   sub.s    $f12, $f12, $f0
/* CC3AEC 802402DC E600000C */  swc1      $f0, 0xc($s0)
.L802402E0:
/* CC3AF0 802402E0 8E2200CC */  lw        $v0, 0xcc($s1)
/* CC3AF4 802402E4 8C420004 */  lw        $v0, 4($v0)
/* CC3AF8 802402E8 AE020028 */  sw        $v0, 0x28($s0)
/* CC3AFC 802402EC AE600074 */  sw        $zero, 0x74($s3)
/* CC3B00 802402F0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC3B04 802402F4 8C420014 */  lw        $v0, 0x14($v0)
/* CC3B08 802402F8 04410004 */  bgez      $v0, .L8024030C
/* CC3B0C 802402FC 00000000 */   nop
/* CC3B10 80240300 C6400000 */  lwc1      $f0, ($s2)
/* CC3B14 80240304 080900CB */  j         .L8024032C
/* CC3B18 80240308 E6000018 */   swc1     $f0, 0x18($s0)
.L8024030C:
/* CC3B1C 8024030C 3C018024 */  lui       $at, %hi(D_80247A30_CCB240)
/* CC3B20 80240310 D4227A30 */  ldc1      $f2, %lo(D_80247A30_CCB240)($at)
/* CC3B24 80240314 44820000 */  mtc1      $v0, $f0
/* CC3B28 80240318 00000000 */  nop
/* CC3B2C 8024031C 46800021 */  cvt.d.w   $f0, $f0
/* CC3B30 80240320 46220003 */  div.d     $f0, $f0, $f2
/* CC3B34 80240324 46200020 */  cvt.s.d   $f0, $f0
/* CC3B38 80240328 E6000018 */  swc1      $f0, 0x18($s0)
.L8024032C:
/* CC3B3C 8024032C C600003C */  lwc1      $f0, 0x3c($s0)
/* CC3B40 80240330 3C014059 */  lui       $at, 0x4059
/* CC3B44 80240334 44811800 */  mtc1      $at, $f3
/* CC3B48 80240338 44801000 */  mtc1      $zero, $f2
/* CC3B4C 8024033C 46000021 */  cvt.d.s   $f0, $f0
/* CC3B50 80240340 46220002 */  mul.d     $f0, $f0, $f2
/* CC3B54 80240344 00000000 */  nop
/* CC3B58 80240348 24020001 */  addiu     $v0, $zero, 1
/* CC3B5C 8024034C 4620018D */  trunc.w.d $f6, $f0
/* CC3B60 80240350 E626007C */  swc1      $f6, 0x7c($s1)
/* CC3B64 80240354 AE620070 */  sw        $v0, 0x70($s3)
/* CC3B68 80240358 8FBF0030 */  lw        $ra, 0x30($sp)
/* CC3B6C 8024035C 8FB3002C */  lw        $s3, 0x2c($sp)
/* CC3B70 80240360 8FB20028 */  lw        $s2, 0x28($sp)
/* CC3B74 80240364 8FB10024 */  lw        $s1, 0x24($sp)
/* CC3B78 80240368 8FB00020 */  lw        $s0, 0x20($sp)
/* CC3B7C 8024036C 03E00008 */  jr        $ra
/* CC3B80 80240370 27BD0038 */   addiu    $sp, $sp, 0x38
