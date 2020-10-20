.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A52BD0
/* A52BD0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A52BD4 80240314 AFB20018 */  sw        $s2, 0x18($sp)
/* A52BD8 80240318 0080902D */  daddu     $s2, $a0, $zero
/* A52BDC 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* A52BE0 80240320 AFB10014 */  sw        $s1, 0x14($sp)
/* A52BE4 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* A52BE8 80240328 8E510148 */  lw        $s1, 0x148($s2)
/* A52BEC 8024032C 0C00EABB */  jal       get_npc_unsafe
/* A52BF0 80240330 86240008 */   lh       $a0, 8($s1)
/* A52BF4 80240334 0040802D */  daddu     $s0, $v0, $zero
/* A52BF8 80240338 8E2300CC */  lw        $v1, 0xcc($s1)
/* A52BFC 8024033C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A52C00 80240340 8C630020 */  lw        $v1, 0x20($v1)
/* A52C04 80240344 AE030028 */  sw        $v1, 0x28($s0)
/* A52C08 80240348 96220076 */  lhu       $v0, 0x76($s1)
/* A52C0C 8024034C A602008E */  sh        $v0, 0x8e($s0)
/* A52C10 80240350 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A52C14 80240354 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A52C18 80240358 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A52C1C 8024035C 8C460028 */  lw        $a2, 0x28($v0)
/* A52C20 80240360 0C00A720 */  jal       atan2
/* A52C24 80240364 8C470030 */   lw       $a3, 0x30($v0)
/* A52C28 80240368 2402000D */  addiu     $v0, $zero, 0xd
/* A52C2C 8024036C E600000C */  swc1      $f0, 0xc($s0)
/* A52C30 80240370 AE420070 */  sw        $v0, 0x70($s2)
/* A52C34 80240374 8FBF001C */  lw        $ra, 0x1c($sp)
/* A52C38 80240378 8FB20018 */  lw        $s2, 0x18($sp)
/* A52C3C 8024037C 8FB10014 */  lw        $s1, 0x14($sp)
/* A52C40 80240380 8FB00010 */  lw        $s0, 0x10($sp)
/* A52C44 80240384 03E00008 */  jr        $ra
/* A52C48 80240388 27BD0020 */   addiu    $sp, $sp, 0x20
