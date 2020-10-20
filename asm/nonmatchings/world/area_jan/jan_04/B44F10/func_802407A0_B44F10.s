.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407A0_B44F10
/* B44F10 802407A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B44F14 802407A4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B44F18 802407A8 4485A000 */  mtc1      $a1, $f20
/* B44F1C 802407AC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B44F20 802407B0 4486B000 */  mtc1      $a2, $f22
/* B44F24 802407B4 AFB00010 */  sw        $s0, 0x10($sp)
/* B44F28 802407B8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B44F2C 802407BC 4487C000 */  mtc1      $a3, $f24
/* B44F30 802407C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B44F34 802407C4 0C019D28 */  jal       guMtxIdentF
/* B44F38 802407C8 0080802D */   daddu    $s0, $a0, $zero
/* B44F3C 802407CC 4616A582 */  mul.s     $f22, $f20, $f22
/* B44F40 802407D0 00000000 */  nop       
/* B44F44 802407D4 4618A502 */  mul.s     $f20, $f20, $f24
/* B44F48 802407D8 00000000 */  nop       
/* B44F4C 802407DC 3C013F80 */  lui       $at, 0x3f80
/* B44F50 802407E0 44810000 */  mtc1      $at, $f0
/* B44F54 802407E4 00000000 */  nop       
/* B44F58 802407E8 E6000014 */  swc1      $f0, 0x14($s0)
/* B44F5C 802407EC E6160010 */  swc1      $f22, 0x10($s0)
/* B44F60 802407F0 E6140018 */  swc1      $f20, 0x18($s0)
/* B44F64 802407F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B44F68 802407F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B44F6C 802407FC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B44F70 80240800 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B44F74 80240804 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B44F78 80240808 03E00008 */  jr        $ra
/* B44F7C 8024080C 27BD0030 */   addiu    $sp, $sp, 0x30
