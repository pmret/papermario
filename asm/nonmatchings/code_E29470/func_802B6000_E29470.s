.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E29470
/* E29470 802B6000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E29474 802B6004 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E29478 802B6008 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E2947C 802B600C 27A50028 */  addiu     $a1, $sp, 0x28
/* E29480 802B6010 27A6002C */  addiu     $a2, $sp, 0x2c
/* E29484 802B6014 AFBF0048 */  sw        $ra, 0x48($sp)
/* E29488 802B6018 848200B0 */  lh        $v0, 0xb0($a0)
/* E2948C 802B601C 3C013FE0 */  lui       $at, 0x3fe0
/* E29490 802B6020 44810800 */  mtc1      $at, $f1
/* E29494 802B6024 44800000 */  mtc1      $zero, $f0
/* E29498 802B6028 44823000 */  mtc1      $v0, $f6
/* E2949C 802B602C 00000000 */  nop       
/* E294A0 802B6030 468031A0 */  cvt.s.w   $f6, $f6
/* E294A4 802B6034 460030A1 */  cvt.d.s   $f2, $f6
/* E294A8 802B6038 46201082 */  mul.d     $f2, $f2, $f0
/* E294AC 802B603C 00000000 */  nop       
/* E294B0 802B6040 27A70030 */  addiu     $a3, $sp, 0x30
/* E294B4 802B6044 C4840028 */  lwc1      $f4, 0x28($a0)
/* E294B8 802B6048 C480002C */  lwc1      $f0, 0x2c($a0)
/* E294BC 802B604C 27A20034 */  addiu     $v0, $sp, 0x34
/* E294C0 802B6050 E7A40028 */  swc1      $f4, 0x28($sp)
/* E294C4 802B6054 C4840030 */  lwc1      $f4, 0x30($a0)
/* E294C8 802B6058 46000021 */  cvt.d.s   $f0, $f0
/* E294CC 802B605C 46220000 */  add.d     $f0, $f0, $f2
/* E294D0 802B6060 E7A60034 */  swc1      $f6, 0x34($sp)
/* E294D4 802B6064 E7A40030 */  swc1      $f4, 0x30($sp)
/* E294D8 802B6068 46200020 */  cvt.s.d   $f0, $f0
/* E294DC 802B606C E7A0002C */  swc1      $f0, 0x2c($sp)
/* E294E0 802B6070 AFA20010 */  sw        $v0, 0x10($sp)
/* E294E4 802B6074 27A20038 */  addiu     $v0, $sp, 0x38
/* E294E8 802B6078 AFA20014 */  sw        $v0, 0x14($sp)
/* E294EC 802B607C 27A2003C */  addiu     $v0, $sp, 0x3c
/* E294F0 802B6080 AFA20018 */  sw        $v0, 0x18($sp)
/* E294F4 802B6084 27A20040 */  addiu     $v0, $sp, 0x40
/* E294F8 802B6088 AFA2001C */  sw        $v0, 0x1c($sp)
/* E294FC 802B608C 27A20044 */  addiu     $v0, $sp, 0x44
/* E29500 802B6090 0C03791B */  jal       func_800DE46C
/* E29504 802B6094 AFA20020 */   sw       $v0, 0x20($sp)
/* E29508 802B6098 8FBF0048 */  lw        $ra, 0x48($sp)
/* E2950C 802B609C 03E00008 */  jr        $ra
/* E29510 802B60A0 27BD0050 */   addiu    $sp, $sp, 0x50
