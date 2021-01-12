.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D0000
/* 3D3E20 E00D0000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3D3E24 E00D0004 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D3E28 E00D0008 4485B000 */  mtc1      $a1, $f22
/* 3D3E2C E00D000C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D3E30 E00D0010 4486C000 */  mtc1      $a2, $f24
/* 3D3E34 E00D0014 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3D3E38 E00D0018 4487D000 */  mtc1      $a3, $f26
/* 3D3E3C E00D001C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D3E40 E00D0020 C7B40070 */  lwc1      $f20, 0x70($sp)
/* 3D3E44 E00D0024 AFB20030 */  sw        $s2, 0x30($sp)
/* 3D3E48 E00D0028 0080902D */  daddu     $s2, $a0, $zero
/* 3D3E4C E00D002C AFB00028 */  sw        $s0, 0x28($sp)
/* 3D3E50 E00D0030 24100003 */  addiu     $s0, $zero, 3
/* 3D3E54 E00D0034 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3D3E58 E00D0038 4480E000 */  mtc1      $zero, $f28
/* 3D3E5C E00D003C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D3E60 E00D0040 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3D3E64 E00D0044 16400002 */  bnez      $s2, .LE00D0050
/* 3D3E68 E00D0048 AFB1002C */   sw       $s1, 0x2c($sp)
/* 3D3E6C E00D004C 24100007 */  addiu     $s0, $zero, 7
.LE00D0050:
/* 3D3E70 E00D0050 26100001 */  addiu     $s0, $s0, 1
/* 3D3E74 E00D0054 3C02E00D */  lui       $v0, %hi(func_E00D018C)
/* 3D3E78 E00D0058 2442018C */  addiu     $v0, $v0, %lo(func_E00D018C)
/* 3D3E7C E00D005C AFA00010 */  sw        $zero, 0x10($sp)
/* 3D3E80 E00D0060 AC820008 */  sw        $v0, 8($a0)
/* 3D3E84 E00D0064 3C02E00D */  lui       $v0, %hi(func_E00D0194)
/* 3D3E88 E00D0068 24420194 */  addiu     $v0, $v0, %lo(func_E00D0194)
/* 3D3E8C E00D006C AC82000C */  sw        $v0, 0xc($a0)
/* 3D3E90 E00D0070 3C02E00D */  lui       $v0, %hi(func_E00D0448)
/* 3D3E94 E00D0074 24420448 */  addiu     $v0, $v0, %lo(func_E00D0448)
/* 3D3E98 E00D0078 AC820010 */  sw        $v0, 0x10($a0)
/* 3D3E9C E00D007C 24020068 */  addiu     $v0, $zero, 0x68
/* 3D3EA0 E00D0080 AC800014 */  sw        $zero, 0x14($a0)
/* 3D3EA4 E00D0084 0C080124 */  jal       func_E0200490
/* 3D3EA8 E00D0088 AC820004 */   sw       $v0, 4($a0)
/* 3D3EAC E00D008C 00102040 */  sll       $a0, $s0, 1
/* 3D3EB0 E00D0090 00902021 */  addu      $a0, $a0, $s0
/* 3D3EB4 E00D0094 00042080 */  sll       $a0, $a0, 2
/* 3D3EB8 E00D0098 00902023 */  subu      $a0, $a0, $s0
/* 3D3EBC E00D009C 000420C0 */  sll       $a0, $a0, 3
/* 3D3EC0 E00D00A0 0040882D */  daddu     $s1, $v0, $zero
/* 3D3EC4 E00D00A4 0C08012C */  jal       func_E02004B0
/* 3D3EC8 E00D00A8 AE300008 */   sw       $s0, 8($s1)
/* 3D3ECC E00D00AC 0040182D */  daddu     $v1, $v0, $zero
/* 3D3ED0 E00D00B0 14600003 */  bnez      $v1, .LE00D00C0
/* 3D3ED4 E00D00B4 AE23000C */   sw       $v1, 0xc($s1)
.LE00D00B8:
/* 3D3ED8 E00D00B8 0803402E */  j         .LE00D00B8
/* 3D3EDC E00D00BC 00000000 */   nop
.LE00D00C0:
/* 3D3EE0 E00D00C0 2402003C */  addiu     $v0, $zero, 0x3c
/* 3D3EE4 E00D00C4 AC620028 */  sw        $v0, 0x28($v1)
/* 3D3EE8 E00D00C8 240200FF */  addiu     $v0, $zero, 0xff
/* 3D3EEC E00D00CC AC620038 */  sw        $v0, 0x38($v1)
/* 3D3EF0 E00D00D0 A0620050 */  sb        $v0, 0x50($v1)
/* 3D3EF4 E00D00D4 A0620053 */  sb        $v0, 0x53($v1)
/* 3D3EF8 E00D00D8 240200C8 */  addiu     $v0, $zero, 0xc8
/* 3D3EFC E00D00DC A0620054 */  sb        $v0, 0x54($v1)
/* 3D3F00 E00D00E0 24020064 */  addiu     $v0, $zero, 0x64
/* 3D3F04 E00D00E4 AC60002C */  sw        $zero, 0x2c($v1)
/* 3D3F08 E00D00E8 A4720000 */  sh        $s2, ($v1)
/* 3D3F0C E00D00EC E4760004 */  swc1      $f22, 4($v1)
/* 3D3F10 E00D00F0 E4780008 */  swc1      $f24, 8($v1)
/* 3D3F14 E00D00F4 E47A000C */  swc1      $f26, 0xc($v1)
/* 3D3F18 E00D00F8 E4740024 */  swc1      $f20, 0x24($v1)
/* 3D3F1C E00D00FC E4740020 */  swc1      $f20, 0x20($v1)
/* 3D3F20 E00D0100 E474001C */  swc1      $f20, 0x1c($v1)
/* 3D3F24 E00D0104 A0600051 */  sb        $zero, 0x51($v1)
/* 3D3F28 E00D0108 A0600052 */  sb        $zero, 0x52($v1)
/* 3D3F2C E00D010C A0620055 */  sb        $v0, 0x55($v1)
/* 3D3F30 E00D0110 24040001 */  addiu     $a0, $zero, 1
/* 3D3F34 E00D0114 0090102A */  slt       $v0, $a0, $s0
/* 3D3F38 E00D0118 10400010 */  beqz      $v0, .LE00D015C
/* 3D3F3C E00D011C 24630058 */   addiu    $v1, $v1, 0x58
/* 3D3F40 E00D0120 24630030 */  addiu     $v1, $v1, 0x30
/* 3D3F44 E00D0124 2406001E */  addiu     $a2, $zero, 0x1e
/* 3D3F48 E00D0128 2405FFFF */  addiu     $a1, $zero, -1
.LE00D012C:
/* 3D3F4C E00D012C 44860000 */  mtc1      $a2, $f0
/* 3D3F50 E00D0130 00000000 */  nop
/* 3D3F54 E00D0134 46800020 */  cvt.s.w   $f0, $f0
/* 3D3F58 E00D0138 24C6001E */  addiu     $a2, $a2, 0x1e
/* 3D3F5C E00D013C AC65001C */  sw        $a1, 0x1c($v1)
/* 3D3F60 E00D0140 24A5FFFE */  addiu     $a1, $a1, -2
/* 3D3F64 E00D0144 24840001 */  addiu     $a0, $a0, 1
/* 3D3F68 E00D0148 E47C0004 */  swc1      $f28, 4($v1)
/* 3D3F6C E00D014C E4600000 */  swc1      $f0, ($v1)
/* 3D3F70 E00D0150 0090102A */  slt       $v0, $a0, $s0
/* 3D3F74 E00D0154 1440FFF5 */  bnez      $v0, .LE00D012C
/* 3D3F78 E00D0158 24630058 */   addiu    $v1, $v1, 0x58
.LE00D015C:
/* 3D3F7C E00D015C 0220102D */  daddu     $v0, $s1, $zero
/* 3D3F80 E00D0160 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3D3F84 E00D0164 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D3F88 E00D0168 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D3F8C E00D016C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D3F90 E00D0170 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 3D3F94 E00D0174 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3D3F98 E00D0178 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D3F9C E00D017C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D3FA0 E00D0180 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D3FA4 E00D0184 03E00008 */  jr        $ra
/* 3D3FA8 E00D0188 27BD0060 */   addiu    $sp, $sp, 0x60
