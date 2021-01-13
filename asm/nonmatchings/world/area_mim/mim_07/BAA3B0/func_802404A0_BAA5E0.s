.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A0_BAA5E0
/* BAA5E0 802404A0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* BAA5E4 802404A4 AFB3004C */  sw        $s3, 0x4c($sp)
/* BAA5E8 802404A8 0080982D */  daddu     $s3, $a0, $zero
/* BAA5EC 802404AC AFBF0054 */  sw        $ra, 0x54($sp)
/* BAA5F0 802404B0 AFB40050 */  sw        $s4, 0x50($sp)
/* BAA5F4 802404B4 AFB20048 */  sw        $s2, 0x48($sp)
/* BAA5F8 802404B8 AFB10044 */  sw        $s1, 0x44($sp)
/* BAA5FC 802404BC AFB00040 */  sw        $s0, 0x40($sp)
/* BAA600 802404C0 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BAA604 802404C4 8E710148 */  lw        $s1, 0x148($s3)
/* BAA608 802404C8 00A0A02D */  daddu     $s4, $a1, $zero
/* BAA60C 802404CC 86240008 */  lh        $a0, 8($s1)
/* BAA610 802404D0 0C00EABB */  jal       get_npc_unsafe
/* BAA614 802404D4 00C0902D */   daddu    $s2, $a2, $zero
/* BAA618 802404D8 8E830014 */  lw        $v1, 0x14($s4)
/* BAA61C 802404DC 04600034 */  bltz      $v1, .L802405B0
/* BAA620 802404E0 0040802D */   daddu    $s0, $v0, $zero
/* BAA624 802404E4 8E620074 */  lw        $v0, 0x74($s3)
/* BAA628 802404E8 1C400030 */  bgtz      $v0, .L802405AC
/* BAA62C 802404EC 2442FFFF */   addiu    $v0, $v0, -1
/* BAA630 802404F0 0240202D */  daddu     $a0, $s2, $zero
/* BAA634 802404F4 AE630074 */  sw        $v1, 0x74($s3)
/* BAA638 802404F8 AFA00010 */  sw        $zero, 0x10($sp)
/* BAA63C 802404FC 8E86000C */  lw        $a2, 0xc($s4)
/* BAA640 80240500 8E870010 */  lw        $a3, 0x10($s4)
/* BAA644 80240504 0C01242D */  jal       func_800490B4
/* BAA648 80240508 0220282D */   daddu    $a1, $s1, $zero
/* BAA64C 8024050C 10400025 */  beqz      $v0, .L802405A4
/* BAA650 80240510 0000202D */   daddu    $a0, $zero, $zero
/* BAA654 80240514 0200282D */  daddu     $a1, $s0, $zero
/* BAA658 80240518 0000302D */  daddu     $a2, $zero, $zero
/* BAA65C 8024051C 860300A8 */  lh        $v1, 0xa8($s0)
/* BAA660 80240520 3C013F80 */  lui       $at, 0x3f80
/* BAA664 80240524 44810000 */  mtc1      $at, $f0
/* BAA668 80240528 3C014000 */  lui       $at, 0x4000
/* BAA66C 8024052C 44811000 */  mtc1      $at, $f2
/* BAA670 80240530 3C01C1A0 */  lui       $at, 0xc1a0
/* BAA674 80240534 44812000 */  mtc1      $at, $f4
/* BAA678 80240538 2402000F */  addiu     $v0, $zero, 0xf
/* BAA67C 8024053C AFA2001C */  sw        $v0, 0x1c($sp)
/* BAA680 80240540 44835000 */  mtc1      $v1, $f10
/* BAA684 80240544 00000000 */  nop
/* BAA688 80240548 468052A0 */  cvt.s.w   $f10, $f10
/* BAA68C 8024054C 44075000 */  mfc1      $a3, $f10
/* BAA690 80240550 27A20028 */  addiu     $v0, $sp, 0x28
/* BAA694 80240554 AFA20020 */  sw        $v0, 0x20($sp)
/* BAA698 80240558 E7A00010 */  swc1      $f0, 0x10($sp)
/* BAA69C 8024055C E7A20014 */  swc1      $f2, 0x14($sp)
/* BAA6A0 80240560 0C01BFA4 */  jal       fx_emote
/* BAA6A4 80240564 E7A40018 */   swc1     $f4, 0x18($sp)
/* BAA6A8 80240568 0200202D */  daddu     $a0, $s0, $zero
/* BAA6AC 8024056C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BAA6B0 80240570 0C012530 */  jal       func_800494C0
/* BAA6B4 80240574 3C060020 */   lui      $a2, 0x20
/* BAA6B8 80240578 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAA6BC 8024057C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAA6C0 80240580 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAA6C4 80240584 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAA6C8 80240588 8C460028 */  lw        $a2, 0x28($v0)
/* BAA6CC 8024058C 0C00A720 */  jal       atan2
/* BAA6D0 80240590 8C470030 */   lw       $a3, 0x30($v0)
/* BAA6D4 80240594 2402000C */  addiu     $v0, $zero, 0xc
/* BAA6D8 80240598 E600000C */  swc1      $f0, 0xc($s0)
/* BAA6DC 8024059C 080901ED */  j         .L802407B4
/* BAA6E0 802405A0 AE620070 */   sw       $v0, 0x70($s3)
.L802405A4:
/* BAA6E4 802405A4 8E620074 */  lw        $v0, 0x74($s3)
/* BAA6E8 802405A8 2442FFFF */  addiu     $v0, $v0, -1
.L802405AC:
/* BAA6EC 802405AC AE620074 */  sw        $v0, 0x74($s3)
.L802405B0:
/* BAA6F0 802405B0 C6000018 */  lwc1      $f0, 0x18($s0)
/* BAA6F4 802405B4 44801000 */  mtc1      $zero, $f2
/* BAA6F8 802405B8 44801800 */  mtc1      $zero, $f3
/* BAA6FC 802405BC 46000021 */  cvt.d.s   $f0, $f0
/* BAA700 802405C0 4620103C */  c.lt.d    $f2, $f0
/* BAA704 802405C4 00000000 */  nop
/* BAA708 802405C8 45000025 */  bc1f      .L80240660
/* BAA70C 802405CC 27A5002C */   addiu    $a1, $sp, 0x2c
/* BAA710 802405D0 C6000038 */  lwc1      $f0, 0x38($s0)
/* BAA714 802405D4 860200A6 */  lh        $v0, 0xa6($s0)
/* BAA718 802405D8 3C018024 */  lui       $at, %hi(D_802437B0)
/* BAA71C 802405DC D42237B0 */  ldc1      $f2, %lo(D_802437B0)($at)
/* BAA720 802405E0 27A60030 */  addiu     $a2, $sp, 0x30
/* BAA724 802405E4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* BAA728 802405E8 44820000 */  mtc1      $v0, $f0
/* BAA72C 802405EC 00000000 */  nop
/* BAA730 802405F0 46800020 */  cvt.s.w   $f0, $f0
/* BAA734 802405F4 46000021 */  cvt.d.s   $f0, $f0
/* BAA738 802405F8 C604003C */  lwc1      $f4, 0x3c($s0)
/* BAA73C 802405FC C6060040 */  lwc1      $f6, 0x40($s0)
/* BAA740 80240600 C6080018 */  lwc1      $f8, 0x18($s0)
/* BAA744 80240604 860200A8 */  lh        $v0, 0xa8($s0)
/* BAA748 80240608 46220002 */  mul.d     $f0, $f0, $f2
/* BAA74C 8024060C 00000000 */  nop
/* BAA750 80240610 E7A40030 */  swc1      $f4, 0x30($sp)
/* BAA754 80240614 E7A60034 */  swc1      $f6, 0x34($sp)
/* BAA758 80240618 E7A80010 */  swc1      $f8, 0x10($sp)
/* BAA75C 8024061C C604000C */  lwc1      $f4, 0xc($s0)
/* BAA760 80240620 44821000 */  mtc1      $v0, $f2
/* BAA764 80240624 00000000 */  nop
/* BAA768 80240628 468010A0 */  cvt.s.w   $f2, $f2
/* BAA76C 8024062C E7A20018 */  swc1      $f2, 0x18($sp)
/* BAA770 80240630 E7A40014 */  swc1      $f4, 0x14($sp)
/* BAA774 80240634 46200020 */  cvt.s.d   $f0, $f0
/* BAA778 80240638 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAA77C 8024063C 8E040080 */  lw        $a0, 0x80($s0)
/* BAA780 80240640 0C037711 */  jal       func_800DDC44
/* BAA784 80240644 27A70034 */   addiu    $a3, $sp, 0x34
/* BAA788 80240648 54400005 */  bnel      $v0, $zero, .L80240660
/* BAA78C 8024064C AE000018 */   sw       $zero, 0x18($s0)
/* BAA790 80240650 8E050018 */  lw        $a1, 0x18($s0)
/* BAA794 80240654 8E06000C */  lw        $a2, 0xc($s0)
/* BAA798 80240658 0C00EA95 */  jal       npc_move_heading
/* BAA79C 8024065C 0200202D */   daddu    $a0, $s0, $zero
.L80240660:
/* BAA7A0 80240660 C600001C */  lwc1      $f0, 0x1c($s0)
/* BAA7A4 80240664 44801000 */  mtc1      $zero, $f2
/* BAA7A8 80240668 44801800 */  mtc1      $zero, $f3
/* BAA7AC 8024066C 46000021 */  cvt.d.s   $f0, $f0
/* BAA7B0 80240670 4622003C */  c.lt.d    $f0, $f2
/* BAA7B4 80240674 00000000 */  nop
/* BAA7B8 80240678 45000047 */  bc1f      .L80240798
/* BAA7BC 8024067C 27A5002C */   addiu    $a1, $sp, 0x2c
/* BAA7C0 80240680 27A60030 */  addiu     $a2, $sp, 0x30
/* BAA7C4 80240684 27A20038 */  addiu     $v0, $sp, 0x38
/* BAA7C8 80240688 C602003C */  lwc1      $f2, 0x3c($s0)
/* BAA7CC 8024068C C6060038 */  lwc1      $f6, 0x38($s0)
/* BAA7D0 80240690 3C01402A */  lui       $at, 0x402a
/* BAA7D4 80240694 4481A800 */  mtc1      $at, $f21
/* BAA7D8 80240698 4480A000 */  mtc1      $zero, $f20
/* BAA7DC 8024069C 460010A1 */  cvt.d.s   $f2, $f2
/* BAA7E0 802406A0 46341080 */  add.d     $f2, $f2, $f20
/* BAA7E4 802406A4 C600001C */  lwc1      $f0, 0x1c($s0)
/* BAA7E8 802406A8 C6040040 */  lwc1      $f4, 0x40($s0)
/* BAA7EC 802406AC 46000005 */  abs.s     $f0, $f0
/* BAA7F0 802406B0 E7A40034 */  swc1      $f4, 0x34($sp)
/* BAA7F4 802406B4 3C014030 */  lui       $at, 0x4030
/* BAA7F8 802406B8 44812800 */  mtc1      $at, $f5
/* BAA7FC 802406BC 44802000 */  mtc1      $zero, $f4
/* BAA800 802406C0 46000021 */  cvt.d.s   $f0, $f0
/* BAA804 802406C4 E7A6002C */  swc1      $f6, 0x2c($sp)
/* BAA808 802406C8 46240000 */  add.d     $f0, $f0, $f4
/* BAA80C 802406CC 462010A0 */  cvt.s.d   $f2, $f2
/* BAA810 802406D0 E7A20030 */  swc1      $f2, 0x30($sp)
/* BAA814 802406D4 46200020 */  cvt.s.d   $f0, $f0
/* BAA818 802406D8 E7A00038 */  swc1      $f0, 0x38($sp)
/* BAA81C 802406DC AFA20010 */  sw        $v0, 0x10($sp)
/* BAA820 802406E0 8E040080 */  lw        $a0, 0x80($s0)
/* BAA824 802406E4 0C0372DF */  jal       func_800DCB7C
/* BAA828 802406E8 27A70034 */   addiu    $a3, $sp, 0x34
/* BAA82C 802406EC 1040002A */  beqz      $v0, .L80240798
/* BAA830 802406F0 00000000 */   nop
/* BAA834 802406F4 C600001C */  lwc1      $f0, 0x1c($s0)
/* BAA838 802406F8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BAA83C 802406FC 46000005 */  abs.s     $f0, $f0
/* BAA840 80240700 46000021 */  cvt.d.s   $f0, $f0
/* BAA844 80240704 46340000 */  add.d     $f0, $f0, $f20
/* BAA848 80240708 460010A1 */  cvt.d.s   $f2, $f2
/* BAA84C 8024070C 4620103E */  c.le.d    $f2, $f0
/* BAA850 80240710 00000000 */  nop
/* BAA854 80240714 45000020 */  bc1f      .L80240798
/* BAA858 80240718 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BAA85C 8024071C C7A00030 */  lwc1      $f0, 0x30($sp)
/* BAA860 80240720 8E020000 */  lw        $v0, ($s0)
/* BAA864 80240724 2403F7FF */  addiu     $v1, $zero, -0x801
/* BAA868 80240728 AE00001C */  sw        $zero, 0x1c($s0)
/* BAA86C 8024072C 00431024 */  and       $v0, $v0, $v1
/* BAA870 80240730 AE020000 */  sw        $v0, ($s0)
/* BAA874 80240734 24020002 */  addiu     $v0, $zero, 2
/* BAA878 80240738 E600003C */  swc1      $f0, 0x3c($s0)
/* BAA87C 8024073C 0C00A67F */  jal       rand_int
/* BAA880 80240740 AE620070 */   sw       $v0, 0x70($s3)
/* BAA884 80240744 3C035555 */  lui       $v1, 0x5555
/* BAA888 80240748 34635556 */  ori       $v1, $v1, 0x5556
/* BAA88C 8024074C 00430018 */  mult      $v0, $v1
/* BAA890 80240750 000227C3 */  sra       $a0, $v0, 0x1f
/* BAA894 80240754 00004010 */  mfhi      $t0
/* BAA898 80240758 01042023 */  subu      $a0, $t0, $a0
/* BAA89C 8024075C 00041840 */  sll       $v1, $a0, 1
/* BAA8A0 80240760 00641821 */  addu      $v1, $v1, $a0
/* BAA8A4 80240764 00431023 */  subu      $v0, $v0, $v1
/* BAA8A8 80240768 24430002 */  addiu     $v1, $v0, 2
/* BAA8AC 8024076C AE630074 */  sw        $v1, 0x74($s3)
/* BAA8B0 80240770 8E82002C */  lw        $v0, 0x2c($s4)
/* BAA8B4 80240774 5840000F */  blezl     $v0, .L802407B4
/* BAA8B8 80240778 AE600070 */   sw       $zero, 0x70($s3)
/* BAA8BC 8024077C 8E820004 */  lw        $v0, 4($s4)
/* BAA8C0 80240780 5840000C */  blezl     $v0, .L802407B4
/* BAA8C4 80240784 AE600070 */   sw       $zero, 0x70($s3)
/* BAA8C8 80240788 1460000A */  bnez      $v1, .L802407B4
/* BAA8CC 8024078C 00000000 */   nop
/* BAA8D0 80240790 080901ED */  j         .L802407B4
/* BAA8D4 80240794 AE600070 */   sw       $zero, 0x70($s3)
.L80240798:
/* BAA8D8 80240798 C604003C */  lwc1      $f4, 0x3c($s0)
/* BAA8DC 8024079C C600001C */  lwc1      $f0, 0x1c($s0)
/* BAA8E0 802407A0 46002100 */  add.s     $f4, $f4, $f0
/* BAA8E4 802407A4 C6020014 */  lwc1      $f2, 0x14($s0)
/* BAA8E8 802407A8 46020001 */  sub.s     $f0, $f0, $f2
/* BAA8EC 802407AC E604003C */  swc1      $f4, 0x3c($s0)
/* BAA8F0 802407B0 E600001C */  swc1      $f0, 0x1c($s0)
.L802407B4:
/* BAA8F4 802407B4 8FBF0054 */  lw        $ra, 0x54($sp)
/* BAA8F8 802407B8 8FB40050 */  lw        $s4, 0x50($sp)
/* BAA8FC 802407BC 8FB3004C */  lw        $s3, 0x4c($sp)
/* BAA900 802407C0 8FB20048 */  lw        $s2, 0x48($sp)
/* BAA904 802407C4 8FB10044 */  lw        $s1, 0x44($sp)
/* BAA908 802407C8 8FB00040 */  lw        $s0, 0x40($sp)
/* BAA90C 802407CC D7B40058 */  ldc1      $f20, 0x58($sp)
/* BAA910 802407D0 03E00008 */  jr        $ra
/* BAA914 802407D4 27BD0060 */   addiu    $sp, $sp, 0x60
