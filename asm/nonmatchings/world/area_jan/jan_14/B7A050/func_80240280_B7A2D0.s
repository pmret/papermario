.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_B7A2D0
/* B7A2D0 80240280 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B7A2D4 80240284 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B7A2D8 80240288 4485A000 */  mtc1      $a1, $f20
/* B7A2DC 8024028C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B7A2E0 80240290 4486B000 */  mtc1      $a2, $f22
/* B7A2E4 80240294 AFB00010 */  sw        $s0, 0x10($sp)
/* B7A2E8 80240298 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B7A2EC 8024029C 4487C000 */  mtc1      $a3, $f24
/* B7A2F0 802402A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B7A2F4 802402A4 0C019D28 */  jal       guMtxIdentF
/* B7A2F8 802402A8 0080802D */   daddu    $s0, $a0, $zero
/* B7A2FC 802402AC 4616A582 */  mul.s     $f22, $f20, $f22
/* B7A300 802402B0 00000000 */  nop       
/* B7A304 802402B4 4618A502 */  mul.s     $f20, $f20, $f24
/* B7A308 802402B8 00000000 */  nop       
/* B7A30C 802402BC 3C013F80 */  lui       $at, 0x3f80
/* B7A310 802402C0 44810000 */  mtc1      $at, $f0
/* B7A314 802402C4 00000000 */  nop       
/* B7A318 802402C8 E6000014 */  swc1      $f0, 0x14($s0)
/* B7A31C 802402CC E6160010 */  swc1      $f22, 0x10($s0)
/* B7A320 802402D0 E6140018 */  swc1      $f20, 0x18($s0)
/* B7A324 802402D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7A328 802402D8 8FB00010 */  lw        $s0, 0x10($sp)
/* B7A32C 802402DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B7A330 802402E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B7A334 802402E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B7A338 802402E8 03E00008 */  jr        $ra
/* B7A33C 802402EC 27BD0030 */   addiu    $sp, $sp, 0x30
