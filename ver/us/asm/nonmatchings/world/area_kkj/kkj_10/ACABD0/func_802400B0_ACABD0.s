.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_ACABD0
/* ACABD0 802400B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* ACABD4 802400B4 AFB3003C */  sw        $s3, 0x3c($sp)
/* ACABD8 802400B8 0080982D */  daddu     $s3, $a0, $zero
/* ACABDC 802400BC AFBF0044 */  sw        $ra, 0x44($sp)
/* ACABE0 802400C0 AFB40040 */  sw        $s4, 0x40($sp)
/* ACABE4 802400C4 AFB20038 */  sw        $s2, 0x38($sp)
/* ACABE8 802400C8 AFB10034 */  sw        $s1, 0x34($sp)
/* ACABEC 802400CC AFB00030 */  sw        $s0, 0x30($sp)
/* ACABF0 802400D0 F7B80058 */  sdc1      $f24, 0x58($sp)
/* ACABF4 802400D4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ACABF8 802400D8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* ACABFC 802400DC 8E620148 */  lw        $v0, 0x148($s3)
/* ACAC00 802400E0 0C00EABB */  jal       get_npc_unsafe
/* ACAC04 802400E4 84440008 */   lh       $a0, 8($v0)
/* ACAC08 802400E8 27A40020 */  addiu     $a0, $sp, 0x20
/* ACAC0C 802400EC 27A50024 */  addiu     $a1, $sp, 0x24
/* ACAC10 802400F0 0040802D */  daddu     $s0, $v0, $zero
/* ACAC14 802400F4 8E63000C */  lw        $v1, 0xc($s3)
/* ACAC18 802400F8 8E07000C */  lw        $a3, 0xc($s0)
/* ACAC1C 802400FC C6000038 */  lwc1      $f0, 0x38($s0)
/* ACAC20 80240100 C6020040 */  lwc1      $f2, 0x40($s0)
/* ACAC24 80240104 8C740000 */  lw        $s4, ($v1)
/* ACAC28 80240108 24630004 */  addiu     $v1, $v1, 4
/* ACAC2C 8024010C C4780000 */  lwc1      $f24, ($v1)
/* ACAC30 80240110 4680C620 */  cvt.s.w   $f24, $f24
/* ACAC34 80240114 24630004 */  addiu     $v1, $v1, 4
/* ACAC38 80240118 C4740000 */  lwc1      $f20, ($v1)
/* ACAC3C 8024011C 4680A520 */  cvt.s.w   $f20, $f20
/* ACAC40 80240120 4406A000 */  mfc1      $a2, $f20
/* ACAC44 80240124 C4760004 */  lwc1      $f22, 4($v1)
/* ACAC48 80240128 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACAC4C 8024012C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACAC50 80240130 0C00A7E7 */  jal       add_vec2D_polar
/* ACAC54 80240134 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACAC58 80240138 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACAC5C 8024013C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACAC60 80240140 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACAC64 80240144 4480A000 */  mtc1      $zero, $f20
/* ACAC68 80240148 8E460028 */  lw        $a2, 0x28($s2)
/* ACAC6C 8024014C 4407A000 */  mfc1      $a3, $f20
/* ACAC70 80240150 0C00A7B5 */  jal       dist2D
/* ACAC74 80240154 4600A386 */   mov.s    $f14, $f20
/* ACAC78 80240158 4600A306 */  mov.s     $f12, $f20
/* ACAC7C 8024015C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACAC80 80240160 44066000 */  mfc1      $a2, $f12
/* ACAC84 80240164 8E470030 */  lw        $a3, 0x30($s2)
/* ACAC88 80240168 0C00A7B5 */  jal       dist2D
/* ACAC8C 8024016C 46000506 */   mov.s    $f20, $f0
/* ACAC90 80240170 C604000C */  lwc1      $f4, 0xc($s0)
/* ACAC94 80240174 3C018024 */  lui       $at, %hi(D_802435E0_ACE100)
/* ACAC98 80240178 D42235E0 */  ldc1      $f2, %lo(D_802435E0_ACE100)($at)
/* ACAC9C 8024017C 46002121 */  cvt.d.s   $f4, $f4
/* ACACA0 80240180 46222032 */  c.eq.d    $f4, $f2
/* ACACA4 80240184 00000000 */  nop
/* ACACA8 80240188 45010007 */  bc1t      .L802401A8
/* ACACAC 8024018C 46000086 */   mov.s    $f2, $f0
/* ACACB0 80240190 3C018024 */  lui       $at, %hi(D_802435E8_ACE108)
/* ACACB4 80240194 D42035E8 */  ldc1      $f0, %lo(D_802435E8_ACE108)($at)
/* ACACB8 80240198 46202032 */  c.eq.d    $f4, $f0
/* ACACBC 8024019C 00000000 */  nop
/* ACACC0 802401A0 45000008 */  bc1f      .L802401C4
/* ACACC4 802401A4 00000000 */   nop
.L802401A8:
/* ACACC8 802401A8 4618A03E */  c.le.s    $f20, $f24
/* ACACCC 802401AC 00000000 */  nop
/* ACACD0 802401B0 4500000C */  bc1f      .L802401E4
/* ACACD4 802401B4 0000882D */   daddu    $s1, $zero, $zero
/* ACACD8 802401B8 4616103E */  c.le.s    $f2, $f22
/* ACACDC 802401BC 08090077 */  j         .L802401DC
/* ACACE0 802401C0 00000000 */   nop
.L802401C4:
/* ACACE4 802401C4 4618103E */  c.le.s    $f2, $f24
/* ACACE8 802401C8 00000000 */  nop
/* ACACEC 802401CC 45000005 */  bc1f      .L802401E4
/* ACACF0 802401D0 0000882D */   daddu    $s1, $zero, $zero
/* ACACF4 802401D4 4616A03E */  c.le.s    $f20, $f22
/* ACACF8 802401D8 00000000 */  nop
.L802401DC:
/* ACACFC 802401DC 45030001 */  bc1tl     .L802401E4
/* ACAD00 802401E0 24110001 */   addiu    $s1, $zero, 1
.L802401E4:
/* ACAD04 802401E4 12200027 */  beqz      $s1, .L80240284
/* ACAD08 802401E8 0260202D */   daddu    $a0, $s3, $zero
/* ACAD0C 802401EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACAD10 802401F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACAD14 802401F4 8E460028 */  lw        $a2, 0x28($s2)
/* ACAD18 802401F8 8E470030 */  lw        $a3, 0x30($s2)
/* ACAD1C 802401FC C602003C */  lwc1      $f2, 0x3c($s0)
/* ACAD20 80240200 46006006 */  mov.s     $f0, $f12
/* ACAD24 80240204 46007106 */  mov.s     $f4, $f14
/* ACAD28 80240208 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACAD2C 8024020C E7A20028 */  swc1      $f2, 0x28($sp)
/* ACAD30 80240210 0C00A7B5 */  jal       dist2D
/* ACAD34 80240214 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACAD38 80240218 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACAD3C 8024021C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACAD40 80240220 8E460028 */  lw        $a2, 0x28($s2)
/* ACAD44 80240224 8E470030 */  lw        $a3, 0x30($s2)
/* ACAD48 80240228 0C00A720 */  jal       atan2
/* ACAD4C 8024022C 46000506 */   mov.s    $f20, $f0
/* ACAD50 80240230 3C040007 */  lui       $a0, 7
/* ACAD54 80240234 34848000 */  ori       $a0, $a0, 0x8000
/* ACAD58 80240238 27A50020 */  addiu     $a1, $sp, 0x20
/* ACAD5C 8024023C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACAD60 80240240 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACAD64 80240244 860200A6 */  lh        $v0, 0xa6($s0)
/* ACAD68 80240248 27A60028 */  addiu     $a2, $sp, 0x28
/* ACAD6C 8024024C 44820000 */  mtc1      $v0, $f0
/* ACAD70 80240250 00000000 */  nop
/* ACAD74 80240254 46800020 */  cvt.s.w   $f0, $f0
/* ACAD78 80240258 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACAD7C 8024025C 860200A8 */  lh        $v0, 0xa8($s0)
/* ACAD80 80240260 27A70024 */  addiu     $a3, $sp, 0x24
/* ACAD84 80240264 44820000 */  mtc1      $v0, $f0
/* ACAD88 80240268 00000000 */  nop
/* ACAD8C 8024026C 46800020 */  cvt.s.w   $f0, $f0
/* ACAD90 80240270 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACAD94 80240274 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACAD98 80240278 54400001 */  bnel      $v0, $zero, .L80240280
/* ACAD9C 8024027C 0000882D */   daddu    $s1, $zero, $zero
.L80240280:
/* ACADA0 80240280 0260202D */  daddu     $a0, $s3, $zero
.L80240284:
/* ACADA4 80240284 0280282D */  daddu     $a1, $s4, $zero
/* ACADA8 80240288 0C0B2026 */  jal       set_variable
/* ACADAC 8024028C 0220302D */   daddu    $a2, $s1, $zero
/* ACADB0 80240290 8FBF0044 */  lw        $ra, 0x44($sp)
/* ACADB4 80240294 8FB40040 */  lw        $s4, 0x40($sp)
/* ACADB8 80240298 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACADBC 8024029C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACADC0 802402A0 8FB10034 */  lw        $s1, 0x34($sp)
/* ACADC4 802402A4 8FB00030 */  lw        $s0, 0x30($sp)
/* ACADC8 802402A8 D7B80058 */  ldc1      $f24, 0x58($sp)
/* ACADCC 802402AC D7B60050 */  ldc1      $f22, 0x50($sp)
/* ACADD0 802402B0 D7B40048 */  ldc1      $f20, 0x48($sp)
/* ACADD4 802402B4 24020002 */  addiu     $v0, $zero, 2
/* ACADD8 802402B8 03E00008 */  jr        $ra
/* ACADDC 802402BC 27BD0060 */   addiu    $sp, $sp, 0x60
