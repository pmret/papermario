.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012204
/* 32DF14 E0012204 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 32DF18 E0012208 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 32DF1C E001220C 4485F000 */  mtc1      $a1, $f30
/* 32DF20 E0012210 AFB40038 */  sw        $s4, 0x38($sp)
/* 32DF24 E0012214 0080A02D */  daddu     $s4, $a0, $zero
/* 32DF28 E0012218 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 32DF2C E001221C C7BA0080 */  lwc1      $f26, 0x80($sp)
/* 32DF30 E0012220 27A40010 */  addiu     $a0, $sp, 0x10
/* 32DF34 E0012224 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 32DF38 E0012228 C7BC0084 */  lwc1      $f28, 0x84($sp)
/* 32DF3C E001222C 3C02E001 */  lui       $v0, %hi(func_E0012440)
/* 32DF40 E0012230 24422440 */  addiu     $v0, $v0, %lo(func_E0012440)
/* 32DF44 E0012234 AFA20018 */  sw        $v0, 0x18($sp)
/* 32DF48 E0012238 3C02E001 */  lui       $v0, %hi(func_E0012448)
/* 32DF4C E001223C 24422448 */  addiu     $v0, $v0, %lo(func_E0012448)
/* 32DF50 E0012240 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32DF54 E0012244 3C02E001 */  lui       $v0, %hi(func_E0012504)
/* 32DF58 E0012248 24422504 */  addiu     $v0, $v0, %lo(func_E0012504)
/* 32DF5C E001224C AFA20020 */  sw        $v0, 0x20($sp)
/* 32DF60 E0012250 24020009 */  addiu     $v0, $zero, 9
/* 32DF64 E0012254 AFBF003C */  sw        $ra, 0x3c($sp)
/* 32DF68 E0012258 AFB30034 */  sw        $s3, 0x34($sp)
/* 32DF6C E001225C AFB20030 */  sw        $s2, 0x30($sp)
/* 32DF70 E0012260 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32DF74 E0012264 AFB00028 */  sw        $s0, 0x28($sp)
/* 32DF78 E0012268 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 32DF7C E001226C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 32DF80 E0012270 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 32DF84 E0012274 AFA60078 */  sw        $a2, 0x78($sp)
/* 32DF88 E0012278 AFA7007C */  sw        $a3, 0x7c($sp)
/* 32DF8C E001227C AFA00010 */  sw        $zero, 0x10($sp)
/* 32DF90 E0012280 AFA00024 */  sw        $zero, 0x24($sp)
/* 32DF94 E0012284 0C080124 */  jal       func_E0200490
/* 32DF98 E0012288 AFA20014 */   sw       $v0, 0x14($sp)
/* 32DF9C E001228C 24040098 */  addiu     $a0, $zero, 0x98
/* 32DFA0 E0012290 24130001 */  addiu     $s3, $zero, 1
/* 32DFA4 E0012294 0040802D */  daddu     $s0, $v0, $zero
/* 32DFA8 E0012298 0C08012C */  jal       func_E02004B0
/* 32DFAC E001229C AE130008 */   sw       $s3, 8($s0)
/* 32DFB0 E00122A0 0040882D */  daddu     $s1, $v0, $zero
/* 32DFB4 E00122A4 16200003 */  bnez      $s1, .LE00122B4
/* 32DFB8 E00122A8 AE11000C */   sw       $s1, 0xc($s0)
.LE00122AC:
/* 32DFBC E00122AC 080048AB */  j         .LE00122AC
/* 32DFC0 E00122B0 00000000 */   nop
.LE00122B4:
/* 32DFC4 E00122B4 0220202D */  daddu     $a0, $s1, $zero
/* 32DFC8 E00122B8 00132880 */  sll       $a1, $s3, 2
/* 32DFCC E00122BC 00B32821 */  addu      $a1, $a1, $s3
/* 32DFD0 E00122C0 00052880 */  sll       $a1, $a1, 2
/* 32DFD4 E00122C4 00B32823 */  subu      $a1, $a1, $s3
/* 32DFD8 E00122C8 0C080130 */  jal       func_E02004C0
/* 32DFDC E00122CC 000528C0 */   sll      $a1, $a1, 3
/* 32DFE0 E00122D0 0000902D */  daddu     $s2, $zero, $zero
/* 32DFE4 E00122D4 0253102A */  slt       $v0, $s2, $s3
/* 32DFE8 E00122D8 1040004B */  beqz      $v0, .LE0012408
/* 32DFEC E00122DC 26300094 */   addiu    $s0, $s1, 0x94
/* 32DFF0 E00122E0 3C013F80 */  lui       $at, 0x3f80
/* 32DFF4 E00122E4 4481B000 */  mtc1      $at, $f22
/* 32DFF8 E00122E8 4480C000 */  mtc1      $zero, $f24
.LE00122EC:
/* 32DFFC E00122EC 24020001 */  addiu     $v0, $zero, 1
/* 32E000 E00122F0 AE220000 */  sw        $v0, ($s1)
/* 32E004 E00122F4 A614FF70 */  sh        $s4, -0x90($s0)
/* 32E008 E00122F8 AE00FFE8 */  sw        $zero, -0x18($s0)
/* 32E00C E00122FC E61EFF78 */  swc1      $f30, -0x88($s0)
/* 32E010 E0012300 C7A60078 */  lwc1      $f6, 0x78($sp)
/* 32E014 E0012304 3C0140AC */  lui       $at, 0x40ac
/* 32E018 E0012308 3421CCCD */  ori       $at, $at, 0xcccd
/* 32E01C E001230C 44810000 */  mtc1      $at, $f0
/* 32E020 E0012310 240200FF */  addiu     $v0, $zero, 0xff
/* 32E024 E0012314 E606FF7C */  swc1      $f6, -0x84($s0)
/* 32E028 E0012318 C7A6007C */  lwc1      $f6, 0x7c($sp)
/* 32E02C E001231C 4618E032 */  c.eq.s    $f28, $f24
/* 32E030 E0012320 E616FF84 */  swc1      $f22, -0x7c($s0)
/* 32E034 E0012324 E616FF88 */  swc1      $f22, -0x78($s0)
/* 32E038 E0012328 E616FF8C */  swc1      $f22, -0x74($s0)
/* 32E03C E001232C A202FF74 */  sb        $v0, -0x8c($s0)
/* 32E040 E0012330 E616FFE4 */  swc1      $f22, -0x1c($s0)
/* 32E044 E0012334 E600FFE0 */  swc1      $f0, -0x20($s0)
/* 32E048 E0012338 45010005 */  bc1t      .LE0012350
/* 32E04C E001233C E606FF80 */   swc1     $f6, -0x80($s0)
/* 32E050 E0012340 3C01C120 */  lui       $at, 0xc120
/* 32E054 E0012344 44810000 */  mtc1      $at, $f0
/* 32E058 E0012348 080048D8 */  j         .LE0012360
/* 32E05C E001234C E600FFDC */   swc1     $f0, -0x24($s0)
.LE0012350:
/* 32E060 E0012350 3C014120 */  lui       $at, 0x4120
/* 32E064 E0012354 44810000 */  mtc1      $at, $f0
/* 32E068 E0012358 00000000 */  nop
/* 32E06C E001235C E600FFDC */  swc1      $f0, -0x24($s0)
.LE0012360:
/* 32E070 E0012360 24040064 */  addiu     $a0, $zero, 0x64
/* 32E074 E0012364 3C013F00 */  lui       $at, 0x3f00
/* 32E078 E0012368 44810000 */  mtc1      $at, $f0
/* 32E07C E001236C 3C01BD8F */  lui       $at, 0xbd8f
/* 32E080 E0012370 34215C29 */  ori       $at, $at, 0x5c29
/* 32E084 E0012374 44811000 */  mtc1      $at, $f2
/* 32E088 E0012378 3C013B44 */  lui       $at, 0x3b44
/* 32E08C E001237C 34219BA6 */  ori       $at, $at, 0x9ba6
/* 32E090 E0012380 44812000 */  mtc1      $at, $f4
/* 32E094 E0012384 2402000F */  addiu     $v0, $zero, 0xf
/* 32E098 E0012388 AE00FFF8 */  sw        $zero, -8($s0)
/* 32E09C E001238C A602FF72 */  sh        $v0, -0x8e($s0)
/* 32E0A0 E0012390 E61AFF94 */  swc1      $f26, -0x6c($s0)
/* 32E0A4 E0012394 AE00FF90 */  sw        $zero, -0x70($s0)
/* 32E0A8 E0012398 AE00FF98 */  sw        $zero, -0x68($s0)
/* 32E0AC E001239C E600FFEC */  swc1      $f0, -0x14($s0)
/* 32E0B0 E00123A0 E602FFF0 */  swc1      $f2, -0x10($s0)
/* 32E0B4 E00123A4 0C080138 */  jal       func_E02004E0
/* 32E0B8 E00123A8 E604FFF4 */   swc1     $f4, -0xc($s0)
/* 32E0BC E00123AC 00021103 */  sra       $v0, $v0, 4
/* 32E0C0 E00123B0 30420001 */  andi      $v0, $v0, 1
/* 32E0C4 E00123B4 4618E032 */  c.eq.s    $f28, $f24
/* 32E0C8 E00123B8 3C0142B4 */  lui       $at, 0x42b4
/* 32E0CC E00123BC 44810000 */  mtc1      $at, $f0
/* 32E0D0 E00123C0 45010003 */  bc1t      .LE00123D0
/* 32E0D4 E00123C4 A202FF75 */   sb       $v0, -0x8b($s0)
/* 32E0D8 E00123C8 3C01C2B4 */  lui       $at, 0xc2b4
/* 32E0DC E00123CC 44810000 */  mtc1      $at, $f0
.LE00123D0:
/* 32E0E0 E00123D0 0C08013C */  jal       func_E02004F0
/* 32E0E4 E00123D4 4600D300 */   add.s    $f12, $f26, $f0
/* 32E0E8 E00123D8 46000506 */  mov.s     $f20, $f0
/* 32E0EC E00123DC 0C080140 */  jal       func_E0200500
/* 32E0F0 E00123E0 4600A306 */   mov.s    $f12, $f20
/* 32E0F4 E00123E4 4600A306 */  mov.s     $f12, $f20
/* 32E0F8 E00123E8 0C080144 */  jal       func_E0200510
/* 32E0FC E00123EC E600FFFC */   swc1     $f0, -4($s0)
/* 32E100 E00123F0 26520001 */  addiu     $s2, $s2, 1
/* 32E104 E00123F4 E6000000 */  swc1      $f0, ($s0)
/* 32E108 E00123F8 26100098 */  addiu     $s0, $s0, 0x98
/* 32E10C E00123FC 0253102A */  slt       $v0, $s2, $s3
/* 32E110 E0012400 1440FFBA */  bnez      $v0, .LE00122EC
/* 32E114 E0012404 26310098 */   addiu    $s1, $s1, 0x98
.LE0012408:
/* 32E118 E0012408 8FBF003C */  lw        $ra, 0x3c($sp)
/* 32E11C E001240C 8FB40038 */  lw        $s4, 0x38($sp)
/* 32E120 E0012410 8FB30034 */  lw        $s3, 0x34($sp)
/* 32E124 E0012414 8FB20030 */  lw        $s2, 0x30($sp)
/* 32E128 E0012418 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32E12C E001241C 8FB00028 */  lw        $s0, 0x28($sp)
/* 32E130 E0012420 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 32E134 E0012424 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 32E138 E0012428 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 32E13C E001242C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 32E140 E0012430 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 32E144 E0012434 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 32E148 E0012438 03E00008 */  jr        $ra
/* 32E14C E001243C 27BD0070 */   addiu    $sp, $sp, 0x70
