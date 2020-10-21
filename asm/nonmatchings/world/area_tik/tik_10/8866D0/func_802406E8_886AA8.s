.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E8_886AA8
/* 886AA8 802406E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 886AAC 802406EC AFB00010 */  sw        $s0, 0x10($sp)
/* 886AB0 802406F0 0080802D */  daddu     $s0, $a0, $zero
/* 886AB4 802406F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 886AB8 802406F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 886ABC 802406FC 8E11000C */  lw        $s1, 0xc($s0)
/* 886AC0 80240700 8E250000 */  lw        $a1, ($s1)
/* 886AC4 80240704 0C0B1EAF */  jal       get_variable
/* 886AC8 80240708 26310004 */   addiu    $s1, $s1, 4
/* 886ACC 8024070C 0200202D */  daddu     $a0, $s0, $zero
/* 886AD0 80240710 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 886AD4 80240714 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 886AD8 80240718 000210C0 */  sll       $v0, $v0, 3
/* 886ADC 8024071C 00431021 */  addu      $v0, $v0, $v1
/* 886AE0 80240720 90460015 */  lbu       $a2, 0x15($v0)
/* 886AE4 80240724 8E250000 */  lw        $a1, ($s1)
/* 886AE8 80240728 24C60001 */  addiu     $a2, $a2, 1
/* 886AEC 8024072C A0460015 */  sb        $a2, 0x15($v0)
/* 886AF0 80240730 00063600 */  sll       $a2, $a2, 0x18
/* 886AF4 80240734 0C0B2026 */  jal       set_variable
/* 886AF8 80240738 00063603 */   sra      $a2, $a2, 0x18
/* 886AFC 8024073C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 886B00 80240740 8FB10014 */  lw        $s1, 0x14($sp)
/* 886B04 80240744 8FB00010 */  lw        $s0, 0x10($sp)
/* 886B08 80240748 24020002 */  addiu     $v0, $zero, 2
/* 886B0C 8024074C 03E00008 */  jr        $ra
/* 886B10 80240750 27BD0020 */   addiu    $sp, $sp, 0x20
