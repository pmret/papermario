.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A154C_73361C
/* 73361C 802A154C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 733620 802A1550 AFBF0014 */  sw        $ra, 0x14($sp)
/* 733624 802A1554 AFB00010 */  sw        $s0, 0x10($sp)
/* 733628 802A1558 8C82000C */  lw        $v0, 0xc($a0)
/* 73362C 802A155C 0C0B1EAF */  jal       get_variable
/* 733630 802A1560 8C450000 */   lw       $a1, ($v0)
/* 733634 802A1564 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 733638 802A1568 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 73363C 802A156C 80640005 */  lb        $a0, 5($v1)
/* 733640 802A1570 80650006 */  lb        $a1, 6($v1)
/* 733644 802A1574 00822021 */  addu      $a0, $a0, $v0
/* 733648 802A1578 00A4102A */  slt       $v0, $a1, $a0
/* 73364C 802A157C 10400002 */  beqz      $v0, .L802A1588
/* 733650 802A1580 0060802D */   daddu    $s0, $v1, $zero
/* 733654 802A1584 00A0202D */  daddu     $a0, $a1, $zero
.L802A1588:
/* 733658 802A1588 A2040005 */  sb        $a0, 5($s0)
/* 73365C 802A158C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 733660 802A1590 8FB00010 */  lw        $s0, 0x10($sp)
/* 733664 802A1594 24020002 */  addiu     $v0, $zero, 2
/* 733668 802A1598 03E00008 */  jr        $ra
/* 73366C 802A159C 27BD0018 */   addiu    $sp, $sp, 0x18
