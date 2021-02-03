.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1894_78BE94
/* 78BE94 802A1894 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78BE98 802A1898 AFBF0014 */  sw        $ra, 0x14($sp)
/* 78BE9C 802A189C AFB00010 */  sw        $s0, 0x10($sp)
/* 78BEA0 802A18A0 8C82000C */  lw        $v0, 0xc($a0)
/* 78BEA4 802A18A4 0C0B1EAF */  jal       get_variable
/* 78BEA8 802A18A8 8C450000 */   lw       $a1, ($v0)
/* 78BEAC 802A18AC 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 78BEB0 802A18B0 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 78BEB4 802A18B4 80640005 */  lb        $a0, 5($v1)
/* 78BEB8 802A18B8 80650006 */  lb        $a1, 6($v1)
/* 78BEBC 802A18BC 00822021 */  addu      $a0, $a0, $v0
/* 78BEC0 802A18C0 00A4102A */  slt       $v0, $a1, $a0
/* 78BEC4 802A18C4 10400002 */  beqz      $v0, .L802A18D0
/* 78BEC8 802A18C8 0060802D */   daddu    $s0, $v1, $zero
/* 78BECC 802A18CC 00A0202D */  daddu     $a0, $a1, $zero
.L802A18D0:
/* 78BED0 802A18D0 A2040005 */  sb        $a0, 5($s0)
/* 78BED4 802A18D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78BED8 802A18D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 78BEDC 802A18DC 24020002 */  addiu     $v0, $zero, 2
/* 78BEE0 802A18E0 03E00008 */  jr        $ra
/* 78BEE4 802A18E4 27BD0018 */   addiu    $sp, $sp, 0x18
