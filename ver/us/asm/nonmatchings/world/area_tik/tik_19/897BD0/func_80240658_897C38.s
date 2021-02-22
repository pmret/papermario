.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240658_897C38
/* 897C38 80240658 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 897C3C 8024065C AFB00010 */  sw        $s0, 0x10($sp)
/* 897C40 80240660 0080802D */  daddu     $s0, $a0, $zero
/* 897C44 80240664 AFBF0018 */  sw        $ra, 0x18($sp)
/* 897C48 80240668 AFB10014 */  sw        $s1, 0x14($sp)
/* 897C4C 8024066C 8E11000C */  lw        $s1, 0xc($s0)
/* 897C50 80240670 8E250000 */  lw        $a1, ($s1)
/* 897C54 80240674 0C0B1EAF */  jal       get_variable
/* 897C58 80240678 26310004 */   addiu    $s1, $s1, 4
/* 897C5C 8024067C 0200202D */  daddu     $a0, $s0, $zero
/* 897C60 80240680 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 897C64 80240684 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 897C68 80240688 000210C0 */  sll       $v0, $v0, 3
/* 897C6C 8024068C 00431021 */  addu      $v0, $v0, $v1
/* 897C70 80240690 90460015 */  lbu       $a2, 0x15($v0)
/* 897C74 80240694 8E250000 */  lw        $a1, ($s1)
/* 897C78 80240698 24C60001 */  addiu     $a2, $a2, 1
/* 897C7C 8024069C A0460015 */  sb        $a2, 0x15($v0)
/* 897C80 802406A0 00063600 */  sll       $a2, $a2, 0x18
/* 897C84 802406A4 0C0B2026 */  jal       set_variable
/* 897C88 802406A8 00063603 */   sra      $a2, $a2, 0x18
/* 897C8C 802406AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 897C90 802406B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 897C94 802406B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 897C98 802406B8 24020002 */  addiu     $v0, $zero, 2
/* 897C9C 802406BC 03E00008 */  jr        $ra
/* 897CA0 802406C0 27BD0020 */   addiu    $sp, $sp, 0x20
