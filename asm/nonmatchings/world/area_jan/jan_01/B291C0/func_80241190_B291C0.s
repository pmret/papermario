.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241190_B291C0
/* B291C0 80241190 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B291C4 80241194 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B291C8 80241198 4485A000 */  mtc1      $a1, $f20
/* B291CC 8024119C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B291D0 802411A0 4486B000 */  mtc1      $a2, $f22
/* B291D4 802411A4 AFB00010 */  sw        $s0, 0x10($sp)
/* B291D8 802411A8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B291DC 802411AC 4487C000 */  mtc1      $a3, $f24
/* B291E0 802411B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B291E4 802411B4 0C019D28 */  jal       guMtxIdentF
/* B291E8 802411B8 0080802D */   daddu    $s0, $a0, $zero
/* B291EC 802411BC 4616A582 */  mul.s     $f22, $f20, $f22
/* B291F0 802411C0 00000000 */  nop       
/* B291F4 802411C4 4618A502 */  mul.s     $f20, $f20, $f24
/* B291F8 802411C8 00000000 */  nop       
/* B291FC 802411CC 3C013F80 */  lui       $at, 0x3f80
/* B29200 802411D0 44810000 */  mtc1      $at, $f0
/* B29204 802411D4 00000000 */  nop       
/* B29208 802411D8 E6000014 */  swc1      $f0, 0x14($s0)
/* B2920C 802411DC E6160010 */  swc1      $f22, 0x10($s0)
/* B29210 802411E0 E6140018 */  swc1      $f20, 0x18($s0)
/* B29214 802411E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B29218 802411E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2921C 802411EC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B29220 802411F0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B29224 802411F4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B29228 802411F8 03E00008 */  jr        $ra
/* B2922C 802411FC 27BD0030 */   addiu    $sp, $sp, 0x30
