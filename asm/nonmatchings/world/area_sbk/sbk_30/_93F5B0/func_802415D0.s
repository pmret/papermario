.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415D0
/* 940B80 802415D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 940B84 802415D4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 940B88 802415D8 4485A000 */  mtc1      $a1, $f20
/* 940B8C 802415DC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 940B90 802415E0 4486B000 */  mtc1      $a2, $f22
/* 940B94 802415E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 940B98 802415E8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 940B9C 802415EC 4487C000 */  mtc1      $a3, $f24
/* 940BA0 802415F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 940BA4 802415F4 0C019D28 */  jal       guMtxIdentF
/* 940BA8 802415F8 0080802D */   daddu    $s0, $a0, $zero
/* 940BAC 802415FC 4616A582 */  mul.s     $f22, $f20, $f22
/* 940BB0 80241600 00000000 */  nop       
/* 940BB4 80241604 4618A502 */  mul.s     $f20, $f20, $f24
/* 940BB8 80241608 00000000 */  nop       
/* 940BBC 8024160C 3C013F80 */  lui       $at, 0x3f80
/* 940BC0 80241610 44810000 */  mtc1      $at, $f0
/* 940BC4 80241614 00000000 */  nop       
/* 940BC8 80241618 E6000014 */  swc1      $f0, 0x14($s0)
/* 940BCC 8024161C E6160010 */  swc1      $f22, 0x10($s0)
/* 940BD0 80241620 E6140018 */  swc1      $f20, 0x18($s0)
/* 940BD4 80241624 8FBF0014 */  lw        $ra, 0x14($sp)
/* 940BD8 80241628 8FB00010 */  lw        $s0, 0x10($sp)
/* 940BDC 8024162C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 940BE0 80241630 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 940BE4 80241634 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 940BE8 80241638 03E00008 */  jr        $ra
/* 940BEC 8024163C 27BD0030 */   addiu    $sp, $sp, 0x30
