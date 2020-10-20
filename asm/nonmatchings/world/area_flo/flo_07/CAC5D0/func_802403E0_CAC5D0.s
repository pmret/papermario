.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403E0_CAC5D0
/* CAC5D0 802403E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CAC5D4 802403E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CAC5D8 802403E8 4485A000 */  mtc1      $a1, $f20
/* CAC5DC 802403EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* CAC5E0 802403F0 4486B000 */  mtc1      $a2, $f22
/* CAC5E4 802403F4 AFB00010 */  sw        $s0, 0x10($sp)
/* CAC5E8 802403F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CAC5EC 802403FC 4487C000 */  mtc1      $a3, $f24
/* CAC5F0 80240400 AFBF0014 */  sw        $ra, 0x14($sp)
/* CAC5F4 80240404 0C019D28 */  jal       guMtxIdentF
/* CAC5F8 80240408 0080802D */   daddu    $s0, $a0, $zero
/* CAC5FC 8024040C 4616A582 */  mul.s     $f22, $f20, $f22
/* CAC600 80240410 00000000 */  nop       
/* CAC604 80240414 4618A502 */  mul.s     $f20, $f20, $f24
/* CAC608 80240418 00000000 */  nop       
/* CAC60C 8024041C 3C013F80 */  lui       $at, 0x3f80
/* CAC610 80240420 44810000 */  mtc1      $at, $f0
/* CAC614 80240424 00000000 */  nop       
/* CAC618 80240428 E6000014 */  swc1      $f0, 0x14($s0)
/* CAC61C 8024042C E6160010 */  swc1      $f22, 0x10($s0)
/* CAC620 80240430 E6140018 */  swc1      $f20, 0x18($s0)
/* CAC624 80240434 8FBF0014 */  lw        $ra, 0x14($sp)
/* CAC628 80240438 8FB00010 */  lw        $s0, 0x10($sp)
/* CAC62C 8024043C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CAC630 80240440 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CAC634 80240444 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CAC638 80240448 03E00008 */  jr        $ra
/* CAC63C 8024044C 27BD0030 */   addiu    $sp, $sp, 0x30
