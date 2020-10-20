.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BDC_8D20EC
/* 8D20EC 80240BDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8D20F0 80240BE0 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D20F4 80240BE4 0080902D */  daddu     $s2, $a0, $zero
/* 8D20F8 80240BE8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8D20FC 80240BEC AFB10014 */  sw        $s1, 0x14($sp)
/* 8D2100 80240BF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D2104 80240BF4 8E510148 */  lw        $s1, 0x148($s2)
/* 8D2108 80240BF8 0C00EABB */  jal       get_npc_unsafe
/* 8D210C 80240BFC 86240008 */   lh       $a0, 8($s1)
/* 8D2110 80240C00 0040802D */  daddu     $s0, $v0, $zero
/* 8D2114 80240C04 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8D2118 80240C08 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8D211C 80240C0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8D2120 80240C10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8D2124 80240C14 A600008E */  sh        $zero, 0x8e($s0)
/* 8D2128 80240C18 8C460028 */  lw        $a2, 0x28($v0)
/* 8D212C 80240C1C 0C00A720 */  jal       atan2
/* 8D2130 80240C20 8C470030 */   lw       $a3, 0x30($v0)
/* 8D2134 80240C24 E600000C */  swc1      $f0, 0xc($s0)
/* 8D2138 80240C28 8E2200CC */  lw        $v0, 0xcc($s1)
/* 8D213C 80240C2C 8C420020 */  lw        $v0, 0x20($v0)
/* 8D2140 80240C30 AE020028 */  sw        $v0, 0x28($s0)
/* 8D2144 80240C34 2402000B */  addiu     $v0, $zero, 0xb
/* 8D2148 80240C38 AE420070 */  sw        $v0, 0x70($s2)
/* 8D214C 80240C3C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8D2150 80240C40 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D2154 80240C44 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D2158 80240C48 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D215C 80240C4C 03E00008 */  jr        $ra
/* 8D2160 80240C50 27BD0020 */   addiu    $sp, $sp, 0x20
