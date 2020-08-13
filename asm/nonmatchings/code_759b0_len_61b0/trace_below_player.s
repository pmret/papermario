.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel trace_below_player
/* 0779FC 800DE54C 27BDFF78 */  addiu $sp, $sp, -0x88
/* 077A00 800DE550 AFB20060 */  sw    $s2, 0x60($sp)
/* 077A04 800DE554 0080902D */  daddu $s2, $a0, $zero
/* 077A08 800DE558 AFB30064 */  sw    $s3, 0x64($sp)
/* 077A0C 800DE55C 00A0982D */  daddu $s3, $a1, $zero
/* 077A10 800DE560 AFB40068 */  sw    $s4, 0x68($sp)
/* 077A14 800DE564 00C0A02D */  daddu $s4, $a2, $zero
/* 077A18 800DE568 AFB5006C */  sw    $s5, 0x6c($sp)
/* 077A1C 800DE56C 00E0A82D */  daddu $s5, $a3, $zero
/* 077A20 800DE570 AFBF0070 */  sw    $ra, 0x70($sp)
/* 077A24 800DE574 AFB1005C */  sw    $s1, 0x5c($sp)
/* 077A28 800DE578 AFB00058 */  sw    $s0, 0x58($sp)
/* 077A2C 800DE57C F7B60080 */  sdc1  $f22, 0x80($sp)
/* 077A30 800DE580 F7B40078 */  sdc1  $f20, 0x78($sp)
/* 077A34 800DE584 C6A20000 */  lwc1  $f2, ($s5)
/* 077A38 800DE588 44802000 */  mtc1  $zero, $f4
/* 077A3C 800DE58C 3C01BF80 */  lui   $at, 0xbf80
/* 077A40 800DE590 44810000 */  mtc1  $at, $f0
/* 077A44 800DE594 27A20038 */  addiu $v0, $sp, 0x38
/* 077A48 800DE598 E7A20044 */  swc1  $f2, 0x44($sp)
/* 077A4C 800DE59C AFA20018 */  sw    $v0, 0x18($sp)
/* 077A50 800DE5A0 27A2003C */  addiu $v0, $sp, 0x3c
/* 077A54 800DE5A4 AFA2001C */  sw    $v0, 0x1c($sp)
/* 077A58 800DE5A8 27A20040 */  addiu $v0, $sp, 0x40
/* 077A5C 800DE5AC AFA20020 */  sw    $v0, 0x20($sp)
/* 077A60 800DE5B0 27A20044 */  addiu $v0, $sp, 0x44
/* 077A64 800DE5B4 AFA20024 */  sw    $v0, 0x24($sp)
/* 077A68 800DE5B8 27A20048 */  addiu $v0, $sp, 0x48
/* 077A6C 800DE5BC AFA20028 */  sw    $v0, 0x28($sp)
/* 077A70 800DE5C0 27A2004C */  addiu $v0, $sp, 0x4c
/* 077A74 800DE5C4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 077A78 800DE5C8 27A20050 */  addiu $v0, $sp, 0x50
/* 077A7C 800DE5CC E7A00010 */  swc1  $f0, 0x10($sp)
/* 077A80 800DE5D0 E7A40014 */  swc1  $f4, 0x14($sp)
/* 077A84 800DE5D4 AFA20030 */  sw    $v0, 0x30($sp)
/* 077A88 800DE5D8 C64C0000 */  lwc1  $f12, ($s2)
/* 077A8C 800DE5DC C66E0000 */  lwc1  $f14, ($s3)
/* 077A90 800DE5E0 8E860000 */  lw    $a2, ($s4)
/* 077A94 800DE5E4 44072000 */  mfc1  $a3, $f4
/* 077A98 800DE5E8 0C017512 */  jal   test_ray_entities
/* 077A9C 800DE5EC 2411FFFF */   addiu $s1, $zero, -1
/* 077AA0 800DE5F0 0040802D */  daddu $s0, $v0, $zero
/* 077AA4 800DE5F4 0600000E */  bltz  $s0, .L800DE630
/* 077AA8 800DE5F8 00000000 */   nop   
/* 077AAC 800DE5FC 0C04417A */  jal   get_entity_by_index
/* 077AB0 800DE600 0200202D */   daddu $a0, $s0, $zero
/* 077AB4 800DE604 0040202D */  daddu $a0, $v0, $zero
/* 077AB8 800DE608 9082000B */  lbu   $v0, 0xb($a0)
/* 077ABC 800DE60C 2C4200FF */  sltiu $v0, $v0, 0xff
/* 077AC0 800DE610 10400006 */  beqz  $v0, .L800DE62C
/* 077AC4 800DE614 24030004 */   addiu $v1, $zero, 4
/* 077AC8 800DE618 8C820000 */  lw    $v0, ($a0)
/* 077ACC 800DE61C A0830007 */  sb    $v1, 7($a0)
/* 077AD0 800DE620 34420040 */  ori   $v0, $v0, 0x40
/* 077AD4 800DE624 0803798C */  j     .L800DE630
/* 077AD8 800DE628 AC820000 */   sw    $v0, ($a0)

.L800DE62C:
/* 077ADC 800DE62C 36114000 */  ori   $s1, $s0, 0x4000
.L800DE630:
/* 077AE0 800DE630 3C01BF80 */  lui   $at, 0xbf80
/* 077AE4 800DE634 44810000 */  mtc1  $at, $f0
/* 077AE8 800DE638 27A20038 */  addiu $v0, $sp, 0x38
/* 077AEC 800DE63C AFA2001C */  sw    $v0, 0x1c($sp)
/* 077AF0 800DE640 27A2003C */  addiu $v0, $sp, 0x3c
/* 077AF4 800DE644 AFA20020 */  sw    $v0, 0x20($sp)
/* 077AF8 800DE648 27A20040 */  addiu $v0, $sp, 0x40
/* 077AFC 800DE64C AFA20024 */  sw    $v0, 0x24($sp)
/* 077B00 800DE650 27A20044 */  addiu $v0, $sp, 0x44
/* 077B04 800DE654 AFA20028 */  sw    $v0, 0x28($sp)
/* 077B08 800DE658 27A20048 */  addiu $v0, $sp, 0x48
/* 077B0C 800DE65C AFA2002C */  sw    $v0, 0x2c($sp)
/* 077B10 800DE660 27A2004C */  addiu $v0, $sp, 0x4c
/* 077B14 800DE664 AFA20030 */  sw    $v0, 0x30($sp)
/* 077B18 800DE668 27A20050 */  addiu $v0, $sp, 0x50
/* 077B1C 800DE66C AFA00010 */  sw    $zero, 0x10($sp)
/* 077B20 800DE670 AFA00018 */  sw    $zero, 0x18($sp)
/* 077B24 800DE674 AFA20034 */  sw    $v0, 0x34($sp)
/* 077B28 800DE678 E7A00014 */  swc1  $f0, 0x14($sp)
/* 077B2C 800DE67C 8E660000 */  lw    $a2, ($s3)
/* 077B30 800DE680 8E870000 */  lw    $a3, ($s4)
/* 077B34 800DE684 8E450000 */  lw    $a1, ($s2)
/* 077B38 800DE688 0C017334 */  jal   test_ray_colliders
/* 077B3C 800DE68C 3C040001 */   lui   $a0, 1
/* 077B40 800DE690 04430001 */  bgezl $v0, .L800DE698
/* 077B44 800DE694 0040882D */   daddu $s1, $v0, $zero
.L800DE698:
/* 077B48 800DE698 06200041 */  bltz  $s1, .L800DE7A0
/* 077B4C 800DE69C 00000000 */   nop   
/* 077B50 800DE6A0 C7A00044 */  lwc1  $f0, 0x44($sp)
/* 077B54 800DE6A4 E6A00000 */  swc1  $f0, ($s5)
/* 077B58 800DE6A8 C7A00038 */  lwc1  $f0, 0x38($sp)
/* 077B5C 800DE6AC E6400000 */  swc1  $f0, ($s2)
/* 077B60 800DE6B0 C7A0003C */  lwc1  $f0, 0x3c($sp)
/* 077B64 800DE6B4 E6600000 */  swc1  $f0, ($s3)
/* 077B68 800DE6B8 C7A00040 */  lwc1  $f0, 0x40($sp)
/* 077B6C 800DE6BC 3C108007 */  lui   $s0, 0x8007
/* 077B70 800DE6C0 2610419C */  addiu $s0, $s0, 0x419c
/* 077B74 800DE6C4 E6800000 */  swc1  $f0, ($s4)
/* 077B78 800DE6C8 8E020000 */  lw    $v0, ($s0)
/* 077B7C 800DE6CC C7A00048 */  lwc1  $f0, 0x48($sp)
/* 077B80 800DE6D0 C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 077B84 800DE6D4 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 077B88 800DE6D8 E4400128 */  swc1  $f0, 0x128($v0)
/* 077B8C 800DE6DC E442012C */  swc1  $f2, 0x12c($v0)
/* 077B90 800DE6E0 0C00A788 */  jal   get_player_normal_yaw
/* 077B94 800DE6E4 E4440130 */   swc1  $f4, 0x130($v0)
/* 077B98 800DE6E8 3C018011 */  lui   $at, 0x8011
/* 077B9C 800DE6EC E420C938 */  swc1  $f0, -0x36c8($at)
/* 077BA0 800DE6F0 0C00A794 */  jal   get_player_normal_pitch
/* 077BA4 800DE6F4 00000000 */   nop   
/* 077BA8 800DE6F8 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 077BAC 800DE6FC 3C014059 */  lui   $at, 0x4059
/* 077BB0 800DE700 4481A800 */  mtc1  $at, $f21
/* 077BB4 800DE704 4480A000 */  mtc1  $zero, $f20
/* 077BB8 800DE708 46002121 */  cvt.d.s $f4, $f4
/* 077BBC 800DE70C 46342102 */  mul.d $f4, $f4, $f20
/* 077BC0 800DE710 00000000 */  nop   
/* 077BC4 800DE714 C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 077BC8 800DE718 460010A1 */  cvt.d.s $f2, $f2
/* 077BCC 800DE71C 46341082 */  mul.d $f2, $f2, $f20
/* 077BD0 800DE720 00000000 */  nop   
/* 077BD4 800DE724 4480B000 */  mtc1  $zero, $f22
/* 077BD8 800DE728 3C018011 */  lui   $at, 0x8011
/* 077BDC 800DE72C E420C990 */  swc1  $f0, -0x3670($at)
/* 077BE0 800DE730 4600B306 */  mov.s $f12, $f22
/* 077BE4 800DE734 46202120 */  cvt.s.d $f4, $f4
/* 077BE8 800DE738 462010A0 */  cvt.s.d $f2, $f2
/* 077BEC 800DE73C 44062000 */  mfc1  $a2, $f4
/* 077BF0 800DE740 44071000 */  mfc1  $a3, $f2
/* 077BF4 800DE744 0C00A720 */  jal   atan2
/* 077BF8 800DE748 4600B386 */   mov.s $f14, $f22
/* 077BFC 800DE74C C7A40048 */  lwc1  $f4, 0x48($sp)
/* 077C00 800DE750 46002121 */  cvt.d.s $f4, $f4
/* 077C04 800DE754 46342102 */  mul.d $f4, $f4, $f20
/* 077C08 800DE758 00000000 */  nop   
/* 077C0C 800DE75C C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 077C10 800DE760 460010A1 */  cvt.d.s $f2, $f2
/* 077C14 800DE764 46341082 */  mul.d $f2, $f2, $f20
/* 077C18 800DE768 00000000 */  nop   
/* 077C1C 800DE76C 4600B306 */  mov.s $f12, $f22
/* 077C20 800DE770 8E020000 */  lw    $v0, ($s0)
/* 077C24 800DE774 46202120 */  cvt.s.d $f4, $f4
/* 077C28 800DE778 462010A0 */  cvt.s.d $f2, $f2
/* 077C2C 800DE77C 44062000 */  mfc1  $a2, $f4
/* 077C30 800DE780 44071000 */  mfc1  $a3, $f2
/* 077C34 800DE784 46006386 */  mov.s $f14, $f12
/* 077C38 800DE788 E440011C */  swc1  $f0, 0x11c($v0)
/* 077C3C 800DE78C 0C00A720 */  jal   atan2
/* 077C40 800DE790 E44C0120 */   swc1  $f12, 0x120($v0)
/* 077C44 800DE794 8E020000 */  lw    $v0, ($s0)
/* 077C48 800DE798 080379ED */  j     .L800DE7B4
/* 077C4C 800DE79C E4400124 */   swc1  $f0, 0x124($v0)

.L800DE7A0:
/* 077C50 800DE7A0 3C028007 */  lui   $v0, 0x8007
/* 077C54 800DE7A4 8C42419C */  lw    $v0, 0x419c($v0)
/* 077C58 800DE7A8 AC40011C */  sw    $zero, 0x11c($v0)
/* 077C5C 800DE7AC AC400120 */  sw    $zero, 0x120($v0)
/* 077C60 800DE7B0 AC400124 */  sw    $zero, 0x124($v0)
.L800DE7B4:
/* 077C64 800DE7B4 0220102D */  daddu $v0, $s1, $zero
/* 077C68 800DE7B8 8FBF0070 */  lw    $ra, 0x70($sp)
/* 077C6C 800DE7BC 8FB5006C */  lw    $s5, 0x6c($sp)
/* 077C70 800DE7C0 8FB40068 */  lw    $s4, 0x68($sp)
/* 077C74 800DE7C4 8FB30064 */  lw    $s3, 0x64($sp)
/* 077C78 800DE7C8 8FB20060 */  lw    $s2, 0x60($sp)
/* 077C7C 800DE7CC 8FB1005C */  lw    $s1, 0x5c($sp)
/* 077C80 800DE7D0 8FB00058 */  lw    $s0, 0x58($sp)
/* 077C84 800DE7D4 D7B60080 */  ldc1  $f22, 0x80($sp)
/* 077C88 800DE7D8 D7B40078 */  ldc1  $f20, 0x78($sp)
/* 077C8C 800DE7DC 03E00008 */  jr    $ra
/* 077C90 800DE7E0 27BD0088 */   addiu $sp, $sp, 0x88

