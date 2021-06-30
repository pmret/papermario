.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E2A6B0
/* E2A6B0 802B6000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E2A6B4 802B6004 AFB00010 */  sw        $s0, 0x10($sp)
/* E2A6B8 802B6008 0000802D */  daddu     $s0, $zero, $zero
/* E2A6BC 802B600C AFB10014 */  sw        $s1, 0x14($sp)
/* E2A6C0 802B6010 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2A6C4 802B6014 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2A6C8 802B6018 AFB20018 */  sw        $s2, 0x18($sp)
/* E2A6CC 802B601C AFBF001C */  sw        $ra, 0x1c($sp)
/* E2A6D0 802B6020 F7B40020 */  sdc1      $f20, 0x20($sp)
/* E2A6D4 802B6024 8222000D */  lb        $v0, 0xd($s1)
/* E2A6D8 802B6028 10400035 */  beqz      $v0, .L802B6100
/* E2A6DC 802B602C 0220902D */   daddu    $s2, $s1, $zero
/* E2A6E0 802B6030 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* E2A6E4 802B6034 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* E2A6E8 802B6038 9083007E */  lbu       $v1, 0x7e($a0)
/* E2A6EC 802B603C 30620008 */  andi      $v0, $v1, 8
/* E2A6F0 802B6040 10400003 */  beqz      $v0, .L802B6050
/* E2A6F4 802B6044 306200F7 */   andi     $v0, $v1, 0xf7
/* E2A6F8 802B6048 080AD840 */  j         .L802B6100
/* E2A6FC 802B604C A082007E */   sb       $v0, 0x7e($a0)
.L802B6050:
/* E2A700 802B6050 C62C0028 */  lwc1      $f12, 0x28($s1)
/* E2A704 802B6054 C62E002C */  lwc1      $f14, 0x2c($s1)
/* E2A708 802B6058 8E260030 */  lw        $a2, 0x30($s1)
/* E2A70C 802B605C 0C00F3ED */  jal       npc_find_closest
/* E2A710 802B6060 3C0742C8 */   lui      $a3, 0x42c8
/* E2A714 802B6064 0040802D */  daddu     $s0, $v0, $zero
/* E2A718 802B6068 12000026 */  beqz      $s0, .L802B6104
/* E2A71C 802B606C 0200102D */   daddu    $v0, $s0, $zero
/* E2A720 802B6070 C600003C */  lwc1      $f0, 0x3c($s0)
/* E2A724 802B6074 C622002C */  lwc1      $f2, 0x2c($s1)
/* E2A728 802B6078 46020001 */  sub.s     $f0, $f0, $f2
/* E2A72C 802B607C 3C013FF0 */  lui       $at, 0x3ff0
/* E2A730 802B6080 44811800 */  mtc1      $at, $f3
/* E2A734 802B6084 44801000 */  mtc1      $zero, $f2
/* E2A738 802B6088 46000021 */  cvt.d.s   $f0, $f0
/* E2A73C 802B608C 46200005 */  abs.d     $f0, $f0
/* E2A740 802B6090 46220001 */  sub.d     $f0, $f0, $f2
/* E2A744 802B6094 44801000 */  mtc1      $zero, $f2
/* E2A748 802B6098 44801800 */  mtc1      $zero, $f3
/* E2A74C 802B609C 00000000 */  nop
/* E2A750 802B60A0 4620103C */  c.lt.d    $f2, $f0
/* E2A754 802B60A4 00000000 */  nop
/* E2A758 802B60A8 45030015 */  bc1tl     .L802B6100
/* E2A75C 802B60AC 0000802D */   daddu    $s0, $zero, $zero
/* E2A760 802B60B0 C64C0028 */  lwc1      $f12, 0x28($s2)
/* E2A764 802B60B4 C64E0030 */  lwc1      $f14, 0x30($s2)
/* E2A768 802B60B8 8E060038 */  lw        $a2, 0x38($s0)
/* E2A76C 802B60BC 0C00A720 */  jal       atan2
/* E2A770 802B60C0 8E070040 */   lw       $a3, 0x40($s0)
/* E2A774 802B60C4 0C00A6C9 */  jal       clamp_angle
/* E2A778 802B60C8 46000306 */   mov.s    $f12, $f0
/* E2A77C 802B60CC 0C0394D2 */  jal       func_800E5348
/* E2A780 802B60D0 46000506 */   mov.s    $f20, $f0
/* E2A784 802B60D4 4600A501 */  sub.s     $f20, $f20, $f0
/* E2A788 802B60D8 3C01403E */  lui       $at, 0x403e
/* E2A78C 802B60DC 44810800 */  mtc1      $at, $f1
/* E2A790 802B60E0 44800000 */  mtc1      $zero, $f0
/* E2A794 802B60E4 4600A521 */  cvt.d.s   $f20, $f20
/* E2A798 802B60E8 4620A505 */  abs.d     $f20, $f20
/* E2A79C 802B60EC 4634003C */  c.lt.d    $f0, $f20
/* E2A7A0 802B60F0 00000000 */  nop
/* E2A7A4 802B60F4 45000003 */  bc1f      .L802B6104
/* E2A7A8 802B60F8 0200102D */   daddu    $v0, $s0, $zero
/* E2A7AC 802B60FC 0000802D */  daddu     $s0, $zero, $zero
.L802B6100:
/* E2A7B0 802B6100 0200102D */  daddu     $v0, $s0, $zero
.L802B6104:
/* E2A7B4 802B6104 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2A7B8 802B6108 8FB20018 */  lw        $s2, 0x18($sp)
/* E2A7BC 802B610C 8FB10014 */  lw        $s1, 0x14($sp)
/* E2A7C0 802B6110 8FB00010 */  lw        $s0, 0x10($sp)
/* E2A7C4 802B6114 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E2A7C8 802B6118 03E00008 */  jr        $ra
/* E2A7CC 802B611C 27BD0028 */   addiu    $sp, $sp, 0x28
