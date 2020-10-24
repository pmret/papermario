.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240570_9FAD60
/* 9FAD60 80240570 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9FAD64 80240574 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FAD68 80240578 0080902D */  daddu     $s2, $a0, $zero
/* 9FAD6C 8024057C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9FAD70 80240580 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FAD74 80240584 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FAD78 80240588 8E510148 */  lw        $s1, 0x148($s2)
/* 9FAD7C 8024058C 0C00EABB */  jal       get_npc_unsafe
/* 9FAD80 80240590 86240008 */   lh       $a0, 8($s1)
/* 9FAD84 80240594 0040802D */  daddu     $s0, $v0, $zero
/* 9FAD88 80240598 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9FAD8C 8024059C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9FAD90 802405A0 8C630020 */  lw        $v1, 0x20($v1)
/* 9FAD94 802405A4 AE030028 */  sw        $v1, 0x28($s0)
/* 9FAD98 802405A8 96220076 */  lhu       $v0, 0x76($s1)
/* 9FAD9C 802405AC A602008E */  sh        $v0, 0x8e($s0)
/* 9FADA0 802405B0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9FADA4 802405B4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9FADA8 802405B8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9FADAC 802405BC 8C460028 */  lw        $a2, 0x28($v0)
/* 9FADB0 802405C0 0C00A720 */  jal       atan2
/* 9FADB4 802405C4 8C470030 */   lw       $a3, 0x30($v0)
/* 9FADB8 802405C8 2402000D */  addiu     $v0, $zero, 0xd
/* 9FADBC 802405CC E600000C */  swc1      $f0, 0xc($s0)
/* 9FADC0 802405D0 AE420070 */  sw        $v0, 0x70($s2)
/* 9FADC4 802405D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9FADC8 802405D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FADCC 802405DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FADD0 802405E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FADD4 802405E4 03E00008 */  jr        $ra
/* 9FADD8 802405E8 27BD0020 */   addiu    $sp, $sp, 0x20
