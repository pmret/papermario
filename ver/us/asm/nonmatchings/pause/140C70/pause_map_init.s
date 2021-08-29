.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_init
/* 141944 8024E604 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 141948 8024E608 AFB3001C */  sw        $s3, 0x1c($sp)
/* 14194C 8024E60C 0080982D */  daddu     $s3, $a0, $zero
/* 141950 8024E610 AFB00010 */  sw        $s0, 0x10($sp)
/* 141954 8024E614 0000802D */  daddu     $s0, $zero, $zero
/* 141958 8024E618 AFB20018 */  sw        $s2, 0x18($sp)
/* 14195C 8024E61C 3C128027 */  lui       $s2, %hi(D_80270700)
/* 141960 8024E620 26520700 */  addiu     $s2, $s2, %lo(D_80270700)
/* 141964 8024E624 AFB10014 */  sw        $s1, 0x14($sp)
/* 141968 8024E628 3C118025 */  lui       $s1, %hi(D_8024FA30)
/* 14196C 8024E62C 2631FA30 */  addiu     $s1, $s1, %lo(D_8024FA30)
/* 141970 8024E630 AFBF0020 */  sw        $ra, 0x20($sp)
.L8024E634:
/* 141974 8024E634 8E240000 */  lw        $a0, ($s1)
/* 141978 8024E638 26310004 */  addiu     $s1, $s1, 4
/* 14197C 8024E63C 0C050529 */  jal       create_hud_element
/* 141980 8024E640 26100001 */   addiu    $s0, $s0, 1
/* 141984 8024E644 0040202D */  daddu     $a0, $v0, $zero
/* 141988 8024E648 24050080 */  addiu     $a1, $zero, 0x80
/* 14198C 8024E64C 0C051280 */  jal       set_hud_element_flags
/* 141990 8024E650 AE440000 */   sw       $a0, ($s2)
/* 141994 8024E654 1A00FFF7 */  blez      $s0, .L8024E634
/* 141998 8024E658 26520004 */   addiu    $s2, $s2, 4
/* 14199C 8024E65C 24100006 */  addiu     $s0, $zero, 6
/* 1419A0 8024E660 3C028025 */  lui       $v0, %hi(D_80250668)
/* 1419A4 8024E664 24420668 */  addiu     $v0, $v0, %lo(D_80250668)
.L8024E668:
/* 1419A8 8024E668 AC530010 */  sw        $s3, 0x10($v0)
/* 1419AC 8024E66C 2610FFFF */  addiu     $s0, $s0, -1
/* 1419B0 8024E670 0601FFFD */  bgez      $s0, .L8024E668
/* 1419B4 8024E674 2442FFDC */   addiu    $v0, $v0, -0x24
/* 1419B8 8024E678 3C048025 */  lui       $a0, %hi(D_80250590)
/* 1419BC 8024E67C 24840590 */  addiu     $a0, $a0, %lo(D_80250590)
/* 1419C0 8024E680 0C051FCC */  jal       setup_pause_menu_tab
/* 1419C4 8024E684 24050007 */   addiu    $a1, $zero, 7
/* 1419C8 8024E688 0000202D */  daddu     $a0, $zero, $zero
/* 1419CC 8024E68C 3C05F5DE */  lui       $a1, 0xf5de
/* 1419D0 8024E690 2402FFFF */  addiu     $v0, $zero, -1
/* 1419D4 8024E694 3C018027 */  lui       $at, %hi(mapCursorCurrentOption)
/* 1419D8 8024E698 AC22071C */  sw        $v0, %lo(mapCursorCurrentOption)($at)
/* 1419DC 8024E69C 3C018027 */  lui       $at, %hi(D_80270724)
/* 1419E0 8024E6A0 AC200724 */  sw        $zero, %lo(D_80270724)($at)
/* 1419E4 8024E6A4 3C018027 */  lui       $at, %hi(mapCursorCurrentOptionCopy)
/* 1419E8 8024E6A8 AC220720 */  sw        $v0, %lo(mapCursorCurrentOptionCopy)($at)
/* 1419EC 8024E6AC 0C0B1EAF */  jal       get_variable
/* 1419F0 8024E6B0 34A50329 */   ori      $a1, $a1, 0x329
/* 1419F4 8024E6B4 0040202D */  daddu     $a0, $v0, $zero
/* 1419F8 8024E6B8 0000802D */  daddu     $s0, $zero, $zero
/* 1419FC 8024E6BC 3C058025 */  lui       $a1, %hi(D_802502B8)
/* 141A00 8024E6C0 24A502B8 */  addiu     $a1, $a1, %lo(D_802502B8)
/* 141A04 8024E6C4 00A0182D */  daddu     $v1, $a1, $zero
.L8024E6C8:
/* 141A08 8024E6C8 8C620010 */  lw        $v0, 0x10($v1)
/* 141A0C 8024E6CC 10440006 */  beq       $v0, $a0, .L8024E6E8
/* 141A10 8024E6D0 2A020022 */   slti     $v0, $s0, 0x22
/* 141A14 8024E6D4 26100001 */  addiu     $s0, $s0, 1
/* 141A18 8024E6D8 2A020022 */  slti      $v0, $s0, 0x22
/* 141A1C 8024E6DC 1440FFFA */  bnez      $v0, .L8024E6C8
/* 141A20 8024E6E0 24630014 */   addiu    $v1, $v1, 0x14
/* 141A24 8024E6E4 2A020022 */  slti      $v0, $s0, 0x22
.L8024E6E8:
/* 141A28 8024E6E8 1040000C */  beqz      $v0, .L8024E71C
/* 141A2C 8024E6EC 00101080 */   sll      $v0, $s0, 2
/* 141A30 8024E6F0 00501021 */  addu      $v0, $v0, $s0
/* 141A34 8024E6F4 00021080 */  sll       $v0, $v0, 2
/* 141A38 8024E6F8 00451021 */  addu      $v0, $v0, $a1
/* 141A3C 8024E6FC 84430000 */  lh        $v1, ($v0)
/* 141A40 8024E700 84420002 */  lh        $v0, 2($v0)
/* 141A44 8024E704 3C018027 */  lui       $at, %hi(mapMarioXPos)
/* 141A48 8024E708 AC23070C */  sw        $v1, %lo(mapMarioXPos)($at)
/* 141A4C 8024E70C 3C018027 */  lui       $at, %hi(mapMarioYPos)
/* 141A50 8024E710 AC220710 */  sw        $v0, %lo(mapMarioYPos)($at)
/* 141A54 8024E714 080939CB */  j         .L8024E72C
/* 141A58 8024E718 00000000 */   nop
.L8024E71C:
/* 141A5C 8024E71C 3C018027 */  lui       $at, %hi(mapMarioXPos)
/* 141A60 8024E720 AC20070C */  sw        $zero, %lo(mapMarioXPos)($at)
/* 141A64 8024E724 3C018027 */  lui       $at, %hi(mapMarioYPos)
/* 141A68 8024E728 AC200710 */  sw        $zero, %lo(mapMarioYPos)($at)
.L8024E72C:
/* 141A6C 8024E72C 3C018027 */  lui       $at, %hi(mapMarioXPos)
/* 141A70 8024E730 C422070C */  lwc1      $f2, %lo(mapMarioXPos)($at)
/* 141A74 8024E734 468010A0 */  cvt.s.w   $f2, $f2
/* 141A78 8024E738 3C038027 */  lui       $v1, %hi(D_80270704)
/* 141A7C 8024E73C 24630704 */  addiu     $v1, $v1, %lo(D_80270704)
/* 141A80 8024E740 3C018027 */  lui       $at, %hi(mapCursorXPos)
/* 141A84 8024E744 E4220714 */  swc1      $f2, %lo(mapCursorXPos)($at)
/* 141A88 8024E748 AC600000 */  sw        $zero, ($v1)
/* 141A8C 8024E74C C4660000 */  lwc1      $f6, ($v1)
/* 141A90 8024E750 3C018027 */  lui       $at, %hi(mapMarioYPos)
/* 141A94 8024E754 C4200710 */  lwc1      $f0, %lo(mapMarioYPos)($at)
/* 141A98 8024E758 46800020 */  cvt.s.w   $f0, $f0
/* 141A9C 8024E75C 46061080 */  add.s     $f2, $f2, $f6
/* 141AA0 8024E760 3C048027 */  lui       $a0, %hi(D_80270708)
/* 141AA4 8024E764 24840708 */  addiu     $a0, $a0, %lo(D_80270708)
/* 141AA8 8024E768 3C018027 */  lui       $at, %hi(mapCursorYPos)
/* 141AAC 8024E76C E4200718 */  swc1      $f0, %lo(mapCursorYPos)($at)
/* 141AB0 8024E770 46060000 */  add.s     $f0, $f0, $f6
/* 141AB4 8024E774 3C018027 */  lui       $at, %hi(D_80270080)
/* 141AB8 8024E778 D4240080 */  ldc1      $f4, %lo(D_80270080)($at)
/* 141ABC 8024E77C 460010A1 */  cvt.d.s   $f2, $f2
/* 141AC0 8024E780 46241081 */  sub.d     $f2, $f2, $f4
/* 141AC4 8024E784 3C018027 */  lui       $at, %hi(D_80270088)
/* 141AC8 8024E788 D4240088 */  ldc1      $f4, %lo(D_80270088)($at)
/* 141ACC 8024E78C 46000021 */  cvt.d.s   $f0, $f0
/* 141AD0 8024E790 46240001 */  sub.d     $f0, $f0, $f4
/* 141AD4 8024E794 4620120D */  trunc.w.d $f8, $f2
/* 141AD8 8024E798 44024000 */  mfc1      $v0, $f8
/* 141ADC 8024E79C 00000000 */  nop
/* 141AE0 8024E7A0 44821000 */  mtc1      $v0, $f2
/* 141AE4 8024E7A4 00000000 */  nop
/* 141AE8 8024E7A8 468010A0 */  cvt.s.w   $f2, $f2
/* 141AEC 8024E7AC 46023081 */  sub.s     $f2, $f6, $f2
/* 141AF0 8024E7B0 4620020D */  trunc.w.d $f8, $f0
/* 141AF4 8024E7B4 44024000 */  mfc1      $v0, $f8
/* 141AF8 8024E7B8 00000000 */  nop
/* 141AFC 8024E7BC 44820000 */  mtc1      $v0, $f0
/* 141B00 8024E7C0 00000000 */  nop
/* 141B04 8024E7C4 46800020 */  cvt.s.w   $f0, $f0
/* 141B08 8024E7C8 46003001 */  sub.s     $f0, $f6, $f0
/* 141B0C 8024E7CC AC800000 */  sw        $zero, ($a0)
/* 141B10 8024E7D0 E4620000 */  swc1      $f2, ($v1)
/* 141B14 8024E7D4 4602303C */  c.lt.s    $f6, $f2
/* 141B18 8024E7D8 00000000 */  nop
/* 141B1C 8024E7DC 45000002 */  bc1f      .L8024E7E8
/* 141B20 8024E7E0 E4800000 */   swc1     $f0, ($a0)
/* 141B24 8024E7E4 E4660000 */  swc1      $f6, ($v1)
.L8024E7E8:
/* 141B28 8024E7E8 4600303C */  c.lt.s    $f6, $f0
/* 141B2C 8024E7EC 00000000 */  nop
/* 141B30 8024E7F0 45030001 */  bc1tl     .L8024E7F8
/* 141B34 8024E7F4 E4860000 */   swc1     $f6, ($a0)
.L8024E7F8:
/* 141B38 8024E7F8 C4620000 */  lwc1      $f2, ($v1)
/* 141B3C 8024E7FC 3C01C2AC */  lui       $at, 0xc2ac
/* 141B40 8024E800 44810000 */  mtc1      $at, $f0
/* 141B44 8024E804 00000000 */  nop
/* 141B48 8024E808 4600103E */  c.le.s    $f2, $f0
/* 141B4C 8024E80C 00000000 */  nop
/* 141B50 8024E810 45000005 */  bc1f      .L8024E828
/* 141B54 8024E814 00000000 */   nop
/* 141B58 8024E818 3C01C2AA */  lui       $at, 0xc2aa
/* 141B5C 8024E81C 44810000 */  mtc1      $at, $f0
/* 141B60 8024E820 00000000 */  nop
/* 141B64 8024E824 E4600000 */  swc1      $f0, ($v1)
.L8024E828:
/* 141B68 8024E828 C4820000 */  lwc1      $f2, ($a0)
/* 141B6C 8024E82C 3C01C352 */  lui       $at, 0xc352
/* 141B70 8024E830 44810000 */  mtc1      $at, $f0
/* 141B74 8024E834 00000000 */  nop
/* 141B78 8024E838 4600103E */  c.le.s    $f2, $f0
/* 141B7C 8024E83C 00000000 */  nop
/* 141B80 8024E840 45000005 */  bc1f      .L8024E858
/* 141B84 8024E844 24020001 */   addiu    $v0, $zero, 1
/* 141B88 8024E848 3C01C351 */  lui       $at, 0xc351
/* 141B8C 8024E84C 44810000 */  mtc1      $at, $f0
/* 141B90 8024E850 00000000 */  nop
/* 141B94 8024E854 E4800000 */  swc1      $f0, ($a0)
.L8024E858:
/* 141B98 8024E858 A2620000 */  sb        $v0, ($s3)
/* 141B9C 8024E85C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 141BA0 8024E860 8FB3001C */  lw        $s3, 0x1c($sp)
/* 141BA4 8024E864 8FB20018 */  lw        $s2, 0x18($sp)
/* 141BA8 8024E868 8FB10014 */  lw        $s1, 0x14($sp)
/* 141BAC 8024E86C 8FB00010 */  lw        $s0, 0x10($sp)
/* 141BB0 8024E870 03E00008 */  jr        $ra
/* 141BB4 8024E874 27BD0028 */   addiu    $sp, $sp, 0x28
