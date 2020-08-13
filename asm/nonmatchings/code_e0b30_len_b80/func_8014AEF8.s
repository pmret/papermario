.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8014AEF8
/* 0E15F8 8014AEF8 3C028007 */  lui   $v0, 0x8007
/* 0E15FC 8014AEFC 8C42419C */  lw    $v0, 0x419c($v0)
/* 0E1600 8014AF00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E1604 8014AF04 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E1608 8014AF08 AFB00018 */  sw    $s0, 0x18($sp)
/* 0E160C 8014AF0C 80420071 */  lb    $v0, 0x71($v0)
/* 0E1610 8014AF10 3C108016 */  lui   $s0, 0x8016
/* 0E1614 8014AF14 26109AF0 */  addiu $s0, $s0, -0x6510
/* 0E1618 8014AF18 14400018 */  bnez  $v0, .L8014AF7C
/* 0E161C 8014AF1C 3C030002 */   lui   $v1, 2
/* 0E1620 8014AF20 3C02800A */  lui   $v0, 0x800a
/* 0E1624 8014AF24 8C42A650 */  lw    $v0, -0x59b0($v0)
/* 0E1628 8014AF28 00431024 */  and   $v0, $v0, $v1
/* 0E162C 8014AF2C 14400013 */  bnez  $v0, .L8014AF7C
/* 0E1630 8014AF30 0000202D */   daddu $a0, $zero, $zero
/* 0E1634 8014AF34 0C01554F */  jal   func_8005553C
/* 0E1638 8014AF38 240500FA */   addiu $a1, $zero, 0xfa
/* 0E163C 8014AF3C 0000202D */  daddu $a0, $zero, $zero
/* 0E1640 8014AF40 8E05001C */  lw    $a1, 0x1c($s0)
/* 0E1644 8014AF44 8E060010 */  lw    $a2, 0x10($s0)
/* 0E1648 8014AF48 8E070014 */  lw    $a3, 0x14($s0)
/* 0E164C 8014AF4C 8E080018 */  lw    $t0, 0x18($s0)
/* 0E1650 8014AF50 96030000 */  lhu   $v1, ($s0)
/* 0E1654 8014AF54 24020008 */  addiu $v0, $zero, 8
/* 0E1658 8014AF58 AFA20010 */  sw    $v0, 0x10($sp)
/* 0E165C 8014AF5C AE060024 */  sw    $a2, 0x24($s0)
/* 0E1660 8014AF60 8E060020 */  lw    $a2, 0x20($s0)
/* 0E1664 8014AF64 34630004 */  ori   $v1, $v1, 4
/* 0E1668 8014AF68 AE070028 */  sw    $a3, 0x28($s0)
/* 0E166C 8014AF6C 240701F4 */  addiu $a3, $zero, 0x1f4
/* 0E1670 8014AF70 AE08002C */  sw    $t0, 0x2c($s0)
/* 0E1674 8014AF74 0C052A46 */  jal   set_music_track
/* 0E1678 8014AF78 A6030000 */   sh    $v1, ($s0)
.L8014AF7C:
/* 0E167C 8014AF7C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E1680 8014AF80 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E1684 8014AF84 03E00008 */  jr    $ra
/* 0E1688 8014AF88 27BD0020 */   addiu $sp, $sp, 0x20

