.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A68_C3E658
/* C3E658 80240A68 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3E65C 80240A6C AFB20020 */  sw        $s2, 0x20($sp)
/* C3E660 80240A70 0080902D */  daddu     $s2, $a0, $zero
/* C3E664 80240A74 AFBF0028 */  sw        $ra, 0x28($sp)
/* C3E668 80240A78 AFB30024 */  sw        $s3, 0x24($sp)
/* C3E66C 80240A7C AFB1001C */  sw        $s1, 0x1c($sp)
/* C3E670 80240A80 AFB00018 */  sw        $s0, 0x18($sp)
/* C3E674 80240A84 8E510148 */  lw        $s1, 0x148($s2)
/* C3E678 80240A88 00A0982D */  daddu     $s3, $a1, $zero
/* C3E67C 80240A8C 86240008 */  lh        $a0, 8($s1)
/* C3E680 80240A90 0C00EABB */  jal       get_npc_unsafe
/* C3E684 80240A94 00C0802D */   daddu    $s0, $a2, $zero
/* C3E688 80240A98 0200202D */  daddu     $a0, $s0, $zero
/* C3E68C 80240A9C 0040802D */  daddu     $s0, $v0, $zero
/* C3E690 80240AA0 AFA00010 */  sw        $zero, 0x10($sp)
/* C3E694 80240AA4 8E660024 */  lw        $a2, 0x24($s3)
/* C3E698 80240AA8 8E670028 */  lw        $a3, 0x28($s3)
/* C3E69C 80240AAC 0C01242D */  jal       func_800490B4
/* C3E6A0 80240AB0 0220282D */   daddu    $a1, $s1, $zero
/* C3E6A4 80240AB4 1040000C */  beqz      $v0, .L80240AE8
/* C3E6A8 80240AB8 00000000 */   nop
/* C3E6AC 80240ABC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C3E6B0 80240AC0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3E6B4 80240AC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3E6B8 80240AC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3E6BC 80240ACC 8C460028 */  lw        $a2, 0x28($v0)
/* C3E6C0 80240AD0 0C00A720 */  jal       atan2
/* C3E6C4 80240AD4 8C470030 */   lw       $a3, 0x30($v0)
/* C3E6C8 80240AD8 2402000C */  addiu     $v0, $zero, 0xc
/* C3E6CC 80240ADC E600000C */  swc1      $f0, 0xc($s0)
/* C3E6D0 80240AE0 080902E1 */  j         .L80240B84
/* C3E6D4 80240AE4 AE420070 */   sw       $v0, 0x70($s2)
.L80240AE8:
/* C3E6D8 80240AE8 9602008E */  lhu       $v0, 0x8e($s0)
/* C3E6DC 80240AEC 2442FFFF */  addiu     $v0, $v0, -1
/* C3E6E0 80240AF0 A602008E */  sh        $v0, 0x8e($s0)
/* C3E6E4 80240AF4 00021400 */  sll       $v0, $v0, 0x10
/* C3E6E8 80240AF8 1C400022 */  bgtz      $v0, .L80240B84
/* C3E6EC 80240AFC 00000000 */   nop
/* C3E6F0 80240B00 8E420074 */  lw        $v0, 0x74($s2)
/* C3E6F4 80240B04 2442FFFF */  addiu     $v0, $v0, -1
/* C3E6F8 80240B08 18400014 */  blez      $v0, .L80240B5C
/* C3E6FC 80240B0C AE420074 */   sw       $v0, 0x74($s2)
/* C3E700 80240B10 C600000C */  lwc1      $f0, 0xc($s0)
/* C3E704 80240B14 3C014334 */  lui       $at, 0x4334
/* C3E708 80240B18 44816000 */  mtc1      $at, $f12
/* C3E70C 80240B1C 0C00A6C9 */  jal       clamp_angle
/* C3E710 80240B20 460C0300 */   add.s    $f12, $f0, $f12
/* C3E714 80240B24 E600000C */  swc1      $f0, 0xc($s0)
/* C3E718 80240B28 8E640008 */  lw        $a0, 8($s3)
/* C3E71C 80240B2C 000417C2 */  srl       $v0, $a0, 0x1f
/* C3E720 80240B30 00822021 */  addu      $a0, $a0, $v0
/* C3E724 80240B34 00042043 */  sra       $a0, $a0, 1
/* C3E728 80240B38 0C00A67F */  jal       rand_int
/* C3E72C 80240B3C 24840001 */   addiu    $a0, $a0, 1
/* C3E730 80240B40 8E630008 */  lw        $v1, 8($s3)
/* C3E734 80240B44 000327C2 */  srl       $a0, $v1, 0x1f
/* C3E738 80240B48 00641821 */  addu      $v1, $v1, $a0
/* C3E73C 80240B4C 00031843 */  sra       $v1, $v1, 1
/* C3E740 80240B50 00621821 */  addu      $v1, $v1, $v0
/* C3E744 80240B54 080902E1 */  j         .L80240B84
/* C3E748 80240B58 A603008E */   sh       $v1, 0x8e($s0)
.L80240B5C:
/* C3E74C 80240B5C 8E250088 */  lw        $a1, 0x88($s1)
/* C3E750 80240B60 24020028 */  addiu     $v0, $zero, 0x28
/* C3E754 80240B64 14A20003 */  bne       $a1, $v0, .L80240B74
/* C3E758 80240B68 24020032 */   addiu    $v0, $zero, 0x32
/* C3E75C 80240B6C 080902DF */  j         .L80240B7C
/* C3E760 80240B70 24020014 */   addiu    $v0, $zero, 0x14
.L80240B74:
/* C3E764 80240B74 14A20003 */  bne       $a1, $v0, .L80240B84
/* C3E768 80240B78 24020019 */   addiu    $v0, $zero, 0x19
.L80240B7C:
/* C3E76C 80240B7C A602008E */  sh        $v0, 0x8e($s0)
/* C3E770 80240B80 AE450070 */  sw        $a1, 0x70($s2)
.L80240B84:
/* C3E774 80240B84 8FBF0028 */  lw        $ra, 0x28($sp)
/* C3E778 80240B88 8FB30024 */  lw        $s3, 0x24($sp)
/* C3E77C 80240B8C 8FB20020 */  lw        $s2, 0x20($sp)
/* C3E780 80240B90 8FB1001C */  lw        $s1, 0x1c($sp)
/* C3E784 80240B94 8FB00018 */  lw        $s0, 0x18($sp)
/* C3E788 80240B98 03E00008 */  jr        $ra
/* C3E78C 80240B9C 27BD0030 */   addiu    $sp, $sp, 0x30
