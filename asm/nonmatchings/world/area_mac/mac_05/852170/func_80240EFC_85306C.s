.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_85306C
/* 85306C 80240EFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 853070 80240F00 AFB10014 */  sw        $s1, 0x14($sp)
/* 853074 80240F04 0080882D */  daddu     $s1, $a0, $zero
/* 853078 80240F08 AFBF0018 */  sw        $ra, 0x18($sp)
/* 85307C 80240F0C AFB00010 */  sw        $s0, 0x10($sp)
/* 853080 80240F10 8E300148 */  lw        $s0, 0x148($s1)
/* 853084 80240F14 0C00EABB */  jal       get_npc_unsafe
/* 853088 80240F18 86040008 */   lh       $a0, 8($s0)
/* 85308C 80240F1C 9443008E */  lhu       $v1, 0x8e($v0)
/* 853090 80240F20 2463FFFF */  addiu     $v1, $v1, -1
/* 853094 80240F24 A443008E */  sh        $v1, 0x8e($v0)
/* 853098 80240F28 00031C00 */  sll       $v1, $v1, 0x10
/* 85309C 80240F2C 14600008 */  bnez      $v1, .L80240F50
/* 8530A0 80240F30 00000000 */   nop      
/* 8530A4 80240F34 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 8530A8 80240F38 30420080 */  andi      $v0, $v0, 0x80
/* 8530AC 80240F3C 10400003 */  beqz      $v0, .L80240F4C
/* 8530B0 80240F40 2402000F */   addiu    $v0, $zero, 0xf
/* 8530B4 80240F44 080903D4 */  j         .L80240F50
/* 8530B8 80240F48 AE220070 */   sw       $v0, 0x70($s1)
.L80240F4C:
/* 8530BC 80240F4C AE200070 */  sw        $zero, 0x70($s1)
.L80240F50:
/* 8530C0 80240F50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8530C4 80240F54 8FB10014 */  lw        $s1, 0x14($sp)
/* 8530C8 80240F58 8FB00010 */  lw        $s0, 0x10($sp)
/* 8530CC 80240F5C 03E00008 */  jr        $ra
/* 8530D0 80240F60 27BD0020 */   addiu    $sp, $sp, 0x20
