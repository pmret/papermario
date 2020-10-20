.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D80
/* B454F0 80240D80 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B454F4 80240D84 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B454F8 80240D88 4485A000 */  mtc1      $a1, $f20
/* B454FC 80240D8C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B45500 80240D90 4486B000 */  mtc1      $a2, $f22
/* B45504 80240D94 AFB00010 */  sw        $s0, 0x10($sp)
/* B45508 80240D98 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B4550C 80240D9C 4487C000 */  mtc1      $a3, $f24
/* B45510 80240DA0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B45514 80240DA4 0C019D28 */  jal       guMtxIdentF
/* B45518 80240DA8 0080802D */   daddu    $s0, $a0, $zero
/* B4551C 80240DAC 4616A582 */  mul.s     $f22, $f20, $f22
/* B45520 80240DB0 00000000 */  nop       
/* B45524 80240DB4 4618A502 */  mul.s     $f20, $f20, $f24
/* B45528 80240DB8 00000000 */  nop       
/* B4552C 80240DBC 3C013F80 */  lui       $at, 0x3f80
/* B45530 80240DC0 44810000 */  mtc1      $at, $f0
/* B45534 80240DC4 00000000 */  nop       
/* B45538 80240DC8 E6000014 */  swc1      $f0, 0x14($s0)
/* B4553C 80240DCC E6160010 */  swc1      $f22, 0x10($s0)
/* B45540 80240DD0 E6140018 */  swc1      $f20, 0x18($s0)
/* B45544 80240DD4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B45548 80240DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* B4554C 80240DDC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B45550 80240DE0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B45554 80240DE4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B45558 80240DE8 03E00008 */  jr        $ra
/* B4555C 80240DEC 27BD0030 */   addiu    $sp, $sp, 0x30
