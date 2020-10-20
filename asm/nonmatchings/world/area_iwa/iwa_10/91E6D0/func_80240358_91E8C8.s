.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240358_91E8C8
/* 91E8C8 80240358 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91E8CC 8024035C AFB00010 */  sw        $s0, 0x10($sp)
/* 91E8D0 80240360 0080802D */  daddu     $s0, $a0, $zero
/* 91E8D4 80240364 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91E8D8 80240368 AFB10014 */  sw        $s1, 0x14($sp)
/* 91E8DC 8024036C 8E11000C */  lw        $s1, 0xc($s0)
/* 91E8E0 80240370 8E250000 */  lw        $a1, ($s1)
/* 91E8E4 80240374 0C0B1EAF */  jal       get_variable
/* 91E8E8 80240378 26310004 */   addiu    $s1, $s1, 4
/* 91E8EC 8024037C 0200202D */  daddu     $a0, $s0, $zero
/* 91E8F0 80240380 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 91E8F4 80240384 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 91E8F8 80240388 000210C0 */  sll       $v0, $v0, 3
/* 91E8FC 8024038C 00431021 */  addu      $v0, $v0, $v1
/* 91E900 80240390 90460015 */  lbu       $a2, 0x15($v0)
/* 91E904 80240394 8E250000 */  lw        $a1, ($s1)
/* 91E908 80240398 24C60001 */  addiu     $a2, $a2, 1
/* 91E90C 8024039C A0460015 */  sb        $a2, 0x15($v0)
/* 91E910 802403A0 00063600 */  sll       $a2, $a2, 0x18
/* 91E914 802403A4 0C0B2026 */  jal       set_variable
/* 91E918 802403A8 00063603 */   sra      $a2, $a2, 0x18
/* 91E91C 802403AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91E920 802403B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 91E924 802403B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 91E928 802403B8 24020002 */  addiu     $v0, $zero, 2
/* 91E92C 802403BC 03E00008 */  jr        $ra
/* 91E930 802403C0 27BD0020 */   addiu    $sp, $sp, 0x20
