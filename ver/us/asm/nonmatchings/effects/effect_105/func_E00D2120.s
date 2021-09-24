.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D2120
/* 3D4A90 E00D2120 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D4A94 E00D2124 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D4A98 E00D2128 8C830000 */  lw        $v1, ($a0)
/* 3D4A9C E00D212C 8C85000C */  lw        $a1, 0xc($a0)
/* 3D4AA0 E00D2130 30620010 */  andi      $v0, $v1, 0x10
/* 3D4AA4 E00D2134 10400005 */  beqz      $v0, .LE00D214C
/* 3D4AA8 E00D2138 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D4AAC E00D213C 00621024 */  and       $v0, $v1, $v0
/* 3D4AB0 E00D2140 AC820000 */  sw        $v0, ($a0)
/* 3D4AB4 E00D2144 24020010 */  addiu     $v0, $zero, 0x10
/* 3D4AB8 E00D2148 ACA20010 */  sw        $v0, 0x10($a1)
.LE00D214C:
/* 3D4ABC E00D214C 8CA30010 */  lw        $v1, 0x10($a1)
/* 3D4AC0 E00D2150 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D4AC4 E00D2154 10400002 */  beqz      $v0, .LE00D2160
/* 3D4AC8 E00D2158 2462FFFF */   addiu    $v0, $v1, -1
/* 3D4ACC E00D215C ACA20010 */  sw        $v0, 0x10($a1)
.LE00D2160:
/* 3D4AD0 E00D2160 8CA70014 */  lw        $a3, 0x14($a1)
/* 3D4AD4 E00D2164 8CA30010 */  lw        $v1, 0x10($a1)
/* 3D4AD8 E00D2168 24E60001 */  addiu     $a2, $a3, 1
/* 3D4ADC E00D216C 04610005 */  bgez      $v1, .LE00D2184
/* 3D4AE0 E00D2170 ACA60014 */   sw       $a2, 0x14($a1)
/* 3D4AE4 E00D2174 0C080128 */  jal       shim_remove_effect
/* 3D4AE8 E00D2178 00000000 */   nop
/* 3D4AEC E00D217C 0803488A */  j         .LE00D2228
/* 3D4AF0 E00D2180 00000000 */   nop
.LE00D2184:
/* 3D4AF4 E00D2184 28620010 */  slti      $v0, $v1, 0x10
/* 3D4AF8 E00D2188 10400002 */  beqz      $v0, .LE00D2194
/* 3D4AFC E00D218C 00031100 */   sll      $v0, $v1, 4
/* 3D4B00 E00D2190 ACA20024 */  sw        $v0, 0x24($a1)
.LE00D2194:
/* 3D4B04 E00D2194 C4A00008 */  lwc1      $f0, 8($a1)
/* 3D4B08 E00D2198 3C01E00D */  lui       $at, %hi(D_E00D2510)
/* 3D4B0C E00D219C D4222510 */  ldc1      $f2, %lo(D_E00D2510)($at)
/* 3D4B10 E00D21A0 46000021 */  cvt.d.s   $f0, $f0
/* 3D4B14 E00D21A4 46220000 */  add.d     $f0, $f0, $f2
/* 3D4B18 E00D21A8 28C20007 */  slti      $v0, $a2, 7
/* 3D4B1C E00D21AC 46200020 */  cvt.s.d   $f0, $f0
/* 3D4B20 E00D21B0 10400005 */  beqz      $v0, .LE00D21C8
/* 3D4B24 E00D21B4 E4A00008 */   swc1     $f0, 8($a1)
/* 3D4B28 E00D21B8 3C02E00D */  lui       $v0, %hi(D_E00D2500)
/* 3D4B2C E00D21BC 00461021 */  addu      $v0, $v0, $a2
/* 3D4B30 E00D21C0 08034881 */  j         .LE00D2204
/* 3D4B34 E00D21C4 90422500 */   lbu      $v0, %lo(D_E00D2500)($v0)
.LE00D21C8:
/* 3D4B38 E00D21C8 3C029249 */  lui       $v0, 0x9249
/* 3D4B3C E00D21CC 34422493 */  ori       $v0, $v0, 0x2493
/* 3D4B40 E00D21D0 24E4FFFA */  addiu     $a0, $a3, -6
/* 3D4B44 E00D21D4 00820018 */  mult      $a0, $v0
/* 3D4B48 E00D21D8 000417C3 */  sra       $v0, $a0, 0x1f
/* 3D4B4C E00D21DC 00004010 */  mfhi      $t0
/* 3D4B50 E00D21E0 01041821 */  addu      $v1, $t0, $a0
/* 3D4B54 E00D21E4 00031883 */  sra       $v1, $v1, 2
/* 3D4B58 E00D21E8 00621823 */  subu      $v1, $v1, $v0
/* 3D4B5C E00D21EC 000310C0 */  sll       $v0, $v1, 3
/* 3D4B60 E00D21F0 00431023 */  subu      $v0, $v0, $v1
/* 3D4B64 E00D21F4 00822023 */  subu      $a0, $a0, $v0
/* 3D4B68 E00D21F8 3C02E00D */  lui       $v0, %hi(D_E00D2508)
/* 3D4B6C E00D21FC 00441021 */  addu      $v0, $v0, $a0
/* 3D4B70 E00D2200 90422508 */  lbu       $v0, %lo(D_E00D2508)($v0)
.LE00D2204:
/* 3D4B74 E00D2204 3C01E00D */  lui       $at, %hi(D_E00D2518)
/* 3D4B78 E00D2208 D4222518 */  ldc1      $f2, %lo(D_E00D2518)($at)
/* 3D4B7C E00D220C 44820000 */  mtc1      $v0, $f0
/* 3D4B80 E00D2210 00000000 */  nop
/* 3D4B84 E00D2214 46800021 */  cvt.d.w   $f0, $f0
/* 3D4B88 E00D2218 46220002 */  mul.d     $f0, $f0, $f2
/* 3D4B8C E00D221C 00000000 */  nop
/* 3D4B90 E00D2220 46200020 */  cvt.s.d   $f0, $f0
/* 3D4B94 E00D2224 E4A00038 */  swc1      $f0, 0x38($a1)
.LE00D2228:
/* 3D4B98 E00D2228 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D4B9C E00D222C 03E00008 */  jr        $ra
/* 3D4BA0 E00D2230 27BD0018 */   addiu    $sp, $sp, 0x18
