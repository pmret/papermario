.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C0_B7D9E0
/* B7D9E0 802400C0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B7D9E4 802400C4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B7D9E8 802400C8 4485A000 */  mtc1      $a1, $f20
/* B7D9EC 802400CC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B7D9F0 802400D0 4486B000 */  mtc1      $a2, $f22
/* B7D9F4 802400D4 AFB00010 */  sw        $s0, 0x10($sp)
/* B7D9F8 802400D8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B7D9FC 802400DC 4487C000 */  mtc1      $a3, $f24
/* B7DA00 802400E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B7DA04 802400E4 0C019D28 */  jal       guMtxIdentF
/* B7DA08 802400E8 0080802D */   daddu    $s0, $a0, $zero
/* B7DA0C 802400EC 4616A582 */  mul.s     $f22, $f20, $f22
/* B7DA10 802400F0 00000000 */  nop       
/* B7DA14 802400F4 4618A502 */  mul.s     $f20, $f20, $f24
/* B7DA18 802400F8 00000000 */  nop       
/* B7DA1C 802400FC 3C013F80 */  lui       $at, 0x3f80
/* B7DA20 80240100 44810000 */  mtc1      $at, $f0
/* B7DA24 80240104 00000000 */  nop       
/* B7DA28 80240108 E6000014 */  swc1      $f0, 0x14($s0)
/* B7DA2C 8024010C E6160010 */  swc1      $f22, 0x10($s0)
/* B7DA30 80240110 E6140018 */  swc1      $f20, 0x18($s0)
/* B7DA34 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7DA38 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* B7DA3C 8024011C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B7DA40 80240120 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B7DA44 80240124 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B7DA48 80240128 03E00008 */  jr        $ra
/* B7DA4C 8024012C 27BD0030 */   addiu    $sp, $sp, 0x30
