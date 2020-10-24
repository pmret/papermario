.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429F4_9AADE4
/* 9AADE4 802429F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9AADE8 802429F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AADEC 802429FC 0080902D */  daddu     $s2, $a0, $zero
/* 9AADF0 80242A00 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9AADF4 80242A04 AFB10014 */  sw        $s1, 0x14($sp)
/* 9AADF8 80242A08 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AADFC 80242A0C 8E510148 */  lw        $s1, 0x148($s2)
/* 9AAE00 80242A10 0C00EABB */  jal       get_npc_unsafe
/* 9AAE04 80242A14 86240008 */   lh       $a0, 8($s1)
/* 9AAE08 80242A18 0040802D */  daddu     $s0, $v0, $zero
/* 9AAE0C 80242A1C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9AAE10 80242A20 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9AAE14 80242A24 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9AAE18 80242A28 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9AAE1C 80242A2C A600008E */  sh        $zero, 0x8e($s0)
/* 9AAE20 80242A30 8C460028 */  lw        $a2, 0x28($v0)
/* 9AAE24 80242A34 0C00A720 */  jal       atan2
/* 9AAE28 80242A38 8C470030 */   lw       $a3, 0x30($v0)
/* 9AAE2C 80242A3C E600000C */  swc1      $f0, 0xc($s0)
/* 9AAE30 80242A40 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AAE34 80242A44 8C420020 */  lw        $v0, 0x20($v0)
/* 9AAE38 80242A48 AE020028 */  sw        $v0, 0x28($s0)
/* 9AAE3C 80242A4C 2402000B */  addiu     $v0, $zero, 0xb
/* 9AAE40 80242A50 AE420070 */  sw        $v0, 0x70($s2)
/* 9AAE44 80242A54 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9AAE48 80242A58 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AAE4C 80242A5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AAE50 80242A60 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AAE54 80242A64 03E00008 */  jr        $ra
/* 9AAE58 80242A68 27BD0020 */   addiu    $sp, $sp, 0x20
