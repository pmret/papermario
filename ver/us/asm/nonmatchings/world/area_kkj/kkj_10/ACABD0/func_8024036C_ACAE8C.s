.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802435F0_ACE110
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_8024036C_ACAE8C
/* ACAE8C 8024036C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ACAE90 80240370 AFB7004C */  sw        $s7, 0x4c($sp)
/* ACAE94 80240374 0080B82D */  daddu     $s7, $a0, $zero
/* ACAE98 80240378 AFBF0054 */  sw        $ra, 0x54($sp)
/* ACAE9C 8024037C AFBE0050 */  sw        $fp, 0x50($sp)
/* ACAEA0 80240380 AFB60048 */  sw        $s6, 0x48($sp)
/* ACAEA4 80240384 AFB50044 */  sw        $s5, 0x44($sp)
/* ACAEA8 80240388 AFB40040 */  sw        $s4, 0x40($sp)
/* ACAEAC 8024038C AFB3003C */  sw        $s3, 0x3c($sp)
/* ACAEB0 80240390 AFB20038 */  sw        $s2, 0x38($sp)
/* ACAEB4 80240394 AFB10034 */  sw        $s1, 0x34($sp)
/* ACAEB8 80240398 AFB00030 */  sw        $s0, 0x30($sp)
/* ACAEBC 8024039C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* ACAEC0 802403A0 F7B80068 */  sdc1      $f24, 0x68($sp)
/* ACAEC4 802403A4 F7B60060 */  sdc1      $f22, 0x60($sp)
/* ACAEC8 802403A8 F7B40058 */  sdc1      $f20, 0x58($sp)
/* ACAECC 802403AC 8EE20148 */  lw        $v0, 0x148($s7)
/* ACAED0 802403B0 0C00EABB */  jal       get_npc_unsafe
/* ACAED4 802403B4 84440008 */   lh       $a0, 8($v0)
/* ACAED8 802403B8 27B50020 */  addiu     $s5, $sp, 0x20
/* ACAEDC 802403BC 02A0202D */  daddu     $a0, $s5, $zero
/* ACAEE0 802403C0 0040882D */  daddu     $s1, $v0, $zero
/* ACAEE4 802403C4 27B40024 */  addiu     $s4, $sp, 0x24
/* ACAEE8 802403C8 8EE3000C */  lw        $v1, 0xc($s7)
/* ACAEEC 802403CC 3C0641F0 */  lui       $a2, 0x41f0
/* ACAEF0 802403D0 8E27000C */  lw        $a3, 0xc($s1)
/* ACAEF4 802403D4 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACAEF8 802403D8 C6220040 */  lwc1      $f2, 0x40($s1)
/* ACAEFC 802403DC 8C7E0000 */  lw        $fp, ($v1)
/* ACAF00 802403E0 24630004 */  addiu     $v1, $v1, 4
/* ACAF04 802403E4 C4740000 */  lwc1      $f20, ($v1)
/* ACAF08 802403E8 4680A520 */  cvt.s.w   $f20, $f20
/* ACAF0C 802403EC 24630004 */  addiu     $v1, $v1, 4
/* ACAF10 802403F0 C4760000 */  lwc1      $f22, ($v1)
/* ACAF14 802403F4 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACAF18 802403F8 24630004 */  addiu     $v1, $v1, 4
/* ACAF1C 802403FC C4780000 */  lwc1      $f24, ($v1)
/* ACAF20 80240400 4680C620 */  cvt.s.w   $f24, $f24
/* ACAF24 80240404 24630004 */  addiu     $v1, $v1, 4
/* ACAF28 80240408 C47A0000 */  lwc1      $f26, ($v1)
/* ACAF2C 8024040C 4680D6A0 */  cvt.s.w   $f26, $f26
/* ACAF30 80240410 24630004 */  addiu     $v1, $v1, 4
/* ACAF34 80240414 8C760000 */  lw        $s6, ($v1)
/* ACAF38 80240418 8C700004 */  lw        $s0, 4($v1)
/* ACAF3C 8024041C 0280282D */  daddu     $a1, $s4, $zero
/* ACAF40 80240420 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACAF44 80240424 0C00A7E7 */  jal       add_vec2D_polar
/* ACAF48 80240428 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACAF4C 8024042C 3C038015 */  lui       $v1, %hi(D_80151328)
/* ACAF50 80240430 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* ACAF54 80240434 C7A00020 */  lwc1      $f0, 0x20($sp)
/* ACAF58 80240438 3C0141A0 */  lui       $at, 0x41a0
/* ACAF5C 8024043C 44811000 */  mtc1      $at, $f2
/* ACAF60 80240440 00101040 */  sll       $v0, $s0, 1
/* ACAF64 80240444 00501021 */  addu      $v0, $v0, $s0
/* ACAF68 80240448 000210C0 */  sll       $v0, $v0, 3
/* ACAF6C 8024044C 24420004 */  addiu     $v0, $v0, 4
/* ACAF70 80240450 00621821 */  addu      $v1, $v1, $v0
/* ACAF74 80240454 E4600004 */  swc1      $f0, 4($v1)
/* ACAF78 80240458 C620003C */  lwc1      $f0, 0x3c($s1)
/* ACAF7C 8024045C 4406A000 */  mfc1      $a2, $f20
/* ACAF80 80240460 46020000 */  add.s     $f0, $f0, $f2
/* ACAF84 80240464 C7A20024 */  lwc1      $f2, 0x24($sp)
/* ACAF88 80240468 02A0202D */  daddu     $a0, $s5, $zero
/* ACAF8C 8024046C E462000C */  swc1      $f2, 0xc($v1)
/* ACAF90 80240470 E4600008 */  swc1      $f0, 8($v1)
/* ACAF94 80240474 8E27000C */  lw        $a3, 0xc($s1)
/* ACAF98 80240478 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACAF9C 8024047C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACAFA0 80240480 0280282D */  daddu     $a1, $s4, $zero
/* ACAFA4 80240484 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACAFA8 80240488 0C00A7E7 */  jal       add_vec2D_polar
/* ACAFAC 8024048C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACAFB0 80240490 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACAFB4 80240494 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACAFB8 80240498 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACAFBC 8024049C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACAFC0 802404A0 8E460028 */  lw        $a2, 0x28($s2)
/* ACAFC4 802404A4 8E470030 */  lw        $a3, 0x30($s2)
/* ACAFC8 802404A8 0C00A7B5 */  jal       dist2D
/* ACAFCC 802404AC 0000802D */   daddu    $s0, $zero, $zero
/* ACAFD0 802404B0 4616003E */  c.le.s    $f0, $f22
/* ACAFD4 802404B4 00000000 */  nop
/* ACAFD8 802404B8 45000002 */  bc1f      .L802404C4
/* ACAFDC 802404BC 0240982D */   daddu    $s3, $s2, $zero
/* ACAFE0 802404C0 24100001 */  addiu     $s0, $zero, 1
.L802404C4:
/* ACAFE4 802404C4 4600B021 */  cvt.d.s   $f0, $f22
/* ACAFE8 802404C8 46200000 */  add.d     $f0, $f0, $f0
/* ACAFEC 802404CC 3C014059 */  lui       $at, 0x4059
/* ACAFF0 802404D0 44811800 */  mtc1      $at, $f3
/* ACAFF4 802404D4 44801000 */  mtc1      $zero, $f2
/* ACAFF8 802404D8 3C018024 */  lui       $at, %hi(D_802435F0_ACE110)
/* ACAFFC 802404DC D42435F0 */  ldc1      $f4, %lo(D_802435F0_ACE110)($at)
/* ACB000 802404E0 46220003 */  div.d     $f0, $f0, $f2
/* ACB004 802404E4 46240000 */  add.d     $f0, $f0, $f4
/* ACB008 802404E8 C7A20020 */  lwc1      $f2, 0x20($sp)
/* ACB00C 802404EC C7A40024 */  lwc1      $f4, 0x24($sp)
/* ACB010 802404F0 44051000 */  mfc1      $a1, $f2
/* ACB014 802404F4 44072000 */  mfc1      $a3, $f4
/* ACB018 802404F8 46200020 */  cvt.s.d   $f0, $f0
/* ACB01C 802404FC E7A00010 */  swc1      $f0, 0x10($sp)
/* ACB020 80240500 8E26003C */  lw        $a2, 0x3c($s1)
/* ACB024 80240504 0C0900B0 */  jal       func_802402C0_ACADE0
/* ACB028 80240508 02C0202D */   daddu    $a0, $s6, $zero
/* ACB02C 8024050C 02A0202D */  daddu     $a0, $s5, $zero
/* ACB030 80240510 4406C000 */  mfc1      $a2, $f24
/* ACB034 80240514 8E27000C */  lw        $a3, 0xc($s1)
/* ACB038 80240518 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACB03C 8024051C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACB040 80240520 0280282D */  daddu     $a1, $s4, $zero
/* ACB044 80240524 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB048 80240528 0C00A7E7 */  jal       add_vec2D_polar
/* ACB04C 8024052C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACB050 80240530 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACB054 80240534 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACB058 80240538 8E460028 */  lw        $a2, 0x28($s2)
/* ACB05C 8024053C 0C00A7B5 */  jal       dist2D
/* ACB060 80240540 8E470030 */   lw       $a3, 0x30($s2)
/* ACB064 80240544 461A003E */  c.le.s    $f0, $f26
/* ACB068 80240548 00000000 */  nop
/* ACB06C 8024054C 45030001 */  bc1tl     .L80240554
/* ACB070 80240550 36100010 */   ori      $s0, $s0, 0x10
.L80240554:
/* ACB074 80240554 32020001 */  andi      $v0, $s0, 1
/* ACB078 80240558 10400026 */  beqz      $v0, .L802405F4
/* ACB07C 8024055C 02E0202D */   daddu    $a0, $s7, $zero
/* ACB080 80240560 C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACB084 80240564 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACB088 80240568 8E660028 */  lw        $a2, 0x28($s3)
/* ACB08C 8024056C 8E670030 */  lw        $a3, 0x30($s3)
/* ACB090 80240570 C622003C */  lwc1      $f2, 0x3c($s1)
/* ACB094 80240574 46006006 */  mov.s     $f0, $f12
/* ACB098 80240578 46007106 */  mov.s     $f4, $f14
/* ACB09C 8024057C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB0A0 80240580 E7A20028 */  swc1      $f2, 0x28($sp)
/* ACB0A4 80240584 0C00A7B5 */  jal       dist2D
/* ACB0A8 80240588 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACB0AC 8024058C C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACB0B0 80240590 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACB0B4 80240594 8E660028 */  lw        $a2, 0x28($s3)
/* ACB0B8 80240598 8E670030 */  lw        $a3, 0x30($s3)
/* ACB0BC 8024059C 0C00A720 */  jal       atan2
/* ACB0C0 802405A0 46000506 */   mov.s    $f20, $f0
/* ACB0C4 802405A4 0000202D */  daddu     $a0, $zero, $zero
/* ACB0C8 802405A8 02A0282D */  daddu     $a1, $s5, $zero
/* ACB0CC 802405AC E7B40010 */  swc1      $f20, 0x10($sp)
/* ACB0D0 802405B0 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACB0D4 802405B4 862200A6 */  lh        $v0, 0xa6($s1)
/* ACB0D8 802405B8 27A60028 */  addiu     $a2, $sp, 0x28
/* ACB0DC 802405BC 44820000 */  mtc1      $v0, $f0
/* ACB0E0 802405C0 00000000 */  nop
/* ACB0E4 802405C4 46800020 */  cvt.s.w   $f0, $f0
/* ACB0E8 802405C8 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACB0EC 802405CC 862200A8 */  lh        $v0, 0xa8($s1)
/* ACB0F0 802405D0 0280382D */  daddu     $a3, $s4, $zero
/* ACB0F4 802405D4 44820000 */  mtc1      $v0, $f0
/* ACB0F8 802405D8 00000000 */  nop
/* ACB0FC 802405DC 46800020 */  cvt.s.w   $f0, $f0
/* ACB100 802405E0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACB104 802405E4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACB108 802405E8 54400001 */  bnel      $v0, $zero, .L802405F0
/* ACB10C 802405EC 0000802D */   daddu    $s0, $zero, $zero
.L802405F0:
/* ACB110 802405F0 02E0202D */  daddu     $a0, $s7, $zero
.L802405F4:
/* ACB114 802405F4 03C0282D */  daddu     $a1, $fp, $zero
/* ACB118 802405F8 0C0B2026 */  jal       evt_set_variable
/* ACB11C 802405FC 0200302D */   daddu    $a2, $s0, $zero
/* ACB120 80240600 8FBF0054 */  lw        $ra, 0x54($sp)
/* ACB124 80240604 8FBE0050 */  lw        $fp, 0x50($sp)
/* ACB128 80240608 8FB7004C */  lw        $s7, 0x4c($sp)
/* ACB12C 8024060C 8FB60048 */  lw        $s6, 0x48($sp)
/* ACB130 80240610 8FB50044 */  lw        $s5, 0x44($sp)
/* ACB134 80240614 8FB40040 */  lw        $s4, 0x40($sp)
/* ACB138 80240618 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACB13C 8024061C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACB140 80240620 8FB10034 */  lw        $s1, 0x34($sp)
/* ACB144 80240624 8FB00030 */  lw        $s0, 0x30($sp)
/* ACB148 80240628 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* ACB14C 8024062C D7B80068 */  ldc1      $f24, 0x68($sp)
/* ACB150 80240630 D7B60060 */  ldc1      $f22, 0x60($sp)
/* ACB154 80240634 D7B40058 */  ldc1      $f20, 0x58($sp)
/* ACB158 80240638 24020002 */  addiu     $v0, $zero, 2
/* ACB15C 8024063C 03E00008 */  jr        $ra
/* ACB160 80240640 27BD0078 */   addiu    $sp, $sp, 0x78
