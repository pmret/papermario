.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_ACE1F0
/* ACE1F0 802400B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* ACE1F4 802400B4 AFB3003C */  sw        $s3, 0x3c($sp)
/* ACE1F8 802400B8 0080982D */  daddu     $s3, $a0, $zero
/* ACE1FC 802400BC AFBF0044 */  sw        $ra, 0x44($sp)
/* ACE200 802400C0 AFB40040 */  sw        $s4, 0x40($sp)
/* ACE204 802400C4 AFB20038 */  sw        $s2, 0x38($sp)
/* ACE208 802400C8 AFB10034 */  sw        $s1, 0x34($sp)
/* ACE20C 802400CC AFB00030 */  sw        $s0, 0x30($sp)
/* ACE210 802400D0 F7B80058 */  sdc1      $f24, 0x58($sp)
/* ACE214 802400D4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ACE218 802400D8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* ACE21C 802400DC 8E620148 */  lw        $v0, 0x148($s3)
/* ACE220 802400E0 0C00EABB */  jal       get_npc_unsafe
/* ACE224 802400E4 84440008 */   lh       $a0, 8($v0)
/* ACE228 802400E8 27A40020 */  addiu     $a0, $sp, 0x20
/* ACE22C 802400EC 27A50024 */  addiu     $a1, $sp, 0x24
/* ACE230 802400F0 0040802D */  daddu     $s0, $v0, $zero
/* ACE234 802400F4 8E63000C */  lw        $v1, 0xc($s3)
/* ACE238 802400F8 8E07000C */  lw        $a3, 0xc($s0)
/* ACE23C 802400FC C6000038 */  lwc1      $f0, 0x38($s0)
/* ACE240 80240100 C6020040 */  lwc1      $f2, 0x40($s0)
/* ACE244 80240104 8C740000 */  lw        $s4, ($v1)
/* ACE248 80240108 24630004 */  addiu     $v1, $v1, 4
/* ACE24C 8024010C C4780000 */  lwc1      $f24, ($v1)
/* ACE250 80240110 4680C620 */  cvt.s.w   $f24, $f24
/* ACE254 80240114 24630004 */  addiu     $v1, $v1, 4
/* ACE258 80240118 C4740000 */  lwc1      $f20, ($v1)
/* ACE25C 8024011C 4680A520 */  cvt.s.w   $f20, $f20
/* ACE260 80240120 4406A000 */  mfc1      $a2, $f20
/* ACE264 80240124 C4760004 */  lwc1      $f22, 4($v1)
/* ACE268 80240128 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACE26C 8024012C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE270 80240130 0C00A7E7 */  jal       add_vec2D_polar
/* ACE274 80240134 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACE278 80240138 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACE27C 8024013C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACE280 80240140 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACE284 80240144 4480A000 */  mtc1      $zero, $f20
/* ACE288 80240148 8E460028 */  lw        $a2, 0x28($s2)
/* ACE28C 8024014C 4407A000 */  mfc1      $a3, $f20
/* ACE290 80240150 0C00A7B5 */  jal       dist2D
/* ACE294 80240154 4600A386 */   mov.s    $f14, $f20
/* ACE298 80240158 4600A306 */  mov.s     $f12, $f20
/* ACE29C 8024015C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACE2A0 80240160 44066000 */  mfc1      $a2, $f12
/* ACE2A4 80240164 8E470030 */  lw        $a3, 0x30($s2)
/* ACE2A8 80240168 0C00A7B5 */  jal       dist2D
/* ACE2AC 8024016C 46000506 */   mov.s    $f20, $f0
/* ACE2B0 80240170 C604000C */  lwc1      $f4, 0xc($s0)
/* ACE2B4 80240174 3C018024 */  lui       $at, %hi(D_80245F10_AD4050)
/* ACE2B8 80240178 D4225F10 */  ldc1      $f2, %lo(D_80245F10_AD4050)($at)
/* ACE2BC 8024017C 46002121 */  cvt.d.s   $f4, $f4
/* ACE2C0 80240180 46222032 */  c.eq.d    $f4, $f2
/* ACE2C4 80240184 00000000 */  nop
/* ACE2C8 80240188 45010007 */  bc1t      .L802401A8
/* ACE2CC 8024018C 46000086 */   mov.s    $f2, $f0
/* ACE2D0 80240190 3C018024 */  lui       $at, %hi(D_80245F18_AD4058)
/* ACE2D4 80240194 D4205F18 */  ldc1      $f0, %lo(D_80245F18_AD4058)($at)
/* ACE2D8 80240198 46202032 */  c.eq.d    $f4, $f0
/* ACE2DC 8024019C 00000000 */  nop
/* ACE2E0 802401A0 45000008 */  bc1f      .L802401C4
/* ACE2E4 802401A4 00000000 */   nop
.L802401A8:
/* ACE2E8 802401A8 4618A03E */  c.le.s    $f20, $f24
/* ACE2EC 802401AC 00000000 */  nop
/* ACE2F0 802401B0 4500000C */  bc1f      .L802401E4
/* ACE2F4 802401B4 0000882D */   daddu    $s1, $zero, $zero
/* ACE2F8 802401B8 4616103E */  c.le.s    $f2, $f22
/* ACE2FC 802401BC 08090077 */  j         .L802401DC
/* ACE300 802401C0 00000000 */   nop
.L802401C4:
/* ACE304 802401C4 4618103E */  c.le.s    $f2, $f24
/* ACE308 802401C8 00000000 */  nop
/* ACE30C 802401CC 45000005 */  bc1f      .L802401E4
/* ACE310 802401D0 0000882D */   daddu    $s1, $zero, $zero
/* ACE314 802401D4 4616A03E */  c.le.s    $f20, $f22
/* ACE318 802401D8 00000000 */  nop
.L802401DC:
/* ACE31C 802401DC 45030001 */  bc1tl     .L802401E4
/* ACE320 802401E0 24110001 */   addiu    $s1, $zero, 1
.L802401E4:
/* ACE324 802401E4 12200027 */  beqz      $s1, .L80240284
/* ACE328 802401E8 0260202D */   daddu    $a0, $s3, $zero
/* ACE32C 802401EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACE330 802401F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACE334 802401F4 8E460028 */  lw        $a2, 0x28($s2)
/* ACE338 802401F8 8E470030 */  lw        $a3, 0x30($s2)
/* ACE33C 802401FC C602003C */  lwc1      $f2, 0x3c($s0)
/* ACE340 80240200 46006006 */  mov.s     $f0, $f12
/* ACE344 80240204 46007106 */  mov.s     $f4, $f14
/* ACE348 80240208 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE34C 8024020C E7A20028 */  swc1      $f2, 0x28($sp)
/* ACE350 80240210 0C00A7B5 */  jal       dist2D
/* ACE354 80240214 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACE358 80240218 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACE35C 8024021C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACE360 80240220 8E460028 */  lw        $a2, 0x28($s2)
/* ACE364 80240224 8E470030 */  lw        $a3, 0x30($s2)
/* ACE368 80240228 0C00A720 */  jal       atan2
/* ACE36C 8024022C 46000506 */   mov.s    $f20, $f0
/* ACE370 80240230 3C040007 */  lui       $a0, 7
/* ACE374 80240234 34848000 */  ori       $a0, $a0, 0x8000
/* ACE378 80240238 27A50020 */  addiu     $a1, $sp, 0x20
/* ACE37C 8024023C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACE380 80240240 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACE384 80240244 860200A6 */  lh        $v0, 0xa6($s0)
/* ACE388 80240248 27A60028 */  addiu     $a2, $sp, 0x28
/* ACE38C 8024024C 44820000 */  mtc1      $v0, $f0
/* ACE390 80240250 00000000 */  nop
/* ACE394 80240254 46800020 */  cvt.s.w   $f0, $f0
/* ACE398 80240258 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACE39C 8024025C 860200A8 */  lh        $v0, 0xa8($s0)
/* ACE3A0 80240260 27A70024 */  addiu     $a3, $sp, 0x24
/* ACE3A4 80240264 44820000 */  mtc1      $v0, $f0
/* ACE3A8 80240268 00000000 */  nop
/* ACE3AC 8024026C 46800020 */  cvt.s.w   $f0, $f0
/* ACE3B0 80240270 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACE3B4 80240274 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACE3B8 80240278 54400001 */  bnel      $v0, $zero, .L80240280
/* ACE3BC 8024027C 0000882D */   daddu    $s1, $zero, $zero
.L80240280:
/* ACE3C0 80240280 0260202D */  daddu     $a0, $s3, $zero
.L80240284:
/* ACE3C4 80240284 0280282D */  daddu     $a1, $s4, $zero
/* ACE3C8 80240288 0C0B2026 */  jal       set_variable
/* ACE3CC 8024028C 0220302D */   daddu    $a2, $s1, $zero
/* ACE3D0 80240290 8FBF0044 */  lw        $ra, 0x44($sp)
/* ACE3D4 80240294 8FB40040 */  lw        $s4, 0x40($sp)
/* ACE3D8 80240298 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACE3DC 8024029C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACE3E0 802402A0 8FB10034 */  lw        $s1, 0x34($sp)
/* ACE3E4 802402A4 8FB00030 */  lw        $s0, 0x30($sp)
/* ACE3E8 802402A8 D7B80058 */  ldc1      $f24, 0x58($sp)
/* ACE3EC 802402AC D7B60050 */  ldc1      $f22, 0x50($sp)
/* ACE3F0 802402B0 D7B40048 */  ldc1      $f20, 0x48($sp)
/* ACE3F4 802402B4 24020002 */  addiu     $v0, $zero, 2
/* ACE3F8 802402B8 03E00008 */  jr        $ra
/* ACE3FC 802402BC 27BD0060 */   addiu    $sp, $sp, 0x60
