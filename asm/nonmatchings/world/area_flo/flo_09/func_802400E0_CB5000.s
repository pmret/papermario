.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_CB50E0
/* CB50E0 802400E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CB50E4 802400E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CB50E8 802400E8 4485A000 */  mtc1      $a1, $f20
/* CB50EC 802400EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* CB50F0 802400F0 4486B000 */  mtc1      $a2, $f22
/* CB50F4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* CB50F8 802400F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CB50FC 802400FC 4487C000 */  mtc1      $a3, $f24
/* CB5100 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB5104 80240104 0C019D28 */  jal       guMtxIdentF
/* CB5108 80240108 0080802D */   daddu    $s0, $a0, $zero
/* CB510C 8024010C 4616A582 */  mul.s     $f22, $f20, $f22
/* CB5110 80240110 00000000 */  nop       
/* CB5114 80240114 4618A502 */  mul.s     $f20, $f20, $f24
/* CB5118 80240118 00000000 */  nop       
/* CB511C 8024011C 3C013F80 */  lui       $at, 0x3f80
/* CB5120 80240120 44810000 */  mtc1      $at, $f0
/* CB5124 80240124 00000000 */  nop       
/* CB5128 80240128 E6000014 */  swc1      $f0, 0x14($s0)
/* CB512C 8024012C E6160010 */  swc1      $f22, 0x10($s0)
/* CB5130 80240130 E6140018 */  swc1      $f20, 0x18($s0)
/* CB5134 80240134 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB5138 80240138 8FB00010 */  lw        $s0, 0x10($sp)
/* CB513C 8024013C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CB5140 80240140 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CB5144 80240144 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CB5148 80240148 03E00008 */  jr        $ra
/* CB514C 8024014C 27BD0030 */   addiu    $sp, $sp, 0x30
