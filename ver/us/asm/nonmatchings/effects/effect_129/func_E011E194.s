.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011E194
/* 409B24 E011E194 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 409B28 E011E198 AFB30024 */  sw        $s3, 0x24($sp)
/* 409B2C E011E19C 0080982D */  daddu     $s3, $a0, $zero
/* 409B30 E011E1A0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 409B34 E011E1A4 AFB20020 */  sw        $s2, 0x20($sp)
/* 409B38 E011E1A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 409B3C E011E1AC AFB00018 */  sw        $s0, 0x18($sp)
/* 409B40 E011E1B0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 409B44 E011E1B4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 409B48 E011E1B8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 409B4C E011E1BC 8E630000 */  lw        $v1, ($s3)
/* 409B50 E011E1C0 8E71000C */  lw        $s1, 0xc($s3)
/* 409B54 E011E1C4 30620010 */  andi      $v0, $v1, 0x10
/* 409B58 E011E1C8 10400005 */  beqz      $v0, .LE011E1E0
/* 409B5C E011E1CC 2402FFEF */   addiu    $v0, $zero, -0x11
/* 409B60 E011E1D0 00621024 */  and       $v0, $v1, $v0
/* 409B64 E011E1D4 AE620000 */  sw        $v0, ($s3)
/* 409B68 E011E1D8 24020010 */  addiu     $v0, $zero, 0x10
/* 409B6C E011E1DC AE220010 */  sw        $v0, 0x10($s1)
.LE011E1E0:
/* 409B70 E011E1E0 8E230010 */  lw        $v1, 0x10($s1)
/* 409B74 E011E1E4 286203E8 */  slti      $v0, $v1, 0x3e8
/* 409B78 E011E1E8 10400002 */  beqz      $v0, .LE011E1F4
/* 409B7C E011E1EC 2462FFFF */   addiu    $v0, $v1, -1
/* 409B80 E011E1F0 AE220010 */  sw        $v0, 0x10($s1)
.LE011E1F4:
/* 409B84 E011E1F4 8E220014 */  lw        $v0, 0x14($s1)
/* 409B88 E011E1F8 8E240010 */  lw        $a0, 0x10($s1)
/* 409B8C E011E1FC 24430001 */  addiu     $v1, $v0, 1
/* 409B90 E011E200 04810085 */  bgez      $a0, .LE011E418
/* 409B94 E011E204 AE230014 */   sw       $v1, 0x14($s1)
/* 409B98 E011E208 0C080150 */  jal       func_E0200540
/* 409B9C E011E20C 2404007A */   addiu    $a0, $zero, 0x7a
/* 409BA0 E011E210 0000902D */  daddu     $s2, $zero, $zero
/* 409BA4 E011E214 3C01E012 */  lui       $at, %hi(D_E011E810)
/* 409BA8 E011E218 D438E810 */  ldc1      $f24, %lo(D_E011E810)($at)
.LE011E21C:
/* 409BAC E011E21C 0C080138 */  jal       func_E02004E0
/* 409BB0 E011E220 24040014 */   addiu    $a0, $zero, 0x14
/* 409BB4 E011E224 C6340004 */  lwc1      $f20, 4($s1)
/* 409BB8 E011E228 44820000 */  mtc1      $v0, $f0
/* 409BBC E011E22C 00000000 */  nop
/* 409BC0 E011E230 46800020 */  cvt.s.w   $f0, $f0
/* 409BC4 E011E234 4600A500 */  add.s     $f20, $f20, $f0
/* 409BC8 E011E238 3C014120 */  lui       $at, 0x4120
/* 409BCC E011E23C 44810000 */  mtc1      $at, $f0
/* 409BD0 E011E240 24040028 */  addiu     $a0, $zero, 0x28
/* 409BD4 E011E244 0C080138 */  jal       func_E02004E0
/* 409BD8 E011E248 4600A501 */   sub.s    $f20, $f20, $f0
/* 409BDC E011E24C C6220020 */  lwc1      $f2, 0x20($s1)
/* 409BE0 E011E250 44820000 */  mtc1      $v0, $f0
/* 409BE4 E011E254 00000000 */  nop
/* 409BE8 E011E258 46800020 */  cvt.s.w   $f0, $f0
/* 409BEC E011E25C 46020002 */  mul.s     $f0, $f0, $f2
/* 409BF0 E011E260 00000000 */  nop
/* 409BF4 E011E264 C6360008 */  lwc1      $f22, 8($s1)
/* 409BF8 E011E268 2404000A */  addiu     $a0, $zero, 0xa
/* 409BFC E011E26C 0C080138 */  jal       func_E02004E0
/* 409C00 E011E270 4600B580 */   add.s    $f22, $f22, $f0
/* 409C04 E011E274 3C01E012 */  lui       $at, %hi(D_E011E818)
/* 409C08 E011E278 D422E818 */  ldc1      $f2, %lo(D_E011E818)($at)
/* 409C0C E011E27C 44820000 */  mtc1      $v0, $f0
/* 409C10 E011E280 00000000 */  nop
/* 409C14 E011E284 46800021 */  cvt.d.w   $f0, $f0
/* 409C18 E011E288 46220002 */  mul.d     $f0, $f0, $f2
/* 409C1C E011E28C 00000000 */  nop
/* 409C20 E011E290 46380002 */  mul.d     $f0, $f0, $f24
/* 409C24 E011E294 00000000 */  nop
/* 409C28 E011E298 001227C2 */  srl       $a0, $s2, 0x1f
/* 409C2C E011E29C 02442021 */  addu      $a0, $s2, $a0
/* 409C30 E011E2A0 3C01E012 */  lui       $at, %hi(D_E011E820)
/* 409C34 E011E2A4 D422E820 */  ldc1      $f2, %lo(D_E011E820)($at)
/* 409C38 E011E2A8 C6240020 */  lwc1      $f4, 0x20($s1)
/* 409C3C E011E2AC 46220000 */  add.d     $f0, $f0, $f2
/* 409C40 E011E2B0 00042043 */  sra       $a0, $a0, 1
/* 409C44 E011E2B4 46002121 */  cvt.d.s   $f4, $f4
/* 409C48 E011E2B8 46202102 */  mul.d     $f4, $f4, $f0
/* 409C4C E011E2BC 00000000 */  nop
/* 409C50 E011E2C0 00042040 */  sll       $a0, $a0, 1
/* 409C54 E011E2C4 02442023 */  subu      $a0, $s2, $a0
/* 409C58 E011E2C8 24840002 */  addiu     $a0, $a0, 2
/* 409C5C E011E2CC 4405A000 */  mfc1      $a1, $f20
/* 409C60 E011E2D0 C622000C */  lwc1      $f2, 0xc($s1)
/* 409C64 E011E2D4 3C014040 */  lui       $at, 0x4040
/* 409C68 E011E2D8 44810000 */  mtc1      $at, $f0
/* 409C6C E011E2DC 4406B000 */  mfc1      $a2, $f22
/* 409C70 E011E2E0 46001080 */  add.s     $f2, $f2, $f0
/* 409C74 E011E2E4 2642001E */  addiu     $v0, $s2, 0x1e
/* 409C78 E011E2E8 AFA20014 */  sw        $v0, 0x14($sp)
/* 409C7C E011E2EC 44071000 */  mfc1      $a3, $f2
/* 409C80 E011E2F0 46202120 */  cvt.s.d   $f4, $f4
/* 409C84 E011E2F4 0C044000 */  jal       fx_122_main
/* 409C88 E011E2F8 E7A40010 */   swc1     $f4, 0x10($sp)
/* 409C8C E011E2FC 2404000A */  addiu     $a0, $zero, 0xa
/* 409C90 E011E300 0C080138 */  jal       func_E02004E0
/* 409C94 E011E304 0040802D */   daddu    $s0, $v0, $zero
/* 409C98 E011E308 44820000 */  mtc1      $v0, $f0
/* 409C9C E011E30C 00000000 */  nop
/* 409CA0 E011E310 46800021 */  cvt.d.w   $f0, $f0
/* 409CA4 E011E314 46380002 */  mul.d     $f0, $f0, $f24
/* 409CA8 E011E318 00000000 */  nop
/* 409CAC E011E31C 2404001E */  addiu     $a0, $zero, 0x1e
/* 409CB0 E011E320 8E02000C */  lw        $v0, 0xc($s0)
/* 409CB4 E011E324 46200020 */  cvt.s.d   $f0, $f0
/* 409CB8 E011E328 0C080138 */  jal       func_E02004E0
/* 409CBC E011E32C E4400044 */   swc1     $f0, 0x44($v0)
/* 409CC0 E011E330 3C01E012 */  lui       $at, %hi(D_E011E828)
/* 409CC4 E011E334 D422E828 */  ldc1      $f2, %lo(D_E011E828)($at)
/* 409CC8 E011E338 44820000 */  mtc1      $v0, $f0
/* 409CCC E011E33C 00000000 */  nop
/* 409CD0 E011E340 46800021 */  cvt.d.w   $f0, $f0
/* 409CD4 E011E344 46220002 */  mul.d     $f0, $f0, $f2
/* 409CD8 E011E348 00000000 */  nop
/* 409CDC E011E34C 46380000 */  add.d     $f0, $f0, $f24
/* 409CE0 E011E350 24040167 */  addiu     $a0, $zero, 0x167
/* 409CE4 E011E354 8E02000C */  lw        $v0, 0xc($s0)
/* 409CE8 E011E358 46200020 */  cvt.s.d   $f0, $f0
/* 409CEC E011E35C 0C080138 */  jal       func_E02004E0
/* 409CF0 E011E360 E4400048 */   swc1     $f0, 0x48($v0)
/* 409CF4 E011E364 24040014 */  addiu     $a0, $zero, 0x14
/* 409CF8 E011E368 8E03000C */  lw        $v1, 0xc($s0)
/* 409CFC E011E36C 44820000 */  mtc1      $v0, $f0
/* 409D00 E011E370 00000000 */  nop
/* 409D04 E011E374 46800020 */  cvt.s.w   $f0, $f0
/* 409D08 E011E378 0C080138 */  jal       func_E02004E0
/* 409D0C E011E37C E460003C */   swc1     $f0, 0x3c($v1)
/* 409D10 E011E380 2404000A */  addiu     $a0, $zero, 0xa
/* 409D14 E011E384 8E03000C */  lw        $v1, 0xc($s0)
/* 409D18 E011E388 44820000 */  mtc1      $v0, $f0
/* 409D1C E011E38C 00000000 */  nop
/* 409D20 E011E390 46800020 */  cvt.s.w   $f0, $f0
/* 409D24 E011E394 0C080138 */  jal       func_E02004E0
/* 409D28 E011E398 E4600040 */   swc1     $f0, 0x40($v1)
/* 409D2C E011E39C 2404000A */  addiu     $a0, $zero, 0xa
/* 409D30 E011E3A0 2442FFFB */  addiu     $v0, $v0, -5
/* 409D34 E011E3A4 8E03000C */  lw        $v1, 0xc($s0)
/* 409D38 E011E3A8 44820000 */  mtc1      $v0, $f0
/* 409D3C E011E3AC 00000000 */  nop
/* 409D40 E011E3B0 46800020 */  cvt.s.w   $f0, $f0
/* 409D44 E011E3B4 0C080138 */  jal       func_E02004E0
/* 409D48 E011E3B8 E460004C */   swc1     $f0, 0x4c($v1)
/* 409D4C E011E3BC 2442FFFB */  addiu     $v0, $v0, -5
/* 409D50 E011E3C0 8E03000C */  lw        $v1, 0xc($s0)
/* 409D54 E011E3C4 44820000 */  mtc1      $v0, $f0
/* 409D58 E011E3C8 00000000 */  nop
/* 409D5C E011E3CC 46800020 */  cvt.s.w   $f0, $f0
/* 409D60 E011E3D0 E4600050 */  swc1      $f0, 0x50($v1)
/* 409D64 E011E3D4 8E02000C */  lw        $v0, 0xc($s0)
/* 409D68 E011E3D8 3C01BDCC */  lui       $at, 0xbdcc
/* 409D6C E011E3DC 3421CCCD */  ori       $at, $at, 0xcccd
/* 409D70 E011E3E0 44810000 */  mtc1      $at, $f0
/* 409D74 E011E3E4 AC400054 */  sw        $zero, 0x54($v0)
/* 409D78 E011E3E8 8E02000C */  lw        $v0, 0xc($s0)
/* 409D7C E011E3EC 26520001 */  addiu     $s2, $s2, 1
/* 409D80 E011E3F0 E4400058 */  swc1      $f0, 0x58($v0)
/* 409D84 E011E3F4 2A420014 */  slti      $v0, $s2, 0x14
/* 409D88 E011E3F8 1440FF88 */  bnez      $v0, .LE011E21C
/* 409D8C E011E3FC 00000000 */   nop
/* 409D90 E011E400 0C080128 */  jal       func_E02004A0
/* 409D94 E011E404 8E240028 */   lw       $a0, 0x28($s1)
/* 409D98 E011E408 0C080128 */  jal       func_E02004A0
/* 409D9C E011E40C 0260202D */   daddu    $a0, $s3, $zero
/* 409DA0 E011E410 08047942 */  j         .LE011E508
/* 409DA4 E011E414 00000000 */   nop
.LE011E418:
/* 409DA8 E011E418 0080802D */  daddu     $s0, $a0, $zero
/* 409DAC E011E41C 92220025 */  lbu       $v0, 0x25($s1)
/* 409DB0 E011E420 2442FFFF */  addiu     $v0, $v0, -1
/* 409DB4 E011E424 A2220025 */  sb        $v0, 0x25($s1)
/* 409DB8 E011E428 00021600 */  sll       $v0, $v0, 0x18
/* 409DBC E011E42C 04410005 */  bgez      $v0, .LE011E444
/* 409DC0 E011E430 0060902D */   daddu    $s2, $v1, $zero
/* 409DC4 E011E434 0C080138 */  jal       func_E02004E0
/* 409DC8 E011E438 2404003C */   addiu    $a0, $zero, 0x3c
/* 409DCC E011E43C 24420008 */  addiu     $v0, $v0, 8
/* 409DD0 E011E440 A2220025 */  sb        $v0, 0x25($s1)
.LE011E444:
/* 409DD4 E011E444 92220025 */  lbu       $v0, 0x25($s1)
/* 409DD8 E011E448 00022600 */  sll       $a0, $v0, 0x18
/* 409DDC E011E44C 00041E03 */  sra       $v1, $a0, 0x18
/* 409DE0 E011E450 28620008 */  slti      $v0, $v1, 8
/* 409DE4 E011E454 10400005 */  beqz      $v0, .LE011E46C
/* 409DE8 E011E458 000417C2 */   srl      $v0, $a0, 0x1f
/* 409DEC E011E45C 00621021 */  addu      $v0, $v1, $v0
/* 409DF0 E011E460 00021043 */  sra       $v0, $v0, 1
/* 409DF4 E011E464 0804791C */  j         .LE011E470
/* 409DF8 E011E468 A2220024 */   sb       $v0, 0x24($s1)
.LE011E46C:
/* 409DFC E011E46C A2200024 */  sb        $zero, 0x24($s1)
.LE011E470:
/* 409E00 E011E470 2A020011 */  slti      $v0, $s0, 0x11
/* 409E04 E011E474 14400015 */  bnez      $v0, .LE011E4CC
/* 409E08 E011E478 3242000F */   andi     $v0, $s2, 0xf
/* 409E0C E011E47C 14400013 */  bnez      $v0, .LE011E4CC
/* 409E10 E011E480 00000000 */   nop
/* 409E14 E011E484 0C080150 */  jal       func_E0200540
/* 409E18 E011E488 2404006F */   addiu    $a0, $zero, 0x6f
/* 409E1C E011E48C C6220020 */  lwc1      $f2, 0x20($s1)
/* 409E20 E011E490 3C014220 */  lui       $at, 0x4220
/* 409E24 E011E494 44810000 */  mtc1      $at, $f0
/* 409E28 E011E498 00000000 */  nop
/* 409E2C E011E49C 46001002 */  mul.s     $f0, $f2, $f0
/* 409E30 E011E4A0 00000000 */  nop
/* 409E34 E011E4A4 C6240008 */  lwc1      $f4, 8($s1)
/* 409E38 E011E4A8 2402001E */  addiu     $v0, $zero, 0x1e
/* 409E3C E011E4AC AFA20014 */  sw        $v0, 0x14($sp)
/* 409E40 E011E4B0 E7A20010 */  swc1      $f2, 0x10($sp)
/* 409E44 E011E4B4 46002100 */  add.s     $f4, $f4, $f0
/* 409E48 E011E4B8 8E250004 */  lw        $a1, 4($s1)
/* 409E4C E011E4BC 8E27000C */  lw        $a3, 0xc($s1)
/* 409E50 E011E4C0 44062000 */  mfc1      $a2, $f4
/* 409E54 E011E4C4 0C037800 */  jal       fx_111_main
/* 409E58 E011E4C8 24040002 */   addiu    $a0, $zero, 2
.LE011E4CC:
/* 409E5C E011E4CC 8E220028 */  lw        $v0, 0x28($s1)
/* 409E60 E011E4D0 C6200004 */  lwc1      $f0, 4($s1)
/* 409E64 E011E4D4 3C014120 */  lui       $at, 0x4120
/* 409E68 E011E4D8 44811000 */  mtc1      $at, $f2
/* 409E6C E011E4DC 8C42000C */  lw        $v0, 0xc($v0)
/* 409E70 E011E4E0 E4400004 */  swc1      $f0, 4($v0)
/* 409E74 E011E4E4 C6200008 */  lwc1      $f0, 8($s1)
/* 409E78 E011E4E8 8E220028 */  lw        $v0, 0x28($s1)
/* 409E7C E011E4EC 46020000 */  add.s     $f0, $f0, $f2
/* 409E80 E011E4F0 8C42000C */  lw        $v0, 0xc($v0)
/* 409E84 E011E4F4 E4400008 */  swc1      $f0, 8($v0)
/* 409E88 E011E4F8 8E220028 */  lw        $v0, 0x28($s1)
/* 409E8C E011E4FC C620000C */  lwc1      $f0, 0xc($s1)
/* 409E90 E011E500 8C42000C */  lw        $v0, 0xc($v0)
/* 409E94 E011E504 E440000C */  swc1      $f0, 0xc($v0)
.LE011E508:
/* 409E98 E011E508 8FBF0028 */  lw        $ra, 0x28($sp)
/* 409E9C E011E50C 8FB30024 */  lw        $s3, 0x24($sp)
/* 409EA0 E011E510 8FB20020 */  lw        $s2, 0x20($sp)
/* 409EA4 E011E514 8FB1001C */  lw        $s1, 0x1c($sp)
/* 409EA8 E011E518 8FB00018 */  lw        $s0, 0x18($sp)
/* 409EAC E011E51C D7B80040 */  ldc1      $f24, 0x40($sp)
/* 409EB0 E011E520 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 409EB4 E011E524 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 409EB8 E011E528 03E00008 */  jr        $ra
/* 409EBC E011E52C 27BD0048 */   addiu    $sp, $sp, 0x48
