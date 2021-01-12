.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0112000
/* 3F9E50 E0112000 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 3F9E54 E0112004 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 3F9E58 E0112008 4485C000 */  mtc1      $a1, $f24
/* 3F9E5C E011200C F7BC0078 */  sdc1      $f28, 0x78($sp)
/* 3F9E60 E0112010 4486E000 */  mtc1      $a2, $f28
/* 3F9E64 E0112014 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 3F9E68 E0112018 4487D000 */  mtc1      $a3, $f26
/* 3F9E6C E011201C AFB20048 */  sw        $s2, 0x48($sp)
/* 3F9E70 E0112020 0080902D */  daddu     $s2, $a0, $zero
/* 3F9E74 E0112024 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 3F9E78 E0112028 C7B40090 */  lwc1      $f20, 0x90($sp)
/* 3F9E7C E011202C 27A40028 */  addiu     $a0, $sp, 0x28
/* 3F9E80 E0112030 AFB3004C */  sw        $s3, 0x4c($sp)
/* 3F9E84 E0112034 8FB30094 */  lw        $s3, 0x94($sp)
/* 3F9E88 E0112038 3C02E011 */  lui       $v0, %hi(func_E01121B8)
/* 3F9E8C E011203C 244221B8 */  addiu     $v0, $v0, %lo(func_E01121B8)
/* 3F9E90 E0112040 AFA20030 */  sw        $v0, 0x30($sp)
/* 3F9E94 E0112044 3C02E011 */  lui       $v0, %hi(func_E01121C0)
/* 3F9E98 E0112048 244221C0 */  addiu     $v0, $v0, %lo(func_E01121C0)
/* 3F9E9C E011204C AFA20034 */  sw        $v0, 0x34($sp)
/* 3F9EA0 E0112050 3C02E011 */  lui       $v0, %hi(func_E01122E8)
/* 3F9EA4 E0112054 244222E8 */  addiu     $v0, $v0, %lo(func_E01122E8)
/* 3F9EA8 E0112058 AFA20038 */  sw        $v0, 0x38($sp)
/* 3F9EAC E011205C 2402007B */  addiu     $v0, $zero, 0x7b
/* 3F9EB0 E0112060 AFBF0050 */  sw        $ra, 0x50($sp)
/* 3F9EB4 E0112064 AFB10044 */  sw        $s1, 0x44($sp)
/* 3F9EB8 E0112068 AFB00040 */  sw        $s0, 0x40($sp)
/* 3F9EBC E011206C F7B60060 */  sdc1      $f22, 0x60($sp)
/* 3F9EC0 E0112070 AFA00028 */  sw        $zero, 0x28($sp)
/* 3F9EC4 E0112074 AFA0003C */  sw        $zero, 0x3c($sp)
/* 3F9EC8 E0112078 0C080124 */  jal       func_E0200490
/* 3F9ECC E011207C AFA2002C */   sw       $v0, 0x2c($sp)
/* 3F9ED0 E0112080 24040038 */  addiu     $a0, $zero, 0x38
/* 3F9ED4 E0112084 24030001 */  addiu     $v1, $zero, 1
/* 3F9ED8 E0112088 0040882D */  daddu     $s1, $v0, $zero
/* 3F9EDC E011208C 0C08012C */  jal       func_E02004B0
/* 3F9EE0 E0112090 AE230008 */   sw       $v1, 8($s1)
/* 3F9EE4 E0112094 0040802D */  daddu     $s0, $v0, $zero
/* 3F9EE8 E0112098 16000003 */  bnez      $s0, .LE01120A8
/* 3F9EEC E011209C AE22000C */   sw       $v0, 0xc($s1)
.LE01120A0:
/* 3F9EF0 E01120A0 08044828 */  j         .LE01120A0
/* 3F9EF4 E01120A4 00000000 */   nop
.LE01120A8:
/* 3F9EF8 E01120A8 AE120000 */  sw        $s2, ($s0)
/* 3F9EFC E01120AC 1E600004 */  bgtz      $s3, .LE01120C0
/* 3F9F00 E01120B0 AE000014 */   sw       $zero, 0x14($s0)
/* 3F9F04 E01120B4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3F9F08 E01120B8 08044831 */  j         .LE01120C4
/* 3F9F0C E01120BC AE020010 */   sw       $v0, 0x10($s0)
.LE01120C0:
/* 3F9F10 E01120C0 AE130010 */  sw        $s3, 0x10($s0)
.LE01120C4:
/* 3F9F14 E01120C4 3C0141F0 */  lui       $at, 0x41f0
/* 3F9F18 E01120C8 4481B000 */  mtc1      $at, $f22
/* 3F9F1C E01120CC E6180004 */  swc1      $f24, 4($s0)
/* 3F9F20 E01120D0 E61C0008 */  swc1      $f28, 8($s0)
/* 3F9F24 E01120D4 E61A000C */  swc1      $f26, 0xc($s0)
/* 3F9F28 E01120D8 E6140018 */  swc1      $f20, 0x18($s0)
/* 3F9F2C E01120DC AE000024 */  sw        $zero, 0x24($s0)
/* 3F9F30 E01120E0 A2000034 */  sb        $zero, 0x34($s0)
/* 3F9F34 E01120E4 1640000D */  bnez      $s2, .LE011211C
/* 3F9F38 E01120E8 E6160020 */   swc1     $f22, 0x20($s0)
/* 3F9F3C E01120EC 0C080150 */  jal       func_E0200540
/* 3F9F40 E01120F0 24040024 */   addiu    $a0, $zero, 0x24
/* 3F9F44 E01120F4 3C014040 */  lui       $at, 0x4040
/* 3F9F48 E01120F8 44810000 */  mtc1      $at, $f0
/* 3F9F4C E01120FC 2402001E */  addiu     $v0, $zero, 0x1e
/* 3F9F50 E0112100 AFA20014 */  sw        $v0, 0x14($sp)
/* 3F9F54 E0112104 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3F9F58 E0112108 8E050004 */  lw        $a1, 4($s0)
/* 3F9F5C E011210C 8E060008 */  lw        $a2, 8($s0)
/* 3F9F60 E0112110 8E07000C */  lw        $a3, 0xc($s0)
/* 3F9F64 E0112114 0C012000 */  jal       func_E0048000
/* 3F9F68 E0112118 24040001 */   addiu    $a0, $zero, 1
.LE011211C:
/* 3F9F6C E011211C 2A420002 */  slti      $v0, $s2, 2
/* 3F9F70 E0112120 50400018 */  beql      $v0, $zero, .LE0112184
/* 3F9F74 E0112124 AE00001C */   sw       $zero, 0x1c($s0)
/* 3F9F78 E0112128 0C080150 */  jal       func_E0200540
/* 3F9F7C E011212C 24040072 */   addiu    $a0, $zero, 0x72
/* 3F9F80 E0112130 4616A102 */  mul.s     $f4, $f20, $f22
/* 3F9F84 E0112134 00000000 */  nop
/* 3F9F88 E0112138 24040003 */  addiu     $a0, $zero, 3
/* 3F9F8C E011213C 24020010 */  addiu     $v0, $zero, 0x10
/* 3F9F90 E0112140 4405C000 */  mfc1      $a1, $f24
/* 3F9F94 E0112144 3C014248 */  lui       $at, 0x4248
/* 3F9F98 E0112148 44810000 */  mtc1      $at, $f0
/* 3F9F9C E011214C 4604E701 */  sub.s     $f28, $f28, $f4
/* 3F9FA0 E0112150 4407D000 */  mfc1      $a3, $f26
/* 3F9FA4 E0112154 3C013F80 */  lui       $at, 0x3f80
/* 3F9FA8 E0112158 44811000 */  mtc1      $at, $f2
/* 3F9FAC E011215C 4406E000 */  mfc1      $a2, $f28
/* 3F9FB0 E0112160 4600A002 */  mul.s     $f0, $f20, $f0
/* 3F9FB4 E0112164 00000000 */  nop
/* 3F9FB8 E0112168 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3F9FBC E011216C AFA00020 */  sw        $zero, 0x20($sp)
/* 3F9FC0 E0112170 E7A20018 */  swc1      $f2, 0x18($sp)
/* 3F9FC4 E0112174 E7A40010 */  swc1      $f4, 0x10($sp)
/* 3F9FC8 E0112178 0C039000 */  jal       func_E00E4000
/* 3F9FCC E011217C E7A00014 */   swc1     $f0, 0x14($sp)
/* 3F9FD0 E0112180 AE02001C */  sw        $v0, 0x1c($s0)
.LE0112184:
/* 3F9FD4 E0112184 0220102D */  daddu     $v0, $s1, $zero
/* 3F9FD8 E0112188 8FBF0050 */  lw        $ra, 0x50($sp)
/* 3F9FDC E011218C 8FB3004C */  lw        $s3, 0x4c($sp)
/* 3F9FE0 E0112190 8FB20048 */  lw        $s2, 0x48($sp)
/* 3F9FE4 E0112194 8FB10044 */  lw        $s1, 0x44($sp)
/* 3F9FE8 E0112198 8FB00040 */  lw        $s0, 0x40($sp)
/* 3F9FEC E011219C D7BC0078 */  ldc1      $f28, 0x78($sp)
/* 3F9FF0 E01121A0 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 3F9FF4 E01121A4 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 3F9FF8 E01121A8 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 3F9FFC E01121AC D7B40058 */  ldc1      $f20, 0x58($sp)
/* 3FA000 E01121B0 03E00008 */  jr        $ra
/* 3FA004 E01121B4 27BD0080 */   addiu    $sp, $sp, 0x80
