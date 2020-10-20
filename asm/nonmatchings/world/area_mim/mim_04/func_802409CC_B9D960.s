.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409CC_B9E32C
/* B9E32C 802409CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9E330 802409D0 AFB10014 */  sw        $s1, 0x14($sp)
/* B9E334 802409D4 0080882D */  daddu     $s1, $a0, $zero
/* B9E338 802409D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B9E33C 802409DC AFB20018 */  sw        $s2, 0x18($sp)
/* B9E340 802409E0 AFB00010 */  sw        $s0, 0x10($sp)
/* B9E344 802409E4 8E220148 */  lw        $v0, 0x148($s1)
/* B9E348 802409E8 00A0902D */  daddu     $s2, $a1, $zero
/* B9E34C 802409EC 84440008 */  lh        $a0, 8($v0)
/* B9E350 802409F0 0C00EABB */  jal       get_npc_unsafe
/* B9E354 802409F4 00C0802D */   daddu    $s0, $a2, $zero
/* B9E358 802409F8 0220202D */  daddu     $a0, $s1, $zero
/* B9E35C 802409FC 0240282D */  daddu     $a1, $s2, $zero
/* B9E360 80240A00 0200302D */  daddu     $a2, $s0, $zero
/* B9E364 80240A04 0C0127DF */  jal       func_80049F7C
/* B9E368 80240A08 0040802D */   daddu    $s0, $v0, $zero
/* B9E36C 80240A0C 8E020000 */  lw        $v0, ($s0)
/* B9E370 80240A10 24040005 */  addiu     $a0, $zero, 5
/* B9E374 80240A14 34420800 */  ori       $v0, $v0, 0x800
/* B9E378 80240A18 0C00A67F */  jal       rand_int
/* B9E37C 80240A1C AE020000 */   sw       $v0, ($s0)
/* B9E380 80240A20 44820000 */  mtc1      $v0, $f0
/* B9E384 80240A24 00000000 */  nop       
/* B9E388 80240A28 46800021 */  cvt.d.w   $f0, $f0
/* B9E38C 80240A2C 3C014024 */  lui       $at, 0x4024
/* B9E390 80240A30 44811800 */  mtc1      $at, $f3
/* B9E394 80240A34 44801000 */  mtc1      $zero, $f2
/* B9E398 80240A38 3C013FC0 */  lui       $at, 0x3fc0
/* B9E39C 80240A3C 44812000 */  mtc1      $at, $f4
/* B9E3A0 80240A40 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B9E3A4 80240A44 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B9E3A8 80240A48 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B9E3AC 80240A4C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B9E3B0 80240A50 46220000 */  add.d     $f0, $f0, $f2
/* B9E3B4 80240A54 E6040014 */  swc1      $f4, 0x14($s0)
/* B9E3B8 80240A58 46200020 */  cvt.s.d   $f0, $f0
/* B9E3BC 80240A5C E600001C */  swc1      $f0, 0x1c($s0)
/* B9E3C0 80240A60 8C460028 */  lw        $a2, 0x28($v0)
/* B9E3C4 80240A64 0C00A720 */  jal       atan2
/* B9E3C8 80240A68 8C470030 */   lw       $a3, 0x30($v0)
/* B9E3CC 80240A6C 0200202D */  daddu     $a0, $s0, $zero
/* B9E3D0 80240A70 3C05B000 */  lui       $a1, 0xb000
/* B9E3D4 80240A74 34A50017 */  ori       $a1, $a1, 0x17
/* B9E3D8 80240A78 0000302D */  daddu     $a2, $zero, $zero
/* B9E3DC 80240A7C E480000C */  swc1      $f0, 0xc($a0)
/* B9E3E0 80240A80 C6400018 */  lwc1      $f0, 0x18($s2)
/* B9E3E4 80240A84 2402000D */  addiu     $v0, $zero, 0xd
/* B9E3E8 80240A88 E4800018 */  swc1      $f0, 0x18($a0)
/* B9E3EC 80240A8C 0C012530 */  jal       func_800494C0
/* B9E3F0 80240A90 AE220070 */   sw       $v0, 0x70($s1)
/* B9E3F4 80240A94 8FBF001C */  lw        $ra, 0x1c($sp)
/* B9E3F8 80240A98 8FB20018 */  lw        $s2, 0x18($sp)
/* B9E3FC 80240A9C 8FB10014 */  lw        $s1, 0x14($sp)
/* B9E400 80240AA0 8FB00010 */  lw        $s0, 0x10($sp)
/* B9E404 80240AA4 03E00008 */  jr        $ra
/* B9E408 80240AA8 27BD0020 */   addiu    $sp, $sp, 0x20
