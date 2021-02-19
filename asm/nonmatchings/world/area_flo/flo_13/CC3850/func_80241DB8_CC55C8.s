.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DB8_CC55C8
/* CC55C8 80241DB8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* CC55CC 80241DBC AFB40050 */  sw        $s4, 0x50($sp)
/* CC55D0 80241DC0 0080A02D */  daddu     $s4, $a0, $zero
/* CC55D4 80241DC4 AFBF005C */  sw        $ra, 0x5c($sp)
/* CC55D8 80241DC8 AFB60058 */  sw        $s6, 0x58($sp)
/* CC55DC 80241DCC AFB50054 */  sw        $s5, 0x54($sp)
/* CC55E0 80241DD0 AFB3004C */  sw        $s3, 0x4c($sp)
/* CC55E4 80241DD4 AFB20048 */  sw        $s2, 0x48($sp)
/* CC55E8 80241DD8 AFB10044 */  sw        $s1, 0x44($sp)
/* CC55EC 80241DDC AFB00040 */  sw        $s0, 0x40($sp)
/* CC55F0 80241DE0 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CC55F4 80241DE4 8E930148 */  lw        $s3, 0x148($s4)
/* CC55F8 80241DE8 86640008 */  lh        $a0, 8($s3)
/* CC55FC 80241DEC 8E90000C */  lw        $s0, 0xc($s4)
/* CC5600 80241DF0 0C00EABB */  jal       get_npc_unsafe
/* CC5604 80241DF4 00A0882D */   daddu    $s1, $a1, $zero
/* CC5608 80241DF8 0280202D */  daddu     $a0, $s4, $zero
/* CC560C 80241DFC 8E050000 */  lw        $a1, ($s0)
/* CC5610 80241E00 0C0B1EAF */  jal       get_variable
/* CC5614 80241E04 0040902D */   daddu    $s2, $v0, $zero
/* CC5618 80241E08 AFA00020 */  sw        $zero, 0x20($sp)
/* CC561C 80241E0C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CC5620 80241E10 8C630030 */  lw        $v1, 0x30($v1)
/* CC5624 80241E14 AFA30024 */  sw        $v1, 0x24($sp)
/* CC5628 80241E18 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CC562C 80241E1C 8C63001C */  lw        $v1, 0x1c($v1)
/* CC5630 80241E20 AFA30028 */  sw        $v1, 0x28($sp)
/* CC5634 80241E24 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CC5638 80241E28 8C630024 */  lw        $v1, 0x24($v1)
/* CC563C 80241E2C AFA3002C */  sw        $v1, 0x2c($sp)
/* CC5640 80241E30 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CC5644 80241E34 8C630028 */  lw        $v1, 0x28($v1)
/* CC5648 80241E38 27B50020 */  addiu     $s5, $sp, 0x20
/* CC564C 80241E3C AFA30030 */  sw        $v1, 0x30($sp)
/* CC5650 80241E40 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CC5654 80241E44 3C0142F0 */  lui       $at, 0x42f0
/* CC5658 80241E48 44810000 */  mtc1      $at, $f0
/* CC565C 80241E4C 8C63002C */  lw        $v1, 0x2c($v1)
/* CC5660 80241E50 0040B02D */  daddu     $s6, $v0, $zero
/* CC5664 80241E54 E7A00038 */  swc1      $f0, 0x38($sp)
/* CC5668 80241E58 A7A0003C */  sh        $zero, 0x3c($sp)
/* CC566C 80241E5C 12200007 */  beqz      $s1, .L80241E7C
/* CC5670 80241E60 AFA30034 */   sw       $v1, 0x34($sp)
/* CC5674 80241E64 0240202D */  daddu     $a0, $s2, $zero
/* CC5678 80241E68 0260282D */  daddu     $a1, $s3, $zero
/* CC567C 80241E6C 0280302D */  daddu     $a2, $s4, $zero
/* CC5680 80241E70 0C0904EB */  jal       func_802413AC_CC4BBC
/* CC5684 80241E74 02C0382D */   daddu    $a3, $s6, $zero
/* CC5688 80241E78 AE800070 */  sw        $zero, 0x70($s4)
.L80241E7C:
/* CC568C 80241E7C 2402FFFD */  addiu     $v0, $zero, -3
/* CC5690 80241E80 A24200AB */  sb        $v0, 0xab($s2)
/* CC5694 80241E84 8E6300B0 */  lw        $v1, 0xb0($s3)
/* CC5698 80241E88 30620004 */  andi      $v0, $v1, 4
/* CC569C 80241E8C 10400007 */  beqz      $v0, .L80241EAC
/* CC56A0 80241E90 00000000 */   nop
/* CC56A4 80241E94 826200B4 */  lb        $v0, 0xb4($s3)
/* CC56A8 80241E98 144000F4 */  bnez      $v0, .L8024226C
/* CC56AC 80241E9C 0000102D */   daddu    $v0, $zero, $zero
/* CC56B0 80241EA0 2402FFFB */  addiu     $v0, $zero, -5
/* CC56B4 80241EA4 00621024 */  and       $v0, $v1, $v0
/* CC56B8 80241EA8 AE6200B0 */  sw        $v0, 0xb0($s3)
.L80241EAC:
/* CC56BC 80241EAC 8E830070 */  lw        $v1, 0x70($s4)
/* CC56C0 80241EB0 24020001 */  addiu     $v0, $zero, 1
/* CC56C4 80241EB4 10620011 */  beq       $v1, $v0, .L80241EFC
/* CC56C8 80241EB8 28620002 */   slti     $v0, $v1, 2
/* CC56CC 80241EBC 10400005 */  beqz      $v0, .L80241ED4
/* CC56D0 80241EC0 24020002 */   addiu    $v0, $zero, 2
/* CC56D4 80241EC4 10600009 */  beqz      $v1, .L80241EEC
/* CC56D8 80241EC8 2402000C */   addiu    $v0, $zero, 0xc
/* CC56DC 80241ECC 080907CF */  j         .L80241F3C
/* CC56E0 80241ED0 00000000 */   nop
.L80241ED4:
/* CC56E4 80241ED4 1062000F */  beq       $v1, $v0, .L80241F14
/* CC56E8 80241ED8 24020003 */   addiu    $v0, $zero, 3
/* CC56EC 80241EDC 10620012 */  beq       $v1, $v0, .L80241F28
/* CC56F0 80241EE0 0280202D */   daddu    $a0, $s4, $zero
/* CC56F4 80241EE4 080907CD */  j         .L80241F34
/* CC56F8 80241EE8 00000000 */   nop
.L80241EEC:
/* CC56FC 80241EEC 0280202D */  daddu     $a0, $s4, $zero
/* CC5700 80241EF0 02C0282D */  daddu     $a1, $s6, $zero
/* CC5704 80241EF4 0C090071 */  jal       func_802401C4_CC39D4
/* CC5708 80241EF8 02A0302D */   daddu    $a2, $s5, $zero
.L80241EFC:
/* CC570C 80241EFC 0280202D */  daddu     $a0, $s4, $zero
/* CC5710 80241F00 02C0282D */  daddu     $a1, $s6, $zero
/* CC5714 80241F04 0C0905C1 */  jal       func_80241704_CC4F14
/* CC5718 80241F08 02A0302D */   daddu    $a2, $s5, $zero
/* CC571C 80241F0C 080907CD */  j         .L80241F34
/* CC5720 80241F10 00000000 */   nop
.L80241F14:
/* CC5724 80241F14 0280202D */  daddu     $a0, $s4, $zero
/* CC5728 80241F18 02C0282D */  daddu     $a1, $s6, $zero
/* CC572C 80241F1C 0C090267 */  jal       flo_13_UnkNpcAIFunc1
/* CC5730 80241F20 02A0302D */   daddu    $a2, $s5, $zero
/* CC5734 80241F24 0280202D */  daddu     $a0, $s4, $zero
.L80241F28:
/* CC5738 80241F28 02C0282D */  daddu     $a1, $s6, $zero
/* CC573C 80241F2C 0C0906DA */  jal       func_80241B68_CC5378
/* CC5740 80241F30 02A0302D */   daddu    $a2, $s5, $zero
.L80241F34:
/* CC5744 80241F34 8E830070 */  lw        $v1, 0x70($s4)
/* CC5748 80241F38 2402000C */  addiu     $v0, $zero, 0xc
.L80241F3C:
/* CC574C 80241F3C 1462001A */  bne       $v1, $v0, .L80241FA8
/* CC5750 80241F40 00000000 */   nop
/* CC5754 80241F44 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CC5758 80241F48 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC575C 80241F4C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC5760 80241F50 C64E0040 */  lwc1      $f14, 0x40($s2)
/* CC5764 80241F54 8C460028 */  lw        $a2, 0x28($v0)
/* CC5768 80241F58 0C00A720 */  jal       atan2
/* CC576C 80241F5C 8C470030 */   lw       $a3, 0x30($v0)
/* CC5770 80241F60 0C0905AF */  jal       func_802416BC_CC4ECC
/* CC5774 80241F64 E640000C */   swc1     $f0, 0xc($s2)
/* CC5778 80241F68 0440000F */  bltz      $v0, .L80241FA8
/* CC577C 80241F6C AE62007C */   sw       $v0, 0x7c($s3)
/* CC5780 80241F70 0C00FB3A */  jal       get_enemy
/* CC5784 80241F74 0040202D */   daddu    $a0, $v0, $zero
/* CC5788 80241F78 3C030049 */  lui       $v1, 0x49
/* CC578C 80241F7C 0040202D */  daddu     $a0, $v0, $zero
/* CC5790 80241F80 24020001 */  addiu     $v0, $zero, 1
/* CC5794 80241F84 AC820094 */  sw        $v0, 0x94($a0)
/* CC5798 80241F88 86620008 */  lh        $v0, 8($s3)
/* CC579C 80241F8C 34630014 */  ori       $v1, $v1, 0x14
/* CC57A0 80241F90 AC820098 */  sw        $v0, 0x98($a0)
/* CC57A4 80241F94 2402000F */  addiu     $v0, $zero, 0xf
/* CC57A8 80241F98 A642008E */  sh        $v0, 0x8e($s2)
/* CC57AC 80241F9C 2402001E */  addiu     $v0, $zero, 0x1e
/* CC57B0 80241FA0 AE430028 */  sw        $v1, 0x28($s2)
/* CC57B4 80241FA4 AE820070 */  sw        $v0, 0x70($s4)
.L80241FA8:
/* CC57B8 80241FA8 8E830070 */  lw        $v1, 0x70($s4)
/* CC57BC 80241FAC 2402000D */  addiu     $v0, $zero, 0xd
/* CC57C0 80241FB0 10620010 */  beq       $v1, $v0, .L80241FF4
/* CC57C4 80241FB4 2862000E */   slti     $v0, $v1, 0xe
/* CC57C8 80241FB8 10400005 */  beqz      $v0, .L80241FD0
/* CC57CC 80241FBC 2402000C */   addiu    $v0, $zero, 0xc
/* CC57D0 80241FC0 10620008 */  beq       $v1, $v0, .L80241FE4
/* CC57D4 80241FC4 2410001F */   addiu    $s0, $zero, 0x1f
/* CC57D8 80241FC8 08090808 */  j         .L80242020
/* CC57DC 80241FCC 00000000 */   nop
.L80241FD0:
/* CC57E0 80241FD0 2402000E */  addiu     $v0, $zero, 0xe
/* CC57E4 80241FD4 1062000D */  beq       $v1, $v0, .L8024200C
/* CC57E8 80241FD8 0280202D */   daddu    $a0, $s4, $zero
/* CC57EC 80241FDC 08090806 */  j         .L80242018
/* CC57F0 80241FE0 00000000 */   nop
.L80241FE4:
/* CC57F4 80241FE4 0280202D */  daddu     $a0, $s4, $zero
/* CC57F8 80241FE8 02C0282D */  daddu     $a1, $s6, $zero
/* CC57FC 80241FEC 0C0903A1 */  jal       flo_13_UnkNpcAIFunc14
/* CC5800 80241FF0 02A0302D */   daddu    $a2, $s5, $zero
.L80241FF4:
/* CC5804 80241FF4 0280202D */  daddu     $a0, $s4, $zero
/* CC5808 80241FF8 02C0282D */  daddu     $a1, $s6, $zero
/* CC580C 80241FFC 0C0903EE */  jal       flo_13_UnkNpcAIFunc3
/* CC5810 80242000 02A0302D */   daddu    $a2, $s5, $zero
/* CC5814 80242004 08090806 */  j         .L80242018
/* CC5818 80242008 00000000 */   nop
.L8024200C:
/* CC581C 8024200C 02C0282D */  daddu     $a1, $s6, $zero
/* CC5820 80242010 0C090407 */  jal       func_8024101C_CC482C
/* CC5824 80242014 02A0302D */   daddu    $a2, $s5, $zero
.L80242018:
/* CC5828 80242018 8E830070 */  lw        $v1, 0x70($s4)
/* CC582C 8024201C 2410001F */  addiu     $s0, $zero, 0x1f
.L80242020:
/* CC5830 80242020 1070001B */  beq       $v1, $s0, .L80242090
/* CC5834 80242024 28620020 */   slti     $v0, $v1, 0x20
/* CC5838 80242028 10400005 */  beqz      $v0, .L80242040
/* CC583C 8024202C 2402001E */   addiu    $v0, $zero, 0x1e
/* CC5840 80242030 1062000A */  beq       $v1, $v0, .L8024205C
/* CC5844 80242034 00000000 */   nop
/* CC5848 80242038 08090843 */  j         .L8024210C
/* CC584C 8024203C 00000000 */   nop
.L80242040:
/* CC5850 80242040 24020020 */  addiu     $v0, $zero, 0x20
/* CC5854 80242044 10620022 */  beq       $v1, $v0, .L802420D0
/* CC5858 80242048 24020021 */   addiu    $v0, $zero, 0x21
/* CC585C 8024204C 10620029 */  beq       $v1, $v0, .L802420F4
/* CC5860 80242050 00000000 */   nop
/* CC5864 80242054 08090843 */  j         .L8024210C
/* CC5868 80242058 00000000 */   nop
.L8024205C:
/* CC586C 8024205C 9642008E */  lhu       $v0, 0x8e($s2)
/* CC5870 80242060 2442FFFF */  addiu     $v0, $v0, -1
/* CC5874 80242064 A642008E */  sh        $v0, 0x8e($s2)
/* CC5878 80242068 00021400 */  sll       $v0, $v0, 0x10
/* CC587C 8024206C 1C400027 */  bgtz      $v0, .L8024210C
/* CC5880 80242070 00000000 */   nop
/* CC5884 80242074 0C00FB3A */  jal       get_enemy
/* CC5888 80242078 8E64007C */   lw       $a0, 0x7c($s3)
/* CC588C 8024207C 24030002 */  addiu     $v1, $zero, 2
/* CC5890 80242080 AC430094 */  sw        $v1, 0x94($v0)
/* CC5894 80242084 24020005 */  addiu     $v0, $zero, 5
/* CC5898 80242088 A642008E */  sh        $v0, 0x8e($s2)
/* CC589C 8024208C AE900070 */  sw        $s0, 0x70($s4)
.L80242090:
/* CC58A0 80242090 9642008E */  lhu       $v0, 0x8e($s2)
/* CC58A4 80242094 2442FFFF */  addiu     $v0, $v0, -1
/* CC58A8 80242098 A642008E */  sh        $v0, 0x8e($s2)
/* CC58AC 8024209C 00021400 */  sll       $v0, $v0, 0x10
/* CC58B0 802420A0 1C40001A */  bgtz      $v0, .L8024210C
/* CC58B4 802420A4 3C020049 */   lui      $v0, 0x49
/* CC58B8 802420A8 34420015 */  ori       $v0, $v0, 0x15
/* CC58BC 802420AC AE420028 */  sw        $v0, 0x28($s2)
/* CC58C0 802420B0 0C00FB3A */  jal       get_enemy
/* CC58C4 802420B4 8E64007C */   lw       $a0, 0x7c($s3)
/* CC58C8 802420B8 24030003 */  addiu     $v1, $zero, 3
/* CC58CC 802420BC AC430094 */  sw        $v1, 0x94($v0)
/* CC58D0 802420C0 2402000A */  addiu     $v0, $zero, 0xa
/* CC58D4 802420C4 A642008E */  sh        $v0, 0x8e($s2)
/* CC58D8 802420C8 24020020 */  addiu     $v0, $zero, 0x20
/* CC58DC 802420CC AE820070 */  sw        $v0, 0x70($s4)
.L802420D0:
/* CC58E0 802420D0 9642008E */  lhu       $v0, 0x8e($s2)
/* CC58E4 802420D4 2442FFFF */  addiu     $v0, $v0, -1
/* CC58E8 802420D8 A642008E */  sh        $v0, 0x8e($s2)
/* CC58EC 802420DC 00021400 */  sll       $v0, $v0, 0x10
/* CC58F0 802420E0 1C40000A */  bgtz      $v0, .L8024210C
/* CC58F4 802420E4 24020003 */   addiu    $v0, $zero, 3
/* CC58F8 802420E8 A642008E */  sh        $v0, 0x8e($s2)
/* CC58FC 802420EC 24020021 */  addiu     $v0, $zero, 0x21
/* CC5900 802420F0 AE820070 */  sw        $v0, 0x70($s4)
.L802420F4:
/* CC5904 802420F4 9642008E */  lhu       $v0, 0x8e($s2)
/* CC5908 802420F8 2442FFFF */  addiu     $v0, $v0, -1
/* CC590C 802420FC A642008E */  sh        $v0, 0x8e($s2)
/* CC5910 80242100 00021400 */  sll       $v0, $v0, 0x10
/* CC5914 80242104 58400001 */  blezl     $v0, .L8024210C
/* CC5918 80242108 AE800070 */   sw       $zero, 0x70($s4)
.L8024210C:
/* CC591C 8024210C 8E820070 */  lw        $v0, 0x70($s4)
/* CC5920 80242110 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* CC5924 80242114 2C420002 */  sltiu     $v0, $v0, 2
/* CC5928 80242118 10400054 */  beqz      $v0, .L8024226C
/* CC592C 8024211C 0000102D */   daddu    $v0, $zero, $zero
/* CC5930 80242120 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* CC5934 80242124 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* CC5938 80242128 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CC593C 8024212C 8E020000 */  lw        $v0, ($s0)
/* CC5940 80242130 C64E0040 */  lwc1      $f14, 0x40($s2)
/* CC5944 80242134 8C460028 */  lw        $a2, 0x28($v0)
/* CC5948 80242138 0C00A720 */  jal       atan2
/* CC594C 8024213C 8C470030 */   lw       $a3, 0x30($v0)
/* CC5950 80242140 8E460038 */  lw        $a2, 0x38($s2)
/* CC5954 80242144 8E470040 */  lw        $a3, 0x40($s2)
/* CC5958 80242148 8E020000 */  lw        $v0, ($s0)
/* CC595C 8024214C E640000C */  swc1      $f0, 0xc($s2)
/* CC5960 80242150 C44C0028 */  lwc1      $f12, 0x28($v0)
/* CC5964 80242154 0C00A7B5 */  jal       dist2D
/* CC5968 80242158 C44E0030 */   lwc1     $f14, 0x30($v0)
/* CC596C 8024215C C6A20008 */  lwc1      $f2, 8($s5)
/* CC5970 80242160 468010A0 */  cvt.s.w   $f2, $f2
/* CC5974 80242164 44051000 */  mfc1      $a1, $f2
/* CC5978 80242168 C6A2000C */  lwc1      $f2, 0xc($s5)
/* CC597C 8024216C 468010A0 */  cvt.s.w   $f2, $f2
/* CC5980 80242170 44061000 */  mfc1      $a2, $f2
/* CC5984 80242174 C6420040 */  lwc1      $f2, 0x40($s2)
/* CC5988 80242178 E7A20010 */  swc1      $f2, 0x10($sp)
/* CC598C 8024217C C6A20010 */  lwc1      $f2, 0x10($s5)
/* CC5990 80242180 468010A0 */  cvt.s.w   $f2, $f2
/* CC5994 80242184 E7A20014 */  swc1      $f2, 0x14($sp)
/* CC5998 80242188 C6A20014 */  lwc1      $f2, 0x14($s5)
/* CC599C 8024218C 468010A0 */  cvt.s.w   $f2, $f2
/* CC59A0 80242190 E7A20018 */  swc1      $f2, 0x18($sp)
/* CC59A4 80242194 8EA40004 */  lw        $a0, 4($s5)
/* CC59A8 80242198 8E470038 */  lw        $a3, 0x38($s2)
/* CC59AC 8024219C 0C0123F5 */  jal       is_point_within_region
/* CC59B0 802421A0 46000506 */   mov.s    $f20, $f0
/* CC59B4 802421A4 14400031 */  bnez      $v0, .L8024226C
/* CC59B8 802421A8 0000102D */   daddu    $v0, $zero, $zero
/* CC59BC 802421AC 3C01403E */  lui       $at, 0x403e
/* CC59C0 802421B0 44810800 */  mtc1      $at, $f1
/* CC59C4 802421B4 44800000 */  mtc1      $zero, $f0
/* CC59C8 802421B8 4600A0A1 */  cvt.d.s   $f2, $f20
/* CC59CC 802421BC 4622003C */  c.lt.d    $f0, $f2
/* CC59D0 802421C0 00000000 */  nop
/* CC59D4 802421C4 45000029 */  bc1f      .L8024226C
/* CC59D8 802421C8 00000000 */   nop
/* CC59DC 802421CC 8642008C */  lh        $v0, 0x8c($s2)
/* CC59E0 802421D0 54400026 */  bnel      $v0, $zero, .L8024226C
/* CC59E4 802421D4 0000102D */   daddu    $v0, $zero, $zero
/* CC59E8 802421D8 3C014034 */  lui       $at, 0x4034
/* CC59EC 802421DC 44810800 */  mtc1      $at, $f1
/* CC59F0 802421E0 44800000 */  mtc1      $zero, $f0
/* CC59F4 802421E4 00000000 */  nop
/* CC59F8 802421E8 46201001 */  sub.d     $f0, $f2, $f0
/* CC59FC 802421EC 44801000 */  mtc1      $zero, $f2
/* CC5A00 802421F0 44801800 */  mtc1      $zero, $f3
/* CC5A04 802421F4 46200120 */  cvt.s.d   $f4, $f0
/* CC5A08 802421F8 46002021 */  cvt.d.s   $f0, $f4
/* CC5A0C 802421FC 4622003C */  c.lt.d    $f0, $f2
/* CC5A10 80242200 00000000 */  nop
/* CC5A14 80242204 45000002 */  bc1f      .L80242210
/* CC5A18 80242208 00000000 */   nop
/* CC5A1C 8024220C 44802000 */  mtc1      $zero, $f4
.L80242210:
/* CC5A20 80242210 3C014069 */  lui       $at, 0x4069
/* CC5A24 80242214 44811800 */  mtc1      $at, $f3
/* CC5A28 80242218 44801000 */  mtc1      $zero, $f2
/* CC5A2C 8024221C 46002021 */  cvt.d.s   $f0, $f4
/* CC5A30 80242220 4620103C */  c.lt.d    $f2, $f0
/* CC5A34 80242224 00000000 */  nop
/* CC5A38 80242228 45000003 */  bc1f      .L80242238
/* CC5A3C 8024222C 240200C8 */   addiu    $v0, $zero, 0xc8
/* CC5A40 80242230 3C014348 */  lui       $at, 0x4348
/* CC5A44 80242234 44812000 */  mtc1      $at, $f4
.L80242238:
/* CC5A48 80242238 AFA20010 */  sw        $v0, 0x10($sp)
/* CC5A4C 8024223C 8EC50000 */  lw        $a1, ($s6)
/* CC5A50 80242240 8EC60018 */  lw        $a2, 0x18($s6)
/* CC5A54 80242244 4600218D */  trunc.w.s $f6, $f4
/* CC5A58 80242248 44073000 */  mfc1      $a3, $f6
/* CC5A5C 8024224C 0C00A8ED */  jal       update_lerp
/* CC5A60 80242250 0000202D */   daddu    $a0, $zero, $zero
/* CC5A64 80242254 44050000 */  mfc1      $a1, $f0
/* CC5A68 80242258 8E46000C */  lw        $a2, 0xc($s2)
/* CC5A6C 8024225C 0240202D */  daddu     $a0, $s2, $zero
/* CC5A70 80242260 0C00EA95 */  jal       npc_move_heading
/* CC5A74 80242264 AC850018 */   sw       $a1, 0x18($a0)
/* CC5A78 80242268 0000102D */  daddu     $v0, $zero, $zero
.L8024226C:
/* CC5A7C 8024226C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CC5A80 80242270 8FB60058 */  lw        $s6, 0x58($sp)
/* CC5A84 80242274 8FB50054 */  lw        $s5, 0x54($sp)
/* CC5A88 80242278 8FB40050 */  lw        $s4, 0x50($sp)
/* CC5A8C 8024227C 8FB3004C */  lw        $s3, 0x4c($sp)
/* CC5A90 80242280 8FB20048 */  lw        $s2, 0x48($sp)
/* CC5A94 80242284 8FB10044 */  lw        $s1, 0x44($sp)
/* CC5A98 80242288 8FB00040 */  lw        $s0, 0x40($sp)
/* CC5A9C 8024228C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CC5AA0 80242290 03E00008 */  jr        $ra
/* CC5AA4 80242294 27BD0068 */   addiu    $sp, $sp, 0x68
