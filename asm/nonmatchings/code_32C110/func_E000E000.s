.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000E000
/* 32C110 E000E000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 32C114 E000E004 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 32C118 E000E008 4485B000 */  mtc1      $a1, $f22
/* 32C11C E000E00C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 32C120 E000E010 4486C000 */  mtc1      $a2, $f24
/* 32C124 E000E014 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 32C128 E000E018 4487D000 */  mtc1      $a3, $f26
/* 32C12C E000E01C AFB30034 */  sw        $s3, 0x34($sp)
/* 32C130 E000E020 0080982D */  daddu     $s3, $a0, $zero
/* 32C134 E000E024 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 32C138 E000E028 C7BC0078 */  lwc1      $f28, 0x78($sp)
/* 32C13C E000E02C 27A40010 */  addiu     $a0, $sp, 0x10
/* 32C140 E000E030 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 32C144 E000E034 C7B4007C */  lwc1      $f20, 0x7c($sp)
/* 32C148 E000E038 3C02E001 */  lui       $v0, %hi(D_E000E16C)
/* 32C14C E000E03C 2442E16C */  addiu     $v0, $v0, %lo(D_E000E16C)
/* 32C150 E000E040 AFA20018 */  sw        $v0, 0x18($sp)
/* 32C154 E000E044 3C02E001 */  lui       $v0, %hi(D_E000E174)
/* 32C158 E000E048 2442E174 */  addiu     $v0, $v0, %lo(D_E000E174)
/* 32C15C E000E04C AFA2001C */  sw        $v0, 0x1c($sp)
/* 32C160 E000E050 3C02E001 */  lui       $v0, %hi(D_E000E244)
/* 32C164 E000E054 2442E244 */  addiu     $v0, $v0, %lo(D_E000E244)
/* 32C168 E000E058 AFA20020 */  sw        $v0, 0x20($sp)
/* 32C16C E000E05C 24020007 */  addiu     $v0, $zero, 7
/* 32C170 E000E060 AFBF0038 */  sw        $ra, 0x38($sp)
/* 32C174 E000E064 AFB20030 */  sw        $s2, 0x30($sp)
/* 32C178 E000E068 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32C17C E000E06C AFB00028 */  sw        $s0, 0x28($sp)
/* 32C180 E000E070 AFA00010 */  sw        $zero, 0x10($sp)
/* 32C184 E000E074 AFA00024 */  sw        $zero, 0x24($sp)
/* 32C188 E000E078 0C080124 */  jal       func_E0200490
/* 32C18C E000E07C AFA20014 */   sw       $v0, 0x14($sp)
/* 32C190 E000E080 24040078 */  addiu     $a0, $zero, 0x78
/* 32C194 E000E084 24120001 */  addiu     $s2, $zero, 1
/* 32C198 E000E088 0040802D */  daddu     $s0, $v0, $zero
/* 32C19C E000E08C 0C08012C */  jal       func_E02004B0
/* 32C1A0 E000E090 AE120008 */   sw       $s2, 8($s0)
/* 32C1A4 E000E094 0040882D */  daddu     $s1, $v0, $zero
/* 32C1A8 E000E098 16200003 */  bnez      $s1, .LE000E0A8
/* 32C1AC E000E09C AE11000C */   sw       $s1, 0xc($s0)
.LE000E0A0:
/* 32C1B0 E000E0A0 08003828 */  j         .LE000E0A0
/* 32C1B4 E000E0A4 00000000 */   nop      
.LE000E0A8:
/* 32C1B8 E000E0A8 0220202D */  daddu     $a0, $s1, $zero
/* 32C1BC E000E0AC 00122900 */  sll       $a1, $s2, 4
/* 32C1C0 E000E0B0 00B22823 */  subu      $a1, $a1, $s2
/* 32C1C4 E000E0B4 0C080130 */  jal       func_E02004C0
/* 32C1C8 E000E0B8 000528C0 */   sll      $a1, $a1, 3
/* 32C1CC E000E0BC 0000202D */  daddu     $a0, $zero, $zero
/* 32C1D0 E000E0C0 3A620002 */  xori      $v0, $s3, 2
/* 32C1D4 E000E0C4 2C420001 */  sltiu     $v0, $v0, 1
/* 32C1D8 E000E0C8 AE22006C */  sw        $v0, 0x6c($s1)
/* 32C1DC E000E0CC 0092102A */  slt       $v0, $a0, $s2
/* 32C1E0 E000E0D0 AE200070 */  sw        $zero, 0x70($s1)
/* 32C1E4 E000E0D4 10400019 */  beqz      $v0, .LE000E13C
/* 32C1E8 E000E0D8 A6330004 */   sh       $s3, 4($s1)
/* 32C1EC E000E0DC 24050001 */  addiu     $a1, $zero, 1
/* 32C1F0 E000E0E0 26230060 */  addiu     $v1, $s1, 0x60
/* 32C1F4 E000E0E4 3C013EAA */  lui       $at, 0x3eaa
/* 32C1F8 E000E0E8 3421AAAB */  ori       $at, $at, 0xaaab
/* 32C1FC E000E0EC 44812000 */  mtc1      $at, $f4
/* 32C200 E000E0F0 3C013FE0 */  lui       $at, 0x3fe0
/* 32C204 E000E0F4 44811000 */  mtc1      $at, $f2
/* 32C208 E000E0F8 3C01BE23 */  lui       $at, 0xbe23
/* 32C20C E000E0FC 3421D70A */  ori       $at, $at, 0xd70a
/* 32C210 E000E100 44810000 */  mtc1      $at, $f0
.LE000E104:
/* 32C214 E000E104 24840001 */  addiu     $a0, $a0, 1
/* 32C218 E000E108 AE250000 */  sw        $a1, ($s1)
/* 32C21C E000E10C E47C0004 */  swc1      $f28, 4($v1)
/* 32C220 E000E110 E4740008 */  swc1      $f20, 8($v1)
/* 32C224 E000E114 E476FFA8 */  swc1      $f22, -0x58($v1)
/* 32C228 E000E118 E478FFAC */  swc1      $f24, -0x54($v1)
/* 32C22C E000E11C E47AFFB0 */  swc1      $f26, -0x50($v1)
/* 32C230 E000E120 E464FFF8 */  swc1      $f4, -8($v1)
/* 32C234 E000E124 E462FFFC */  swc1      $f2, -4($v1)
/* 32C238 E000E128 E4600000 */  swc1      $f0, ($v1)
/* 32C23C E000E12C 24630078 */  addiu     $v1, $v1, 0x78
/* 32C240 E000E130 0092102A */  slt       $v0, $a0, $s2
/* 32C244 E000E134 1440FFF3 */  bnez      $v0, .LE000E104
/* 32C248 E000E138 26310078 */   addiu    $s1, $s1, 0x78
.LE000E13C:
/* 32C24C E000E13C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 32C250 E000E140 8FB30034 */  lw        $s3, 0x34($sp)
/* 32C254 E000E144 8FB20030 */  lw        $s2, 0x30($sp)
/* 32C258 E000E148 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32C25C E000E14C 8FB00028 */  lw        $s0, 0x28($sp)
/* 32C260 E000E150 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 32C264 E000E154 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 32C268 E000E158 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 32C26C E000E15C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 32C270 E000E160 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 32C274 E000E164 03E00008 */  jr        $ra
/* 32C278 E000E168 27BD0068 */   addiu    $sp, $sp, 0x68
