.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240160_A48720
/* A48720 80240160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A48724 80240164 AFB20018 */  sw        $s2, 0x18($sp)
/* A48728 80240168 0080902D */  daddu     $s2, $a0, $zero
/* A4872C 8024016C AFBF001C */  sw        $ra, 0x1c($sp)
/* A48730 80240170 AFB10014 */  sw        $s1, 0x14($sp)
/* A48734 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* A48738 80240178 8E510148 */  lw        $s1, 0x148($s2)
/* A4873C 8024017C 0C00EABB */  jal       get_npc_unsafe
/* A48740 80240180 86240008 */   lh       $a0, 8($s1)
/* A48744 80240184 0040802D */  daddu     $s0, $v0, $zero
/* A48748 80240188 8E2300CC */  lw        $v1, 0xcc($s1)
/* A4874C 8024018C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A48750 80240190 8C630020 */  lw        $v1, 0x20($v1)
/* A48754 80240194 AE030028 */  sw        $v1, 0x28($s0)
/* A48758 80240198 96220076 */  lhu       $v0, 0x76($s1)
/* A4875C 8024019C A602008E */  sh        $v0, 0x8e($s0)
/* A48760 802401A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A48764 802401A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A48768 802401A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A4876C 802401AC 8C460028 */  lw        $a2, 0x28($v0)
/* A48770 802401B0 0C00A720 */  jal       atan2
/* A48774 802401B4 8C470030 */   lw       $a3, 0x30($v0)
/* A48778 802401B8 2402000D */  addiu     $v0, $zero, 0xd
/* A4877C 802401BC E600000C */  swc1      $f0, 0xc($s0)
/* A48780 802401C0 AE420070 */  sw        $v0, 0x70($s2)
/* A48784 802401C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* A48788 802401C8 8FB20018 */  lw        $s2, 0x18($sp)
/* A4878C 802401CC 8FB10014 */  lw        $s1, 0x14($sp)
/* A48790 802401D0 8FB00010 */  lw        $s0, 0x10($sp)
/* A48794 802401D4 03E00008 */  jr        $ra
/* A48798 802401D8 27BD0020 */   addiu    $sp, $sp, 0x20
