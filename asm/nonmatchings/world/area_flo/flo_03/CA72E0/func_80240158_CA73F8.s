.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_CA73F8
/* CA73F8 80240158 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CA73FC 8024015C AFBF0020 */  sw        $ra, 0x20($sp)
/* CA7400 80240160 AFB1001C */  sw        $s1, 0x1c($sp)
/* CA7404 80240164 AFB00018 */  sw        $s0, 0x18($sp)
/* CA7408 80240168 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CA740C 8024016C F7B80038 */  sdc1      $f24, 0x38($sp)
/* CA7410 80240170 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CA7414 80240174 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CA7418 80240178 8C910148 */  lw        $s1, 0x148($a0)
/* CA741C 8024017C 0C00EABB */  jal       get_npc_unsafe
/* CA7420 80240180 86240008 */   lh       $a0, 8($s1)
/* CA7424 80240184 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* CA7428 80240188 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* CA742C 8024018C 0040802D */  daddu     $s0, $v0, $zero
/* CA7430 80240190 3C01C352 */  lui       $at, 0xc352
/* CA7434 80240194 4481B000 */  mtc1      $at, $f22
/* CA7438 80240198 3C01C337 */  lui       $at, 0xc337
/* CA743C 8024019C 4481C000 */  mtc1      $at, $f24
/* CA7440 802401A0 8C660028 */  lw        $a2, 0x28($v1)
/* CA7444 802401A4 8C670030 */  lw        $a3, 0x30($v1)
/* CA7448 802401A8 3C014334 */  lui       $at, 0x4334
/* CA744C 802401AC 4481D000 */  mtc1      $at, $f26
/* CA7450 802401B0 4600B306 */  mov.s     $f12, $f22
/* CA7454 802401B4 0C00A720 */  jal       atan2
/* CA7458 802401B8 4600C386 */   mov.s    $f14, $f24
/* CA745C 802401BC 0C00A6C9 */  jal       clamp_angle
/* CA7460 802401C0 461A0300 */   add.s    $f12, $f0, $f26
/* CA7464 802401C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CA7468 802401C8 3C064238 */  lui       $a2, 0x4238
/* CA746C 802401CC 44070000 */  mfc1      $a3, $f0
/* CA7470 802401D0 27A50014 */  addiu     $a1, $sp, 0x14
/* CA7474 802401D4 E7B60010 */  swc1      $f22, 0x10($sp)
/* CA7478 802401D8 0C00A7E7 */  jal       add_vec2D_polar
/* CA747C 802401DC E7B80014 */   swc1     $f24, 0x14($sp)
/* CA7480 802401E0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CA7484 802401E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CA7488 802401E8 8FA60010 */  lw        $a2, 0x10($sp)
/* CA748C 802401EC 0C00A7B5 */  jal       dist2D
/* CA7490 802401F0 8FA70014 */   lw       $a3, 0x14($sp)
/* CA7494 802401F4 3C014000 */  lui       $at, 0x4000
/* CA7498 802401F8 44811800 */  mtc1      $at, $f3
/* CA749C 802401FC 44801000 */  mtc1      $zero, $f2
/* CA74A0 80240200 46000121 */  cvt.d.s   $f4, $f0
/* CA74A4 80240204 4624103C */  c.lt.d    $f2, $f4
/* CA74A8 80240208 00000000 */  nop
/* CA74AC 8024020C 45000053 */  bc1f      .L8024035C
/* CA74B0 80240210 4600B306 */   mov.s    $f12, $f22
/* CA74B4 80240214 8E060038 */  lw        $a2, 0x38($s0)
/* CA74B8 80240218 8E070040 */  lw        $a3, 0x40($s0)
/* CA74BC 8024021C 0C00A720 */  jal       atan2
/* CA74C0 80240220 4600C386 */   mov.s    $f14, $f24
/* CA74C4 80240224 0C00A6C9 */  jal       clamp_angle
/* CA74C8 80240228 46000306 */   mov.s    $f12, $f0
/* CA74CC 8024022C 4600B306 */  mov.s     $f12, $f22
/* CA74D0 80240230 4600C386 */  mov.s     $f14, $f24
/* CA74D4 80240234 8FA60010 */  lw        $a2, 0x10($sp)
/* CA74D8 80240238 8FA70014 */  lw        $a3, 0x14($sp)
/* CA74DC 8024023C 0C00A720 */  jal       atan2
/* CA74E0 80240240 46000506 */   mov.s    $f20, $f0
/* CA74E4 80240244 0C00A6C9 */  jal       clamp_angle
/* CA74E8 80240248 46000306 */   mov.s    $f12, $f0
/* CA74EC 8024024C 4600A101 */  sub.s     $f4, $f20, $f0
/* CA74F0 80240250 4600218D */  trunc.w.s $f6, $f4
/* CA74F4 80240254 44023000 */  mfc1      $v0, $f6
/* CA74F8 80240258 00000000 */  nop
/* CA74FC 8024025C 04420001 */  bltzl     $v0, .L80240264
/* CA7500 80240260 00021023 */   negu     $v0, $v0
.L80240264:
/* CA7504 80240264 28420015 */  slti      $v0, $v0, 0x15
/* CA7508 80240268 1440002D */  bnez      $v0, .L80240320
/* CA750C 8024026C 00000000 */   nop
/* CA7510 80240270 4604D03E */  c.le.s    $f26, $f4
/* CA7514 80240274 00000000 */  nop
/* CA7518 80240278 45000005 */  bc1f      .L80240290
/* CA751C 8024027C 46002086 */   mov.s    $f2, $f4
/* CA7520 80240280 3C0143B4 */  lui       $at, 0x43b4
/* CA7524 80240284 44810000 */  mtc1      $at, $f0
/* CA7528 80240288 00000000 */  nop
/* CA752C 8024028C 46002081 */  sub.s     $f2, $f4, $f0
.L80240290:
/* CA7530 80240290 3C01C334 */  lui       $at, 0xc334
/* CA7534 80240294 44810000 */  mtc1      $at, $f0
/* CA7538 80240298 00000000 */  nop
/* CA753C 8024029C 4600103E */  c.le.s    $f2, $f0
/* CA7540 802402A0 00000000 */  nop
/* CA7544 802402A4 45000005 */  bc1f      .L802402BC
/* CA7548 802402A8 00000000 */   nop
/* CA754C 802402AC 3C0143B4 */  lui       $at, 0x43b4
/* CA7550 802402B0 44810000 */  mtc1      $at, $f0
/* CA7554 802402B4 00000000 */  nop
/* CA7558 802402B8 46001080 */  add.s     $f2, $f2, $f0
.L802402BC:
/* CA755C 802402BC 46022032 */  c.eq.s    $f4, $f2
/* CA7560 802402C0 00000000 */  nop
/* CA7564 802402C4 45000016 */  bc1f      .L80240320
/* CA7568 802402C8 00000000 */   nop
/* CA756C 802402CC 44800000 */  mtc1      $zero, $f0
/* CA7570 802402D0 E7B60010 */  swc1      $f22, 0x10($sp)
/* CA7574 802402D4 4604003E */  c.le.s    $f0, $f4
/* CA7578 802402D8 00000000 */  nop
/* CA757C 802402DC 45000005 */  bc1f      .L802402F4
/* CA7580 802402E0 E7B80014 */   swc1     $f24, 0x14($sp)
/* CA7584 802402E4 3C0141A0 */  lui       $at, 0x41a0
/* CA7588 802402E8 44816000 */  mtc1      $at, $f12
/* CA758C 802402EC 080900C1 */  j         .L80240304
/* CA7590 802402F0 460CA301 */   sub.s    $f12, $f20, $f12
.L802402F4:
/* CA7594 802402F4 3C0141A0 */  lui       $at, 0x41a0
/* CA7598 802402F8 44816000 */  mtc1      $at, $f12
/* CA759C 802402FC 00000000 */  nop
/* CA75A0 80240300 460CA300 */  add.s     $f12, $f20, $f12
.L80240304:
/* CA75A4 80240304 0C00A6C9 */  jal       clamp_angle
/* CA75A8 80240308 00000000 */   nop
/* CA75AC 8024030C 27A40010 */  addiu     $a0, $sp, 0x10
/* CA75B0 80240310 3C064238 */  lui       $a2, 0x4238
/* CA75B4 80240314 44070000 */  mfc1      $a3, $f0
/* CA75B8 80240318 0C00A7E7 */  jal       add_vec2D_polar
/* CA75BC 8024031C 27A50014 */   addiu    $a1, $sp, 0x14
.L80240320:
/* CA75C0 80240320 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CA75C4 80240324 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CA75C8 80240328 8FA60010 */  lw        $a2, 0x10($sp)
/* CA75CC 8024032C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CA75D0 80240330 8FA70014 */  lw        $a3, 0x14($sp)
/* CA75D4 80240334 8C420008 */  lw        $v0, 8($v0)
/* CA75D8 80240338 0C00A720 */  jal       atan2
/* CA75DC 8024033C AE020028 */   sw       $v0, 0x28($s0)
/* CA75E0 80240340 3C054000 */  lui       $a1, 0x4000
/* CA75E4 80240344 44060000 */  mfc1      $a2, $f0
/* CA75E8 80240348 0200202D */  daddu     $a0, $s0, $zero
/* CA75EC 8024034C 0C00EA95 */  jal       npc_move_heading
/* CA75F0 80240350 AC86000C */   sw       $a2, 0xc($a0)
/* CA75F4 80240354 080900F2 */  j         .L802403C8
/* CA75F8 80240358 00000000 */   nop
.L8024035C:
/* CA75FC 8024035C 3C018024 */  lui       $at, %hi(D_80244F48)
/* CA7600 80240360 D4204F48 */  ldc1      $f0, %lo(D_80244F48)($at)
/* CA7604 80240364 4624003C */  c.lt.d    $f0, $f4
/* CA7608 80240368 00000000 */  nop
/* CA760C 8024036C 4500000F */  bc1f      .L802403AC
/* CA7610 80240370 00000000 */   nop
/* CA7614 80240374 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CA7618 80240378 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CA761C 8024037C 8FA60010 */  lw        $a2, 0x10($sp)
/* CA7620 80240380 0C00A720 */  jal       atan2
/* CA7624 80240384 8FA70014 */   lw       $a3, 0x14($sp)
/* CA7628 80240388 C7A20010 */  lwc1      $f2, 0x10($sp)
/* CA762C 8024038C C7A40014 */  lwc1      $f4, 0x14($sp)
/* CA7630 80240390 E600000C */  swc1      $f0, 0xc($s0)
/* CA7634 80240394 E6020038 */  swc1      $f2, 0x38($s0)
/* CA7638 80240398 E6040040 */  swc1      $f4, 0x40($s0)
/* CA763C 8024039C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CA7640 802403A0 8C420004 */  lw        $v0, 4($v0)
/* CA7644 802403A4 080900F2 */  j         .L802403C8
/* CA7648 802403A8 AE020028 */   sw       $v0, 0x28($s0)
.L802403AC:
/* CA764C 802403AC C7A00010 */  lwc1      $f0, 0x10($sp)
/* CA7650 802403B0 C7A20014 */  lwc1      $f2, 0x14($sp)
/* CA7654 802403B4 E6000038 */  swc1      $f0, 0x38($s0)
/* CA7658 802403B8 E6020040 */  swc1      $f2, 0x40($s0)
/* CA765C 802403BC 8E2200CC */  lw        $v0, 0xcc($s1)
/* CA7660 802403C0 8C420000 */  lw        $v0, ($v0)
/* CA7664 802403C4 AE020028 */  sw        $v0, 0x28($s0)
.L802403C8:
/* CA7668 802403C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* CA766C 802403CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* CA7670 802403D0 8FB00018 */  lw        $s0, 0x18($sp)
/* CA7674 802403D4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CA7678 802403D8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CA767C 802403DC D7B60030 */  ldc1      $f22, 0x30($sp)
/* CA7680 802403E0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CA7684 802403E4 0000102D */  daddu     $v0, $zero, $zero
/* CA7688 802403E8 03E00008 */  jr        $ra
/* CA768C 802403EC 27BD0048 */   addiu    $sp, $sp, 0x48
