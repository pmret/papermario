.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240590_CDCC30
/* CDCC30 80240590 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CDCC34 80240594 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CDCC38 80240598 4485A000 */  mtc1      $a1, $f20
/* CDCC3C 8024059C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CDCC40 802405A0 4486B000 */  mtc1      $a2, $f22
/* CDCC44 802405A4 AFB00010 */  sw        $s0, 0x10($sp)
/* CDCC48 802405A8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CDCC4C 802405AC 4487C000 */  mtc1      $a3, $f24
/* CDCC50 802405B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* CDCC54 802405B4 0C019D28 */  jal       guMtxIdentF
/* CDCC58 802405B8 0080802D */   daddu    $s0, $a0, $zero
/* CDCC5C 802405BC 4616A582 */  mul.s     $f22, $f20, $f22
/* CDCC60 802405C0 00000000 */  nop       
/* CDCC64 802405C4 4618A502 */  mul.s     $f20, $f20, $f24
/* CDCC68 802405C8 00000000 */  nop       
/* CDCC6C 802405CC 3C013F80 */  lui       $at, 0x3f80
/* CDCC70 802405D0 44810000 */  mtc1      $at, $f0
/* CDCC74 802405D4 00000000 */  nop       
/* CDCC78 802405D8 E6000014 */  swc1      $f0, 0x14($s0)
/* CDCC7C 802405DC E6160010 */  swc1      $f22, 0x10($s0)
/* CDCC80 802405E0 E6140018 */  swc1      $f20, 0x18($s0)
/* CDCC84 802405E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* CDCC88 802405E8 8FB00010 */  lw        $s0, 0x10($sp)
/* CDCC8C 802405EC D7B80028 */  ldc1      $f24, 0x28($sp)
/* CDCC90 802405F0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CDCC94 802405F4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CDCC98 802405F8 03E00008 */  jr        $ra
/* CDCC9C 802405FC 27BD0030 */   addiu    $sp, $sp, 0x30
