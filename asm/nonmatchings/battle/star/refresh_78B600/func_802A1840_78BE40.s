.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1840_78BE40
/* 78BE40 802A1840 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78BE44 802A1844 AFBF0014 */  sw        $ra, 0x14($sp)
/* 78BE48 802A1848 AFB00010 */  sw        $s0, 0x10($sp)
/* 78BE4C 802A184C 8C82000C */  lw        $v0, 0xc($a0)
/* 78BE50 802A1850 0C0B1EAF */  jal       get_variable
/* 78BE54 802A1854 8C450000 */   lw       $a1, ($v0)
/* 78BE58 802A1858 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 78BE5C 802A185C 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 78BE60 802A1860 80640002 */  lb        $a0, 2($v1)
/* 78BE64 802A1864 80650003 */  lb        $a1, 3($v1)
/* 78BE68 802A1868 00822021 */  addu      $a0, $a0, $v0
/* 78BE6C 802A186C 00A4102A */  slt       $v0, $a1, $a0
/* 78BE70 802A1870 10400002 */  beqz      $v0, .L802A187C
/* 78BE74 802A1874 0060802D */   daddu    $s0, $v1, $zero
/* 78BE78 802A1878 00A0202D */  daddu     $a0, $a1, $zero
.L802A187C:
/* 78BE7C 802A187C A2040002 */  sb        $a0, 2($s0)
/* 78BE80 802A1880 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78BE84 802A1884 8FB00010 */  lw        $s0, 0x10($sp)
/* 78BE88 802A1888 24020002 */  addiu     $v0, $zero, 2
/* 78BE8C 802A188C 03E00008 */  jr        $ra
/* 78BE90 802A1890 27BD0018 */   addiu    $sp, $sp, 0x18
