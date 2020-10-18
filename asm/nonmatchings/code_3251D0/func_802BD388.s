.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD388
/* 325458 802BD388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32545C 802BD38C AFBF0014 */  sw        $ra, 0x14($sp)
/* 325460 802BD390 AFB00010 */  sw        $s0, 0x10($sp)
/* 325464 802BD394 8C82000C */  lw        $v0, 0xc($a0)
/* 325468 802BD398 0C0B1EAF */  jal       get_variable
/* 32546C 802BD39C 8C450000 */   lw       $a1, ($v0)
/* 325470 802BD3A0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 325474 802BD3A4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 325478 802BD3A8 80640005 */  lb        $a0, 5($v1)
/* 32547C 802BD3AC 80650006 */  lb        $a1, 6($v1)
/* 325480 802BD3B0 00822021 */  addu      $a0, $a0, $v0
/* 325484 802BD3B4 00A4102A */  slt       $v0, $a1, $a0
/* 325488 802BD3B8 10400002 */  beqz      $v0, .L802BD3C4
/* 32548C 802BD3BC 0060802D */   daddu    $s0, $v1, $zero
/* 325490 802BD3C0 00A0202D */  daddu     $a0, $a1, $zero
.L802BD3C4:
/* 325494 802BD3C4 58800001 */  blezl     $a0, .L802BD3CC
/* 325498 802BD3C8 24040001 */   addiu    $a0, $zero, 1
.L802BD3CC:
/* 32549C 802BD3CC A2040005 */  sb        $a0, 5($s0)
/* 3254A0 802BD3D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3254A4 802BD3D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3254A8 802BD3D8 24020002 */  addiu     $v0, $zero, 2
/* 3254AC 802BD3DC 03E00008 */  jr        $ra
/* 3254B0 802BD3E0 27BD0018 */   addiu    $sp, $sp, 0x18
