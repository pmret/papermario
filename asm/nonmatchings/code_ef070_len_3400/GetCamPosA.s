.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamPosA
/* 0F0AA4 802CC0F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0AA8 802CC0F8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0AAC 802CC0FC 0080902D */  daddu $s2, $a0, $zero
/* 0F0AB0 802CC100 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0AB4 802CC104 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0AB8 802CC108 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0ABC 802CC10C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0AC0 802CC110 8E250000 */  lw    $a1, ($s1)
/* 0F0AC4 802CC114 0C0B1EAF */  jal   get_variable
/* 0F0AC8 802CC118 26310004 */   addiu $s1, $s1, 4
/* 0F0ACC 802CC11C 3C03800B */  lui   $v1, 0x800b
/* 0F0AD0 802CC120 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0AD4 802CC124 00028080 */  sll   $s0, $v0, 2
/* 0F0AD8 802CC128 02028021 */  addu  $s0, $s0, $v0
/* 0F0ADC 802CC12C 00108080 */  sll   $s0, $s0, 2
/* 0F0AE0 802CC130 02028023 */  subu  $s0, $s0, $v0
/* 0F0AE4 802CC134 001010C0 */  sll   $v0, $s0, 3
/* 0F0AE8 802CC138 02028021 */  addu  $s0, $s0, $v0
/* 0F0AEC 802CC13C 001080C0 */  sll   $s0, $s0, 3
/* 0F0AF0 802CC140 02038021 */  addu  $s0, $s0, $v1
/* 0F0AF4 802CC144 8E250000 */  lw    $a1, ($s1)
/* 0F0AF8 802CC148 8E0604E4 */  lw    $a2, 0x4e4($s0)
/* 0F0AFC 802CC14C 8E310004 */  lw    $s1, 4($s1)
/* 0F0B00 802CC150 0C0B2190 */  jal   set_float_variable
/* 0F0B04 802CC154 0240202D */   daddu $a0, $s2, $zero
/* 0F0B08 802CC158 0240202D */  daddu $a0, $s2, $zero
/* 0F0B0C 802CC15C 8E0604EC */  lw    $a2, 0x4ec($s0)
/* 0F0B10 802CC160 0C0B2190 */  jal   set_float_variable
/* 0F0B14 802CC164 0220282D */   daddu $a1, $s1, $zero
/* 0F0B18 802CC168 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0B1C 802CC16C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0B20 802CC170 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0B24 802CC174 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0B28 802CC178 24020002 */  addiu $v0, $zero, 2
/* 0F0B2C 802CC17C 03E00008 */  jr    $ra
/* 0F0B30 802CC180 27BD0020 */   addiu $sp, $sp, 0x20

