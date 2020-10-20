.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CC0E70
/* CC0E70 80240040 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CC0E74 80240044 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CC0E78 80240048 4485A000 */  mtc1      $a1, $f20
/* CC0E7C 8024004C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CC0E80 80240050 4486B000 */  mtc1      $a2, $f22
/* CC0E84 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* CC0E88 80240058 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CC0E8C 8024005C 4487C000 */  mtc1      $a3, $f24
/* CC0E90 80240060 AFBF0014 */  sw        $ra, 0x14($sp)
/* CC0E94 80240064 0C019D28 */  jal       guMtxIdentF
/* CC0E98 80240068 0080802D */   daddu    $s0, $a0, $zero
/* CC0E9C 8024006C 4616A582 */  mul.s     $f22, $f20, $f22
/* CC0EA0 80240070 00000000 */  nop       
/* CC0EA4 80240074 4618A502 */  mul.s     $f20, $f20, $f24
/* CC0EA8 80240078 00000000 */  nop       
/* CC0EAC 8024007C 3C013F80 */  lui       $at, 0x3f80
/* CC0EB0 80240080 44810000 */  mtc1      $at, $f0
/* CC0EB4 80240084 00000000 */  nop       
/* CC0EB8 80240088 E6000014 */  swc1      $f0, 0x14($s0)
/* CC0EBC 8024008C E6160010 */  swc1      $f22, 0x10($s0)
/* CC0EC0 80240090 E6140018 */  swc1      $f20, 0x18($s0)
/* CC0EC4 80240094 8FBF0014 */  lw        $ra, 0x14($sp)
/* CC0EC8 80240098 8FB00010 */  lw        $s0, 0x10($sp)
/* CC0ECC 8024009C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CC0ED0 802400A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CC0ED4 802400A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CC0ED8 802400A8 03E00008 */  jr        $ra
/* CC0EDC 802400AC 27BD0030 */   addiu    $sp, $sp, 0x30
