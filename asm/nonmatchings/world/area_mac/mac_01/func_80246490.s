.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80246490
/* 806D10 80246490 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 806D14 80246494 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 806D18 80246498 4485A000 */  mtc1      $a1, $f20
/* 806D1C 8024649C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 806D20 802464A0 4486B000 */  mtc1      $a2, $f22
/* 806D24 802464A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 806D28 802464A8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 806D2C 802464AC 4487C000 */  mtc1      $a3, $f24
/* 806D30 802464B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 806D34 802464B4 0C019D28 */  jal       guMtxIdentF
/* 806D38 802464B8 0080802D */   daddu    $s0, $a0, $zero
/* 806D3C 802464BC 4616A582 */  mul.s     $f22, $f20, $f22
/* 806D40 802464C0 00000000 */  nop       
/* 806D44 802464C4 4618A502 */  mul.s     $f20, $f20, $f24
/* 806D48 802464C8 00000000 */  nop       
/* 806D4C 802464CC 3C013F80 */  lui       $at, 0x3f80
/* 806D50 802464D0 44810000 */  mtc1      $at, $f0
/* 806D54 802464D4 00000000 */  nop       
/* 806D58 802464D8 E6000014 */  swc1      $f0, 0x14($s0)
/* 806D5C 802464DC E6160010 */  swc1      $f22, 0x10($s0)
/* 806D60 802464E0 E6140018 */  swc1      $f20, 0x18($s0)
/* 806D64 802464E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 806D68 802464E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 806D6C 802464EC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 806D70 802464F0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 806D74 802464F4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 806D78 802464F8 03E00008 */  jr        $ra
/* 806D7C 802464FC 27BD0030 */   addiu    $sp, $sp, 0x30
