.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240330_9FAB20
/* 9FAB20 80240330 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9FAB24 80240334 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9FAB28 80240338 4485A000 */  mtc1      $a1, $f20
/* 9FAB2C 8024033C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9FAB30 80240340 4486B000 */  mtc1      $a2, $f22
/* 9FAB34 80240344 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FAB38 80240348 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9FAB3C 8024034C 4487C000 */  mtc1      $a3, $f24
/* 9FAB40 80240350 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9FAB44 80240354 0C019D28 */  jal       guMtxIdentF
/* 9FAB48 80240358 0080802D */   daddu    $s0, $a0, $zero
/* 9FAB4C 8024035C 4616A582 */  mul.s     $f22, $f20, $f22
/* 9FAB50 80240360 00000000 */  nop       
/* 9FAB54 80240364 4618A502 */  mul.s     $f20, $f20, $f24
/* 9FAB58 80240368 00000000 */  nop       
/* 9FAB5C 8024036C 3C013F80 */  lui       $at, 0x3f80
/* 9FAB60 80240370 44810000 */  mtc1      $at, $f0
/* 9FAB64 80240374 00000000 */  nop       
/* 9FAB68 80240378 E6000014 */  swc1      $f0, 0x14($s0)
/* 9FAB6C 8024037C E6160010 */  swc1      $f22, 0x10($s0)
/* 9FAB70 80240380 E6140018 */  swc1      $f20, 0x18($s0)
/* 9FAB74 80240384 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9FAB78 80240388 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FAB7C 8024038C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 9FAB80 80240390 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 9FAB84 80240394 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 9FAB88 80240398 03E00008 */  jr        $ra
/* 9FAB8C 8024039C 27BD0030 */   addiu    $sp, $sp, 0x30
