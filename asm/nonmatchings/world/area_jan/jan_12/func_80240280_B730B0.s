.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_B73330
/* B73330 80240280 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B73334 80240284 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B73338 80240288 4485A000 */  mtc1      $a1, $f20
/* B7333C 8024028C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B73340 80240290 4486B000 */  mtc1      $a2, $f22
/* B73344 80240294 AFB00010 */  sw        $s0, 0x10($sp)
/* B73348 80240298 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B7334C 8024029C 4487C000 */  mtc1      $a3, $f24
/* B73350 802402A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B73354 802402A4 0C019D28 */  jal       guMtxIdentF
/* B73358 802402A8 0080802D */   daddu    $s0, $a0, $zero
/* B7335C 802402AC 4616A582 */  mul.s     $f22, $f20, $f22
/* B73360 802402B0 00000000 */  nop       
/* B73364 802402B4 4618A502 */  mul.s     $f20, $f20, $f24
/* B73368 802402B8 00000000 */  nop       
/* B7336C 802402BC 3C013F80 */  lui       $at, 0x3f80
/* B73370 802402C0 44810000 */  mtc1      $at, $f0
/* B73374 802402C4 00000000 */  nop       
/* B73378 802402C8 E6000014 */  swc1      $f0, 0x14($s0)
/* B7337C 802402CC E6160010 */  swc1      $f22, 0x10($s0)
/* B73380 802402D0 E6140018 */  swc1      $f20, 0x18($s0)
/* B73384 802402D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B73388 802402D8 8FB00010 */  lw        $s0, 0x10($sp)
/* B7338C 802402DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B73390 802402E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B73394 802402E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B73398 802402E8 03E00008 */  jr        $ra
/* B7339C 802402EC 27BD0030 */   addiu    $sp, $sp, 0x30
