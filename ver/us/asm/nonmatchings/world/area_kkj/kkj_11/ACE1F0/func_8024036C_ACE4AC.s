.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80245F20_AD4060
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_8024036C_ACE4AC
/* ACE4AC 8024036C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ACE4B0 80240370 AFB7004C */  sw        $s7, 0x4c($sp)
/* ACE4B4 80240374 0080B82D */  daddu     $s7, $a0, $zero
/* ACE4B8 80240378 AFBF0054 */  sw        $ra, 0x54($sp)
/* ACE4BC 8024037C AFBE0050 */  sw        $fp, 0x50($sp)
/* ACE4C0 80240380 AFB60048 */  sw        $s6, 0x48($sp)
/* ACE4C4 80240384 AFB50044 */  sw        $s5, 0x44($sp)
/* ACE4C8 80240388 AFB40040 */  sw        $s4, 0x40($sp)
/* ACE4CC 8024038C AFB3003C */  sw        $s3, 0x3c($sp)
/* ACE4D0 80240390 AFB20038 */  sw        $s2, 0x38($sp)
/* ACE4D4 80240394 AFB10034 */  sw        $s1, 0x34($sp)
/* ACE4D8 80240398 AFB00030 */  sw        $s0, 0x30($sp)
/* ACE4DC 8024039C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* ACE4E0 802403A0 F7B80068 */  sdc1      $f24, 0x68($sp)
/* ACE4E4 802403A4 F7B60060 */  sdc1      $f22, 0x60($sp)
/* ACE4E8 802403A8 F7B40058 */  sdc1      $f20, 0x58($sp)
/* ACE4EC 802403AC 8EE20148 */  lw        $v0, 0x148($s7)
/* ACE4F0 802403B0 0C00EABB */  jal       get_npc_unsafe
/* ACE4F4 802403B4 84440008 */   lh       $a0, 8($v0)
/* ACE4F8 802403B8 27B50020 */  addiu     $s5, $sp, 0x20
/* ACE4FC 802403BC 02A0202D */  daddu     $a0, $s5, $zero
/* ACE500 802403C0 0040882D */  daddu     $s1, $v0, $zero
/* ACE504 802403C4 27B40024 */  addiu     $s4, $sp, 0x24
/* ACE508 802403C8 8EE3000C */  lw        $v1, 0xc($s7)
/* ACE50C 802403CC 3C0641F0 */  lui       $a2, 0x41f0
/* ACE510 802403D0 8E27000C */  lw        $a3, 0xc($s1)
/* ACE514 802403D4 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACE518 802403D8 C6220040 */  lwc1      $f2, 0x40($s1)
/* ACE51C 802403DC 8C7E0000 */  lw        $fp, ($v1)
/* ACE520 802403E0 24630004 */  addiu     $v1, $v1, 4
/* ACE524 802403E4 C4740000 */  lwc1      $f20, ($v1)
/* ACE528 802403E8 4680A520 */  cvt.s.w   $f20, $f20
/* ACE52C 802403EC 24630004 */  addiu     $v1, $v1, 4
/* ACE530 802403F0 C4760000 */  lwc1      $f22, ($v1)
/* ACE534 802403F4 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACE538 802403F8 24630004 */  addiu     $v1, $v1, 4
/* ACE53C 802403FC C4780000 */  lwc1      $f24, ($v1)
/* ACE540 80240400 4680C620 */  cvt.s.w   $f24, $f24
/* ACE544 80240404 24630004 */  addiu     $v1, $v1, 4
/* ACE548 80240408 C47A0000 */  lwc1      $f26, ($v1)
/* ACE54C 8024040C 4680D6A0 */  cvt.s.w   $f26, $f26
/* ACE550 80240410 24630004 */  addiu     $v1, $v1, 4
/* ACE554 80240414 8C760000 */  lw        $s6, ($v1)
/* ACE558 80240418 8C700004 */  lw        $s0, 4($v1)
/* ACE55C 8024041C 0280282D */  daddu     $a1, $s4, $zero
/* ACE560 80240420 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE564 80240424 0C00A7E7 */  jal       add_vec2D_polar
/* ACE568 80240428 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACE56C 8024042C 3C038015 */  lui       $v1, %hi(D_80151328)
/* ACE570 80240430 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* ACE574 80240434 C7A00020 */  lwc1      $f0, 0x20($sp)
/* ACE578 80240438 3C0141A0 */  lui       $at, 0x41a0
/* ACE57C 8024043C 44811000 */  mtc1      $at, $f2
/* ACE580 80240440 00101040 */  sll       $v0, $s0, 1
/* ACE584 80240444 00501021 */  addu      $v0, $v0, $s0
/* ACE588 80240448 000210C0 */  sll       $v0, $v0, 3
/* ACE58C 8024044C 24420004 */  addiu     $v0, $v0, 4
/* ACE590 80240450 00621821 */  addu      $v1, $v1, $v0
/* ACE594 80240454 E4600004 */  swc1      $f0, 4($v1)
/* ACE598 80240458 C620003C */  lwc1      $f0, 0x3c($s1)
/* ACE59C 8024045C 4406A000 */  mfc1      $a2, $f20
/* ACE5A0 80240460 46020000 */  add.s     $f0, $f0, $f2
/* ACE5A4 80240464 C7A20024 */  lwc1      $f2, 0x24($sp)
/* ACE5A8 80240468 02A0202D */  daddu     $a0, $s5, $zero
/* ACE5AC 8024046C E462000C */  swc1      $f2, 0xc($v1)
/* ACE5B0 80240470 E4600008 */  swc1      $f0, 8($v1)
/* ACE5B4 80240474 8E27000C */  lw        $a3, 0xc($s1)
/* ACE5B8 80240478 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACE5BC 8024047C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACE5C0 80240480 0280282D */  daddu     $a1, $s4, $zero
/* ACE5C4 80240484 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE5C8 80240488 0C00A7E7 */  jal       add_vec2D_polar
/* ACE5CC 8024048C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACE5D0 80240490 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACE5D4 80240494 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACE5D8 80240498 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACE5DC 8024049C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACE5E0 802404A0 8E460028 */  lw        $a2, 0x28($s2)
/* ACE5E4 802404A4 8E470030 */  lw        $a3, 0x30($s2)
/* ACE5E8 802404A8 0C00A7B5 */  jal       dist2D
/* ACE5EC 802404AC 0000802D */   daddu    $s0, $zero, $zero
/* ACE5F0 802404B0 4616003E */  c.le.s    $f0, $f22
/* ACE5F4 802404B4 00000000 */  nop
/* ACE5F8 802404B8 45000002 */  bc1f      .L802404C4
/* ACE5FC 802404BC 0240982D */   daddu    $s3, $s2, $zero
/* ACE600 802404C0 24100001 */  addiu     $s0, $zero, 1
.L802404C4:
/* ACE604 802404C4 4600B021 */  cvt.d.s   $f0, $f22
/* ACE608 802404C8 46200000 */  add.d     $f0, $f0, $f0
/* ACE60C 802404CC 3C014059 */  lui       $at, 0x4059
/* ACE610 802404D0 44811800 */  mtc1      $at, $f3
/* ACE614 802404D4 44801000 */  mtc1      $zero, $f2
/* ACE618 802404D8 3C018024 */  lui       $at, %hi(D_80245F20_AD4060)
/* ACE61C 802404DC D4245F20 */  ldc1      $f4, %lo(D_80245F20_AD4060)($at)
/* ACE620 802404E0 46220003 */  div.d     $f0, $f0, $f2
/* ACE624 802404E4 46240000 */  add.d     $f0, $f0, $f4
/* ACE628 802404E8 C7A20020 */  lwc1      $f2, 0x20($sp)
/* ACE62C 802404EC C7A40024 */  lwc1      $f4, 0x24($sp)
/* ACE630 802404F0 44051000 */  mfc1      $a1, $f2
/* ACE634 802404F4 44072000 */  mfc1      $a3, $f4
/* ACE638 802404F8 46200020 */  cvt.s.d   $f0, $f0
/* ACE63C 802404FC E7A00010 */  swc1      $f0, 0x10($sp)
/* ACE640 80240500 8E26003C */  lw        $a2, 0x3c($s1)
/* ACE644 80240504 0C0900B0 */  jal       func_802402C0_ACE400
/* ACE648 80240508 02C0202D */   daddu    $a0, $s6, $zero
/* ACE64C 8024050C 02A0202D */  daddu     $a0, $s5, $zero
/* ACE650 80240510 4406C000 */  mfc1      $a2, $f24
/* ACE654 80240514 8E27000C */  lw        $a3, 0xc($s1)
/* ACE658 80240518 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACE65C 8024051C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACE660 80240520 0280282D */  daddu     $a1, $s4, $zero
/* ACE664 80240524 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE668 80240528 0C00A7E7 */  jal       add_vec2D_polar
/* ACE66C 8024052C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACE670 80240530 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACE674 80240534 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACE678 80240538 8E460028 */  lw        $a2, 0x28($s2)
/* ACE67C 8024053C 0C00A7B5 */  jal       dist2D
/* ACE680 80240540 8E470030 */   lw       $a3, 0x30($s2)
/* ACE684 80240544 461A003E */  c.le.s    $f0, $f26
/* ACE688 80240548 00000000 */  nop
/* ACE68C 8024054C 45030001 */  bc1tl     .L80240554
/* ACE690 80240550 36100010 */   ori      $s0, $s0, 0x10
.L80240554:
/* ACE694 80240554 32020001 */  andi      $v0, $s0, 1
/* ACE698 80240558 10400026 */  beqz      $v0, .L802405F4
/* ACE69C 8024055C 02E0202D */   daddu    $a0, $s7, $zero
/* ACE6A0 80240560 C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACE6A4 80240564 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACE6A8 80240568 8E660028 */  lw        $a2, 0x28($s3)
/* ACE6AC 8024056C 8E670030 */  lw        $a3, 0x30($s3)
/* ACE6B0 80240570 C622003C */  lwc1      $f2, 0x3c($s1)
/* ACE6B4 80240574 46006006 */  mov.s     $f0, $f12
/* ACE6B8 80240578 46007106 */  mov.s     $f4, $f14
/* ACE6BC 8024057C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACE6C0 80240580 E7A20028 */  swc1      $f2, 0x28($sp)
/* ACE6C4 80240584 0C00A7B5 */  jal       dist2D
/* ACE6C8 80240588 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACE6CC 8024058C C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACE6D0 80240590 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACE6D4 80240594 8E660028 */  lw        $a2, 0x28($s3)
/* ACE6D8 80240598 8E670030 */  lw        $a3, 0x30($s3)
/* ACE6DC 8024059C 0C00A720 */  jal       atan2
/* ACE6E0 802405A0 46000506 */   mov.s    $f20, $f0
/* ACE6E4 802405A4 0000202D */  daddu     $a0, $zero, $zero
/* ACE6E8 802405A8 02A0282D */  daddu     $a1, $s5, $zero
/* ACE6EC 802405AC E7B40010 */  swc1      $f20, 0x10($sp)
/* ACE6F0 802405B0 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACE6F4 802405B4 862200A6 */  lh        $v0, 0xa6($s1)
/* ACE6F8 802405B8 27A60028 */  addiu     $a2, $sp, 0x28
/* ACE6FC 802405BC 44820000 */  mtc1      $v0, $f0
/* ACE700 802405C0 00000000 */  nop
/* ACE704 802405C4 46800020 */  cvt.s.w   $f0, $f0
/* ACE708 802405C8 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACE70C 802405CC 862200A8 */  lh        $v0, 0xa8($s1)
/* ACE710 802405D0 0280382D */  daddu     $a3, $s4, $zero
/* ACE714 802405D4 44820000 */  mtc1      $v0, $f0
/* ACE718 802405D8 00000000 */  nop
/* ACE71C 802405DC 46800020 */  cvt.s.w   $f0, $f0
/* ACE720 802405E0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACE724 802405E4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACE728 802405E8 54400001 */  bnel      $v0, $zero, .L802405F0
/* ACE72C 802405EC 0000802D */   daddu    $s0, $zero, $zero
.L802405F0:
/* ACE730 802405F0 02E0202D */  daddu     $a0, $s7, $zero
.L802405F4:
/* ACE734 802405F4 03C0282D */  daddu     $a1, $fp, $zero
/* ACE738 802405F8 0C0B2026 */  jal       evt_set_variable
/* ACE73C 802405FC 0200302D */   daddu    $a2, $s0, $zero
/* ACE740 80240600 8FBF0054 */  lw        $ra, 0x54($sp)
/* ACE744 80240604 8FBE0050 */  lw        $fp, 0x50($sp)
/* ACE748 80240608 8FB7004C */  lw        $s7, 0x4c($sp)
/* ACE74C 8024060C 8FB60048 */  lw        $s6, 0x48($sp)
/* ACE750 80240610 8FB50044 */  lw        $s5, 0x44($sp)
/* ACE754 80240614 8FB40040 */  lw        $s4, 0x40($sp)
/* ACE758 80240618 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACE75C 8024061C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACE760 80240620 8FB10034 */  lw        $s1, 0x34($sp)
/* ACE764 80240624 8FB00030 */  lw        $s0, 0x30($sp)
/* ACE768 80240628 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* ACE76C 8024062C D7B80068 */  ldc1      $f24, 0x68($sp)
/* ACE770 80240630 D7B60060 */  ldc1      $f22, 0x60($sp)
/* ACE774 80240634 D7B40058 */  ldc1      $f20, 0x58($sp)
/* ACE778 80240638 24020002 */  addiu     $v0, $zero, 2
/* ACE77C 8024063C 03E00008 */  jr        $ra
/* ACE780 80240640 27BD0078 */   addiu    $sp, $sp, 0x78
