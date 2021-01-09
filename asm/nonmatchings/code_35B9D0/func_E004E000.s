.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004E000
/* 35B9D0 E004E000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 35B9D4 E004E004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 35B9D8 E004E008 4485A000 */  mtc1      $a1, $f20
/* 35B9DC E004E00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 35B9E0 E004E010 4486B000 */  mtc1      $a2, $f22
/* 35B9E4 E004E014 AFB20030 */  sw        $s2, 0x30($sp)
/* 35B9E8 E004E018 0080902D */  daddu     $s2, $a0, $zero
/* 35B9EC E004E01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 35B9F0 E004E020 4487C000 */  mtc1      $a3, $f24
/* 35B9F4 E004E024 27A40010 */  addiu     $a0, $sp, 0x10
/* 35B9F8 E004E028 AFB30034 */  sw        $s3, 0x34($sp)
/* 35B9FC E004E02C 8FB3006C */  lw        $s3, 0x6c($sp)
/* 35BA00 E004E030 3C02E005 */  lui       $v0, %hi(func_E004E15C)
/* 35BA04 E004E034 2442E15C */  addiu     $v0, $v0, %lo(func_E004E15C)
/* 35BA08 E004E038 AFA20018 */  sw        $v0, 0x18($sp)
/* 35BA0C E004E03C 3C02E005 */  lui       $v0, %hi(func_E004E164)
/* 35BA10 E004E040 2442E164 */  addiu     $v0, $v0, %lo(func_E004E164)
/* 35BA14 E004E044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35BA18 E004E048 3C02E005 */  lui       $v0, %hi(func_E004E1D0)
/* 35BA1C E004E04C 2442E1D0 */  addiu     $v0, $v0, %lo(func_E004E1D0)
/* 35BA20 E004E050 AFA20020 */  sw        $v0, 0x20($sp)
/* 35BA24 E004E054 24020027 */  addiu     $v0, $zero, 0x27
/* 35BA28 E004E058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 35BA2C E004E05C AFB1002C */  sw        $s1, 0x2c($sp)
/* 35BA30 E004E060 AFB00028 */  sw        $s0, 0x28($sp)
/* 35BA34 E004E064 AFA00010 */  sw        $zero, 0x10($sp)
/* 35BA38 E004E068 AFA00024 */  sw        $zero, 0x24($sp)
/* 35BA3C E004E06C 0C080124 */  jal       func_E0200490
/* 35BA40 E004E070 AFA20014 */   sw       $v0, 0x14($sp)
/* 35BA44 E004E074 24040028 */  addiu     $a0, $zero, 0x28
/* 35BA48 E004E078 24110001 */  addiu     $s1, $zero, 1
/* 35BA4C E004E07C 0040802D */  daddu     $s0, $v0, $zero
/* 35BA50 E004E080 0C08012C */  jal       func_E02004B0
/* 35BA54 E004E084 AE110008 */   sw       $s1, 8($s0)
/* 35BA58 E004E088 AE02000C */  sw        $v0, 0xc($s0)
/* 35BA5C E004E08C 0040802D */  daddu     $s0, $v0, $zero
/* 35BA60 E004E090 16000003 */  bnez      $s0, .LE004E0A0
/* 35BA64 E004E094 0200202D */   daddu    $a0, $s0, $zero
.LE004E098:
/* 35BA68 E004E098 08013826 */  j         .LE004E098
/* 35BA6C E004E09C 00000000 */   nop      
.LE004E0A0:
/* 35BA70 E004E0A0 00112880 */  sll       $a1, $s1, 2
/* 35BA74 E004E0A4 00B12821 */  addu      $a1, $a1, $s1
/* 35BA78 E004E0A8 0C080130 */  jal       func_E02004C0
/* 35BA7C E004E0AC 000528C0 */   sll      $a1, $a1, 3
/* 35BA80 E004E0B0 AE130014 */  sw        $s3, 0x14($s0)
/* 35BA84 E004E0B4 AE000018 */  sw        $zero, 0x18($s0)
/* 35BA88 E004E0B8 AE13001C */  sw        $s3, 0x1c($s0)
/* 35BA8C E004E0BC AE000020 */  sw        $zero, 0x20($s0)
/* 35BA90 E004E0C0 A6120000 */  sh        $s2, ($s0)
/* 35BA94 E004E0C4 E6140004 */  swc1      $f20, 4($s0)
/* 35BA98 E004E0C8 E6160008 */  swc1      $f22, 8($s0)
/* 35BA9C E004E0CC E618000C */  swc1      $f24, 0xc($s0)
/* 35BAA0 E004E0D0 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 35BAA4 E004E0D4 12400006 */  beqz      $s2, .LE004E0F0
/* 35BAA8 E004E0D8 E6000010 */   swc1     $f0, 0x10($s0)
/* 35BAAC E004E0DC 24020001 */  addiu     $v0, $zero, 1
/* 35BAB0 E004E0E0 12420008 */  beq       $s2, $v0, .LE004E104
/* 35BAB4 E004E0E4 240200E1 */   addiu    $v0, $zero, 0xe1
/* 35BAB8 E004E0E8 08013847 */  j         .LE004E11C
/* 35BABC E004E0EC A2020024 */   sb       $v0, 0x24($s0)
.LE004E0F0:
/* 35BAC0 E004E0F0 24020082 */  addiu     $v0, $zero, 0x82
/* 35BAC4 E004E0F4 A2000026 */  sb        $zero, 0x26($s0)
/* 35BAC8 E004E0F8 A2000025 */  sb        $zero, 0x25($s0)
/* 35BACC E004E0FC 0801384C */  j         .LE004E130
/* 35BAD0 E004E100 A2000024 */   sb       $zero, 0x24($s0)
.LE004E104:
/* 35BAD4 E004E104 240200FF */  addiu     $v0, $zero, 0xff
/* 35BAD8 E004E108 A2020024 */  sb        $v0, 0x24($s0)
/* 35BADC E004E10C 24020082 */  addiu     $v0, $zero, 0x82
/* 35BAE0 E004E110 A2000026 */  sb        $zero, 0x26($s0)
/* 35BAE4 E004E114 0801384C */  j         .LE004E130
/* 35BAE8 E004E118 A2000025 */   sb       $zero, 0x25($s0)
.LE004E11C:
/* 35BAEC E004E11C 240200D7 */  addiu     $v0, $zero, 0xd7
/* 35BAF0 E004E120 A2020025 */  sb        $v0, 0x25($s0)
/* 35BAF4 E004E124 240200FF */  addiu     $v0, $zero, 0xff
/* 35BAF8 E004E128 A2020026 */  sb        $v0, 0x26($s0)
/* 35BAFC E004E12C 240200B4 */  addiu     $v0, $zero, 0xb4
.LE004E130:
/* 35BB00 E004E130 A2020027 */  sb        $v0, 0x27($s0)
/* 35BB04 E004E134 8FBF0038 */  lw        $ra, 0x38($sp)
/* 35BB08 E004E138 8FB30034 */  lw        $s3, 0x34($sp)
/* 35BB0C E004E13C 8FB20030 */  lw        $s2, 0x30($sp)
/* 35BB10 E004E140 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35BB14 E004E144 8FB00028 */  lw        $s0, 0x28($sp)
/* 35BB18 E004E148 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 35BB1C E004E14C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 35BB20 E004E150 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 35BB24 E004E154 03E00008 */  jr        $ra
/* 35BB28 E004E158 27BD0058 */   addiu    $sp, $sp, 0x58
