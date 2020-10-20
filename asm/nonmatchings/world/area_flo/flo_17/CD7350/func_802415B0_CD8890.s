.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415B0_CD8890
/* CD8890 802415B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CD8894 802415B4 AFB20048 */  sw        $s2, 0x48($sp)
/* CD8898 802415B8 0080902D */  daddu     $s2, $a0, $zero
/* CD889C 802415BC AFBF0064 */  sw        $ra, 0x64($sp)
/* CD88A0 802415C0 AFBE0060 */  sw        $fp, 0x60($sp)
/* CD88A4 802415C4 AFB7005C */  sw        $s7, 0x5c($sp)
/* CD88A8 802415C8 AFB60058 */  sw        $s6, 0x58($sp)
/* CD88AC 802415CC AFB50054 */  sw        $s5, 0x54($sp)
/* CD88B0 802415D0 AFB40050 */  sw        $s4, 0x50($sp)
/* CD88B4 802415D4 AFB3004C */  sw        $s3, 0x4c($sp)
/* CD88B8 802415D8 AFB10044 */  sw        $s1, 0x44($sp)
/* CD88BC 802415DC AFB00040 */  sw        $s0, 0x40($sp)
/* CD88C0 802415E0 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* CD88C4 802415E4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* CD88C8 802415E8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* CD88CC 802415EC F7B40068 */  sdc1      $f20, 0x68($sp)
/* CD88D0 802415F0 8E510148 */  lw        $s1, 0x148($s2)
/* CD88D4 802415F4 00A0B82D */  daddu     $s7, $a1, $zero
/* CD88D8 802415F8 86240008 */  lh        $a0, 8($s1)
/* CD88DC 802415FC 0C00EABB */  jal       get_npc_unsafe
/* CD88E0 80241600 00C0F02D */   daddu    $fp, $a2, $zero
/* CD88E4 80241604 C620007C */  lwc1      $f0, 0x7c($s1)
/* CD88E8 80241608 46800020 */  cvt.s.w   $f0, $f0
/* CD88EC 8024160C 46000021 */  cvt.d.s   $f0, $f0
/* CD88F0 80241610 0040802D */  daddu     $s0, $v0, $zero
/* CD88F4 80241614 3C014059 */  lui       $at, 0x4059
/* CD88F8 80241618 44813800 */  mtc1      $at, $f7
/* CD88FC 8024161C 44803000 */  mtc1      $zero, $f6
/* CD8900 80241620 8602008E */  lh        $v0, 0x8e($s0)
/* CD8904 80241624 9603008E */  lhu       $v1, 0x8e($s0)
/* CD8908 80241628 46260003 */  div.d     $f0, $f0, $f6
/* CD890C 8024162C 462005A0 */  cvt.s.d   $f22, $f0
/* CD8910 80241630 C6200078 */  lwc1      $f0, 0x78($s1)
/* CD8914 80241634 46800020 */  cvt.s.w   $f0, $f0
/* CD8918 80241638 46000021 */  cvt.d.s   $f0, $f0
/* CD891C 8024163C 46260003 */  div.d     $f0, $f0, $f6
/* CD8920 80241640 18400003 */  blez      $v0, .L80241650
/* CD8924 80241644 46200620 */   cvt.s.d  $f24, $f0
/* CD8928 80241648 2462FFFF */  addiu     $v0, $v1, -1
/* CD892C 8024164C A602008E */  sh        $v0, 0x8e($s0)
.L80241650:
/* CD8930 80241650 27B40028 */  addiu     $s4, $sp, 0x28
/* CD8934 80241654 0280282D */  daddu     $a1, $s4, $zero
/* CD8938 80241658 27B5002C */  addiu     $s5, $sp, 0x2c
/* CD893C 8024165C 02A0302D */  daddu     $a2, $s5, $zero
/* CD8940 80241660 27B60030 */  addiu     $s6, $sp, 0x30
/* CD8944 80241664 02C0382D */  daddu     $a3, $s6, $zero
/* CD8948 80241668 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD894C 8024166C C602003C */  lwc1      $f2, 0x3c($s0)
/* CD8950 80241670 C6040040 */  lwc1      $f4, 0x40($s0)
/* CD8954 80241674 3C01447A */  lui       $at, 0x447a
/* CD8958 80241678 4481D000 */  mtc1      $at, $f26
/* CD895C 8024167C 27B30034 */  addiu     $s3, $sp, 0x34
/* CD8960 80241680 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD8964 80241684 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD8968 80241688 E7A40030 */  swc1      $f4, 0x30($sp)
/* CD896C 8024168C E7BA0034 */  swc1      $f26, 0x34($sp)
/* CD8970 80241690 C6340070 */  lwc1      $f20, 0x70($s1)
/* CD8974 80241694 4680A520 */  cvt.s.w   $f20, $f20
/* CD8978 80241698 4600A521 */  cvt.d.s   $f20, $f20
/* CD897C 8024169C 4626A503 */  div.d     $f20, $f20, $f6
/* CD8980 802416A0 AFB30010 */  sw        $s3, 0x10($sp)
/* CD8984 802416A4 8E040080 */  lw        $a0, 0x80($s0)
/* CD8988 802416A8 0C0372DF */  jal       func_800DCB7C
/* CD898C 802416AC 4620A520 */   cvt.s.d  $f20, $f20
/* CD8990 802416B0 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CD8994 802416B4 0C00A8BB */  jal       sin_deg
/* CD8998 802416B8 46806320 */   cvt.s.w  $f12, $f12
/* CD899C 802416BC 46140002 */  mul.s     $f0, $f0, $f20
/* CD89A0 802416C0 00000000 */  nop       
/* CD89A4 802416C4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* CD89A8 802416C8 46181080 */  add.s     $f2, $f2, $f24
/* CD89AC 802416CC 46001080 */  add.s     $f2, $f2, $f0
/* CD89B0 802416D0 E602003C */  swc1      $f2, 0x3c($s0)
/* CD89B4 802416D4 8E220074 */  lw        $v0, 0x74($s1)
/* CD89B8 802416D8 2442000C */  addiu     $v0, $v0, 0xc
/* CD89BC 802416DC 44826000 */  mtc1      $v0, $f12
/* CD89C0 802416E0 00000000 */  nop       
/* CD89C4 802416E4 0C00A6C9 */  jal       clamp_angle
/* CD89C8 802416E8 46806320 */   cvt.s.w  $f12, $f12
/* CD89CC 802416EC 4600020D */  trunc.w.s $f8, $f0
/* CD89D0 802416F0 E6280074 */  swc1      $f8, 0x74($s1)
/* CD89D4 802416F4 8EE30014 */  lw        $v1, 0x14($s7)
/* CD89D8 802416F8 0460003C */  bltz      $v1, .L802417EC
/* CD89DC 802416FC 00000000 */   nop      
/* CD89E0 80241700 8E420074 */  lw        $v0, 0x74($s2)
/* CD89E4 80241704 1C400038 */  bgtz      $v0, .L802417E8
/* CD89E8 80241708 2442FFFF */   addiu    $v0, $v0, -1
/* CD89EC 8024170C 03C0202D */  daddu     $a0, $fp, $zero
/* CD89F0 80241710 AE430074 */  sw        $v1, 0x74($s2)
/* CD89F4 80241714 AFA00010 */  sw        $zero, 0x10($sp)
/* CD89F8 80241718 8EE6000C */  lw        $a2, 0xc($s7)
/* CD89FC 8024171C 8EE70010 */  lw        $a3, 0x10($s7)
/* CD8A00 80241720 0C01242D */  jal       func_800490B4
/* CD8A04 80241724 0220282D */   daddu    $a1, $s1, $zero
/* CD8A08 80241728 1040002D */  beqz      $v0, .L802417E0
/* CD8A0C 8024172C 0000202D */   daddu    $a0, $zero, $zero
/* CD8A10 80241730 0200282D */  daddu     $a1, $s0, $zero
/* CD8A14 80241734 0000302D */  daddu     $a2, $zero, $zero
/* CD8A18 80241738 860300A8 */  lh        $v1, 0xa8($s0)
/* CD8A1C 8024173C 3C013F80 */  lui       $at, 0x3f80
/* CD8A20 80241740 44810000 */  mtc1      $at, $f0
/* CD8A24 80241744 3C014000 */  lui       $at, 0x4000
/* CD8A28 80241748 44811000 */  mtc1      $at, $f2
/* CD8A2C 8024174C 3C01C1A0 */  lui       $at, 0xc1a0
/* CD8A30 80241750 44812000 */  mtc1      $at, $f4
/* CD8A34 80241754 2402000F */  addiu     $v0, $zero, 0xf
/* CD8A38 80241758 AFA2001C */  sw        $v0, 0x1c($sp)
/* CD8A3C 8024175C 44834000 */  mtc1      $v1, $f8
/* CD8A40 80241760 00000000 */  nop       
/* CD8A44 80241764 46804220 */  cvt.s.w   $f8, $f8
/* CD8A48 80241768 44074000 */  mfc1      $a3, $f8
/* CD8A4C 8024176C 27A20038 */  addiu     $v0, $sp, 0x38
/* CD8A50 80241770 AFA20020 */  sw        $v0, 0x20($sp)
/* CD8A54 80241774 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD8A58 80241778 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD8A5C 8024177C 0C01BFA4 */  jal       fx_emote
/* CD8A60 80241780 E7A40018 */   swc1     $f4, 0x18($sp)
/* CD8A64 80241784 0200202D */  daddu     $a0, $s0, $zero
/* CD8A68 80241788 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CD8A6C 8024178C 0C012530 */  jal       func_800494C0
/* CD8A70 80241790 3C060020 */   lui      $a2, 0x20
/* CD8A74 80241794 0280282D */  daddu     $a1, $s4, $zero
/* CD8A78 80241798 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD8A7C 8024179C C602003C */  lwc1      $f2, 0x3c($s0)
/* CD8A80 802417A0 C6040040 */  lwc1      $f4, 0x40($s0)
/* CD8A84 802417A4 02A0302D */  daddu     $a2, $s5, $zero
/* CD8A88 802417A8 E7BA0034 */  swc1      $f26, 0x34($sp)
/* CD8A8C 802417AC E7A00028 */  swc1      $f0, 0x28($sp)
/* CD8A90 802417B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD8A94 802417B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* CD8A98 802417B8 AFB30010 */  sw        $s3, 0x10($sp)
/* CD8A9C 802417BC 8E040080 */  lw        $a0, 0x80($s0)
/* CD8AA0 802417C0 0C0372DF */  jal       func_800DCB7C
/* CD8AA4 802417C4 02C0382D */   daddu    $a3, $s6, $zero
/* CD8AA8 802417C8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CD8AAC 802417CC 46180000 */  add.s     $f0, $f0, $f24
/* CD8AB0 802417D0 2402000C */  addiu     $v0, $zero, 0xc
/* CD8AB4 802417D4 E6000064 */  swc1      $f0, 0x64($s0)
/* CD8AB8 802417D8 08090675 */  j         .L802419D4
/* CD8ABC 802417DC AE420070 */   sw       $v0, 0x70($s2)
.L802417E0:
/* CD8AC0 802417E0 8E420074 */  lw        $v0, 0x74($s2)
/* CD8AC4 802417E4 2442FFFF */  addiu     $v0, $v0, -1
.L802417E8:
/* CD8AC8 802417E8 AE420074 */  sw        $v0, 0x74($s2)
.L802417EC:
/* CD8ACC 802417EC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD8AD0 802417F0 C6000040 */  lwc1      $f0, 0x40($s0)
/* CD8AD4 802417F4 C4620000 */  lwc1      $f2, ($v1)
/* CD8AD8 802417F8 468010A0 */  cvt.s.w   $f2, $f2
/* CD8ADC 802417FC C4640008 */  lwc1      $f4, 8($v1)
/* CD8AE0 80241800 46802120 */  cvt.s.w   $f4, $f4
/* CD8AE4 80241804 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD8AE8 80241808 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD8AEC 8024180C 44051000 */  mfc1      $a1, $f2
/* CD8AF0 80241810 C440000C */  lwc1      $f0, 0xc($v0)
/* CD8AF4 80241814 46800020 */  cvt.s.w   $f0, $f0
/* CD8AF8 80241818 E7A00014 */  swc1      $f0, 0x14($sp)
/* CD8AFC 8024181C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD8B00 80241820 44062000 */  mfc1      $a2, $f4
/* CD8B04 80241824 C4400010 */  lwc1      $f0, 0x10($v0)
/* CD8B08 80241828 46800020 */  cvt.s.w   $f0, $f0
/* CD8B0C 8024182C E7A00018 */  swc1      $f0, 0x18($sp)
/* CD8B10 80241830 8C640018 */  lw        $a0, 0x18($v1)
/* CD8B14 80241834 0C0123F5 */  jal       is_point_within_region
/* CD8B18 80241838 8E070038 */   lw       $a3, 0x38($s0)
/* CD8B1C 8024183C 1040000D */  beqz      $v0, .L80241874
/* CD8B20 80241840 00000000 */   nop      
/* CD8B24 80241844 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD8B28 80241848 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD8B2C 8024184C C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD8B30 80241850 C4480000 */  lwc1      $f8, ($v0)
/* CD8B34 80241854 46804220 */  cvt.s.w   $f8, $f8
/* CD8B38 80241858 44064000 */  mfc1      $a2, $f8
/* CD8B3C 8024185C C4480008 */  lwc1      $f8, 8($v0)
/* CD8B40 80241860 46804220 */  cvt.s.w   $f8, $f8
/* CD8B44 80241864 44074000 */  mfc1      $a3, $f8
/* CD8B48 80241868 0C00A720 */  jal       atan2
/* CD8B4C 8024186C 00000000 */   nop      
/* CD8B50 80241870 E600000C */  swc1      $f0, 0xc($s0)
.L80241874:
/* CD8B54 80241874 8602008C */  lh        $v0, 0x8c($s0)
/* CD8B58 80241878 14400056 */  bnez      $v0, .L802419D4
/* CD8B5C 8024187C 00000000 */   nop      
/* CD8B60 80241880 8602008E */  lh        $v0, 0x8e($s0)
/* CD8B64 80241884 1840003D */  blez      $v0, .L8024197C
/* CD8B68 80241888 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CD8B6C 8024188C 8E050018 */  lw        $a1, 0x18($s0)
/* CD8B70 80241890 8E06000C */  lw        $a2, 0xc($s0)
/* CD8B74 80241894 0C00EA95 */  jal       npc_move_heading
/* CD8B78 80241898 0200202D */   daddu    $a0, $s0, $zero
/* CD8B7C 8024189C 8E22006C */  lw        $v0, 0x6c($s1)
/* CD8B80 802418A0 30420001 */  andi      $v0, $v0, 1
/* CD8B84 802418A4 10400032 */  beqz      $v0, .L80241970
/* CD8B88 802418A8 27A50028 */   addiu    $a1, $sp, 0x28
/* CD8B8C 802418AC 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD8B90 802418B0 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD8B94 802418B4 C6020040 */  lwc1      $f2, 0x40($s0)
/* CD8B98 802418B8 3C01447A */  lui       $at, 0x447a
/* CD8B9C 802418BC 44812000 */  mtc1      $at, $f4
/* CD8BA0 802418C0 27A20034 */  addiu     $v0, $sp, 0x34
/* CD8BA4 802418C4 E7B6002C */  swc1      $f22, 0x2c($sp)
/* CD8BA8 802418C8 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD8BAC 802418CC E7A20030 */  swc1      $f2, 0x30($sp)
/* CD8BB0 802418D0 E7A40034 */  swc1      $f4, 0x34($sp)
/* CD8BB4 802418D4 AFA20010 */  sw        $v0, 0x10($sp)
/* CD8BB8 802418D8 8E040080 */  lw        $a0, 0x80($s0)
/* CD8BBC 802418DC 0C0372DF */  jal       func_800DCB7C
/* CD8BC0 802418E0 27A70030 */   addiu    $a3, $sp, 0x30
/* CD8BC4 802418E4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CD8BC8 802418E8 46180100 */  add.s     $f4, $f0, $f24
/* CD8BCC 802418EC 3C014000 */  lui       $at, 0x4000
/* CD8BD0 802418F0 44813800 */  mtc1      $at, $f7
/* CD8BD4 802418F4 44803000 */  mtc1      $zero, $f6
/* CD8BD8 802418F8 46162001 */  sub.s     $f0, $f4, $f22
/* CD8BDC 802418FC E7A4002C */  swc1      $f4, 0x2c($sp)
/* CD8BE0 80241900 460000A1 */  cvt.d.s   $f2, $f0
/* CD8BE4 80241904 4622303C */  c.lt.d    $f6, $f2
/* CD8BE8 80241908 00000000 */  nop       
/* CD8BEC 8024190C 45000005 */  bc1f      .L80241924
/* CD8BF0 80241910 E7A00034 */   swc1     $f0, 0x34($sp)
/* CD8BF4 80241914 4600B021 */  cvt.d.s   $f0, $f22
/* CD8BF8 80241918 46260000 */  add.d     $f0, $f0, $f6
/* CD8BFC 8024191C 08090654 */  j         .L80241950
/* CD8C00 80241920 462005A0 */   cvt.s.d  $f22, $f0
.L80241924:
/* CD8C04 80241924 3C01C000 */  lui       $at, 0xc000
/* CD8C08 80241928 44810800 */  mtc1      $at, $f1
/* CD8C0C 8024192C 44800000 */  mtc1      $zero, $f0
/* CD8C10 80241930 00000000 */  nop       
/* CD8C14 80241934 4620103C */  c.lt.d    $f2, $f0
/* CD8C18 80241938 00000000 */  nop       
/* CD8C1C 8024193C 45020004 */  bc1fl     .L80241950
/* CD8C20 80241940 46002586 */   mov.s    $f22, $f4
/* CD8C24 80241944 4600B021 */  cvt.d.s   $f0, $f22
/* CD8C28 80241948 46260001 */  sub.d     $f0, $f0, $f6
/* CD8C2C 8024194C 462005A0 */  cvt.s.d   $f22, $f0
.L80241950:
/* CD8C30 80241950 3C014059 */  lui       $at, 0x4059
/* CD8C34 80241954 44811800 */  mtc1      $at, $f3
/* CD8C38 80241958 44801000 */  mtc1      $zero, $f2
/* CD8C3C 8024195C 4600B021 */  cvt.d.s   $f0, $f22
/* CD8C40 80241960 46220002 */  mul.d     $f0, $f0, $f2
/* CD8C44 80241964 00000000 */  nop       
/* CD8C48 80241968 4620020D */  trunc.w.d $f8, $f0
/* CD8C4C 8024196C E628007C */  swc1      $f8, 0x7c($s1)
.L80241970:
/* CD8C50 80241970 8602008E */  lh        $v0, 0x8e($s0)
/* CD8C54 80241974 1C400017 */  bgtz      $v0, .L802419D4
/* CD8C58 80241978 240403E8 */   addiu    $a0, $zero, 0x3e8
.L8024197C:
/* CD8C5C 8024197C 24020002 */  addiu     $v0, $zero, 2
/* CD8C60 80241980 0C00A67F */  jal       rand_int
/* CD8C64 80241984 AE420070 */   sw       $v0, 0x70($s2)
/* CD8C68 80241988 3C035555 */  lui       $v1, 0x5555
/* CD8C6C 8024198C 34635556 */  ori       $v1, $v1, 0x5556
/* CD8C70 80241990 00430018 */  mult      $v0, $v1
/* CD8C74 80241994 000227C3 */  sra       $a0, $v0, 0x1f
/* CD8C78 80241998 00004010 */  mfhi      $t0
/* CD8C7C 8024199C 01042023 */  subu      $a0, $t0, $a0
/* CD8C80 802419A0 00041840 */  sll       $v1, $a0, 1
/* CD8C84 802419A4 00641821 */  addu      $v1, $v1, $a0
/* CD8C88 802419A8 00431023 */  subu      $v0, $v0, $v1
/* CD8C8C 802419AC 24430002 */  addiu     $v1, $v0, 2
/* CD8C90 802419B0 AE430074 */  sw        $v1, 0x74($s2)
/* CD8C94 802419B4 8EE2002C */  lw        $v0, 0x2c($s7)
/* CD8C98 802419B8 58400006 */  blezl     $v0, .L802419D4
/* CD8C9C 802419BC AE400070 */   sw       $zero, 0x70($s2)
/* CD8CA0 802419C0 8EE20004 */  lw        $v0, 4($s7)
/* CD8CA4 802419C4 58400003 */  blezl     $v0, .L802419D4
/* CD8CA8 802419C8 AE400070 */   sw       $zero, 0x70($s2)
/* CD8CAC 802419CC 50600001 */  beql      $v1, $zero, .L802419D4
/* CD8CB0 802419D0 AE400070 */   sw       $zero, 0x70($s2)
.L802419D4:
/* CD8CB4 802419D4 8FBF0064 */  lw        $ra, 0x64($sp)
/* CD8CB8 802419D8 8FBE0060 */  lw        $fp, 0x60($sp)
/* CD8CBC 802419DC 8FB7005C */  lw        $s7, 0x5c($sp)
/* CD8CC0 802419E0 8FB60058 */  lw        $s6, 0x58($sp)
/* CD8CC4 802419E4 8FB50054 */  lw        $s5, 0x54($sp)
/* CD8CC8 802419E8 8FB40050 */  lw        $s4, 0x50($sp)
/* CD8CCC 802419EC 8FB3004C */  lw        $s3, 0x4c($sp)
/* CD8CD0 802419F0 8FB20048 */  lw        $s2, 0x48($sp)
/* CD8CD4 802419F4 8FB10044 */  lw        $s1, 0x44($sp)
/* CD8CD8 802419F8 8FB00040 */  lw        $s0, 0x40($sp)
/* CD8CDC 802419FC D7BA0080 */  ldc1      $f26, 0x80($sp)
/* CD8CE0 80241A00 D7B80078 */  ldc1      $f24, 0x78($sp)
/* CD8CE4 80241A04 D7B60070 */  ldc1      $f22, 0x70($sp)
/* CD8CE8 80241A08 D7B40068 */  ldc1      $f20, 0x68($sp)
/* CD8CEC 80241A0C 03E00008 */  jr        $ra
/* CD8CF0 80241A10 27BD0088 */   addiu    $sp, $sp, 0x88
