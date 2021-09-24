.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A2120
/* 3A2AB0 E00A2120 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A2AB4 E00A2124 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A2AB8 E00A2128 8C850000 */  lw        $a1, ($a0)
/* 3A2ABC E00A212C 8C83000C */  lw        $v1, 0xc($a0)
/* 3A2AC0 E00A2130 30A20010 */  andi      $v0, $a1, 0x10
/* 3A2AC4 E00A2134 10400005 */  beqz      $v0, .LE00A214C
/* 3A2AC8 E00A2138 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3A2ACC E00A213C 00A21024 */  and       $v0, $a1, $v0
/* 3A2AD0 E00A2140 AC820000 */  sw        $v0, ($a0)
/* 3A2AD4 E00A2144 2402001E */  addiu     $v0, $zero, 0x1e
/* 3A2AD8 E00A2148 AC620050 */  sw        $v0, 0x50($v1)
.LE00A214C:
/* 3A2ADC E00A214C 8C620054 */  lw        $v0, 0x54($v1)
/* 3A2AE0 E00A2150 8C650050 */  lw        $a1, 0x50($v1)
/* 3A2AE4 E00A2154 24420001 */  addiu     $v0, $v0, 1
/* 3A2AE8 E00A2158 AC620054 */  sw        $v0, 0x54($v1)
/* 3A2AEC E00A215C 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3A2AF0 E00A2160 10400002 */  beqz      $v0, .LE00A216C
/* 3A2AF4 E00A2164 24A2FFFF */   addiu    $v0, $a1, -1
/* 3A2AF8 E00A2168 AC620050 */  sw        $v0, 0x50($v1)
.LE00A216C:
/* 3A2AFC E00A216C 8C620050 */  lw        $v0, 0x50($v1)
/* 3A2B00 E00A2170 04410005 */  bgez      $v0, .LE00A2188
/* 3A2B04 E00A2174 0040282D */   daddu    $a1, $v0, $zero
/* 3A2B08 E00A2178 0C080128 */  jal       shim_remove_effect
/* 3A2B0C E00A217C 00000000 */   nop
/* 3A2B10 E00A2180 08028878 */  j         .LE00A21E0
/* 3A2B14 E00A2184 00000000 */   nop
.LE00A2188:
/* 3A2B18 E00A2188 8C640054 */  lw        $a0, 0x54($v1)
/* 3A2B1C E00A218C 28820011 */  slti      $v0, $a0, 0x11
/* 3A2B20 E00A2190 10400003 */  beqz      $v0, .LE00A21A0
/* 3A2B24 E00A2194 000410C0 */   sll      $v0, $a0, 3
/* 3A2B28 E00A2198 2442FFFF */  addiu     $v0, $v0, -1
/* 3A2B2C E00A219C AC62004C */  sw        $v0, 0x4c($v1)
.LE00A21A0:
/* 3A2B30 E00A21A0 28A20010 */  slti      $v0, $a1, 0x10
/* 3A2B34 E00A21A4 10400002 */  beqz      $v0, .LE00A21B0
/* 3A2B38 E00A21A8 000510C0 */   sll      $v0, $a1, 3
/* 3A2B3C E00A21AC AC62004C */  sw        $v0, 0x4c($v1)
.LE00A21B0:
/* 3A2B40 E00A21B0 C4660004 */  lwc1      $f6, 4($v1)
/* 3A2B44 E00A21B4 C4600010 */  lwc1      $f0, 0x10($v1)
/* 3A2B48 E00A21B8 C4640008 */  lwc1      $f4, 8($v1)
/* 3A2B4C E00A21BC 46003180 */  add.s     $f6, $f6, $f0
/* 3A2B50 E00A21C0 C4600014 */  lwc1      $f0, 0x14($v1)
/* 3A2B54 E00A21C4 C462000C */  lwc1      $f2, 0xc($v1)
/* 3A2B58 E00A21C8 46002100 */  add.s     $f4, $f4, $f0
/* 3A2B5C E00A21CC C4600018 */  lwc1      $f0, 0x18($v1)
/* 3A2B60 E00A21D0 46001080 */  add.s     $f2, $f2, $f0
/* 3A2B64 E00A21D4 E466001C */  swc1      $f6, 0x1c($v1)
/* 3A2B68 E00A21D8 E464002C */  swc1      $f4, 0x2c($v1)
/* 3A2B6C E00A21DC E462003C */  swc1      $f2, 0x3c($v1)
.LE00A21E0:
/* 3A2B70 E00A21E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A2B74 E00A21E4 03E00008 */  jr        $ra
/* 3A2B78 E00A21E8 27BD0018 */   addiu    $sp, $sp, 0x18
