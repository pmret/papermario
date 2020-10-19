.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_9B6C90
/* 9B6C90 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9B6C94 80240314 AFB20018 */  sw        $s2, 0x18($sp)
/* 9B6C98 80240318 0080902D */  daddu     $s2, $a0, $zero
/* 9B6C9C 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9B6CA0 80240320 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B6CA4 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B6CA8 80240328 8E510148 */  lw        $s1, 0x148($s2)
/* 9B6CAC 8024032C 0C00EABB */  jal       get_npc_unsafe
/* 9B6CB0 80240330 86240008 */   lh       $a0, 8($s1)
/* 9B6CB4 80240334 0040802D */  daddu     $s0, $v0, $zero
/* 9B6CB8 80240338 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9B6CBC 8024033C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B6CC0 80240340 8C630020 */  lw        $v1, 0x20($v1)
/* 9B6CC4 80240344 AE030028 */  sw        $v1, 0x28($s0)
/* 9B6CC8 80240348 96220076 */  lhu       $v0, 0x76($s1)
/* 9B6CCC 8024034C A602008E */  sh        $v0, 0x8e($s0)
/* 9B6CD0 80240350 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9B6CD4 80240354 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9B6CD8 80240358 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B6CDC 8024035C 8C460028 */  lw        $a2, 0x28($v0)
/* 9B6CE0 80240360 0C00A720 */  jal       atan2
/* 9B6CE4 80240364 8C470030 */   lw       $a3, 0x30($v0)
/* 9B6CE8 80240368 2402000D */  addiu     $v0, $zero, 0xd
/* 9B6CEC 8024036C E600000C */  swc1      $f0, 0xc($s0)
/* 9B6CF0 80240370 AE420070 */  sw        $v0, 0x70($s2)
/* 9B6CF4 80240374 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9B6CF8 80240378 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B6CFC 8024037C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B6D00 80240380 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B6D04 80240384 03E00008 */  jr        $ra
/* 9B6D08 80240388 27BD0020 */   addiu    $sp, $sp, 0x20
