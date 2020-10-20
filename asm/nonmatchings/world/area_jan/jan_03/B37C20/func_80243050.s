.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243050
/* B37C20 80243050 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B37C24 80243054 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B37C28 80243058 4485A000 */  mtc1      $a1, $f20
/* B37C2C 8024305C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B37C30 80243060 4486B000 */  mtc1      $a2, $f22
/* B37C34 80243064 AFB00010 */  sw        $s0, 0x10($sp)
/* B37C38 80243068 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B37C3C 8024306C 4487C000 */  mtc1      $a3, $f24
/* B37C40 80243070 AFBF0014 */  sw        $ra, 0x14($sp)
/* B37C44 80243074 0C019D28 */  jal       guMtxIdentF
/* B37C48 80243078 0080802D */   daddu    $s0, $a0, $zero
/* B37C4C 8024307C 4616A582 */  mul.s     $f22, $f20, $f22
/* B37C50 80243080 00000000 */  nop       
/* B37C54 80243084 4618A502 */  mul.s     $f20, $f20, $f24
/* B37C58 80243088 00000000 */  nop       
/* B37C5C 8024308C 3C013F80 */  lui       $at, 0x3f80
/* B37C60 80243090 44810000 */  mtc1      $at, $f0
/* B37C64 80243094 00000000 */  nop       
/* B37C68 80243098 E6000014 */  swc1      $f0, 0x14($s0)
/* B37C6C 8024309C E6160010 */  swc1      $f22, 0x10($s0)
/* B37C70 802430A0 E6140018 */  swc1      $f20, 0x18($s0)
/* B37C74 802430A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B37C78 802430A8 8FB00010 */  lw        $s0, 0x10($sp)
/* B37C7C 802430AC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B37C80 802430B0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B37C84 802430B4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B37C88 802430B8 03E00008 */  jr        $ra
/* B37C8C 802430BC 27BD0030 */   addiu    $sp, $sp, 0x30
