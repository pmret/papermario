.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416E0_B67190
/* B67190 802416E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B67194 802416E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B67198 802416E8 4485A000 */  mtc1      $a1, $f20
/* B6719C 802416EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B671A0 802416F0 4486B000 */  mtc1      $a2, $f22
/* B671A4 802416F4 AFB00010 */  sw        $s0, 0x10($sp)
/* B671A8 802416F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B671AC 802416FC 4487C000 */  mtc1      $a3, $f24
/* B671B0 80241700 AFBF0014 */  sw        $ra, 0x14($sp)
/* B671B4 80241704 0C019D28 */  jal       guMtxIdentF
/* B671B8 80241708 0080802D */   daddu    $s0, $a0, $zero
/* B671BC 8024170C 4616A582 */  mul.s     $f22, $f20, $f22
/* B671C0 80241710 00000000 */  nop       
/* B671C4 80241714 4618A502 */  mul.s     $f20, $f20, $f24
/* B671C8 80241718 00000000 */  nop       
/* B671CC 8024171C 3C013F80 */  lui       $at, 0x3f80
/* B671D0 80241720 44810000 */  mtc1      $at, $f0
/* B671D4 80241724 00000000 */  nop       
/* B671D8 80241728 E6000014 */  swc1      $f0, 0x14($s0)
/* B671DC 8024172C E6160010 */  swc1      $f22, 0x10($s0)
/* B671E0 80241730 E6140018 */  swc1      $f20, 0x18($s0)
/* B671E4 80241734 8FBF0014 */  lw        $ra, 0x14($sp)
/* B671E8 80241738 8FB00010 */  lw        $s0, 0x10($sp)
/* B671EC 8024173C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B671F0 80241740 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B671F4 80241744 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B671F8 80241748 03E00008 */  jr        $ra
/* B671FC 8024174C 27BD0030 */   addiu    $sp, $sp, 0x30
