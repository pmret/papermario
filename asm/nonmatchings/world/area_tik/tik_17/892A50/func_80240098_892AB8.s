.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240098_892AB8
/* 892AB8 80240098 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 892ABC 8024009C AFB00010 */  sw        $s0, 0x10($sp)
/* 892AC0 802400A0 0080802D */  daddu     $s0, $a0, $zero
/* 892AC4 802400A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 892AC8 802400A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 892ACC 802400AC 8E11000C */  lw        $s1, 0xc($s0)
/* 892AD0 802400B0 8E250000 */  lw        $a1, ($s1)
/* 892AD4 802400B4 0C0B1EAF */  jal       get_variable
/* 892AD8 802400B8 26310004 */   addiu    $s1, $s1, 4
/* 892ADC 802400BC 0200202D */  daddu     $a0, $s0, $zero
/* 892AE0 802400C0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 892AE4 802400C4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 892AE8 802400C8 000210C0 */  sll       $v0, $v0, 3
/* 892AEC 802400CC 00431021 */  addu      $v0, $v0, $v1
/* 892AF0 802400D0 90460015 */  lbu       $a2, 0x15($v0)
/* 892AF4 802400D4 8E250000 */  lw        $a1, ($s1)
/* 892AF8 802400D8 24C60001 */  addiu     $a2, $a2, 1
/* 892AFC 802400DC A0460015 */  sb        $a2, 0x15($v0)
/* 892B00 802400E0 00063600 */  sll       $a2, $a2, 0x18
/* 892B04 802400E4 0C0B2026 */  jal       set_variable
/* 892B08 802400E8 00063603 */   sra      $a2, $a2, 0x18
/* 892B0C 802400EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 892B10 802400F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 892B14 802400F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 892B18 802400F8 24020002 */  addiu     $v0, $zero, 2
/* 892B1C 802400FC 03E00008 */  jr        $ra
/* 892B20 80240100 27BD0020 */   addiu    $sp, $sp, 0x20
