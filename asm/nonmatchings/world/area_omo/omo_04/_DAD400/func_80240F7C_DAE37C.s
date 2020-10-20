.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F7C_DAE37C
/* DAE37C 80240F7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAE380 80240F80 AFB20018 */  sw        $s2, 0x18($sp)
/* DAE384 80240F84 0080902D */  daddu     $s2, $a0, $zero
/* DAE388 80240F88 AFBF001C */  sw        $ra, 0x1c($sp)
/* DAE38C 80240F8C AFB10014 */  sw        $s1, 0x14($sp)
/* DAE390 80240F90 AFB00010 */  sw        $s0, 0x10($sp)
/* DAE394 80240F94 8E510148 */  lw        $s1, 0x148($s2)
/* DAE398 80240F98 0C00EABB */  jal       get_npc_unsafe
/* DAE39C 80240F9C 86240008 */   lh       $a0, 8($s1)
/* DAE3A0 80240FA0 0040802D */  daddu     $s0, $v0, $zero
/* DAE3A4 80240FA4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DAE3A8 80240FA8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DAE3AC 80240FAC C60C0038 */  lwc1      $f12, 0x38($s0)
/* DAE3B0 80240FB0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DAE3B4 80240FB4 A600008E */  sh        $zero, 0x8e($s0)
/* DAE3B8 80240FB8 8C460028 */  lw        $a2, 0x28($v0)
/* DAE3BC 80240FBC 0C00A720 */  jal       atan2
/* DAE3C0 80240FC0 8C470030 */   lw       $a3, 0x30($v0)
/* DAE3C4 80240FC4 E600000C */  swc1      $f0, 0xc($s0)
/* DAE3C8 80240FC8 8E2200CC */  lw        $v0, 0xcc($s1)
/* DAE3CC 80240FCC 8C420020 */  lw        $v0, 0x20($v0)
/* DAE3D0 80240FD0 AE020028 */  sw        $v0, 0x28($s0)
/* DAE3D4 80240FD4 2402000B */  addiu     $v0, $zero, 0xb
/* DAE3D8 80240FD8 AE420070 */  sw        $v0, 0x70($s2)
/* DAE3DC 80240FDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DAE3E0 80240FE0 8FB20018 */  lw        $s2, 0x18($sp)
/* DAE3E4 80240FE4 8FB10014 */  lw        $s1, 0x14($sp)
/* DAE3E8 80240FE8 8FB00010 */  lw        $s0, 0x10($sp)
/* DAE3EC 80240FEC 03E00008 */  jr        $ra
/* DAE3F0 80240FF0 27BD0020 */   addiu    $sp, $sp, 0x20
