.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024112C_D20FBC
/* D20FBC 8024112C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D20FC0 80241130 AFB20018 */  sw        $s2, 0x18($sp)
/* D20FC4 80241134 0080902D */  daddu     $s2, $a0, $zero
/* D20FC8 80241138 AFBF001C */  sw        $ra, 0x1c($sp)
/* D20FCC 8024113C AFB10014 */  sw        $s1, 0x14($sp)
/* D20FD0 80241140 AFB00010 */  sw        $s0, 0x10($sp)
/* D20FD4 80241144 8E510148 */  lw        $s1, 0x148($s2)
/* D20FD8 80241148 0C00EABB */  jal       get_npc_unsafe
/* D20FDC 8024114C 86240008 */   lh       $a0, 8($s1)
/* D20FE0 80241150 0040802D */  daddu     $s0, $v0, $zero
/* D20FE4 80241154 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D20FE8 80241158 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D20FEC 8024115C C60C0038 */  lwc1      $f12, 0x38($s0)
/* D20FF0 80241160 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D20FF4 80241164 A600008E */  sh        $zero, 0x8e($s0)
/* D20FF8 80241168 8C460028 */  lw        $a2, 0x28($v0)
/* D20FFC 8024116C 0C00A720 */  jal       atan2
/* D21000 80241170 8C470030 */   lw       $a3, 0x30($v0)
/* D21004 80241174 E600000C */  swc1      $f0, 0xc($s0)
/* D21008 80241178 8E2200CC */  lw        $v0, 0xcc($s1)
/* D2100C 8024117C 8C420020 */  lw        $v0, 0x20($v0)
/* D21010 80241180 AE020028 */  sw        $v0, 0x28($s0)
/* D21014 80241184 2402000B */  addiu     $v0, $zero, 0xb
/* D21018 80241188 AE420070 */  sw        $v0, 0x70($s2)
/* D2101C 8024118C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D21020 80241190 8FB20018 */  lw        $s2, 0x18($sp)
/* D21024 80241194 8FB10014 */  lw        $s1, 0x14($sp)
/* D21028 80241198 8FB00010 */  lw        $s0, 0x10($sp)
/* D2102C 8024119C 03E00008 */  jr        $ra
/* D21030 802411A0 27BD0020 */   addiu    $sp, $sp, 0x20
