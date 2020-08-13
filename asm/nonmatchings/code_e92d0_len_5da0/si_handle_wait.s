.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_wait
/* 0E950C 802C4B5C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9510 802C4B60 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9514 802C4B64 0080802D */  daddu $s0, $a0, $zero
/* 0E9518 802C4B68 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E951C 802C4B6C 82020005 */  lb    $v0, 5($s0)
/* 0E9520 802C4B70 14400006 */  bnez  $v0, .L802C4B8C
/* 0E9524 802C4B74 8E05000C */   lw    $a1, 0xc($s0)
/* 0E9528 802C4B78 0C0B1EAF */  jal   get_variable
/* 0E952C 802C4B7C 8CA50000 */   lw    $a1, ($a1)
/* 0E9530 802C4B80 AE020070 */  sw    $v0, 0x70($s0)
/* 0E9534 802C4B84 24020001 */  addiu $v0, $zero, 1
/* 0E9538 802C4B88 A2020005 */  sb    $v0, 5($s0)
.L802C4B8C:
/* 0E953C 802C4B8C 8E020070 */  lw    $v0, 0x70($s0)
/* 0E9540 802C4B90 10400004 */  beqz  $v0, .L802C4BA4
/* 0E9544 802C4B94 2442FFFF */   addiu $v0, $v0, -1
/* 0E9548 802C4B98 AE020070 */  sw    $v0, 0x70($s0)
/* 0E954C 802C4B9C 080B12EA */  j     .L802C4BA8
/* 0E9550 802C4BA0 2C420001 */   sltiu $v0, $v0, 1

.L802C4BA4:
/* 0E9554 802C4BA4 24020002 */  addiu $v0, $zero, 2
.L802C4BA8:
/* 0E9558 802C4BA8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E955C 802C4BAC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9560 802C4BB0 03E00008 */  jr    $ra
/* 0E9564 802C4BB4 27BD0018 */   addiu $sp, $sp, 0x18

