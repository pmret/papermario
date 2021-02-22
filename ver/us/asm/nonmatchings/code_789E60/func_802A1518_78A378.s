.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_78A378
/* 78A378 802A1518 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 78A37C 802A151C AFB20018 */  sw        $s2, 0x18($sp)
/* 78A380 802A1520 0080902D */  daddu     $s2, $a0, $zero
/* 78A384 802A1524 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 78A388 802A1528 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 78A38C 802A152C AFB10014 */  sw        $s1, 0x14($sp)
/* 78A390 802A1530 0040882D */  daddu     $s1, $v0, $zero
/* 78A394 802A1534 AFBF001C */  sw        $ra, 0x1c($sp)
/* 78A398 802A1538 AFB00010 */  sw        $s0, 0x10($sp)
/* 78A39C 802A153C AE400084 */  sw        $zero, 0x84($s2)
/* 78A3A0 802A1540 8222028E */  lb        $v0, 0x28e($s1)
/* 78A3A4 802A1544 86230290 */  lh        $v1, 0x290($s1)
/* 78A3A8 802A1548 00021200 */  sll       $v0, $v0, 8
/* 78A3AC 802A154C 0062182A */  slt       $v1, $v1, $v0
/* 78A3B0 802A1550 1060000F */  beqz      $v1, .L802A1590
/* 78A3B4 802A1554 24020001 */   addiu    $v0, $zero, 1
/* 78A3B8 802A1558 0C03A752 */  jal       is_ability_active
/* 78A3BC 802A155C 24040030 */   addiu    $a0, $zero, 0x30
/* 78A3C0 802A1560 24040031 */  addiu     $a0, $zero, 0x31
/* 78A3C4 802A1564 0C03A752 */  jal       is_ability_active
/* 78A3C8 802A1568 00028180 */   sll      $s0, $v0, 6
/* 78A3CC 802A156C 000211C0 */  sll       $v0, $v0, 7
/* 78A3D0 802A1570 02028021 */  addu      $s0, $s0, $v0
/* 78A3D4 802A1574 0C03A87D */  jal       add_SP
/* 78A3D8 802A1578 26040080 */   addiu    $a0, $s0, 0x80
/* 78A3DC 802A157C 8222028E */  lb        $v0, 0x28e($s1)
/* 78A3E0 802A1580 86230290 */  lh        $v1, 0x290($s1)
/* 78A3E4 802A1584 00021200 */  sll       $v0, $v0, 8
/* 78A3E8 802A1588 14620003 */  bne       $v1, $v0, .L802A1598
/* 78A3EC 802A158C 24020002 */   addiu    $v0, $zero, 2
.L802A1590:
/* 78A3F0 802A1590 AE420084 */  sw        $v0, 0x84($s2)
/* 78A3F4 802A1594 24020002 */  addiu     $v0, $zero, 2
.L802A1598:
/* 78A3F8 802A1598 8FBF001C */  lw        $ra, 0x1c($sp)
/* 78A3FC 802A159C 8FB20018 */  lw        $s2, 0x18($sp)
/* 78A400 802A15A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 78A404 802A15A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 78A408 802A15A8 03E00008 */  jr        $ra
/* 78A40C 802A15AC 27BD0020 */   addiu    $sp, $sp, 0x20
