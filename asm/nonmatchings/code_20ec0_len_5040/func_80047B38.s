.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80047B38
/* 022F38 80047B38 00041040 */  sll   $v0, $a0, 1
/* 022F3C 80047B3C 00441021 */  addu  $v0, $v0, $a0
/* 022F40 80047B40 00021080 */  sll   $v0, $v0, 2
/* 022F44 80047B44 00441023 */  subu  $v0, $v0, $a0
/* 022F48 80047B48 3C03800A */  lui   $v1, 0x800a
/* 022F4C 80047B4C 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022F50 80047B50 00021100 */  sll   $v0, $v0, 4
/* 022F54 80047B54 00622821 */  addu  $a1, $v1, $v0
/* 022F58 80047B58 2403FFDF */  addiu $v1, $zero, -0x21
/* 022F5C 80047B5C 8CA20000 */  lw    $v0, ($a1)
/* 022F60 80047B60 80A40068 */  lb    $a0, 0x68($a1)
/* 022F64 80047B64 00431024 */  and   $v0, $v0, $v1
/* 022F68 80047B68 14800004 */  bnez  $a0, .L80047B7C
/* 022F6C 80047B6C ACA20000 */   sw    $v0, ($a1)
/* 022F70 80047B70 24020001 */  addiu $v0, $zero, 1
/* 022F74 80047B74 A0A20068 */  sb    $v0, 0x68($a1)
/* 022F78 80047B78 A0A2006A */  sb    $v0, 0x6a($a1)
.L80047B7C:
/* 022F7C 80047B7C 03E00008 */  jr    $ra
/* 022F80 80047B80 00000000 */   nop   

