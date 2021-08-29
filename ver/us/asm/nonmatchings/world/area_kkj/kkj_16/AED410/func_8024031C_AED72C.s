.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244820_AF1C30
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_8024031C_AED72C
/* AED72C 8024031C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* AED730 80240320 AFB7004C */  sw        $s7, 0x4c($sp)
/* AED734 80240324 0080B82D */  daddu     $s7, $a0, $zero
/* AED738 80240328 AFBF0054 */  sw        $ra, 0x54($sp)
/* AED73C 8024032C AFBE0050 */  sw        $fp, 0x50($sp)
/* AED740 80240330 AFB60048 */  sw        $s6, 0x48($sp)
/* AED744 80240334 AFB50044 */  sw        $s5, 0x44($sp)
/* AED748 80240338 AFB40040 */  sw        $s4, 0x40($sp)
/* AED74C 8024033C AFB3003C */  sw        $s3, 0x3c($sp)
/* AED750 80240340 AFB20038 */  sw        $s2, 0x38($sp)
/* AED754 80240344 AFB10034 */  sw        $s1, 0x34($sp)
/* AED758 80240348 AFB00030 */  sw        $s0, 0x30($sp)
/* AED75C 8024034C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* AED760 80240350 F7B80068 */  sdc1      $f24, 0x68($sp)
/* AED764 80240354 F7B60060 */  sdc1      $f22, 0x60($sp)
/* AED768 80240358 F7B40058 */  sdc1      $f20, 0x58($sp)
/* AED76C 8024035C 8EE20148 */  lw        $v0, 0x148($s7)
/* AED770 80240360 0C00EABB */  jal       get_npc_unsafe
/* AED774 80240364 84440008 */   lh       $a0, 8($v0)
/* AED778 80240368 27B50020 */  addiu     $s5, $sp, 0x20
/* AED77C 8024036C 02A0202D */  daddu     $a0, $s5, $zero
/* AED780 80240370 0040882D */  daddu     $s1, $v0, $zero
/* AED784 80240374 27B40024 */  addiu     $s4, $sp, 0x24
/* AED788 80240378 8EE3000C */  lw        $v1, 0xc($s7)
/* AED78C 8024037C 3C0641F0 */  lui       $a2, 0x41f0
/* AED790 80240380 8E27000C */  lw        $a3, 0xc($s1)
/* AED794 80240384 C6200038 */  lwc1      $f0, 0x38($s1)
/* AED798 80240388 C6220040 */  lwc1      $f2, 0x40($s1)
/* AED79C 8024038C 8C7E0000 */  lw        $fp, ($v1)
/* AED7A0 80240390 24630004 */  addiu     $v1, $v1, 4
/* AED7A4 80240394 C4740000 */  lwc1      $f20, ($v1)
/* AED7A8 80240398 4680A520 */  cvt.s.w   $f20, $f20
/* AED7AC 8024039C 24630004 */  addiu     $v1, $v1, 4
/* AED7B0 802403A0 C4760000 */  lwc1      $f22, ($v1)
/* AED7B4 802403A4 4680B5A0 */  cvt.s.w   $f22, $f22
/* AED7B8 802403A8 24630004 */  addiu     $v1, $v1, 4
/* AED7BC 802403AC C4780000 */  lwc1      $f24, ($v1)
/* AED7C0 802403B0 4680C620 */  cvt.s.w   $f24, $f24
/* AED7C4 802403B4 24630004 */  addiu     $v1, $v1, 4
/* AED7C8 802403B8 C47A0000 */  lwc1      $f26, ($v1)
/* AED7CC 802403BC 4680D6A0 */  cvt.s.w   $f26, $f26
/* AED7D0 802403C0 24630004 */  addiu     $v1, $v1, 4
/* AED7D4 802403C4 8C760000 */  lw        $s6, ($v1)
/* AED7D8 802403C8 8C700004 */  lw        $s0, 4($v1)
/* AED7DC 802403CC 0280282D */  daddu     $a1, $s4, $zero
/* AED7E0 802403D0 E7A00020 */  swc1      $f0, 0x20($sp)
/* AED7E4 802403D4 0C00A7E7 */  jal       add_vec2D_polar
/* AED7E8 802403D8 E7A20024 */   swc1     $f2, 0x24($sp)
/* AED7EC 802403DC 3C038015 */  lui       $v1, %hi(D_80151328)
/* AED7F0 802403E0 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* AED7F4 802403E4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* AED7F8 802403E8 3C0141A0 */  lui       $at, 0x41a0
/* AED7FC 802403EC 44811000 */  mtc1      $at, $f2
/* AED800 802403F0 00101040 */  sll       $v0, $s0, 1
/* AED804 802403F4 00501021 */  addu      $v0, $v0, $s0
/* AED808 802403F8 000210C0 */  sll       $v0, $v0, 3
/* AED80C 802403FC 24420004 */  addiu     $v0, $v0, 4
/* AED810 80240400 00621821 */  addu      $v1, $v1, $v0
/* AED814 80240404 E4600004 */  swc1      $f0, 4($v1)
/* AED818 80240408 C620003C */  lwc1      $f0, 0x3c($s1)
/* AED81C 8024040C 4406A000 */  mfc1      $a2, $f20
/* AED820 80240410 46020000 */  add.s     $f0, $f0, $f2
/* AED824 80240414 C7A20024 */  lwc1      $f2, 0x24($sp)
/* AED828 80240418 02A0202D */  daddu     $a0, $s5, $zero
/* AED82C 8024041C E462000C */  swc1      $f2, 0xc($v1)
/* AED830 80240420 E4600008 */  swc1      $f0, 8($v1)
/* AED834 80240424 8E27000C */  lw        $a3, 0xc($s1)
/* AED838 80240428 C6200038 */  lwc1      $f0, 0x38($s1)
/* AED83C 8024042C C6220040 */  lwc1      $f2, 0x40($s1)
/* AED840 80240430 0280282D */  daddu     $a1, $s4, $zero
/* AED844 80240434 E7A00020 */  swc1      $f0, 0x20($sp)
/* AED848 80240438 0C00A7E7 */  jal       add_vec2D_polar
/* AED84C 8024043C E7A20024 */   swc1     $f2, 0x24($sp)
/* AED850 80240440 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AED854 80240444 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AED858 80240448 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AED85C 8024044C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AED860 80240450 8E460028 */  lw        $a2, 0x28($s2)
/* AED864 80240454 8E470030 */  lw        $a3, 0x30($s2)
/* AED868 80240458 0C00A7B5 */  jal       dist2D
/* AED86C 8024045C 0000802D */   daddu    $s0, $zero, $zero
/* AED870 80240460 4616003E */  c.le.s    $f0, $f22
/* AED874 80240464 00000000 */  nop
/* AED878 80240468 45000002 */  bc1f      .L80240474
/* AED87C 8024046C 0240982D */   daddu    $s3, $s2, $zero
/* AED880 80240470 24100001 */  addiu     $s0, $zero, 1
.L80240474:
/* AED884 80240474 4600B021 */  cvt.d.s   $f0, $f22
/* AED888 80240478 46200000 */  add.d     $f0, $f0, $f0
/* AED88C 8024047C 3C014059 */  lui       $at, 0x4059
/* AED890 80240480 44811800 */  mtc1      $at, $f3
/* AED894 80240484 44801000 */  mtc1      $zero, $f2
/* AED898 80240488 3C018024 */  lui       $at, %hi(D_80244820_AF1C30)
/* AED89C 8024048C D4244820 */  ldc1      $f4, %lo(D_80244820_AF1C30)($at)
/* AED8A0 80240490 46220003 */  div.d     $f0, $f0, $f2
/* AED8A4 80240494 46240000 */  add.d     $f0, $f0, $f4
/* AED8A8 80240498 C7A20020 */  lwc1      $f2, 0x20($sp)
/* AED8AC 8024049C C7A40024 */  lwc1      $f4, 0x24($sp)
/* AED8B0 802404A0 44051000 */  mfc1      $a1, $f2
/* AED8B4 802404A4 44072000 */  mfc1      $a3, $f4
/* AED8B8 802404A8 46200020 */  cvt.s.d   $f0, $f0
/* AED8BC 802404AC E7A00010 */  swc1      $f0, 0x10($sp)
/* AED8C0 802404B0 8E26003C */  lw        $a2, 0x3c($s1)
/* AED8C4 802404B4 0C09009C */  jal       func_80240270_AED680
/* AED8C8 802404B8 02C0202D */   daddu    $a0, $s6, $zero
/* AED8CC 802404BC 02A0202D */  daddu     $a0, $s5, $zero
/* AED8D0 802404C0 4406C000 */  mfc1      $a2, $f24
/* AED8D4 802404C4 8E27000C */  lw        $a3, 0xc($s1)
/* AED8D8 802404C8 C6200038 */  lwc1      $f0, 0x38($s1)
/* AED8DC 802404CC C6220040 */  lwc1      $f2, 0x40($s1)
/* AED8E0 802404D0 0280282D */  daddu     $a1, $s4, $zero
/* AED8E4 802404D4 E7A00020 */  swc1      $f0, 0x20($sp)
/* AED8E8 802404D8 0C00A7E7 */  jal       add_vec2D_polar
/* AED8EC 802404DC E7A20024 */   swc1     $f2, 0x24($sp)
/* AED8F0 802404E0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AED8F4 802404E4 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AED8F8 802404E8 8E460028 */  lw        $a2, 0x28($s2)
/* AED8FC 802404EC 0C00A7B5 */  jal       dist2D
/* AED900 802404F0 8E470030 */   lw       $a3, 0x30($s2)
/* AED904 802404F4 461A003E */  c.le.s    $f0, $f26
/* AED908 802404F8 00000000 */  nop
/* AED90C 802404FC 45030001 */  bc1tl     .L80240504
/* AED910 80240500 36100010 */   ori      $s0, $s0, 0x10
.L80240504:
/* AED914 80240504 32020001 */  andi      $v0, $s0, 1
/* AED918 80240508 10400026 */  beqz      $v0, .L802405A4
/* AED91C 8024050C 02E0202D */   daddu    $a0, $s7, $zero
/* AED920 80240510 C62C0038 */  lwc1      $f12, 0x38($s1)
/* AED924 80240514 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AED928 80240518 8E660028 */  lw        $a2, 0x28($s3)
/* AED92C 8024051C 8E670030 */  lw        $a3, 0x30($s3)
/* AED930 80240520 C622003C */  lwc1      $f2, 0x3c($s1)
/* AED934 80240524 46006006 */  mov.s     $f0, $f12
/* AED938 80240528 46007106 */  mov.s     $f4, $f14
/* AED93C 8024052C E7A00020 */  swc1      $f0, 0x20($sp)
/* AED940 80240530 E7A20028 */  swc1      $f2, 0x28($sp)
/* AED944 80240534 0C00A7B5 */  jal       dist2D
/* AED948 80240538 E7A40024 */   swc1     $f4, 0x24($sp)
/* AED94C 8024053C C62C0038 */  lwc1      $f12, 0x38($s1)
/* AED950 80240540 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AED954 80240544 8E660028 */  lw        $a2, 0x28($s3)
/* AED958 80240548 8E670030 */  lw        $a3, 0x30($s3)
/* AED95C 8024054C 0C00A720 */  jal       atan2
/* AED960 80240550 46000506 */   mov.s    $f20, $f0
/* AED964 80240554 0000202D */  daddu     $a0, $zero, $zero
/* AED968 80240558 02A0282D */  daddu     $a1, $s5, $zero
/* AED96C 8024055C E7B40010 */  swc1      $f20, 0x10($sp)
/* AED970 80240560 E7A00014 */  swc1      $f0, 0x14($sp)
/* AED974 80240564 862200A6 */  lh        $v0, 0xa6($s1)
/* AED978 80240568 27A60028 */  addiu     $a2, $sp, 0x28
/* AED97C 8024056C 44820000 */  mtc1      $v0, $f0
/* AED980 80240570 00000000 */  nop
/* AED984 80240574 46800020 */  cvt.s.w   $f0, $f0
/* AED988 80240578 E7A00018 */  swc1      $f0, 0x18($sp)
/* AED98C 8024057C 862200A8 */  lh        $v0, 0xa8($s1)
/* AED990 80240580 0280382D */  daddu     $a3, $s4, $zero
/* AED994 80240584 44820000 */  mtc1      $v0, $f0
/* AED998 80240588 00000000 */  nop
/* AED99C 8024058C 46800020 */  cvt.s.w   $f0, $f0
/* AED9A0 80240590 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* AED9A4 80240594 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AED9A8 80240598 54400001 */  bnel      $v0, $zero, .L802405A0
/* AED9AC 8024059C 0000802D */   daddu    $s0, $zero, $zero
.L802405A0:
/* AED9B0 802405A0 02E0202D */  daddu     $a0, $s7, $zero
.L802405A4:
/* AED9B4 802405A4 03C0282D */  daddu     $a1, $fp, $zero
/* AED9B8 802405A8 0C0B2026 */  jal       evt_set_variable
/* AED9BC 802405AC 0200302D */   daddu    $a2, $s0, $zero
/* AED9C0 802405B0 8FBF0054 */  lw        $ra, 0x54($sp)
/* AED9C4 802405B4 8FBE0050 */  lw        $fp, 0x50($sp)
/* AED9C8 802405B8 8FB7004C */  lw        $s7, 0x4c($sp)
/* AED9CC 802405BC 8FB60048 */  lw        $s6, 0x48($sp)
/* AED9D0 802405C0 8FB50044 */  lw        $s5, 0x44($sp)
/* AED9D4 802405C4 8FB40040 */  lw        $s4, 0x40($sp)
/* AED9D8 802405C8 8FB3003C */  lw        $s3, 0x3c($sp)
/* AED9DC 802405CC 8FB20038 */  lw        $s2, 0x38($sp)
/* AED9E0 802405D0 8FB10034 */  lw        $s1, 0x34($sp)
/* AED9E4 802405D4 8FB00030 */  lw        $s0, 0x30($sp)
/* AED9E8 802405D8 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* AED9EC 802405DC D7B80068 */  ldc1      $f24, 0x68($sp)
/* AED9F0 802405E0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* AED9F4 802405E4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* AED9F8 802405E8 24020002 */  addiu     $v0, $zero, 2
/* AED9FC 802405EC 03E00008 */  jr        $ra
/* AEDA00 802405F0 27BD0078 */   addiu    $sp, $sp, 0x78
