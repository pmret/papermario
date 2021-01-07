.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A2000
/* 3A2990 E00A2000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3A2994 E00A2004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3A2998 E00A2008 4485A000 */  mtc1      $a1, $f20
/* 3A299C E00A200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3A29A0 E00A2010 4486B000 */  mtc1      $a2, $f22
/* 3A29A4 E00A2014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3A29A8 E00A2018 0080902D */  daddu     $s2, $a0, $zero
/* 3A29AC E00A201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3A29B0 E00A2020 4487C000 */  mtc1      $a3, $f24
/* 3A29B4 E00A2024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A29B8 E00A2028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3A29BC E00A202C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3A29C0 E00A2030 3C02E00A */  lui       $v0, %hi(D_E00A2118)
/* 3A29C4 E00A2034 24422118 */  addiu     $v0, $v0, %lo(D_E00A2118)
/* 3A29C8 E00A2038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3A29CC E00A203C 3C02E00A */  lui       $v0, %hi(D_E00A2120)
/* 3A29D0 E00A2040 24422120 */  addiu     $v0, $v0, %lo(D_E00A2120)
/* 3A29D4 E00A2044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A29D8 E00A2048 3C02E00A */  lui       $v0, %hi(D_E00A21EC)
/* 3A29DC E00A204C 244221EC */  addiu     $v0, $v0, %lo(D_E00A21EC)
/* 3A29E0 E00A2050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A29E4 E00A2054 24020051 */  addiu     $v0, $zero, 0x51
/* 3A29E8 E00A2058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3A29EC E00A205C AFB00028 */  sw        $s0, 0x28($sp)
/* 3A29F0 E00A2060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3A29F4 E00A2064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3A29F8 E00A2068 0C080124 */  jal       func_E0200490
/* 3A29FC E00A206C AFA20014 */   sw       $v0, 0x14($sp)
/* 3A2A00 E00A2070 24040068 */  addiu     $a0, $zero, 0x68
/* 3A2A04 E00A2074 24030001 */  addiu     $v1, $zero, 1
/* 3A2A08 E00A2078 0040802D */  daddu     $s0, $v0, $zero
/* 3A2A0C E00A207C 0C08012C */  jal       func_E02004B0
/* 3A2A10 E00A2080 AE030008 */   sw       $v1, 8($s0)
/* 3A2A14 E00A2084 0040202D */  daddu     $a0, $v0, $zero
/* 3A2A18 E00A2088 14800003 */  bnez      $a0, .LE00A2098
/* 3A2A1C E00A208C AE02000C */   sw       $v0, 0xc($s0)
.LE00A2090:
/* 3A2A20 E00A2090 08028824 */  j         .LE00A2090
/* 3A2A24 E00A2094 00000000 */   nop      
.LE00A2098:
/* 3A2A28 E00A2098 06210004 */  bgez      $s1, .LE00A20AC
/* 3A2A2C E00A209C AC920000 */   sw       $s2, ($a0)
/* 3A2A30 E00A20A0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3A2A34 E00A20A4 0802882C */  j         .LE00A20B0
/* 3A2A38 E00A20A8 AC820050 */   sw       $v0, 0x50($a0)
.LE00A20AC:
/* 3A2A3C E00A20AC AC910050 */  sw        $s1, 0x50($a0)
.LE00A20B0:
/* 3A2A40 E00A20B0 0200102D */  daddu     $v0, $s0, $zero
/* 3A2A44 E00A20B4 2403007F */  addiu     $v1, $zero, 0x7f
/* 3A2A48 E00A20B8 AC83004C */  sw        $v1, 0x4c($a0)
/* 3A2A4C E00A20BC 240300FF */  addiu     $v1, $zero, 0xff
/* 3A2A50 E00A20C0 AC800054 */  sw        $zero, 0x54($a0)
/* 3A2A54 E00A20C4 E4940004 */  swc1      $f20, 4($a0)
/* 3A2A58 E00A20C8 E4960008 */  swc1      $f22, 8($a0)
/* 3A2A5C E00A20CC E498000C */  swc1      $f24, 0xc($a0)
/* 3A2A60 E00A20D0 AC800010 */  sw        $zero, 0x10($a0)
/* 3A2A64 E00A20D4 AC800014 */  sw        $zero, 0x14($a0)
/* 3A2A68 E00A20D8 AC800018 */  sw        $zero, 0x18($a0)
/* 3A2A6C E00A20DC AC83005C */  sw        $v1, 0x5c($a0)
/* 3A2A70 E00A20E0 AC830060 */  sw        $v1, 0x60($a0)
/* 3A2A74 E00A20E4 AC830064 */  sw        $v1, 0x64($a0)
/* 3A2A78 E00A20E8 AC800040 */  sw        $zero, 0x40($a0)
/* 3A2A7C E00A20EC AC800044 */  sw        $zero, 0x44($a0)
/* 3A2A80 E00A20F0 AC800048 */  sw        $zero, 0x48($a0)
/* 3A2A84 E00A20F4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3A2A88 E00A20F8 8FB20030 */  lw        $s2, 0x30($sp)
/* 3A2A8C E00A20FC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3A2A90 E00A2100 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A2A94 E00A2104 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3A2A98 E00A2108 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3A2A9C E00A210C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3A2AA0 E00A2110 03E00008 */  jr        $ra
/* 3A2AA4 E00A2114 27BD0050 */   addiu    $sp, $sp, 0x50
