.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001A000
/* 32FE30 E001A000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 32FE34 E001A004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 32FE38 E001A008 4485A000 */  mtc1      $a1, $f20
/* 32FE3C E001A00C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 32FE40 E001A010 4486C000 */  mtc1      $a2, $f24
/* 32FE44 E001A014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32FE48 E001A018 0080882D */  daddu     $s1, $a0, $zero
/* 32FE4C E001A01C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 32FE50 E001A020 4487B000 */  mtc1      $a3, $f22
/* 32FE54 E001A024 27A40010 */  addiu     $a0, $sp, 0x10
/* 32FE58 E001A028 AFB20030 */  sw        $s2, 0x30($sp)
/* 32FE5C E001A02C 8FB20060 */  lw        $s2, 0x60($sp)
/* 32FE60 E001A030 3C02E002 */  lui       $v0, %hi(D_E001A21C)
/* 32FE64 E001A034 2442A21C */  addiu     $v0, $v0, %lo(D_E001A21C)
/* 32FE68 E001A038 AFA20018 */  sw        $v0, 0x18($sp)
/* 32FE6C E001A03C 3C02E002 */  lui       $v0, %hi(D_E001A224)
/* 32FE70 E001A040 2442A224 */  addiu     $v0, $v0, %lo(D_E001A224)
/* 32FE74 E001A044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32FE78 E001A048 3C02E002 */  lui       $v0, %hi(D_E001A3FC)
/* 32FE7C E001A04C 2442A3FC */  addiu     $v0, $v0, %lo(D_E001A3FC)
/* 32FE80 E001A050 AFA20020 */  sw        $v0, 0x20($sp)
/* 32FE84 E001A054 2402000D */  addiu     $v0, $zero, 0xd
/* 32FE88 E001A058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 32FE8C E001A05C AFB00028 */  sw        $s0, 0x28($sp)
/* 32FE90 E001A060 AFA00010 */  sw        $zero, 0x10($sp)
/* 32FE94 E001A064 AFA00024 */  sw        $zero, 0x24($sp)
/* 32FE98 E001A068 0C080124 */  jal       func_E0200490
/* 32FE9C E001A06C AFA20014 */   sw       $v0, 0x14($sp)
/* 32FEA0 E001A070 24040048 */  addiu     $a0, $zero, 0x48
/* 32FEA4 E001A074 24030001 */  addiu     $v1, $zero, 1
/* 32FEA8 E001A078 0040802D */  daddu     $s0, $v0, $zero
/* 32FEAC E001A07C 0C08012C */  jal       func_E02004B0
/* 32FEB0 E001A080 AE030008 */   sw       $v1, 8($s0)
/* 32FEB4 E001A084 AE02000C */  sw        $v0, 0xc($s0)
/* 32FEB8 E001A088 0040802D */  daddu     $s0, $v0, $zero
/* 32FEBC E001A08C 56000003 */  bnel      $s0, $zero, .LE001A09C
/* 32FEC0 E001A090 AE110000 */   sw       $s1, ($s0)
.LE001A094:
/* 32FEC4 E001A094 08006825 */  j         .LE001A094
/* 32FEC8 E001A098 00000000 */   nop      
.LE001A09C:
/* 32FECC E001A09C 3C014120 */  lui       $at, 0x4120
/* 32FED0 E001A0A0 44813000 */  mtc1      $at, $f6
/* 32FED4 E001A0A4 E6140004 */  swc1      $f20, 4($s0)
/* 32FED8 E001A0A8 E616000C */  swc1      $f22, 0xc($s0)
/* 32FEDC E001A0AC AE000010 */  sw        $zero, 0x10($s0)
/* 32FEE0 E001A0B0 4606C000 */  add.s     $f0, $f24, $f6
/* 32FEE4 E001A0B4 AE000014 */  sw        $zero, 0x14($s0)
/* 32FEE8 E001A0B8 AE000018 */  sw        $zero, 0x18($s0)
/* 32FEEC E001A0BC 16200018 */  bnez      $s1, .LE001A120
/* 32FEF0 E001A0C0 E6000008 */   swc1     $f0, 8($s0)
/* 32FEF4 E001A0C4 3C013DF5 */  lui       $at, 0x3df5
/* 32FEF8 E001A0C8 3421C28F */  ori       $at, $at, 0xc28f
/* 32FEFC E001A0CC 44810000 */  mtc1      $at, $f0
/* 32FF00 E001A0D0 3C01BC79 */  lui       $at, 0xbc79
/* 32FF04 E001A0D4 3421096C */  ori       $at, $at, 0x96c
/* 32FF08 E001A0D8 44811000 */  mtc1      $at, $f2
/* 32FF0C E001A0DC 3C014040 */  lui       $at, 0x4040
/* 32FF10 E001A0E0 44812000 */  mtc1      $at, $f4
/* 32FF14 E001A0E4 3C02E002 */  lui       $v0, %hi(D_E001A610)
/* 32FF18 E001A0E8 8C42A610 */  lw        $v0, %lo(D_E001A610)($v0)
/* 32FF1C E001A0EC AE000018 */  sw        $zero, 0x18($s0)
/* 32FF20 E001A0F0 AE000024 */  sw        $zero, 0x24($s0)
/* 32FF24 E001A0F4 AE000028 */  sw        $zero, 0x28($s0)
/* 32FF28 E001A0F8 E600001C */  swc1      $f0, 0x1c($s0)
/* 32FF2C E001A0FC E6020020 */  swc1      $f2, 0x20($s0)
/* 32FF30 E001A100 10400004 */  beqz      $v0, .LE001A114
/* 32FF34 E001A104 E604002C */   swc1     $f4, 0x2c($s0)
/* 32FF38 E001A108 3C01C120 */  lui       $at, 0xc120
/* 32FF3C E001A10C 44813000 */  mtc1      $at, $f6
/* 32FF40 E001A110 00000000 */  nop       
.LE001A114:
/* 32FF44 E001A114 E6060030 */  swc1      $f6, 0x30($s0)
/* 32FF48 E001A118 08006876 */  j         .LE001A1D8
/* 32FF4C E001A11C AE120034 */   sw       $s2, 0x34($s0)
.LE001A120:
/* 32FF50 E001A120 3C013DF5 */  lui       $at, 0x3df5
/* 32FF54 E001A124 3421C28F */  ori       $at, $at, 0xc28f
/* 32FF58 E001A128 44810000 */  mtc1      $at, $f0
/* 32FF5C E001A12C 3C01BC79 */  lui       $at, 0xbc79
/* 32FF60 E001A130 3421096C */  ori       $at, $at, 0x96c
/* 32FF64 E001A134 44811000 */  mtc1      $at, $f2
/* 32FF68 E001A138 24040001 */  addiu     $a0, $zero, 1
/* 32FF6C E001A13C E600001C */  swc1      $f0, 0x1c($s0)
/* 32FF70 E001A140 0C080138 */  jal       func_E02004E0
/* 32FF74 E001A144 E6020020 */   swc1     $f2, 0x20($s0)
/* 32FF78 E001A148 24040168 */  addiu     $a0, $zero, 0x168
/* 32FF7C E001A14C 00021900 */  sll       $v1, $v0, 4
/* 32FF80 E001A150 00621823 */  subu      $v1, $v1, $v0
/* 32FF84 E001A154 00031840 */  sll       $v1, $v1, 1
/* 32FF88 E001A158 2463FFF1 */  addiu     $v1, $v1, -0xf
/* 32FF8C E001A15C 44830000 */  mtc1      $v1, $f0
/* 32FF90 E001A160 00000000 */  nop       
/* 32FF94 E001A164 46800020 */  cvt.s.w   $f0, $f0
/* 32FF98 E001A168 0C080138 */  jal       func_E02004E0
/* 32FF9C E001A16C E6000024 */   swc1     $f0, 0x24($s0)
/* 32FFA0 E001A170 24040001 */  addiu     $a0, $zero, 1
/* 32FFA4 E001A174 44820000 */  mtc1      $v0, $f0
/* 32FFA8 E001A178 00000000 */  nop       
/* 32FFAC E001A17C 46800020 */  cvt.s.w   $f0, $f0
/* 32FFB0 E001A180 E6000028 */  swc1      $f0, 0x28($s0)
/* 32FFB4 E001A184 0C080138 */  jal       func_E02004E0
/* 32FFB8 E001A188 AE00002C */   sw       $zero, 0x2c($s0)
/* 32FFBC E001A18C 2404000A */  addiu     $a0, $zero, 0xa
/* 32FFC0 E001A190 000210C0 */  sll       $v0, $v0, 3
/* 32FFC4 E001A194 2442FFFC */  addiu     $v0, $v0, -4
/* 32FFC8 E001A198 44820000 */  mtc1      $v0, $f0
/* 32FFCC E001A19C 00000000 */  nop       
/* 32FFD0 E001A1A0 46800020 */  cvt.s.w   $f0, $f0
/* 32FFD4 E001A1A4 E6000030 */  swc1      $f0, 0x30($s0)
/* 32FFD8 E001A1A8 AE120034 */  sw        $s2, 0x34($s0)
/* 32FFDC E001A1AC 0C080138 */  jal       func_E02004E0
/* 32FFE0 E001A1B0 AE000038 */   sw       $zero, 0x38($s0)
/* 32FFE4 E001A1B4 24040014 */  addiu     $a0, $zero, 0x14
/* 32FFE8 E001A1B8 0C080138 */  jal       func_E02004E0
/* 32FFEC E001A1BC AE020044 */   sw       $v0, 0x44($s0)
/* 32FFF0 E001A1C0 24040001 */  addiu     $a0, $zero, 1
/* 32FFF4 E001A1C4 0C080138 */  jal       func_E02004E0
/* 32FFF8 E001A1C8 AE020040 */   sw       $v0, 0x40($s0)
/* 32FFFC E001A1CC 00021040 */  sll       $v0, $v0, 1
/* 330000 E001A1D0 2442FFFF */  addiu     $v0, $v0, -1
/* 330004 E001A1D4 AE02003C */  sw        $v0, 0x3c($s0)
.LE001A1D8:
/* 330008 E001A1D8 3C03E002 */  lui       $v1, %hi(D_E001A610)
/* 33000C E001A1DC 2463A610 */  addiu     $v1, $v1, %lo(D_E001A610)
/* 330010 E001A1E0 8C620000 */  lw        $v0, ($v1)
/* 330014 E001A1E4 24420001 */  addiu     $v0, $v0, 1
/* 330018 E001A1E8 AC620000 */  sw        $v0, ($v1)
/* 33001C E001A1EC 28420002 */  slti      $v0, $v0, 2
/* 330020 E001A1F0 50400001 */  beql      $v0, $zero, .LE001A1F8
/* 330024 E001A1F4 AC600000 */   sw       $zero, ($v1)
.LE001A1F8:
/* 330028 E001A1F8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 33002C E001A1FC 8FB20030 */  lw        $s2, 0x30($sp)
/* 330030 E001A200 8FB1002C */  lw        $s1, 0x2c($sp)
/* 330034 E001A204 8FB00028 */  lw        $s0, 0x28($sp)
/* 330038 E001A208 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 33003C E001A20C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 330040 E001A210 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 330044 E001A214 03E00008 */  jr        $ra
/* 330048 E001A218 27BD0050 */   addiu    $sp, $sp, 0x50
