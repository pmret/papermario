.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B10_43A5A0
/* 43A5A0 80218B10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 43A5A4 80218B14 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 43A5A8 80218B18 4485A000 */  mtc1      $a1, $f20
/* 43A5AC 80218B1C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 43A5B0 80218B20 4486B000 */  mtc1      $a2, $f22
/* 43A5B4 80218B24 AFB00010 */  sw        $s0, 0x10($sp)
/* 43A5B8 80218B28 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 43A5BC 80218B2C 4487C000 */  mtc1      $a3, $f24
/* 43A5C0 80218B30 AFBF0014 */  sw        $ra, 0x14($sp)
/* 43A5C4 80218B34 0C019D28 */  jal       guMtxIdentF
/* 43A5C8 80218B38 0080802D */   daddu    $s0, $a0, $zero
/* 43A5CC 80218B3C 4616A582 */  mul.s     $f22, $f20, $f22
/* 43A5D0 80218B40 00000000 */  nop       
/* 43A5D4 80218B44 4618A502 */  mul.s     $f20, $f20, $f24
/* 43A5D8 80218B48 00000000 */  nop       
/* 43A5DC 80218B4C 3C013F80 */  lui       $at, 0x3f80
/* 43A5E0 80218B50 44810000 */  mtc1      $at, $f0
/* 43A5E4 80218B54 00000000 */  nop       
/* 43A5E8 80218B58 E6000014 */  swc1      $f0, 0x14($s0)
/* 43A5EC 80218B5C E6160010 */  swc1      $f22, 0x10($s0)
/* 43A5F0 80218B60 E6140018 */  swc1      $f20, 0x18($s0)
/* 43A5F4 80218B64 8FBF0014 */  lw        $ra, 0x14($sp)
/* 43A5F8 80218B68 8FB00010 */  lw        $s0, 0x10($sp)
/* 43A5FC 80218B6C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 43A600 80218B70 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 43A604 80218B74 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 43A608 80218B78 03E00008 */  jr        $ra
/* 43A60C 80218B7C 27BD0030 */   addiu    $sp, $sp, 0x30
