.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_7922A8
/* 7922A8 802A1518 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7922AC 802A151C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7922B0 802A1520 AFB00010 */  sw        $s0, 0x10($sp)
/* 7922B4 802A1524 8C82000C */  lw        $v0, 0xc($a0)
/* 7922B8 802A1528 0C0B1EAF */  jal       get_variable
/* 7922BC 802A152C 8C450000 */   lw       $a1, ($v0)
/* 7922C0 802A1530 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 7922C4 802A1534 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 7922C8 802A1538 80640002 */  lb        $a0, 2($v1)
/* 7922CC 802A153C 80650003 */  lb        $a1, 3($v1)
/* 7922D0 802A1540 00822021 */  addu      $a0, $a0, $v0
/* 7922D4 802A1544 00A4102A */  slt       $v0, $a1, $a0
/* 7922D8 802A1548 10400002 */  beqz      $v0, .L802A1554
/* 7922DC 802A154C 0060802D */   daddu    $s0, $v1, $zero
/* 7922E0 802A1550 00A0202D */  daddu     $a0, $a1, $zero
.L802A1554:
/* 7922E4 802A1554 A2040002 */  sb        $a0, 2($s0)
/* 7922E8 802A1558 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7922EC 802A155C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7922F0 802A1560 24020002 */  addiu     $v0, $zero, 2
/* 7922F4 802A1564 03E00008 */  jr        $ra
/* 7922F8 802A1568 27BD0018 */   addiu    $sp, $sp, 0x18
