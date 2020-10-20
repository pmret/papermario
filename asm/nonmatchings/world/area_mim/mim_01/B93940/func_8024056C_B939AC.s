.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024056C_B939AC
/* B939AC 8024056C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B939B0 80240570 AFB10014 */  sw        $s1, 0x14($sp)
/* B939B4 80240574 0080882D */  daddu     $s1, $a0, $zero
/* B939B8 80240578 AFBF0018 */  sw        $ra, 0x18($sp)
/* B939BC 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* B939C0 80240580 8E300148 */  lw        $s0, 0x148($s1)
/* B939C4 80240584 0C00EABB */  jal       get_npc_unsafe
/* B939C8 80240588 86040008 */   lh       $a0, 8($s0)
/* B939CC 8024058C 0040202D */  daddu     $a0, $v0, $zero
/* B939D0 80240590 9482008E */  lhu       $v0, 0x8e($a0)
/* B939D4 80240594 2442FFFF */  addiu     $v0, $v0, -1
/* B939D8 80240598 A482008E */  sh        $v0, 0x8e($a0)
/* B939DC 8024059C 00021400 */  sll       $v0, $v0, 0x10
/* B939E0 802405A0 1C400009 */  bgtz      $v0, .L802405C8
/* B939E4 802405A4 24020003 */   addiu    $v0, $zero, 3
/* B939E8 802405A8 96030076 */  lhu       $v1, 0x76($s0)
/* B939EC 802405AC AE02006C */  sw        $v0, 0x6c($s0)
/* B939F0 802405B0 A483008E */  sh        $v1, 0x8e($a0)
/* B939F4 802405B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* B939F8 802405B8 8C420024 */  lw        $v0, 0x24($v0)
/* B939FC 802405BC AC820028 */  sw        $v0, 0x28($a0)
/* B93A00 802405C0 24020020 */  addiu     $v0, $zero, 0x20
/* B93A04 802405C4 AE220070 */  sw        $v0, 0x70($s1)
.L802405C8:
/* B93A08 802405C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* B93A0C 802405CC 8FB10014 */  lw        $s1, 0x14($sp)
/* B93A10 802405D0 8FB00010 */  lw        $s0, 0x10($sp)
/* B93A14 802405D4 03E00008 */  jr        $ra
/* B93A18 802405D8 27BD0020 */   addiu    $sp, $sp, 0x20
