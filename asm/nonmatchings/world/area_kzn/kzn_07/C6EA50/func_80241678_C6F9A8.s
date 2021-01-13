.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241678_C6F9A8
/* C6F9A8 80241678 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C6F9AC 8024167C AFB20030 */  sw        $s2, 0x30($sp)
/* C6F9B0 80241680 0080902D */  daddu     $s2, $a0, $zero
/* C6F9B4 80241684 AFBF0038 */  sw        $ra, 0x38($sp)
/* C6F9B8 80241688 AFB30034 */  sw        $s3, 0x34($sp)
/* C6F9BC 8024168C AFB1002C */  sw        $s1, 0x2c($sp)
/* C6F9C0 80241690 AFB00028 */  sw        $s0, 0x28($sp)
/* C6F9C4 80241694 F7B60048 */  sdc1      $f22, 0x48($sp)
/* C6F9C8 80241698 F7B40040 */  sdc1      $f20, 0x40($sp)
/* C6F9CC 8024169C 8E510148 */  lw        $s1, 0x148($s2)
/* C6F9D0 802416A0 86240008 */  lh        $a0, 8($s1)
/* C6F9D4 802416A4 0C00EABB */  jal       get_npc_unsafe
/* C6F9D8 802416A8 00A0982D */   daddu    $s3, $a1, $zero
/* C6F9DC 802416AC 0040802D */  daddu     $s0, $v0, $zero
/* C6F9E0 802416B0 0200202D */  daddu     $a0, $s0, $zero
/* C6F9E4 802416B4 C6220088 */  lwc1      $f2, 0x88($s1)
/* C6F9E8 802416B8 468010A0 */  cvt.s.w   $f2, $f2
/* C6F9EC 802416BC 460010A1 */  cvt.d.s   $f2, $f2
/* C6F9F0 802416C0 C604001C */  lwc1      $f4, 0x1c($s0)
/* C6F9F4 802416C4 C6000014 */  lwc1      $f0, 0x14($s0)
/* C6F9F8 802416C8 8E050018 */  lw        $a1, 0x18($s0)
/* C6F9FC 802416CC 46002100 */  add.s     $f4, $f4, $f0
/* C6FA00 802416D0 8E06000C */  lw        $a2, 0xc($s0)
/* C6FA04 802416D4 C6200078 */  lwc1      $f0, 0x78($s1)
/* C6FA08 802416D8 46800020 */  cvt.s.w   $f0, $f0
/* C6FA0C 802416DC E604001C */  swc1      $f4, 0x1c($s0)
/* C6FA10 802416E0 3C014059 */  lui       $at, 0x4059
/* C6FA14 802416E4 44812800 */  mtc1      $at, $f5
/* C6FA18 802416E8 44802000 */  mtc1      $zero, $f4
/* C6FA1C 802416EC 46000021 */  cvt.d.s   $f0, $f0
/* C6FA20 802416F0 46240003 */  div.d     $f0, $f0, $f4
/* C6FA24 802416F4 46200520 */  cvt.s.d   $f20, $f0
/* C6FA28 802416F8 46241083 */  div.d     $f2, $f2, $f4
/* C6FA2C 802416FC 0C00EA95 */  jal       npc_move_heading
/* C6FA30 80241700 462015A0 */   cvt.s.d  $f22, $f2
/* C6FA34 80241704 C604001C */  lwc1      $f4, 0x1c($s0)
/* C6FA38 80241708 44801000 */  mtc1      $zero, $f2
/* C6FA3C 8024170C 44801800 */  mtc1      $zero, $f3
/* C6FA40 80241710 46002021 */  cvt.d.s   $f0, $f4
/* C6FA44 80241714 4620103E */  c.le.d    $f2, $f0
/* C6FA48 80241718 00000000 */  nop
/* C6FA4C 8024171C 45000030 */  bc1f      .L802417E0
/* C6FA50 80241720 00000000 */   nop
/* C6FA54 80241724 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6FA58 80241728 46040000 */  add.s     $f0, $f0, $f4
/* C6FA5C 8024172C E600003C */  swc1      $f0, 0x3c($s0)
/* C6FA60 80241730 8E2200CC */  lw        $v0, 0xcc($s1)
/* C6FA64 80241734 8C420024 */  lw        $v0, 0x24($v0)
/* C6FA68 80241738 AE020028 */  sw        $v0, 0x28($s0)
/* C6FA6C 8024173C A2200007 */  sb        $zero, 7($s1)
/* C6FA70 80241740 8E020000 */  lw        $v0, ($s0)
/* C6FA74 80241744 30420008 */  andi      $v0, $v0, 8
/* C6FA78 80241748 14400011 */  bnez      $v0, .L80241790
/* C6FA7C 8024174C 0000102D */   daddu    $v0, $zero, $zero
/* C6FA80 80241750 27A50018 */  addiu     $a1, $sp, 0x18
/* C6FA84 80241754 27A6001C */  addiu     $a2, $sp, 0x1c
/* C6FA88 80241758 C6000038 */  lwc1      $f0, 0x38($s0)
/* C6FA8C 8024175C C602003C */  lwc1      $f2, 0x3c($s0)
/* C6FA90 80241760 C6040040 */  lwc1      $f4, 0x40($s0)
/* C6FA94 80241764 3C01447A */  lui       $at, 0x447a
/* C6FA98 80241768 44813000 */  mtc1      $at, $f6
/* C6FA9C 8024176C 27A20024 */  addiu     $v0, $sp, 0x24
/* C6FAA0 80241770 E7A00018 */  swc1      $f0, 0x18($sp)
/* C6FAA4 80241774 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C6FAA8 80241778 E7A40020 */  swc1      $f4, 0x20($sp)
/* C6FAAC 8024177C E7A60024 */  swc1      $f6, 0x24($sp)
/* C6FAB0 80241780 AFA20010 */  sw        $v0, 0x10($sp)
/* C6FAB4 80241784 8E040080 */  lw        $a0, 0x80($s0)
/* C6FAB8 80241788 0C0372DF */  jal       func_800DCB7C
/* C6FABC 8024178C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241790:
/* C6FAC0 80241790 1040000B */  beqz      $v0, .L802417C0
/* C6FAC4 80241794 00000000 */   nop
/* C6FAC8 80241798 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C6FACC 8024179C 46140080 */  add.s     $f2, $f0, $f20
/* C6FAD0 802417A0 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6FAD4 802417A4 4600103E */  c.le.s    $f2, $f0
/* C6FAD8 802417A8 00000000 */  nop
/* C6FADC 802417AC 4500008D */  bc1f      .L802419E4
/* C6FAE0 802417B0 00000000 */   nop
/* C6FAE4 802417B4 E602003C */  swc1      $f2, 0x3c($s0)
/* C6FAE8 802417B8 08090679 */  j         .L802419E4
/* C6FAEC 802417BC AE400070 */   sw       $zero, 0x70($s2)
.L802417C0:
/* C6FAF0 802417C0 C602003C */  lwc1      $f2, 0x3c($s0)
/* C6FAF4 802417C4 C6000064 */  lwc1      $f0, 0x64($s0)
/* C6FAF8 802417C8 4602003E */  c.le.s    $f0, $f2
/* C6FAFC 802417CC 00000000 */  nop
/* C6FB00 802417D0 45030084 */  bc1tl     .L802419E4
/* C6FB04 802417D4 AE400070 */   sw       $zero, 0x70($s2)
/* C6FB08 802417D8 08090679 */  j         .L802419E4
/* C6FB0C 802417DC 00000000 */   nop
.L802417E0:
/* C6FB10 802417E0 4622003C */  c.lt.d    $f0, $f2
/* C6FB14 802417E4 00000000 */  nop
/* C6FB18 802417E8 4500007E */  bc1f      .L802419E4
/* C6FB1C 802417EC 00000000 */   nop
/* C6FB20 802417F0 9602008E */  lhu       $v0, 0x8e($s0)
/* C6FB24 802417F4 24420001 */  addiu     $v0, $v0, 1
/* C6FB28 802417F8 A602008E */  sh        $v0, 0x8e($s0)
/* C6FB2C 802417FC 00021400 */  sll       $v0, $v0, 0x10
/* C6FB30 80241800 8E630020 */  lw        $v1, 0x20($s3)
/* C6FB34 80241804 00021403 */  sra       $v0, $v0, 0x10
/* C6FB38 80241808 0043102A */  slt       $v0, $v0, $v1
/* C6FB3C 8024180C 14400026 */  bnez      $v0, .L802418A8
/* C6FB40 80241810 00000000 */   nop
/* C6FB44 80241814 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C6FB48 80241818 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C6FB4C 8024181C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C6FB50 80241820 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C6FB54 80241824 A600008E */  sh        $zero, 0x8e($s0)
/* C6FB58 80241828 8C460028 */  lw        $a2, 0x28($v0)
/* C6FB5C 8024182C 0C00A720 */  jal       atan2
/* C6FB60 80241830 8C470030 */   lw       $a3, 0x30($v0)
/* C6FB64 80241834 46000506 */  mov.s     $f20, $f0
/* C6FB68 80241838 C60C000C */  lwc1      $f12, 0xc($s0)
/* C6FB6C 8024183C 0C00A70A */  jal       get_clamped_angle_diff
/* C6FB70 80241840 4600A386 */   mov.s    $f14, $f20
/* C6FB74 80241844 46000086 */  mov.s     $f2, $f0
/* C6FB78 80241848 8E62001C */  lw        $v0, 0x1c($s3)
/* C6FB7C 8024184C 46001005 */  abs.s     $f0, $f2
/* C6FB80 80241850 44822000 */  mtc1      $v0, $f4
/* C6FB84 80241854 00000000 */  nop
/* C6FB88 80241858 46802120 */  cvt.s.w   $f4, $f4
/* C6FB8C 8024185C 4600203C */  c.lt.s    $f4, $f0
/* C6FB90 80241860 00000000 */  nop
/* C6FB94 80241864 4500000D */  bc1f      .L8024189C
/* C6FB98 80241868 00000000 */   nop
/* C6FB9C 8024186C 44800000 */  mtc1      $zero, $f0
/* C6FBA0 80241870 C614000C */  lwc1      $f20, 0xc($s0)
/* C6FBA4 80241874 4600103C */  c.lt.s    $f2, $f0
/* C6FBA8 80241878 00000000 */  nop
/* C6FBAC 8024187C 45000006 */  bc1f      .L80241898
/* C6FBB0 80241880 00021023 */   negu     $v0, $v0
/* C6FBB4 80241884 44820000 */  mtc1      $v0, $f0
/* C6FBB8 80241888 00000000 */  nop
/* C6FBBC 8024188C 46800020 */  cvt.s.w   $f0, $f0
/* C6FBC0 80241890 08090627 */  j         .L8024189C
/* C6FBC4 80241894 4600A500 */   add.s    $f20, $f20, $f0
.L80241898:
/* C6FBC8 80241898 4604A500 */  add.s     $f20, $f20, $f4
.L8024189C:
/* C6FBCC 8024189C 0C00A6C9 */  jal       clamp_angle
/* C6FBD0 802418A0 4600A306 */   mov.s    $f12, $f20
/* C6FBD4 802418A4 E600000C */  swc1      $f0, 0xc($s0)
.L802418A8:
/* C6FBD8 802418A8 8E020000 */  lw        $v0, ($s0)
/* C6FBDC 802418AC 30420008 */  andi      $v0, $v0, 8
/* C6FBE0 802418B0 1040000A */  beqz      $v0, .L802418DC
/* C6FBE4 802418B4 27A50018 */   addiu    $a1, $sp, 0x18
/* C6FBE8 802418B8 C602003C */  lwc1      $f2, 0x3c($s0)
/* C6FBEC 802418BC C600001C */  lwc1      $f0, 0x1c($s0)
/* C6FBF0 802418C0 46001080 */  add.s     $f2, $f2, $f0
/* C6FBF4 802418C4 4616103C */  c.lt.s    $f2, $f22
/* C6FBF8 802418C8 00000000 */  nop
/* C6FBFC 802418CC 45020045 */  bc1fl     .L802419E4
/* C6FC00 802418D0 E602003C */   swc1     $f2, 0x3c($s0)
/* C6FC04 802418D4 08090678 */  j         .L802419E0
/* C6FC08 802418D8 E616003C */   swc1     $f22, 0x3c($s0)
.L802418DC:
/* C6FC0C 802418DC C6000038 */  lwc1      $f0, 0x38($s0)
/* C6FC10 802418E0 27A6001C */  addiu     $a2, $sp, 0x1c
/* C6FC14 802418E4 E7A00018 */  swc1      $f0, 0x18($sp)
/* C6FC18 802418E8 860200A8 */  lh        $v0, 0xa8($s0)
/* C6FC1C 802418EC C600001C */  lwc1      $f0, 0x1c($s0)
/* C6FC20 802418F0 C604003C */  lwc1      $f4, 0x3c($s0)
/* C6FC24 802418F4 44821000 */  mtc1      $v0, $f2
/* C6FC28 802418F8 00000000 */  nop
/* C6FC2C 802418FC 468010A0 */  cvt.s.w   $f2, $f2
/* C6FC30 80241900 46000005 */  abs.s     $f0, $f0
/* C6FC34 80241904 46020000 */  add.s     $f0, $f0, $f2
/* C6FC38 80241908 C6060040 */  lwc1      $f6, 0x40($s0)
/* C6FC3C 8024190C 27A20024 */  addiu     $v0, $sp, 0x24
/* C6FC40 80241910 46022100 */  add.s     $f4, $f4, $f2
/* C6FC44 80241914 3C014024 */  lui       $at, 0x4024
/* C6FC48 80241918 44811800 */  mtc1      $at, $f3
/* C6FC4C 8024191C 44801000 */  mtc1      $zero, $f2
/* C6FC50 80241920 46000021 */  cvt.d.s   $f0, $f0
/* C6FC54 80241924 46220000 */  add.d     $f0, $f0, $f2
/* C6FC58 80241928 E7A60020 */  swc1      $f6, 0x20($sp)
/* C6FC5C 8024192C E7A4001C */  swc1      $f4, 0x1c($sp)
/* C6FC60 80241930 46200020 */  cvt.s.d   $f0, $f0
/* C6FC64 80241934 E7A00024 */  swc1      $f0, 0x24($sp)
/* C6FC68 80241938 AFA20010 */  sw        $v0, 0x10($sp)
/* C6FC6C 8024193C 8E040080 */  lw        $a0, 0x80($s0)
/* C6FC70 80241940 0C0372DF */  jal       func_800DCB7C
/* C6FC74 80241944 27A70020 */   addiu    $a3, $sp, 0x20
/* C6FC78 80241948 10400015 */  beqz      $v0, .L802419A0
/* C6FC7C 8024194C 00000000 */   nop
/* C6FC80 80241950 860200A8 */  lh        $v0, 0xa8($s0)
/* C6FC84 80241954 C604001C */  lwc1      $f4, 0x1c($s0)
/* C6FC88 80241958 44820000 */  mtc1      $v0, $f0
/* C6FC8C 8024195C 00000000 */  nop
/* C6FC90 80241960 46800020 */  cvt.s.w   $f0, $f0
/* C6FC94 80241964 46002085 */  abs.s     $f2, $f4
/* C6FC98 80241968 46020000 */  add.s     $f0, $f0, $f2
/* C6FC9C 8024196C C7A20024 */  lwc1      $f2, 0x24($sp)
/* C6FCA0 80241970 4600103E */  c.le.s    $f2, $f0
/* C6FCA4 80241974 00000000 */  nop
/* C6FCA8 80241978 45000005 */  bc1f      .L80241990
/* C6FCAC 8024197C 00000000 */   nop
/* C6FCB0 80241980 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C6FCB4 80241984 AE00001C */  sw        $zero, 0x1c($s0)
/* C6FCB8 80241988 08090679 */  j         .L802419E4
/* C6FCBC 8024198C E600003C */   swc1     $f0, 0x3c($s0)
.L80241990:
/* C6FCC0 80241990 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6FCC4 80241994 46040000 */  add.s     $f0, $f0, $f4
/* C6FCC8 80241998 08090679 */  j         .L802419E4
/* C6FCCC 8024199C E600003C */   swc1     $f0, 0x3c($s0)
.L802419A0:
/* C6FCD0 802419A0 C606003C */  lwc1      $f6, 0x3c($s0)
/* C6FCD4 802419A4 860200A8 */  lh        $v0, 0xa8($s0)
/* C6FCD8 802419A8 46163081 */  sub.s     $f2, $f6, $f22
/* C6FCDC 802419AC 44820000 */  mtc1      $v0, $f0
/* C6FCE0 802419B0 00000000 */  nop
/* C6FCE4 802419B4 46800020 */  cvt.s.w   $f0, $f0
/* C6FCE8 802419B8 46001080 */  add.s     $f2, $f2, $f0
/* C6FCEC 802419BC C604001C */  lwc1      $f4, 0x1c($s0)
/* C6FCF0 802419C0 46002005 */  abs.s     $f0, $f4
/* C6FCF4 802419C4 4602003C */  c.lt.s    $f0, $f2
/* C6FCF8 802419C8 00000000 */  nop
/* C6FCFC 802419CC 45020005 */  bc1fl     .L802419E4
/* C6FD00 802419D0 AE00001C */   sw       $zero, 0x1c($s0)
/* C6FD04 802419D4 46043000 */  add.s     $f0, $f6, $f4
/* C6FD08 802419D8 08090679 */  j         .L802419E4
/* C6FD0C 802419DC E600003C */   swc1     $f0, 0x3c($s0)
.L802419E0:
/* C6FD10 802419E0 AE00001C */  sw        $zero, 0x1c($s0)
.L802419E4:
/* C6FD14 802419E4 8FBF0038 */  lw        $ra, 0x38($sp)
/* C6FD18 802419E8 8FB30034 */  lw        $s3, 0x34($sp)
/* C6FD1C 802419EC 8FB20030 */  lw        $s2, 0x30($sp)
/* C6FD20 802419F0 8FB1002C */  lw        $s1, 0x2c($sp)
/* C6FD24 802419F4 8FB00028 */  lw        $s0, 0x28($sp)
/* C6FD28 802419F8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* C6FD2C 802419FC D7B40040 */  ldc1      $f20, 0x40($sp)
/* C6FD30 80241A00 03E00008 */  jr        $ra
/* C6FD34 80241A04 27BD0050 */   addiu    $sp, $sp, 0x50
