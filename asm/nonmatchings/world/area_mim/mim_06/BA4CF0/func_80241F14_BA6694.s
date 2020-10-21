.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F14_BA6694
/* BA6694 80241F14 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BA6698 80241F18 AFB00030 */  sw        $s0, 0x30($sp)
/* BA669C 80241F1C 0080802D */  daddu     $s0, $a0, $zero
/* BA66A0 80241F20 AFBF0040 */  sw        $ra, 0x40($sp)
/* BA66A4 80241F24 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA66A8 80241F28 AFB20038 */  sw        $s2, 0x38($sp)
/* BA66AC 80241F2C AFB10034 */  sw        $s1, 0x34($sp)
/* BA66B0 80241F30 F7B60050 */  sdc1      $f22, 0x50($sp)
/* BA66B4 80241F34 F7B40048 */  sdc1      $f20, 0x48($sp)
/* BA66B8 80241F38 8E130148 */  lw        $s3, 0x148($s0)
/* BA66BC 80241F3C 00A0882D */  daddu     $s1, $a1, $zero
/* BA66C0 80241F40 86640008 */  lh        $a0, 8($s3)
/* BA66C4 80241F44 0C00EABB */  jal       get_npc_unsafe
/* BA66C8 80241F48 00C0902D */   daddu    $s2, $a2, $zero
/* BA66CC 80241F4C 0200202D */  daddu     $a0, $s0, $zero
/* BA66D0 80241F50 0220282D */  daddu     $a1, $s1, $zero
/* BA66D4 80241F54 0240302D */  daddu     $a2, $s2, $zero
/* BA66D8 80241F58 0C012568 */  jal       func_800495A0
/* BA66DC 80241F5C 0040802D */   daddu    $s0, $v0, $zero
/* BA66E0 80241F60 8E020000 */  lw        $v0, ($s0)
/* BA66E4 80241F64 2404002D */  addiu     $a0, $zero, 0x2d
/* BA66E8 80241F68 34420800 */  ori       $v0, $v0, 0x800
/* BA66EC 80241F6C 0C00A67F */  jal       rand_int
/* BA66F0 80241F70 AE020000 */   sw       $v0, ($s0)
/* BA66F4 80241F74 0200202D */  daddu     $a0, $s0, $zero
/* BA66F8 80241F78 3C05B000 */  lui       $a1, 0xb000
/* BA66FC 80241F7C 34A50017 */  ori       $a1, $a1, 0x17
/* BA6700 80241F80 44820000 */  mtc1      $v0, $f0
/* BA6704 80241F84 00000000 */  nop       
/* BA6708 80241F88 46800021 */  cvt.d.w   $f0, $f0
/* BA670C 80241F8C 3C014024 */  lui       $at, 0x4024
/* BA6710 80241F90 44811800 */  mtc1      $at, $f3
/* BA6714 80241F94 44801000 */  mtc1      $zero, $f2
/* BA6718 80241F98 3C014020 */  lui       $at, 0x4020
/* BA671C 80241F9C 44812800 */  mtc1      $at, $f5
/* BA6720 80241FA0 44802000 */  mtc1      $zero, $f4
/* BA6724 80241FA4 46220003 */  div.d     $f0, $f0, $f2
/* BA6728 80241FA8 46240000 */  add.d     $f0, $f0, $f4
/* BA672C 80241FAC 3C013FC0 */  lui       $at, 0x3fc0
/* BA6730 80241FB0 44811000 */  mtc1      $at, $f2
/* BA6734 80241FB4 0000302D */  daddu     $a2, $zero, $zero
/* BA6738 80241FB8 E6020014 */  swc1      $f2, 0x14($s0)
/* BA673C 80241FBC 46200020 */  cvt.s.d   $f0, $f0
/* BA6740 80241FC0 0C012530 */  jal       func_800494C0
/* BA6744 80241FC4 E600001C */   swc1     $f0, 0x1c($s0)
/* BA6748 80241FC8 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BA674C 80241FCC C6000040 */  lwc1      $f0, 0x40($s0)
/* BA6750 80241FD0 C4620000 */  lwc1      $f2, ($v1)
/* BA6754 80241FD4 468010A0 */  cvt.s.w   $f2, $f2
/* BA6758 80241FD8 C4640008 */  lwc1      $f4, 8($v1)
/* BA675C 80241FDC 46802120 */  cvt.s.w   $f4, $f4
/* BA6760 80241FE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA6764 80241FE4 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BA6768 80241FE8 44051000 */  mfc1      $a1, $f2
/* BA676C 80241FEC C440000C */  lwc1      $f0, 0xc($v0)
/* BA6770 80241FF0 46800020 */  cvt.s.w   $f0, $f0
/* BA6774 80241FF4 E7A00014 */  swc1      $f0, 0x14($sp)
/* BA6778 80241FF8 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BA677C 80241FFC 44062000 */  mfc1      $a2, $f4
/* BA6780 80242000 C4400010 */  lwc1      $f0, 0x10($v0)
/* BA6784 80242004 46800020 */  cvt.s.w   $f0, $f0
/* BA6788 80242008 E7A00018 */  swc1      $f0, 0x18($sp)
/* BA678C 8024200C 8C640018 */  lw        $a0, 0x18($v1)
/* BA6790 80242010 0C0123F5 */  jal       is_point_within_region
/* BA6794 80242014 8E070038 */   lw       $a3, 0x38($s0)
/* BA6798 80242018 10400035 */  beqz      $v0, .L802420F0
/* BA679C 8024201C 00000000 */   nop      
/* BA67A0 80242020 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA67A4 80242024 3C0141C8 */  lui       $at, 0x41c8
/* BA67A8 80242028 4481B000 */  mtc1      $at, $f22
/* BA67AC 8024202C 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BA67B0 80242030 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA67B4 80242034 C4480000 */  lwc1      $f8, ($v0)
/* BA67B8 80242038 46804220 */  cvt.s.w   $f8, $f8
/* BA67BC 8024203C 44064000 */  mfc1      $a2, $f8
/* BA67C0 80242040 C4480008 */  lwc1      $f8, 8($v0)
/* BA67C4 80242044 46804220 */  cvt.s.w   $f8, $f8
/* BA67C8 80242048 44074000 */  mfc1      $a3, $f8
/* BA67CC 8024204C 3C01403E */  lui       $at, 0x403e
/* BA67D0 80242050 4481A800 */  mtc1      $at, $f21
/* BA67D4 80242054 4480A000 */  mtc1      $zero, $f20
/* BA67D8 80242058 0C00A720 */  jal       atan2
/* BA67DC 8024205C 0000882D */   daddu    $s1, $zero, $zero
/* BA67E0 80242060 C6020038 */  lwc1      $f2, 0x38($s0)
/* BA67E4 80242064 C604003C */  lwc1      $f4, 0x3c($s0)
/* BA67E8 80242068 C6060040 */  lwc1      $f6, 0x40($s0)
/* BA67EC 8024206C E600000C */  swc1      $f0, 0xc($s0)
/* BA67F0 80242070 E7A20020 */  swc1      $f2, 0x20($sp)
/* BA67F4 80242074 E7A40024 */  swc1      $f4, 0x24($sp)
/* BA67F8 80242078 E7A60028 */  swc1      $f6, 0x28($sp)
.L8024207C:
/* BA67FC 8024207C E7B60010 */  swc1      $f22, 0x10($sp)
/* BA6800 80242080 C600000C */  lwc1      $f0, 0xc($s0)
/* BA6804 80242084 E7A00014 */  swc1      $f0, 0x14($sp)
/* BA6808 80242088 860200A8 */  lh        $v0, 0xa8($s0)
/* BA680C 8024208C 27A50020 */  addiu     $a1, $sp, 0x20
/* BA6810 80242090 44820000 */  mtc1      $v0, $f0
/* BA6814 80242094 00000000 */  nop       
/* BA6818 80242098 46800020 */  cvt.s.w   $f0, $f0
/* BA681C 8024209C E7A00018 */  swc1      $f0, 0x18($sp)
/* BA6820 802420A0 860200A6 */  lh        $v0, 0xa6($s0)
/* BA6824 802420A4 27A60024 */  addiu     $a2, $sp, 0x24
/* BA6828 802420A8 44820000 */  mtc1      $v0, $f0
/* BA682C 802420AC 00000000 */  nop       
/* BA6830 802420B0 46800020 */  cvt.s.w   $f0, $f0
/* BA6834 802420B4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA6838 802420B8 8E040080 */  lw        $a0, 0x80($s0)
/* BA683C 802420BC 0C037711 */  jal       func_800DDC44
/* BA6840 802420C0 27A70028 */   addiu    $a3, $sp, 0x28
/* BA6844 802420C4 10400016 */  beqz      $v0, .L80242120
/* BA6848 802420C8 26310001 */   addiu    $s1, $s1, 1
/* BA684C 802420CC C600000C */  lwc1      $f0, 0xc($s0)
/* BA6850 802420D0 46000021 */  cvt.d.s   $f0, $f0
/* BA6854 802420D4 46340000 */  add.d     $f0, $f0, $f20
/* BA6858 802420D8 2A220006 */  slti      $v0, $s1, 6
/* BA685C 802420DC 46200020 */  cvt.s.d   $f0, $f0
/* BA6860 802420E0 1440FFE6 */  bnez      $v0, .L8024207C
/* BA6864 802420E4 E600000C */   swc1     $f0, 0xc($s0)
/* BA6868 802420E8 08090848 */  j         .L80242120
/* BA686C 802420EC 00000000 */   nop      
.L802420F0:
/* BA6870 802420F0 0C00A67F */  jal       rand_int
/* BA6874 802420F4 2404003C */   addiu    $a0, $zero, 0x3c
/* BA6878 802420F8 C60C000C */  lwc1      $f12, 0xc($s0)
/* BA687C 802420FC 44820000 */  mtc1      $v0, $f0
/* BA6880 80242100 00000000 */  nop       
/* BA6884 80242104 46800020 */  cvt.s.w   $f0, $f0
/* BA6888 80242108 46006300 */  add.s     $f12, $f12, $f0
/* BA688C 8024210C 3C0141F0 */  lui       $at, 0x41f0
/* BA6890 80242110 44810000 */  mtc1      $at, $f0
/* BA6894 80242114 0C00A6C9 */  jal       clamp_angle
/* BA6898 80242118 46006301 */   sub.s    $f12, $f12, $f0
/* BA689C 8024211C E600000C */  swc1      $f0, 0xc($s0)
.L80242120:
/* BA68A0 80242120 8FBF0040 */  lw        $ra, 0x40($sp)
/* BA68A4 80242124 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA68A8 80242128 8FB20038 */  lw        $s2, 0x38($sp)
/* BA68AC 8024212C 8FB10034 */  lw        $s1, 0x34($sp)
/* BA68B0 80242130 8FB00030 */  lw        $s0, 0x30($sp)
/* BA68B4 80242134 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BA68B8 80242138 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BA68BC 8024213C 03E00008 */  jr        $ra
/* BA68C0 80242140 27BD0058 */   addiu    $sp, $sp, 0x58
