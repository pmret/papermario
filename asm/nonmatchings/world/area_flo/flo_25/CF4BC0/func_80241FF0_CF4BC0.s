.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FF0_CF4BC0
/* CF4BC0 80241FF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CF4BC4 80241FF4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CF4BC8 80241FF8 4485A000 */  mtc1      $a1, $f20
/* CF4BCC 80241FFC F7B60020 */  sdc1      $f22, 0x20($sp)
/* CF4BD0 80242000 4486B000 */  mtc1      $a2, $f22
/* CF4BD4 80242004 AFB00010 */  sw        $s0, 0x10($sp)
/* CF4BD8 80242008 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CF4BDC 8024200C 4487C000 */  mtc1      $a3, $f24
/* CF4BE0 80242010 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF4BE4 80242014 0C019D28 */  jal       guMtxIdentF
/* CF4BE8 80242018 0080802D */   daddu    $s0, $a0, $zero
/* CF4BEC 8024201C 4616A582 */  mul.s     $f22, $f20, $f22
/* CF4BF0 80242020 00000000 */  nop       
/* CF4BF4 80242024 4618A502 */  mul.s     $f20, $f20, $f24
/* CF4BF8 80242028 00000000 */  nop       
/* CF4BFC 8024202C 3C013F80 */  lui       $at, 0x3f80
/* CF4C00 80242030 44810000 */  mtc1      $at, $f0
/* CF4C04 80242034 00000000 */  nop       
/* CF4C08 80242038 E6000014 */  swc1      $f0, 0x14($s0)
/* CF4C0C 8024203C E6160010 */  swc1      $f22, 0x10($s0)
/* CF4C10 80242040 E6140018 */  swc1      $f20, 0x18($s0)
/* CF4C14 80242044 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF4C18 80242048 8FB00010 */  lw        $s0, 0x10($sp)
/* CF4C1C 8024204C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CF4C20 80242050 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CF4C24 80242054 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CF4C28 80242058 03E00008 */  jr        $ra
/* CF4C2C 8024205C 27BD0030 */   addiu    $sp, $sp, 0x30
