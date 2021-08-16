.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0026000
/* 33B180 E0026000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 33B184 E0026004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 33B188 E0026008 4485A000 */  mtc1      $a1, $f20
/* 33B18C E002600C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 33B190 E0026010 4486B000 */  mtc1      $a2, $f22
/* 33B194 E0026014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 33B198 E0026018 0080882D */  daddu     $s1, $a0, $zero
/* 33B19C E002601C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 33B1A0 E0026020 4487C000 */  mtc1      $a3, $f24
/* 33B1A4 E0026024 27A40010 */  addiu     $a0, $sp, 0x10
/* 33B1A8 E0026028 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 33B1AC E002602C C7BA0068 */  lwc1      $f26, 0x68($sp)
/* 33B1B0 E0026030 3C02E002 */  lui       $v0, %hi(func_E0026184)
/* 33B1B4 E0026034 24426184 */  addiu     $v0, $v0, %lo(func_E0026184)
/* 33B1B8 E0026038 AFA20018 */  sw        $v0, 0x18($sp)
/* 33B1BC E002603C 3C02E002 */  lui       $v0, %hi(func_E002618C)
/* 33B1C0 E0026040 2442618C */  addiu     $v0, $v0, %lo(func_E002618C)
/* 33B1C4 E0026044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33B1C8 E0026048 3C02E002 */  lui       $v0, %hi(func_E00264B0)
/* 33B1CC E002604C 244264B0 */  addiu     $v0, $v0, %lo(func_E00264B0)
/* 33B1D0 E0026050 AFA20020 */  sw        $v0, 0x20($sp)
/* 33B1D4 E0026054 24020013 */  addiu     $v0, $zero, 0x13
/* 33B1D8 E0026058 AFBF0030 */  sw        $ra, 0x30($sp)
/* 33B1DC E002605C AFB00028 */  sw        $s0, 0x28($sp)
/* 33B1E0 E0026060 AFA00010 */  sw        $zero, 0x10($sp)
/* 33B1E4 E0026064 AFA00024 */  sw        $zero, 0x24($sp)
/* 33B1E8 E0026068 0C080124 */  jal       func_E0200490
/* 33B1EC E002606C AFA20014 */   sw       $v0, 0x14($sp)
/* 33B1F0 E0026070 24040060 */  addiu     $a0, $zero, 0x60
/* 33B1F4 E0026074 24030001 */  addiu     $v1, $zero, 1
/* 33B1F8 E0026078 0040802D */  daddu     $s0, $v0, $zero
/* 33B1FC E002607C 0C08012C */  jal       func_E02004B0
/* 33B200 E0026080 AE030008 */   sw       $v1, 8($s0)
/* 33B204 E0026084 AE02000C */  sw        $v0, 0xc($s0)
/* 33B208 E0026088 0040802D */  daddu     $s0, $v0, $zero
/* 33B20C E002608C 56000003 */  bnel      $s0, $zero, .LE002609C
/* 33B210 E0026090 AE110000 */   sw       $s1, ($s0)
.LE0026094:
/* 33B214 E0026094 08009825 */  j         .LE0026094
/* 33B218 E0026098 00000000 */   nop
.LE002609C:
/* 33B21C E002609C 3C014120 */  lui       $at, 0x4120
/* 33B220 E00260A0 44810000 */  mtc1      $at, $f0
/* 33B224 E00260A4 8FA2006C */  lw        $v0, 0x6c($sp)
/* 33B228 E00260A8 24040168 */  addiu     $a0, $zero, 0x168
/* 33B22C E00260AC AE00002C */  sw        $zero, 0x2c($s0)
/* 33B230 E00260B0 AE000024 */  sw        $zero, 0x24($s0)
/* 33B234 E00260B4 E6140010 */  swc1      $f20, 0x10($s0)
/* 33B238 E00260B8 E6160014 */  swc1      $f22, 0x14($s0)
/* 33B23C E00260BC E6180018 */  swc1      $f24, 0x18($s0)
/* 33B240 E00260C0 AE000044 */  sw        $zero, 0x44($s0)
/* 33B244 E00260C4 AE000040 */  sw        $zero, 0x40($s0)
/* 33B248 E00260C8 AE00004C */  sw        $zero, 0x4c($s0)
/* 33B24C E00260CC AE000048 */  sw        $zero, 0x48($s0)
/* 33B250 E00260D0 AE000034 */  sw        $zero, 0x34($s0)
/* 33B254 E00260D4 AE000030 */  sw        $zero, 0x30($s0)
/* 33B258 E00260D8 AE00003C */  sw        $zero, 0x3c($s0)
/* 33B25C E00260DC AE000038 */  sw        $zero, 0x38($s0)
/* 33B260 E00260E0 E6140004 */  swc1      $f20, 4($s0)
/* 33B264 E00260E4 E6160008 */  swc1      $f22, 8($s0)
/* 33B268 E00260E8 E618000C */  swc1      $f24, 0xc($s0)
/* 33B26C E00260EC AE020028 */  sw        $v0, 0x28($s0)
/* 33B270 E00260F0 0C080000 */  jal       func_E0200000
/* 33B274 E00260F4 E600001C */   swc1     $f0, 0x1c($s0)
/* 33B278 E00260F8 44820000 */  mtc1      $v0, $f0
/* 33B27C E00260FC 00000000 */  nop
/* 33B280 E0026100 46800020 */  cvt.s.w   $f0, $f0
/* 33B284 E0026104 3C014080 */  lui       $at, 0x4080
/* 33B288 E0026108 44811000 */  mtc1      $at, $f2
/* 33B28C E002610C 24020001 */  addiu     $v0, $zero, 1
/* 33B290 E0026110 E6000058 */  swc1      $f0, 0x58($s0)
/* 33B294 E0026114 AE000050 */  sw        $zero, 0x50($s0)
/* 33B298 E0026118 AE000054 */  sw        $zero, 0x54($s0)
/* 33B29C E002611C 16220005 */  bne       $s1, $v0, .LE0026134
/* 33B2A0 E0026120 E602005C */   swc1     $f2, 0x5c($s0)
/* 33B2A4 E0026124 24020060 */  addiu     $v0, $zero, 0x60
/* 33B2A8 E0026128 AE02003C */  sw        $v0, 0x3c($s0)
/* 33B2AC E002612C 08009858 */  j         .LE0026160
/* 33B2B0 E0026130 E61A0020 */   swc1     $f26, 0x20($s0)
.LE0026134:
/* 33B2B4 E0026134 3C01E002 */  lui       $at, %hi(D_E0026A20)
/* 33B2B8 E0026138 D4226A20 */  ldc1      $f2, %lo(D_E0026A20)($at)
/* 33B2BC E002613C 4600D021 */  cvt.d.s   $f0, $f26
/* 33B2C0 E0026140 46220002 */  mul.d     $f0, $f0, $f2
/* 33B2C4 E0026144 00000000 */  nop
/* 33B2C8 E0026148 2402FFFE */  addiu     $v0, $zero, -2
/* 33B2CC E002614C AE020044 */  sw        $v0, 0x44($s0)
/* 33B2D0 E0026150 2402FFFC */  addiu     $v0, $zero, -4
/* 33B2D4 E0026154 AE02004C */  sw        $v0, 0x4c($s0)
/* 33B2D8 E0026158 46200020 */  cvt.s.d   $f0, $f0
/* 33B2DC E002615C E6000020 */  swc1      $f0, 0x20($s0)
.LE0026160:
/* 33B2E0 E0026160 8FBF0030 */  lw        $ra, 0x30($sp)
/* 33B2E4 E0026164 8FB1002C */  lw        $s1, 0x2c($sp)
/* 33B2E8 E0026168 8FB00028 */  lw        $s0, 0x28($sp)
/* 33B2EC E002616C D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 33B2F0 E0026170 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 33B2F4 E0026174 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 33B2F8 E0026178 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 33B2FC E002617C 03E00008 */  jr        $ra
/* 33B300 E0026180 27BD0058 */   addiu    $sp, $sp, 0x58
