.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A68_E07DC8
/* E07DC8 80242A68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E07DCC 80242A6C AFB10014 */  sw        $s1, 0x14($sp)
/* E07DD0 80242A70 0080882D */  daddu     $s1, $a0, $zero
/* E07DD4 80242A74 AFBF0018 */  sw        $ra, 0x18($sp)
/* E07DD8 80242A78 AFB00010 */  sw        $s0, 0x10($sp)
/* E07DDC 80242A7C 8E22000C */  lw        $v0, 0xc($s1)
/* E07DE0 80242A80 00A0802D */  daddu     $s0, $a1, $zero
/* E07DE4 80242A84 0C0B1EAF */  jal       get_variable
/* E07DE8 80242A88 8C450000 */   lw       $a1, ($v0)
/* E07DEC 80242A8C 1200000C */  beqz      $s0, .L80242AC0
/* E07DF0 80242A90 0220202D */   daddu    $a0, $s1, $zero
/* E07DF4 80242A94 0C0B36B0 */  jal       resolve_npc
/* E07DF8 80242A98 0040282D */   daddu    $a1, $v0, $zero
/* E07DFC 80242A9C AE220074 */  sw        $v0, 0x74($s1)
/* E07E00 80242AA0 C4420038 */  lwc1      $f2, 0x38($v0)
/* E07E04 80242AA4 3C014334 */  lui       $at, 0x4334
/* E07E08 80242AA8 44810000 */  mtc1      $at, $f0
/* E07E0C 80242AAC 24020048 */  addiu     $v0, $zero, 0x48
/* E07E10 80242AB0 AE220070 */  sw        $v0, 0x70($s1)
/* E07E14 80242AB4 4600110D */  trunc.w.s $f4, $f2
/* E07E18 80242AB8 E6240078 */  swc1      $f4, 0x78($s1)
/* E07E1C 80242ABC E620007C */  swc1      $f0, 0x7c($s1)
.L80242AC0:
/* E07E20 80242AC0 C620007C */  lwc1      $f0, 0x7c($s1)
/* E07E24 80242AC4 3C0140A0 */  lui       $at, 0x40a0
/* E07E28 80242AC8 44816000 */  mtc1      $at, $f12
/* E07E2C 80242ACC 8E300074 */  lw        $s0, 0x74($s1)
/* E07E30 80242AD0 0C00A6C9 */  jal       clamp_angle
/* E07E34 80242AD4 460C0301 */   sub.s    $f12, $f0, $f12
/* E07E38 80242AD8 46000306 */  mov.s     $f12, $f0
/* E07E3C 80242ADC 0C00A8D4 */  jal       cos_deg
/* E07E40 80242AE0 E62C007C */   swc1     $f12, 0x7c($s1)
/* E07E44 80242AE4 3C0140C0 */  lui       $at, 0x40c0
/* E07E48 80242AE8 44811000 */  mtc1      $at, $f2
/* E07E4C 80242AEC 00000000 */  nop       
/* E07E50 80242AF0 46020002 */  mul.s     $f0, $f0, $f2
/* E07E54 80242AF4 00000000 */  nop       
/* E07E58 80242AF8 C6020038 */  lwc1      $f2, 0x38($s0)
/* E07E5C 80242AFC 46001080 */  add.s     $f2, $f2, $f0
/* E07E60 80242B00 E6020038 */  swc1      $f2, 0x38($s0)
/* E07E64 80242B04 0C00A8BB */  jal       sin_deg
/* E07E68 80242B08 C62C007C */   lwc1     $f12, 0x7c($s1)
/* E07E6C 80242B0C 3C014020 */  lui       $at, 0x4020
/* E07E70 80242B10 44811000 */  mtc1      $at, $f2
/* E07E74 80242B14 00000000 */  nop       
/* E07E78 80242B18 46020002 */  mul.s     $f0, $f0, $f2
/* E07E7C 80242B1C 00000000 */  nop       
/* E07E80 80242B20 C6020040 */  lwc1      $f2, 0x40($s0)
/* E07E84 80242B24 46001080 */  add.s     $f2, $f2, $f0
/* E07E88 80242B28 3C014334 */  lui       $at, 0x4334
/* E07E8C 80242B2C 44816000 */  mtc1      $at, $f12
/* E07E90 80242B30 E6020040 */  swc1      $f2, 0x40($s0)
/* E07E94 80242B34 C620007C */  lwc1      $f0, 0x7c($s1)
/* E07E98 80242B38 0C00A6C9 */  jal       clamp_angle
/* E07E9C 80242B3C 46006301 */   sub.s    $f12, $f12, $f0
/* E07EA0 80242B40 E6000034 */  swc1      $f0, 0x34($s0)
/* E07EA4 80242B44 8E230070 */  lw        $v1, 0x70($s1)
/* E07EA8 80242B48 2463FFFF */  addiu     $v1, $v1, -1
/* E07EAC 80242B4C AE230070 */  sw        $v1, 0x70($s1)
/* E07EB0 80242B50 8FBF0018 */  lw        $ra, 0x18($sp)
/* E07EB4 80242B54 8FB10014 */  lw        $s1, 0x14($sp)
/* E07EB8 80242B58 8FB00010 */  lw        $s0, 0x10($sp)
/* E07EBC 80242B5C 2C620001 */  sltiu     $v0, $v1, 1
/* E07EC0 80242B60 03E00008 */  jr        $ra
/* E07EC4 80242B64 27BD0020 */   addiu    $sp, $sp, 0x20
