.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242450_B4CEC0
/* B4CEC0 80242450 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B4CEC4 80242454 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B4CEC8 80242458 4485A000 */  mtc1      $a1, $f20
/* B4CECC 8024245C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B4CED0 80242460 4486B000 */  mtc1      $a2, $f22
/* B4CED4 80242464 AFB00010 */  sw        $s0, 0x10($sp)
/* B4CED8 80242468 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B4CEDC 8024246C 4487C000 */  mtc1      $a3, $f24
/* B4CEE0 80242470 AFBF0014 */  sw        $ra, 0x14($sp)
/* B4CEE4 80242474 0C019D28 */  jal       guMtxIdentF
/* B4CEE8 80242478 0080802D */   daddu    $s0, $a0, $zero
/* B4CEEC 8024247C 4616A582 */  mul.s     $f22, $f20, $f22
/* B4CEF0 80242480 00000000 */  nop       
/* B4CEF4 80242484 4618A502 */  mul.s     $f20, $f20, $f24
/* B4CEF8 80242488 00000000 */  nop       
/* B4CEFC 8024248C 3C013F80 */  lui       $at, 0x3f80
/* B4CF00 80242490 44810000 */  mtc1      $at, $f0
/* B4CF04 80242494 00000000 */  nop       
/* B4CF08 80242498 E6000014 */  swc1      $f0, 0x14($s0)
/* B4CF0C 8024249C E6160010 */  swc1      $f22, 0x10($s0)
/* B4CF10 802424A0 E6140018 */  swc1      $f20, 0x18($s0)
/* B4CF14 802424A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4CF18 802424A8 8FB00010 */  lw        $s0, 0x10($sp)
/* B4CF1C 802424AC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B4CF20 802424B0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B4CF24 802424B4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B4CF28 802424B8 03E00008 */  jr        $ra
/* B4CF2C 802424BC 27BD0030 */   addiu    $sp, $sp, 0x30
