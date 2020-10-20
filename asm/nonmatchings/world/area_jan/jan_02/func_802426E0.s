.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426E0
/* B2EB50 802426E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B2EB54 802426E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B2EB58 802426E8 4485A000 */  mtc1      $a1, $f20
/* B2EB5C 802426EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B2EB60 802426F0 4486B000 */  mtc1      $a2, $f22
/* B2EB64 802426F4 AFB00010 */  sw        $s0, 0x10($sp)
/* B2EB68 802426F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B2EB6C 802426FC 4487C000 */  mtc1      $a3, $f24
/* B2EB70 80242700 AFBF0014 */  sw        $ra, 0x14($sp)
/* B2EB74 80242704 0C019D28 */  jal       guMtxIdentF
/* B2EB78 80242708 0080802D */   daddu    $s0, $a0, $zero
/* B2EB7C 8024270C 4616A582 */  mul.s     $f22, $f20, $f22
/* B2EB80 80242710 00000000 */  nop       
/* B2EB84 80242714 4618A502 */  mul.s     $f20, $f20, $f24
/* B2EB88 80242718 00000000 */  nop       
/* B2EB8C 8024271C 3C013F80 */  lui       $at, 0x3f80
/* B2EB90 80242720 44810000 */  mtc1      $at, $f0
/* B2EB94 80242724 00000000 */  nop       
/* B2EB98 80242728 E6000014 */  swc1      $f0, 0x14($s0)
/* B2EB9C 8024272C E6160010 */  swc1      $f22, 0x10($s0)
/* B2EBA0 80242730 E6140018 */  swc1      $f20, 0x18($s0)
/* B2EBA4 80242734 8FBF0014 */  lw        $ra, 0x14($sp)
/* B2EBA8 80242738 8FB00010 */  lw        $s0, 0x10($sp)
/* B2EBAC 8024273C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B2EBB0 80242740 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B2EBB4 80242744 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B2EBB8 80242748 03E00008 */  jr        $ra
/* B2EBBC 8024274C 27BD0030 */   addiu    $sp, $sp, 0x30
