.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419F4_A2BC34
/* A2BC34 802419F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2BC38 802419F8 AFB00010 */  sw        $s0, 0x10($sp)
/* A2BC3C 802419FC 0080802D */  daddu     $s0, $a0, $zero
/* A2BC40 80241A00 AFB10014 */  sw        $s1, 0x14($sp)
/* A2BC44 80241A04 00A0882D */  daddu     $s1, $a1, $zero
/* A2BC48 80241A08 AFBF0018 */  sw        $ra, 0x18($sp)
/* A2BC4C 80241A0C 0C0B36B0 */  jal       resolve_npc
/* A2BC50 80241A10 24050007 */   addiu    $a1, $zero, 7
/* A2BC54 80241A14 0200202D */  daddu     $a0, $s0, $zero
/* A2BC58 80241A18 24050008 */  addiu     $a1, $zero, 8
/* A2BC5C 80241A1C 0C0B36B0 */  jal       resolve_npc
/* A2BC60 80241A20 0040802D */   daddu    $s0, $v0, $zero
/* A2BC64 80241A24 12200017 */  beqz      $s1, .L80241A84
/* A2BC68 80241A28 0040282D */   daddu    $a1, $v0, $zero
/* A2BC6C 80241A2C 3C01C280 */  lui       $at, 0xc280
/* A2BC70 80241A30 44810000 */  mtc1      $at, $f0
/* A2BC74 80241A34 3C0143C8 */  lui       $at, 0x43c8
/* A2BC78 80241A38 44811000 */  mtc1      $at, $f2
/* A2BC7C 80241A3C 3C0142AA */  lui       $at, 0x42aa
/* A2BC80 80241A40 44812000 */  mtc1      $at, $f4
/* A2BC84 80241A44 E6000038 */  swc1      $f0, 0x38($s0)
/* A2BC88 80241A48 E602003C */  swc1      $f2, 0x3c($s0)
/* A2BC8C 80241A4C E6040040 */  swc1      $f4, 0x40($s0)
/* A2BC90 80241A50 E4A00038 */  swc1      $f0, 0x38($a1)
/* A2BC94 80241A54 E4A2003C */  swc1      $f2, 0x3c($a1)
/* A2BC98 80241A58 E4A40040 */  swc1      $f4, 0x40($a1)
/* A2BC9C 80241A5C C6000038 */  lwc1      $f0, 0x38($s0)
/* A2BCA0 80241A60 E600006C */  swc1      $f0, 0x6c($s0)
/* A2BCA4 80241A64 C4A00038 */  lwc1      $f0, 0x38($a1)
/* A2BCA8 80241A68 E4A0006C */  swc1      $f0, 0x6c($a1)
/* A2BCAC 80241A6C C6000040 */  lwc1      $f0, 0x40($s0)
/* A2BCB0 80241A70 E6000074 */  swc1      $f0, 0x74($s0)
/* A2BCB4 80241A74 C4A00040 */  lwc1      $f0, 0x40($a1)
/* A2BCB8 80241A78 3C018025 */  lui       $at, %hi(D_8024F2C8)
/* A2BCBC 80241A7C E422F2C8 */  swc1      $f2, %lo(D_8024F2C8)($at)
/* A2BCC0 80241A80 E4A00074 */  swc1      $f0, 0x74($a1)
.L80241A84:
/* A2BCC4 80241A84 3C038025 */  lui       $v1, %hi(D_80249910_A33B50)
/* A2BCC8 80241A88 8C639910 */  lw        $v1, %lo(D_80249910_A33B50)($v1)
/* A2BCCC 80241A8C 28620014 */  slti      $v0, $v1, 0x14
/* A2BCD0 80241A90 10400009 */  beqz      $v0, .L80241AB8
/* A2BCD4 80241A94 00031040 */   sll      $v0, $v1, 1
/* A2BCD8 80241A98 3C018025 */  lui       $at, %hi(D_80249934_A33B74)
/* A2BCDC 80241A9C 00220821 */  addu      $at, $at, $v0
/* A2BCE0 80241AA0 84229934 */  lh        $v0, %lo(D_80249934_A33B74)($at)
/* A2BCE4 80241AA4 44820000 */  mtc1      $v0, $f0
/* A2BCE8 80241AA8 00000000 */  nop
/* A2BCEC 80241AAC 46800020 */  cvt.s.w   $f0, $f0
/* A2BCF0 80241AB0 080906BE */  j         .L80241AF8
/* A2BCF4 80241AB4 E600003C */   swc1     $f0, 0x3c($s0)
.L80241AB8:
/* A2BCF8 80241AB8 2462FFEC */  addiu     $v0, $v1, -0x14
/* A2BCFC 80241ABC 3042001E */  andi      $v0, $v0, 0x1e
/* A2BD00 80241AC0 3C018025 */  lui       $at, %hi(D_80249914_A33B54)
/* A2BD04 80241AC4 00220821 */  addu      $at, $at, $v0
/* A2BD08 80241AC8 84229914 */  lh        $v0, %lo(D_80249914_A33B54)($at)
/* A2BD0C 80241ACC 3C013DCC */  lui       $at, 0x3dcc
/* A2BD10 80241AD0 3421CCCD */  ori       $at, $at, 0xcccd
/* A2BD14 80241AD4 44810000 */  mtc1      $at, $f0
/* A2BD18 80241AD8 44821000 */  mtc1      $v0, $f2
/* A2BD1C 80241ADC 00000000 */  nop
/* A2BD20 80241AE0 468010A0 */  cvt.s.w   $f2, $f2
/* A2BD24 80241AE4 46001082 */  mul.s     $f2, $f2, $f0
/* A2BD28 80241AE8 00000000 */  nop
/* A2BD2C 80241AEC C600003C */  lwc1      $f0, 0x3c($s0)
/* A2BD30 80241AF0 46020000 */  add.s     $f0, $f0, $f2
/* A2BD34 80241AF4 E600003C */  swc1      $f0, 0x3c($s0)
.L80241AF8:
/* A2BD38 80241AF8 C600003C */  lwc1      $f0, 0x3c($s0)
/* A2BD3C 80241AFC 3C048025 */  lui       $a0, %hi(D_80249910_A33B50)
/* A2BD40 80241B00 24849910 */  addiu     $a0, $a0, %lo(D_80249910_A33B50)
/* A2BD44 80241B04 E4A0003C */  swc1      $f0, 0x3c($a1)
/* A2BD48 80241B08 8C830000 */  lw        $v1, ($a0)
/* A2BD4C 80241B0C C600003C */  lwc1      $f0, 0x3c($s0)
/* A2BD50 80241B10 24630001 */  addiu     $v1, $v1, 1
/* A2BD54 80241B14 E6000070 */  swc1      $f0, 0x70($s0)
/* A2BD58 80241B18 C4A0003C */  lwc1      $f0, 0x3c($a1)
/* A2BD5C 80241B1C 286207D0 */  slti      $v0, $v1, 0x7d0
/* A2BD60 80241B20 AC830000 */  sw        $v1, ($a0)
/* A2BD64 80241B24 E4A00070 */  swc1      $f0, 0x70($a1)
/* A2BD68 80241B28 8FBF0018 */  lw        $ra, 0x18($sp)
/* A2BD6C 80241B2C 8FB10014 */  lw        $s1, 0x14($sp)
/* A2BD70 80241B30 8FB00010 */  lw        $s0, 0x10($sp)
/* A2BD74 80241B34 38420001 */  xori      $v0, $v0, 1
/* A2BD78 80241B38 03E00008 */  jr        $ra
/* A2BD7C 80241B3C 27BD0020 */   addiu    $sp, $sp, 0x20
