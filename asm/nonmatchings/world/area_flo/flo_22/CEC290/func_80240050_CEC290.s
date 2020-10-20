.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_CEC290
/* CEC290 80240050 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CEC294 80240054 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CEC298 80240058 4485A000 */  mtc1      $a1, $f20
/* CEC29C 8024005C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CEC2A0 80240060 4486B000 */  mtc1      $a2, $f22
/* CEC2A4 80240064 AFB00010 */  sw        $s0, 0x10($sp)
/* CEC2A8 80240068 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CEC2AC 8024006C 4487C000 */  mtc1      $a3, $f24
/* CEC2B0 80240070 AFBF0014 */  sw        $ra, 0x14($sp)
/* CEC2B4 80240074 0C019D28 */  jal       guMtxIdentF
/* CEC2B8 80240078 0080802D */   daddu    $s0, $a0, $zero
/* CEC2BC 8024007C 4616A582 */  mul.s     $f22, $f20, $f22
/* CEC2C0 80240080 00000000 */  nop       
/* CEC2C4 80240084 4618A502 */  mul.s     $f20, $f20, $f24
/* CEC2C8 80240088 00000000 */  nop       
/* CEC2CC 8024008C 3C013F80 */  lui       $at, 0x3f80
/* CEC2D0 80240090 44810000 */  mtc1      $at, $f0
/* CEC2D4 80240094 00000000 */  nop       
/* CEC2D8 80240098 E6000014 */  swc1      $f0, 0x14($s0)
/* CEC2DC 8024009C E6160010 */  swc1      $f22, 0x10($s0)
/* CEC2E0 802400A0 E6140018 */  swc1      $f20, 0x18($s0)
/* CEC2E4 802400A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* CEC2E8 802400A8 8FB00010 */  lw        $s0, 0x10($sp)
/* CEC2EC 802400AC D7B80028 */  ldc1      $f24, 0x28($sp)
/* CEC2F0 802400B0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CEC2F4 802400B4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CEC2F8 802400B8 03E00008 */  jr        $ra
/* CEC2FC 802400BC 27BD0030 */   addiu    $sp, $sp, 0x30
