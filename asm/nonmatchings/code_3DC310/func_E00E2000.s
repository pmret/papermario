.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E2000
/* 3DC310 E00E2000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3DC314 E00E2004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3DC318 E00E2008 4485A000 */  mtc1      $a1, $f20
/* 3DC31C E00E200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3DC320 E00E2010 4486B000 */  mtc1      $a2, $f22
/* 3DC324 E00E2014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3DC328 E00E2018 0080902D */  daddu     $s2, $a0, $zero
/* 3DC32C E00E201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3DC330 E00E2020 4487C000 */  mtc1      $a3, $f24
/* 3DC334 E00E2024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DC338 E00E2028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3DC33C E00E202C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3DC340 E00E2030 3C02E00E */  lui       $v0, %hi(D_E00E212C)
/* 3DC344 E00E2034 2442212C */  addiu     $v0, $v0, %lo(D_E00E212C)
/* 3DC348 E00E2038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3DC34C E00E203C 3C02E00E */  lui       $v0, %hi(D_E00E2134)
/* 3DC350 E00E2040 24422134 */  addiu     $v0, $v0, %lo(D_E00E2134)
/* 3DC354 E00E2044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DC358 E00E2048 3C02E00E */  lui       $v0, %hi(D_E00E21C8)
/* 3DC35C E00E204C 244221C8 */  addiu     $v0, $v0, %lo(D_E00E21C8)
/* 3DC360 E00E2050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3DC364 E00E2054 24020071 */  addiu     $v0, $zero, 0x71
/* 3DC368 E00E2058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3DC36C E00E205C AFB00028 */  sw        $s0, 0x28($sp)
/* 3DC370 E00E2060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3DC374 E00E2064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3DC378 E00E2068 0C080124 */  jal       func_E0200490
/* 3DC37C E00E206C AFA20014 */   sw       $v0, 0x14($sp)
/* 3DC380 E00E2070 2404003C */  addiu     $a0, $zero, 0x3c
/* 3DC384 E00E2074 24030001 */  addiu     $v1, $zero, 1
/* 3DC388 E00E2078 0040802D */  daddu     $s0, $v0, $zero
/* 3DC38C E00E207C 0C08012C */  jal       func_E02004B0
/* 3DC390 E00E2080 AE030008 */   sw       $v1, 8($s0)
/* 3DC394 E00E2084 0040202D */  daddu     $a0, $v0, $zero
/* 3DC398 E00E2088 14800003 */  bnez      $a0, .LE00E2098
/* 3DC39C E00E208C AE02000C */   sw       $v0, 0xc($s0)
.LE00E2090:
/* 3DC3A0 E00E2090 08038824 */  j         .LE00E2090
/* 3DC3A4 E00E2094 00000000 */   nop      
.LE00E2098:
/* 3DC3A8 E00E2098 AC920000 */  sw        $s2, ($a0)
/* 3DC3AC E00E209C 1E200004 */  bgtz      $s1, .LE00E20B0
/* 3DC3B0 E00E20A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3DC3B4 E00E20A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3DC3B8 E00E20A8 0803882D */  j         .LE00E20B4
/* 3DC3BC E00E20AC AC820010 */   sw       $v0, 0x10($a0)
.LE00E20B0:
/* 3DC3C0 E00E20B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00E20B4:
/* 3DC3C4 E00E20B4 0200102D */  daddu     $v0, $s0, $zero
/* 3DC3C8 E00E20B8 AC800024 */  sw        $zero, 0x24($a0)
/* 3DC3CC E00E20BC E4940004 */  swc1      $f20, 4($a0)
/* 3DC3D0 E00E20C0 E4960008 */  swc1      $f22, 8($a0)
/* 3DC3D4 E00E20C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3DC3D8 E00E20C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3DC3DC E00E20CC 24030046 */  addiu     $v1, $zero, 0x46
/* 3DC3E0 E00E20D0 AC830018 */  sw        $v1, 0x18($a0)
/* 3DC3E4 E00E20D4 240300B4 */  addiu     $v1, $zero, 0xb4
/* 3DC3E8 E00E20D8 AC83001C */  sw        $v1, 0x1c($a0)
/* 3DC3EC E00E20DC 24030078 */  addiu     $v1, $zero, 0x78
/* 3DC3F0 E00E20E0 AC830020 */  sw        $v1, 0x20($a0)
/* 3DC3F4 E00E20E4 24030014 */  addiu     $v1, $zero, 0x14
/* 3DC3F8 E00E20E8 AC830028 */  sw        $v1, 0x28($a0)
/* 3DC3FC E00E20EC 240300E6 */  addiu     $v1, $zero, 0xe6
/* 3DC400 E00E20F0 AC83002C */  sw        $v1, 0x2c($a0)
/* 3DC404 E00E20F4 24030032 */  addiu     $v1, $zero, 0x32
/* 3DC408 E00E20F8 AC830030 */  sw        $v1, 0x30($a0)
/* 3DC40C E00E20FC 240300FF */  addiu     $v1, $zero, 0xff
/* 3DC410 E00E2100 AC830034 */  sw        $v1, 0x34($a0)
/* 3DC414 E00E2104 E4800038 */  swc1      $f0, 0x38($a0)
/* 3DC418 E00E2108 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3DC41C E00E210C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3DC420 E00E2110 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3DC424 E00E2114 8FB00028 */  lw        $s0, 0x28($sp)
/* 3DC428 E00E2118 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3DC42C E00E211C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3DC430 E00E2120 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3DC434 E00E2124 03E00008 */  jr        $ra
/* 3DC438 E00E2128 27BD0050 */   addiu    $sp, $sp, 0x50
