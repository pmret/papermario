.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel collision_heap_create
/* 006174 8002AD74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006178 8002AD78 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00617C 8002AD7C 3C050001 */  lui   $a1, 1
/* 006180 8002AD80 3C048027 */  lui   $a0, 0x8027
/* 006184 8002AD84 24848000 */  addiu $a0, $a0, -0x8000
/* 006188 8002AD88 0C00A40C */  jal   _heap_create
/* 00618C 8002AD8C 34A58000 */   ori   $a1, $a1, 0x8000
/* 006190 8002AD90 0040202D */  daddu $a0, $v0, $zero
/* 006194 8002AD94 2402FFFF */  addiu $v0, $zero, -1
/* 006198 8002AD98 0040182D */  daddu $v1, $v0, $zero
/* 00619C 8002AD9C 54830001 */  bnel  $a0, $v1, .L8002ADA4
/* 0061A0 8002ADA0 0000102D */   daddu $v0, $zero, $zero
.L8002ADA4:
/* 0061A4 8002ADA4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0061A8 8002ADA8 03E00008 */  jr    $ra
/* 0061AC 8002ADAC 27BD0018 */   addiu $sp, $sp, 0x18


