.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A8_BEE598
/* BEE598 802417A8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BEE59C 802417AC AFB20030 */  sw        $s2, 0x30($sp)
/* BEE5A0 802417B0 0080902D */  daddu     $s2, $a0, $zero
/* BEE5A4 802417B4 AFBF0038 */  sw        $ra, 0x38($sp)
/* BEE5A8 802417B8 AFB30034 */  sw        $s3, 0x34($sp)
/* BEE5AC 802417BC AFB1002C */  sw        $s1, 0x2c($sp)
/* BEE5B0 802417C0 AFB00028 */  sw        $s0, 0x28($sp)
/* BEE5B4 802417C4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* BEE5B8 802417C8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* BEE5BC 802417CC 8E510148 */  lw        $s1, 0x148($s2)
/* BEE5C0 802417D0 86240008 */  lh        $a0, 8($s1)
/* BEE5C4 802417D4 0C00EABB */  jal       get_npc_unsafe
/* BEE5C8 802417D8 00A0982D */   daddu    $s3, $a1, $zero
/* BEE5CC 802417DC 0040802D */  daddu     $s0, $v0, $zero
/* BEE5D0 802417E0 0200202D */  daddu     $a0, $s0, $zero
/* BEE5D4 802417E4 C6220088 */  lwc1      $f2, 0x88($s1)
/* BEE5D8 802417E8 468010A0 */  cvt.s.w   $f2, $f2
/* BEE5DC 802417EC 460010A1 */  cvt.d.s   $f2, $f2
/* BEE5E0 802417F0 C604001C */  lwc1      $f4, 0x1c($s0)
/* BEE5E4 802417F4 C6000014 */  lwc1      $f0, 0x14($s0)
/* BEE5E8 802417F8 8E050018 */  lw        $a1, 0x18($s0)
/* BEE5EC 802417FC 46002100 */  add.s     $f4, $f4, $f0
/* BEE5F0 80241800 8E06000C */  lw        $a2, 0xc($s0)
/* BEE5F4 80241804 C6200078 */  lwc1      $f0, 0x78($s1)
/* BEE5F8 80241808 46800020 */  cvt.s.w   $f0, $f0
/* BEE5FC 8024180C E604001C */  swc1      $f4, 0x1c($s0)
/* BEE600 80241810 3C014059 */  lui       $at, 0x4059
/* BEE604 80241814 44812800 */  mtc1      $at, $f5
/* BEE608 80241818 44802000 */  mtc1      $zero, $f4
/* BEE60C 8024181C 46000021 */  cvt.d.s   $f0, $f0
/* BEE610 80241820 46240003 */  div.d     $f0, $f0, $f4
/* BEE614 80241824 46200520 */  cvt.s.d   $f20, $f0
/* BEE618 80241828 46241083 */  div.d     $f2, $f2, $f4
/* BEE61C 8024182C 0C00EA95 */  jal       npc_move_heading
/* BEE620 80241830 462015A0 */   cvt.s.d  $f22, $f2
/* BEE624 80241834 C604001C */  lwc1      $f4, 0x1c($s0)
/* BEE628 80241838 44801000 */  mtc1      $zero, $f2
/* BEE62C 8024183C 44801800 */  mtc1      $zero, $f3
/* BEE630 80241840 46002021 */  cvt.d.s   $f0, $f4
/* BEE634 80241844 4620103E */  c.le.d    $f2, $f0
/* BEE638 80241848 00000000 */  nop       
/* BEE63C 8024184C 45000030 */  bc1f      .L80241910
/* BEE640 80241850 00000000 */   nop      
/* BEE644 80241854 C600003C */  lwc1      $f0, 0x3c($s0)
/* BEE648 80241858 46040000 */  add.s     $f0, $f0, $f4
/* BEE64C 8024185C E600003C */  swc1      $f0, 0x3c($s0)
/* BEE650 80241860 8E2200CC */  lw        $v0, 0xcc($s1)
/* BEE654 80241864 8C420024 */  lw        $v0, 0x24($v0)
/* BEE658 80241868 AE020028 */  sw        $v0, 0x28($s0)
/* BEE65C 8024186C A2200007 */  sb        $zero, 7($s1)
/* BEE660 80241870 8E020000 */  lw        $v0, ($s0)
/* BEE664 80241874 30420008 */  andi      $v0, $v0, 8
/* BEE668 80241878 14400011 */  bnez      $v0, .L802418C0
/* BEE66C 8024187C 0000102D */   daddu    $v0, $zero, $zero
/* BEE670 80241880 27A50018 */  addiu     $a1, $sp, 0x18
/* BEE674 80241884 27A6001C */  addiu     $a2, $sp, 0x1c
/* BEE678 80241888 C6000038 */  lwc1      $f0, 0x38($s0)
/* BEE67C 8024188C C602003C */  lwc1      $f2, 0x3c($s0)
/* BEE680 80241890 C6040040 */  lwc1      $f4, 0x40($s0)
/* BEE684 80241894 3C01447A */  lui       $at, 0x447a
/* BEE688 80241898 44813000 */  mtc1      $at, $f6
/* BEE68C 8024189C 27A20024 */  addiu     $v0, $sp, 0x24
/* BEE690 802418A0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BEE694 802418A4 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BEE698 802418A8 E7A40020 */  swc1      $f4, 0x20($sp)
/* BEE69C 802418AC E7A60024 */  swc1      $f6, 0x24($sp)
/* BEE6A0 802418B0 AFA20010 */  sw        $v0, 0x10($sp)
/* BEE6A4 802418B4 8E040080 */  lw        $a0, 0x80($s0)
/* BEE6A8 802418B8 0C0372DF */  jal       func_800DCB7C
/* BEE6AC 802418BC 27A70020 */   addiu    $a3, $sp, 0x20
.L802418C0:
/* BEE6B0 802418C0 1040000B */  beqz      $v0, .L802418F0
/* BEE6B4 802418C4 00000000 */   nop      
/* BEE6B8 802418C8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BEE6BC 802418CC 46140080 */  add.s     $f2, $f0, $f20
/* BEE6C0 802418D0 C600003C */  lwc1      $f0, 0x3c($s0)
/* BEE6C4 802418D4 4600103E */  c.le.s    $f2, $f0
/* BEE6C8 802418D8 00000000 */  nop       
/* BEE6CC 802418DC 4500008D */  bc1f      .L80241B14
/* BEE6D0 802418E0 00000000 */   nop      
/* BEE6D4 802418E4 E602003C */  swc1      $f2, 0x3c($s0)
/* BEE6D8 802418E8 080906C5 */  j         .L80241B14
/* BEE6DC 802418EC AE400070 */   sw       $zero, 0x70($s2)
.L802418F0:
/* BEE6E0 802418F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEE6E4 802418F4 C6000064 */  lwc1      $f0, 0x64($s0)
/* BEE6E8 802418F8 4602003E */  c.le.s    $f0, $f2
/* BEE6EC 802418FC 00000000 */  nop       
/* BEE6F0 80241900 45030084 */  bc1tl     .L80241B14
/* BEE6F4 80241904 AE400070 */   sw       $zero, 0x70($s2)
/* BEE6F8 80241908 080906C5 */  j         .L80241B14
/* BEE6FC 8024190C 00000000 */   nop      
.L80241910:
/* BEE700 80241910 4622003C */  c.lt.d    $f0, $f2
/* BEE704 80241914 00000000 */  nop       
/* BEE708 80241918 4500007E */  bc1f      .L80241B14
/* BEE70C 8024191C 00000000 */   nop      
/* BEE710 80241920 9602008E */  lhu       $v0, 0x8e($s0)
/* BEE714 80241924 24420001 */  addiu     $v0, $v0, 1
/* BEE718 80241928 A602008E */  sh        $v0, 0x8e($s0)
/* BEE71C 8024192C 00021400 */  sll       $v0, $v0, 0x10
/* BEE720 80241930 8E630020 */  lw        $v1, 0x20($s3)
/* BEE724 80241934 00021403 */  sra       $v0, $v0, 0x10
/* BEE728 80241938 0043102A */  slt       $v0, $v0, $v1
/* BEE72C 8024193C 14400026 */  bnez      $v0, .L802419D8
/* BEE730 80241940 00000000 */   nop      
/* BEE734 80241944 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BEE738 80241948 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BEE73C 8024194C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BEE740 80241950 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BEE744 80241954 A600008E */  sh        $zero, 0x8e($s0)
/* BEE748 80241958 8C460028 */  lw        $a2, 0x28($v0)
/* BEE74C 8024195C 0C00A720 */  jal       atan2
/* BEE750 80241960 8C470030 */   lw       $a3, 0x30($v0)
/* BEE754 80241964 46000506 */  mov.s     $f20, $f0
/* BEE758 80241968 C60C000C */  lwc1      $f12, 0xc($s0)
/* BEE75C 8024196C 0C00A70A */  jal       get_clamped_angle_diff
/* BEE760 80241970 4600A386 */   mov.s    $f14, $f20
/* BEE764 80241974 46000086 */  mov.s     $f2, $f0
/* BEE768 80241978 8E62001C */  lw        $v0, 0x1c($s3)
/* BEE76C 8024197C 46001005 */  abs.s     $f0, $f2
/* BEE770 80241980 44822000 */  mtc1      $v0, $f4
/* BEE774 80241984 00000000 */  nop       
/* BEE778 80241988 46802120 */  cvt.s.w   $f4, $f4
/* BEE77C 8024198C 4600203C */  c.lt.s    $f4, $f0
/* BEE780 80241990 00000000 */  nop       
/* BEE784 80241994 4500000D */  bc1f      .L802419CC
/* BEE788 80241998 00000000 */   nop      
/* BEE78C 8024199C 44800000 */  mtc1      $zero, $f0
/* BEE790 802419A0 C614000C */  lwc1      $f20, 0xc($s0)
/* BEE794 802419A4 4600103C */  c.lt.s    $f2, $f0
/* BEE798 802419A8 00000000 */  nop       
/* BEE79C 802419AC 45000006 */  bc1f      .L802419C8
/* BEE7A0 802419B0 00021023 */   negu     $v0, $v0
/* BEE7A4 802419B4 44820000 */  mtc1      $v0, $f0
/* BEE7A8 802419B8 00000000 */  nop       
/* BEE7AC 802419BC 46800020 */  cvt.s.w   $f0, $f0
/* BEE7B0 802419C0 08090673 */  j         .L802419CC
/* BEE7B4 802419C4 4600A500 */   add.s    $f20, $f20, $f0
.L802419C8:
/* BEE7B8 802419C8 4604A500 */  add.s     $f20, $f20, $f4
.L802419CC:
/* BEE7BC 802419CC 0C00A6C9 */  jal       clamp_angle
/* BEE7C0 802419D0 4600A306 */   mov.s    $f12, $f20
/* BEE7C4 802419D4 E600000C */  swc1      $f0, 0xc($s0)
.L802419D8:
/* BEE7C8 802419D8 8E020000 */  lw        $v0, ($s0)
/* BEE7CC 802419DC 30420008 */  andi      $v0, $v0, 8
/* BEE7D0 802419E0 1040000A */  beqz      $v0, .L80241A0C
/* BEE7D4 802419E4 27A50018 */   addiu    $a1, $sp, 0x18
/* BEE7D8 802419E8 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEE7DC 802419EC C600001C */  lwc1      $f0, 0x1c($s0)
/* BEE7E0 802419F0 46001080 */  add.s     $f2, $f2, $f0
/* BEE7E4 802419F4 4616103C */  c.lt.s    $f2, $f22
/* BEE7E8 802419F8 00000000 */  nop       
/* BEE7EC 802419FC 45020045 */  bc1fl     .L80241B14
/* BEE7F0 80241A00 E602003C */   swc1     $f2, 0x3c($s0)
/* BEE7F4 80241A04 080906C4 */  j         .L80241B10
/* BEE7F8 80241A08 E616003C */   swc1     $f22, 0x3c($s0)
.L80241A0C:
/* BEE7FC 80241A0C C6000038 */  lwc1      $f0, 0x38($s0)
/* BEE800 80241A10 27A6001C */  addiu     $a2, $sp, 0x1c
/* BEE804 80241A14 E7A00018 */  swc1      $f0, 0x18($sp)
/* BEE808 80241A18 860200A8 */  lh        $v0, 0xa8($s0)
/* BEE80C 80241A1C C600001C */  lwc1      $f0, 0x1c($s0)
/* BEE810 80241A20 C604003C */  lwc1      $f4, 0x3c($s0)
/* BEE814 80241A24 44821000 */  mtc1      $v0, $f2
/* BEE818 80241A28 00000000 */  nop       
/* BEE81C 80241A2C 468010A0 */  cvt.s.w   $f2, $f2
/* BEE820 80241A30 46000005 */  abs.s     $f0, $f0
/* BEE824 80241A34 46020000 */  add.s     $f0, $f0, $f2
/* BEE828 80241A38 C6060040 */  lwc1      $f6, 0x40($s0)
/* BEE82C 80241A3C 27A20024 */  addiu     $v0, $sp, 0x24
/* BEE830 80241A40 46022100 */  add.s     $f4, $f4, $f2
/* BEE834 80241A44 3C014024 */  lui       $at, 0x4024
/* BEE838 80241A48 44811800 */  mtc1      $at, $f3
/* BEE83C 80241A4C 44801000 */  mtc1      $zero, $f2
/* BEE840 80241A50 46000021 */  cvt.d.s   $f0, $f0
/* BEE844 80241A54 46220000 */  add.d     $f0, $f0, $f2
/* BEE848 80241A58 E7A60020 */  swc1      $f6, 0x20($sp)
/* BEE84C 80241A5C E7A4001C */  swc1      $f4, 0x1c($sp)
/* BEE850 80241A60 46200020 */  cvt.s.d   $f0, $f0
/* BEE854 80241A64 E7A00024 */  swc1      $f0, 0x24($sp)
/* BEE858 80241A68 AFA20010 */  sw        $v0, 0x10($sp)
/* BEE85C 80241A6C 8E040080 */  lw        $a0, 0x80($s0)
/* BEE860 80241A70 0C0372DF */  jal       func_800DCB7C
/* BEE864 80241A74 27A70020 */   addiu    $a3, $sp, 0x20
/* BEE868 80241A78 10400015 */  beqz      $v0, .L80241AD0
/* BEE86C 80241A7C 00000000 */   nop      
/* BEE870 80241A80 860200A8 */  lh        $v0, 0xa8($s0)
/* BEE874 80241A84 C604001C */  lwc1      $f4, 0x1c($s0)
/* BEE878 80241A88 44820000 */  mtc1      $v0, $f0
/* BEE87C 80241A8C 00000000 */  nop       
/* BEE880 80241A90 46800020 */  cvt.s.w   $f0, $f0
/* BEE884 80241A94 46002085 */  abs.s     $f2, $f4
/* BEE888 80241A98 46020000 */  add.s     $f0, $f0, $f2
/* BEE88C 80241A9C C7A20024 */  lwc1      $f2, 0x24($sp)
/* BEE890 80241AA0 4600103E */  c.le.s    $f2, $f0
/* BEE894 80241AA4 00000000 */  nop       
/* BEE898 80241AA8 45000005 */  bc1f      .L80241AC0
/* BEE89C 80241AAC 00000000 */   nop      
/* BEE8A0 80241AB0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BEE8A4 80241AB4 AE00001C */  sw        $zero, 0x1c($s0)
/* BEE8A8 80241AB8 080906C5 */  j         .L80241B14
/* BEE8AC 80241ABC E600003C */   swc1     $f0, 0x3c($s0)
.L80241AC0:
/* BEE8B0 80241AC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* BEE8B4 80241AC4 46040000 */  add.s     $f0, $f0, $f4
/* BEE8B8 80241AC8 080906C5 */  j         .L80241B14
/* BEE8BC 80241ACC E600003C */   swc1     $f0, 0x3c($s0)
.L80241AD0:
/* BEE8C0 80241AD0 C606003C */  lwc1      $f6, 0x3c($s0)
/* BEE8C4 80241AD4 860200A8 */  lh        $v0, 0xa8($s0)
/* BEE8C8 80241AD8 46163081 */  sub.s     $f2, $f6, $f22
/* BEE8CC 80241ADC 44820000 */  mtc1      $v0, $f0
/* BEE8D0 80241AE0 00000000 */  nop       
/* BEE8D4 80241AE4 46800020 */  cvt.s.w   $f0, $f0
/* BEE8D8 80241AE8 46001080 */  add.s     $f2, $f2, $f0
/* BEE8DC 80241AEC C604001C */  lwc1      $f4, 0x1c($s0)
/* BEE8E0 80241AF0 46002005 */  abs.s     $f0, $f4
/* BEE8E4 80241AF4 4602003C */  c.lt.s    $f0, $f2
/* BEE8E8 80241AF8 00000000 */  nop       
/* BEE8EC 80241AFC 45020005 */  bc1fl     .L80241B14
/* BEE8F0 80241B00 AE00001C */   sw       $zero, 0x1c($s0)
/* BEE8F4 80241B04 46043000 */  add.s     $f0, $f6, $f4
/* BEE8F8 80241B08 080906C5 */  j         .L80241B14
/* BEE8FC 80241B0C E600003C */   swc1     $f0, 0x3c($s0)
.L80241B10:
/* BEE900 80241B10 AE00001C */  sw        $zero, 0x1c($s0)
.L80241B14:
/* BEE904 80241B14 8FBF0038 */  lw        $ra, 0x38($sp)
/* BEE908 80241B18 8FB30034 */  lw        $s3, 0x34($sp)
/* BEE90C 80241B1C 8FB20030 */  lw        $s2, 0x30($sp)
/* BEE910 80241B20 8FB1002C */  lw        $s1, 0x2c($sp)
/* BEE914 80241B24 8FB00028 */  lw        $s0, 0x28($sp)
/* BEE918 80241B28 D7B60048 */  ldc1      $f22, 0x48($sp)
/* BEE91C 80241B2C D7B40040 */  ldc1      $f20, 0x40($sp)
/* BEE920 80241B30 03E00008 */  jr        $ra
/* BEE924 80241B34 27BD0050 */   addiu    $sp, $sp, 0x50
