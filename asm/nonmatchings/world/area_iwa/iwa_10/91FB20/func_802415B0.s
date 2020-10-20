.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415B0
/* 91FB20 802415B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 91FB24 802415B4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 91FB28 802415B8 4485A000 */  mtc1      $a1, $f20
/* 91FB2C 802415BC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 91FB30 802415C0 4486B000 */  mtc1      $a2, $f22
/* 91FB34 802415C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 91FB38 802415C8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 91FB3C 802415CC 4487C000 */  mtc1      $a3, $f24
/* 91FB40 802415D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 91FB44 802415D4 0C019D28 */  jal       guMtxIdentF
/* 91FB48 802415D8 0080802D */   daddu    $s0, $a0, $zero
/* 91FB4C 802415DC 4616A582 */  mul.s     $f22, $f20, $f22
/* 91FB50 802415E0 00000000 */  nop       
/* 91FB54 802415E4 4618A502 */  mul.s     $f20, $f20, $f24
/* 91FB58 802415E8 00000000 */  nop       
/* 91FB5C 802415EC 3C013F80 */  lui       $at, 0x3f80
/* 91FB60 802415F0 44810000 */  mtc1      $at, $f0
/* 91FB64 802415F4 00000000 */  nop       
/* 91FB68 802415F8 E6000014 */  swc1      $f0, 0x14($s0)
/* 91FB6C 802415FC E6160010 */  swc1      $f22, 0x10($s0)
/* 91FB70 80241600 E6140018 */  swc1      $f20, 0x18($s0)
/* 91FB74 80241604 8FBF0014 */  lw        $ra, 0x14($sp)
/* 91FB78 80241608 8FB00010 */  lw        $s0, 0x10($sp)
/* 91FB7C 8024160C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 91FB80 80241610 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 91FB84 80241614 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 91FB88 80241618 03E00008 */  jr        $ra
/* 91FB8C 8024161C 27BD0030 */   addiu    $sp, $sp, 0x30
