.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_105_main
/* 3D4970 E00D2000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3D4974 E00D2004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D4978 E00D2008 4485A000 */  mtc1      $a1, $f20
/* 3D497C E00D200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D4980 E00D2010 4486B000 */  mtc1      $a2, $f22
/* 3D4984 E00D2014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3D4988 E00D2018 0080902D */  daddu     $s2, $a0, $zero
/* 3D498C E00D201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D4990 E00D2020 4487C000 */  mtc1      $a3, $f24
/* 3D4994 E00D2024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D4998 E00D2028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D499C E00D202C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D49A0 E00D2030 3C02E00D */  lui       $v0, %hi(fx_105_init)
/* 3D49A4 E00D2034 24422118 */  addiu     $v0, $v0, %lo(fx_105_init)
/* 3D49A8 E00D2038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D49AC E00D203C 3C02E00D */  lui       $v0, %hi(fx_105_update)
/* 3D49B0 E00D2040 24422120 */  addiu     $v0, $v0, %lo(fx_105_update)
/* 3D49B4 E00D2044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D49B8 E00D2048 3C02E00D */  lui       $v0, %hi(fx_105_render)
/* 3D49BC E00D204C 24422234 */  addiu     $v0, $v0, %lo(fx_105_render)
/* 3D49C0 E00D2050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D49C4 E00D2054 24020069 */  addiu     $v0, $zero, 0x69
/* 3D49C8 E00D2058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3D49CC E00D205C AFB00028 */  sw        $s0, 0x28($sp)
/* 3D49D0 E00D2060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D49D4 E00D2064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D49D8 E00D2068 0C080124 */  jal       shim_create_effect_instance
/* 3D49DC E00D206C AFA20014 */   sw       $v0, 0x14($sp)
/* 3D49E0 E00D2070 2404003C */  addiu     $a0, $zero, 0x3c
/* 3D49E4 E00D2074 24030001 */  addiu     $v1, $zero, 1
/* 3D49E8 E00D2078 0040802D */  daddu     $s0, $v0, $zero
/* 3D49EC E00D207C 0C08012C */  jal       shim_general_heap_malloc
/* 3D49F0 E00D2080 AE030008 */   sw       $v1, 8($s0)
/* 3D49F4 E00D2084 0040202D */  daddu     $a0, $v0, $zero
/* 3D49F8 E00D2088 14800003 */  bnez      $a0, .LE00D2098
/* 3D49FC E00D208C AE02000C */   sw       $v0, 0xc($s0)
.LE00D2090:
/* 3D4A00 E00D2090 08034824 */  j         .LE00D2090
/* 3D4A04 E00D2094 00000000 */   nop
.LE00D2098:
/* 3D4A08 E00D2098 AC920000 */  sw        $s2, ($a0)
/* 3D4A0C E00D209C 1E200004 */  bgtz      $s1, .LE00D20B0
/* 3D4A10 E00D20A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3D4A14 E00D20A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D4A18 E00D20A8 0803482D */  j         .LE00D20B4
/* 3D4A1C E00D20AC AC820010 */   sw       $v0, 0x10($a0)
.LE00D20B0:
/* 3D4A20 E00D20B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00D20B4:
/* 3D4A24 E00D20B4 240300FF */  addiu     $v1, $zero, 0xff
/* 3D4A28 E00D20B8 AC830024 */  sw        $v1, 0x24($a0)
/* 3D4A2C E00D20BC E4940004 */  swc1      $f20, 4($a0)
/* 3D4A30 E00D20C0 E4960008 */  swc1      $f22, 8($a0)
/* 3D4A34 E00D20C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3D4A38 E00D20C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3D4A3C E00D20CC 0200102D */  daddu     $v0, $s0, $zero
/* 3D4A40 E00D20D0 AC830018 */  sw        $v1, 0x18($a0)
/* 3D4A44 E00D20D4 AC83001C */  sw        $v1, 0x1c($a0)
/* 3D4A48 E00D20D8 AC830020 */  sw        $v1, 0x20($a0)
/* 3D4A4C E00D20DC 2403000A */  addiu     $v1, $zero, 0xa
/* 3D4A50 E00D20E0 AC830028 */  sw        $v1, 0x28($a0)
/* 3D4A54 E00D20E4 AC83002C */  sw        $v1, 0x2c($a0)
/* 3D4A58 E00D20E8 24030078 */  addiu     $v1, $zero, 0x78
/* 3D4A5C E00D20EC AC830030 */  sw        $v1, 0x30($a0)
/* 3D4A60 E00D20F0 E4800034 */  swc1      $f0, 0x34($a0)
/* 3D4A64 E00D20F4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3D4A68 E00D20F8 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D4A6C E00D20FC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D4A70 E00D2100 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D4A74 E00D2104 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D4A78 E00D2108 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D4A7C E00D210C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D4A80 E00D2110 03E00008 */  jr        $ra
/* 3D4A84 E00D2114 27BD0050 */   addiu    $sp, $sp, 0x50
