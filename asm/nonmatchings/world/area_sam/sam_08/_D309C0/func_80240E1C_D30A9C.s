.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E1C_D30A9C
/* D30A9C 80240E1C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D30AA0 80240E20 AFB10034 */  sw        $s1, 0x34($sp)
/* D30AA4 80240E24 0080882D */  daddu     $s1, $a0, $zero
/* D30AA8 80240E28 AFBF0038 */  sw        $ra, 0x38($sp)
/* D30AAC 80240E2C AFB00030 */  sw        $s0, 0x30($sp)
/* D30AB0 80240E30 8E300148 */  lw        $s0, 0x148($s1)
/* D30AB4 80240E34 0C00EABB */  jal       get_npc_unsafe
/* D30AB8 80240E38 86040008 */   lh       $a0, 8($s0)
/* D30ABC 80240E3C 0040282D */  daddu     $a1, $v0, $zero
/* D30AC0 80240E40 94A2008E */  lhu       $v0, 0x8e($a1)
/* D30AC4 80240E44 2442FFFF */  addiu     $v0, $v0, -1
/* D30AC8 80240E48 A4A2008E */  sh        $v0, 0x8e($a1)
/* D30ACC 80240E4C 00021400 */  sll       $v0, $v0, 0x10
/* D30AD0 80240E50 1C400023 */  bgtz      $v0, .L80240EE0
/* D30AD4 80240E54 24020004 */   addiu    $v0, $zero, 4
/* D30AD8 80240E58 8E0300CC */  lw        $v1, 0xcc($s0)
/* D30ADC 80240E5C AE02006C */  sw        $v0, 0x6c($s0)
/* D30AE0 80240E60 8C620000 */  lw        $v0, ($v1)
/* D30AE4 80240E64 ACA20028 */  sw        $v0, 0x28($a1)
/* D30AE8 80240E68 9602007A */  lhu       $v0, 0x7a($s0)
/* D30AEC 80240E6C A4A2008E */  sh        $v0, 0x8e($a1)
/* D30AF0 80240E70 8E020078 */  lw        $v0, 0x78($s0)
/* D30AF4 80240E74 28420008 */  slti      $v0, $v0, 8
/* D30AF8 80240E78 14400018 */  bnez      $v0, .L80240EDC
/* D30AFC 80240E7C 24020021 */   addiu    $v0, $zero, 0x21
/* D30B00 80240E80 24040003 */  addiu     $a0, $zero, 3
/* D30B04 80240E84 27A30028 */  addiu     $v1, $sp, 0x28
/* D30B08 80240E88 84A700A8 */  lh        $a3, 0xa8($a1)
/* D30B0C 80240E8C 3C013F80 */  lui       $at, 0x3f80
/* D30B10 80240E90 44810000 */  mtc1      $at, $f0
/* D30B14 80240E94 3C014000 */  lui       $at, 0x4000
/* D30B18 80240E98 44811000 */  mtc1      $at, $f2
/* D30B1C 80240E9C 3C01C1A0 */  lui       $at, 0xc1a0
/* D30B20 80240EA0 44812000 */  mtc1      $at, $f4
/* D30B24 80240EA4 44873000 */  mtc1      $a3, $f6
/* D30B28 80240EA8 00000000 */  nop       
/* D30B2C 80240EAC 468031A0 */  cvt.s.w   $f6, $f6
/* D30B30 80240EB0 E7A00010 */  swc1      $f0, 0x10($sp)
/* D30B34 80240EB4 E7A20014 */  swc1      $f2, 0x14($sp)
/* D30B38 80240EB8 E7A40018 */  swc1      $f4, 0x18($sp)
/* D30B3C 80240EBC 8E020078 */  lw        $v0, 0x78($s0)
/* D30B40 80240EC0 44073000 */  mfc1      $a3, $f6
/* D30B44 80240EC4 0000302D */  daddu     $a2, $zero, $zero
/* D30B48 80240EC8 AFA30020 */  sw        $v1, 0x20($sp)
/* D30B4C 80240ECC 2442FFFF */  addiu     $v0, $v0, -1
/* D30B50 80240ED0 0C01BFA4 */  jal       fx_emote
/* D30B54 80240ED4 AFA2001C */   sw       $v0, 0x1c($sp)
/* D30B58 80240ED8 24020021 */  addiu     $v0, $zero, 0x21
.L80240EDC:
/* D30B5C 80240EDC AE220070 */  sw        $v0, 0x70($s1)
.L80240EE0:
/* D30B60 80240EE0 8FBF0038 */  lw        $ra, 0x38($sp)
/* D30B64 80240EE4 8FB10034 */  lw        $s1, 0x34($sp)
/* D30B68 80240EE8 8FB00030 */  lw        $s0, 0x30($sp)
/* D30B6C 80240EEC 03E00008 */  jr        $ra
/* D30B70 80240EF0 27BD0040 */   addiu    $sp, $sp, 0x40
