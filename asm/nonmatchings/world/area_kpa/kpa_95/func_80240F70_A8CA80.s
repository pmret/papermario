.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F70_A8D9F0
/* A8D9F0 80240F70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8D9F4 80240F74 AFB20018 */  sw        $s2, 0x18($sp)
/* A8D9F8 80240F78 0080902D */  daddu     $s2, $a0, $zero
/* A8D9FC 80240F7C AFBF001C */  sw        $ra, 0x1c($sp)
/* A8DA00 80240F80 AFB10014 */  sw        $s1, 0x14($sp)
/* A8DA04 80240F84 AFB00010 */  sw        $s0, 0x10($sp)
/* A8DA08 80240F88 8E510148 */  lw        $s1, 0x148($s2)
/* A8DA0C 80240F8C 0C00EABB */  jal       get_npc_unsafe
/* A8DA10 80240F90 86240008 */   lh       $a0, 8($s1)
/* A8DA14 80240F94 0040802D */  daddu     $s0, $v0, $zero
/* A8DA18 80240F98 8E2300CC */  lw        $v1, 0xcc($s1)
/* A8DA1C 80240F9C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A8DA20 80240FA0 8C630020 */  lw        $v1, 0x20($v1)
/* A8DA24 80240FA4 AE030028 */  sw        $v1, 0x28($s0)
/* A8DA28 80240FA8 96220076 */  lhu       $v0, 0x76($s1)
/* A8DA2C 80240FAC A602008E */  sh        $v0, 0x8e($s0)
/* A8DA30 80240FB0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A8DA34 80240FB4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A8DA38 80240FB8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8DA3C 80240FBC 8C460028 */  lw        $a2, 0x28($v0)
/* A8DA40 80240FC0 0C00A720 */  jal       atan2
/* A8DA44 80240FC4 8C470030 */   lw       $a3, 0x30($v0)
/* A8DA48 80240FC8 2402000D */  addiu     $v0, $zero, 0xd
/* A8DA4C 80240FCC E600000C */  swc1      $f0, 0xc($s0)
/* A8DA50 80240FD0 AE420070 */  sw        $v0, 0x70($s2)
/* A8DA54 80240FD4 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8DA58 80240FD8 8FB20018 */  lw        $s2, 0x18($sp)
/* A8DA5C 80240FDC 8FB10014 */  lw        $s1, 0x14($sp)
/* A8DA60 80240FE0 8FB00010 */  lw        $s0, 0x10($sp)
/* A8DA64 80240FE4 03E00008 */  jr        $ra
/* A8DA68 80240FE8 27BD0020 */   addiu    $sp, $sp, 0x20
