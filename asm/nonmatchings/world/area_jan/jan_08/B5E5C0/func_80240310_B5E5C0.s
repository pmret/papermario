.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_B5E5C0
/* B5E5C0 80240310 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5E5C4 80240314 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B5E5C8 80240318 4485A000 */  mtc1      $a1, $f20
/* B5E5CC 8024031C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B5E5D0 80240320 4486B000 */  mtc1      $a2, $f22
/* B5E5D4 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* B5E5D8 80240328 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B5E5DC 8024032C 4487C000 */  mtc1      $a3, $f24
/* B5E5E0 80240330 AFBF0014 */  sw        $ra, 0x14($sp)
/* B5E5E4 80240334 0C019D28 */  jal       guMtxIdentF
/* B5E5E8 80240338 0080802D */   daddu    $s0, $a0, $zero
/* B5E5EC 8024033C 4616A582 */  mul.s     $f22, $f20, $f22
/* B5E5F0 80240340 00000000 */  nop       
/* B5E5F4 80240344 4618A502 */  mul.s     $f20, $f20, $f24
/* B5E5F8 80240348 00000000 */  nop       
/* B5E5FC 8024034C 3C013F80 */  lui       $at, 0x3f80
/* B5E600 80240350 44810000 */  mtc1      $at, $f0
/* B5E604 80240354 00000000 */  nop       
/* B5E608 80240358 E6000014 */  swc1      $f0, 0x14($s0)
/* B5E60C 8024035C E6160010 */  swc1      $f22, 0x10($s0)
/* B5E610 80240360 E6140018 */  swc1      $f20, 0x18($s0)
/* B5E614 80240364 8FBF0014 */  lw        $ra, 0x14($sp)
/* B5E618 80240368 8FB00010 */  lw        $s0, 0x10($sp)
/* B5E61C 8024036C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B5E620 80240370 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B5E624 80240374 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B5E628 80240378 03E00008 */  jr        $ra
/* B5E62C 8024037C 27BD0030 */   addiu    $sp, $sp, 0x30
