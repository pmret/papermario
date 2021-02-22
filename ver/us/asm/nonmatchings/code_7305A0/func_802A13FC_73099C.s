.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A13FC_73099C
/* 73099C 802A13FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7309A0 802A1400 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7309A4 802A1404 AFB00010 */  sw        $s0, 0x10($sp)
/* 7309A8 802A1408 8C82000C */  lw        $v0, 0xc($a0)
/* 7309AC 802A140C 0C0B1EAF */  jal       get_variable
/* 7309B0 802A1410 8C450000 */   lw       $a1, ($v0)
/* 7309B4 802A1414 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 7309B8 802A1418 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 7309BC 802A141C 80640002 */  lb        $a0, 2($v1)
/* 7309C0 802A1420 80650003 */  lb        $a1, 3($v1)
/* 7309C4 802A1424 00822021 */  addu      $a0, $a0, $v0
/* 7309C8 802A1428 00A4102A */  slt       $v0, $a1, $a0
/* 7309CC 802A142C 10400002 */  beqz      $v0, .L802A1438
/* 7309D0 802A1430 0060802D */   daddu    $s0, $v1, $zero
/* 7309D4 802A1434 00A0202D */  daddu     $a0, $a1, $zero
.L802A1438:
/* 7309D8 802A1438 A2040002 */  sb        $a0, 2($s0)
/* 7309DC 802A143C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7309E0 802A1440 8FB00010 */  lw        $s0, 0x10($sp)
/* 7309E4 802A1444 24020002 */  addiu     $v0, $zero, 2
/* 7309E8 802A1448 03E00008 */  jr        $ra
/* 7309EC 802A144C 27BD0018 */   addiu    $sp, $sp, 0x18
