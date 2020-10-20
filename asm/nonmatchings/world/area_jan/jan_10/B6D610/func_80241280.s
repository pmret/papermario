.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241280
/* B6D610 80241280 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B6D614 80241284 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B6D618 80241288 4485A000 */  mtc1      $a1, $f20
/* B6D61C 8024128C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B6D620 80241290 4486B000 */  mtc1      $a2, $f22
/* B6D624 80241294 AFB00010 */  sw        $s0, 0x10($sp)
/* B6D628 80241298 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B6D62C 8024129C 4487C000 */  mtc1      $a3, $f24
/* B6D630 802412A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B6D634 802412A4 0C019D28 */  jal       guMtxIdentF
/* B6D638 802412A8 0080802D */   daddu    $s0, $a0, $zero
/* B6D63C 802412AC 4616A582 */  mul.s     $f22, $f20, $f22
/* B6D640 802412B0 00000000 */  nop       
/* B6D644 802412B4 4618A502 */  mul.s     $f20, $f20, $f24
/* B6D648 802412B8 00000000 */  nop       
/* B6D64C 802412BC 3C013F80 */  lui       $at, 0x3f80
/* B6D650 802412C0 44810000 */  mtc1      $at, $f0
/* B6D654 802412C4 00000000 */  nop       
/* B6D658 802412C8 E6000014 */  swc1      $f0, 0x14($s0)
/* B6D65C 802412CC E6160010 */  swc1      $f22, 0x10($s0)
/* B6D660 802412D0 E6140018 */  swc1      $f20, 0x18($s0)
/* B6D664 802412D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B6D668 802412D8 8FB00010 */  lw        $s0, 0x10($sp)
/* B6D66C 802412DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B6D670 802412E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B6D674 802412E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B6D678 802412E8 03E00008 */  jr        $ra
/* B6D67C 802412EC 27BD0030 */   addiu    $sp, $sp, 0x30
