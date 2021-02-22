.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241704_CC4F14
/* CC4F14 80241704 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CC4F18 80241708 AFB20048 */  sw        $s2, 0x48($sp)
/* CC4F1C 8024170C 0080902D */  daddu     $s2, $a0, $zero
/* CC4F20 80241710 AFBF0064 */  sw        $ra, 0x64($sp)
/* CC4F24 80241714 AFBE0060 */  sw        $fp, 0x60($sp)
/* CC4F28 80241718 AFB7005C */  sw        $s7, 0x5c($sp)
/* CC4F2C 8024171C AFB60058 */  sw        $s6, 0x58($sp)
/* CC4F30 80241720 AFB50054 */  sw        $s5, 0x54($sp)
/* CC4F34 80241724 AFB40050 */  sw        $s4, 0x50($sp)
/* CC4F38 80241728 AFB3004C */  sw        $s3, 0x4c($sp)
/* CC4F3C 8024172C AFB10044 */  sw        $s1, 0x44($sp)
/* CC4F40 80241730 AFB00040 */  sw        $s0, 0x40($sp)
/* CC4F44 80241734 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* CC4F48 80241738 F7B80078 */  sdc1      $f24, 0x78($sp)
/* CC4F4C 8024173C F7B60070 */  sdc1      $f22, 0x70($sp)
/* CC4F50 80241740 F7B40068 */  sdc1      $f20, 0x68($sp)
/* CC4F54 80241744 8E510148 */  lw        $s1, 0x148($s2)
/* CC4F58 80241748 00A0B82D */  daddu     $s7, $a1, $zero
/* CC4F5C 8024174C 86240008 */  lh        $a0, 8($s1)
/* CC4F60 80241750 0C00EABB */  jal       get_npc_unsafe
/* CC4F64 80241754 00C0F02D */   daddu    $fp, $a2, $zero
/* CC4F68 80241758 C620007C */  lwc1      $f0, 0x7c($s1)
/* CC4F6C 8024175C 46800020 */  cvt.s.w   $f0, $f0
/* CC4F70 80241760 46000021 */  cvt.d.s   $f0, $f0
/* CC4F74 80241764 0040802D */  daddu     $s0, $v0, $zero
/* CC4F78 80241768 3C014059 */  lui       $at, 0x4059
/* CC4F7C 8024176C 44813800 */  mtc1      $at, $f7
/* CC4F80 80241770 44803000 */  mtc1      $zero, $f6
/* CC4F84 80241774 8602008E */  lh        $v0, 0x8e($s0)
/* CC4F88 80241778 9603008E */  lhu       $v1, 0x8e($s0)
/* CC4F8C 8024177C 46260003 */  div.d     $f0, $f0, $f6
/* CC4F90 80241780 462005A0 */  cvt.s.d   $f22, $f0
/* CC4F94 80241784 C6200078 */  lwc1      $f0, 0x78($s1)
/* CC4F98 80241788 46800020 */  cvt.s.w   $f0, $f0
/* CC4F9C 8024178C 46000021 */  cvt.d.s   $f0, $f0
/* CC4FA0 80241790 46260003 */  div.d     $f0, $f0, $f6
/* CC4FA4 80241794 18400003 */  blez      $v0, .L802417A4
/* CC4FA8 80241798 46200620 */   cvt.s.d  $f24, $f0
/* CC4FAC 8024179C 2462FFFF */  addiu     $v0, $v1, -1
/* CC4FB0 802417A0 A602008E */  sh        $v0, 0x8e($s0)
.L802417A4:
/* CC4FB4 802417A4 27B40028 */  addiu     $s4, $sp, 0x28
/* CC4FB8 802417A8 0280282D */  daddu     $a1, $s4, $zero
/* CC4FBC 802417AC 27B5002C */  addiu     $s5, $sp, 0x2c
/* CC4FC0 802417B0 02A0302D */  daddu     $a2, $s5, $zero
/* CC4FC4 802417B4 27B60030 */  addiu     $s6, $sp, 0x30
/* CC4FC8 802417B8 02C0382D */  daddu     $a3, $s6, $zero
/* CC4FCC 802417BC C6000038 */  lwc1      $f0, 0x38($s0)
/* CC4FD0 802417C0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CC4FD4 802417C4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CC4FD8 802417C8 3C01447A */  lui       $at, 0x447a
/* CC4FDC 802417CC 4481D000 */  mtc1      $at, $f26
/* CC4FE0 802417D0 27B30034 */  addiu     $s3, $sp, 0x34
/* CC4FE4 802417D4 E7A00028 */  swc1      $f0, 0x28($sp)
/* CC4FE8 802417D8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CC4FEC 802417DC E7A40030 */  swc1      $f4, 0x30($sp)
/* CC4FF0 802417E0 E7BA0034 */  swc1      $f26, 0x34($sp)
/* CC4FF4 802417E4 C6340070 */  lwc1      $f20, 0x70($s1)
/* CC4FF8 802417E8 4680A520 */  cvt.s.w   $f20, $f20
/* CC4FFC 802417EC 4600A521 */  cvt.d.s   $f20, $f20
/* CC5000 802417F0 4626A503 */  div.d     $f20, $f20, $f6
/* CC5004 802417F4 AFB30010 */  sw        $s3, 0x10($sp)
/* CC5008 802417F8 8E040080 */  lw        $a0, 0x80($s0)
/* CC500C 802417FC 0C0372DF */  jal       func_800DCB7C
/* CC5010 80241800 4620A520 */   cvt.s.d  $f20, $f20
/* CC5014 80241804 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CC5018 80241808 0C00A8BB */  jal       sin_deg
/* CC501C 8024180C 46806320 */   cvt.s.w  $f12, $f12
/* CC5020 80241810 46140002 */  mul.s     $f0, $f0, $f20
/* CC5024 80241814 00000000 */  nop
/* CC5028 80241818 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* CC502C 8024181C 46181080 */  add.s     $f2, $f2, $f24
/* CC5030 80241820 46001080 */  add.s     $f2, $f2, $f0
/* CC5034 80241824 E602003C */  swc1      $f2, 0x3c($s0)
/* CC5038 80241828 8E220074 */  lw        $v0, 0x74($s1)
/* CC503C 8024182C 2442000C */  addiu     $v0, $v0, 0xc
/* CC5040 80241830 44826000 */  mtc1      $v0, $f12
/* CC5044 80241834 00000000 */  nop
/* CC5048 80241838 0C00A6C9 */  jal       clamp_angle
/* CC504C 8024183C 46806320 */   cvt.s.w  $f12, $f12
/* CC5050 80241840 4600020D */  trunc.w.s $f8, $f0
/* CC5054 80241844 E6280074 */  swc1      $f8, 0x74($s1)
/* CC5058 80241848 8EE30014 */  lw        $v1, 0x14($s7)
/* CC505C 8024184C 0460003C */  bltz      $v1, .L80241940
/* CC5060 80241850 00000000 */   nop
/* CC5064 80241854 8E420074 */  lw        $v0, 0x74($s2)
/* CC5068 80241858 1C400038 */  bgtz      $v0, .L8024193C
/* CC506C 8024185C 2442FFFF */   addiu    $v0, $v0, -1
/* CC5070 80241860 03C0202D */  daddu     $a0, $fp, $zero
/* CC5074 80241864 AE430074 */  sw        $v1, 0x74($s2)
/* CC5078 80241868 AFA00010 */  sw        $zero, 0x10($sp)
/* CC507C 8024186C 8EE6000C */  lw        $a2, 0xc($s7)
/* CC5080 80241870 8EE70010 */  lw        $a3, 0x10($s7)
/* CC5084 80241874 0C01242D */  jal       func_800490B4
/* CC5088 80241878 0220282D */   daddu    $a1, $s1, $zero
/* CC508C 8024187C 1040002D */  beqz      $v0, .L80241934
/* CC5090 80241880 0000202D */   daddu    $a0, $zero, $zero
/* CC5094 80241884 0200282D */  daddu     $a1, $s0, $zero
/* CC5098 80241888 0000302D */  daddu     $a2, $zero, $zero
/* CC509C 8024188C 860300A8 */  lh        $v1, 0xa8($s0)
/* CC50A0 80241890 3C013F80 */  lui       $at, 0x3f80
/* CC50A4 80241894 44810000 */  mtc1      $at, $f0
/* CC50A8 80241898 3C014000 */  lui       $at, 0x4000
/* CC50AC 8024189C 44811000 */  mtc1      $at, $f2
/* CC50B0 802418A0 3C01C1A0 */  lui       $at, 0xc1a0
/* CC50B4 802418A4 44812000 */  mtc1      $at, $f4
/* CC50B8 802418A8 2402000F */  addiu     $v0, $zero, 0xf
/* CC50BC 802418AC AFA2001C */  sw        $v0, 0x1c($sp)
/* CC50C0 802418B0 44834000 */  mtc1      $v1, $f8
/* CC50C4 802418B4 00000000 */  nop
/* CC50C8 802418B8 46804220 */  cvt.s.w   $f8, $f8
/* CC50CC 802418BC 44074000 */  mfc1      $a3, $f8
/* CC50D0 802418C0 27A20038 */  addiu     $v0, $sp, 0x38
/* CC50D4 802418C4 AFA20020 */  sw        $v0, 0x20($sp)
/* CC50D8 802418C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CC50DC 802418CC E7A20014 */  swc1      $f2, 0x14($sp)
/* CC50E0 802418D0 0C01BFA4 */  jal       fx_emote
/* CC50E4 802418D4 E7A40018 */   swc1     $f4, 0x18($sp)
/* CC50E8 802418D8 0200202D */  daddu     $a0, $s0, $zero
/* CC50EC 802418DC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CC50F0 802418E0 0C012530 */  jal       func_800494C0
/* CC50F4 802418E4 3C060020 */   lui      $a2, 0x20
/* CC50F8 802418E8 0280282D */  daddu     $a1, $s4, $zero
/* CC50FC 802418EC C6000038 */  lwc1      $f0, 0x38($s0)
/* CC5100 802418F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CC5104 802418F4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CC5108 802418F8 02A0302D */  daddu     $a2, $s5, $zero
/* CC510C 802418FC E7BA0034 */  swc1      $f26, 0x34($sp)
/* CC5110 80241900 E7A00028 */  swc1      $f0, 0x28($sp)
/* CC5114 80241904 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CC5118 80241908 E7A40030 */  swc1      $f4, 0x30($sp)
/* CC511C 8024190C AFB30010 */  sw        $s3, 0x10($sp)
/* CC5120 80241910 8E040080 */  lw        $a0, 0x80($s0)
/* CC5124 80241914 0C0372DF */  jal       func_800DCB7C
/* CC5128 80241918 02C0382D */   daddu    $a3, $s6, $zero
/* CC512C 8024191C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CC5130 80241920 46180000 */  add.s     $f0, $f0, $f24
/* CC5134 80241924 2402000C */  addiu     $v0, $zero, 0xc
/* CC5138 80241928 E6000064 */  swc1      $f0, 0x64($s0)
/* CC513C 8024192C 080906CA */  j         .L80241B28
/* CC5140 80241930 AE420070 */   sw       $v0, 0x70($s2)
.L80241934:
/* CC5144 80241934 8E420074 */  lw        $v0, 0x74($s2)
/* CC5148 80241938 2442FFFF */  addiu     $v0, $v0, -1
.L8024193C:
/* CC514C 8024193C AE420074 */  sw        $v0, 0x74($s2)
.L80241940:
/* CC5150 80241940 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5154 80241944 C6000040 */  lwc1      $f0, 0x40($s0)
/* CC5158 80241948 C4620000 */  lwc1      $f2, ($v1)
/* CC515C 8024194C 468010A0 */  cvt.s.w   $f2, $f2
/* CC5160 80241950 C4640008 */  lwc1      $f4, 8($v1)
/* CC5164 80241954 46802120 */  cvt.s.w   $f4, $f4
/* CC5168 80241958 E7A00010 */  swc1      $f0, 0x10($sp)
/* CC516C 8024195C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC5170 80241960 44051000 */  mfc1      $a1, $f2
/* CC5174 80241964 C440000C */  lwc1      $f0, 0xc($v0)
/* CC5178 80241968 46800020 */  cvt.s.w   $f0, $f0
/* CC517C 8024196C E7A00014 */  swc1      $f0, 0x14($sp)
/* CC5180 80241970 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC5184 80241974 44062000 */  mfc1      $a2, $f4
/* CC5188 80241978 C4400010 */  lwc1      $f0, 0x10($v0)
/* CC518C 8024197C 46800020 */  cvt.s.w   $f0, $f0
/* CC5190 80241980 E7A00018 */  swc1      $f0, 0x18($sp)
/* CC5194 80241984 8C640018 */  lw        $a0, 0x18($v1)
/* CC5198 80241988 0C0123F5 */  jal       is_point_within_region
/* CC519C 8024198C 8E070038 */   lw       $a3, 0x38($s0)
/* CC51A0 80241990 1040000D */  beqz      $v0, .L802419C8
/* CC51A4 80241994 00000000 */   nop
/* CC51A8 80241998 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC51AC 8024199C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CC51B0 802419A0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CC51B4 802419A4 C4480000 */  lwc1      $f8, ($v0)
/* CC51B8 802419A8 46804220 */  cvt.s.w   $f8, $f8
/* CC51BC 802419AC 44064000 */  mfc1      $a2, $f8
/* CC51C0 802419B0 C4480008 */  lwc1      $f8, 8($v0)
/* CC51C4 802419B4 46804220 */  cvt.s.w   $f8, $f8
/* CC51C8 802419B8 44074000 */  mfc1      $a3, $f8
/* CC51CC 802419BC 0C00A720 */  jal       atan2
/* CC51D0 802419C0 00000000 */   nop
/* CC51D4 802419C4 E600000C */  swc1      $f0, 0xc($s0)
.L802419C8:
/* CC51D8 802419C8 8602008C */  lh        $v0, 0x8c($s0)
/* CC51DC 802419CC 14400056 */  bnez      $v0, .L80241B28
/* CC51E0 802419D0 00000000 */   nop
/* CC51E4 802419D4 8602008E */  lh        $v0, 0x8e($s0)
/* CC51E8 802419D8 1840003D */  blez      $v0, .L80241AD0
/* CC51EC 802419DC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CC51F0 802419E0 8E050018 */  lw        $a1, 0x18($s0)
/* CC51F4 802419E4 8E06000C */  lw        $a2, 0xc($s0)
/* CC51F8 802419E8 0C00EA95 */  jal       npc_move_heading
/* CC51FC 802419EC 0200202D */   daddu    $a0, $s0, $zero
/* CC5200 802419F0 8E22006C */  lw        $v0, 0x6c($s1)
/* CC5204 802419F4 30420001 */  andi      $v0, $v0, 1
/* CC5208 802419F8 10400032 */  beqz      $v0, .L80241AC4
/* CC520C 802419FC 27A50028 */   addiu    $a1, $sp, 0x28
/* CC5210 80241A00 27A6002C */  addiu     $a2, $sp, 0x2c
/* CC5214 80241A04 C6000038 */  lwc1      $f0, 0x38($s0)
/* CC5218 80241A08 C6020040 */  lwc1      $f2, 0x40($s0)
/* CC521C 80241A0C 3C01447A */  lui       $at, 0x447a
/* CC5220 80241A10 44812000 */  mtc1      $at, $f4
/* CC5224 80241A14 27A20034 */  addiu     $v0, $sp, 0x34
/* CC5228 80241A18 E7B6002C */  swc1      $f22, 0x2c($sp)
/* CC522C 80241A1C E7A00028 */  swc1      $f0, 0x28($sp)
/* CC5230 80241A20 E7A20030 */  swc1      $f2, 0x30($sp)
/* CC5234 80241A24 E7A40034 */  swc1      $f4, 0x34($sp)
/* CC5238 80241A28 AFA20010 */  sw        $v0, 0x10($sp)
/* CC523C 80241A2C 8E040080 */  lw        $a0, 0x80($s0)
/* CC5240 80241A30 0C0372DF */  jal       func_800DCB7C
/* CC5244 80241A34 27A70030 */   addiu    $a3, $sp, 0x30
/* CC5248 80241A38 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CC524C 80241A3C 46180100 */  add.s     $f4, $f0, $f24
/* CC5250 80241A40 3C014000 */  lui       $at, 0x4000
/* CC5254 80241A44 44813800 */  mtc1      $at, $f7
/* CC5258 80241A48 44803000 */  mtc1      $zero, $f6
/* CC525C 80241A4C 46162001 */  sub.s     $f0, $f4, $f22
/* CC5260 80241A50 E7A4002C */  swc1      $f4, 0x2c($sp)
/* CC5264 80241A54 460000A1 */  cvt.d.s   $f2, $f0
/* CC5268 80241A58 4622303C */  c.lt.d    $f6, $f2
/* CC526C 80241A5C 00000000 */  nop
/* CC5270 80241A60 45000005 */  bc1f      .L80241A78
/* CC5274 80241A64 E7A00034 */   swc1     $f0, 0x34($sp)
/* CC5278 80241A68 4600B021 */  cvt.d.s   $f0, $f22
/* CC527C 80241A6C 46260000 */  add.d     $f0, $f0, $f6
/* CC5280 80241A70 080906A9 */  j         .L80241AA4
/* CC5284 80241A74 462005A0 */   cvt.s.d  $f22, $f0
.L80241A78:
/* CC5288 80241A78 3C01C000 */  lui       $at, 0xc000
/* CC528C 80241A7C 44810800 */  mtc1      $at, $f1
/* CC5290 80241A80 44800000 */  mtc1      $zero, $f0
/* CC5294 80241A84 00000000 */  nop
/* CC5298 80241A88 4620103C */  c.lt.d    $f2, $f0
/* CC529C 80241A8C 00000000 */  nop
/* CC52A0 80241A90 45020004 */  bc1fl     .L80241AA4
/* CC52A4 80241A94 46002586 */   mov.s    $f22, $f4
/* CC52A8 80241A98 4600B021 */  cvt.d.s   $f0, $f22
/* CC52AC 80241A9C 46260001 */  sub.d     $f0, $f0, $f6
/* CC52B0 80241AA0 462005A0 */  cvt.s.d   $f22, $f0
.L80241AA4:
/* CC52B4 80241AA4 3C014059 */  lui       $at, 0x4059
/* CC52B8 80241AA8 44811800 */  mtc1      $at, $f3
/* CC52BC 80241AAC 44801000 */  mtc1      $zero, $f2
/* CC52C0 80241AB0 4600B021 */  cvt.d.s   $f0, $f22
/* CC52C4 80241AB4 46220002 */  mul.d     $f0, $f0, $f2
/* CC52C8 80241AB8 00000000 */  nop
/* CC52CC 80241ABC 4620020D */  trunc.w.d $f8, $f0
/* CC52D0 80241AC0 E628007C */  swc1      $f8, 0x7c($s1)
.L80241AC4:
/* CC52D4 80241AC4 8602008E */  lh        $v0, 0x8e($s0)
/* CC52D8 80241AC8 1C400017 */  bgtz      $v0, .L80241B28
/* CC52DC 80241ACC 240403E8 */   addiu    $a0, $zero, 0x3e8
.L80241AD0:
/* CC52E0 80241AD0 24020002 */  addiu     $v0, $zero, 2
/* CC52E4 80241AD4 0C00A67F */  jal       rand_int
/* CC52E8 80241AD8 AE420070 */   sw       $v0, 0x70($s2)
/* CC52EC 80241ADC 3C035555 */  lui       $v1, 0x5555
/* CC52F0 80241AE0 34635556 */  ori       $v1, $v1, 0x5556
/* CC52F4 80241AE4 00430018 */  mult      $v0, $v1
/* CC52F8 80241AE8 000227C3 */  sra       $a0, $v0, 0x1f
/* CC52FC 80241AEC 00004010 */  mfhi      $t0
/* CC5300 80241AF0 01042023 */  subu      $a0, $t0, $a0
/* CC5304 80241AF4 00041840 */  sll       $v1, $a0, 1
/* CC5308 80241AF8 00641821 */  addu      $v1, $v1, $a0
/* CC530C 80241AFC 00431023 */  subu      $v0, $v0, $v1
/* CC5310 80241B00 24430002 */  addiu     $v1, $v0, 2
/* CC5314 80241B04 AE430074 */  sw        $v1, 0x74($s2)
/* CC5318 80241B08 8EE2002C */  lw        $v0, 0x2c($s7)
/* CC531C 80241B0C 58400006 */  blezl     $v0, .L80241B28
/* CC5320 80241B10 AE400070 */   sw       $zero, 0x70($s2)
/* CC5324 80241B14 8EE20004 */  lw        $v0, 4($s7)
/* CC5328 80241B18 58400003 */  blezl     $v0, .L80241B28
/* CC532C 80241B1C AE400070 */   sw       $zero, 0x70($s2)
/* CC5330 80241B20 50600001 */  beql      $v1, $zero, .L80241B28
/* CC5334 80241B24 AE400070 */   sw       $zero, 0x70($s2)
.L80241B28:
/* CC5338 80241B28 8FBF0064 */  lw        $ra, 0x64($sp)
/* CC533C 80241B2C 8FBE0060 */  lw        $fp, 0x60($sp)
/* CC5340 80241B30 8FB7005C */  lw        $s7, 0x5c($sp)
/* CC5344 80241B34 8FB60058 */  lw        $s6, 0x58($sp)
/* CC5348 80241B38 8FB50054 */  lw        $s5, 0x54($sp)
/* CC534C 80241B3C 8FB40050 */  lw        $s4, 0x50($sp)
/* CC5350 80241B40 8FB3004C */  lw        $s3, 0x4c($sp)
/* CC5354 80241B44 8FB20048 */  lw        $s2, 0x48($sp)
/* CC5358 80241B48 8FB10044 */  lw        $s1, 0x44($sp)
/* CC535C 80241B4C 8FB00040 */  lw        $s0, 0x40($sp)
/* CC5360 80241B50 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* CC5364 80241B54 D7B80078 */  ldc1      $f24, 0x78($sp)
/* CC5368 80241B58 D7B60070 */  ldc1      $f22, 0x70($sp)
/* CC536C 80241B5C D7B40068 */  ldc1      $f20, 0x68($sp)
/* CC5370 80241B60 03E00008 */  jr        $ra
/* CC5374 80241B64 27BD0088 */   addiu    $sp, $sp, 0x88
