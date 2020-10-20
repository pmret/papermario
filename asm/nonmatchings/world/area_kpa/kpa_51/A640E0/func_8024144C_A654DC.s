.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024144C_A654DC
/* A654DC 8024144C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A654E0 80241450 AFB20018 */  sw        $s2, 0x18($sp)
/* A654E4 80241454 0080902D */  daddu     $s2, $a0, $zero
/* A654E8 80241458 AFBF001C */  sw        $ra, 0x1c($sp)
/* A654EC 8024145C AFB10014 */  sw        $s1, 0x14($sp)
/* A654F0 80241460 AFB00010 */  sw        $s0, 0x10($sp)
/* A654F4 80241464 8E510148 */  lw        $s1, 0x148($s2)
/* A654F8 80241468 0C00EABB */  jal       get_npc_unsafe
/* A654FC 8024146C 86240008 */   lh       $a0, 8($s1)
/* A65500 80241470 0040802D */  daddu     $s0, $v0, $zero
/* A65504 80241474 8E2300CC */  lw        $v1, 0xcc($s1)
/* A65508 80241478 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A6550C 8024147C 8C630020 */  lw        $v1, 0x20($v1)
/* A65510 80241480 AE030028 */  sw        $v1, 0x28($s0)
/* A65514 80241484 96220076 */  lhu       $v0, 0x76($s1)
/* A65518 80241488 A602008E */  sh        $v0, 0x8e($s0)
/* A6551C 8024148C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A65520 80241490 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A65524 80241494 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A65528 80241498 8C460028 */  lw        $a2, 0x28($v0)
/* A6552C 8024149C 0C00A720 */  jal       atan2
/* A65530 802414A0 8C470030 */   lw       $a3, 0x30($v0)
/* A65534 802414A4 2402000D */  addiu     $v0, $zero, 0xd
/* A65538 802414A8 E600000C */  swc1      $f0, 0xc($s0)
/* A6553C 802414AC AE420070 */  sw        $v0, 0x70($s2)
/* A65540 802414B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A65544 802414B4 8FB20018 */  lw        $s2, 0x18($sp)
/* A65548 802414B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A6554C 802414BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A65550 802414C0 03E00008 */  jr        $ra
/* A65554 802414C4 27BD0020 */   addiu    $sp, $sp, 0x20
