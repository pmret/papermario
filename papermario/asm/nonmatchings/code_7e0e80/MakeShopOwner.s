.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel MakeShopOwner
/* 7E2A58 80281BD8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 7E2A5C 80281BDC AFBF0014 */  sw    $ra, 0x14($sp)
/* 7E2A60 80281BE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 7E2A64 80281BE4 8C82000C */  lw    $v0, 0xc($a0)
/* 7E2A68 80281BE8 3C038007 */  lui   $v1, 0x8007
/* 7E2A6C 80281BEC 8C63419C */  lw    $v1, 0x419c($v1)
/* 7E2A70 80281BF0 8C450000 */  lw    $a1, ($v0)
/* 7E2A74 80281BF4 0C0B1EAF */  jal   get_variable
/* 7E2A78 80281BF8 8C700144 */   lw    $s0, 0x144($v1)
/* 7E2A7C 80281BFC AE020010 */  sw    $v0, 0x10($s0)
/* 7E2A80 80281C00 8FBF0014 */  lw    $ra, 0x14($sp)
/* 7E2A84 80281C04 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E2A88 80281C08 24020002 */  addiu $v0, $zero, 2
/* 7E2A8C 80281C0C 03E00008 */  jr    $ra
/* 7E2A90 80281C10 27BD0018 */   addiu $sp, $sp, 0x18

/* 7E2A94 80281C14 00000000 */  nop   
/* 7E2A98 80281C18 00000000 */  nop   
/* 7E2A9C 80281C1C 00000000 */  nop   
