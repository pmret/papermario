.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel delete_trigger
/* 0DC2F4 80145BF4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DC2F8 80145BF8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0DC2FC 80145BFC 3C118016 */  lui   $s1, 0x8016
/* 0DC300 80145C00 26319390 */  addiu $s1, $s1, -0x6c70
/* 0DC304 80145C04 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0DC308 80145C08 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DC30C 80145C0C 8E250000 */  lw    $a1, ($s1)
/* 0DC310 80145C10 0000802D */  daddu $s0, $zero, $zero
/* 0DC314 80145C14 00A0182D */  daddu $v1, $a1, $zero
.L80145C18:
/* 0DC318 80145C18 8C620000 */  lw    $v0, ($v1)
/* 0DC31C 80145C1C 10440006 */  beq   $v0, $a0, .L80145C38
/* 0DC320 80145C20 2A020040 */   slti  $v0, $s0, 0x40
/* 0DC324 80145C24 26100001 */  addiu $s0, $s0, 1
/* 0DC328 80145C28 2A020040 */  slti  $v0, $s0, 0x40
/* 0DC32C 80145C2C 1440FFFA */  bnez  $v0, .L80145C18
/* 0DC330 80145C30 24630004 */   addiu $v1, $v1, 4
/* 0DC334 80145C34 2A020040 */  slti  $v0, $s0, 0x40
.L80145C38:
/* 0DC338 80145C38 10400007 */  beqz  $v0, .L80145C58
/* 0DC33C 80145C3C 00108080 */   sll   $s0, $s0, 2
/* 0DC340 80145C40 02051021 */  addu  $v0, $s0, $a1
/* 0DC344 80145C44 0C00AB4B */  jal   heap_free
/* 0DC348 80145C48 8C440000 */   lw    $a0, ($v0)
/* 0DC34C 80145C4C 8E220000 */  lw    $v0, ($s1)
/* 0DC350 80145C50 02028021 */  addu  $s0, $s0, $v0
/* 0DC354 80145C54 AE000000 */  sw    $zero, ($s0)
.L80145C58:
/* 0DC358 80145C58 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0DC35C 80145C5C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0DC360 80145C60 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DC364 80145C64 03E00008 */  jr    $ra
/* 0DC368 80145C68 27BD0020 */   addiu $sp, $sp, 0x20

