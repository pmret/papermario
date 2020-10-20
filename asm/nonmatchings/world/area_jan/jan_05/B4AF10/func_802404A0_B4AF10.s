.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A0_B4AF10
/* B4AF10 802404A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B4AF14 802404A4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B4AF18 802404A8 4485A000 */  mtc1      $a1, $f20
/* B4AF1C 802404AC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B4AF20 802404B0 4486B000 */  mtc1      $a2, $f22
/* B4AF24 802404B4 AFB00010 */  sw        $s0, 0x10($sp)
/* B4AF28 802404B8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B4AF2C 802404BC 4487C000 */  mtc1      $a3, $f24
/* B4AF30 802404C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B4AF34 802404C4 0C019D28 */  jal       guMtxIdentF
/* B4AF38 802404C8 0080802D */   daddu    $s0, $a0, $zero
/* B4AF3C 802404CC 4616A582 */  mul.s     $f22, $f20, $f22
/* B4AF40 802404D0 00000000 */  nop       
/* B4AF44 802404D4 4618A502 */  mul.s     $f20, $f20, $f24
/* B4AF48 802404D8 00000000 */  nop       
/* B4AF4C 802404DC 3C013F80 */  lui       $at, 0x3f80
/* B4AF50 802404E0 44810000 */  mtc1      $at, $f0
/* B4AF54 802404E4 00000000 */  nop       
/* B4AF58 802404E8 E6000014 */  swc1      $f0, 0x14($s0)
/* B4AF5C 802404EC E6160010 */  swc1      $f22, 0x10($s0)
/* B4AF60 802404F0 E6140018 */  swc1      $f20, 0x18($s0)
/* B4AF64 802404F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4AF68 802404F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B4AF6C 802404FC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B4AF70 80240500 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B4AF74 80240504 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B4AF78 80240508 03E00008 */  jr        $ra
/* B4AF7C 8024050C 27BD0030 */   addiu    $sp, $sp, 0x30
