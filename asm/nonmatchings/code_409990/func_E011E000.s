.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011E000
/* 409990 E011E000 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 409994 E011E004 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 409998 E011E008 4485B000 */  mtc1      $a1, $f22
/* 40999C E011E00C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 4099A0 E011E010 4486D000 */  mtc1      $a2, $f26
/* 4099A4 E011E014 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 4099A8 E011E018 4487C000 */  mtc1      $a3, $f24
/* 4099AC E011E01C AFB3004C */  sw        $s3, 0x4c($sp)
/* 4099B0 E011E020 0080982D */  daddu     $s3, $a0, $zero
/* 4099B4 E011E024 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 4099B8 E011E028 C7B40088 */  lwc1      $f20, 0x88($sp)
/* 4099BC E011E02C 27A40028 */  addiu     $a0, $sp, 0x28
/* 4099C0 E011E030 AFB20048 */  sw        $s2, 0x48($sp)
/* 4099C4 E011E034 8FB2008C */  lw        $s2, 0x8c($sp)
/* 4099C8 E011E038 3C02E012 */  lui       $v0, %hi(func_E011E18C)
/* 4099CC E011E03C 2442E18C */  addiu     $v0, $v0, %lo(func_E011E18C)
/* 4099D0 E011E040 AFA20030 */  sw        $v0, 0x30($sp)
/* 4099D4 E011E044 3C02E012 */  lui       $v0, %hi(func_E011E194)
/* 4099D8 E011E048 2442E194 */  addiu     $v0, $v0, %lo(func_E011E194)
/* 4099DC E011E04C AFA20034 */  sw        $v0, 0x34($sp)
/* 4099E0 E011E050 3C02E012 */  lui       $v0, %hi(func_E011E530)
/* 4099E4 E011E054 2442E530 */  addiu     $v0, $v0, %lo(func_E011E530)
/* 4099E8 E011E058 AFA20038 */  sw        $v0, 0x38($sp)
/* 4099EC E011E05C 24020081 */  addiu     $v0, $zero, 0x81
/* 4099F0 E011E060 AFBF0050 */  sw        $ra, 0x50($sp)
/* 4099F4 E011E064 AFB10044 */  sw        $s1, 0x44($sp)
/* 4099F8 E011E068 AFB00040 */  sw        $s0, 0x40($sp)
/* 4099FC E011E06C AFA00028 */  sw        $zero, 0x28($sp)
/* 409A00 E011E070 AFA0003C */  sw        $zero, 0x3c($sp)
/* 409A04 E011E074 0C080124 */  jal       func_E0200490
/* 409A08 E011E078 AFA2002C */   sw       $v0, 0x2c($sp)
/* 409A0C E011E07C 2404002C */  addiu     $a0, $zero, 0x2c
/* 409A10 E011E080 24030001 */  addiu     $v1, $zero, 1
/* 409A14 E011E084 0040882D */  daddu     $s1, $v0, $zero
/* 409A18 E011E088 0C08012C */  jal       func_E02004B0
/* 409A1C E011E08C AE230008 */   sw       $v1, 8($s1)
/* 409A20 E011E090 0040802D */  daddu     $s0, $v0, $zero
/* 409A24 E011E094 16000003 */  bnez      $s0, .LE011E0A4
/* 409A28 E011E098 AE22000C */   sw       $v0, 0xc($s1)
.LE011E09C:
/* 409A2C E011E09C 08047827 */  j         .LE011E09C
/* 409A30 E011E0A0 00000000 */   nop
.LE011E0A4:
/* 409A34 E011E0A4 AE130000 */  sw        $s3, ($s0)
/* 409A38 E011E0A8 1E400004 */  bgtz      $s2, .LE011E0BC
/* 409A3C E011E0AC AE000014 */   sw       $zero, 0x14($s0)
/* 409A40 E011E0B0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 409A44 E011E0B4 08047830 */  j         .LE011E0C0
/* 409A48 E011E0B8 AE020010 */   sw       $v0, 0x10($s0)
.LE011E0BC:
/* 409A4C E011E0BC AE120010 */  sw        $s2, 0x10($s0)
.LE011E0C0:
/* 409A50 E011E0C0 24040072 */  addiu     $a0, $zero, 0x72
/* 409A54 E011E0C4 240300FF */  addiu     $v1, $zero, 0xff
/* 409A58 E011E0C8 240200F0 */  addiu     $v0, $zero, 0xf0
/* 409A5C E011E0CC A203001B */  sb        $v1, 0x1b($s0)
/* 409A60 E011E0D0 E6160004 */  swc1      $f22, 4($s0)
/* 409A64 E011E0D4 E61A0008 */  swc1      $f26, 8($s0)
/* 409A68 E011E0D8 E618000C */  swc1      $f24, 0xc($s0)
/* 409A6C E011E0DC E6140020 */  swc1      $f20, 0x20($s0)
/* 409A70 E011E0E0 A2030018 */  sb        $v1, 0x18($s0)
/* 409A74 E011E0E4 A2030019 */  sb        $v1, 0x19($s0)
/* 409A78 E011E0E8 A203001A */  sb        $v1, 0x1a($s0)
/* 409A7C E011E0EC A202001C */  sb        $v0, 0x1c($s0)
/* 409A80 E011E0F0 A203001D */  sb        $v1, 0x1d($s0)
/* 409A84 E011E0F4 A203001E */  sb        $v1, 0x1e($s0)
/* 409A88 E011E0F8 A203001F */  sb        $v1, 0x1f($s0)
/* 409A8C E011E0FC A2000025 */  sb        $zero, 0x25($s0)
/* 409A90 E011E100 0C080150 */  jal       func_E0200540
/* 409A94 E011E104 A2000024 */   sb       $zero, 0x24($s0)
/* 409A98 E011E108 24040001 */  addiu     $a0, $zero, 1
/* 409A9C E011E10C 3C014120 */  lui       $at, 0x4120
/* 409AA0 E011E110 44810000 */  mtc1      $at, $f0
/* 409AA4 E011E114 3C014200 */  lui       $at, 0x4200
/* 409AA8 E011E118 44811000 */  mtc1      $at, $f2
/* 409AAC E011E11C 3C0141F0 */  lui       $at, 0x41f0
/* 409AB0 E011E120 44812000 */  mtc1      $at, $f4
/* 409AB4 E011E124 4600D680 */  add.s     $f26, $f26, $f0
/* 409AB8 E011E128 4405B000 */  mfc1      $a1, $f22
/* 409ABC E011E12C 4407C000 */  mfc1      $a3, $f24
/* 409AC0 E011E130 4406D000 */  mfc1      $a2, $f26
/* 409AC4 E011E134 24020004 */  addiu     $v0, $zero, 4
/* 409AC8 E011E138 E7B40018 */  swc1      $f20, 0x18($sp)
/* 409ACC E011E13C AFA2001C */  sw        $v0, 0x1c($sp)
/* 409AD0 E011E140 AFA00020 */  sw        $zero, 0x20($sp)
/* 409AD4 E011E144 E7A20010 */  swc1      $f2, 0x10($sp)
/* 409AD8 E011E148 0C039000 */  jal       func_E00E4000
/* 409ADC E011E14C E7A40014 */   swc1     $f4, 0x14($sp)
/* 409AE0 E011E150 2404006F */  addiu     $a0, $zero, 0x6f
/* 409AE4 E011E154 0C080150 */  jal       func_E0200540
/* 409AE8 E011E158 AE020028 */   sw       $v0, 0x28($s0)
/* 409AEC E011E15C 0220102D */  daddu     $v0, $s1, $zero
/* 409AF0 E011E160 8FBF0050 */  lw        $ra, 0x50($sp)
/* 409AF4 E011E164 8FB3004C */  lw        $s3, 0x4c($sp)
/* 409AF8 E011E168 8FB20048 */  lw        $s2, 0x48($sp)
/* 409AFC E011E16C 8FB10044 */  lw        $s1, 0x44($sp)
/* 409B00 E011E170 8FB00040 */  lw        $s0, 0x40($sp)
/* 409B04 E011E174 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 409B08 E011E178 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 409B0C E011E17C D7B60060 */  ldc1      $f22, 0x60($sp)
/* 409B10 E011E180 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 409B14 E011E184 03E00008 */  jr        $ra
/* 409B18 E011E188 27BD0078 */   addiu    $sp, $sp, 0x78
