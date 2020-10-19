.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024162C
/* 9F606C 8024162C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9F6070 80241630 AFB20030 */  sw        $s2, 0x30($sp)
/* 9F6074 80241634 0080902D */  daddu     $s2, $a0, $zero
/* 9F6078 80241638 AFBF0038 */  sw        $ra, 0x38($sp)
/* 9F607C 8024163C AFB30034 */  sw        $s3, 0x34($sp)
/* 9F6080 80241640 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9F6084 80241644 AFB00028 */  sw        $s0, 0x28($sp)
/* 9F6088 80241648 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 9F608C 8024164C F7B40040 */  sdc1      $f20, 0x40($sp)
/* 9F6090 80241650 8E510148 */  lw        $s1, 0x148($s2)
/* 9F6094 80241654 86240008 */  lh        $a0, 8($s1)
/* 9F6098 80241658 0C00EABB */  jal       get_npc_unsafe
/* 9F609C 8024165C 00A0982D */   daddu    $s3, $a1, $zero
/* 9F60A0 80241660 0040802D */  daddu     $s0, $v0, $zero
/* 9F60A4 80241664 0200202D */  daddu     $a0, $s0, $zero
/* 9F60A8 80241668 C6220088 */  lwc1      $f2, 0x88($s1)
/* 9F60AC 8024166C 468010A0 */  cvt.s.w   $f2, $f2
/* 9F60B0 80241670 460010A1 */  cvt.d.s   $f2, $f2
/* 9F60B4 80241674 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9F60B8 80241678 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9F60BC 8024167C 8E050018 */  lw        $a1, 0x18($s0)
/* 9F60C0 80241680 46002100 */  add.s     $f4, $f4, $f0
/* 9F60C4 80241684 8E06000C */  lw        $a2, 0xc($s0)
/* 9F60C8 80241688 C6200078 */  lwc1      $f0, 0x78($s1)
/* 9F60CC 8024168C 46800020 */  cvt.s.w   $f0, $f0
/* 9F60D0 80241690 E604001C */  swc1      $f4, 0x1c($s0)
/* 9F60D4 80241694 3C014059 */  lui       $at, 0x4059
/* 9F60D8 80241698 44812800 */  mtc1      $at, $f5
/* 9F60DC 8024169C 44802000 */  mtc1      $zero, $f4
/* 9F60E0 802416A0 46000021 */  cvt.d.s   $f0, $f0
/* 9F60E4 802416A4 46240003 */  div.d     $f0, $f0, $f4
/* 9F60E8 802416A8 46200520 */  cvt.s.d   $f20, $f0
/* 9F60EC 802416AC 46241083 */  div.d     $f2, $f2, $f4
/* 9F60F0 802416B0 0C00EA95 */  jal       npc_move_heading
/* 9F60F4 802416B4 462015A0 */   cvt.s.d  $f22, $f2
/* 9F60F8 802416B8 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9F60FC 802416BC 44801000 */  mtc1      $zero, $f2
/* 9F6100 802416C0 44801800 */  mtc1      $zero, $f3
/* 9F6104 802416C4 46002021 */  cvt.d.s   $f0, $f4
/* 9F6108 802416C8 4620103E */  c.le.d    $f2, $f0
/* 9F610C 802416CC 00000000 */  nop       
/* 9F6110 802416D0 45000030 */  bc1f      .L80241794
/* 9F6114 802416D4 00000000 */   nop      
/* 9F6118 802416D8 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9F611C 802416DC 46040000 */  add.s     $f0, $f0, $f4
/* 9F6120 802416E0 E600003C */  swc1      $f0, 0x3c($s0)
/* 9F6124 802416E4 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9F6128 802416E8 8C420024 */  lw        $v0, 0x24($v0)
/* 9F612C 802416EC AE020028 */  sw        $v0, 0x28($s0)
/* 9F6130 802416F0 A2200007 */  sb        $zero, 7($s1)
/* 9F6134 802416F4 8E020000 */  lw        $v0, ($s0)
/* 9F6138 802416F8 30420008 */  andi      $v0, $v0, 8
/* 9F613C 802416FC 14400011 */  bnez      $v0, .L80241744
/* 9F6140 80241700 0000102D */   daddu    $v0, $zero, $zero
/* 9F6144 80241704 27A50018 */  addiu     $a1, $sp, 0x18
/* 9F6148 80241708 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9F614C 8024170C C6000038 */  lwc1      $f0, 0x38($s0)
/* 9F6150 80241710 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9F6154 80241714 C6040040 */  lwc1      $f4, 0x40($s0)
/* 9F6158 80241718 3C01447A */  lui       $at, 0x447a
/* 9F615C 8024171C 44813000 */  mtc1      $at, $f6
/* 9F6160 80241720 27A20024 */  addiu     $v0, $sp, 0x24
/* 9F6164 80241724 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9F6168 80241728 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9F616C 8024172C E7A40020 */  swc1      $f4, 0x20($sp)
/* 9F6170 80241730 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9F6174 80241734 AFA20010 */  sw        $v0, 0x10($sp)
/* 9F6178 80241738 8E040080 */  lw        $a0, 0x80($s0)
/* 9F617C 8024173C 0C0372DF */  jal       func_800DCB7C
/* 9F6180 80241740 27A70020 */   addiu    $a3, $sp, 0x20
.L80241744:
/* 9F6184 80241744 1040000B */  beqz      $v0, .L80241774
/* 9F6188 80241748 00000000 */   nop      
/* 9F618C 8024174C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9F6190 80241750 46140080 */  add.s     $f2, $f0, $f20
/* 9F6194 80241754 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9F6198 80241758 4600103E */  c.le.s    $f2, $f0
/* 9F619C 8024175C 00000000 */  nop       
/* 9F61A0 80241760 4500008D */  bc1f      .L80241998
/* 9F61A4 80241764 00000000 */   nop      
/* 9F61A8 80241768 E602003C */  swc1      $f2, 0x3c($s0)
/* 9F61AC 8024176C 08090666 */  j         .L80241998
/* 9F61B0 80241770 AE400070 */   sw       $zero, 0x70($s2)
.L80241774:
/* 9F61B4 80241774 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9F61B8 80241778 C6000064 */  lwc1      $f0, 0x64($s0)
/* 9F61BC 8024177C 4602003E */  c.le.s    $f0, $f2
/* 9F61C0 80241780 00000000 */  nop       
/* 9F61C4 80241784 45030084 */  bc1tl     .L80241998
/* 9F61C8 80241788 AE400070 */   sw       $zero, 0x70($s2)
/* 9F61CC 8024178C 08090666 */  j         .L80241998
/* 9F61D0 80241790 00000000 */   nop      
.L80241794:
/* 9F61D4 80241794 4622003C */  c.lt.d    $f0, $f2
/* 9F61D8 80241798 00000000 */  nop       
/* 9F61DC 8024179C 4500007E */  bc1f      .L80241998
/* 9F61E0 802417A0 00000000 */   nop      
/* 9F61E4 802417A4 9602008E */  lhu       $v0, 0x8e($s0)
/* 9F61E8 802417A8 24420001 */  addiu     $v0, $v0, 1
/* 9F61EC 802417AC A602008E */  sh        $v0, 0x8e($s0)
/* 9F61F0 802417B0 00021400 */  sll       $v0, $v0, 0x10
/* 9F61F4 802417B4 8E630020 */  lw        $v1, 0x20($s3)
/* 9F61F8 802417B8 00021403 */  sra       $v0, $v0, 0x10
/* 9F61FC 802417BC 0043102A */  slt       $v0, $v0, $v1
/* 9F6200 802417C0 14400026 */  bnez      $v0, .L8024185C
/* 9F6204 802417C4 00000000 */   nop      
/* 9F6208 802417C8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9F620C 802417CC C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9F6210 802417D0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9F6214 802417D4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9F6218 802417D8 A600008E */  sh        $zero, 0x8e($s0)
/* 9F621C 802417DC 8C460028 */  lw        $a2, 0x28($v0)
/* 9F6220 802417E0 0C00A720 */  jal       atan2
/* 9F6224 802417E4 8C470030 */   lw       $a3, 0x30($v0)
/* 9F6228 802417E8 46000506 */  mov.s     $f20, $f0
/* 9F622C 802417EC C60C000C */  lwc1      $f12, 0xc($s0)
/* 9F6230 802417F0 0C00A70A */  jal       get_clamped_angle_diff
/* 9F6234 802417F4 4600A386 */   mov.s    $f14, $f20
/* 9F6238 802417F8 46000086 */  mov.s     $f2, $f0
/* 9F623C 802417FC 8E62001C */  lw        $v0, 0x1c($s3)
/* 9F6240 80241800 46001005 */  abs.s     $f0, $f2
/* 9F6244 80241804 44822000 */  mtc1      $v0, $f4
/* 9F6248 80241808 00000000 */  nop       
/* 9F624C 8024180C 46802120 */  cvt.s.w   $f4, $f4
/* 9F6250 80241810 4600203C */  c.lt.s    $f4, $f0
/* 9F6254 80241814 00000000 */  nop       
/* 9F6258 80241818 4500000D */  bc1f      .L80241850
/* 9F625C 8024181C 00000000 */   nop      
/* 9F6260 80241820 44800000 */  mtc1      $zero, $f0
/* 9F6264 80241824 C614000C */  lwc1      $f20, 0xc($s0)
/* 9F6268 80241828 4600103C */  c.lt.s    $f2, $f0
/* 9F626C 8024182C 00000000 */  nop       
/* 9F6270 80241830 45000006 */  bc1f      .L8024184C
/* 9F6274 80241834 00021023 */   negu     $v0, $v0
/* 9F6278 80241838 44820000 */  mtc1      $v0, $f0
/* 9F627C 8024183C 00000000 */  nop       
/* 9F6280 80241840 46800020 */  cvt.s.w   $f0, $f0
/* 9F6284 80241844 08090614 */  j         .L80241850
/* 9F6288 80241848 4600A500 */   add.s    $f20, $f20, $f0
.L8024184C:
/* 9F628C 8024184C 4604A500 */  add.s     $f20, $f20, $f4
.L80241850:
/* 9F6290 80241850 0C00A6C9 */  jal       clamp_angle
/* 9F6294 80241854 4600A306 */   mov.s    $f12, $f20
/* 9F6298 80241858 E600000C */  swc1      $f0, 0xc($s0)
.L8024185C:
/* 9F629C 8024185C 8E020000 */  lw        $v0, ($s0)
/* 9F62A0 80241860 30420008 */  andi      $v0, $v0, 8
/* 9F62A4 80241864 1040000A */  beqz      $v0, .L80241890
/* 9F62A8 80241868 27A50018 */   addiu    $a1, $sp, 0x18
/* 9F62AC 8024186C C602003C */  lwc1      $f2, 0x3c($s0)
/* 9F62B0 80241870 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9F62B4 80241874 46001080 */  add.s     $f2, $f2, $f0
/* 9F62B8 80241878 4616103C */  c.lt.s    $f2, $f22
/* 9F62BC 8024187C 00000000 */  nop       
/* 9F62C0 80241880 45020045 */  bc1fl     .L80241998
/* 9F62C4 80241884 E602003C */   swc1     $f2, 0x3c($s0)
/* 9F62C8 80241888 08090665 */  j         .L80241994
/* 9F62CC 8024188C E616003C */   swc1     $f22, 0x3c($s0)
.L80241890:
/* 9F62D0 80241890 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9F62D4 80241894 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9F62D8 80241898 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9F62DC 8024189C 860200A8 */  lh        $v0, 0xa8($s0)
/* 9F62E0 802418A0 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9F62E4 802418A4 C604003C */  lwc1      $f4, 0x3c($s0)
/* 9F62E8 802418A8 44821000 */  mtc1      $v0, $f2
/* 9F62EC 802418AC 00000000 */  nop       
/* 9F62F0 802418B0 468010A0 */  cvt.s.w   $f2, $f2
/* 9F62F4 802418B4 46000005 */  abs.s     $f0, $f0
/* 9F62F8 802418B8 46020000 */  add.s     $f0, $f0, $f2
/* 9F62FC 802418BC C6060040 */  lwc1      $f6, 0x40($s0)
/* 9F6300 802418C0 27A20024 */  addiu     $v0, $sp, 0x24
/* 9F6304 802418C4 46022100 */  add.s     $f4, $f4, $f2
/* 9F6308 802418C8 3C014024 */  lui       $at, 0x4024
/* 9F630C 802418CC 44811800 */  mtc1      $at, $f3
/* 9F6310 802418D0 44801000 */  mtc1      $zero, $f2
/* 9F6314 802418D4 46000021 */  cvt.d.s   $f0, $f0
/* 9F6318 802418D8 46220000 */  add.d     $f0, $f0, $f2
/* 9F631C 802418DC E7A60020 */  swc1      $f6, 0x20($sp)
/* 9F6320 802418E0 E7A4001C */  swc1      $f4, 0x1c($sp)
/* 9F6324 802418E4 46200020 */  cvt.s.d   $f0, $f0
/* 9F6328 802418E8 E7A00024 */  swc1      $f0, 0x24($sp)
/* 9F632C 802418EC AFA20010 */  sw        $v0, 0x10($sp)
/* 9F6330 802418F0 8E040080 */  lw        $a0, 0x80($s0)
/* 9F6334 802418F4 0C0372DF */  jal       func_800DCB7C
/* 9F6338 802418F8 27A70020 */   addiu    $a3, $sp, 0x20
/* 9F633C 802418FC 10400015 */  beqz      $v0, .L80241954
/* 9F6340 80241900 00000000 */   nop      
/* 9F6344 80241904 860200A8 */  lh        $v0, 0xa8($s0)
/* 9F6348 80241908 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9F634C 8024190C 44820000 */  mtc1      $v0, $f0
/* 9F6350 80241910 00000000 */  nop       
/* 9F6354 80241914 46800020 */  cvt.s.w   $f0, $f0
/* 9F6358 80241918 46002085 */  abs.s     $f2, $f4
/* 9F635C 8024191C 46020000 */  add.s     $f0, $f0, $f2
/* 9F6360 80241920 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 9F6364 80241924 4600103E */  c.le.s    $f2, $f0
/* 9F6368 80241928 00000000 */  nop       
/* 9F636C 8024192C 45000005 */  bc1f      .L80241944
/* 9F6370 80241930 00000000 */   nop      
/* 9F6374 80241934 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9F6378 80241938 AE00001C */  sw        $zero, 0x1c($s0)
/* 9F637C 8024193C 08090666 */  j         .L80241998
/* 9F6380 80241940 E600003C */   swc1     $f0, 0x3c($s0)
.L80241944:
/* 9F6384 80241944 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9F6388 80241948 46040000 */  add.s     $f0, $f0, $f4
/* 9F638C 8024194C 08090666 */  j         .L80241998
/* 9F6390 80241950 E600003C */   swc1     $f0, 0x3c($s0)
.L80241954:
/* 9F6394 80241954 C606003C */  lwc1      $f6, 0x3c($s0)
/* 9F6398 80241958 860200A8 */  lh        $v0, 0xa8($s0)
/* 9F639C 8024195C 46163081 */  sub.s     $f2, $f6, $f22
/* 9F63A0 80241960 44820000 */  mtc1      $v0, $f0
/* 9F63A4 80241964 00000000 */  nop       
/* 9F63A8 80241968 46800020 */  cvt.s.w   $f0, $f0
/* 9F63AC 8024196C 46001080 */  add.s     $f2, $f2, $f0
/* 9F63B0 80241970 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9F63B4 80241974 46002005 */  abs.s     $f0, $f4
/* 9F63B8 80241978 4602003C */  c.lt.s    $f0, $f2
/* 9F63BC 8024197C 00000000 */  nop       
/* 9F63C0 80241980 45020005 */  bc1fl     .L80241998
/* 9F63C4 80241984 AE00001C */   sw       $zero, 0x1c($s0)
/* 9F63C8 80241988 46043000 */  add.s     $f0, $f6, $f4
/* 9F63CC 8024198C 08090666 */  j         .L80241998
/* 9F63D0 80241990 E600003C */   swc1     $f0, 0x3c($s0)
.L80241994:
/* 9F63D4 80241994 AE00001C */  sw        $zero, 0x1c($s0)
.L80241998:
/* 9F63D8 80241998 8FBF0038 */  lw        $ra, 0x38($sp)
/* 9F63DC 8024199C 8FB30034 */  lw        $s3, 0x34($sp)
/* 9F63E0 802419A0 8FB20030 */  lw        $s2, 0x30($sp)
/* 9F63E4 802419A4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9F63E8 802419A8 8FB00028 */  lw        $s0, 0x28($sp)
/* 9F63EC 802419AC D7B60048 */  ldc1      $f22, 0x48($sp)
/* 9F63F0 802419B0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 9F63F4 802419B4 03E00008 */  jr        $ra
/* 9F63F8 802419B8 27BD0050 */   addiu    $sp, $sp, 0x50
