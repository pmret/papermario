.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_message_value
/* 0BC2E8 80125BE8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0BC2EC 80125BEC AFB00030 */  sw    $s0, 0x30($sp)
/* 0BC2F0 80125BF0 00A0802D */  daddu $s0, $a1, $zero
/* 0BC2F4 80125BF4 27A50010 */  addiu $a1, $sp, 0x10
/* 0BC2F8 80125BF8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0BC2FC 80125BFC 0C00A531 */  jal   int_to_string
/* 0BC300 80125C00 2406000A */   addiu $a2, $zero, 0xa
/* 0BC304 80125C04 0000282D */  daddu $a1, $zero, $zero
/* 0BC308 80125C08 27A70010 */  addiu $a3, $sp, 0x10
/* 0BC30C 80125C0C 3C088015 */  lui   $t0, 0x8015
/* 0BC310 80125C10 25085C38 */  addiu $t0, $t0, 0x5c38
/* 0BC314 80125C14 00103140 */  sll   $a2, $s0, 5
/* 0BC318 80125C18 00E51021 */  addu  $v0, $a3, $a1
.L80125C1C:
/* 0BC31C 80125C1C 80430000 */  lb    $v1, ($v0)
/* 0BC320 80125C20 90440000 */  lbu   $a0, ($v0)
/* 0BC324 80125C24 10600008 */  beqz  $v1, .L80125C48
/* 0BC328 80125C28 00A61021 */   addu  $v0, $a1, $a2
/* 0BC32C 80125C2C 00481021 */  addu  $v0, $v0, $t0
/* 0BC330 80125C30 2483FFE0 */  addiu $v1, $a0, -0x20
/* 0BC334 80125C34 A0430000 */  sb    $v1, ($v0)
/* 0BC338 80125C38 24A50001 */  addiu $a1, $a1, 1
/* 0BC33C 80125C3C 28A2001F */  slti  $v0, $a1, 0x1f
/* 0BC340 80125C40 1440FFF6 */  bnez  $v0, .L80125C1C
/* 0BC344 80125C44 00E51021 */   addu  $v0, $a3, $a1
.L80125C48:
/* 0BC348 80125C48 00101140 */  sll   $v0, $s0, 5
/* 0BC34C 80125C4C 00A21021 */  addu  $v0, $a1, $v0
/* 0BC350 80125C50 240300FD */  addiu $v1, $zero, 0xfd
/* 0BC354 80125C54 3C018015 */  lui   $at, 0x8015
/* 0BC358 80125C58 00220821 */  addu  $at, $at, $v0
/* 0BC35C 80125C5C A0235C38 */  sb    $v1, 0x5c38($at)
/* 0BC360 80125C60 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0BC364 80125C64 8FB00030 */  lw    $s0, 0x30($sp)
/* 0BC368 80125C68 03E00008 */  jr    $ra
/* 0BC36C 80125C6C 27BD0038 */   addiu $sp, $sp, 0x38

