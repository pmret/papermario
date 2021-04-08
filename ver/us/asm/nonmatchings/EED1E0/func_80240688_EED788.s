.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240688_EED788
/* EED788 80240688 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EED78C 8024068C AFBF0018 */  sw        $ra, 0x18($sp)
/* EED790 80240690 0C00F94D */  jal       func_8003E534
/* EED794 80240694 2404FFFC */   addiu    $a0, $zero, -4
/* EED798 80240698 C444003C */  lwc1      $f4, 0x3c($v0)
/* EED79C 8024069C 3C014148 */  lui       $at, 0x4148
/* EED7A0 802406A0 44811000 */  mtc1      $at, $f2
/* EED7A4 802406A4 3C013F80 */  lui       $at, 0x3f80
/* EED7A8 802406A8 44810000 */  mtc1      $at, $f0
/* EED7AC 802406AC 2403001E */  addiu     $v1, $zero, 0x1e
/* EED7B0 802406B0 AFA30014 */  sw        $v1, 0x14($sp)
/* EED7B4 802406B4 46022100 */  add.s     $f4, $f4, $f2
/* EED7B8 802406B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* EED7BC 802406BC 8C450038 */  lw        $a1, 0x38($v0)
/* EED7C0 802406C0 8C470040 */  lw        $a3, 0x40($v0)
/* EED7C4 802406C4 44062000 */  mfc1      $a2, $f4
/* EED7C8 802406C8 0C01D78C */  jal       func_80075E30
/* EED7CC 802406CC 24040009 */   addiu    $a0, $zero, 9
/* EED7D0 802406D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* EED7D4 802406D4 24020002 */  addiu     $v0, $zero, 2
/* EED7D8 802406D8 03E00008 */  jr        $ra
/* EED7DC 802406DC 27BD0020 */   addiu    $sp, $sp, 0x20
