.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011F304
/* 0B5A04 8011F304 3C028007 */  lui   $v0, 0x8007
/* 0B5A08 8011F308 8C42419C */  lw    $v0, 0x419c($v0)
/* 0B5A0C 8011F30C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0B5A10 8011F310 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0B5A14 8011F314 80420070 */  lb    $v0, 0x70($v0)
/* 0B5A18 8011F318 10400004 */  beqz  $v0, .L8011F32C
/* 0B5A1C 8011F31C 27A80010 */   addiu $t0, $sp, 0x10
/* 0B5A20 8011F320 30820800 */  andi  $v0, $a0, 0x800
/* 0B5A24 8011F324 1040002D */  beqz  $v0, .L8011F3DC
/* 0B5A28 8011F328 00000000 */   nop   
.L8011F32C:
/* 0B5A2C 8011F32C 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B5A30 8011F330 00822024 */  and   $a0, $a0, $v0
/* 0B5A34 8011F334 3C038015 */  lui   $v1, 0x8015
/* 0B5A38 8011F338 8C633A40 */  lw    $v1, 0x3a40($v1)
/* 0B5A3C 8011F33C 00041080 */  sll   $v0, $a0, 2
/* 0B5A40 8011F340 00431021 */  addu  $v0, $v0, $v1
/* 0B5A44 8011F344 8C470000 */  lw    $a3, ($v0)
/* 0B5A48 8011F348 10E00024 */  beqz  $a3, .L8011F3DC
/* 0B5A4C 8011F34C 00000000 */   nop   
/* 0B5A50 8011F350 8CE60000 */  lw    $a2, ($a3)
/* 0B5A54 8011F354 10C00021 */  beqz  $a2, .L8011F3DC
/* 0B5A58 8011F358 30C20040 */   andi  $v0, $a2, 0x40
/* 0B5A5C 8011F35C 1440001F */  bnez  $v0, .L8011F3DC
/* 0B5A60 8011F360 24020001 */   addiu $v0, $zero, 1
/* 0B5A64 8011F364 3C03800A */  lui   $v1, 0x800a
/* 0B5A68 8011F368 8463A634 */  lh    $v1, -0x59cc($v1)
/* 0B5A6C 8011F36C 00621004 */  sllv  $v0, $v0, $v1
/* 0B5A70 8011F370 00C21024 */  and   $v0, $a2, $v0
/* 0B5A74 8011F374 10400019 */  beqz  $v0, .L8011F3DC
/* 0B5A78 8011F378 30C20080 */   andi  $v0, $a2, 0x80
/* 0B5A7C 8011F37C 14400017 */  bnez  $v0, .L8011F3DC
/* 0B5A80 8011F380 24E20098 */   addiu $v0, $a3, 0x98
/* 0B5A84 8011F384 24A30040 */  addiu $v1, $a1, 0x40
.L8011F388:
/* 0B5A88 8011F388 8CA90000 */  lw    $t1, ($a1)
/* 0B5A8C 8011F38C 8CAA0004 */  lw    $t2, 4($a1)
/* 0B5A90 8011F390 8CAB0008 */  lw    $t3, 8($a1)
/* 0B5A94 8011F394 8CAC000C */  lw    $t4, 0xc($a1)
/* 0B5A98 8011F398 AC490000 */  sw    $t1, ($v0)
/* 0B5A9C 8011F39C AC4A0004 */  sw    $t2, 4($v0)
/* 0B5AA0 8011F3A0 AC4B0008 */  sw    $t3, 8($v0)
/* 0B5AA4 8011F3A4 AC4C000C */  sw    $t4, 0xc($v0)
/* 0B5AA8 8011F3A8 24A50010 */  addiu $a1, $a1, 0x10
/* 0B5AAC 8011F3AC 14A3FFF6 */  bne   $a1, $v1, .L8011F388
/* 0B5AB0 8011F3B0 24420010 */   addiu $v0, $v0, 0x10
/* 0B5AB4 8011F3B4 3C028012 */  lui   $v0, 0x8012
/* 0B5AB8 8011F3B8 2442F4D4 */  addiu $v0, $v0, -0xb2c
/* 0B5ABC 8011F3BC ACE000D8 */  sw    $zero, 0xd8($a3)
/* 0B5AC0 8011F3C0 AD070008 */  sw    $a3, 8($t0)
/* 0B5AC4 8011F3C4 AD02000C */  sw    $v0, 0xc($t0)
/* 0B5AC8 8011F3C8 AD000004 */  sw    $zero, 4($t0)
/* 0B5ACC 8011F3CC 80E20004 */  lb    $v0, 4($a3)
/* 0B5AD0 8011F3D0 0100202D */  daddu $a0, $t0, $zero
/* 0B5AD4 8011F3D4 0C047644 */  jal   queue_render_task
/* 0B5AD8 8011F3D8 AD020000 */   sw    $v0, ($t0)
.L8011F3DC:
/* 0B5ADC 8011F3DC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0B5AE0 8011F3E0 03E00008 */  jr    $ra
/* 0B5AE4 8011F3E4 27BD0028 */   addiu $sp, $sp, 0x28

