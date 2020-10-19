.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A3C_BAAB7C
/* BAAB7C 80240A3C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAAB80 80240A40 AFB10014 */  sw        $s1, 0x14($sp)
/* BAAB84 80240A44 0080882D */  daddu     $s1, $a0, $zero
/* BAAB88 80240A48 AFBF001C */  sw        $ra, 0x1c($sp)
/* BAAB8C 80240A4C AFB20018 */  sw        $s2, 0x18($sp)
/* BAAB90 80240A50 AFB00010 */  sw        $s0, 0x10($sp)
/* BAAB94 80240A54 8E220148 */  lw        $v0, 0x148($s1)
/* BAAB98 80240A58 00A0902D */  daddu     $s2, $a1, $zero
/* BAAB9C 80240A5C 84440008 */  lh        $a0, 8($v0)
/* BAABA0 80240A60 0C00EABB */  jal       get_npc_unsafe
/* BAABA4 80240A64 00C0802D */   daddu    $s0, $a2, $zero
/* BAABA8 80240A68 0220202D */  daddu     $a0, $s1, $zero
/* BAABAC 80240A6C 0240282D */  daddu     $a1, $s2, $zero
/* BAABB0 80240A70 0200302D */  daddu     $a2, $s0, $zero
/* BAABB4 80240A74 0C0127DF */  jal       func_80049F7C
/* BAABB8 80240A78 0040802D */   daddu    $s0, $v0, $zero
/* BAABBC 80240A7C 8E020000 */  lw        $v0, ($s0)
/* BAABC0 80240A80 24040005 */  addiu     $a0, $zero, 5
/* BAABC4 80240A84 34420800 */  ori       $v0, $v0, 0x800
/* BAABC8 80240A88 0C00A67F */  jal       rand_int
/* BAABCC 80240A8C AE020000 */   sw       $v0, ($s0)
/* BAABD0 80240A90 44820000 */  mtc1      $v0, $f0
/* BAABD4 80240A94 00000000 */  nop       
/* BAABD8 80240A98 46800021 */  cvt.d.w   $f0, $f0
/* BAABDC 80240A9C 3C014024 */  lui       $at, 0x4024
/* BAABE0 80240AA0 44811800 */  mtc1      $at, $f3
/* BAABE4 80240AA4 44801000 */  mtc1      $zero, $f2
/* BAABE8 80240AA8 3C013FC0 */  lui       $at, 0x3fc0
/* BAABEC 80240AAC 44812000 */  mtc1      $at, $f4
/* BAABF0 80240AB0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAABF4 80240AB4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAABF8 80240AB8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAABFC 80240ABC C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAAC00 80240AC0 46220000 */  add.d     $f0, $f0, $f2
/* BAAC04 80240AC4 E6040014 */  swc1      $f4, 0x14($s0)
/* BAAC08 80240AC8 46200020 */  cvt.s.d   $f0, $f0
/* BAAC0C 80240ACC E600001C */  swc1      $f0, 0x1c($s0)
/* BAAC10 80240AD0 8C460028 */  lw        $a2, 0x28($v0)
/* BAAC14 80240AD4 0C00A720 */  jal       atan2
/* BAAC18 80240AD8 8C470030 */   lw       $a3, 0x30($v0)
/* BAAC1C 80240ADC 0200202D */  daddu     $a0, $s0, $zero
/* BAAC20 80240AE0 3C05B000 */  lui       $a1, 0xb000
/* BAAC24 80240AE4 34A50017 */  ori       $a1, $a1, 0x17
/* BAAC28 80240AE8 0000302D */  daddu     $a2, $zero, $zero
/* BAAC2C 80240AEC E480000C */  swc1      $f0, 0xc($a0)
/* BAAC30 80240AF0 C6400018 */  lwc1      $f0, 0x18($s2)
/* BAAC34 80240AF4 2402000D */  addiu     $v0, $zero, 0xd
/* BAAC38 80240AF8 E4800018 */  swc1      $f0, 0x18($a0)
/* BAAC3C 80240AFC 0C012530 */  jal       func_800494C0
/* BAAC40 80240B00 AE220070 */   sw       $v0, 0x70($s1)
/* BAAC44 80240B04 8FBF001C */  lw        $ra, 0x1c($sp)
/* BAAC48 80240B08 8FB20018 */  lw        $s2, 0x18($sp)
/* BAAC4C 80240B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* BAAC50 80240B10 8FB00010 */  lw        $s0, 0x10($sp)
/* BAAC54 80240B14 03E00008 */  jr        $ra
/* BAAC58 80240B18 27BD0020 */   addiu    $sp, $sp, 0x20
