.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044E9C
/* 2029C 80044E9C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 202A0 80044EA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 202A4 80044EA4 0080882D */  daddu     $s1, $a0, $zero
/* 202A8 80044EA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 202AC 80044EAC AFB3001C */  sw        $s3, 0x1c($sp)
/* 202B0 80044EB0 AFB20018 */  sw        $s2, 0x18($sp)
/* 202B4 80044EB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 202B8 80044EB8 8E30000C */  lw        $s0, 0xc($s1)
/* 202BC 80044EBC 8E330148 */  lw        $s3, 0x148($s1)
/* 202C0 80044EC0 8E050000 */  lw        $a1, ($s0)
/* 202C4 80044EC4 0C0B1EAF */  jal       func_802C7ABC
/* 202C8 80044EC8 26100004 */   addiu    $s0, $s0, 4
/* 202CC 80044ECC 0040902D */  daddu     $s2, $v0, $zero
/* 202D0 80044ED0 8E050000 */  lw        $a1, ($s0)
/* 202D4 80044ED4 0C0B1EAF */  jal       func_802C7ABC
/* 202D8 80044ED8 0220202D */   daddu    $a0, $s1, $zero
/* 202DC 80044EDC 0040802D */  daddu     $s0, $v0, $zero
/* 202E0 80044EE0 2402FFFF */  addiu     $v0, $zero, -1
/* 202E4 80044EE4 16420002 */  bne       $s2, $v0, .L80044EF0
/* 202E8 80044EE8 00000000 */   nop
/* 202EC 80044EEC 86720008 */  lh        $s2, 8($s3)
.L80044EF0:
/* 202F0 80044EF0 0C00FA6A */  jal       func_8003E9A8
/* 202F4 80044EF4 0240202D */   daddu    $a0, $s2, $zero
/* 202F8 80044EF8 AC500030 */  sw        $s0, 0x30($v0)
/* 202FC 80044EFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20300 80044F00 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20304 80044F04 8FB20018 */  lw        $s2, 0x18($sp)
/* 20308 80044F08 8FB10014 */  lw        $s1, 0x14($sp)
/* 2030C 80044F0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20310 80044F10 24020002 */  addiu     $v0, $zero, 2
/* 20314 80044F14 03E00008 */  jr        $ra
/* 20318 80044F18 27BD0028 */   addiu    $sp, $sp, 0x28
