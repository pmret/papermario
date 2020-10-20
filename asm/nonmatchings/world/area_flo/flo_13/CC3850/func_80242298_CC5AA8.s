.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242298_CC5AA8
/* CC5AA8 80242298 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC5AAC 8024229C AFB20018 */  sw        $s2, 0x18($sp)
/* CC5AB0 802422A0 0080902D */  daddu     $s2, $a0, $zero
/* CC5AB4 802422A4 AFBF001C */  sw        $ra, 0x1c($sp)
/* CC5AB8 802422A8 AFB10014 */  sw        $s1, 0x14($sp)
/* CC5ABC 802422AC AFB00010 */  sw        $s0, 0x10($sp)
/* CC5AC0 802422B0 8E510148 */  lw        $s1, 0x148($s2)
/* CC5AC4 802422B4 0C00EABB */  jal       get_npc_unsafe
/* CC5AC8 802422B8 86240008 */   lh       $a0, 8($s1)
/* CC5ACC 802422BC 0040802D */  daddu     $s0, $v0, $zero
/* CC5AD0 802422C0 8E2300CC */  lw        $v1, 0xcc($s1)
/* CC5AD4 802422C4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CC5AD8 802422C8 8C630020 */  lw        $v1, 0x20($v1)
/* CC5ADC 802422CC AE030028 */  sw        $v1, 0x28($s0)
/* CC5AE0 802422D0 96220076 */  lhu       $v0, 0x76($s1)
/* CC5AE4 802422D4 A602008E */  sh        $v0, 0x8e($s0)
/* CC5AE8 802422D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC5AEC 802422DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC5AF0 802422E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CC5AF4 802422E4 8C460028 */  lw        $a2, 0x28($v0)
/* CC5AF8 802422E8 0C00A720 */  jal       atan2
/* CC5AFC 802422EC 8C470030 */   lw       $a3, 0x30($v0)
/* CC5B00 802422F0 2402000D */  addiu     $v0, $zero, 0xd
/* CC5B04 802422F4 E600000C */  swc1      $f0, 0xc($s0)
/* CC5B08 802422F8 AE420070 */  sw        $v0, 0x70($s2)
/* CC5B0C 802422FC 8FBF001C */  lw        $ra, 0x1c($sp)
/* CC5B10 80242300 8FB20018 */  lw        $s2, 0x18($sp)
/* CC5B14 80242304 8FB10014 */  lw        $s1, 0x14($sp)
/* CC5B18 80242308 8FB00010 */  lw        $s0, 0x10($sp)
/* CC5B1C 8024230C 03E00008 */  jr        $ra
/* CC5B20 80242310 27BD0020 */   addiu    $sp, $sp, 0x20
