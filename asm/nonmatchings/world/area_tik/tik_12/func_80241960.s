.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241960
/* 88A530 80241960 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88A534 80241964 AFB20018 */  sw        $s2, 0x18($sp)
/* 88A538 80241968 0080902D */  daddu     $s2, $a0, $zero
/* 88A53C 8024196C AFBF001C */  sw        $ra, 0x1c($sp)
/* 88A540 80241970 AFB10014 */  sw        $s1, 0x14($sp)
/* 88A544 80241974 AFB00010 */  sw        $s0, 0x10($sp)
/* 88A548 80241978 8E510148 */  lw        $s1, 0x148($s2)
/* 88A54C 8024197C 0C00EABB */  jal       get_npc_unsafe
/* 88A550 80241980 86240008 */   lh       $a0, 8($s1)
/* 88A554 80241984 0040802D */  daddu     $s0, $v0, $zero
/* 88A558 80241988 8E2300CC */  lw        $v1, 0xcc($s1)
/* 88A55C 8024198C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 88A560 80241990 8C630020 */  lw        $v1, 0x20($v1)
/* 88A564 80241994 AE030028 */  sw        $v1, 0x28($s0)
/* 88A568 80241998 96220076 */  lhu       $v0, 0x76($s1)
/* 88A56C 8024199C A602008E */  sh        $v0, 0x8e($s0)
/* 88A570 802419A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 88A574 802419A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 88A578 802419A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 88A57C 802419AC 8C460028 */  lw        $a2, 0x28($v0)
/* 88A580 802419B0 0C00A720 */  jal       atan2
/* 88A584 802419B4 8C470030 */   lw       $a3, 0x30($v0)
/* 88A588 802419B8 2402000D */  addiu     $v0, $zero, 0xd
/* 88A58C 802419BC E600000C */  swc1      $f0, 0xc($s0)
/* 88A590 802419C0 AE420070 */  sw        $v0, 0x70($s2)
/* 88A594 802419C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 88A598 802419C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 88A59C 802419CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 88A5A0 802419D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 88A5A4 802419D4 03E00008 */  jr        $ra
/* 88A5A8 802419D8 27BD0020 */   addiu    $sp, $sp, 0x20
