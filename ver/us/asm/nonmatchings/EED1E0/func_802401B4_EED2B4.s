.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_EED2B4
/* EED2B4 802401B4 3C028011 */  lui       $v0, %hi(D_80117840)
/* EED2B8 802401B8 24427840 */  addiu     $v0, $v0, %lo(D_80117840)
/* EED2BC 802401BC 000420C0 */  sll       $a0, $a0, 3
/* EED2C0 802401C0 00822021 */  addu      $a0, $a0, $v0
/* EED2C4 802401C4 90820014 */  lbu       $v0, 0x14($a0)
/* EED2C8 802401C8 10400009 */  beqz      $v0, .L802401F0
/* EED2CC 802401CC 00000000 */   nop
/* EED2D0 802401D0 90820015 */  lbu       $v0, 0x15($a0)
/* EED2D4 802401D4 00022600 */  sll       $a0, $v0, 0x18
/* EED2D8 802401D8 00041E03 */  sra       $v1, $a0, 0x18
/* EED2DC 802401DC 00051400 */  sll       $v0, $a1, 0x10
/* EED2E0 802401E0 00021403 */  sra       $v0, $v0, 0x10
/* EED2E4 802401E4 0043102A */  slt       $v0, $v0, $v1
/* EED2E8 802401E8 10400003 */  beqz      $v0, .L802401F8
/* EED2EC 802401EC 00000000 */   nop
.L802401F0:
/* EED2F0 802401F0 03E00008 */  jr        $ra
/* EED2F4 802401F4 2402FFFF */   addiu    $v0, $zero, -1
.L802401F8:
/* EED2F8 802401F8 03E00008 */  jr        $ra
/* EED2FC 802401FC 00041603 */   sra      $v0, $a0, 0x18
