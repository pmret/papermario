.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_B5A850
/* B5A850 80240FE0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5A854 80240FE4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B5A858 80240FE8 4485A000 */  mtc1      $a1, $f20
/* B5A85C 80240FEC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B5A860 80240FF0 4486B000 */  mtc1      $a2, $f22
/* B5A864 80240FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* B5A868 80240FF8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B5A86C 80240FFC 4487C000 */  mtc1      $a3, $f24
/* B5A870 80241000 AFBF0014 */  sw        $ra, 0x14($sp)
/* B5A874 80241004 0C019D28 */  jal       guMtxIdentF
/* B5A878 80241008 0080802D */   daddu    $s0, $a0, $zero
/* B5A87C 8024100C 4616A582 */  mul.s     $f22, $f20, $f22
/* B5A880 80241010 00000000 */  nop       
/* B5A884 80241014 4618A502 */  mul.s     $f20, $f20, $f24
/* B5A888 80241018 00000000 */  nop       
/* B5A88C 8024101C 3C013F80 */  lui       $at, 0x3f80
/* B5A890 80241020 44810000 */  mtc1      $at, $f0
/* B5A894 80241024 00000000 */  nop       
/* B5A898 80241028 E6000014 */  swc1      $f0, 0x14($s0)
/* B5A89C 8024102C E6160010 */  swc1      $f22, 0x10($s0)
/* B5A8A0 80241030 E6140018 */  swc1      $f20, 0x18($s0)
/* B5A8A4 80241034 8FBF0014 */  lw        $ra, 0x14($sp)
/* B5A8A8 80241038 8FB00010 */  lw        $s0, 0x10($sp)
/* B5A8AC 8024103C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B5A8B0 80241040 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B5A8B4 80241044 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B5A8B8 80241048 03E00008 */  jr        $ra
/* B5A8BC 8024104C 27BD0030 */   addiu    $sp, $sp, 0x30
