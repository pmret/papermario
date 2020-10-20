.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_D05D1C
/* D05D1C 802405EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D05D20 802405F0 F7B40018 */  sdc1      $f20, 0x18($sp)
/* D05D24 802405F4 4485A000 */  mtc1      $a1, $f20
/* D05D28 802405F8 F7B60020 */  sdc1      $f22, 0x20($sp)
/* D05D2C 802405FC 4486B000 */  mtc1      $a2, $f22
/* D05D30 80240600 AFB00010 */  sw        $s0, 0x10($sp)
/* D05D34 80240604 F7B80028 */  sdc1      $f24, 0x28($sp)
/* D05D38 80240608 4487C000 */  mtc1      $a3, $f24
/* D05D3C 8024060C AFBF0014 */  sw        $ra, 0x14($sp)
/* D05D40 80240610 0C019D28 */  jal       guMtxIdentF
/* D05D44 80240614 0080802D */   daddu    $s0, $a0, $zero
/* D05D48 80240618 4616A582 */  mul.s     $f22, $f20, $f22
/* D05D4C 8024061C 00000000 */  nop       
/* D05D50 80240620 4618A502 */  mul.s     $f20, $f20, $f24
/* D05D54 80240624 00000000 */  nop       
/* D05D58 80240628 3C013F80 */  lui       $at, 0x3f80
/* D05D5C 8024062C 44810000 */  mtc1      $at, $f0
/* D05D60 80240630 00000000 */  nop       
/* D05D64 80240634 E6000014 */  swc1      $f0, 0x14($s0)
/* D05D68 80240638 E6160010 */  swc1      $f22, 0x10($s0)
/* D05D6C 8024063C E6140018 */  swc1      $f20, 0x18($s0)
/* D05D70 80240640 8FBF0014 */  lw        $ra, 0x14($sp)
/* D05D74 80240644 8FB00010 */  lw        $s0, 0x10($sp)
/* D05D78 80240648 D7B80028 */  ldc1      $f24, 0x28($sp)
/* D05D7C 8024064C D7B60020 */  ldc1      $f22, 0x20($sp)
/* D05D80 80240650 D7B40018 */  ldc1      $f20, 0x18($sp)
/* D05D84 80240654 03E00008 */  jr        $ra
/* D05D88 80240658 27BD0030 */   addiu    $sp, $sp, 0x30
