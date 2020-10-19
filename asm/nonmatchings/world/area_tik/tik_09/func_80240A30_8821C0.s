.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A30_882BF0
/* 882BF0 80240A30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 882BF4 80240A34 AFB20018 */  sw        $s2, 0x18($sp)
/* 882BF8 80240A38 0080902D */  daddu     $s2, $a0, $zero
/* 882BFC 80240A3C AFBF001C */  sw        $ra, 0x1c($sp)
/* 882C00 80240A40 AFB10014 */  sw        $s1, 0x14($sp)
/* 882C04 80240A44 AFB00010 */  sw        $s0, 0x10($sp)
/* 882C08 80240A48 8E510148 */  lw        $s1, 0x148($s2)
/* 882C0C 80240A4C 0C00EABB */  jal       get_npc_unsafe
/* 882C10 80240A50 86240008 */   lh       $a0, 8($s1)
/* 882C14 80240A54 0040802D */  daddu     $s0, $v0, $zero
/* 882C18 80240A58 8E2300CC */  lw        $v1, 0xcc($s1)
/* 882C1C 80240A5C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 882C20 80240A60 8C630020 */  lw        $v1, 0x20($v1)
/* 882C24 80240A64 AE030028 */  sw        $v1, 0x28($s0)
/* 882C28 80240A68 96220076 */  lhu       $v0, 0x76($s1)
/* 882C2C 80240A6C A602008E */  sh        $v0, 0x8e($s0)
/* 882C30 80240A70 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 882C34 80240A74 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 882C38 80240A78 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 882C3C 80240A7C 8C460028 */  lw        $a2, 0x28($v0)
/* 882C40 80240A80 0C00A720 */  jal       atan2
/* 882C44 80240A84 8C470030 */   lw       $a3, 0x30($v0)
/* 882C48 80240A88 2402000D */  addiu     $v0, $zero, 0xd
/* 882C4C 80240A8C E600000C */  swc1      $f0, 0xc($s0)
/* 882C50 80240A90 AE420070 */  sw        $v0, 0x70($s2)
/* 882C54 80240A94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 882C58 80240A98 8FB20018 */  lw        $s2, 0x18($sp)
/* 882C5C 80240A9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 882C60 80240AA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 882C64 80240AA4 03E00008 */  jr        $ra
/* 882C68 80240AA8 27BD0020 */   addiu    $sp, $sp, 0x20
