.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E0000
/* 3DB460 E00E0000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3DB464 E00E0004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3DB468 E00E0008 4485A000 */  mtc1      $a1, $f20
/* 3DB46C E00E000C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3DB470 E00E0010 4486B000 */  mtc1      $a2, $f22
/* 3DB474 E00E0014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3DB478 E00E0018 4487C000 */  mtc1      $a3, $f24
/* 3DB47C E00E001C AFB30034 */  sw        $s3, 0x34($sp)
/* 3DB480 E00E0020 0080982D */  daddu     $s3, $a0, $zero
/* 3DB484 E00E0024 AFB00028 */  sw        $s0, 0x28($sp)
/* 3DB488 E00E0028 8FB00074 */  lw        $s0, 0x74($sp)
/* 3DB48C E00E002C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DB490 E00E0030 AFB20030 */  sw        $s2, 0x30($sp)
/* 3DB494 E00E0034 8FB20078 */  lw        $s2, 0x78($sp)
/* 3DB498 E00E0038 3C02E00E */  lui       $v0, %hi(func_E00E01D0)
/* 3DB49C E00E003C 244201D0 */  addiu     $v0, $v0, %lo(func_E00E01D0)
/* 3DB4A0 E00E0040 AFA20018 */  sw        $v0, 0x18($sp)
/* 3DB4A4 E00E0044 3C02E00E */  lui       $v0, %hi(func_E00E01D8)
/* 3DB4A8 E00E0048 244201D8 */  addiu     $v0, $v0, %lo(func_E00E01D8)
/* 3DB4AC E00E004C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DB4B0 E00E0050 3C02E00E */  lui       $v0, %hi(func_E00E05B0)
/* 3DB4B4 E00E0054 244205B0 */  addiu     $v0, $v0, %lo(func_E00E05B0)
/* 3DB4B8 E00E0058 AFA20020 */  sw        $v0, 0x20($sp)
/* 3DB4BC E00E005C 24020070 */  addiu     $v0, $zero, 0x70
/* 3DB4C0 E00E0060 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3DB4C4 E00E0064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3DB4C8 E00E0068 AFA00010 */  sw        $zero, 0x10($sp)
/* 3DB4CC E00E006C AFA00024 */  sw        $zero, 0x24($sp)
/* 3DB4D0 E00E0070 AFA20014 */  sw        $v0, 0x14($sp)
/* 3DB4D4 E00E0074 0C080124 */  jal       func_E0200490
/* 3DB4D8 E00E0078 26100001 */   addiu    $s0, $s0, 1
/* 3DB4DC E00E007C 001020C0 */  sll       $a0, $s0, 3
/* 3DB4E0 E00E0080 00902023 */  subu      $a0, $a0, $s0
/* 3DB4E4 E00E0084 00042100 */  sll       $a0, $a0, 4
/* 3DB4E8 E00E0088 0040882D */  daddu     $s1, $v0, $zero
/* 3DB4EC E00E008C 0C08012C */  jal       func_E02004B0
/* 3DB4F0 E00E0090 AE300008 */   sw       $s0, 8($s1)
/* 3DB4F4 E00E0094 0040202D */  daddu     $a0, $v0, $zero
/* 3DB4F8 E00E0098 14800003 */  bnez      $a0, .LE00E00A8
/* 3DB4FC E00E009C AE24000C */   sw       $a0, 0xc($s1)
.LE00E00A0:
/* 3DB500 E00E00A0 08038028 */  j         .LE00E00A0
/* 3DB504 E00E00A4 00000000 */   nop      
.LE00E00A8:
/* 3DB508 E00E00A8 AC930000 */  sw        $s3, ($a0)
/* 3DB50C E00E00AC 1E400004 */  bgtz      $s2, .LE00E00C0
/* 3DB510 E00E00B0 AC80001C */   sw       $zero, 0x1c($a0)
/* 3DB514 E00E00B4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3DB518 E00E00B8 08038031 */  j         .LE00E00C4
/* 3DB51C E00E00BC AC820018 */   sw       $v0, 0x18($a0)
.LE00E00C0:
/* 3DB520 E00E00C0 AC920018 */  sw        $s2, 0x18($a0)
.LE00E00C4:
/* 3DB524 E00E00C4 AC80002C */  sw        $zero, 0x2c($a0)
/* 3DB528 E00E00C8 E4940004 */  swc1      $f20, 4($a0)
/* 3DB52C E00E00CC E4960008 */  swc1      $f22, 8($a0)
/* 3DB530 E00E00D0 E498000C */  swc1      $f24, 0xc($a0)
/* 3DB534 E00E00D4 C7A00070 */  lwc1      $f0, 0x70($sp)
/* 3DB538 E00E00D8 3C0141F0 */  lui       $at, 0x41f0
/* 3DB53C E00E00DC 44811000 */  mtc1      $at, $f2
/* 3DB540 E00E00E0 E4800040 */  swc1      $f0, 0x40($a0)
/* 3DB544 E00E00E4 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3DB548 E00E00E8 E4800010 */  swc1      $f0, 0x10($a0)
/* 3DB54C E00E00EC C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 3DB550 E00E00F0 E4800014 */  swc1      $f0, 0x14($a0)
/* 3DB554 E00E00F4 C7A0007C */  lwc1      $f0, 0x7c($sp)
/* 3DB558 E00E00F8 2403007F */  addiu     $v1, $zero, 0x7f
/* 3DB55C E00E00FC E4800068 */  swc1      $f0, 0x68($a0)
/* 3DB560 E00E0100 C7A00080 */  lwc1      $f0, 0x80($sp)
/* 3DB564 E00E0104 2602FFFF */  addiu     $v0, $s0, -1
/* 3DB568 E00E0108 AC830020 */  sw        $v1, 0x20($a0)
/* 3DB56C E00E010C AC830030 */  sw        $v1, 0x30($a0)
/* 3DB570 E00E0110 AC830034 */  sw        $v1, 0x34($a0)
/* 3DB574 E00E0114 24030001 */  addiu     $v1, $zero, 1
/* 3DB578 E00E0118 E480006C */  swc1      $f0, 0x6c($a0)
/* 3DB57C E00E011C 44820000 */  mtc1      $v0, $f0
/* 3DB580 E00E0120 00000000 */  nop       
/* 3DB584 E00E0124 46800020 */  cvt.s.w   $f0, $f0
/* 3DB588 E00E0128 46001083 */  div.s     $f2, $f2, $f0
/* 3DB58C E00E012C 3C013FE0 */  lui       $at, 0x3fe0
/* 3DB590 E00E0130 44810800 */  mtc1      $at, $f1
/* 3DB594 E00E0134 44800000 */  mtc1      $zero, $f0
/* 3DB598 E00E0138 460010A1 */  cvt.d.s   $f2, $f2
/* 3DB59C E00E013C 46201082 */  mul.d     $f2, $f2, $f0
/* 3DB5A0 E00E0140 00000000 */  nop       
/* 3DB5A4 E00E0144 AC800024 */  sw        $zero, 0x24($a0)
/* 3DB5A8 E00E0148 AC800028 */  sw        $zero, 0x28($a0)
/* 3DB5AC E00E014C AC800038 */  sw        $zero, 0x38($a0)
/* 3DB5B0 E00E0150 240200FF */  addiu     $v0, $zero, 0xff
/* 3DB5B4 E00E0154 AC82003C */  sw        $v0, 0x3c($a0)
/* 3DB5B8 E00E0158 24840070 */  addiu     $a0, $a0, 0x70
/* 3DB5BC E00E015C 0070102A */  slt       $v0, $v1, $s0
/* 3DB5C0 E00E0160 10400010 */  beqz      $v0, .LE00E01A4
/* 3DB5C4 E00E0164 462010A0 */   cvt.s.d  $f2, $f2
.LE00E0168:
/* 3DB5C8 E00E0168 44830000 */  mtc1      $v1, $f0
/* 3DB5CC E00E016C 00000000 */  nop       
/* 3DB5D0 E00E0170 46800020 */  cvt.s.w   $f0, $f0
/* 3DB5D4 E00E0174 46000007 */  neg.s     $f0, $f0
/* 3DB5D8 E00E0178 46020002 */  mul.s     $f0, $f0, $f2
/* 3DB5DC E00E017C 00000000 */  nop       
/* 3DB5E0 E00E0180 24630001 */  addiu     $v1, $v1, 1
/* 3DB5E4 E00E0184 4600010D */  trunc.w.s $f4, $f0
/* 3DB5E8 E00E0188 44022000 */  mfc1      $v0, $f4
/* 3DB5EC E00E018C 00000000 */  nop       
/* 3DB5F0 E00E0190 2442FFFF */  addiu     $v0, $v0, -1
/* 3DB5F4 E00E0194 AC820064 */  sw        $v0, 0x64($a0)
/* 3DB5F8 E00E0198 0070102A */  slt       $v0, $v1, $s0
/* 3DB5FC E00E019C 1440FFF2 */  bnez      $v0, .LE00E0168
/* 3DB600 E00E01A0 24840070 */   addiu    $a0, $a0, 0x70
.LE00E01A4:
/* 3DB604 E00E01A4 0220102D */  daddu     $v0, $s1, $zero
/* 3DB608 E00E01A8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3DB60C E00E01AC 8FB30034 */  lw        $s3, 0x34($sp)
/* 3DB610 E00E01B0 8FB20030 */  lw        $s2, 0x30($sp)
/* 3DB614 E00E01B4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3DB618 E00E01B8 8FB00028 */  lw        $s0, 0x28($sp)
/* 3DB61C E00E01BC D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3DB620 E00E01C0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3DB624 E00E01C4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3DB628 E00E01C8 03E00008 */  jr        $ra
/* 3DB62C E00E01CC 27BD0058 */   addiu    $sp, $sp, 0x58
