.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241744_B5F9F4
/* B5F9F4 80241744 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B5F9F8 80241748 AFB10034 */  sw        $s1, 0x34($sp)
/* B5F9FC 8024174C 0080882D */  daddu     $s1, $a0, $zero
/* B5FA00 80241750 AFBF0038 */  sw        $ra, 0x38($sp)
/* B5FA04 80241754 AFB00030 */  sw        $s0, 0x30($sp)
/* B5FA08 80241758 8E300148 */  lw        $s0, 0x148($s1)
/* B5FA0C 8024175C 0C00EABB */  jal       get_npc_unsafe
/* B5FA10 80241760 86040008 */   lh       $a0, 8($s0)
/* B5FA14 80241764 0040282D */  daddu     $a1, $v0, $zero
/* B5FA18 80241768 94A2008E */  lhu       $v0, 0x8e($a1)
/* B5FA1C 8024176C 2442FFFF */  addiu     $v0, $v0, -1
/* B5FA20 80241770 A4A2008E */  sh        $v0, 0x8e($a1)
/* B5FA24 80241774 00021400 */  sll       $v0, $v0, 0x10
/* B5FA28 80241778 1C400023 */  bgtz      $v0, .L80241808
/* B5FA2C 8024177C 24020004 */   addiu    $v0, $zero, 4
/* B5FA30 80241780 8E0300CC */  lw        $v1, 0xcc($s0)
/* B5FA34 80241784 AE02006C */  sw        $v0, 0x6c($s0)
/* B5FA38 80241788 8C620000 */  lw        $v0, ($v1)
/* B5FA3C 8024178C ACA20028 */  sw        $v0, 0x28($a1)
/* B5FA40 80241790 9602007A */  lhu       $v0, 0x7a($s0)
/* B5FA44 80241794 A4A2008E */  sh        $v0, 0x8e($a1)
/* B5FA48 80241798 8E020078 */  lw        $v0, 0x78($s0)
/* B5FA4C 8024179C 28420008 */  slti      $v0, $v0, 8
/* B5FA50 802417A0 14400018 */  bnez      $v0, .L80241804
/* B5FA54 802417A4 24020021 */   addiu    $v0, $zero, 0x21
/* B5FA58 802417A8 24040003 */  addiu     $a0, $zero, 3
/* B5FA5C 802417AC 27A30028 */  addiu     $v1, $sp, 0x28
/* B5FA60 802417B0 84A700A8 */  lh        $a3, 0xa8($a1)
/* B5FA64 802417B4 3C013F80 */  lui       $at, 0x3f80
/* B5FA68 802417B8 44810000 */  mtc1      $at, $f0
/* B5FA6C 802417BC 3C014000 */  lui       $at, 0x4000
/* B5FA70 802417C0 44811000 */  mtc1      $at, $f2
/* B5FA74 802417C4 3C01C1A0 */  lui       $at, 0xc1a0
/* B5FA78 802417C8 44812000 */  mtc1      $at, $f4
/* B5FA7C 802417CC 44873000 */  mtc1      $a3, $f6
/* B5FA80 802417D0 00000000 */  nop       
/* B5FA84 802417D4 468031A0 */  cvt.s.w   $f6, $f6
/* B5FA88 802417D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B5FA8C 802417DC E7A20014 */  swc1      $f2, 0x14($sp)
/* B5FA90 802417E0 E7A40018 */  swc1      $f4, 0x18($sp)
/* B5FA94 802417E4 8E020078 */  lw        $v0, 0x78($s0)
/* B5FA98 802417E8 44073000 */  mfc1      $a3, $f6
/* B5FA9C 802417EC 0000302D */  daddu     $a2, $zero, $zero
/* B5FAA0 802417F0 AFA30020 */  sw        $v1, 0x20($sp)
/* B5FAA4 802417F4 2442FFFF */  addiu     $v0, $v0, -1
/* B5FAA8 802417F8 0C01BFA4 */  jal       fx_emote
/* B5FAAC 802417FC AFA2001C */   sw       $v0, 0x1c($sp)
/* B5FAB0 80241800 24020021 */  addiu     $v0, $zero, 0x21
.L80241804:
/* B5FAB4 80241804 AE220070 */  sw        $v0, 0x70($s1)
.L80241808:
/* B5FAB8 80241808 8FBF0038 */  lw        $ra, 0x38($sp)
/* B5FABC 8024180C 8FB10034 */  lw        $s1, 0x34($sp)
/* B5FAC0 80241810 8FB00030 */  lw        $s0, 0x30($sp)
/* B5FAC4 80241814 03E00008 */  jr        $ra
/* B5FAC8 80241818 27BD0040 */   addiu    $sp, $sp, 0x40
