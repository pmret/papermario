.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242438_C38968
/* C38968 80242438 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3896C 8024243C AFB00010 */  sw        $s0, 0x10($sp)
/* C38970 80242440 0080802D */  daddu     $s0, $a0, $zero
/* C38974 80242444 AFBF0018 */  sw        $ra, 0x18($sp)
/* C38978 80242448 AFB10014 */  sw        $s1, 0x14($sp)
/* C3897C 8024244C 8E11000C */  lw        $s1, 0xc($s0)
/* C38980 80242450 8E250000 */  lw        $a1, ($s1)
/* C38984 80242454 0C0B1EAF */  jal       get_variable
/* C38988 80242458 26310004 */   addiu    $s1, $s1, 4
/* C3898C 8024245C 0200202D */  daddu     $a0, $s0, $zero
/* C38990 80242460 3C038011 */  lui       $v1, %hi(gPlayerData)
/* C38994 80242464 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* C38998 80242468 000210C0 */  sll       $v0, $v0, 3
/* C3899C 8024246C 00431021 */  addu      $v0, $v0, $v1
/* C389A0 80242470 90460015 */  lbu       $a2, 0x15($v0)
/* C389A4 80242474 8E250000 */  lw        $a1, ($s1)
/* C389A8 80242478 24C60001 */  addiu     $a2, $a2, 1
/* C389AC 8024247C A0460015 */  sb        $a2, 0x15($v0)
/* C389B0 80242480 00063600 */  sll       $a2, $a2, 0x18
/* C389B4 80242484 0C0B2026 */  jal       set_variable
/* C389B8 80242488 00063603 */   sra      $a2, $a2, 0x18
/* C389BC 8024248C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C389C0 80242490 8FB10014 */  lw        $s1, 0x14($sp)
/* C389C4 80242494 8FB00010 */  lw        $s0, 0x10($sp)
/* C389C8 80242498 24020002 */  addiu     $v0, $zero, 2
/* C389CC 8024249C 03E00008 */  jr        $ra
/* C389D0 802424A0 27BD0020 */   addiu    $sp, $sp, 0x20
