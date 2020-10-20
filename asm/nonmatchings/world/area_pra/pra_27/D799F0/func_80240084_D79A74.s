.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240084_D79A74
/* D79A74 80240084 00041403 */  sra       $v0, $a0, 0x10
/* D79A78 80240088 304300FF */  andi      $v1, $v0, 0xff
/* D79A7C 8024008C 24020006 */  addiu     $v0, $zero, 6
/* D79A80 80240090 10620015 */  beq       $v1, $v0, .L802400E8
/* D79A84 80240094 28620007 */   slti     $v0, $v1, 7
/* D79A88 80240098 10400005 */  beqz      $v0, .L802400B0
/* D79A8C 8024009C 24020001 */   addiu    $v0, $zero, 1
/* D79A90 802400A0 1062000A */  beq       $v1, $v0, .L802400CC
/* D79A94 802400A4 3C020100 */   lui      $v0, 0x100
/* D79A98 802400A8 03E00008 */  jr        $ra
/* D79A9C 802400AC 00821025 */   or       $v0, $a0, $v0
.L802400B0:
/* D79AA0 802400B0 2862000A */  slti      $v0, $v1, 0xa
/* D79AA4 802400B4 10400016 */  beqz      $v0, .L80240110
/* D79AA8 802400B8 28620008 */   slti     $v0, $v1, 8
/* D79AAC 802400BC 14400015 */  bnez      $v0, .L80240114
/* D79AB0 802400C0 3C020100 */   lui      $v0, 0x100
/* D79AB4 802400C4 03E00008 */  jr        $ra
/* D79AB8 802400C8 0080102D */   daddu    $v0, $a0, $zero
.L802400CC:
/* D79ABC 802400CC 3C020001 */  lui       $v0, 1
/* D79AC0 802400D0 3442000C */  ori       $v0, $v0, 0xc
/* D79AC4 802400D4 0044102A */  slt       $v0, $v0, $a0
/* D79AC8 802400D8 1040000E */  beqz      $v0, .L80240114
/* D79ACC 802400DC 3C020100 */   lui      $v0, 0x100
.L802400E0:
/* D79AD0 802400E0 03E00008 */  jr        $ra
/* D79AD4 802400E4 0080102D */   daddu    $v0, $a0, $zero
.L802400E8:
/* D79AD8 802400E8 3C02FFF9 */  lui       $v0, 0xfff9
/* D79ADC 802400EC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D79AE0 802400F0 00821821 */  addu      $v1, $a0, $v0
/* D79AE4 802400F4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D79AE8 802400F8 10400005 */  beqz      $v0, .L80240110
/* D79AEC 802400FC 30620001 */   andi     $v0, $v1, 1
/* D79AF0 80240100 1440FFF7 */  bnez      $v0, .L802400E0
/* D79AF4 80240104 24820001 */   addiu    $v0, $a0, 1
/* D79AF8 80240108 03E00008 */  jr        $ra
/* D79AFC 8024010C 00000000 */   nop      
.L80240110:
/* D79B00 80240110 3C020100 */  lui       $v0, 0x100
.L80240114:
/* D79B04 80240114 03E00008 */  jr        $ra
/* D79B08 80240118 00821025 */   or       $v0, $a0, $v0
