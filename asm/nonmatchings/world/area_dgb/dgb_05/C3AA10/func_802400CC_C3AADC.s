.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400CC_C3AADC
/* C3AADC 802400CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3AAE0 802400D0 AFB10014 */  sw        $s1, 0x14($sp)
/* C3AAE4 802400D4 0080882D */  daddu     $s1, $a0, $zero
/* C3AAE8 802400D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3AAEC 802400DC AFB00010 */  sw        $s0, 0x10($sp)
/* C3AAF0 802400E0 8E300148 */  lw        $s0, 0x148($s1)
/* C3AAF4 802400E4 0C00EABB */  jal       get_npc_unsafe
/* C3AAF8 802400E8 86040008 */   lh       $a0, 8($s0)
/* C3AAFC 802400EC 0040202D */  daddu     $a0, $v0, $zero
/* C3AB00 802400F0 9482008E */  lhu       $v0, 0x8e($a0)
/* C3AB04 802400F4 2442FFFF */  addiu     $v0, $v0, -1
/* C3AB08 802400F8 A482008E */  sh        $v0, 0x8e($a0)
/* C3AB0C 802400FC 00021400 */  sll       $v0, $v0, 0x10
/* C3AB10 80240100 1C400009 */  bgtz      $v0, .L80240128
/* C3AB14 80240104 24020003 */   addiu    $v0, $zero, 3
/* C3AB18 80240108 96030076 */  lhu       $v1, 0x76($s0)
/* C3AB1C 8024010C AE02006C */  sw        $v0, 0x6c($s0)
/* C3AB20 80240110 A483008E */  sh        $v1, 0x8e($a0)
/* C3AB24 80240114 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3AB28 80240118 8C420024 */  lw        $v0, 0x24($v0)
/* C3AB2C 8024011C AC820028 */  sw        $v0, 0x28($a0)
/* C3AB30 80240120 24020020 */  addiu     $v0, $zero, 0x20
/* C3AB34 80240124 AE220070 */  sw        $v0, 0x70($s1)
.L80240128:
/* C3AB38 80240128 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3AB3C 8024012C 8FB10014 */  lw        $s1, 0x14($sp)
/* C3AB40 80240130 8FB00010 */  lw        $s0, 0x10($sp)
/* C3AB44 80240134 03E00008 */  jr        $ra
/* C3AB48 80240138 27BD0020 */   addiu    $sp, $sp, 0x20
