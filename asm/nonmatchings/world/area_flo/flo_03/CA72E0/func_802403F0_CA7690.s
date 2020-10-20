.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_CA7690
/* CA7690 802403F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CA7694 802403F4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CA7698 802403F8 4485A000 */  mtc1      $a1, $f20
/* CA769C 802403FC F7B60020 */  sdc1      $f22, 0x20($sp)
/* CA76A0 80240400 4486B000 */  mtc1      $a2, $f22
/* CA76A4 80240404 AFB00010 */  sw        $s0, 0x10($sp)
/* CA76A8 80240408 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CA76AC 8024040C 4487C000 */  mtc1      $a3, $f24
/* CA76B0 80240410 AFBF0014 */  sw        $ra, 0x14($sp)
/* CA76B4 80240414 0C019D28 */  jal       guMtxIdentF
/* CA76B8 80240418 0080802D */   daddu    $s0, $a0, $zero
/* CA76BC 8024041C 4616A582 */  mul.s     $f22, $f20, $f22
/* CA76C0 80240420 00000000 */  nop       
/* CA76C4 80240424 4618A502 */  mul.s     $f20, $f20, $f24
/* CA76C8 80240428 00000000 */  nop       
/* CA76CC 8024042C 3C013F80 */  lui       $at, 0x3f80
/* CA76D0 80240430 44810000 */  mtc1      $at, $f0
/* CA76D4 80240434 00000000 */  nop       
/* CA76D8 80240438 E6000014 */  swc1      $f0, 0x14($s0)
/* CA76DC 8024043C E6160010 */  swc1      $f22, 0x10($s0)
/* CA76E0 80240440 E6140018 */  swc1      $f20, 0x18($s0)
/* CA76E4 80240444 8FBF0014 */  lw        $ra, 0x14($sp)
/* CA76E8 80240448 8FB00010 */  lw        $s0, 0x10($sp)
/* CA76EC 8024044C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CA76F0 80240450 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CA76F4 80240454 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CA76F8 80240458 03E00008 */  jr        $ra
/* CA76FC 8024045C 27BD0030 */   addiu    $sp, $sp, 0x30
