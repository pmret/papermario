.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DC500
/* 759B0 800DC500 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 759B4 800DC504 AFB00070 */  sw        $s0, 0x70($sp)
/* 759B8 800DC508 0080802D */  daddu     $s0, $a0, $zero
/* 759BC 800DC50C AFB20078 */  sw        $s2, 0x78($sp)
/* 759C0 800DC510 00A0902D */  daddu     $s2, $a1, $zero
/* 759C4 800DC514 AFB3007C */  sw        $s3, 0x7c($sp)
/* 759C8 800DC518 00C0982D */  daddu     $s3, $a2, $zero
/* 759CC 800DC51C AFB40080 */  sw        $s4, 0x80($sp)
/* 759D0 800DC520 00E0A02D */  daddu     $s4, $a3, $zero
/* 759D4 800DC524 AFB50084 */  sw        $s5, 0x84($sp)
/* 759D8 800DC528 8FB500B0 */  lw        $s5, 0xb0($sp)
/* 759DC 800DC52C 27A20038 */  addiu     $v0, $sp, 0x38
/* 759E0 800DC530 AFBF0088 */  sw        $ra, 0x88($sp)
/* 759E4 800DC534 AFB10074 */  sw        $s1, 0x74($sp)
/* 759E8 800DC538 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 759EC 800DC53C F7B40090 */  sdc1      $f20, 0x90($sp)
/* 759F0 800DC540 C6A00000 */  lwc1      $f0, ($s5)
/* 759F4 800DC544 3C01BF80 */  lui       $at, 0xbf80
/* 759F8 800DC548 4481A000 */  mtc1      $at, $f20
/* 759FC 800DC54C 46000005 */  abs.s     $f0, $f0
/* 75A00 800DC550 E7A00044 */  swc1      $f0, 0x44($sp)
/* 75A04 800DC554 E7A00060 */  swc1      $f0, 0x60($sp)
/* 75A08 800DC558 C6440000 */  lwc1      $f4, ($s2)
/* 75A0C 800DC55C C6600000 */  lwc1      $f0, ($s3)
/* 75A10 800DC560 C6820000 */  lwc1      $f2, ($s4)
/* 75A14 800DC564 AFA2001C */  sw        $v0, 0x1c($sp)
/* 75A18 800DC568 27A2003C */  addiu     $v0, $sp, 0x3c
/* 75A1C 800DC56C AFA20020 */  sw        $v0, 0x20($sp)
/* 75A20 800DC570 27A20040 */  addiu     $v0, $sp, 0x40
/* 75A24 800DC574 AFA20024 */  sw        $v0, 0x24($sp)
/* 75A28 800DC578 27A20044 */  addiu     $v0, $sp, 0x44
/* 75A2C 800DC57C AFA20028 */  sw        $v0, 0x28($sp)
/* 75A30 800DC580 27A20048 */  addiu     $v0, $sp, 0x48
/* 75A34 800DC584 AFA2002C */  sw        $v0, 0x2c($sp)
/* 75A38 800DC588 27A2004C */  addiu     $v0, $sp, 0x4c
/* 75A3C 800DC58C AFA20030 */  sw        $v0, 0x30($sp)
/* 75A40 800DC590 44060000 */  mfc1      $a2, $f0
/* 75A44 800DC594 44071000 */  mfc1      $a3, $f2
/* 75A48 800DC598 44052000 */  mfc1      $a1, $f4
/* 75A4C 800DC59C 27A20050 */  addiu     $v0, $sp, 0x50
/* 75A50 800DC5A0 AFA00010 */  sw        $zero, 0x10($sp)
/* 75A54 800DC5A4 E7B40014 */  swc1      $f20, 0x14($sp)
/* 75A58 800DC5A8 AFA00018 */  sw        $zero, 0x18($sp)
/* 75A5C 800DC5AC 0C017334 */  jal       test_ray_colliders
/* 75A60 800DC5B0 AFA20034 */   sw       $v0, 0x34($sp)
/* 75A64 800DC5B4 0040882D */  daddu     $s1, $v0, $zero
/* 75A68 800DC5B8 3C020004 */  lui       $v0, 4
/* 75A6C 800DC5BC 02028024 */  and       $s0, $s0, $v0
/* 75A70 800DC5C0 1600002E */  bnez      $s0, .L800DC67C
/* 75A74 800DC5C4 27A20054 */   addiu    $v0, $sp, 0x54
/* 75A78 800DC5C8 44800000 */  mtc1      $zero, $f0
/* 75A7C 800DC5CC AFA20018 */  sw        $v0, 0x18($sp)
/* 75A80 800DC5D0 27A20058 */  addiu     $v0, $sp, 0x58
/* 75A84 800DC5D4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 75A88 800DC5D8 27A2005C */  addiu     $v0, $sp, 0x5c
/* 75A8C 800DC5DC AFA20020 */  sw        $v0, 0x20($sp)
/* 75A90 800DC5E0 27A20060 */  addiu     $v0, $sp, 0x60
/* 75A94 800DC5E4 AFA20024 */  sw        $v0, 0x24($sp)
/* 75A98 800DC5E8 27A20064 */  addiu     $v0, $sp, 0x64
/* 75A9C 800DC5EC AFA20028 */  sw        $v0, 0x28($sp)
/* 75AA0 800DC5F0 27A20068 */  addiu     $v0, $sp, 0x68
/* 75AA4 800DC5F4 AFA2002C */  sw        $v0, 0x2c($sp)
/* 75AA8 800DC5F8 27A2006C */  addiu     $v0, $sp, 0x6c
/* 75AAC 800DC5FC E7B40010 */  swc1      $f20, 0x10($sp)
/* 75AB0 800DC600 AFA20030 */  sw        $v0, 0x30($sp)
/* 75AB4 800DC604 E7A00014 */  swc1      $f0, 0x14($sp)
/* 75AB8 800DC608 C64C0000 */  lwc1      $f12, ($s2)
/* 75ABC 800DC60C C66E0000 */  lwc1      $f14, ($s3)
/* 75AC0 800DC610 8E860000 */  lw        $a2, ($s4)
/* 75AC4 800DC614 44070000 */  mfc1      $a3, $f0
/* 75AC8 800DC618 0C017512 */  jal       test_ray_entities
/* 75ACC 800DC61C 00000000 */   nop      
/* 75AD0 800DC620 04400014 */  bltz      $v0, .L800DC674
/* 75AD4 800DC624 00000000 */   nop      
/* 75AD8 800DC628 C7AC0060 */  lwc1      $f12, 0x60($sp)
/* 75ADC 800DC62C C7A00044 */  lwc1      $f0, 0x44($sp)
/* 75AE0 800DC630 4600603C */  c.lt.s    $f12, $f0
/* 75AE4 800DC634 00000000 */  nop       
/* 75AE8 800DC638 4500000E */  bc1f      .L800DC674
/* 75AEC 800DC63C 34514000 */   ori      $s1, $v0, 0x4000
/* 75AF0 800DC640 C7A00054 */  lwc1      $f0, 0x54($sp)
/* 75AF4 800DC644 C7A20058 */  lwc1      $f2, 0x58($sp)
/* 75AF8 800DC648 C7A4005C */  lwc1      $f4, 0x5c($sp)
/* 75AFC 800DC64C C7A60064 */  lwc1      $f6, 0x64($sp)
/* 75B00 800DC650 C7A80068 */  lwc1      $f8, 0x68($sp)
/* 75B04 800DC654 C7AA006C */  lwc1      $f10, 0x6c($sp)
/* 75B08 800DC658 E7AC0044 */  swc1      $f12, 0x44($sp)
/* 75B0C 800DC65C E7A00038 */  swc1      $f0, 0x38($sp)
/* 75B10 800DC660 E7A2003C */  swc1      $f2, 0x3c($sp)
/* 75B14 800DC664 E7A40040 */  swc1      $f4, 0x40($sp)
/* 75B18 800DC668 E7A60048 */  swc1      $f6, 0x48($sp)
/* 75B1C 800DC66C E7A8004C */  swc1      $f8, 0x4c($sp)
/* 75B20 800DC670 E7AA0050 */  swc1      $f10, 0x50($sp)
.L800DC674:
/* 75B24 800DC674 06200035 */  bltz      $s1, .L800DC74C
/* 75B28 800DC678 0220102D */   daddu    $v0, $s1, $zero
.L800DC67C:
/* 75B2C 800DC67C C7A00044 */  lwc1      $f0, 0x44($sp)
/* 75B30 800DC680 E6A00000 */  swc1      $f0, ($s5)
/* 75B34 800DC684 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 75B38 800DC688 E6400000 */  swc1      $f0, ($s2)
/* 75B3C 800DC68C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 75B40 800DC690 E6600000 */  swc1      $f0, ($s3)
/* 75B44 800DC694 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 75B48 800DC698 0620002B */  bltz      $s1, .L800DC748
/* 75B4C 800DC69C E6800000 */   swc1     $f0, ($s4)
/* 75B50 800DC6A0 C7A40050 */  lwc1      $f4, 0x50($sp)
/* 75B54 800DC6A4 3C0142C8 */  lui       $at, 0x42c8
/* 75B58 800DC6A8 4481A000 */  mtc1      $at, $f20
/* 75B5C 800DC6AC 00000000 */  nop       
/* 75B60 800DC6B0 46142402 */  mul.s     $f16, $f4, $f20
/* 75B64 800DC6B4 00000000 */  nop       
/* 75B68 800DC6B8 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 75B6C 800DC6BC 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 75B70 800DC6C0 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 75B74 800DC6C4 44068000 */  mfc1      $a2, $f16
/* 75B78 800DC6C8 46141402 */  mul.s     $f16, $f2, $f20
/* 75B7C 800DC6CC 00000000 */  nop       
/* 75B80 800DC6D0 4480B000 */  mtc1      $zero, $f22
/* 75B84 800DC6D4 8E020000 */  lw        $v0, ($s0)
/* 75B88 800DC6D8 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 75B8C 800DC6DC 4600B306 */  mov.s     $f12, $f22
/* 75B90 800DC6E0 44078000 */  mfc1      $a3, $f16
/* 75B94 800DC6E4 4600B386 */  mov.s     $f14, $f22
/* 75B98 800DC6E8 E4400128 */  swc1      $f0, 0x128($v0)
/* 75B9C 800DC6EC E442012C */  swc1      $f2, 0x12c($v0)
/* 75BA0 800DC6F0 0C00A720 */  jal       atan2
/* 75BA4 800DC6F4 E4440130 */   swc1     $f4, 0x130($v0)
/* 75BA8 800DC6F8 C7A20048 */  lwc1      $f2, 0x48($sp)
/* 75BAC 800DC6FC 46141082 */  mul.s     $f2, $f2, $f20
/* 75BB0 800DC700 00000000 */  nop       
/* 75BB4 800DC704 44061000 */  mfc1      $a2, $f2
/* 75BB8 800DC708 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 75BBC 800DC70C 46141082 */  mul.s     $f2, $f2, $f20
/* 75BC0 800DC710 00000000 */  nop       
/* 75BC4 800DC714 4600B306 */  mov.s     $f12, $f22
/* 75BC8 800DC718 46006386 */  mov.s     $f14, $f12
/* 75BCC 800DC71C 8E020000 */  lw        $v0, ($s0)
/* 75BD0 800DC720 44071000 */  mfc1      $a3, $f2
/* 75BD4 800DC724 46000007 */  neg.s     $f0, $f0
/* 75BD8 800DC728 E440011C */  swc1      $f0, 0x11c($v0)
/* 75BDC 800DC72C 0C00A720 */  jal       atan2
/* 75BE0 800DC730 E44C0120 */   swc1     $f12, 0x120($v0)
/* 75BE4 800DC734 0220102D */  daddu     $v0, $s1, $zero
/* 75BE8 800DC738 8E030000 */  lw        $v1, ($s0)
/* 75BEC 800DC73C 46000007 */  neg.s     $f0, $f0
/* 75BF0 800DC740 080371D3 */  j         .L800DC74C
/* 75BF4 800DC744 E4600124 */   swc1     $f0, 0x124($v1)
.L800DC748:
/* 75BF8 800DC748 0220102D */  daddu     $v0, $s1, $zero
.L800DC74C:
/* 75BFC 800DC74C 8FBF0088 */  lw        $ra, 0x88($sp)
/* 75C00 800DC750 8FB50084 */  lw        $s5, 0x84($sp)
/* 75C04 800DC754 8FB40080 */  lw        $s4, 0x80($sp)
/* 75C08 800DC758 8FB3007C */  lw        $s3, 0x7c($sp)
/* 75C0C 800DC75C 8FB20078 */  lw        $s2, 0x78($sp)
/* 75C10 800DC760 8FB10074 */  lw        $s1, 0x74($sp)
/* 75C14 800DC764 8FB00070 */  lw        $s0, 0x70($sp)
/* 75C18 800DC768 D7B60098 */  ldc1      $f22, 0x98($sp)
/* 75C1C 800DC76C D7B40090 */  ldc1      $f20, 0x90($sp)
/* 75C20 800DC770 03E00008 */  jr        $ra
/* 75C24 800DC774 27BD00A0 */   addiu    $sp, $sp, 0xa0
