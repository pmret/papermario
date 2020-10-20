.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F0_B660A0
/* B660A0 802405F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B660A4 802405F4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B660A8 802405F8 4485A000 */  mtc1      $a1, $f20
/* B660AC 802405FC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B660B0 80240600 4486B000 */  mtc1      $a2, $f22
/* B660B4 80240604 AFB00010 */  sw        $s0, 0x10($sp)
/* B660B8 80240608 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B660BC 8024060C 4487C000 */  mtc1      $a3, $f24
/* B660C0 80240610 AFBF0014 */  sw        $ra, 0x14($sp)
/* B660C4 80240614 0C019D28 */  jal       guMtxIdentF
/* B660C8 80240618 0080802D */   daddu    $s0, $a0, $zero
/* B660CC 8024061C 4616A582 */  mul.s     $f22, $f20, $f22
/* B660D0 80240620 00000000 */  nop       
/* B660D4 80240624 4618A502 */  mul.s     $f20, $f20, $f24
/* B660D8 80240628 00000000 */  nop       
/* B660DC 8024062C 3C013F80 */  lui       $at, 0x3f80
/* B660E0 80240630 44810000 */  mtc1      $at, $f0
/* B660E4 80240634 00000000 */  nop       
/* B660E8 80240638 E6000014 */  swc1      $f0, 0x14($s0)
/* B660EC 8024063C E6160010 */  swc1      $f22, 0x10($s0)
/* B660F0 80240640 E6140018 */  swc1      $f20, 0x18($s0)
/* B660F4 80240644 8FBF0014 */  lw        $ra, 0x14($sp)
/* B660F8 80240648 8FB00010 */  lw        $s0, 0x10($sp)
/* B660FC 8024064C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B66100 80240650 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B66104 80240654 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B66108 80240658 03E00008 */  jr        $ra
/* B6610C 8024065C 27BD0030 */   addiu    $sp, $sp, 0x30
