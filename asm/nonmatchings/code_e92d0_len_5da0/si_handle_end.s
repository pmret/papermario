.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_end
/* 0EC404 802C7A54 24020003 */  addiu $v0, $zero, 3
/* 0EC408 802C7A58 10A2FE6E */  beq   $a1, $v0, .L802C7414
/* 0EC40C 802C7A5C 240200FF */   addiu $v0, $zero, 0xff
/* 0EC410 802C7A60 10A20012 */  beq   $a1, $v0, .L802C7AAC
/* 0EC414 802C7A64 2402FFFF */   addiu $v0, $zero, -1
/* 0EC418 802C7A68 04A00010 */  bltz  $a1, .L802C7AAC
/* 0EC41C 802C7A6C 24020001 */   addiu $v0, $zero, 1
/* 0EC420 802C7A70 50A0000E */  beql  $a1, $zero, .L802C7AAC
/* 0EC424 802C7A74 0000102D */   daddu $v0, $zero, $zero
/* 0EC428 802C7A78 14A20003 */  bne   $a1, $v0, .L802C7A88
/* 0EC42C 802C7A7C 24020002 */   addiu $v0, $zero, 2
/* 0EC430 802C7A80 080B1EAA */  j     .L802C7AA8
/* 0EC434 802C7A84 A2000002 */   sb    $zero, 2($s0)

.L802C7A88:
/* 0EC438 802C7A88 14A2FE62 */  bne   $a1, $v0, .L802C7414
/* 0EC43C 802C7A8C 00000000 */   nop   
/* 0EC440 802C7A90 A2000002 */  sb    $zero, 2($s0)
/* 0EC444 802C7A94 3C028007 */  lui   $v0, 0x8007
/* 0EC448 802C7A98 8C42419C */  lw    $v0, 0x419c($v0)
/* 0EC44C 802C7A9C 80420078 */  lb    $v0, 0x78($v0)
/* 0EC450 802C7AA0 1445FE5C */  bne   $v0, $a1, .L802C7414
/* 0EC454 802C7AA4 00000000 */   nop   
.L802C7AA8:
/* 0EC458 802C7AA8 0000102D */  daddu $v0, $zero, $zero
.L802C7AAC:
/* 0EC45C 802C7AAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EC460 802C7AB0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EC464 802C7AB4 03E00008 */  jr    $ra
/* 0EC468 802C7AB8 27BD0018 */   addiu $sp, $sp, 0x18

