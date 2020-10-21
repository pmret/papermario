.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024152C_BEE31C
/* BEE31C 8024152C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BEE320 80241530 AFB20018 */  sw        $s2, 0x18($sp)
/* BEE324 80241534 0080902D */  daddu     $s2, $a0, $zero
/* BEE328 80241538 AFBF001C */  sw        $ra, 0x1c($sp)
/* BEE32C 8024153C AFB10014 */  sw        $s1, 0x14($sp)
/* BEE330 80241540 AFB00010 */  sw        $s0, 0x10($sp)
/* BEE334 80241544 8E510148 */  lw        $s1, 0x148($s2)
/* BEE338 80241548 0C00EABB */  jal       get_npc_unsafe
/* BEE33C 8024154C 86240008 */   lh       $a0, 8($s1)
/* BEE340 80241550 0040802D */  daddu     $s0, $v0, $zero
/* BEE344 80241554 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BEE348 80241558 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BEE34C 8024155C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BEE350 80241560 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BEE354 80241564 A600008E */  sh        $zero, 0x8e($s0)
/* BEE358 80241568 8C460028 */  lw        $a2, 0x28($v0)
/* BEE35C 8024156C 0C00A720 */  jal       atan2
/* BEE360 80241570 8C470030 */   lw       $a3, 0x30($v0)
/* BEE364 80241574 E600000C */  swc1      $f0, 0xc($s0)
/* BEE368 80241578 8E2200CC */  lw        $v0, 0xcc($s1)
/* BEE36C 8024157C 8C420020 */  lw        $v0, 0x20($v0)
/* BEE370 80241580 AE020028 */  sw        $v0, 0x28($s0)
/* BEE374 80241584 2402000B */  addiu     $v0, $zero, 0xb
/* BEE378 80241588 AE420070 */  sw        $v0, 0x70($s2)
/* BEE37C 8024158C 8FBF001C */  lw        $ra, 0x1c($sp)
/* BEE380 80241590 8FB20018 */  lw        $s2, 0x18($sp)
/* BEE384 80241594 8FB10014 */  lw        $s1, 0x14($sp)
/* BEE388 80241598 8FB00010 */  lw        $s0, 0x10($sp)
/* BEE38C 8024159C 03E00008 */  jr        $ra
/* BEE390 802415A0 27BD0020 */   addiu    $sp, $sp, 0x20
