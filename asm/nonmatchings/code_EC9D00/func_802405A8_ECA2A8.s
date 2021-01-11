.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A8_ECA2A8
/* ECA2A8 802405A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECA2AC 802405AC AFBF0018 */  sw        $ra, 0x18($sp)
/* ECA2B0 802405B0 0C00F94D */  jal       func_8003E534
/* ECA2B4 802405B4 2404FFFC */   addiu    $a0, $zero, -4
/* ECA2B8 802405B8 C444003C */  lwc1      $f4, 0x3c($v0)
/* ECA2BC 802405BC 3C014148 */  lui       $at, 0x4148
/* ECA2C0 802405C0 44811000 */  mtc1      $at, $f2
/* ECA2C4 802405C4 3C013F80 */  lui       $at, 0x3f80
/* ECA2C8 802405C8 44810000 */  mtc1      $at, $f0
/* ECA2CC 802405CC 2403001E */  addiu     $v1, $zero, 0x1e
/* ECA2D0 802405D0 AFA30014 */  sw        $v1, 0x14($sp)
/* ECA2D4 802405D4 46022100 */  add.s     $f4, $f4, $f2
/* ECA2D8 802405D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* ECA2DC 802405DC 8C450038 */  lw        $a1, 0x38($v0)
/* ECA2E0 802405E0 8C470040 */  lw        $a3, 0x40($v0)
/* ECA2E4 802405E4 44062000 */  mfc1      $a2, $f4
/* ECA2E8 802405E8 0C01D78C */  jal       func_80075E30
/* ECA2EC 802405EC 24040009 */   addiu    $a0, $zero, 9
/* ECA2F0 802405F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECA2F4 802405F4 24020002 */  addiu     $v0, $zero, 2
/* ECA2F8 802405F8 03E00008 */  jr        $ra
/* ECA2FC 802405FC 27BD0020 */   addiu    $sp, $sp, 0x20
