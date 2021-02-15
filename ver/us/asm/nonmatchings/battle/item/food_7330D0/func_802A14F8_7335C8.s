.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14F8_7335C8
/* 7335C8 802A14F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7335CC 802A14FC AFBF0014 */  sw        $ra, 0x14($sp)
/* 7335D0 802A1500 AFB00010 */  sw        $s0, 0x10($sp)
/* 7335D4 802A1504 8C82000C */  lw        $v0, 0xc($a0)
/* 7335D8 802A1508 0C0B1EAF */  jal       get_variable
/* 7335DC 802A150C 8C450000 */   lw       $a1, ($v0)
/* 7335E0 802A1510 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 7335E4 802A1514 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 7335E8 802A1518 80640002 */  lb        $a0, 2($v1)
/* 7335EC 802A151C 80650003 */  lb        $a1, 3($v1)
/* 7335F0 802A1520 00822021 */  addu      $a0, $a0, $v0
/* 7335F4 802A1524 00A4102A */  slt       $v0, $a1, $a0
/* 7335F8 802A1528 10400002 */  beqz      $v0, .L802A1534
/* 7335FC 802A152C 0060802D */   daddu    $s0, $v1, $zero
/* 733600 802A1530 00A0202D */  daddu     $a0, $a1, $zero
.L802A1534:
/* 733604 802A1534 A2040002 */  sb        $a0, 2($s0)
/* 733608 802A1538 8FBF0014 */  lw        $ra, 0x14($sp)
/* 73360C 802A153C 8FB00010 */  lw        $s0, 0x10($sp)
/* 733610 802A1540 24020002 */  addiu     $v0, $zero, 2
/* 733614 802A1544 03E00008 */  jr        $ra
/* 733618 802A1548 27BD0018 */   addiu    $sp, $sp, 0x18
