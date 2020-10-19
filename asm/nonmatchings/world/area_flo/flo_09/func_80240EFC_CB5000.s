.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_CB5EFC
/* CB5EFC 80240EFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB5F00 80240F00 AFB20018 */  sw        $s2, 0x18($sp)
/* CB5F04 80240F04 0080902D */  daddu     $s2, $a0, $zero
/* CB5F08 80240F08 AFBF001C */  sw        $ra, 0x1c($sp)
/* CB5F0C 80240F0C AFB10014 */  sw        $s1, 0x14($sp)
/* CB5F10 80240F10 AFB00010 */  sw        $s0, 0x10($sp)
/* CB5F14 80240F14 8E510148 */  lw        $s1, 0x148($s2)
/* CB5F18 80240F18 0C00EABB */  jal       get_npc_unsafe
/* CB5F1C 80240F1C 86240008 */   lh       $a0, 8($s1)
/* CB5F20 80240F20 0040802D */  daddu     $s0, $v0, $zero
/* CB5F24 80240F24 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CB5F28 80240F28 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CB5F2C 80240F2C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CB5F30 80240F30 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CB5F34 80240F34 A600008E */  sh        $zero, 0x8e($s0)
/* CB5F38 80240F38 8C460028 */  lw        $a2, 0x28($v0)
/* CB5F3C 80240F3C 0C00A720 */  jal       atan2
/* CB5F40 80240F40 8C470030 */   lw       $a3, 0x30($v0)
/* CB5F44 80240F44 E600000C */  swc1      $f0, 0xc($s0)
/* CB5F48 80240F48 8E2200CC */  lw        $v0, 0xcc($s1)
/* CB5F4C 80240F4C 8C420020 */  lw        $v0, 0x20($v0)
/* CB5F50 80240F50 AE020028 */  sw        $v0, 0x28($s0)
/* CB5F54 80240F54 2402000B */  addiu     $v0, $zero, 0xb
/* CB5F58 80240F58 AE420070 */  sw        $v0, 0x70($s2)
/* CB5F5C 80240F5C 8FBF001C */  lw        $ra, 0x1c($sp)
/* CB5F60 80240F60 8FB20018 */  lw        $s2, 0x18($sp)
/* CB5F64 80240F64 8FB10014 */  lw        $s1, 0x14($sp)
/* CB5F68 80240F68 8FB00010 */  lw        $s0, 0x10($sp)
/* CB5F6C 80240F6C 03E00008 */  jr        $ra
/* CB5F70 80240F70 27BD0020 */   addiu    $sp, $sp, 0x20
