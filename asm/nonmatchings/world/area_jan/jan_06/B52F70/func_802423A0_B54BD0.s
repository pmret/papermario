.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423A0_B54BD0
/* B54BD0 802423A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B54BD4 802423A4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B54BD8 802423A8 4485A000 */  mtc1      $a1, $f20
/* B54BDC 802423AC F7B60020 */  sdc1      $f22, 0x20($sp)
/* B54BE0 802423B0 4486B000 */  mtc1      $a2, $f22
/* B54BE4 802423B4 AFB00010 */  sw        $s0, 0x10($sp)
/* B54BE8 802423B8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B54BEC 802423BC 4487C000 */  mtc1      $a3, $f24
/* B54BF0 802423C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B54BF4 802423C4 0C019D28 */  jal       guMtxIdentF
/* B54BF8 802423C8 0080802D */   daddu    $s0, $a0, $zero
/* B54BFC 802423CC 4616A582 */  mul.s     $f22, $f20, $f22
/* B54C00 802423D0 00000000 */  nop       
/* B54C04 802423D4 4618A502 */  mul.s     $f20, $f20, $f24
/* B54C08 802423D8 00000000 */  nop       
/* B54C0C 802423DC 3C013F80 */  lui       $at, 0x3f80
/* B54C10 802423E0 44810000 */  mtc1      $at, $f0
/* B54C14 802423E4 00000000 */  nop       
/* B54C18 802423E8 E6000014 */  swc1      $f0, 0x14($s0)
/* B54C1C 802423EC E6160010 */  swc1      $f22, 0x10($s0)
/* B54C20 802423F0 E6140018 */  swc1      $f20, 0x18($s0)
/* B54C24 802423F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B54C28 802423F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B54C2C 802423FC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B54C30 80242400 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B54C34 80242404 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B54C38 80242408 03E00008 */  jr        $ra
/* B54C3C 8024240C 27BD0030 */   addiu    $sp, $sp, 0x30
