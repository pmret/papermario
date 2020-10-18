.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B0000
/* 3B3EB0 E00B0000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B3EB4 E00B0004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B3EB8 E00B0008 4485A000 */  mtc1      $a1, $f20
/* 3B3EBC E00B000C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B3EC0 E00B0010 4486B000 */  mtc1      $a2, $f22
/* 3B3EC4 E00B0014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B3EC8 E00B0018 0080902D */  daddu     $s2, $a0, $zero
/* 3B3ECC E00B001C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B3ED0 E00B0020 4487C000 */  mtc1      $a3, $f24
/* 3B3ED4 E00B0024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B3ED8 E00B0028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B3EDC E00B002C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3B3EE0 E00B0030 3C02E00B */  lui       $v0, 0xe00b
/* 3B3EE4 E00B0034 2442011C */  addiu     $v0, $v0, 0x11c
/* 3B3EE8 E00B0038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B3EEC E00B003C 3C02E00B */  lui       $v0, 0xe00b
/* 3B3EF0 E00B0040 24420124 */  addiu     $v0, $v0, 0x124
/* 3B3EF4 E00B0044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B3EF8 E00B0048 3C02E00B */  lui       $v0, 0xe00b
/* 3B3EFC E00B004C 244201F8 */  addiu     $v0, $v0, 0x1f8
/* 3B3F00 E00B0050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B3F04 E00B0054 24020058 */  addiu     $v0, $zero, 0x58
/* 3B3F08 E00B0058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B3F0C E00B005C AFB00028 */  sw        $s0, 0x28($sp)
/* 3B3F10 E00B0060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B3F14 E00B0064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B3F18 E00B0068 0C080124 */  jal       func_E0200490
/* 3B3F1C E00B006C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B3F20 E00B0070 24040034 */  addiu     $a0, $zero, 0x34
/* 3B3F24 E00B0074 24030001 */  addiu     $v1, $zero, 1
/* 3B3F28 E00B0078 0040802D */  daddu     $s0, $v0, $zero
/* 3B3F2C E00B007C 0C08012C */  jal       func_E02004B0
/* 3B3F30 E00B0080 AE030008 */   sw       $v1, 8($s0)
/* 3B3F34 E00B0084 0040202D */  daddu     $a0, $v0, $zero
/* 3B3F38 E00B0088 14800003 */  bnez      $a0, .LE00B0098
/* 3B3F3C E00B008C AE02000C */   sw       $v0, 0xc($s0)
.LE00B0090:
/* 3B3F40 E00B0090 0802C024 */  j         .LE00B0090
/* 3B3F44 E00B0094 00000000 */   nop      
.LE00B0098:
/* 3B3F48 E00B0098 AC920000 */  sw        $s2, ($a0)
/* 3B3F4C E00B009C 1E200004 */  bgtz      $s1, .LE00B00B0
/* 3B3F50 E00B00A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3B3F54 E00B00A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B3F58 E00B00A8 0802C02D */  j         .LE00B00B4
/* 3B3F5C E00B00AC AC820010 */   sw       $v0, 0x10($a0)
.LE00B00B0:
/* 3B3F60 E00B00B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00B00B4:
/* 3B3F64 E00B00B4 240300FF */  addiu     $v1, $zero, 0xff
/* 3B3F68 E00B00B8 AC830024 */  sw        $v1, 0x24($a0)
/* 3B3F6C E00B00BC E4940004 */  swc1      $f20, 4($a0)
/* 3B3F70 E00B00C0 E4960008 */  swc1      $f22, 8($a0)
/* 3B3F74 E00B00C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3B3F78 E00B00C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3B3F7C E00B00CC 0200102D */  daddu     $v0, $s0, $zero
/* 3B3F80 E00B00D0 AC830018 */  sw        $v1, 0x18($a0)
/* 3B3F84 E00B00D4 240300E6 */  addiu     $v1, $zero, 0xe6
/* 3B3F88 E00B00D8 AC83001C */  sw        $v1, 0x1c($a0)
/* 3B3F8C E00B00DC E4800028 */  swc1      $f0, 0x28($a0)
/* 3B3F90 E00B00E0 3C013F80 */  lui       $at, 0x3f80
/* 3B3F94 E00B00E4 44810000 */  mtc1      $at, $f0
/* 3B3F98 E00B00E8 24030032 */  addiu     $v1, $zero, 0x32
/* 3B3F9C E00B00EC AC830020 */  sw        $v1, 0x20($a0)
/* 3B3FA0 E00B00F0 AC800030 */  sw        $zero, 0x30($a0)
/* 3B3FA4 E00B00F4 E480002C */  swc1      $f0, 0x2c($a0)
/* 3B3FA8 E00B00F8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B3FAC E00B00FC 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B3FB0 E00B0100 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B3FB4 E00B0104 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B3FB8 E00B0108 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B3FBC E00B010C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B3FC0 E00B0110 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B3FC4 E00B0114 03E00008 */  jr        $ra
/* 3B3FC8 E00B0118 27BD0050 */   addiu    $sp, $sp, 0x50
