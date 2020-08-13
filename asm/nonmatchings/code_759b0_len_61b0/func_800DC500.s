.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DC500
/* 0759B0 800DC500 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 0759B4 800DC504 AFB00070 */  sw    $s0, 0x70($sp)
/* 0759B8 800DC508 0080802D */  daddu $s0, $a0, $zero
/* 0759BC 800DC50C AFB20078 */  sw    $s2, 0x78($sp)
/* 0759C0 800DC510 00A0902D */  daddu $s2, $a1, $zero
/* 0759C4 800DC514 AFB3007C */  sw    $s3, 0x7c($sp)
/* 0759C8 800DC518 00C0982D */  daddu $s3, $a2, $zero
/* 0759CC 800DC51C AFB40080 */  sw    $s4, 0x80($sp)
/* 0759D0 800DC520 00E0A02D */  daddu $s4, $a3, $zero
/* 0759D4 800DC524 AFB50084 */  sw    $s5, 0x84($sp)
/* 0759D8 800DC528 8FB500B0 */  lw    $s5, 0xb0($sp)
/* 0759DC 800DC52C 27A20038 */  addiu $v0, $sp, 0x38
/* 0759E0 800DC530 AFBF0088 */  sw    $ra, 0x88($sp)
/* 0759E4 800DC534 AFB10074 */  sw    $s1, 0x74($sp)
/* 0759E8 800DC538 F7B60098 */  sdc1  $f22, 0x98($sp)
/* 0759EC 800DC53C F7B40090 */  sdc1  $f20, 0x90($sp)
/* 0759F0 800DC540 C6A00000 */  lwc1  $f0, ($s5)
/* 0759F4 800DC544 3C01BF80 */  lui   $at, 0xbf80
/* 0759F8 800DC548 4481A000 */  mtc1  $at, $f20
/* 0759FC 800DC54C 46000005 */  abs.s $f0, $f0
/* 075A00 800DC550 E7A00044 */  swc1  $f0, 0x44($sp)
/* 075A04 800DC554 E7A00060 */  swc1  $f0, 0x60($sp)
/* 075A08 800DC558 C6440000 */  lwc1  $f4, ($s2)
/* 075A0C 800DC55C C6600000 */  lwc1  $f0, ($s3)
/* 075A10 800DC560 C6820000 */  lwc1  $f2, ($s4)
/* 075A14 800DC564 AFA2001C */  sw    $v0, 0x1c($sp)
/* 075A18 800DC568 27A2003C */  addiu $v0, $sp, 0x3c
/* 075A1C 800DC56C AFA20020 */  sw    $v0, 0x20($sp)
/* 075A20 800DC570 27A20040 */  addiu $v0, $sp, 0x40
/* 075A24 800DC574 AFA20024 */  sw    $v0, 0x24($sp)
/* 075A28 800DC578 27A20044 */  addiu $v0, $sp, 0x44
/* 075A2C 800DC57C AFA20028 */  sw    $v0, 0x28($sp)
/* 075A30 800DC580 27A20048 */  addiu $v0, $sp, 0x48
/* 075A34 800DC584 AFA2002C */  sw    $v0, 0x2c($sp)
/* 075A38 800DC588 27A2004C */  addiu $v0, $sp, 0x4c
/* 075A3C 800DC58C AFA20030 */  sw    $v0, 0x30($sp)
/* 075A40 800DC590 44060000 */  mfc1  $a2, $f0
/* 075A44 800DC594 44071000 */  mfc1  $a3, $f2
/* 075A48 800DC598 44052000 */  mfc1  $a1, $f4
/* 075A4C 800DC59C 27A20050 */  addiu $v0, $sp, 0x50
/* 075A50 800DC5A0 AFA00010 */  sw    $zero, 0x10($sp)
/* 075A54 800DC5A4 E7B40014 */  swc1  $f20, 0x14($sp)
/* 075A58 800DC5A8 AFA00018 */  sw    $zero, 0x18($sp)
/* 075A5C 800DC5AC 0C017334 */  jal   test_ray_colliders
/* 075A60 800DC5B0 AFA20034 */   sw    $v0, 0x34($sp)
/* 075A64 800DC5B4 0040882D */  daddu $s1, $v0, $zero
/* 075A68 800DC5B8 3C020004 */  lui   $v0, 4
/* 075A6C 800DC5BC 02028024 */  and   $s0, $s0, $v0
/* 075A70 800DC5C0 1600002E */  bnez  $s0, .L800DC67C
/* 075A74 800DC5C4 27A20054 */   addiu $v0, $sp, 0x54
/* 075A78 800DC5C8 44800000 */  mtc1  $zero, $f0
/* 075A7C 800DC5CC AFA20018 */  sw    $v0, 0x18($sp)
/* 075A80 800DC5D0 27A20058 */  addiu $v0, $sp, 0x58
/* 075A84 800DC5D4 AFA2001C */  sw    $v0, 0x1c($sp)
/* 075A88 800DC5D8 27A2005C */  addiu $v0, $sp, 0x5c
/* 075A8C 800DC5DC AFA20020 */  sw    $v0, 0x20($sp)
/* 075A90 800DC5E0 27A20060 */  addiu $v0, $sp, 0x60
/* 075A94 800DC5E4 AFA20024 */  sw    $v0, 0x24($sp)
/* 075A98 800DC5E8 27A20064 */  addiu $v0, $sp, 0x64
/* 075A9C 800DC5EC AFA20028 */  sw    $v0, 0x28($sp)
/* 075AA0 800DC5F0 27A20068 */  addiu $v0, $sp, 0x68
/* 075AA4 800DC5F4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 075AA8 800DC5F8 27A2006C */  addiu $v0, $sp, 0x6c
/* 075AAC 800DC5FC E7B40010 */  swc1  $f20, 0x10($sp)
/* 075AB0 800DC600 AFA20030 */  sw    $v0, 0x30($sp)
/* 075AB4 800DC604 E7A00014 */  swc1  $f0, 0x14($sp)
/* 075AB8 800DC608 C64C0000 */  lwc1  $f12, ($s2)
/* 075ABC 800DC60C C66E0000 */  lwc1  $f14, ($s3)
/* 075AC0 800DC610 8E860000 */  lw    $a2, ($s4)
/* 075AC4 800DC614 44070000 */  mfc1  $a3, $f0
/* 075AC8 800DC618 0C017512 */  jal   test_ray_entities
/* 075ACC 800DC61C 00000000 */   nop   
/* 075AD0 800DC620 04400014 */  bltz  $v0, .L800DC674
/* 075AD4 800DC624 00000000 */   nop   
/* 075AD8 800DC628 C7AC0060 */  lwc1  $f12, 0x60($sp)
/* 075ADC 800DC62C C7A00044 */  lwc1  $f0, 0x44($sp)
/* 075AE0 800DC630 4600603C */  c.lt.s $f12, $f0
/* 075AE4 800DC634 00000000 */  nop   
/* 075AE8 800DC638 4500000E */  bc1f  .L800DC674
/* 075AEC 800DC63C 34514000 */   ori   $s1, $v0, 0x4000
/* 075AF0 800DC640 C7A00054 */  lwc1  $f0, 0x54($sp)
/* 075AF4 800DC644 C7A20058 */  lwc1  $f2, 0x58($sp)
/* 075AF8 800DC648 C7A4005C */  lwc1  $f4, 0x5c($sp)
/* 075AFC 800DC64C C7A60064 */  lwc1  $f6, 0x64($sp)
/* 075B00 800DC650 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 075B04 800DC654 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 075B08 800DC658 E7AC0044 */  swc1  $f12, 0x44($sp)
/* 075B0C 800DC65C E7A00038 */  swc1  $f0, 0x38($sp)
/* 075B10 800DC660 E7A2003C */  swc1  $f2, 0x3c($sp)
/* 075B14 800DC664 E7A40040 */  swc1  $f4, 0x40($sp)
/* 075B18 800DC668 E7A60048 */  swc1  $f6, 0x48($sp)
/* 075B1C 800DC66C E7A8004C */  swc1  $f8, 0x4c($sp)
/* 075B20 800DC670 E7AA0050 */  swc1  $f10, 0x50($sp)
.L800DC674:
/* 075B24 800DC674 06200035 */  bltz  $s1, .L800DC74C
/* 075B28 800DC678 0220102D */   daddu $v0, $s1, $zero
.L800DC67C:
/* 075B2C 800DC67C C7A00044 */  lwc1  $f0, 0x44($sp)
/* 075B30 800DC680 E6A00000 */  swc1  $f0, ($s5)
/* 075B34 800DC684 C7A00038 */  lwc1  $f0, 0x38($sp)
/* 075B38 800DC688 E6400000 */  swc1  $f0, ($s2)
/* 075B3C 800DC68C C7A0003C */  lwc1  $f0, 0x3c($sp)
/* 075B40 800DC690 E6600000 */  swc1  $f0, ($s3)
/* 075B44 800DC694 C7A00040 */  lwc1  $f0, 0x40($sp)
/* 075B48 800DC698 0620002B */  bltz  $s1, .L800DC748
/* 075B4C 800DC69C E6800000 */   swc1  $f0, ($s4)
/* 075B50 800DC6A0 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 075B54 800DC6A4 3C0142C8 */  lui   $at, 0x42c8
/* 075B58 800DC6A8 4481A000 */  mtc1  $at, $f20
/* 075B5C 800DC6AC 00000000 */  nop   
/* 075B60 800DC6B0 46142402 */  mul.s $f16, $f4, $f20
/* 075B64 800DC6B4 00000000 */  nop   
/* 075B68 800DC6B8 3C108007 */  lui   $s0, 0x8007
/* 075B6C 800DC6BC 2610419C */  addiu $s0, $s0, 0x419c
/* 075B70 800DC6C0 C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 075B74 800DC6C4 44068000 */  mfc1  $a2, $f16
/* 075B78 800DC6C8 46141402 */  mul.s $f16, $f2, $f20
/* 075B7C 800DC6CC 00000000 */  nop   
/* 075B80 800DC6D0 4480B000 */  mtc1  $zero, $f22
/* 075B84 800DC6D4 8E020000 */  lw    $v0, ($s0)
/* 075B88 800DC6D8 C7A00048 */  lwc1  $f0, 0x48($sp)
/* 075B8C 800DC6DC 4600B306 */  mov.s $f12, $f22
/* 075B90 800DC6E0 44078000 */  mfc1  $a3, $f16
/* 075B94 800DC6E4 4600B386 */  mov.s $f14, $f22
/* 075B98 800DC6E8 E4400128 */  swc1  $f0, 0x128($v0)
/* 075B9C 800DC6EC E442012C */  swc1  $f2, 0x12c($v0)
/* 075BA0 800DC6F0 0C00A720 */  jal   atan2
/* 075BA4 800DC6F4 E4440130 */   swc1  $f4, 0x130($v0)
/* 075BA8 800DC6F8 C7A20048 */  lwc1  $f2, 0x48($sp)
/* 075BAC 800DC6FC 46141082 */  mul.s $f2, $f2, $f20
/* 075BB0 800DC700 00000000 */  nop   
/* 075BB4 800DC704 44061000 */  mfc1  $a2, $f2
/* 075BB8 800DC708 C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 075BBC 800DC70C 46141082 */  mul.s $f2, $f2, $f20
/* 075BC0 800DC710 00000000 */  nop   
/* 075BC4 800DC714 4600B306 */  mov.s $f12, $f22
/* 075BC8 800DC718 46006386 */  mov.s $f14, $f12
/* 075BCC 800DC71C 8E020000 */  lw    $v0, ($s0)
/* 075BD0 800DC720 44071000 */  mfc1  $a3, $f2
/* 075BD4 800DC724 46000007 */  neg.s $f0, $f0
/* 075BD8 800DC728 E440011C */  swc1  $f0, 0x11c($v0)
/* 075BDC 800DC72C 0C00A720 */  jal   atan2
/* 075BE0 800DC730 E44C0120 */   swc1  $f12, 0x120($v0)
/* 075BE4 800DC734 0220102D */  daddu $v0, $s1, $zero
/* 075BE8 800DC738 8E030000 */  lw    $v1, ($s0)
/* 075BEC 800DC73C 46000007 */  neg.s $f0, $f0
/* 075BF0 800DC740 080371D3 */  j     .L800DC74C
/* 075BF4 800DC744 E4600124 */   swc1  $f0, 0x124($v1)

.L800DC748:
/* 075BF8 800DC748 0220102D */  daddu $v0, $s1, $zero
.L800DC74C:
/* 075BFC 800DC74C 8FBF0088 */  lw    $ra, 0x88($sp)
/* 075C00 800DC750 8FB50084 */  lw    $s5, 0x84($sp)
/* 075C04 800DC754 8FB40080 */  lw    $s4, 0x80($sp)
/* 075C08 800DC758 8FB3007C */  lw    $s3, 0x7c($sp)
/* 075C0C 800DC75C 8FB20078 */  lw    $s2, 0x78($sp)
/* 075C10 800DC760 8FB10074 */  lw    $s1, 0x74($sp)
/* 075C14 800DC764 8FB00070 */  lw    $s0, 0x70($sp)
/* 075C18 800DC768 D7B60098 */  ldc1  $f22, 0x98($sp)
/* 075C1C 800DC76C D7B40090 */  ldc1  $f20, 0x90($sp)
/* 075C20 800DC770 03E00008 */  jr    $ra
/* 075C24 800DC774 27BD00A0 */   addiu $sp, $sp, 0xa0

