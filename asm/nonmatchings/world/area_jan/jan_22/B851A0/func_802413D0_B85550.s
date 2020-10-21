.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D0_B85550
/* B85550 802413D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B85554 802413D4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B85558 802413D8 4485A000 */  mtc1      $a1, $f20
/* B8555C 802413DC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B85560 802413E0 4486B000 */  mtc1      $a2, $f22
/* B85564 802413E4 AFB00010 */  sw        $s0, 0x10($sp)
/* B85568 802413E8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B8556C 802413EC 4487C000 */  mtc1      $a3, $f24
/* B85570 802413F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B85574 802413F4 0C019D28 */  jal       guMtxIdentF
/* B85578 802413F8 0080802D */   daddu    $s0, $a0, $zero
/* B8557C 802413FC 4616A582 */  mul.s     $f22, $f20, $f22
/* B85580 80241400 00000000 */  nop       
/* B85584 80241404 4618A502 */  mul.s     $f20, $f20, $f24
/* B85588 80241408 00000000 */  nop       
/* B8558C 8024140C 3C013F80 */  lui       $at, 0x3f80
/* B85590 80241410 44810000 */  mtc1      $at, $f0
/* B85594 80241414 00000000 */  nop       
/* B85598 80241418 E6000014 */  swc1      $f0, 0x14($s0)
/* B8559C 8024141C E6160010 */  swc1      $f22, 0x10($s0)
/* B855A0 80241420 E6140018 */  swc1      $f20, 0x18($s0)
/* B855A4 80241424 8FBF0014 */  lw        $ra, 0x14($sp)
/* B855A8 80241428 8FB00010 */  lw        $s0, 0x10($sp)
/* B855AC 8024142C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B855B0 80241430 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B855B4 80241434 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B855B8 80241438 03E00008 */  jr        $ra
/* B855BC 8024143C 27BD0030 */   addiu    $sp, $sp, 0x30
