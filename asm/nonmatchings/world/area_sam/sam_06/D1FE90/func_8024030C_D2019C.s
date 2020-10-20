.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_D2019C
/* D2019C 8024030C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D201A0 80240310 F7B40018 */  sdc1      $f20, 0x18($sp)
/* D201A4 80240314 4485A000 */  mtc1      $a1, $f20
/* D201A8 80240318 F7B60020 */  sdc1      $f22, 0x20($sp)
/* D201AC 8024031C 4486B000 */  mtc1      $a2, $f22
/* D201B0 80240320 AFB00010 */  sw        $s0, 0x10($sp)
/* D201B4 80240324 F7B80028 */  sdc1      $f24, 0x28($sp)
/* D201B8 80240328 4487C000 */  mtc1      $a3, $f24
/* D201BC 8024032C AFBF0014 */  sw        $ra, 0x14($sp)
/* D201C0 80240330 0C019D28 */  jal       guMtxIdentF
/* D201C4 80240334 0080802D */   daddu    $s0, $a0, $zero
/* D201C8 80240338 4616A582 */  mul.s     $f22, $f20, $f22
/* D201CC 8024033C 00000000 */  nop       
/* D201D0 80240340 4618A502 */  mul.s     $f20, $f20, $f24
/* D201D4 80240344 00000000 */  nop       
/* D201D8 80240348 3C013F80 */  lui       $at, 0x3f80
/* D201DC 8024034C 44810000 */  mtc1      $at, $f0
/* D201E0 80240350 00000000 */  nop       
/* D201E4 80240354 E6000014 */  swc1      $f0, 0x14($s0)
/* D201E8 80240358 E6160010 */  swc1      $f22, 0x10($s0)
/* D201EC 8024035C E6140018 */  swc1      $f20, 0x18($s0)
/* D201F0 80240360 8FBF0014 */  lw        $ra, 0x14($sp)
/* D201F4 80240364 8FB00010 */  lw        $s0, 0x10($sp)
/* D201F8 80240368 D7B80028 */  ldc1      $f24, 0x28($sp)
/* D201FC 8024036C D7B60020 */  ldc1      $f22, 0x20($sp)
/* D20200 80240370 D7B40018 */  ldc1      $f20, 0x18($sp)
/* D20204 80240374 03E00008 */  jr        $ra
/* D20208 80240378 27BD0030 */   addiu    $sp, $sp, 0x30
