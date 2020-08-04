.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003C78C
/* 017B8C 8003C78C 00052880 */  sll   $a1, $a1, 2
/* 017B90 8003C790 00852021 */  addu  $a0, $a0, $a1
/* 017B94 8003C794 8C820324 */  lw    $v0, 0x324($a0)
/* 017B98 8003C798 8C43000C */  lw    $v1, 0xc($v0)
/* 017B9C 8003C79C 24020005 */  addiu $v0, $zero, 5
/* 017BA0 8003C7A0 03E00008 */  jr    $ra
/* 017BA4 8003C7A4 AC62002C */   sw    $v0, 0x2c($v1)

