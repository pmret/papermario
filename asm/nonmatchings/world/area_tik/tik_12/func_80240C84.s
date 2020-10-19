.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C84
/* 889854 80240C84 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 889858 80240C88 AFB00010 */  sw        $s0, 0x10($sp)
/* 88985C 80240C8C 0080802D */  daddu     $s0, $a0, $zero
/* 889860 80240C90 AFBF0018 */  sw        $ra, 0x18($sp)
/* 889864 80240C94 AFB10014 */  sw        $s1, 0x14($sp)
/* 889868 80240C98 8E11000C */  lw        $s1, 0xc($s0)
/* 88986C 80240C9C 8E250000 */  lw        $a1, ($s1)
/* 889870 80240CA0 0C0B1EAF */  jal       get_variable
/* 889874 80240CA4 26310004 */   addiu    $s1, $s1, 4
/* 889878 80240CA8 0200202D */  daddu     $a0, $s0, $zero
/* 88987C 80240CAC 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 889880 80240CB0 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 889884 80240CB4 000210C0 */  sll       $v0, $v0, 3
/* 889888 80240CB8 00431021 */  addu      $v0, $v0, $v1
/* 88988C 80240CBC 90460015 */  lbu       $a2, 0x15($v0)
/* 889890 80240CC0 8E250000 */  lw        $a1, ($s1)
/* 889894 80240CC4 24C60001 */  addiu     $a2, $a2, 1
/* 889898 80240CC8 A0460015 */  sb        $a2, 0x15($v0)
/* 88989C 80240CCC 00063600 */  sll       $a2, $a2, 0x18
/* 8898A0 80240CD0 0C0B2026 */  jal       set_variable
/* 8898A4 80240CD4 00063603 */   sra      $a2, $a2, 0x18
/* 8898A8 80240CD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8898AC 80240CDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8898B0 80240CE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8898B4 80240CE4 24020002 */  addiu     $v0, $zero, 2
/* 8898B8 80240CE8 03E00008 */  jr        $ra
/* 8898BC 80240CEC 27BD0020 */   addiu    $sp, $sp, 0x20
