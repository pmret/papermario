.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240068_D2FCE8
/* D2FCE8 80240068 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2FCEC 8024006C AFB00010 */  sw        $s0, 0x10($sp)
/* D2FCF0 80240070 0080802D */  daddu     $s0, $a0, $zero
/* D2FCF4 80240074 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2FCF8 80240078 AFB10014 */  sw        $s1, 0x14($sp)
/* D2FCFC 8024007C 8E11000C */  lw        $s1, 0xc($s0)
/* D2FD00 80240080 8E250000 */  lw        $a1, ($s1)
/* D2FD04 80240084 0C0B1EAF */  jal       get_variable
/* D2FD08 80240088 26310004 */   addiu    $s1, $s1, 4
/* D2FD0C 8024008C 0200202D */  daddu     $a0, $s0, $zero
/* D2FD10 80240090 3C038011 */  lui       $v1, %hi(gPlayerData)
/* D2FD14 80240094 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* D2FD18 80240098 000210C0 */  sll       $v0, $v0, 3
/* D2FD1C 8024009C 00431021 */  addu      $v0, $v0, $v1
/* D2FD20 802400A0 90460015 */  lbu       $a2, 0x15($v0)
/* D2FD24 802400A4 8E250000 */  lw        $a1, ($s1)
/* D2FD28 802400A8 24C60001 */  addiu     $a2, $a2, 1
/* D2FD2C 802400AC A0460015 */  sb        $a2, 0x15($v0)
/* D2FD30 802400B0 00063600 */  sll       $a2, $a2, 0x18
/* D2FD34 802400B4 0C0B2026 */  jal       set_variable
/* D2FD38 802400B8 00063603 */   sra      $a2, $a2, 0x18
/* D2FD3C 802400BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2FD40 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* D2FD44 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* D2FD48 802400C8 24020002 */  addiu     $v0, $zero, 2
/* D2FD4C 802400CC 03E00008 */  jr        $ra
/* D2FD50 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
