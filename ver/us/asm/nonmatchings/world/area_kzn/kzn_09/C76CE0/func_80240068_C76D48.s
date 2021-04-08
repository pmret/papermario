.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_09_UnkFunc18
/* C76D48 80240068 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C76D4C 8024006C AFB00010 */  sw        $s0, 0x10($sp)
/* C76D50 80240070 0080802D */  daddu     $s0, $a0, $zero
/* C76D54 80240074 AFBF0018 */  sw        $ra, 0x18($sp)
/* C76D58 80240078 AFB10014 */  sw        $s1, 0x14($sp)
/* C76D5C 8024007C 8E11000C */  lw        $s1, 0xc($s0)
/* C76D60 80240080 8E250000 */  lw        $a1, ($s1)
/* C76D64 80240084 0C0B1EAF */  jal       get_variable
/* C76D68 80240088 26310004 */   addiu    $s1, $s1, 4
/* C76D6C 8024008C 0200202D */  daddu     $a0, $s0, $zero
/* C76D70 80240090 3C038011 */  lui       $v1, %hi(gPlayerData)
/* C76D74 80240094 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* C76D78 80240098 000210C0 */  sll       $v0, $v0, 3
/* C76D7C 8024009C 00431021 */  addu      $v0, $v0, $v1
/* C76D80 802400A0 90460015 */  lbu       $a2, 0x15($v0)
/* C76D84 802400A4 8E250000 */  lw        $a1, ($s1)
/* C76D88 802400A8 24C60001 */  addiu     $a2, $a2, 1
/* C76D8C 802400AC A0460015 */  sb        $a2, 0x15($v0)
/* C76D90 802400B0 00063600 */  sll       $a2, $a2, 0x18
/* C76D94 802400B4 0C0B2026 */  jal       set_variable
/* C76D98 802400B8 00063603 */   sra      $a2, $a2, 0x18
/* C76D9C 802400BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C76DA0 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* C76DA4 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* C76DA8 802400C8 24020002 */  addiu     $v0, $zero, 2
/* C76DAC 802400CC 03E00008 */  jr        $ra
/* C76DB0 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
