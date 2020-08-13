.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSpTaskYielded
/* 041070 80065C70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041074 80065C74 AFB00010 */  sw    $s0, 0x10($sp)
/* 041078 80065C78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04107C 80065C7C 0C01B1B8 */  jal   osSpGetStatus
/* 041080 80065C80 00808021 */   addu  $s0, $a0, $zero
/* 041084 80065C84 00022202 */  srl   $a0, $v0, 8
/* 041088 80065C88 30420080 */  andi  $v0, $v0, 0x80
/* 04108C 80065C8C 10400006 */  beqz  $v0, .L80065CA8
/* 041090 80065C90 30840001 */   andi  $a0, $a0, 1
/* 041094 80065C94 8E020004 */  lw    $v0, 4($s0)
/* 041098 80065C98 2403FFFD */  addiu $v1, $zero, -3
/* 04109C 80065C9C 00441025 */  or    $v0, $v0, $a0
/* 0410A0 80065CA0 00431024 */  and   $v0, $v0, $v1
/* 0410A4 80065CA4 AE020004 */  sw    $v0, 4($s0)
.L80065CA8:
/* 0410A8 80065CA8 00801021 */  addu  $v0, $a0, $zero
/* 0410AC 80065CAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0410B0 80065CB0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0410B4 80065CB4 03E00008 */  jr    $ra
/* 0410B8 80065CB8 27BD0018 */   addiu $sp, $sp, 0x18

/* 0410BC 80065CBC 00000000 */  nop   
