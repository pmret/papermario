.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800287F0
/* 003BF0 800287F0 3C038007 */  lui   $v1, 0x8007
/* 003BF4 800287F4 2463419C */  addiu $v1, $v1, 0x419c
/* 003BF8 800287F8 8C620000 */  lw    $v0, ($v1)
/* 003BFC 800287FC A0400040 */  sb    $zero, 0x40($v0)
/* 003C00 80028800 8C640000 */  lw    $a0, ($v1)
/* 003C04 80028804 AC400000 */  sw    $zero, ($v0)
/* 003C08 80028808 AC400010 */  sw    $zero, 0x10($v0)
/* 003C0C 8002880C AC400020 */  sw    $zero, 0x20($v0)
/* 003C10 80028810 A0800044 */  sb    $zero, 0x44($a0)
/* 003C14 80028814 8C630000 */  lw    $v1, ($v1)
/* 003C18 80028818 24020004 */  addiu $v0, $zero, 4
/* 003C1C 8002881C A4620050 */  sh    $v0, 0x50($v1)
/* 003C20 80028820 2402000F */  addiu $v0, $zero, 0xf
/* 003C24 80028824 AC600030 */  sw    $zero, 0x30($v1)
/* 003C28 80028828 A4620048 */  sh    $v0, 0x48($v1)
/* 003C2C 8002882C A4600060 */  sh    $zero, 0x60($v1)
/* 003C30 80028830 03E00008 */  jr    $ra
/* 003C34 80028834 A4600058 */   sh    $zero, 0x58($v1)

