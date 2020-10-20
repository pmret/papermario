.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A6E6F0
/* A6E6F0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6E6F4 80240314 AFB20018 */  sw        $s2, 0x18($sp)
/* A6E6F8 80240318 0080902D */  daddu     $s2, $a0, $zero
/* A6E6FC 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* A6E700 80240320 AFB10014 */  sw        $s1, 0x14($sp)
/* A6E704 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* A6E708 80240328 8E510148 */  lw        $s1, 0x148($s2)
/* A6E70C 8024032C 0C00EABB */  jal       get_npc_unsafe
/* A6E710 80240330 86240008 */   lh       $a0, 8($s1)
/* A6E714 80240334 0040802D */  daddu     $s0, $v0, $zero
/* A6E718 80240338 8E2300CC */  lw        $v1, 0xcc($s1)
/* A6E71C 8024033C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A6E720 80240340 8C630020 */  lw        $v1, 0x20($v1)
/* A6E724 80240344 AE030028 */  sw        $v1, 0x28($s0)
/* A6E728 80240348 96220076 */  lhu       $v0, 0x76($s1)
/* A6E72C 8024034C A602008E */  sh        $v0, 0x8e($s0)
/* A6E730 80240350 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A6E734 80240354 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A6E738 80240358 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A6E73C 8024035C 8C460028 */  lw        $a2, 0x28($v0)
/* A6E740 80240360 0C00A720 */  jal       atan2
/* A6E744 80240364 8C470030 */   lw       $a3, 0x30($v0)
/* A6E748 80240368 2402000D */  addiu     $v0, $zero, 0xd
/* A6E74C 8024036C E600000C */  swc1      $f0, 0xc($s0)
/* A6E750 80240370 AE420070 */  sw        $v0, 0x70($s2)
/* A6E754 80240374 8FBF001C */  lw        $ra, 0x1c($sp)
/* A6E758 80240378 8FB20018 */  lw        $s2, 0x18($sp)
/* A6E75C 8024037C 8FB10014 */  lw        $s1, 0x14($sp)
/* A6E760 80240380 8FB00010 */  lw        $s0, 0x10($sp)
/* A6E764 80240384 03E00008 */  jr        $ra
/* A6E768 80240388 27BD0020 */   addiu    $sp, $sp, 0x20
