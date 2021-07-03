.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244620_A06E60
.double 32767.0

.section .text

glabel func_80240994_A031D4
/* A031D4 80240994 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A031D8 80240998 AFB3002C */  sw        $s3, 0x2c($sp)
/* A031DC 8024099C 0080982D */  daddu     $s3, $a0, $zero
/* A031E0 802409A0 AFBF0030 */  sw        $ra, 0x30($sp)
/* A031E4 802409A4 AFB20028 */  sw        $s2, 0x28($sp)
/* A031E8 802409A8 AFB10024 */  sw        $s1, 0x24($sp)
/* A031EC 802409AC AFB00020 */  sw        $s0, 0x20($sp)
/* A031F0 802409B0 8E710148 */  lw        $s1, 0x148($s3)
/* A031F4 802409B4 86240008 */  lh        $a0, 8($s1)
/* A031F8 802409B8 0C00EABB */  jal       get_npc_unsafe
/* A031FC 802409BC 00A0902D */   daddu    $s2, $a1, $zero
/* A03200 802409C0 8E440004 */  lw        $a0, 4($s2)
/* A03204 802409C4 0040802D */  daddu     $s0, $v0, $zero
/* A03208 802409C8 00041FC2 */  srl       $v1, $a0, 0x1f
/* A0320C 802409CC 00832021 */  addu      $a0, $a0, $v1
/* A03210 802409D0 00042043 */  sra       $a0, $a0, 1
/* A03214 802409D4 0C00A67F */  jal       rand_int
/* A03218 802409D8 24840001 */   addiu    $a0, $a0, 1
/* A0321C 802409DC 8E430004 */  lw        $v1, 4($s2)
/* A03220 802409E0 000327C2 */  srl       $a0, $v1, 0x1f
/* A03224 802409E4 00641821 */  addu      $v1, $v1, $a0
/* A03228 802409E8 00031843 */  sra       $v1, $v1, 1
/* A0322C 802409EC 00621821 */  addu      $v1, $v1, $v0
/* A03230 802409F0 A603008E */  sh        $v1, 0x8e($s0)
/* A03234 802409F4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A03238 802409F8 C6000040 */  lwc1      $f0, 0x40($s0)
/* A0323C 802409FC C4640000 */  lwc1      $f4, ($v1)
/* A03240 80240A00 46802120 */  cvt.s.w   $f4, $f4
/* A03244 80240A04 C4620008 */  lwc1      $f2, 8($v1)
/* A03248 80240A08 468010A0 */  cvt.s.w   $f2, $f2
/* A0324C 80240A0C E7A00010 */  swc1      $f0, 0x10($sp)
/* A03250 80240A10 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03254 80240A14 44061000 */  mfc1      $a2, $f2
/* A03258 80240A18 C440000C */  lwc1      $f0, 0xc($v0)
/* A0325C 80240A1C 46800020 */  cvt.s.w   $f0, $f0
/* A03260 80240A20 E7A00014 */  swc1      $f0, 0x14($sp)
/* A03264 80240A24 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03268 80240A28 44052000 */  mfc1      $a1, $f4
/* A0326C 80240A2C C4400010 */  lwc1      $f0, 0x10($v0)
/* A03270 80240A30 46800020 */  cvt.s.w   $f0, $f0
/* A03274 80240A34 E7A00018 */  swc1      $f0, 0x18($sp)
/* A03278 80240A38 8C640018 */  lw        $a0, 0x18($v1)
/* A0327C 80240A3C 0C0123F5 */  jal       is_point_within_region
/* A03280 80240A40 8E070038 */   lw       $a3, 0x38($s0)
/* A03284 80240A44 1040000E */  beqz      $v0, .L80240A80
/* A03288 80240A48 00000000 */   nop
/* A0328C 80240A4C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03290 80240A50 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A03294 80240A54 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A03298 80240A58 C4460000 */  lwc1      $f6, ($v0)
/* A0329C 80240A5C 468031A0 */  cvt.s.w   $f6, $f6
/* A032A0 80240A60 44063000 */  mfc1      $a2, $f6
/* A032A4 80240A64 C4460008 */  lwc1      $f6, 8($v0)
/* A032A8 80240A68 468031A0 */  cvt.s.w   $f6, $f6
/* A032AC 80240A6C 44073000 */  mfc1      $a3, $f6
/* A032B0 80240A70 0C00A720 */  jal       atan2
/* A032B4 80240A74 00000000 */   nop
/* A032B8 80240A78 080902AC */  j         .L80240AB0
/* A032BC 80240A7C E600000C */   swc1     $f0, 0xc($s0)
.L80240A80:
/* A032C0 80240A80 0C00A67F */  jal       rand_int
/* A032C4 80240A84 2404003C */   addiu    $a0, $zero, 0x3c
/* A032C8 80240A88 C60C000C */  lwc1      $f12, 0xc($s0)
/* A032CC 80240A8C 44820000 */  mtc1      $v0, $f0
/* A032D0 80240A90 00000000 */  nop
/* A032D4 80240A94 46800020 */  cvt.s.w   $f0, $f0
/* A032D8 80240A98 46006300 */  add.s     $f12, $f12, $f0
/* A032DC 80240A9C 3C0141F0 */  lui       $at, 0x41f0
/* A032E0 80240AA0 44810000 */  mtc1      $at, $f0
/* A032E4 80240AA4 0C00A6C9 */  jal       clamp_angle
/* A032E8 80240AA8 46006301 */   sub.s    $f12, $f12, $f0
/* A032EC 80240AAC E600000C */  swc1      $f0, 0xc($s0)
.L80240AB0:
/* A032F0 80240AB0 8E2200CC */  lw        $v0, 0xcc($s1)
/* A032F4 80240AB4 8C420004 */  lw        $v0, 4($v0)
/* A032F8 80240AB8 AE020028 */  sw        $v0, 0x28($s0)
/* A032FC 80240ABC AE600074 */  sw        $zero, 0x74($s3)
/* A03300 80240AC0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03304 80240AC4 8C420014 */  lw        $v0, 0x14($v0)
/* A03308 80240AC8 04410004 */  bgez      $v0, .L80240ADC
/* A0330C 80240ACC 00000000 */   nop
/* A03310 80240AD0 C6400000 */  lwc1      $f0, ($s2)
/* A03314 80240AD4 080902BF */  j         .L80240AFC
/* A03318 80240AD8 E6000018 */   swc1     $f0, 0x18($s0)
.L80240ADC:
/* A0331C 80240ADC 3C018024 */  lui       $at, %hi(D_80244620_A06E60)
/* A03320 80240AE0 D4224620 */  ldc1      $f2, %lo(D_80244620_A06E60)($at)
/* A03324 80240AE4 44820000 */  mtc1      $v0, $f0
/* A03328 80240AE8 00000000 */  nop
/* A0332C 80240AEC 46800021 */  cvt.d.w   $f0, $f0
/* A03330 80240AF0 46220003 */  div.d     $f0, $f0, $f2
/* A03334 80240AF4 46200020 */  cvt.s.d   $f0, $f0
/* A03338 80240AF8 E6000018 */  swc1      $f0, 0x18($s0)
.L80240AFC:
/* A0333C 80240AFC C600003C */  lwc1      $f0, 0x3c($s0)
/* A03340 80240B00 3C014059 */  lui       $at, 0x4059
/* A03344 80240B04 44811800 */  mtc1      $at, $f3
/* A03348 80240B08 44801000 */  mtc1      $zero, $f2
/* A0334C 80240B0C 46000021 */  cvt.d.s   $f0, $f0
/* A03350 80240B10 46220002 */  mul.d     $f0, $f0, $f2
/* A03354 80240B14 00000000 */  nop
/* A03358 80240B18 24020001 */  addiu     $v0, $zero, 1
/* A0335C 80240B1C 4620018D */  trunc.w.d $f6, $f0
/* A03360 80240B20 E626007C */  swc1      $f6, 0x7c($s1)
/* A03364 80240B24 AE620070 */  sw        $v0, 0x70($s3)
/* A03368 80240B28 8FBF0030 */  lw        $ra, 0x30($sp)
/* A0336C 80240B2C 8FB3002C */  lw        $s3, 0x2c($sp)
/* A03370 80240B30 8FB20028 */  lw        $s2, 0x28($sp)
/* A03374 80240B34 8FB10024 */  lw        $s1, 0x24($sp)
/* A03378 80240B38 8FB00020 */  lw        $s0, 0x20($sp)
/* A0337C 80240B3C 03E00008 */  jr        $ra
/* A03380 80240B40 27BD0038 */   addiu    $sp, $sp, 0x38
