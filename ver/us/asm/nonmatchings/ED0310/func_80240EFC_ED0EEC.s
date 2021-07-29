.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_ED0EEC
/* ED0EEC 80240EFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ED0EF0 80240F00 AFB20018 */  sw        $s2, 0x18($sp)
/* ED0EF4 80240F04 0080902D */  daddu     $s2, $a0, $zero
/* ED0EF8 80240F08 AFBF001C */  sw        $ra, 0x1c($sp)
/* ED0EFC 80240F0C AFB10014 */  sw        $s1, 0x14($sp)
/* ED0F00 80240F10 AFB00010 */  sw        $s0, 0x10($sp)
/* ED0F04 80240F14 8E510148 */  lw        $s1, 0x148($s2)
/* ED0F08 80240F18 0C00F92F */  jal       func_8003E4BC
/* ED0F0C 80240F1C 86240008 */   lh       $a0, 8($s1)
/* ED0F10 80240F20 0040802D */  daddu     $s0, $v0, $zero
/* ED0F14 80240F24 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* ED0F18 80240F28 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* ED0F1C 80240F2C C60C0038 */  lwc1      $f12, 0x38($s0)
/* ED0F20 80240F30 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ED0F24 80240F34 A600008E */  sh        $zero, 0x8e($s0)
/* ED0F28 80240F38 8C460028 */  lw        $a2, 0x28($v0)
/* ED0F2C 80240F3C 0C00ABDC */  jal       fio_validate_header_checksums
/* ED0F30 80240F40 8C470030 */   lw       $a3, 0x30($v0)
/* ED0F34 80240F44 E600000C */  swc1      $f0, 0xc($s0)
/* ED0F38 80240F48 8E2200CC */  lw        $v0, 0xcc($s1)
/* ED0F3C 80240F4C 8C420020 */  lw        $v0, 0x20($v0)
/* ED0F40 80240F50 AE020028 */  sw        $v0, 0x28($s0)
/* ED0F44 80240F54 2402000B */  addiu     $v0, $zero, 0xb
/* ED0F48 80240F58 AE420070 */  sw        $v0, 0x70($s2)
/* ED0F4C 80240F5C 8FBF001C */  lw        $ra, 0x1c($sp)
/* ED0F50 80240F60 8FB20018 */  lw        $s2, 0x18($sp)
/* ED0F54 80240F64 8FB10014 */  lw        $s1, 0x14($sp)
/* ED0F58 80240F68 8FB00010 */  lw        $s0, 0x10($sp)
/* ED0F5C 80240F6C 03E00008 */  jr        $ra
/* ED0F60 80240F70 27BD0020 */   addiu    $sp, $sp, 0x20
