.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240780_A4D1A0
/* A4D1A0 80240780 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4D1A4 80240784 AFB10014 */  sw        $s1, 0x14($sp)
/* A4D1A8 80240788 0080882D */  daddu     $s1, $a0, $zero
/* A4D1AC 8024078C AFBF0018 */  sw        $ra, 0x18($sp)
/* A4D1B0 80240790 AFB00010 */  sw        $s0, 0x10($sp)
/* A4D1B4 80240794 8E300148 */  lw        $s0, 0x148($s1)
/* A4D1B8 80240798 0C00EABB */  jal       get_npc_unsafe
/* A4D1BC 8024079C 86040008 */   lh       $a0, 8($s0)
/* A4D1C0 802407A0 0040282D */  daddu     $a1, $v0, $zero
/* A4D1C4 802407A4 94A2008E */  lhu       $v0, 0x8e($a1)
/* A4D1C8 802407A8 2442FFFF */  addiu     $v0, $v0, -1
/* A4D1CC 802407AC A4A2008E */  sh        $v0, 0x8e($a1)
/* A4D1D0 802407B0 00021400 */  sll       $v0, $v0, 0x10
/* A4D1D4 802407B4 1C40000A */  bgtz      $v0, .L802407E0
/* A4D1D8 802407B8 2404FFFD */   addiu    $a0, $zero, -3
/* A4D1DC 802407BC 8E0300CC */  lw        $v1, 0xcc($s0)
/* A4D1E0 802407C0 8CA20000 */  lw        $v0, ($a1)
/* A4D1E4 802407C4 8C630000 */  lw        $v1, ($v1)
/* A4D1E8 802407C8 00441024 */  and       $v0, $v0, $a0
/* A4D1EC 802407CC ACA20000 */  sw        $v0, ($a1)
/* A4D1F0 802407D0 24020001 */  addiu     $v0, $zero, 1
/* A4D1F4 802407D4 A4A0008E */  sh        $zero, 0x8e($a1)
/* A4D1F8 802407D8 ACA30028 */  sw        $v1, 0x28($a1)
/* A4D1FC 802407DC AE220070 */  sw        $v0, 0x70($s1)
.L802407E0:
/* A4D200 802407E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4D204 802407E4 8FB10014 */  lw        $s1, 0x14($sp)
/* A4D208 802407E8 8FB00010 */  lw        $s0, 0x10($sp)
/* A4D20C 802407EC 03E00008 */  jr        $ra
/* A4D210 802407F0 27BD0020 */   addiu    $sp, $sp, 0x20
