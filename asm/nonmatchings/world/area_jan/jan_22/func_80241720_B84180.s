.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241720_B858A0
/* B858A0 80241720 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B858A4 80241724 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B858A8 80241728 4485A000 */  mtc1      $a1, $f20
/* B858AC 8024172C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B858B0 80241730 4486B000 */  mtc1      $a2, $f22
/* B858B4 80241734 AFB00010 */  sw        $s0, 0x10($sp)
/* B858B8 80241738 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B858BC 8024173C 4487C000 */  mtc1      $a3, $f24
/* B858C0 80241740 AFBF0014 */  sw        $ra, 0x14($sp)
/* B858C4 80241744 0C019D28 */  jal       guMtxIdentF
/* B858C8 80241748 0080802D */   daddu    $s0, $a0, $zero
/* B858CC 8024174C 4616A582 */  mul.s     $f22, $f20, $f22
/* B858D0 80241750 00000000 */  nop       
/* B858D4 80241754 4618A502 */  mul.s     $f20, $f20, $f24
/* B858D8 80241758 00000000 */  nop       
/* B858DC 8024175C 3C013F80 */  lui       $at, 0x3f80
/* B858E0 80241760 44810000 */  mtc1      $at, $f0
/* B858E4 80241764 00000000 */  nop       
/* B858E8 80241768 E6000014 */  swc1      $f0, 0x14($s0)
/* B858EC 8024176C E6160010 */  swc1      $f22, 0x10($s0)
/* B858F0 80241770 E6140018 */  swc1      $f20, 0x18($s0)
/* B858F4 80241774 8FBF0014 */  lw        $ra, 0x14($sp)
/* B858F8 80241778 8FB00010 */  lw        $s0, 0x10($sp)
/* B858FC 8024177C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B85900 80241780 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B85904 80241784 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B85908 80241788 03E00008 */  jr        $ra
/* B8590C 8024178C 27BD0030 */   addiu    $sp, $sp, 0x30
