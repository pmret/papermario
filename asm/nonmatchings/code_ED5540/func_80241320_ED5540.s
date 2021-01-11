.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241320_ED5540
/* ED5540 80241320 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* ED5544 80241324 F7B40018 */  sdc1      $f20, 0x18($sp)
/* ED5548 80241328 4485A000 */  mtc1      $a1, $f20
/* ED554C 8024132C F7B60020 */  sdc1      $f22, 0x20($sp)
/* ED5550 80241330 4486B000 */  mtc1      $a2, $f22
/* ED5554 80241334 AFB00010 */  sw        $s0, 0x10($sp)
/* ED5558 80241338 F7B80028 */  sdc1      $f24, 0x28($sp)
/* ED555C 8024133C 4487C000 */  mtc1      $a3, $f24
/* ED5560 80241340 AFBF0014 */  sw        $ra, 0x14($sp)
/* ED5564 80241344 0C01B198 */  jal       osGetCause
/* ED5568 80241348 0080802D */   daddu    $s0, $a0, $zero
/* ED556C 8024134C 4616A582 */  mul.s     $f22, $f20, $f22
/* ED5570 80241350 00000000 */  nop       
/* ED5574 80241354 4618A502 */  mul.s     $f20, $f20, $f24
/* ED5578 80241358 00000000 */  nop       
/* ED557C 8024135C 3C013F80 */  lui       $at, 0x3f80
/* ED5580 80241360 44810000 */  mtc1      $at, $f0
/* ED5584 80241364 00000000 */  nop       
/* ED5588 80241368 E6000014 */  swc1      $f0, 0x14($s0)
/* ED558C 8024136C E6160010 */  swc1      $f22, 0x10($s0)
/* ED5590 80241370 E6140018 */  swc1      $f20, 0x18($s0)
/* ED5594 80241374 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED5598 80241378 8FB00010 */  lw        $s0, 0x10($sp)
/* ED559C 8024137C D7B80028 */  ldc1      $f24, 0x28($sp)
/* ED55A0 80241380 D7B60020 */  ldc1      $f22, 0x20($sp)
/* ED55A4 80241384 D7B40018 */  ldc1      $f20, 0x18($sp)
/* ED55A8 80241388 03E00008 */  jr        $ra
/* ED55AC 8024138C 27BD0030 */   addiu    $sp, $sp, 0x30
