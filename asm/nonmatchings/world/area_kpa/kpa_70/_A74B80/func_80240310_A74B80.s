.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A74B80
/* A74B80 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A74B84 80240314 AFB20018 */  sw        $s2, 0x18($sp)
/* A74B88 80240318 0080902D */  daddu     $s2, $a0, $zero
/* A74B8C 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* A74B90 80240320 AFB10014 */  sw        $s1, 0x14($sp)
/* A74B94 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* A74B98 80240328 8E510148 */  lw        $s1, 0x148($s2)
/* A74B9C 8024032C 0C00EABB */  jal       get_npc_unsafe
/* A74BA0 80240330 86240008 */   lh       $a0, 8($s1)
/* A74BA4 80240334 0040802D */  daddu     $s0, $v0, $zero
/* A74BA8 80240338 8E2300CC */  lw        $v1, 0xcc($s1)
/* A74BAC 8024033C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A74BB0 80240340 8C630020 */  lw        $v1, 0x20($v1)
/* A74BB4 80240344 AE030028 */  sw        $v1, 0x28($s0)
/* A74BB8 80240348 96220076 */  lhu       $v0, 0x76($s1)
/* A74BBC 8024034C A602008E */  sh        $v0, 0x8e($s0)
/* A74BC0 80240350 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A74BC4 80240354 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A74BC8 80240358 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A74BCC 8024035C 8C460028 */  lw        $a2, 0x28($v0)
/* A74BD0 80240360 0C00A720 */  jal       atan2
/* A74BD4 80240364 8C470030 */   lw       $a3, 0x30($v0)
/* A74BD8 80240368 2402000D */  addiu     $v0, $zero, 0xd
/* A74BDC 8024036C E600000C */  swc1      $f0, 0xc($s0)
/* A74BE0 80240370 AE420070 */  sw        $v0, 0x70($s2)
/* A74BE4 80240374 8FBF001C */  lw        $ra, 0x1c($sp)
/* A74BE8 80240378 8FB20018 */  lw        $s2, 0x18($sp)
/* A74BEC 8024037C 8FB10014 */  lw        $s1, 0x14($sp)
/* A74BF0 80240380 8FB00010 */  lw        $s0, 0x10($sp)
/* A74BF4 80240384 03E00008 */  jr        $ra
/* A74BF8 80240388 27BD0020 */   addiu    $sp, $sp, 0x20
