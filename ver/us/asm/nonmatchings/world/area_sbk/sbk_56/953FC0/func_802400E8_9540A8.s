.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sbk_56_UnkFunc18
/* 9540A8 802400E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9540AC 802400EC AFB00010 */  sw        $s0, 0x10($sp)
/* 9540B0 802400F0 0080802D */  daddu     $s0, $a0, $zero
/* 9540B4 802400F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9540B8 802400F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9540BC 802400FC 8E11000C */  lw        $s1, 0xc($s0)
/* 9540C0 80240100 8E250000 */  lw        $a1, ($s1)
/* 9540C4 80240104 0C0B1EAF */  jal       get_variable
/* 9540C8 80240108 26310004 */   addiu    $s1, $s1, 4
/* 9540CC 8024010C 0200202D */  daddu     $a0, $s0, $zero
/* 9540D0 80240110 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 9540D4 80240114 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 9540D8 80240118 000210C0 */  sll       $v0, $v0, 3
/* 9540DC 8024011C 00431021 */  addu      $v0, $v0, $v1
/* 9540E0 80240120 90460015 */  lbu       $a2, 0x15($v0)
/* 9540E4 80240124 8E250000 */  lw        $a1, ($s1)
/* 9540E8 80240128 24C60001 */  addiu     $a2, $a2, 1
/* 9540EC 8024012C A0460015 */  sb        $a2, 0x15($v0)
/* 9540F0 80240130 00063600 */  sll       $a2, $a2, 0x18
/* 9540F4 80240134 0C0B2026 */  jal       set_variable
/* 9540F8 80240138 00063603 */   sra      $a2, $a2, 0x18
/* 9540FC 8024013C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 954100 80240140 8FB10014 */  lw        $s1, 0x14($sp)
/* 954104 80240144 8FB00010 */  lw        $s0, 0x10($sp)
/* 954108 80240148 24020002 */  addiu     $v0, $zero, 2
/* 95410C 8024014C 03E00008 */  jr        $ra
/* 954110 80240150 27BD0020 */   addiu    $sp, $sp, 0x20
