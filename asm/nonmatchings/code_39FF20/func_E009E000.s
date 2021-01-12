.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E009E000
/* 39FF20 E009E000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 39FF24 E009E004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 39FF28 E009E008 4485A000 */  mtc1      $a1, $f20
/* 39FF2C E009E00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 39FF30 E009E010 4486B000 */  mtc1      $a2, $f22
/* 39FF34 E009E014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 39FF38 E009E018 0080882D */  daddu     $s1, $a0, $zero
/* 39FF3C E009E01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 39FF40 E009E020 4487C000 */  mtc1      $a3, $f24
/* 39FF44 E009E024 27A40010 */  addiu     $a0, $sp, 0x10
/* 39FF48 E009E028 AFB00028 */  sw        $s0, 0x28($sp)
/* 39FF4C E009E02C 8FB0006C */  lw        $s0, 0x6c($sp)
/* 39FF50 E009E030 3C02E00A */  lui       $v0, %hi(func_E009E1DC)
/* 39FF54 E009E034 2442E1DC */  addiu     $v0, $v0, %lo(func_E009E1DC)
/* 39FF58 E009E038 AFA20018 */  sw        $v0, 0x18($sp)
/* 39FF5C E009E03C 3C02E00A */  lui       $v0, %hi(func_E009E1E4)
/* 39FF60 E009E040 2442E1E4 */  addiu     $v0, $v0, %lo(func_E009E1E4)
/* 39FF64 E009E044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 39FF68 E009E048 3C02E00A */  lui       $v0, %hi(func_E009E3DC)
/* 39FF6C E009E04C 2442E3DC */  addiu     $v0, $v0, %lo(func_E009E3DC)
/* 39FF70 E009E050 AFA20020 */  sw        $v0, 0x20($sp)
/* 39FF74 E009E054 2402004F */  addiu     $v0, $zero, 0x4f
/* 39FF78 E009E058 AFBF003C */  sw        $ra, 0x3c($sp)
/* 39FF7C E009E05C AFB40038 */  sw        $s4, 0x38($sp)
/* 39FF80 E009E060 AFB30034 */  sw        $s3, 0x34($sp)
/* 39FF84 E009E064 AFB20030 */  sw        $s2, 0x30($sp)
/* 39FF88 E009E068 AFA00010 */  sw        $zero, 0x10($sp)
/* 39FF8C E009E06C AFA00024 */  sw        $zero, 0x24($sp)
/* 39FF90 E009E070 0C080124 */  jal       func_E0200490
/* 39FF94 E009E074 AFA20014 */   sw       $v0, 0x14($sp)
/* 39FF98 E009E078 24040138 */  addiu     $a0, $zero, 0x138
/* 39FF9C E009E07C 24130006 */  addiu     $s3, $zero, 6
/* 39FFA0 E009E080 0040902D */  daddu     $s2, $v0, $zero
/* 39FFA4 E009E084 0C08012C */  jal       func_E02004B0
/* 39FFA8 E009E088 AE530008 */   sw       $s3, 8($s2)
/* 39FFAC E009E08C 0040182D */  daddu     $v1, $v0, $zero
/* 39FFB0 E009E090 14600003 */  bnez      $v1, .LE009E0A0
/* 39FFB4 E009E094 AE43000C */   sw       $v1, 0xc($s2)
.LE009E098:
/* 39FFB8 E009E098 08027826 */  j         .LE009E098
/* 39FFBC E009E09C 00000000 */   nop
.LE009E0A0:
/* 39FFC0 E009E0A0 AC710004 */  sw        $s1, 4($v1)
/* 39FFC4 E009E0A4 1E000004 */  bgtz      $s0, .LE009E0B8
/* 39FFC8 E009E0A8 AC60001C */   sw       $zero, 0x1c($v1)
/* 39FFCC E009E0AC 24020064 */  addiu     $v0, $zero, 0x64
/* 39FFD0 E009E0B0 0802782F */  j         .LE009E0BC
/* 39FFD4 E009E0B4 AC620018 */   sw       $v0, 0x18($v1)
.LE009E0B8:
/* 39FFD8 E009E0B8 AC700018 */  sw        $s0, 0x18($v1)
.LE009E0BC:
/* 39FFDC E009E0BC AC600014 */  sw        $zero, 0x14($v1)
/* 39FFE0 E009E0C0 E4740008 */  swc1      $f20, 8($v1)
/* 39FFE4 E009E0C4 E476000C */  swc1      $f22, 0xc($v1)
/* 39FFE8 E009E0C8 E4780010 */  swc1      $f24, 0x10($v1)
/* 39FFEC E009E0CC 24110001 */  addiu     $s1, $zero, 1
/* 39FFF0 E009E0D0 0233102A */  slt       $v0, $s1, $s3
/* 39FFF4 E009E0D4 10400035 */  beqz      $v0, .LE009E1AC
/* 39FFF8 E009E0D8 24630034 */   addiu    $v1, $v1, 0x34
/* 39FFFC E009E0DC 3C146666 */  lui       $s4, 0x6666
/* 3A0000 E009E0E0 36946667 */  ori       $s4, $s4, 0x6667
/* 3A0004 E009E0E4 24700030 */  addiu     $s0, $v1, 0x30
/* 3A0008 E009E0E8 3C01E00A */  lui       $at, %hi(D_E009EE00)
/* 3A000C E009E0EC D434EE00 */  ldc1      $f20, %lo(D_E009EE00)($at)
/* 3A0010 E009E0F0 3C01E00A */  lui       $at, %hi(D_E009EE08)
/* 3A0014 E009E0F4 D436EE08 */  ldc1      $f22, %lo(D_E009EE08)($at)
.LE009E0F8:
/* 3A0018 E009E0F8 0C080138 */  jal       func_E02004E0
/* 3A001C E009E0FC 24040168 */   addiu    $a0, $zero, 0x168
/* 3A0020 E009E100 00112840 */  sll       $a1, $s1, 1
/* 3A0024 E009E104 00B40018 */  mult      $a1, $s4
/* 3A0028 E009E108 2404000F */  addiu     $a0, $zero, 0xf
/* 3A002C E009E10C 44820000 */  mtc1      $v0, $f0
/* 3A0030 E009E110 00000000 */  nop
/* 3A0034 E009E114 46800020 */  cvt.s.w   $f0, $f0
/* 3A0038 E009E118 000517C3 */  sra       $v0, $a1, 0x1f
/* 3A003C E009E11C E600FFF0 */  swc1      $f0, -0x10($s0)
/* 3A0040 E009E120 00004010 */  mfhi      $t0
/* 3A0044 E009E124 000818C3 */  sra       $v1, $t0, 3
/* 3A0048 E009E128 00621823 */  subu      $v1, $v1, $v0
/* 3A004C E009E12C 00031080 */  sll       $v0, $v1, 2
/* 3A0050 E009E130 00431021 */  addu      $v0, $v0, $v1
/* 3A0054 E009E134 00021080 */  sll       $v0, $v0, 2
/* 3A0058 E009E138 00A22823 */  subu      $a1, $a1, $v0
/* 3A005C E009E13C 24A5003C */  addiu     $a1, $a1, 0x3c
/* 3A0060 E009E140 44850000 */  mtc1      $a1, $f0
/* 3A0064 E009E144 00000000 */  nop
/* 3A0068 E009E148 46800020 */  cvt.s.w   $f0, $f0
/* 3A006C E009E14C 0C080138 */  jal       func_E02004E0
/* 3A0070 E009E150 E600FFFC */   swc1     $f0, -4($s0)
/* 3A0074 E009E154 44820000 */  mtc1      $v0, $f0
/* 3A0078 E009E158 00000000 */  nop
/* 3A007C E009E15C 46800021 */  cvt.d.w   $f0, $f0
/* 3A0080 E009E160 46340002 */  mul.d     $f0, $f0, $f20
/* 3A0084 E009E164 00000000 */  nop
/* 3A0088 E009E168 46360000 */  add.d     $f0, $f0, $f22
/* 3A008C E009E16C 2404000A */  addiu     $a0, $zero, 0xa
/* 3A0090 E009E170 46200020 */  cvt.s.d   $f0, $f0
/* 3A0094 E009E174 0C080138 */  jal       func_E02004E0
/* 3A0098 E009E178 E600FFF8 */   swc1     $f0, -8($s0)
/* 3A009C E009E17C 44820000 */  mtc1      $v0, $f0
/* 3A00A0 E009E180 00000000 */  nop
/* 3A00A4 E009E184 46800021 */  cvt.d.w   $f0, $f0
/* 3A00A8 E009E188 46340002 */  mul.d     $f0, $f0, $f20
/* 3A00AC E009E18C 00000000 */  nop
/* 3A00B0 E009E190 46340000 */  add.d     $f0, $f0, $f20
/* 3A00B4 E009E194 26310001 */  addiu     $s1, $s1, 1
/* 3A00B8 E009E198 0233102A */  slt       $v0, $s1, $s3
/* 3A00BC E009E19C 46200020 */  cvt.s.d   $f0, $f0
/* 3A00C0 E009E1A0 E6000000 */  swc1      $f0, ($s0)
/* 3A00C4 E009E1A4 1440FFD4 */  bnez      $v0, .LE009E0F8
/* 3A00C8 E009E1A8 26100034 */   addiu    $s0, $s0, 0x34
.LE009E1AC:
/* 3A00CC E009E1AC 0240102D */  daddu     $v0, $s2, $zero
/* 3A00D0 E009E1B0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 3A00D4 E009E1B4 8FB40038 */  lw        $s4, 0x38($sp)
/* 3A00D8 E009E1B8 8FB30034 */  lw        $s3, 0x34($sp)
/* 3A00DC E009E1BC 8FB20030 */  lw        $s2, 0x30($sp)
/* 3A00E0 E009E1C0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3A00E4 E009E1C4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A00E8 E009E1C8 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3A00EC E009E1CC D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3A00F0 E009E1D0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3A00F4 E009E1D4 03E00008 */  jr        $ra
/* 3A00F8 E009E1D8 27BD0058 */   addiu    $sp, $sp, 0x58
