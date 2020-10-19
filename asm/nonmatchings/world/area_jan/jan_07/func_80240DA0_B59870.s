.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_B5A610
/* B5A610 80240DA0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5A614 80240DA4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B5A618 80240DA8 4485A000 */  mtc1      $a1, $f20
/* B5A61C 80240DAC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B5A620 80240DB0 4486B000 */  mtc1      $a2, $f22
/* B5A624 80240DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* B5A628 80240DB8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B5A62C 80240DBC 4487C000 */  mtc1      $a3, $f24
/* B5A630 80240DC0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B5A634 80240DC4 0C019D28 */  jal       guMtxIdentF
/* B5A638 80240DC8 0080802D */   daddu    $s0, $a0, $zero
/* B5A63C 80240DCC 4616A582 */  mul.s     $f22, $f20, $f22
/* B5A640 80240DD0 00000000 */  nop       
/* B5A644 80240DD4 4618A502 */  mul.s     $f20, $f20, $f24
/* B5A648 80240DD8 00000000 */  nop       
/* B5A64C 80240DDC 3C013F80 */  lui       $at, 0x3f80
/* B5A650 80240DE0 44810000 */  mtc1      $at, $f0
/* B5A654 80240DE4 00000000 */  nop       
/* B5A658 80240DE8 E6000014 */  swc1      $f0, 0x14($s0)
/* B5A65C 80240DEC E6160010 */  swc1      $f22, 0x10($s0)
/* B5A660 80240DF0 E6140018 */  swc1      $f20, 0x18($s0)
/* B5A664 80240DF4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B5A668 80240DF8 8FB00010 */  lw        $s0, 0x10($sp)
/* B5A66C 80240DFC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B5A670 80240E00 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B5A674 80240E04 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B5A678 80240E08 03E00008 */  jr        $ra
/* B5A67C 80240E0C 27BD0030 */   addiu    $sp, $sp, 0x30
