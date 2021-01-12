.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A19EC_731CEC
/* 731CEC 802A19EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 731CF0 802A19F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 731CF4 802A19F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 731CF8 802A19F8 8C82000C */  lw        $v0, 0xc($a0)
/* 731CFC 802A19FC 0C0B1EAF */  jal       get_variable
/* 731D00 802A1A00 8C450000 */   lw       $a1, ($v0)
/* 731D04 802A1A04 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 731D08 802A1A08 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 731D0C 802A1A0C 80640005 */  lb        $a0, 5($v1)
/* 731D10 802A1A10 80650006 */  lb        $a1, 6($v1)
/* 731D14 802A1A14 00822021 */  addu      $a0, $a0, $v0
/* 731D18 802A1A18 00A4102A */  slt       $v0, $a1, $a0
/* 731D1C 802A1A1C 10400002 */  beqz      $v0, .L802A1A28
/* 731D20 802A1A20 0060802D */   daddu    $s0, $v1, $zero
/* 731D24 802A1A24 00A0202D */  daddu     $a0, $a1, $zero
.L802A1A28:
/* 731D28 802A1A28 A2040005 */  sb        $a0, 5($s0)
/* 731D2C 802A1A2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 731D30 802A1A30 8FB00010 */  lw        $s0, 0x10($sp)
/* 731D34 802A1A34 24020002 */  addiu     $v0, $zero, 2
/* 731D38 802A1A38 03E00008 */  jr        $ra
/* 731D3C 802A1A3C 27BD0018 */   addiu    $sp, $sp, 0x18
