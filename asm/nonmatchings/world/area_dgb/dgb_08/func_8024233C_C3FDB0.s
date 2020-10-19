.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024233C_C420EC
/* C420EC 8024233C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C420F0 80242340 AFB20018 */  sw        $s2, 0x18($sp)
/* C420F4 80242344 0080902D */  daddu     $s2, $a0, $zero
/* C420F8 80242348 AFBF001C */  sw        $ra, 0x1c($sp)
/* C420FC 8024234C AFB10014 */  sw        $s1, 0x14($sp)
/* C42100 80242350 AFB00010 */  sw        $s0, 0x10($sp)
/* C42104 80242354 8E510148 */  lw        $s1, 0x148($s2)
/* C42108 80242358 0C00EABB */  jal       get_npc_unsafe
/* C4210C 8024235C 86240008 */   lh       $a0, 8($s1)
/* C42110 80242360 0040802D */  daddu     $s0, $v0, $zero
/* C42114 80242364 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C42118 80242368 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C4211C 8024236C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C42120 80242370 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C42124 80242374 A600008E */  sh        $zero, 0x8e($s0)
/* C42128 80242378 8C460028 */  lw        $a2, 0x28($v0)
/* C4212C 8024237C 0C00A720 */  jal       atan2
/* C42130 80242380 8C470030 */   lw       $a3, 0x30($v0)
/* C42134 80242384 E600000C */  swc1      $f0, 0xc($s0)
/* C42138 80242388 8E2200CC */  lw        $v0, 0xcc($s1)
/* C4213C 8024238C 8C420020 */  lw        $v0, 0x20($v0)
/* C42140 80242390 AE020028 */  sw        $v0, 0x28($s0)
/* C42144 80242394 2402000B */  addiu     $v0, $zero, 0xb
/* C42148 80242398 AE420070 */  sw        $v0, 0x70($s2)
/* C4214C 8024239C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C42150 802423A0 8FB20018 */  lw        $s2, 0x18($sp)
/* C42154 802423A4 8FB10014 */  lw        $s1, 0x14($sp)
/* C42158 802423A8 8FB00010 */  lw        $s0, 0x10($sp)
/* C4215C 802423AC 03E00008 */  jr        $ra
/* C42160 802423B0 27BD0020 */   addiu    $sp, $sp, 0x20
