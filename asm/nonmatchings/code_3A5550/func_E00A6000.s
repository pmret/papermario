.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A6000
/* 3A5550 E00A6000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3A5554 E00A6004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3A5558 E00A6008 4485A000 */  mtc1      $a1, $f20
/* 3A555C E00A600C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3A5560 E00A6010 0080882D */  daddu     $s1, $a0, $zero
/* 3A5564 E00A6014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3A5568 E00A6018 4486B000 */  mtc1      $a2, $f22
/* 3A556C E00A601C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A5570 E00A6020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3A5574 E00A6024 4487C000 */  mtc1      $a3, $f24
/* 3A5578 E00A6028 3C02E00A */  lui       $v0, %hi(func_E00A611C)
/* 3A557C E00A602C 2442611C */  addiu     $v0, $v0, %lo(func_E00A611C)
/* 3A5580 E00A6030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3A5584 E00A6034 3C02E00A */  lui       $v0, %hi(func_E00A6124)
/* 3A5588 E00A6038 24426124 */  addiu     $v0, $v0, %lo(func_E00A6124)
/* 3A558C E00A603C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A5590 E00A6040 3C02E00A */  lui       $v0, %hi(func_E00A6358)
/* 3A5594 E00A6044 24426358 */  addiu     $v0, $v0, %lo(func_E00A6358)
/* 3A5598 E00A6048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A559C E00A604C 24020053 */  addiu     $v0, $zero, 0x53
/* 3A55A0 E00A6050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3A55A4 E00A6054 AFB00028 */  sw        $s0, 0x28($sp)
/* 3A55A8 E00A6058 AFA00010 */  sw        $zero, 0x10($sp)
/* 3A55AC E00A605C AFA00024 */  sw        $zero, 0x24($sp)
/* 3A55B0 E00A6060 0C080124 */  jal       func_E0200490
/* 3A55B4 E00A6064 AFA20014 */   sw       $v0, 0x14($sp)
/* 3A55B8 E00A6068 2404003C */  addiu     $a0, $zero, 0x3c
/* 3A55BC E00A606C 24030001 */  addiu     $v1, $zero, 1
/* 3A55C0 E00A6070 0040802D */  daddu     $s0, $v0, $zero
/* 3A55C4 E00A6074 0C08012C */  jal       func_E02004B0
/* 3A55C8 E00A6078 AE030008 */   sw       $v1, 8($s0)
/* 3A55CC E00A607C 0040202D */  daddu     $a0, $v0, $zero
/* 3A55D0 E00A6080 14800003 */  bnez      $a0, .LE00A6090
/* 3A55D4 E00A6084 AE02000C */   sw       $v0, 0xc($s0)
.LE00A6088:
/* 3A55D8 E00A6088 08029822 */  j         .LE00A6088
/* 3A55DC E00A608C 00000000 */   nop
.LE00A6090:
/* 3A55E0 E00A6090 0200102D */  daddu     $v0, $s0, $zero
/* 3A55E4 E00A6094 44800000 */  mtc1      $zero, $f0
/* 3A55E8 E00A6098 3C013F99 */  lui       $at, 0x3f99
/* 3A55EC E00A609C 3421999A */  ori       $at, $at, 0x999a
/* 3A55F0 E00A60A0 44812000 */  mtc1      $at, $f4
/* 3A55F4 E00A60A4 3C013ECC */  lui       $at, 0x3ecc
/* 3A55F8 E00A60A8 3421CCCD */  ori       $at, $at, 0xcccd
/* 3A55FC E00A60AC 44811000 */  mtc1      $at, $f2
/* 3A5600 E00A60B0 3C01BF80 */  lui       $at, 0xbf80
/* 3A5604 E00A60B4 44813000 */  mtc1      $at, $f6
/* 3A5608 E00A60B8 24030064 */  addiu     $v1, $zero, 0x64
/* 3A560C E00A60BC AC830004 */  sw        $v1, 4($a0)
/* 3A5610 E00A60C0 240300FF */  addiu     $v1, $zero, 0xff
/* 3A5614 E00A60C4 AC910000 */  sw        $s1, ($a0)
/* 3A5618 E00A60C8 AC830018 */  sw        $v1, 0x18($a0)
/* 3A561C E00A60CC E494000C */  swc1      $f20, 0xc($a0)
/* 3A5620 E00A60D0 E4960010 */  swc1      $f22, 0x10($a0)
/* 3A5624 E00A60D4 E4980014 */  swc1      $f24, 0x14($a0)
/* 3A5628 E00A60D8 AC800008 */  sw        $zero, 8($a0)
/* 3A562C E00A60DC E4800020 */  swc1      $f0, 0x20($a0)
/* 3A5630 E00A60E0 E480001C */  swc1      $f0, 0x1c($a0)
/* 3A5634 E00A60E4 E4800028 */  swc1      $f0, 0x28($a0)
/* 3A5638 E00A60E8 E4800024 */  swc1      $f0, 0x24($a0)
/* 3A563C E00A60EC E484002C */  swc1      $f4, 0x2c($a0)
/* 3A5640 E00A60F0 E4820030 */  swc1      $f2, 0x30($a0)
/* 3A5644 E00A60F4 E4860034 */  swc1      $f6, 0x34($a0)
/* 3A5648 E00A60F8 E4820038 */  swc1      $f2, 0x38($a0)
/* 3A564C E00A60FC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3A5650 E00A6100 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3A5654 E00A6104 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A5658 E00A6108 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3A565C E00A610C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3A5660 E00A6110 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3A5664 E00A6114 03E00008 */  jr        $ra
/* 3A5668 E00A6118 27BD0050 */   addiu    $sp, $sp, 0x50
