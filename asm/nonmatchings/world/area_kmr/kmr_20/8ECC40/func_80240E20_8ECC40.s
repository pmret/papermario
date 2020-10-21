.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E20_8ECC40
/* 8ECC40 80240E20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8ECC44 80240E24 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8ECC48 80240E28 4485A000 */  mtc1      $a1, $f20
/* 8ECC4C 80240E2C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8ECC50 80240E30 4486B000 */  mtc1      $a2, $f22
/* 8ECC54 80240E34 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ECC58 80240E38 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8ECC5C 80240E3C 4487C000 */  mtc1      $a3, $f24
/* 8ECC60 80240E40 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8ECC64 80240E44 0C019D28 */  jal       guMtxIdentF
/* 8ECC68 80240E48 0080802D */   daddu    $s0, $a0, $zero
/* 8ECC6C 80240E4C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8ECC70 80240E50 00000000 */  nop       
/* 8ECC74 80240E54 4618A502 */  mul.s     $f20, $f20, $f24
/* 8ECC78 80240E58 00000000 */  nop       
/* 8ECC7C 80240E5C 3C013F80 */  lui       $at, 0x3f80
/* 8ECC80 80240E60 44810000 */  mtc1      $at, $f0
/* 8ECC84 80240E64 00000000 */  nop       
/* 8ECC88 80240E68 E6000014 */  swc1      $f0, 0x14($s0)
/* 8ECC8C 80240E6C E6160010 */  swc1      $f22, 0x10($s0)
/* 8ECC90 80240E70 E6140018 */  swc1      $f20, 0x18($s0)
/* 8ECC94 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8ECC98 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ECC9C 80240E7C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8ECCA0 80240E80 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8ECCA4 80240E84 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8ECCA8 80240E88 03E00008 */  jr        $ra
/* 8ECCAC 80240E8C 27BD0030 */   addiu    $sp, $sp, 0x30
