.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trace_below_player
/* 779FC 800DE54C 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 77A00 800DE550 AFB20060 */  sw        $s2, 0x60($sp)
/* 77A04 800DE554 0080902D */  daddu     $s2, $a0, $zero
/* 77A08 800DE558 AFB30064 */  sw        $s3, 0x64($sp)
/* 77A0C 800DE55C 00A0982D */  daddu     $s3, $a1, $zero
/* 77A10 800DE560 AFB40068 */  sw        $s4, 0x68($sp)
/* 77A14 800DE564 00C0A02D */  daddu     $s4, $a2, $zero
/* 77A18 800DE568 AFB5006C */  sw        $s5, 0x6c($sp)
/* 77A1C 800DE56C 00E0A82D */  daddu     $s5, $a3, $zero
/* 77A20 800DE570 AFBF0070 */  sw        $ra, 0x70($sp)
/* 77A24 800DE574 AFB1005C */  sw        $s1, 0x5c($sp)
/* 77A28 800DE578 AFB00058 */  sw        $s0, 0x58($sp)
/* 77A2C 800DE57C F7B60080 */  sdc1      $f22, 0x80($sp)
/* 77A30 800DE580 F7B40078 */  sdc1      $f20, 0x78($sp)
/* 77A34 800DE584 C6A20000 */  lwc1      $f2, ($s5)
/* 77A38 800DE588 44802000 */  mtc1      $zero, $f4
/* 77A3C 800DE58C 3C01BF80 */  lui       $at, 0xbf80
/* 77A40 800DE590 44810000 */  mtc1      $at, $f0
/* 77A44 800DE594 27A20038 */  addiu     $v0, $sp, 0x38
/* 77A48 800DE598 E7A20044 */  swc1      $f2, 0x44($sp)
/* 77A4C 800DE59C AFA20018 */  sw        $v0, 0x18($sp)
/* 77A50 800DE5A0 27A2003C */  addiu     $v0, $sp, 0x3c
/* 77A54 800DE5A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 77A58 800DE5A8 27A20040 */  addiu     $v0, $sp, 0x40
/* 77A5C 800DE5AC AFA20020 */  sw        $v0, 0x20($sp)
/* 77A60 800DE5B0 27A20044 */  addiu     $v0, $sp, 0x44
/* 77A64 800DE5B4 AFA20024 */  sw        $v0, 0x24($sp)
/* 77A68 800DE5B8 27A20048 */  addiu     $v0, $sp, 0x48
/* 77A6C 800DE5BC AFA20028 */  sw        $v0, 0x28($sp)
/* 77A70 800DE5C0 27A2004C */  addiu     $v0, $sp, 0x4c
/* 77A74 800DE5C4 AFA2002C */  sw        $v0, 0x2c($sp)
/* 77A78 800DE5C8 27A20050 */  addiu     $v0, $sp, 0x50
/* 77A7C 800DE5CC E7A00010 */  swc1      $f0, 0x10($sp)
/* 77A80 800DE5D0 E7A40014 */  swc1      $f4, 0x14($sp)
/* 77A84 800DE5D4 AFA20030 */  sw        $v0, 0x30($sp)
/* 77A88 800DE5D8 C64C0000 */  lwc1      $f12, ($s2)
/* 77A8C 800DE5DC C66E0000 */  lwc1      $f14, ($s3)
/* 77A90 800DE5E0 8E860000 */  lw        $a2, ($s4)
/* 77A94 800DE5E4 44072000 */  mfc1      $a3, $f4
/* 77A98 800DE5E8 0C017512 */  jal       test_ray_entities
/* 77A9C 800DE5EC 2411FFFF */   addiu    $s1, $zero, -1
/* 77AA0 800DE5F0 0040802D */  daddu     $s0, $v0, $zero
/* 77AA4 800DE5F4 0600000E */  bltz      $s0, .L800DE630
/* 77AA8 800DE5F8 00000000 */   nop      
/* 77AAC 800DE5FC 0C04417A */  jal       get_entity_by_index
/* 77AB0 800DE600 0200202D */   daddu    $a0, $s0, $zero
/* 77AB4 800DE604 0040202D */  daddu     $a0, $v0, $zero
/* 77AB8 800DE608 9082000B */  lbu       $v0, 0xb($a0)
/* 77ABC 800DE60C 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 77AC0 800DE610 10400006 */  beqz      $v0, .L800DE62C
/* 77AC4 800DE614 24030004 */   addiu    $v1, $zero, 4
/* 77AC8 800DE618 8C820000 */  lw        $v0, ($a0)
/* 77ACC 800DE61C A0830007 */  sb        $v1, 7($a0)
/* 77AD0 800DE620 34420040 */  ori       $v0, $v0, 0x40
/* 77AD4 800DE624 0803798C */  j         .L800DE630
/* 77AD8 800DE628 AC820000 */   sw       $v0, ($a0)
.L800DE62C:
/* 77ADC 800DE62C 36114000 */  ori       $s1, $s0, 0x4000
.L800DE630:
/* 77AE0 800DE630 3C01BF80 */  lui       $at, 0xbf80
/* 77AE4 800DE634 44810000 */  mtc1      $at, $f0
/* 77AE8 800DE638 27A20038 */  addiu     $v0, $sp, 0x38
/* 77AEC 800DE63C AFA2001C */  sw        $v0, 0x1c($sp)
/* 77AF0 800DE640 27A2003C */  addiu     $v0, $sp, 0x3c
/* 77AF4 800DE644 AFA20020 */  sw        $v0, 0x20($sp)
/* 77AF8 800DE648 27A20040 */  addiu     $v0, $sp, 0x40
/* 77AFC 800DE64C AFA20024 */  sw        $v0, 0x24($sp)
/* 77B00 800DE650 27A20044 */  addiu     $v0, $sp, 0x44
/* 77B04 800DE654 AFA20028 */  sw        $v0, 0x28($sp)
/* 77B08 800DE658 27A20048 */  addiu     $v0, $sp, 0x48
/* 77B0C 800DE65C AFA2002C */  sw        $v0, 0x2c($sp)
/* 77B10 800DE660 27A2004C */  addiu     $v0, $sp, 0x4c
/* 77B14 800DE664 AFA20030 */  sw        $v0, 0x30($sp)
/* 77B18 800DE668 27A20050 */  addiu     $v0, $sp, 0x50
/* 77B1C 800DE66C AFA00010 */  sw        $zero, 0x10($sp)
/* 77B20 800DE670 AFA00018 */  sw        $zero, 0x18($sp)
/* 77B24 800DE674 AFA20034 */  sw        $v0, 0x34($sp)
/* 77B28 800DE678 E7A00014 */  swc1      $f0, 0x14($sp)
/* 77B2C 800DE67C 8E660000 */  lw        $a2, ($s3)
/* 77B30 800DE680 8E870000 */  lw        $a3, ($s4)
/* 77B34 800DE684 8E450000 */  lw        $a1, ($s2)
/* 77B38 800DE688 0C017334 */  jal       test_ray_colliders
/* 77B3C 800DE68C 3C040001 */   lui      $a0, 1
/* 77B40 800DE690 04430001 */  bgezl     $v0, .L800DE698
/* 77B44 800DE694 0040882D */   daddu    $s1, $v0, $zero
.L800DE698:
/* 77B48 800DE698 06200041 */  bltz      $s1, .L800DE7A0
/* 77B4C 800DE69C 00000000 */   nop      
/* 77B50 800DE6A0 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 77B54 800DE6A4 E6A00000 */  swc1      $f0, ($s5)
/* 77B58 800DE6A8 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 77B5C 800DE6AC E6400000 */  swc1      $f0, ($s2)
/* 77B60 800DE6B0 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 77B64 800DE6B4 E6600000 */  swc1      $f0, ($s3)
/* 77B68 800DE6B8 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 77B6C 800DE6BC 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 77B70 800DE6C0 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 77B74 800DE6C4 E6800000 */  swc1      $f0, ($s4)
/* 77B78 800DE6C8 8E020000 */  lw        $v0, ($s0)
/* 77B7C 800DE6CC C7A00048 */  lwc1      $f0, 0x48($sp)
/* 77B80 800DE6D0 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 77B84 800DE6D4 C7A40050 */  lwc1      $f4, 0x50($sp)
/* 77B88 800DE6D8 E4400128 */  swc1      $f0, 0x128($v0)
/* 77B8C 800DE6DC E442012C */  swc1      $f2, 0x12c($v0)
/* 77B90 800DE6E0 0C00A788 */  jal       get_player_normal_yaw
/* 77B94 800DE6E4 E4440130 */   swc1     $f4, 0x130($v0)
/* 77B98 800DE6E8 3C018011 */  lui       $at, 0x8011
/* 77B9C 800DE6EC E420C938 */  swc1      $f0, -0x36c8($at)
/* 77BA0 800DE6F0 0C00A794 */  jal       get_player_normal_pitch
/* 77BA4 800DE6F4 00000000 */   nop      
/* 77BA8 800DE6F8 C7A40050 */  lwc1      $f4, 0x50($sp)
/* 77BAC 800DE6FC 3C014059 */  lui       $at, 0x4059
/* 77BB0 800DE700 4481A800 */  mtc1      $at, $f21
/* 77BB4 800DE704 4480A000 */  mtc1      $zero, $f20
/* 77BB8 800DE708 46002121 */  cvt.d.s   $f4, $f4
/* 77BBC 800DE70C 46342102 */  mul.d     $f4, $f4, $f20
/* 77BC0 800DE710 00000000 */  nop       
/* 77BC4 800DE714 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 77BC8 800DE718 460010A1 */  cvt.d.s   $f2, $f2
/* 77BCC 800DE71C 46341082 */  mul.d     $f2, $f2, $f20
/* 77BD0 800DE720 00000000 */  nop       
/* 77BD4 800DE724 4480B000 */  mtc1      $zero, $f22
/* 77BD8 800DE728 3C018011 */  lui       $at, 0x8011
/* 77BDC 800DE72C E420C990 */  swc1      $f0, -0x3670($at)
/* 77BE0 800DE730 4600B306 */  mov.s     $f12, $f22
/* 77BE4 800DE734 46202120 */  cvt.s.d   $f4, $f4
/* 77BE8 800DE738 462010A0 */  cvt.s.d   $f2, $f2
/* 77BEC 800DE73C 44062000 */  mfc1      $a2, $f4
/* 77BF0 800DE740 44071000 */  mfc1      $a3, $f2
/* 77BF4 800DE744 0C00A720 */  jal       atan2
/* 77BF8 800DE748 4600B386 */   mov.s    $f14, $f22
/* 77BFC 800DE74C C7A40048 */  lwc1      $f4, 0x48($sp)
/* 77C00 800DE750 46002121 */  cvt.d.s   $f4, $f4
/* 77C04 800DE754 46342102 */  mul.d     $f4, $f4, $f20
/* 77C08 800DE758 00000000 */  nop       
/* 77C0C 800DE75C C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 77C10 800DE760 460010A1 */  cvt.d.s   $f2, $f2
/* 77C14 800DE764 46341082 */  mul.d     $f2, $f2, $f20
/* 77C18 800DE768 00000000 */  nop       
/* 77C1C 800DE76C 4600B306 */  mov.s     $f12, $f22
/* 77C20 800DE770 8E020000 */  lw        $v0, ($s0)
/* 77C24 800DE774 46202120 */  cvt.s.d   $f4, $f4
/* 77C28 800DE778 462010A0 */  cvt.s.d   $f2, $f2
/* 77C2C 800DE77C 44062000 */  mfc1      $a2, $f4
/* 77C30 800DE780 44071000 */  mfc1      $a3, $f2
/* 77C34 800DE784 46006386 */  mov.s     $f14, $f12
/* 77C38 800DE788 E440011C */  swc1      $f0, 0x11c($v0)
/* 77C3C 800DE78C 0C00A720 */  jal       atan2
/* 77C40 800DE790 E44C0120 */   swc1     $f12, 0x120($v0)
/* 77C44 800DE794 8E020000 */  lw        $v0, ($s0)
/* 77C48 800DE798 080379ED */  j         .L800DE7B4
/* 77C4C 800DE79C E4400124 */   swc1     $f0, 0x124($v0)
.L800DE7A0:
/* 77C50 800DE7A0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 77C54 800DE7A4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 77C58 800DE7A8 AC40011C */  sw        $zero, 0x11c($v0)
/* 77C5C 800DE7AC AC400120 */  sw        $zero, 0x120($v0)
/* 77C60 800DE7B0 AC400124 */  sw        $zero, 0x124($v0)
.L800DE7B4:
/* 77C64 800DE7B4 0220102D */  daddu     $v0, $s1, $zero
/* 77C68 800DE7B8 8FBF0070 */  lw        $ra, 0x70($sp)
/* 77C6C 800DE7BC 8FB5006C */  lw        $s5, 0x6c($sp)
/* 77C70 800DE7C0 8FB40068 */  lw        $s4, 0x68($sp)
/* 77C74 800DE7C4 8FB30064 */  lw        $s3, 0x64($sp)
/* 77C78 800DE7C8 8FB20060 */  lw        $s2, 0x60($sp)
/* 77C7C 800DE7CC 8FB1005C */  lw        $s1, 0x5c($sp)
/* 77C80 800DE7D0 8FB00058 */  lw        $s0, 0x58($sp)
/* 77C84 800DE7D4 D7B60080 */  ldc1      $f22, 0x80($sp)
/* 77C88 800DE7D8 D7B40078 */  ldc1      $f20, 0x78($sp)
/* 77C8C 800DE7DC 03E00008 */  jr        $ra
/* 77C90 800DE7E0 27BD0088 */   addiu    $sp, $sp, 0x88
