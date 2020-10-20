.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241230
/* CBA430 80241230 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CBA434 80241234 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CBA438 80241238 4485A000 */  mtc1      $a1, $f20
/* CBA43C 8024123C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CBA440 80241240 4486B000 */  mtc1      $a2, $f22
/* CBA444 80241244 AFB00010 */  sw        $s0, 0x10($sp)
/* CBA448 80241248 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CBA44C 8024124C 4487C000 */  mtc1      $a3, $f24
/* CBA450 80241250 AFBF0014 */  sw        $ra, 0x14($sp)
/* CBA454 80241254 0C019D28 */  jal       guMtxIdentF
/* CBA458 80241258 0080802D */   daddu    $s0, $a0, $zero
/* CBA45C 8024125C 4616A582 */  mul.s     $f22, $f20, $f22
/* CBA460 80241260 00000000 */  nop       
/* CBA464 80241264 4618A502 */  mul.s     $f20, $f20, $f24
/* CBA468 80241268 00000000 */  nop       
/* CBA46C 8024126C 3C013F80 */  lui       $at, 0x3f80
/* CBA470 80241270 44810000 */  mtc1      $at, $f0
/* CBA474 80241274 00000000 */  nop       
/* CBA478 80241278 E6000014 */  swc1      $f0, 0x14($s0)
/* CBA47C 8024127C E6160010 */  swc1      $f22, 0x10($s0)
/* CBA480 80241280 E6140018 */  swc1      $f20, 0x18($s0)
/* CBA484 80241284 8FBF0014 */  lw        $ra, 0x14($sp)
/* CBA488 80241288 8FB00010 */  lw        $s0, 0x10($sp)
/* CBA48C 8024128C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CBA490 80241290 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CBA494 80241294 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CBA498 80241298 03E00008 */  jr        $ra
/* CBA49C 8024129C 27BD0030 */   addiu    $sp, $sp, 0x30
