.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014ADF8
/* E14F8 8014ADF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E14FC 8014ADFC 0080402D */  daddu     $t0, $a0, $zero
/* E1500 8014AE00 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E1504 8014AE04 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E1508 8014AE08 AFBF0018 */  sw        $ra, 0x18($sp)
/* E150C 8014AE0C 80420071 */  lb        $v0, 0x71($v0)
/* E1510 8014AE10 3C078016 */  lui       $a3, 0x8016
/* E1514 8014AE14 24E79AF0 */  addiu     $a3, $a3, -0x6510
/* E1518 8014AE18 14400011 */  bnez      $v0, .L8014AE60
/* E151C 8014AE1C 00A0482D */   daddu    $t1, $a1, $zero
/* E1520 8014AE20 8CE40010 */  lw        $a0, 0x10($a3)
/* E1524 8014AE24 8CE50014 */  lw        $a1, 0x14($a3)
/* E1528 8014AE28 8CE60018 */  lw        $a2, 0x18($a3)
/* E152C 8014AE2C 94E30000 */  lhu       $v1, ($a3)
/* E1530 8014AE30 24020008 */  addiu     $v0, $zero, 8
/* E1534 8014AE34 AFA20010 */  sw        $v0, 0x10($sp)
/* E1538 8014AE38 34630004 */  ori       $v1, $v1, 4
/* E153C 8014AE3C ACE40024 */  sw        $a0, 0x24($a3)
/* E1540 8014AE40 0000202D */  daddu     $a0, $zero, $zero
/* E1544 8014AE44 ACE50028 */  sw        $a1, 0x28($a3)
/* E1548 8014AE48 0100282D */  daddu     $a1, $t0, $zero
/* E154C 8014AE4C ACE6002C */  sw        $a2, 0x2c($a3)
/* E1550 8014AE50 0120302D */  daddu     $a2, $t1, $zero
/* E1554 8014AE54 A4E30000 */  sh        $v1, ($a3)
/* E1558 8014AE58 0C052A46 */  jal       set_music_track
/* E155C 8014AE5C 240701F4 */   addiu    $a3, $zero, 0x1f4
.L8014AE60:
/* E1560 8014AE60 8FBF0018 */  lw        $ra, 0x18($sp)
/* E1564 8014AE64 03E00008 */  jr        $ra
/* E1568 8014AE68 27BD0020 */   addiu    $sp, $sp, 0x20
