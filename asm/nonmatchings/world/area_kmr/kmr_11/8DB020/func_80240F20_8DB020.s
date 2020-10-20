.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_8DB020
/* 8DB020 80240F20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8DB024 80240F24 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8DB028 80240F28 4485A000 */  mtc1      $a1, $f20
/* 8DB02C 80240F2C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8DB030 80240F30 4486B000 */  mtc1      $a2, $f22
/* 8DB034 80240F34 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DB038 80240F38 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8DB03C 80240F3C 4487C000 */  mtc1      $a3, $f24
/* 8DB040 80240F40 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8DB044 80240F44 0C019D28 */  jal       guMtxIdentF
/* 8DB048 80240F48 0080802D */   daddu    $s0, $a0, $zero
/* 8DB04C 80240F4C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8DB050 80240F50 00000000 */  nop       
/* 8DB054 80240F54 4618A502 */  mul.s     $f20, $f20, $f24
/* 8DB058 80240F58 00000000 */  nop       
/* 8DB05C 80240F5C 3C013F80 */  lui       $at, 0x3f80
/* 8DB060 80240F60 44810000 */  mtc1      $at, $f0
/* 8DB064 80240F64 00000000 */  nop       
/* 8DB068 80240F68 E6000014 */  swc1      $f0, 0x14($s0)
/* 8DB06C 80240F6C E6160010 */  swc1      $f22, 0x10($s0)
/* 8DB070 80240F70 E6140018 */  swc1      $f20, 0x18($s0)
/* 8DB074 80240F74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8DB078 80240F78 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DB07C 80240F7C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8DB080 80240F80 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8DB084 80240F84 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8DB088 80240F88 03E00008 */  jr        $ra
/* 8DB08C 80240F8C 27BD0030 */   addiu    $sp, $sp, 0x30
