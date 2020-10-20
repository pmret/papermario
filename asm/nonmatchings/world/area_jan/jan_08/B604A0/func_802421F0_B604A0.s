.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421F0_B604A0
/* B604A0 802421F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B604A4 802421F4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B604A8 802421F8 4485A000 */  mtc1      $a1, $f20
/* B604AC 802421FC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B604B0 80242200 4486B000 */  mtc1      $a2, $f22
/* B604B4 80242204 AFB00010 */  sw        $s0, 0x10($sp)
/* B604B8 80242208 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B604BC 8024220C 4487C000 */  mtc1      $a3, $f24
/* B604C0 80242210 AFBF0014 */  sw        $ra, 0x14($sp)
/* B604C4 80242214 0C019D28 */  jal       guMtxIdentF
/* B604C8 80242218 0080802D */   daddu    $s0, $a0, $zero
/* B604CC 8024221C 4616A582 */  mul.s     $f22, $f20, $f22
/* B604D0 80242220 00000000 */  nop       
/* B604D4 80242224 4618A502 */  mul.s     $f20, $f20, $f24
/* B604D8 80242228 00000000 */  nop       
/* B604DC 8024222C 3C013F80 */  lui       $at, 0x3f80
/* B604E0 80242230 44810000 */  mtc1      $at, $f0
/* B604E4 80242234 00000000 */  nop       
/* B604E8 80242238 E6000014 */  swc1      $f0, 0x14($s0)
/* B604EC 8024223C E6160010 */  swc1      $f22, 0x10($s0)
/* B604F0 80242240 E6140018 */  swc1      $f20, 0x18($s0)
/* B604F4 80242244 8FBF0014 */  lw        $ra, 0x14($sp)
/* B604F8 80242248 8FB00010 */  lw        $s0, 0x10($sp)
/* B604FC 8024224C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B60500 80242250 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B60504 80242254 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B60508 80242258 03E00008 */  jr        $ra
/* B6050C 8024225C 27BD0030 */   addiu    $sp, $sp, 0x30
