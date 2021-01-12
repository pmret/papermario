.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415DC_EF3BEC
/* EF3BEC 802415DC 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EF3BF0 802415E0 AFB20048 */  sw        $s2, 0x48($sp)
/* EF3BF4 802415E4 0080902D */  daddu     $s2, $a0, $zero
/* EF3BF8 802415E8 AFBF0064 */  sw        $ra, 0x64($sp)
/* EF3BFC 802415EC AFBE0060 */  sw        $fp, 0x60($sp)
/* EF3C00 802415F0 AFB7005C */  sw        $s7, 0x5c($sp)
/* EF3C04 802415F4 AFB60058 */  sw        $s6, 0x58($sp)
/* EF3C08 802415F8 AFB50054 */  sw        $s5, 0x54($sp)
/* EF3C0C 802415FC AFB40050 */  sw        $s4, 0x50($sp)
/* EF3C10 80241600 AFB3004C */  sw        $s3, 0x4c($sp)
/* EF3C14 80241604 AFB10044 */  sw        $s1, 0x44($sp)
/* EF3C18 80241608 AFB00040 */  sw        $s0, 0x40($sp)
/* EF3C1C 8024160C F7BA0080 */  sdc1      $f26, 0x80($sp)
/* EF3C20 80241610 F7B80078 */  sdc1      $f24, 0x78($sp)
/* EF3C24 80241614 F7B60070 */  sdc1      $f22, 0x70($sp)
/* EF3C28 80241618 F7B40068 */  sdc1      $f20, 0x68($sp)
/* EF3C2C 8024161C 8E510148 */  lw        $s1, 0x148($s2)
/* EF3C30 80241620 00A0B82D */  daddu     $s7, $a1, $zero
/* EF3C34 80241624 86240008 */  lh        $a0, 8($s1)
/* EF3C38 80241628 0C00F92F */  jal       func_8003E4BC
/* EF3C3C 8024162C 00C0F02D */   daddu    $fp, $a2, $zero
/* EF3C40 80241630 C620007C */  lwc1      $f0, 0x7c($s1)
/* EF3C44 80241634 46800020 */  cvt.s.w   $f0, $f0
/* EF3C48 80241638 46000021 */  cvt.d.s   $f0, $f0
/* EF3C4C 8024163C 0040802D */  daddu     $s0, $v0, $zero
/* EF3C50 80241640 3C014059 */  lui       $at, 0x4059
/* EF3C54 80241644 44813800 */  mtc1      $at, $f7
/* EF3C58 80241648 44803000 */  mtc1      $zero, $f6
/* EF3C5C 8024164C 8602008E */  lh        $v0, 0x8e($s0)
/* EF3C60 80241650 9603008E */  lhu       $v1, 0x8e($s0)
/* EF3C64 80241654 46260003 */  div.d     $f0, $f0, $f6
/* EF3C68 80241658 462005A0 */  cvt.s.d   $f22, $f0
/* EF3C6C 8024165C C6200078 */  lwc1      $f0, 0x78($s1)
/* EF3C70 80241660 46800020 */  cvt.s.w   $f0, $f0
/* EF3C74 80241664 46000021 */  cvt.d.s   $f0, $f0
/* EF3C78 80241668 46260003 */  div.d     $f0, $f0, $f6
/* EF3C7C 8024166C 18400003 */  blez      $v0, .L8024167C
/* EF3C80 80241670 46200620 */   cvt.s.d  $f24, $f0
/* EF3C84 80241674 2462FFFF */  addiu     $v0, $v1, -1
/* EF3C88 80241678 A602008E */  sh        $v0, 0x8e($s0)
.L8024167C:
/* EF3C8C 8024167C 27B40028 */  addiu     $s4, $sp, 0x28
/* EF3C90 80241680 0280282D */  daddu     $a1, $s4, $zero
/* EF3C94 80241684 27B5002C */  addiu     $s5, $sp, 0x2c
/* EF3C98 80241688 02A0302D */  daddu     $a2, $s5, $zero
/* EF3C9C 8024168C 27B60030 */  addiu     $s6, $sp, 0x30
/* EF3CA0 80241690 02C0382D */  daddu     $a3, $s6, $zero
/* EF3CA4 80241694 C6000038 */  lwc1      $f0, 0x38($s0)
/* EF3CA8 80241698 C602003C */  lwc1      $f2, 0x3c($s0)
/* EF3CAC 8024169C C6040040 */  lwc1      $f4, 0x40($s0)
/* EF3CB0 802416A0 3C01447A */  lui       $at, 0x447a
/* EF3CB4 802416A4 4481D000 */  mtc1      $at, $f26
/* EF3CB8 802416A8 27B30034 */  addiu     $s3, $sp, 0x34
/* EF3CBC 802416AC E7A00028 */  swc1      $f0, 0x28($sp)
/* EF3CC0 802416B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EF3CC4 802416B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* EF3CC8 802416B8 E7BA0034 */  swc1      $f26, 0x34($sp)
/* EF3CCC 802416BC C6340070 */  lwc1      $f20, 0x70($s1)
/* EF3CD0 802416C0 4680A520 */  cvt.s.w   $f20, $f20
/* EF3CD4 802416C4 4600A521 */  cvt.d.s   $f20, $f20
/* EF3CD8 802416C8 4626A503 */  div.d     $f20, $f20, $f6
/* EF3CDC 802416CC AFB30010 */  sw        $s3, 0x10($sp)
/* EF3CE0 802416D0 8E040080 */  lw        $a0, 0x80($s0)
/* EF3CE4 802416D4 0C03908F */  jal       func_800E423C
/* EF3CE8 802416D8 4620A520 */   cvt.s.d  $f20, $f20
/* EF3CEC 802416DC C62C0074 */  lwc1      $f12, 0x74($s1)
/* EF3CF0 802416E0 0C00AD77 */  jal       func_8002B5DC
/* EF3CF4 802416E4 46806320 */   cvt.s.w  $f12, $f12
/* EF3CF8 802416E8 46140002 */  mul.s     $f0, $f0, $f20
/* EF3CFC 802416EC 00000000 */  nop
/* EF3D00 802416F0 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* EF3D04 802416F4 46181080 */  add.s     $f2, $f2, $f24
/* EF3D08 802416F8 46001080 */  add.s     $f2, $f2, $f0
/* EF3D0C 802416FC E602003C */  swc1      $f2, 0x3c($s0)
/* EF3D10 80241700 8E220074 */  lw        $v0, 0x74($s1)
/* EF3D14 80241704 2442000C */  addiu     $v0, $v0, 0xc
/* EF3D18 80241708 44826000 */  mtc1      $v0, $f12
/* EF3D1C 8024170C 00000000 */  nop
/* EF3D20 80241710 0C00AB85 */  jal       func_8002AE14
/* EF3D24 80241714 46806320 */   cvt.s.w  $f12, $f12
/* EF3D28 80241718 4600020D */  trunc.w.s $f8, $f0
/* EF3D2C 8024171C E6280074 */  swc1      $f8, 0x74($s1)
/* EF3D30 80241720 8EE30014 */  lw        $v1, 0x14($s7)
/* EF3D34 80241724 0460003C */  bltz      $v1, .L80241818
/* EF3D38 80241728 00000000 */   nop
/* EF3D3C 8024172C 8E420074 */  lw        $v0, 0x74($s2)
/* EF3D40 80241730 1C400038 */  bgtz      $v0, .L80241814
/* EF3D44 80241734 2442FFFF */   addiu    $v0, $v0, -1
/* EF3D48 80241738 03C0202D */  daddu     $a0, $fp, $zero
/* EF3D4C 8024173C AE430074 */  sw        $v1, 0x74($s2)
/* EF3D50 80241740 AFA00010 */  sw        $zero, 0x10($sp)
/* EF3D54 80241744 8EE6000C */  lw        $a2, 0xc($s7)
/* EF3D58 80241748 8EE70010 */  lw        $a3, 0x10($s7)
/* EF3D5C 8024174C 0C013469 */  jal       func_8004D1A4
/* EF3D60 80241750 0220282D */   daddu    $a1, $s1, $zero
/* EF3D64 80241754 1040002D */  beqz      $v0, .L8024180C
/* EF3D68 80241758 0000202D */   daddu    $a0, $zero, $zero
/* EF3D6C 8024175C 0200282D */  daddu     $a1, $s0, $zero
/* EF3D70 80241760 0000302D */  daddu     $a2, $zero, $zero
/* EF3D74 80241764 860300A8 */  lh        $v1, 0xa8($s0)
/* EF3D78 80241768 3C013F80 */  lui       $at, 0x3f80
/* EF3D7C 8024176C 44810000 */  mtc1      $at, $f0
/* EF3D80 80241770 3C014000 */  lui       $at, 0x4000
/* EF3D84 80241774 44811000 */  mtc1      $at, $f2
/* EF3D88 80241778 3C01C1A0 */  lui       $at, 0xc1a0
/* EF3D8C 8024177C 44812000 */  mtc1      $at, $f4
/* EF3D90 80241780 2402000F */  addiu     $v0, $zero, 0xf
/* EF3D94 80241784 AFA2001C */  sw        $v0, 0x1c($sp)
/* EF3D98 80241788 44834000 */  mtc1      $v1, $f8
/* EF3D9C 8024178C 00000000 */  nop
/* EF3DA0 80241790 46804220 */  cvt.s.w   $f8, $f8
/* EF3DA4 80241794 44074000 */  mfc1      $a3, $f8
/* EF3DA8 80241798 27A20038 */  addiu     $v0, $sp, 0x38
/* EF3DAC 8024179C AFA20020 */  sw        $v0, 0x20($sp)
/* EF3DB0 802417A0 E7A00010 */  swc1      $f0, 0x10($sp)
/* EF3DB4 802417A4 E7A20014 */  swc1      $f2, 0x14($sp)
/* EF3DB8 802417A8 0C01D444 */  jal       func_80075110
/* EF3DBC 802417AC E7A40018 */   swc1     $f4, 0x18($sp)
/* EF3DC0 802417B0 0200202D */  daddu     $a0, $s0, $zero
/* EF3DC4 802417B4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EF3DC8 802417B8 0C013600 */  jal       func_8004D800
/* EF3DCC 802417BC 3C060020 */   lui      $a2, 0x20
/* EF3DD0 802417C0 0280282D */  daddu     $a1, $s4, $zero
/* EF3DD4 802417C4 C6000038 */  lwc1      $f0, 0x38($s0)
/* EF3DD8 802417C8 C602003C */  lwc1      $f2, 0x3c($s0)
/* EF3DDC 802417CC C6040040 */  lwc1      $f4, 0x40($s0)
/* EF3DE0 802417D0 02A0302D */  daddu     $a2, $s5, $zero
/* EF3DE4 802417D4 E7BA0034 */  swc1      $f26, 0x34($sp)
/* EF3DE8 802417D8 E7A00028 */  swc1      $f0, 0x28($sp)
/* EF3DEC 802417DC E7A2002C */  swc1      $f2, 0x2c($sp)
/* EF3DF0 802417E0 E7A40030 */  swc1      $f4, 0x30($sp)
/* EF3DF4 802417E4 AFB30010 */  sw        $s3, 0x10($sp)
/* EF3DF8 802417E8 8E040080 */  lw        $a0, 0x80($s0)
/* EF3DFC 802417EC 0C03908F */  jal       func_800E423C
/* EF3E00 802417F0 02C0382D */   daddu    $a3, $s6, $zero
/* EF3E04 802417F4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EF3E08 802417F8 46180000 */  add.s     $f0, $f0, $f24
/* EF3E0C 802417FC 2402000C */  addiu     $v0, $zero, 0xc
/* EF3E10 80241800 E6000064 */  swc1      $f0, 0x64($s0)
/* EF3E14 80241804 08090680 */  j         .L80241A00
/* EF3E18 80241808 AE420070 */   sw       $v0, 0x70($s2)
.L8024180C:
/* EF3E1C 8024180C 8E420074 */  lw        $v0, 0x74($s2)
/* EF3E20 80241810 2442FFFF */  addiu     $v0, $v0, -1
.L80241814:
/* EF3E24 80241814 AE420074 */  sw        $v0, 0x74($s2)
.L80241818:
/* EF3E28 80241818 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF3E2C 8024181C C6000040 */  lwc1      $f0, 0x40($s0)
/* EF3E30 80241820 C4620000 */  lwc1      $f2, ($v1)
/* EF3E34 80241824 468010A0 */  cvt.s.w   $f2, $f2
/* EF3E38 80241828 C4640008 */  lwc1      $f4, 8($v1)
/* EF3E3C 8024182C 46802120 */  cvt.s.w   $f4, $f4
/* EF3E40 80241830 E7A00010 */  swc1      $f0, 0x10($sp)
/* EF3E44 80241834 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EF3E48 80241838 44051000 */  mfc1      $a1, $f2
/* EF3E4C 8024183C C440000C */  lwc1      $f0, 0xc($v0)
/* EF3E50 80241840 46800020 */  cvt.s.w   $f0, $f0
/* EF3E54 80241844 E7A00014 */  swc1      $f0, 0x14($sp)
/* EF3E58 80241848 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EF3E5C 8024184C 44062000 */  mfc1      $a2, $f4
/* EF3E60 80241850 C4400010 */  lwc1      $f0, 0x10($v0)
/* EF3E64 80241854 46800020 */  cvt.s.w   $f0, $f0
/* EF3E68 80241858 E7A00018 */  swc1      $f0, 0x18($sp)
/* EF3E6C 8024185C 8C640018 */  lw        $a0, 0x18($v1)
/* EF3E70 80241860 0C013431 */  jal       func_8004D0C4
/* EF3E74 80241864 8E070038 */   lw       $a3, 0x38($s0)
/* EF3E78 80241868 1040000D */  beqz      $v0, .L802418A0
/* EF3E7C 8024186C 00000000 */   nop
/* EF3E80 80241870 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EF3E84 80241874 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EF3E88 80241878 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EF3E8C 8024187C C4480000 */  lwc1      $f8, ($v0)
/* EF3E90 80241880 46804220 */  cvt.s.w   $f8, $f8
/* EF3E94 80241884 44064000 */  mfc1      $a2, $f8
/* EF3E98 80241888 C4480008 */  lwc1      $f8, 8($v0)
/* EF3E9C 8024188C 46804220 */  cvt.s.w   $f8, $f8
/* EF3EA0 80241890 44074000 */  mfc1      $a3, $f8
/* EF3EA4 80241894 0C00ABDC */  jal       fio_validate_header_checksums
/* EF3EA8 80241898 00000000 */   nop
/* EF3EAC 8024189C E600000C */  swc1      $f0, 0xc($s0)
.L802418A0:
/* EF3EB0 802418A0 8602008C */  lh        $v0, 0x8c($s0)
/* EF3EB4 802418A4 14400056 */  bnez      $v0, .L80241A00
/* EF3EB8 802418A8 00000000 */   nop
/* EF3EBC 802418AC 8602008E */  lh        $v0, 0x8e($s0)
/* EF3EC0 802418B0 1840003D */  blez      $v0, .L802419A8
/* EF3EC4 802418B4 240403E8 */   addiu    $a0, $zero, 0x3e8
/* EF3EC8 802418B8 8E050018 */  lw        $a1, 0x18($s0)
/* EF3ECC 802418BC 8E06000C */  lw        $a2, 0xc($s0)
/* EF3ED0 802418C0 0C00F909 */  jal       func_8003E424
/* EF3ED4 802418C4 0200202D */   daddu    $a0, $s0, $zero
/* EF3ED8 802418C8 8E22006C */  lw        $v0, 0x6c($s1)
/* EF3EDC 802418CC 30420001 */  andi      $v0, $v0, 1
/* EF3EE0 802418D0 10400032 */  beqz      $v0, .L8024199C
/* EF3EE4 802418D4 27A50028 */   addiu    $a1, $sp, 0x28
/* EF3EE8 802418D8 27A6002C */  addiu     $a2, $sp, 0x2c
/* EF3EEC 802418DC C6000038 */  lwc1      $f0, 0x38($s0)
/* EF3EF0 802418E0 C6020040 */  lwc1      $f2, 0x40($s0)
/* EF3EF4 802418E4 3C01447A */  lui       $at, 0x447a
/* EF3EF8 802418E8 44812000 */  mtc1      $at, $f4
/* EF3EFC 802418EC 27A20034 */  addiu     $v0, $sp, 0x34
/* EF3F00 802418F0 E7B6002C */  swc1      $f22, 0x2c($sp)
/* EF3F04 802418F4 E7A00028 */  swc1      $f0, 0x28($sp)
/* EF3F08 802418F8 E7A20030 */  swc1      $f2, 0x30($sp)
/* EF3F0C 802418FC E7A40034 */  swc1      $f4, 0x34($sp)
/* EF3F10 80241900 AFA20010 */  sw        $v0, 0x10($sp)
/* EF3F14 80241904 8E040080 */  lw        $a0, 0x80($s0)
/* EF3F18 80241908 0C03908F */  jal       func_800E423C
/* EF3F1C 8024190C 27A70030 */   addiu    $a3, $sp, 0x30
/* EF3F20 80241910 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EF3F24 80241914 46180100 */  add.s     $f4, $f0, $f24
/* EF3F28 80241918 3C014000 */  lui       $at, 0x4000
/* EF3F2C 8024191C 44813800 */  mtc1      $at, $f7
/* EF3F30 80241920 44803000 */  mtc1      $zero, $f6
/* EF3F34 80241924 46162001 */  sub.s     $f0, $f4, $f22
/* EF3F38 80241928 E7A4002C */  swc1      $f4, 0x2c($sp)
/* EF3F3C 8024192C 460000A1 */  cvt.d.s   $f2, $f0
/* EF3F40 80241930 4622303C */  c.lt.d    $f6, $f2
/* EF3F44 80241934 00000000 */  nop
/* EF3F48 80241938 45000005 */  bc1f      .L80241950
/* EF3F4C 8024193C E7A00034 */   swc1     $f0, 0x34($sp)
/* EF3F50 80241940 4600B021 */  cvt.d.s   $f0, $f22
/* EF3F54 80241944 46260000 */  add.d     $f0, $f0, $f6
/* EF3F58 80241948 0809065F */  j         .L8024197C
/* EF3F5C 8024194C 462005A0 */   cvt.s.d  $f22, $f0
.L80241950:
/* EF3F60 80241950 3C01C000 */  lui       $at, 0xc000
/* EF3F64 80241954 44810800 */  mtc1      $at, $f1
/* EF3F68 80241958 44800000 */  mtc1      $zero, $f0
/* EF3F6C 8024195C 00000000 */  nop
/* EF3F70 80241960 4620103C */  c.lt.d    $f2, $f0
/* EF3F74 80241964 00000000 */  nop
/* EF3F78 80241968 45020004 */  bc1fl     .L8024197C
/* EF3F7C 8024196C 46002586 */   mov.s    $f22, $f4
/* EF3F80 80241970 4600B021 */  cvt.d.s   $f0, $f22
/* EF3F84 80241974 46260001 */  sub.d     $f0, $f0, $f6
/* EF3F88 80241978 462005A0 */  cvt.s.d   $f22, $f0
.L8024197C:
/* EF3F8C 8024197C 3C014059 */  lui       $at, 0x4059
/* EF3F90 80241980 44811800 */  mtc1      $at, $f3
/* EF3F94 80241984 44801000 */  mtc1      $zero, $f2
/* EF3F98 80241988 4600B021 */  cvt.d.s   $f0, $f22
/* EF3F9C 8024198C 46220002 */  mul.d     $f0, $f0, $f2
/* EF3FA0 80241990 00000000 */  nop
/* EF3FA4 80241994 4620020D */  trunc.w.d $f8, $f0
/* EF3FA8 80241998 E628007C */  swc1      $f8, 0x7c($s1)
.L8024199C:
/* EF3FAC 8024199C 8602008E */  lh        $v0, 0x8e($s0)
/* EF3FB0 802419A0 1C400017 */  bgtz      $v0, .L80241A00
/* EF3FB4 802419A4 240403E8 */   addiu    $a0, $zero, 0x3e8
.L802419A8:
/* EF3FB8 802419A8 24020002 */  addiu     $v0, $zero, 2
/* EF3FBC 802419AC 0C00AB3B */  jal       func_8002ACEC
/* EF3FC0 802419B0 AE420070 */   sw       $v0, 0x70($s2)
/* EF3FC4 802419B4 3C035555 */  lui       $v1, 0x5555
/* EF3FC8 802419B8 34635556 */  ori       $v1, $v1, 0x5556
/* EF3FCC 802419BC 00430018 */  mult      $v0, $v1
/* EF3FD0 802419C0 000227C3 */  sra       $a0, $v0, 0x1f
/* EF3FD4 802419C4 00004010 */  mfhi      $t0
/* EF3FD8 802419C8 01042023 */  subu      $a0, $t0, $a0
/* EF3FDC 802419CC 00041840 */  sll       $v1, $a0, 1
/* EF3FE0 802419D0 00641821 */  addu      $v1, $v1, $a0
/* EF3FE4 802419D4 00431023 */  subu      $v0, $v0, $v1
/* EF3FE8 802419D8 24430002 */  addiu     $v1, $v0, 2
/* EF3FEC 802419DC AE430074 */  sw        $v1, 0x74($s2)
/* EF3FF0 802419E0 8EE2002C */  lw        $v0, 0x2c($s7)
/* EF3FF4 802419E4 58400006 */  blezl     $v0, .L80241A00
/* EF3FF8 802419E8 AE400070 */   sw       $zero, 0x70($s2)
/* EF3FFC 802419EC 8EE20004 */  lw        $v0, 4($s7)
/* EF4000 802419F0 58400003 */  blezl     $v0, .L80241A00
/* EF4004 802419F4 AE400070 */   sw       $zero, 0x70($s2)
/* EF4008 802419F8 50600001 */  beql      $v1, $zero, .L80241A00
/* EF400C 802419FC AE400070 */   sw       $zero, 0x70($s2)
.L80241A00:
/* EF4010 80241A00 8FBF0064 */  lw        $ra, 0x64($sp)
/* EF4014 80241A04 8FBE0060 */  lw        $fp, 0x60($sp)
/* EF4018 80241A08 8FB7005C */  lw        $s7, 0x5c($sp)
/* EF401C 80241A0C 8FB60058 */  lw        $s6, 0x58($sp)
/* EF4020 80241A10 8FB50054 */  lw        $s5, 0x54($sp)
/* EF4024 80241A14 8FB40050 */  lw        $s4, 0x50($sp)
/* EF4028 80241A18 8FB3004C */  lw        $s3, 0x4c($sp)
/* EF402C 80241A1C 8FB20048 */  lw        $s2, 0x48($sp)
/* EF4030 80241A20 8FB10044 */  lw        $s1, 0x44($sp)
/* EF4034 80241A24 8FB00040 */  lw        $s0, 0x40($sp)
/* EF4038 80241A28 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* EF403C 80241A2C D7B80078 */  ldc1      $f24, 0x78($sp)
/* EF4040 80241A30 D7B60070 */  ldc1      $f22, 0x70($sp)
/* EF4044 80241A34 D7B40068 */  ldc1      $f20, 0x68($sp)
/* EF4048 80241A38 03E00008 */  jr        $ra
/* EF404C 80241A3C 27BD0088 */   addiu    $sp, $sp, 0x88
