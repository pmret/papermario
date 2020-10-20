.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_D1117C
/* D1117C 802400BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D11180 802400C0 AFB10014 */  sw        $s1, 0x14($sp)
/* D11184 802400C4 0080882D */  daddu     $s1, $a0, $zero
/* D11188 802400C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* D1118C 802400CC AFB00010 */  sw        $s0, 0x10($sp)
/* D11190 802400D0 8E300148 */  lw        $s0, 0x148($s1)
/* D11194 802400D4 0C00EABB */  jal       get_npc_unsafe
/* D11198 802400D8 86040008 */   lh       $a0, 8($s0)
/* D1119C 802400DC 0040202D */  daddu     $a0, $v0, $zero
/* D111A0 802400E0 9482008E */  lhu       $v0, 0x8e($a0)
/* D111A4 802400E4 2442FFFF */  addiu     $v0, $v0, -1
/* D111A8 802400E8 A482008E */  sh        $v0, 0x8e($a0)
/* D111AC 802400EC 00021400 */  sll       $v0, $v0, 0x10
/* D111B0 802400F0 1C400009 */  bgtz      $v0, .L80240118
/* D111B4 802400F4 24020003 */   addiu    $v0, $zero, 3
/* D111B8 802400F8 96030076 */  lhu       $v1, 0x76($s0)
/* D111BC 802400FC AE02006C */  sw        $v0, 0x6c($s0)
/* D111C0 80240100 A483008E */  sh        $v1, 0x8e($a0)
/* D111C4 80240104 8E0200CC */  lw        $v0, 0xcc($s0)
/* D111C8 80240108 8C420024 */  lw        $v0, 0x24($v0)
/* D111CC 8024010C AC820028 */  sw        $v0, 0x28($a0)
/* D111D0 80240110 24020020 */  addiu     $v0, $zero, 0x20
/* D111D4 80240114 AE220070 */  sw        $v0, 0x70($s1)
.L80240118:
/* D111D8 80240118 8FBF0018 */  lw        $ra, 0x18($sp)
/* D111DC 8024011C 8FB10014 */  lw        $s1, 0x14($sp)
/* D111E0 80240120 8FB00010 */  lw        $s0, 0x10($sp)
/* D111E4 80240124 03E00008 */  jr        $ra
/* D111E8 80240128 27BD0020 */   addiu    $sp, $sp, 0x20
